#pragma once

#ifndef DYNAMIXEL_WRAPPER_LIB_PH54_100_S500_R_H
#define DYNAMIXEL_WRAPPER_LIB_PH54_100_S500_R_H

#include <dynamixel_wrapper_lib/config.h>

namespace dynamixel_wrapper_lib
{
    static Config PH54_100_S500_R
    {
        /* Drive Mode */
        Item(true, 10, 1),
        /* Operating Mode */
        Item(true, 11, 1),
        /* Homing Offset */
        Item(true, 20, 4),
        /* Moving Threshold */
        Item(true, 24, 4),
        /* Max Voltage Limit */
        Item(true, 32, 2),
        /* Min Voltage Limit */
        Item(true, 34, 2),
        /* Current Limit */
        Item(true, 38, 2),
        /* Acceleration Limit */
        Item(true, 40, 4),
        /* Velocity Limit */
        Item(true, 44, 4),
        /* Max Position Limit */
        Item(true, 48, 4),
        /* Min Position Limit */
        Item(true, 52, 4),
        /* Torque Enable */
        Item(true, 512, 1),
        /* LED Red */
        Item(true, 513, 1),
        /* LED Green */
        Item(true, 514, 1),
        /* LED Blue */
        Item(true, 515, 1),
        /* Hardware Error Status */
        Item(true, 518, 1),
        /* Velocity I Gain */
        Item(true, 524, 2),
        /* Velocity P Gain */
        Item(true, 526, 2),
        /* Position D Gain */
        Item(true, 528, 2),
        /* Position I Gain */
        Item(true, 530, 2),
        /* Position P Gain */
        Item(true, 532, 2),
        /* Goal Current */
        Item(true, 550, 2),
        /* Goal Velocity */
        Item(true, 552, 4),
        /* Profile Acceleration */
        Item(true, 556, 4),
        /* Profile Velocity */
        Item(true, 560, 4),
        /* Goal Position */
        Item(true, 564, 4),
        /* Moving */
        Item(true, 570, 1),
        /* Moving Status */
        Item(true, 571, 1),
        /* Present Current */
        Item(true, 574, 2),
        /* Present Velocity */
        Item(true, 576, 4),
        /* Present Position */
        Item(true, 580, 4),
        /* Present Temperature */
        Item(true, 594, 1),
        /* Resolution */
        1003846,
        /* Velocity Scaling Factor */
        0.01,
        /* Voltage Scaling Factor */
        0.1,
        /* Current Scaling Factor */
        1,
        /* Accerleration Scaling Factor */
        58000,
        /* Hardware Error Status to String*/
        {"Input voltage error", "Motor hall sensor error", "Overheating error", "Motor encorder error", "Electrical shock error", "Overload error", "", ""}
    };
} // namespace dynaixel_wrapper_lib

#endif