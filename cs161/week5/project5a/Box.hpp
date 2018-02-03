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
        Box(double heightIn, double widthIn, double lengthIn);
        void setHeight(double heightIn);
        void setWidth(double widthIn);
        void setLength(double lengthIn);
        double calcVolume(Box box);
        double calcSurfaceArea(Box box);
        std::string toString(); // REMOVED for assignment submission
};
#endif