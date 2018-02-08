# Assignment 6
## Requirements
 - Write a class called Player that has four data members: a string for the player's name, and an int for each of these stats: points, rebounds and assists. 
     - The class should have a default constructor that initializes the name to the empty string ("") and initializes each of the stats to -1.
     - It should also have a constructor that takes four parameters and uses them to initialize the data members.
     - It should have get methods for each data member.
     - It should have set methods for each of the stats.
     - It should have a bool method called hasMorePointsThan that takes a Player parameter and returns true if the Player that is executing the function has more points than the Player that was passed as a parameter. Otherwise it should return false. 
        - For example, if we have the function call "p1.hasMorePointsThan(p2)", then it should return true if p1 has more points than p2, but return false otherwise.
 - Next write a class called Team that has five data members of type Player: a point guard, a shooting guard, a small forward, a power forward, and a center.
     - The class should have a constructor that takes five Players and uses them to initialize each of those data members (in the given order).
     - The class should have get and set methods for each data member. 
     - It should have a method named totalPoints that returns the sum of the points for all players on the team.

## Example
For example, these classes might be used as follows:
```C++
    Player p1("Charlotte", 24, 10, 7);
    Player p2("Emily", 21, 13, 9);
    Player p3("Anne", 20, 10, 8);
    Player p4("Jane", 19, 10, 10);
    Player p5("Mary", 18, 11, 8);
    p5.setRebounds(12);
    Team team1(p1, p2, p3, p4, p5);
    Player p = team1.getShootingGuard();
    cout << p.getName() << endl;
```
## TODO List
The methods of the Player class should have the following names:

     - [DONE] getName
     - [DONE] setPoints
     - [DONE] getPoints
     - [DONE] setRebounds
     - [DONE] getRebounds
     - [DONE] setAssists
     - [DONE] getAssists
     - [DONE] hasMorePointsThan
The methods of the Team class should have the following names:

     - setPointGuard
     - getPointGuard
     - setShootingGuard
     - getShootingGuard
     - setSmallForward
     - getSmallForward
     - setPowerForward
     - getPowerForward
     - setCenter
     - getCenter
     - totalPoints
The files must be named: Player.hpp, Player.cpp, Team.hpp and Team.cpp