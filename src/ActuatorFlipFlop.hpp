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

#ifndef ACTUATOR_FLIPFLOP_HPP
#define ACTUATOR_FLIPFLOP_HPP

#include "stdint.h"
#include "Actuator.hpp"

class ActuatorFlipFlop : public Actuator {
public:
    ActuatorFlipFlop(const uint8_t pin, const bool inverted);
    ActuatorFlipFlop();
    ~ActuatorFlipFlop();
	void SetParameters(const uint8_t pin, const bool inverted);
	bool Init(const bool default_state);
    void SetState(const bool state);
	bool Toggle();
    bool GetState();
private:
    bool _state;
	bool _inverted;
    uint8_t _pin;
};

#endif
