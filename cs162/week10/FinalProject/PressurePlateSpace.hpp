/*********************************************************************
** Program name: Labyrinth Escape
** Author: Tony Huynh
** Date: 6/12/2018
** Description: Pressure plate class respresents a switch. It requires
** a heavy object in order to activate.
*********************************************************************/
#ifndef PRESSURE_PLATE_SPACE_HPP_
#define PRESSURE_PLATE_SPACE_HPP_

#include "Space.hpp"

class PressurePlateSpace : public Space {
    private:
        bool activated = false;
    public:
        PressurePlateSpace();
        bool isActivated();
        void trigger();
};
#endif  // PRESSURE_PLATE_SPACE_HPP_