#include "dynamixel_wrapper_lib/handler.h"

namespace dynamixel_wrapper_lib
{

    Handler::Handler(const std::string& port_name, const int& baudrate, const float& protcol_version)
    {
        _portHandler = dynamixel::PortHandler::getPortHandler(port_name.c_str());
        _packetHandler = dynamixel::PacketHandler::getPacketHandler(protcol_version);
        
        if (!_portHandler->openPort())
        {
            ROS_ERROR("Failed to open the port!");
        }

        if (!_portHandler->setBaudRate(baudrate))
        {
            ROS_ERROR("Failed to set the baudrate!");
        }
    }

    void Handler::init(const std::string& port_name, const int& baudrate, const float& protcol_version)
    {
        _portHandler = dynamixel::PortHandler::getPortHandler(port_name.c_str());
        _packetHandler = dynamixel::PacketHandler::getPacketHandler(protcol_version);
        
        if (!_portHandler->openPort())
        {
            ROS_ERROR("Failed to open the port!");
        }

        if (!_portHandler->setBaudRate(baudrate))
        {
            ROS_ERROR("Failed to set the baudrate!");
        }
    }

}