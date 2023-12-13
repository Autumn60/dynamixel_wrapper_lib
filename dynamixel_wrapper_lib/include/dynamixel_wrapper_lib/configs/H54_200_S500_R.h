#pragma once

#ifndef DYNAMIXEL_WRAPPER_LIB_H54_200_S500_R_H
#define DYNAMIXEL_WRAPPER_LIB_H54_200_S500_R_H

#include <dynamixel_wrapper_lib/config.h>

namespace dynamixel_wrapper_lib
{
    static Config H54_200_S500_R
    {
        /* Drive Mode */
        Item(false, 0, 0),
        /* Operating Mode */
        Item(true, 11, 1),
        /* Homing Offset */
        Item(true, 13, 4),
        /* Moving Threshold */
        Item(true, 17, 4),
        /* Max Voltage Limit */
        Item(true, 22, 2),
        /* Min Voltage Limit */
        Item(true, 24, 2),
        /* Current Limit */
        Item(true, 0, 0),
        /* Acceleration Limit */
        Item(true, 26, 4),
        /* Velocity Limit */
        Item(true, 32, 4),
        /* Max Position Limit */
        Item(true, 36, 4),
        /* Min Position Limit */
        Item(true, 40, 4),
        /* Torque Enable */
        Item(true, 562, 1),
        /* LED Red */
        Item(true, 563, 1),
        /* LED Green */
        Item(true, 564, 1),
        /* LED Blue */
        Item(true, 565, 1),
        /* Hardware Error Status */
        Item(true, 892, 1),
        /* Velocity I Gain */
        Item(true, 586, 2),
        /* Velocity P Gain */
        Item(true, 588, 2),
        /* Position D Gain */
        Item(false, 0, 0),
        /* Position I Gain */
        Item(false, 0, 0),
        /* Position P Gain */
        Item(true, 594, 2),
        /* Goal Current */
        Item(false, 0, 0),
        /* Goal Velocity */
        Item(true, 600, 4),
        /* Profile Acceleration */
        Item(false, 0, 0),
        /* Profile Velocity */
        Item(false, 0, 0),
        /* Goal Position */
        Item(true, 596, 4),
        /* Moving */
        Item(true, 610, 1),
        /* Moving Status */
        Item(false, 0, 0),
        /* Present Current */
        Item(true, 621, 2),
        /* Present Velocity */
        Item(true, 615, 4),
        /* Present Position */
        Item(true, 611, 4),
        /* Present Temperature */
        Item(true, 625, 1),
        /* Resolution */
        501923,
        /* Velocity Scaling Factor */
        0.001992,
        /* Voltage Scaling Factor */
        0.1,
        /* Current Scaling Factor */
        16.11,
        /* Accerleration Scaling Factor */
        58000,
        /* Hardware Error Status to String*/
        {"Input voltage error", "Motor hall sensor error", "Overheating error", "Motor encorder error", "Electrical shock error", "Overload error", "", ""}
    };
} // namespace dynaixel_wrapper_lib

#endif