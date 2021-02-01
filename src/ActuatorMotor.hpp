//
// Spine - Spine - MCU code for robotics.
// Copyright (C) 2019-2021 Codam Robotics
//
// This file is part of Spine.
//
// Spine is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Spine is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Spine.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef ACTUATOR_MOTOR_HPP
#define ACTUATOR_MOTOR_HPP

#include <stdint.h>
#include "Actuator.hpp"

class ActuatorMotor : public Actuator {
public:
    ActuatorMotor(const uint8_t pin_pwm, const uint8_t pin_a, const uint8_t pin_b);
	ActuatorMotor();
    ~ActuatorMotor();
	void SetParameters(const uint8_t pin_pwm, const uint8_t pin_a, const uint8_t pin_b);
	bool Init();
    void Forward(const uint8_t pulse_width);
    void Reverse(const uint8_t pulse_width);
    void Halt();
    void SetThrottle(const uint8_t pulse_width);

private:
    uint8_t _pin_pwm;
    uint8_t _pin_a;
    uint8_t _pin_b;
};

#endif
