#pragma once

#ifndef DYNAMIXEL_WRAPPER_LIB_CONFIG_H
#define DYNAMIXEL_WRAPPER_LIB_CONFIG_H

#include <string>

namespace dynamixel_wrapper_lib
{
    struct TableItem
    {
        TableItem() {}
        TableItem(bool e, uint a, uint s) : enabled(e), address(a), size(s) {}
        bool enabled;
        uint address;
        uint size;
    };

    using Item = TableItem;

    struct Config
    {
        Item drive_mode;
        Item operating_mode;
        Item homing_offset;
        Item moving_threshold;
        Item max_voltage_limit;
        Item min_voltage_limit;
        Item current_limit;
        Item acceleration_limit;
        Item velocity_limit;
        Item max_position_limit;
        Item min_position_limit;
        Item torque_enable;
        Item led_red;
        Item led_green;
        Item led_blue;
        Item hardware_error_status;
        Item velocity_i_gain;
        Item velocity_p_gain;
        Item position_d_gain;
        Item position_i_gain;
        Item position_p_gain;
        Item goal_current;
        Item goal_velocity;
        Item profile_acceleration;
        Item profile_velocity;
        Item goal_position;
        Item moving;
        Item moving_status;
        Item present_current;
        Item present_velocity;
        Item present_position;
        Item present_temperature;
        double resolution;
        double velocity_scaling_factor;
        double voltage_scaling_factor;
        double current_scaling_factor;
        double acceleration_scaling_factor;
        std::string error_code[8];
    };

} // namespace dynamixel_wrapper_lib

#include "dynamixel_wrapper_lib/configs/H42_20_S300_R.h"
#include "dynamixel_wrapper_lib/configs/H54_100_S500_R.h"
#include "dynamixel_wrapper_lib/configs/H54_200_S500_R.h"
#include "dynamixel_wrapper_lib/configs/PH42_20_S300_R.h"
#include "dynamixel_wrapper_lib/configs/PH54_100_S500_R.h"
#include "dynamixel_wrapper_lib/configs/PH54_200_S500_R.h"

#endif