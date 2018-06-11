#ifndef ITEM_SPACE_HPP_
#define ITEM_SPACE_HPP_

#include "Space.hpp"

class ItemSpace : public Space {
    private:
        // std::string synop
        const std::string error = "Nothing inside the chest...\n";
        std::string item = " ";
        int numOfItems = 1;
    public:
        ItemSpace(std::string);
        std::string getItem();
        bool isEmpty();
};
#endif  // ITEM_SPACE_HPP_