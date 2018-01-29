/*********************************************************************
** Author: Tony Huynh
** Date: 1/31/2018
** Description: Calculates the distance an object travels due to 
** gravity in a specific time period.
*********************************************************************/
#include <cmath>

// Function prototype
double fallDistance(double time);

double fallDistance(double time) {
    const double GRAVITY_VALUE = 9.8;
    double distance = 0;

    distance = 0.5 * GRAVITY_VALUE * pow(time, 2.0);
    return distance;
}


