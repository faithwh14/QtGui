// Online C compiler to run C program online
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

cbuf_handle_t circular_buf_init(uint8_t* buffer, size_t size);
void circular_buf_free(cbuf_handle_t me);
void circular_buf_reset(cbuf_handle_t me);
void ciruclar_buf_put(cbuf_handle_t me, uint8_t data);
int circular_buf_put2(cbuf_handle_t me, uint8_t data);
int circular_buf_get(cbuf_handle_t me, uint8_t* data);
bool circular_buf_empty(cbuf_handle_t me);
bool circular_buf_full(cbuf_handle_t me);
size_t circular_buf_capacity(cbuf_handle_t me);

cbuf_handle_t circular_buf_init(uint8_t* buffer, size_t size) {
    cbuf_handle_t me = malloc(sizeof(struct circular_buf_t));
    me->buffer = buffer;
    me->max = size;
    
    circular_buf_reset(me);
    
    return me;
}

void circular_buf_free(cbuf_handle_t me) {
    free(me);
}

void circular_buf_reset(cbuf_handle_t me) {
    me->head = 0;
    me->tail = 0;
    me->full = false;
}

bool circular_buf_empty(cbuf_handle_t me) {
    return !me->full;
}

bool circular_buf_full(cbuf_handle_t me) {
    return me->full;
}

size_t circular_buf_capacity(cbuf_handle_t me) {
    return me->max;
}

int circular_buf_put(cbuf_handle_t me, uint8_t data) {
    int r = -1;
    
    if (me) {
        me->buffer[me->head] = data;
        // circular
        me->head = (me->head + 1) % me->max;

        r = 0;
    }
    printf("circular buf put value (r) is: %d\n", r);
    return r;
}

int circular_buf_get(cbuf_handle_t me, uint8_t* data) {
    int r = -1;
    
    if (me) {
        *data = me->buffer[me->tail];
        me->tail = (me->tail + 1) % me->max;
        
        r = 0;
    }
    printf("circular buf get value (r) is: %d and data value is: %d\n", r, *data);
    return r;
}

int main() {
    // Write C code here
    printf("Try programiz.pro\n");
    
    uint8_t* buffer = malloc(sizeof(uint8_t) * 20);
    
    cbuf_handle_t cbuf = circular_buf_init(buffer, 20);
    
    for (int it = 0; it < 35; ++it) {
        if (circular_buf_put(cbuf, it) != 0) {
            printf("SOMETHING IS WRONG TO PUT DATA");
            break;
        }
        uint8_t getData;
        if (circular_buf_get(cbuf, &getData) != 0) {
            printf("SOMETHING IS WRONG TO GET DATA");
            break;
        }
    }

    return 0;
}
