 #ifndef MESSAGE_H
 #define MESSAGE_H
 
 
 #include <vector>  
 #include <iostream>
 #include <cstdint>  
 #include <arpa/inet.h> 
 #include <iomanip> 
 #include <iostream>
 #include <string.h>
namespace Messaging{
    struct Message {
        uint32_t id;       // Уникальный идентификатор сообщения (сетевой порядок байт!)
        struct Payload {
            uint32_t msgType;  // Тип сообщения (сетевой порядок байт!)
            uint32_t size;     // Размер массива данных `data` в байтах (сетевой порядок байт!)
            std::vector<uint8_t> data; // Массив байт полезной нагрузки (например, текст в UTF-8)
            Payload(uint32_t type, std::vector<uint8_t> &d) : msgType(type), size(d.size()), data(d) {}
            Payload(): msgType(0), size(0) {}
            ~Payload();
        } payload;

        std::vector<uint8_t> SerializeMessage(const Message& msg);

        Message (uint32_t id, uint32_t type, std::vector<uint8_t> &d) : id(id), payload(type,d) {}
        Message () : id(0), payload() {}
        ~Message();
    };

std::vector<uint8_t> SerializeMessage(const Message& msg);
Message DeserializeMessage(const void* data, std::size_t size);
}
#endif