// Online C++ compiler to run C++ program online
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

enum Test {
    CAR,
    MOTOR
};

class IProduct {
    protected:
    virtual void setPrice() = 0;
    virtual void setQuantity() = 0;
    
    unsigned int m_price = 0;
    unsigned int m_quantity = 0;
};

class Product: public IProduct {
    public:
    unsigned int getPrice() {
        return m_price;
    }
    unsigned int getQuantity() {
        return m_quantity;
    }
};

class Car: public Product {
    public:
    Car() {
        setPrice();
        setQuantity();
    }
    ~Car() {}

    protected:
    void setPrice() {
        m_price = 90;
    }
    
    void setQuantity() {
        m_quantity = 80;
    }
};

class Motor: public Product {
    public:
    Motor() {
        setPrice();
        setQuantity();
    }
    ~Motor() {}
    
    protected:
    void setPrice() {
        m_price = 50;
    }
    void setQuantity() {
        m_quantity = 100;
    }
};

class ProductFactory {
    protected:
    virtual void MakeProduct(Product* product) = 0;
};

class RealFactory: public ProductFactory {
    public:
    static Product* MakeProduct(Test test) {
        Product* product;
        switch (test) {
            case Test::CAR: {
                product = new Car();
                break;
            }
            case Test::MOTOR: {
                product = new Motor();
                break;
            }
            default:
                throw std::runtime_error("NO SUCH PRODUCT, PLEASE CHECK AGAIN!");
        }
        
        return product;
    }
};

void printProduct(Test test) {
    std::string product_name = "";
    Product* product = RealFactory::MakeProduct(test);
    switch (test) {
        case Test::CAR: {
            product_name = "CAR";
            break;
        }
        case Test::MOTOR: {
            product_name = "MOTOR";
            break;
        }
        default:
            throw std::runtime_error("NO SUCH PRODUCT NAME, PLEASE CHECK AGAIN!");
    }
    
    unsigned int productPrice = product->getPrice();
    
    std::cout << product_name << " PRICE IS: " << productPrice << std::endl;
}

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;
    
    std::cout << "Hello World" << std::endl;
    
    printProduct(Test::CAR);
    printProduct(Test::MOTOR);

    return 0;
}
