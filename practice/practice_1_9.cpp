#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <memory>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>

void* threadFunction1(void* damn) {
    int* shared = (int*)damn;
    while (true) {
        printf("Hello World threadfunction1: %d\n", *shared);
        ++*shared;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return nullptr;
}

void* threadFunction2(void* damn) {
    int* shared = (int*)damn;
    while (true) {
        printf("Hello World threadfunction2: %d\n", *shared);
        ++*shared;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return nullptr;
}

int main() {
    printf("Hello World\n");

    int* test = (int*)malloc(sizeof(int));
    void* hehe = (void*)test;
    int* haha = (int*)hehe;

    *test = 1000;

    printf("haha value is: %d\n", *haha);
    printf("size of int is %zu\n", sizeof(int));

    constexpr int a = 4;

    *test = 44;

    printf("check test malloc value is: %d\n", *test);

    if (test == nullptr) {
        printf("Test is nullptr\n");
    } else {
        printf("test is not nullptr\n");
    }

    free(test);
    test = NULL;
    // printf("test value is %d\n", test);

    if (test == nullptr) {
        printf("Test is nullptr\n");
    } else {
        printf("test is not nullptr\n");
    }

    int answer = 0;

    pthread_t worker_1;
    pthread_create(&worker_1, NULL, threadFunction1, (void*)&answer);
    pthread_t worker_2;
    pthread_create(&worker_2, NULL, threadFunction2, (void*)&answer);

    pthread_join(worker_1, NULL);
    pthread_join(worker_2, NULL);

    return 0;
}
