#ifndef PRESSURE_PLATE_SPACE_HPP_
#define PRESSURE_PLATE_SPACE_HPP_

#include "Space.hpp"

class PressurePlateSpace : public Space {
    private:
        bool activated;
    public:
        PressurePlateSpace();
        bool isActivated();
        void trigger();
};
#endif  // PRESSURE_PLATE_SPACE_HPP_