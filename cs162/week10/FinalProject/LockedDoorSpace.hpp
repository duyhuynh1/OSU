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