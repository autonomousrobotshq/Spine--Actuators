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
#include "ActuatorFlipFlop.hpp"

ActuatorFlipFlop::ActuatorFlipFlop(const uint8_t pin, const bool inverted)
    : _pin(pin)
	, _inverted(inverted)
{
}

ActuatorFlipFlop::ActuatorFlipFlop()
{
}

ActuatorFlipFlop::~ActuatorFlipFlop()
{
}

void ActuatorFlipFlop::SetParameters(const uint8_t pin, const bool inverted)
{
	_pin = pin;
	_inverted = inverted;
}

bool ActuatorFlipFlop::Init(const bool default_state)
{
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, _inverted ^ default_state); //pull up/down
	return (true);
}

void ActuatorFlipFlop::SetState(const bool state)
{
    _state = state;
    digitalWrite(_pin, _inverted ^ _state);
}

bool ActuatorFlipFlop::Toggle()
{
    _state = 1 ^ _state;
    digitalWrite(_pin, _inverted ^ _state);
	return (_inverted ^ _state);
}

bool ActuatorFlipFlop::GetState()
{
    return (_inverted ^ _state);
}
