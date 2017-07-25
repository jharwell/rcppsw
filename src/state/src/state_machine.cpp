/**
 * @file state_machine.hpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
 *
 * This file is part of RCPPSW.
 *
 * RCPPSW is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * RCPPSW is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * RCPPSW.  If not, see <http://www.gnu.org/licenses/
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <assert.h>
#include "rcppsw/state/state_machine.hpp"

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
StateMachine::StateMachine(unsigned char maxStates) :
    _maxStates(maxStates),
    currentState(0),
    _eventGenerated(false),
    _pEventData(NULL)
{
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
// generates an external event. called once per external event
// to start the state machine executing
void StateMachine::ExternalEvent(unsigned char newState,
                                 EventData* pData)
{
    // if we are supposed to ignore this event
    if (newState == EVENT_IGNORED) {
        // just delete the event data, if any
        if (pData)
            delete pData;
    }
    else {
		// TODO - capture software lock here for thread-safety if necessary

        // generate the event and execute the state engine
        InternalEvent(newState, pData);
        StateEngine();

		// TODO - release software lock here
    }
}

// generates an internal event. called from within a state
// function to transition to a new state
void StateMachine::InternalEvent(unsigned char newState,
                                 EventData* pData)
{
	if (pData == NULL)
		pData = new EventData();

    _pEventData = pData;
    _eventGenerated = true;
    currentState = newState;
}

// the state engine executes the state machine states
void StateMachine::StateEngine(void)
{
    EventData* pDataTemp = NULL;

    // while events are being generated keep executing states
    while (_eventGenerated) {
        pDataTemp = _pEventData;  // copy of event data pointer
        _pEventData = NULL;       // event data used up, reset ptr
        _eventGenerated = false;  // event used up, reset flag

        assert(currentState < _maxStates);

		// get state map
        const StateStruct* pStateMap = GetStateMap();

        // execute the state passing in event data, if any
        (this->*pStateMap[currentState].pStateFunc)(pDataTemp);

        // if event data was used, then delete it
        if (pDataTemp) {
            delete pDataTemp;
            pDataTemp = NULL;
        }
    }
}
