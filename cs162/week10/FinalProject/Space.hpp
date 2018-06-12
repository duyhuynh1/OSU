/*********************************************************************
** Program name: Labyrinth Escape
** Author: Tony Huynh
** Date: 6/12/2018
** Description: Space class is the base class that defines all used
** functions by all derived spaces. The Space pointers are used to
** link other spaces together
*********************************************************************/
#ifndef SPACE_HPP_
#define SPACE_HPP_

#include "Menu.hpp"
#include "Option.hpp"

class Space {
    private:
        std::string type = "Space";
        Menu mMenu;
    public:
        Space* top = nullptr;
        Space* right = nullptr;
        Space* left = nullptr;
        Space* bottom = nullptr;
        Space();
        Space(std::string type);
        virtual ~Space();
        virtual std::string getItem();
        virtual bool isEmpty();
        virtual bool isActivated();
        virtual void trigger();
        virtual bool isLocked();
        int getMovement();
        std::string getType();
        void topConnectToBottomOf(Space&);
        void bottomConnectToTopOf(Space&);
        void rightConnectToLeftOf(Space&);
        void leftConnectToRightOf(Space&);
};
#endif  // SPACE_HPP_