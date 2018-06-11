#ifndef LOCKED_ITEM_SPACE_HPP_
#define LOCKED_ITEM_SPACE_HPP_

#include "Space.hpp"

class LockedItemSpace : public Space {
    private:
        const std::string error = "Nothing inside the chest...\n";
        std::string item = " ";
        int numOfItems = 1;
        bool locked = true;
    public:
        LockedItemSpace(std::string);
        std::string getItem();
        bool isEmpty();
        bool isLocked();
        void trigger();
};
#endif  // LOCKED_ITEM_SPACE_HPP_