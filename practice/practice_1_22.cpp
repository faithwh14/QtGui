// Online C++ compiler to run C++ program online
#include <iostream>

enum Color {
    COLOR_UNKNOWN,
    RED,
    GREEN,
    YELLOW,
    BLUE
};

enum Size {
    SIZE_UNKNOWN,
    LARGE,
    MEDIUM,
    SMALL
};

enum Quality {
    HIGH,
    LOW
};

class Product {
    public:
    // getter
    unsigned int getPrice() const {
        return m_price;
    }
    unsigned int getQuantity() const {
        return m_quantity;
    }
    Color getColor() const {
        return m_color;
    }
    Size getSize() const {
        return m_size;
    }
    
    // setter
    void setPrice(const unsigned int& price) {
        m_price = price;
    }
    void setQuantity(const unsigned int& quantity) {
        m_quantity = quantity;
    }
    void setColor(Color color) {
        m_color = color;
    }
    void setSize(Size size) {
        m_size = size;
    }
    
    protected:
    Product(): m_price(0), m_quantity(0), m_color(Color::COLOR_UNKNOWN), m_size(Size::SIZE_UNKNOWN) {}
    ~Product() {}
    
    private:
    unsigned int m_price;
    unsigned int m_quantity;
    Color m_color;
    Size m_size;
};

class Apple: public Product {
    public:
    Apple() {
        // default
        setPrice(30);
        setQuantity(1200);
        setColor(Color::RED);
        setSize(Size::SMALL);
    }
    ~Apple() {}
};

class PineApple: public Product {
    public:
    PineApple() {
        // default
        setPrice(180);
        setQuantity(120);
        setColor(Color::YELLOW);
        setSize(Size::LARGE);
    }
    ~PineApple() {}
};


class IFactory {
    protected:
    virtual Product* MakeProduct(Quality quality) = 0;
};

class Fruit1Factory {
    /* This Factory only make high quality pineapple and low quality apple */
    public:
    static Product* MakeProduct(Quality quality) {
        Product* product = nullptr;
        switch (quality) {
            case Quality::HIGH: {
                product = new PineApple();
                product->setColor(Color::YELLOW);
                product->setSize(Size::LARGE);
                break;
            }
            case Quality::LOW: {
                product = new Apple();
                product->setColor(Color::GREEN);
                product->setSize(Size::SMALL);
                break;
            }
            default:
                throw std::runtime_error("SOMETHING IS WRONG");
        }
        return product;
    }
};

class Fruit2Factory {
    /* This Factory only make low quality pineapple and high quality apple */
    public:
    static Product* MakeProduct(Quality quality) {
        Product* product = nullptr;
        switch (quality) {
            case Quality::HIGH: {
                product = new Apple();
                product->setColor(Color::RED);
                product->setSize(Size::LARGE);
                break;
            }
            case Quality::LOW: {
                product = new PineApple();
                product->setColor(Color::GREEN);
                product->setSize(Size::SMALL);
                break;
            }
            default:
                throw std::runtime_error("SOMETHING IS WRONG");
        }
        return product;
    }
};


int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;
    
    Product* lowApple = Fruit1Factory::MakeProduct(Quality::LOW);
    Product* highApple = Fruit2Factory::MakeProduct(Quality::HIGH);
    Product* lowPineApple = Fruit2Factory::MakeProduct(Quality::LOW);
    Product* highPineApple = Fruit1Factory::MakeProduct(Quality::HIGH);

    return 0;
}





