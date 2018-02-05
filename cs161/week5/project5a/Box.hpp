/*********************************************************************
** Author: Tony Huynh
** Date: 2/07/2018
** Description: Box class header file
*********************************************************************/
#ifndef BOX_HPP
#define BOX_HPP

// Box class declaration
class Box {
    private: // Private member variables
        double height;
        double width;
        double length;

    public: // Member function prototype
        Box(); // Default constructor
        Box(double h, double w, double l);
        void setHeight(double h);
        void setWidth(double w);
        void setLength(double l);
        double calcVolume();
        double calcSurfaceArea();
        // void toString(); // REMOVED for assignment submission
};
#endif