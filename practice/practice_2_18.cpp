/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdio.h>
#include <set>

enum ShopClass {
    LUXURY,
    INTERNATIONAL,
    NORMAL,
    CUSTOM   // no standard
};

class Shopping {
    public:
    Shopping(ShopClass shopclass) {
        m_shopClass = shopclass;
        
        switch (m_shopClass) {
            case LUXURY: {
                setDimension(100, 50, 50);
                break;
            }
            case INTERNATIONAL: {
                setDimension(80, 45, 45);
                break;
            }
            case NORMAL: {
                setDimension(30, 15, 30);
                break;
            }
            default: {
                throw std::runtime_error("SOMETHING IS WRONG HERE");
            }
        }
    }
    Shopping(int length, int width, int height) {
        m_shopClass = CUSTOM;
        setDimension(length, width, height);
    }
    virtual ~Shopping() {}
    
    int getDimension() {
        return m_length * m_width * m_height;
    }
    
    protected:
    int m_length;
    int m_width;
    int m_height;
    
    ShopClass m_shopClass;
    
    private:
    void setDimension(int length, int width, int height) {
        m_length = length;
        m_width = width;
        m_height = height;
    }
};

class OneUtama: public Shopping {
    public:
    OneUtama(): Shopping(INTERNATIONAL) {
        std::cout << "OneUtama MALL IS BUILD" << std::endl;
    }
};

class TRX: public Shopping {
    public:
    TRX(): Shopping(LUXURY) {
        std::cout << "TRX MALL IS BUILD" << std::endl;
    }
};

class SunwayPyramid: public Shopping {
    public:
    SunwayPyramid(): Shopping(INTERNATIONAL) {
        std::cout << "SunwayPyramid MALL IS BUILD" << std::endl;
    }
};

class Pavalion: public Shopping {
    public:
    Pavalion(): Shopping(LUXURY) {
        std::cout << "Pavalion MALL IS BUILD" << std::endl;
    }
};

class MidValley: public Shopping {
    public:
    MidValley(): Shopping(INTERNATIONAL) {
        std::cout << "MidValley MALL IS BUILD" << std::endl;
    }
};

class SungeiWang: public Shopping {
    public:
    SungeiWang(): Shopping(60, 35, 40) {
        std::cout << "SungeiWang MALL IS BUILD" << std::endl;
    }
};

/******************* MAKE ALL SHOPPING MALL *******************/
class MakeMall {
    public:
    static MakeMall* GetInstance() {
        static MakeMall* makeMall;
        if (makeMall == nullptr) {
            makeMall = new MakeMall();
        }
        return makeMall;
    }
    ~MakeMall() {
        for (auto& mall: shoppingMall) {
            if (mall != nullptr) {
                delete mall;
                std::cout << "Mall is deleted" << std::endl;
            }
        }
        std::cout << "SUCCESSFULLY DEALLOCATE ALL SHOPPING MEMORY" << std::endl;
    }
    private:
    MakeMall() {
        shoppingMall = {new TRX(), new OneUtama(), new SunwayPyramid(), new Pavalion(), new MidValley(), new SungeiWang()};
    }
    // ~MakeMall() {
    //     for (auto& mall: shoppingMall) {
    //         if (mall != nullptr) {
    //             delete mall;
    //         }
    //     }
    //     std::cout << "SUCCESSFULLY DEALLOCATE ALL SHOPPING MEMORY" << std::endl;
    // }

    std::set<Shopping*> shoppingMall;  // default should be empty
};

int main()
{
    std::cout<<"Hello World" << std::endl;
    
    // TRX trx;
    // int total_dimension = trx.getDimension();
    
    // std::cout << "TOTAL SIZE IN VOLUME FOR TRX MALL IS: " << total_dimension << std::endl;
    
    static MakeMall* makeMall = MakeMall::GetInstance();
    
    delete makeMall;

    return 0;
}
