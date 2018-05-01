/*********************************************************************
** Program name: Zoo Tycoon
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Animal class provides the required members to 
** inform the user about the Animal object.
*********************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		int baseFoodCost = 10;
		int age = 0;
		int cost = 0;
		int numberOfBabies = 0;
		int payoff = 0;
	public:
		Animal(int, int);
		Animal(int, int, int);
		Animal & operator=(const Animal *);		// copy constructor
		virtual ~Animal();
		virtual std::string getClassName() const;	// Do we need this? REMOVE??
		int getBaseFoodCost() const;
		virtual void setBaseFoodCost();
		int getAge() const;
		bool isAdult();
		void increaseAge();
		int getCost() const;
		int getNumberOfBabies() const;
		bool canGiveBirth();
		void hadChild();
		int getPayoff() const;
		virtual void setPayoff();
};
#endif	// ANIMAL_HPP