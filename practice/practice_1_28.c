/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define IDLE_PRIORITY 255
#define MAX_TASK 8

typedef struct {
    uint16_t* sp;
    void (*task)(void);
    uint8_t priority;
} Task;

Task TaskList[MAX_TASK];

void taskInit() {
    for (int it = 0; it < MAX_TASK; ++it) {
        printf("attention for loop it\n");
        // uint16_t* sp = malloc(sizeof(uint16_t));
        // *sp = it;
        TaskList[it].sp = NULL;
        TaskList[it].task = NULL;
        TaskList[it].priority = IDLE_PRIORITY;
        
        printf("check here for loop\n");
    }
    printf("end for loop\n");
}

void task1(void) {
    printf("EXECUTING TASK 1 ... \n");
    for (int it = 0; it < 100; ++it);
    printf("TASK 1 IS DONE\n");
}

void task2(void) {
    printf("EXECUTING TASK 2 ... \n");
    for (int it = 0; it < 100; ++it);
    printf("TASK 2 IS DONE\n");
}

void addTask(void(*task)(void), uint8_t priority) {
    for (int it = 0; it < MAX_TASK; ++it) {
        printf("hehe debug here\n");
        if (TaskList[it].sp == NULL) {
            printf("IMPORTANT ADDTASK DEBUG HERE\n");
            uint16_t* sp = malloc(sizeof(uint16_t));
            *sp = it;
            TaskList[it].sp = sp;
            TaskList[it].task = task;
            TaskList[it].priority = priority;
            
            return;
        }
    }
}

int contextSwitch() {
    int retval = 0;
    
    uint8_t highest_priority = IDLE_PRIORITY;
    int task_index = -1;
    
    for (int it = 0; it < MAX_TASK; ++it) {
        if (TaskList[it].task != NULL && TaskList[it].priority < highest_priority) {
            highest_priority = TaskList[it].priority;
            
            task_index = it;
            printf("TESTING CONTEXTSWITCH TASK INDEX\n");
        }
    }
    
    if (task_index != -1) {
        TaskList[task_index].task();
        
        free(TaskList[task_index].sp);
        TaskList[task_index].sp = NULL;
        TaskList[task_index].task = NULL;
        TaskList[task_index].priority = IDLE_PRIORITY;
    } else {
        retval = -1;   
    }
    
    return retval;
}

int main()
{
    printf("Hello World\n");
    printf("check here before task init\n");
    taskInit();
    addTask(task1, 2);
    addTask(task2, 1);
    
    while (1) {
        // printf("Hello World");
        if (contextSwitch() == -1) {
            break;
        }
    }
    

    return 0;
}
