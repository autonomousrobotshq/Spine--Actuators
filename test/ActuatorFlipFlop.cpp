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
#include <ArduinoUnitTests.h>

#include "ActuatorFlipFlop.hpp"

// example 

#define PIN 10

unittest(ActuatorFlipFlop_Normal)
{
	GodmodeState* state = GODMODE();   // get access to the state

	bool default_state = false;
	bool inverted = false;
	ActuatorFlipFlop relay(PIN, inverted);
	relay.Init(default_state);
	assertTrue(state->digitalPin[PIN] == LOW);
	relay.SetState(true);
	assertTrue(state->digitalPin[PIN] == HIGH);
}

unittest(ActuatorFlipFlop_Inverted)
{
	GodmodeState* state = GODMODE();   // get access to the state

	bool default_state = false;
	bool inverted = true;
	ActuatorFlipFlop relay(PIN, inverted);
	relay.Init(default_state);
	assertTrue(state->digitalPin[PIN] == HIGH);
	relay.SetState(true);
	assertTrue(state->digitalPin[PIN] == LOW);
}

unittest(ActuatorFlipFlop_SetParameters)
{
	GodmodeState* state = GODMODE();   // get access to the state

	bool default_state = false;
	bool inverted = true;
	ActuatorFlipFlop relay;
	relay.SetParameters(PIN, inverted);
	relay.Init(default_state);
	assertTrue(state->digitalPin[PIN] == HIGH);
	relay.SetState(true);
	assertTrue(state->digitalPin[PIN] == LOW);
}

unittest_main()
