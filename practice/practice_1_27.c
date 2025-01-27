#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct circular_buf_t* cbuf_handle_t;

struct circular_buf_t {
    uint8_t* buffer;
    size_t head;
    size_t tail;
    size_t max;
    bool full;
};

// Function prototypes
cbuf_handle_t circular_buf_init(uint8_t* buffer, size_t size);
void circular_buf_free(cbuf_handle_t me);
void circular_buf_reset(cbuf_handle_t me);
int circular_buf_put(cbuf_handle_t me, uint8_t data);
int circular_buf_get(cbuf_handle_t me, uint8_t* data);
bool circular_buf_empty(cbuf_handle_t me);
bool circular_buf_full(cbuf_handle_t me);
size_t circular_buf_capacity(cbuf_handle_t me);

cbuf_handle_t circular_buf_init(uint8_t* buffer, size_t size) {
    cbuf_handle_t me = malloc(sizeof(struct circular_buf_t));
    if (!me) {
        return NULL; // Memory allocation failed
    }
    me->buffer = buffer;
    me->max = size;
    circular_buf_reset(me);
    return me;
}

void circular_buf_free(cbuf_handle_t me) {
    if (me) {
        free(me);
    }
}

void circular_buf_reset(cbuf_handle_t me) {
    if (me) {
        me->head = 0;
        me->tail = 0;
        me->full = false;
    }
}

bool circular_buf_empty(cbuf_handle_t me) {
    return (me && !me->full && (me->head == me->tail));
}

bool circular_buf_full(cbuf_handle_t me) {
    return me && me->full;
}

size_t circular_buf_capacity(cbuf_handle_t me) {
    return me ? me->max : 0;
}

int circular_buf_put(cbuf_handle_t me, uint8_t data) {
    if (!me) {
        return -1; // Invalid handle
    }

    me->buffer[me->head] = data;
    me->head = (me->head + 1) % me->max;

    if (me->full) {
        me->tail = (me->tail + 1) % me->max; // Overwrite oldest data
    }

    me->full = (me->head == me->tail);
    return 0;
}

int circular_buf_get(cbuf_handle_t me, uint8_t* data) {
    if (!me || !data || circular_buf_empty(me)) {
        return -1; // Buffer is empty or invalid handle
    }

    *data = me->buffer[me->tail];
    me->tail = (me->tail + 1) % me->max;
    me->full = false;
    return 0;
}

int main() {
    printf("Circular Buffer Demo\n");

    uint8_t* buffer = malloc(sizeof(uint8_t) * 20);
    if (!buffer) {
        printf("Failed to allocate buffer\n");
        return -1;
    }

    cbuf_handle_t cbuf = circular_buf_init(buffer, 20);
    if (!cbuf) {
        printf("Failed to initialize circular buffer\n");
        free(buffer);
        return -1;
    }

    for (int it = 0; it < 35; ++it) {
        if (circular_buf_put(cbuf, it) != 0) {
            printf("Error: Failed to put data\n");
            break;
        }

        uint8_t getData;
        if (circular_buf_get(cbuf, &getData) != 0) {
            printf("Error: Failed to get data\n");
            break;
        }
        printf("Put %d, Got %d\n", it, getData);
    }

    circular_buf_free(cbuf);
    free(buffer);

    return 0;
}
