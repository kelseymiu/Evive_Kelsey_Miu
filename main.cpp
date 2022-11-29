//  Name: main.cpp
// Author: Kelsey Miu
// Purpose: test file for Evive Assessment

#include <iostream>
#include <sstream>
#include <stdexcept>

#include "MenuOrdering.h"

void testBreakfast(std::ostream &out);

void testLunch(std::ostream &out);

void testDinner(std::ostream &out);

void testInvalidOrders(std::ostream &out);

int main() {
    testBreakfast(std::cout);
    testLunch(std::cout);
    testDinner(std::cout);
    testInvalidOrders(std::cout);
    return 0;
}

// Test 1: testing .size() on empty DNA objects
void testBreakfast(std::ostream &out) {
    MenuOrdering test;

    std::string input = "Breakfast 1,2,3";
    if (test.getMeal(input) != "Eggs, Toast, Coffee") {
        std::cout << "FAIL" << std::endl;
    }

    std::string input2 = "Breakfast 2,3,1";
    if (test.getMeal(input2) != "Eggs, Toast, Coffee") {
        std::cout << "FAIL" << std::endl;
    }

    std::string input3 = "Breakfast 1,2,3,3,3";
    if (test.getMeal(input3) != "Eggs, Toast, Coffee(3)") {
        std::cout << "FAIL" << std::endl;
    }

    std::string input4 = "Breakfast 1, 2, 3 ";
    if (test.getMeal(input4) != "Eggs, Toast, Coffee") {
        std::cout << "FAIL" << std::endl;
    }

    std::string input5 = "breakFAST 1,2,3";
    if (test.getMeal(input4) != "Eggs, Toast, Coffee") {
        std::cout << "FAIL" << std::endl;
    }
}

void testLunch(std::ostream &out) {
    MenuOrdering test;
    std::string input5 = "Lunch 1,2,3";
    if (test.getMeal(input5) != "Sandwich, Chips, Soda") {
        std::cout << "FAIL" << std::endl;
    }

    std::string input = "Lunch 1,2";
    if (test.getMeal(input) != "Sandwich, Chips, Water") {
        std::cout << "FAIL" << std::endl;
    }

    std::string input2 = "Lunch 1,1,2, 3";
    if (test.getMeal(input2) !=
        "Unable to process: Sandwich cannot be ordered more than once") {
        std::cout << "FAIL" << std::endl;
    }

    std::string input3 = "Lunch 1,2,2";
    if (test.getMeal(input3) != "Sandwich, Chips(2), Water") {
        std::cout << "FAIL" << std::endl;
    }

    std::string input4 = "Lunch ";
    if (test.getMeal(input4) != "Unable to process: Main is missing, side is missing") {
        std::cout << "FAIL" << std::endl;
    }
}

void testDinner(std::ostream &out) {
    MenuOrdering test;

    std::string input = "Dinner 1,2,3,4";
    if (test.getMeal(input) != "Steak, Potatoes, Wine, Water, Cake") {
        std::cout << "FAIL" << std::endl;
    }

    std::string input2 = "Dinner 1,2,3";
    if (test.getMeal(input2) != "Unable to process: Dessert is missing") {
        std::cout << "FAIL" << std::endl;
    }

    std::string input3 = "Dinner 1,2,2,4,5";
    if (test.getMeal(input3) != "Unable to process: Ordered items are out of range") {
        std::cout << "FAIL" << std::endl;
    }
}

void testInvalidOrders(std::ostream &out) {
    MenuOrdering test;
    std::string input = "Breakfast 1,2,3,4";
    if (test.getMeal(input) != "Unable to process: Ordered items are out of range") {
        std::cout << "FAIL" << std::endl;
    }
    std::string input2 = "Break";
    if (test.getMeal(input2) != "Unable to process: Invalid order format") {
        std::cout << "FAIL" << std::endl;
    }
    std::string input3 = "Breakfast1,2,3";
    if (test.getMeal(input3) != "Unable to process: Invalid order format") {
        std::cout << "FAIL" << std::endl;
    }
    std::string input4 = "Breakfast 1,2,3,1,1";
    if (test.getMeal(input4) != "Unable to process: Eggs cannot be ordered more than once") {
        std::cout << "FAIL" << std::endl;
    }

    std::string input5 = "Breakfast 1";
    if (test.getMeal(input5) != "Unable to process: Side is missing") {
        std::cout << "FAIL" << std::endl;
    }

    std::string input6 = "Breakfast 1, 2, 2, 3";
    if (test.getMeal(input6) != "Unable to process: Toast cannot be ordered more than once") {
        std::cout << "FAIL" << std::endl;
    }

    std::string input7 = "Lunch 1,2,3,3,3";
    if (test.getMeal(input7) != "Unable to process: Soda cannot be ordered more than once") {
        std::cout << "FAIL" << std::endl;
    }

    std::string input8 = "Dinner 1,2,3,3";
    if (test.getMeal(input8) != "Unable to process: Dessert is missing") {
        std::cout << "FAIL" << std::endl;
    }
}