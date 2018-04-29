/*********************************************************************
** Program name: Dice War Game
** Author: Tony Huynh
** Date: 04/22/2018
** Description: The Option class provides all the functions to check
** the user's input and reprompt the user if the input is invalid.
*********************************************************************/
#include "Option.hpp"

/**
 *	Option object default constructor
 */
Option::Option(std::string prompt, int min, int max) {
	this->prompt = prompt;
	this->min = min;
	this->max = max;
}

/**
 *  Validation algorithm will verify the user's input is an integer and check
 *  if the number is within the range specified by the min and max values
 */
int Option::getSelection() {
	std::string number;
    int result;
    bool valid = false;
    do {
        try {
            std::cout << prompt;
            // Analyze prompt to see if it only contains digits
            while (std::getline(std::cin, number) && number.end() != 
                   std::find_if_not(number.begin(), number.end(), &isdigit)) {
                std::cout << prompt;
            }
            // Handle empty inputs
            if (number.size() == 0) {
                result = -1;
            } else {
                result = stoi(number);
            }
        } catch (std::invalid_argument) {
            result = -1;    // Invalid argument exeception caught (e.g., " ")
        } catch (std::out_of_range) {
            result = -1;    // Out of range exception caught
        }
        if (result >= min && result <= max) {
            valid = true;
            return result;
        }
    } while (!valid);
    return -1;
}

/**
 *  Verify the user's input is an unsingned floating number
 */
float Option::getUnsignedFloat() {
    std::string number;
    std::size_t found;
    float result = 0.0;
    float minFloat = static_cast<float>(min);
    float maxFloat = static_cast<float>(max);
    bool valid = false;
    do {
        std::size_t occurence = 0;
        std::cout << prompt;
        std::getline(std::cin, number);
        found = number.find_first_not_of("1234567890.");
        if (found == std::string::npos) {
            // Check for multiple occurences of the character '.'
            occurence = std::count(number.begin(), number.end(), '.');
            if (occurence <= 1) {
                result = std::stof(number);
                if (result >= minFloat && result <= maxFloat) {
                    valid = true;
                }
            }
        }
    } while (!valid);
    return result;
}