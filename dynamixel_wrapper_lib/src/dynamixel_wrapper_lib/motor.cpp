#include "dynamixel_wrapper_lib/motor.h"

namespace dynamixel_wrapper_lib
{
    Motor::Motor(const int& id, Handler& handler, Config& config)
    {
        _id = id;
        _handler = &handler;
        _config = &config;
        setTorqueEnable(false);
    }

    void Motor::init(const int& id, Handler& handler, Config& config)
    {
        _id = id;
        _handler = &handler;
        _config = &config;
        setTorqueEnable(false);
    }

    void Motor::setLED(int r, int g, int b)
    {
        write(_config->led_red, r);
        write(_config->led_green, g);
        write(_config->led_blue, b);
    }

    void Motor::write(Item item, int value)
    {
        if(!item.enabled) return;
        
        int address = item.address;
        int byte_size = item.size;
        
        bool error;

        if(byte_size == 1)
        {
            error = _handler->GetPacketHandler()->write1ByteTxRx(_handler->GetPortHandler(), _id, address, value);
        }
        else if(byte_size == 2)
        {
            error = _handler->GetPacketHandler()->write2ByteTxRx(_handler->GetPortHandler(), _id, address, value);
        }
        else if(byte_size == 4)
        {
            error = _handler->GetPacketHandler()->write4ByteTxRx(_handler->GetPortHandler(), _id, address, value);
        }
        else
        {
            ROS_ERROR("Byte size is undefined");
        }
        
        if (error)
        {
            ROS_ERROR("Failed to connect for Dynamixel ID %d", _id);
        }
    }

    uint32_t Motor::read(Item item)
    {
        if (!item.enabled) return 0;    

        int address = item.address;
        int byte_size = item.size;
        uint8_t value8;
        uint16_t value16;
        uint32_t value32;
        
        if(byte_size == 1)
        {
            _handler->GetPacketHandler()->read1ByteTxRx(_handler->GetPortHandler(), _id, address, &value8);
            value32=value8;
        }
        else if(byte_size == 2)
        {
            _handler->GetPacketHandler()->read2ByteTxRx(_handler->GetPortHandler(), _id, address, &value16);
            value32=value16;
        }
        else if(byte_size == 4)
        {
            _handler->GetPacketHandler()->read4ByteTxRx(_handler->GetPortHandler(), _id, address, &value32);
        }
        else
        {
            ROS_ERROR("Byte size is undefined");
            return 0;
        }
        
        return value32;
    }

    int32_t Motor::read_signed(Item item)
    {
        if(!item.enabled) return 0;

        int address = item.address;
        int byte_size = item.size;
        uint8_t value8;
        uint16_t value16;
        uint32_t value32;
        int32_t value = 0;
        
        if(byte_size == 1)
        {
            _handler->GetPacketHandler()->read1ByteTxRx(_handler->GetPortHandler(), _id, address, &value8);
            value = value8;
            value = (value > INT8_MAX) ? (value - UINT8_MAX) : value;
        }
        else if(byte_size == 2)
        {
            _handler->GetPacketHandler()->read2ByteTxRx(_handler->GetPortHandler(), _id, address, &value16);
            value = value16;
            value = (value > INT16_MAX) ? (value - UINT16_MAX) : value;
        }
        else if(byte_size == 4)
        {
            _handler->GetPacketHandler()->read4ByteTxRx(_handler->GetPortHandler(), _id, address, &value32);
            value = value32;
            value = (value > INT32_MAX) ? (value - UINT32_MAX) : value;
        }
        else
        {
            ROS_ERROR("Byte size is undefined");
            return 0;
        }

        return value;
    }

} // namespace dynamixel_wrapper_lib