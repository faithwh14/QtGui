// Online C++ compiler to run C++ program online
#include <iostream>
#include <memory>

/* NOT YET COMPLETED
   NOT YET COMPLETED
   NOT YET COMPLETED */


class BaseDto;

typedef std::unique_ptr<BaseDto> BaseDtoPtr;

enum MessageId {
    GOCAR,
    GOBUS
};

enum JsonType {
    SCALAR,
    ARRAY,
    OBJECT
};

enum ScalarType {
    STRING,
    INT,
    DOUBLE
};

enum VehicleType {
    CAR,
    BUS
};

// template <typename s>
// class JsonField {
//     public:
//     ScalarType GetType() {
//         return
//     }
//     private:
    
// }

// class ScalarJsonField: public JsonField {}
// class 

class JsonBase {
    public:
    bool Serialize() {
        return true;
    }
    bool Deserialize() {
        return true;
    }
};

class JsonObject: public JsonBase {
  public:
  JsonObject(JsonObject* parent = nullptr): m_parent(parent) {}
  ~JsonObject() {}
  
  private:
  JsonObject* m_parent;
};

class BaseDto: public JsonObject {
    public:
    void set_messageid(MessageId msgid) { m_msgid = msgid; }
    void set_status(unsigned int status) { m_status = status; }
    
    bool Serialize() { 
        std::cout << "THIS IS BASEDTO SERIALIZE FUNCTION" << std::endl;
        return m_root.Serialize();
    }
    bool Deserialize() {
        std::cout << "THIS IS BASEDTO DESERIALIZE FUNCTION" << std::endl;
        return m_root.Deserialize();
    }
    
    void SetJsonObject(const JsonObject& root) { m_root = root; }
    
    protected:
    BaseDto(): JsonObject() {}
    // ~BaseDto() = default;
    
    JsonBase m_root;
    MessageId m_msgid;
    unsigned int m_status;
};

class CarDto: public BaseDto {
    public:
    CarDto(): BaseDto() {
        std::cout << "THIS IS CAR DTO CONSTRUCTOR" << std::endl;
    }
    ~CarDto() {}
};

class BusDto: public BaseDto {
    public:
    BusDto(): BaseDto() {
        std::cout << "THIS IS BUS DTO CONSTRUCTOR" << std::endl;
    }
    ~BusDto() {}
};

class RequestFactory {
    public:
    static BaseDtoPtr MakeDto(VehicleType vehicle) {
        BaseDtoPtr dto;
        switch (vehicle) {
            case CAR: {
                dto = std::make_unique<CarDto>();
                dto->set_messageid(MessageId::GOCAR);
                dto->set_status(0);  // test only
                break;
            }
            case BUS: {
                dto = std::make_unique<BusDto>();
                dto->set_messageid(MessageId::GOBUS);
                dto->set_status(1050);  // test for error status code
                break;
            }
            default: {
                throw std::runtime_error("No Dto for VehicleType Enum: " + static_cast<int>(vehicle));
            }
        }
        return dto;
    }
};

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;
    BaseDtoPtr dto = RequestFactory::MakeDto(VehicleType::CAR);
    if (!dto->Serialize()) {
        std::cout << "FAILED TO SERIALIZE DTO" << std::endl;
    }

    return 0;
}
