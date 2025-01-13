// Online C++ compiler to run C++ program online
#include <iostream>
#include <functional>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

class Base {
    public:
    void Deserialize() {
        std::cout << "do something in deserialize" << std::endl;
        return deserialize();
    }
    
    protected:
    virtual void deserialize() = 0;
};

class Child: public Base {
    public:
    void addCallback(const std::function<int(int, int)>& test) {
        m_test_list.push_back(test);
    }
    private:
    void deserialize() override {
        // int aa = m_test(4, 5);
        for (auto it = m_test_list.begin(); it != m_test_list.end(); ++it) {
        // for (auto test123: m_test_list) {
            std::cout << "check function: " << (*it)(4, 5) << std::endl;
        }
        std::cout << "Hello World" << std::endl;
    }
    
    std::vector<std::function<int(int, int)>> m_test_list;
};

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;
    
    int a = 3;
    
    char ab[3];
    ab[0] = 'h';
    
    Child child;
    child.addCallback(add);
    child.addCallback(subtract);
    child.addCallback(multiply);
    child.addCallback(divide);
    child.Deserialize();

    return 0;
}
