// Online C++ compiler to run C++ program online
#include <iostream>
#include <functional>
#include <vector>

enum Event {
    GO,
    STOP,
    END
};

struct cb_storage_t {
    std::function<void(int)> att;
    int arg;
    Event event;
};

void add(int a) {
    std::cout << "add function is: " <<  a * 2 << std::endl;
}

void minus(int a) {
    std::cout << "minus function: " << a - 1 << std::endl;
}

std::vector<cb_storage_t> callbacks;

void add_callback(std::function<void(int)> at, int arg, Event event) {
    callbacks.push_back({at, arg, event});
}

void execCallback(Event event) {
    for (auto& cb: callbacks) {
        if (cb.event == event) {
            cb.att(cb.arg);
        }
    }
}

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;
    
    add_callback(add, 3, Event::GO);
    add_callback(add, 55, Event::STOP);
    add_callback(minus, 44, Event::GO);
    
    // execCallback(Event::GO);
    execCallback(Event::STOP);

    return 0;
}
