#ifndef DIE_HPP
#define DIE_HPP

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>     // REMOVE

class Die {
    protected:
        int numberOfSides;
    public:
        Die(int side);
        int roll();
};
#endif  // DIE_HPP