Write a class called Taxicab that has three int fields (data members) to store its current x- and y-coordinates and the total distance it has driven so far (the actual distance driven by the Taxicab, not the Euclidean distance from it's starting point).  The class should have a constructor that takes two parameters and uses them to initialize the coordinates, and also initializes the distance traveled to zero.  The class should have a default constructor that sets all three fields to zero.  The data members of this class do not need to be set after they are initialized, so this class doesn't need any set methods - therefore the constructors will directly assign values to the data members instead of calling set methods to do it.  The class should have a get method for each data member.  It should have a method called moveX that takes an int parameter that tells how far the Taxicab should shift left or right.  It should have a method called moveY that takes an int parameter that tells how far the Taxicab should shift up or down.  For example, the Taxicab class might be used as follows:

Taxicab cab1;
Taxicab cab2(5, -8);
cab1.moveX(3);
cab1.moveY(-4);
cab1.moveX(-1);
cout << cab1.getDistanceTraveled() << endl;
cab2.moveY(7);
cout << cab2.getYCoord() << endl;
Your functions should have the following names:

getXCoord
getYCoord
getDistanceTraveled
moveX
moveY

The files must be named: Taxicab.hpp and Taxicab.cpp