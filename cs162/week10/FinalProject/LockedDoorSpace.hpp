/*********************************************************************
** Program name: Labyrinth Escape
** Author: Tony Huynh
** Date: 6/12/2018
** Description: Locked door space class is a derived Space class. It
** represents the exit of the labyrinth.
*********************************************************************/
#ifndef LOCKED_DOOR_SPACE_HPP_
#define LOCKED_DOOR_SPACE_HPP_

#include "Space.hpp"

class LockedDoorSpace : public Space {
    private:
        const std::string error = "Door is locked. Looks like it requires a \"door key\".\n";
        bool locked = true;
    public:
        LockedDoorSpace();
        bool isLocked();
        void trigger();
};
#endif  // LOCKED_DOOR_SPACE_HPP_