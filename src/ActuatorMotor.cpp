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

#include <Arduino.h>
#include "ActuatorMotor.hpp"

ActuatorMotor::ActuatorMotor(const uint8_t pin_pwm, const uint8_t pin_a, const uint8_t pin_b)
    : _pin_pwm(pin_pwm)
    , _pin_a(pin_a)
    , _pin_b(pin_b)
{
}

ActuatorMotor::ActuatorMotor()
{
}

ActuatorMotor::~ActuatorMotor()
{
}

void ActuatorMotor::SetParameters(const uint8_t pin_pwm, const uint8_t pin_a, const uint8_t pin_b)
{
	_pin_pwm = pin_pwm;
	_pin_a = pin_a;
	_pin_b = pin_b;
}

bool ActuatorMotor::Init()
{
    pinMode(_pin_pwm, OUTPUT);
    pinMode(_pin_a, OUTPUT);
    pinMode(_pin_b, OUTPUT);
	return (true);
}

void ActuatorMotor::Forward(const uint8_t pulse_width)
{
    digitalWrite(this->_pin_a, HIGH);
    digitalWrite(this->_pin_b, LOW);
	SetThrottle(pulse_width);
}

void ActuatorMotor::Reverse(const uint8_t pulse_width)
{
    digitalWrite(this->_pin_a, LOW);
    digitalWrite(this->_pin_b, HIGH);
	SetThrottle(pulse_width);
}

void ActuatorMotor::Halt()
{
    digitalWrite(this->_pin_a, LOW);
    digitalWrite(this->_pin_b, LOW);
}

void ActuatorMotor::SetThrottle(const uint8_t pulse_width)
{
    analogWrite(this->_pin_pwm, pulse_width);
}
