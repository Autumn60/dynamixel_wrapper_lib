#pragma once

#ifndef DYNAMIXEL_WRAPPER_LIB_HANDLER_H
#define DYNAMIXEL_WRAPPER_LIB_HANDLER_H

#include <ros/ros.h>
#include <dynamixel_sdk/dynamixel_sdk.h>

namespace dynamixel_wrapper_lib
{
    class Handler
    {
        public:
            Handler() {}
            Handler(const std::string& port_name, const int& baudrate, const float& protcol_version=2.0);
            void init(const std::string& port_name, const int& baudrate, const float& protcol_version=2.0);
            inline dynamixel::PortHandler* GetPortHandler() { return _portHandler; }
            inline dynamixel::PacketHandler* GetPacketHandler() { return _packetHandler; }
        private:
            dynamixel::PortHandler* _portHandler;
            dynamixel::PacketHandler* _packetHandler;
    };  // class Handler

} // namespace dynamixel_wrapper_lib

#endif