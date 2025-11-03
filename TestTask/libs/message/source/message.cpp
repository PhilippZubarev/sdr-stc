#include "message/message.h"

    std::vector<uint8_t> Messaging::SerializeMessage(const Message& msg){
        std::vector<uint8_t> result;

        uint32_t net_id = htonl(msg.id);
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&net_id);
        result.insert(result.end(), ptr, ptr+sizeof(net_id));

        uint32_t net_type = htonl(msg.payload.msgType);
        ptr = reinterpret_cast<const uint8_t*>(&net_type);
        result.insert(result.end(), ptr, ptr+sizeof(net_type));

        uint32_t net_size = htonl(msg.payload.size);
        ptr = reinterpret_cast<const uint8_t*>(&net_size);
        result.insert(result.end(), ptr, ptr+sizeof(net_size));

        result.insert(result.end(), msg.payload.data.begin(), msg.payload.data.end());

        return result;
    }

        Message Messaging::DeserializeMessage(const void* data, std::size_t size){
        Message msg;

        size_t head = sizeof(msg.id) + sizeof(msg.payload.msgType)+ sizeof(msg.payload.size);

        if (size<head){
            std::cout << "Error.Invalid size\n";
            std::exit(EXIT_FAILURE);
        }

        const uint8_t* ptr = static_cast<const uint8_t*>(data);

        memcpy((&msg.id),ptr,sizeof(msg.id));
        msg.id = ntohl(msg.id);
        ptr += sizeof(msg.id);

        memcpy(&msg.payload.msgType,ptr,sizeof(msg.payload.msgType));
        msg.payload.msgType = ntohl(msg.payload.msgType);
        ptr += sizeof(msg.payload.msgType);

        memcpy(&msg.payload.size,ptr,sizeof(msg.payload.size));
        msg.payload.size = ntohl(msg.payload.size);
        ptr += sizeof(msg.payload.size);

        msg.payload.data.insert(msg.payload.data.end(),ptr,ptr+msg.payload.size);
        

        return msg;
    }