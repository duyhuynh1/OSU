#ifndef LOADED_DIE_HPP
#define LOADED_DIE_HPP

#include <iostream>
#include "Die.hpp"

class LoadedDie: public Die {
    private:
        // const int N_SIDES;
    public:
        LoadedDie(int side);
        int roll();
};
#endif  /* LOADED_DIE_HPP */