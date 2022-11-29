//  Name: MenuOrdering.h
// Author: Kelsey Miu
// Purpose: Evive Assessment

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

#ifndef EVIVE_KELSEY_MIU_MENUORDERING_H
#define EVIVE_KELSEY_MIU_MENUORDERING_H

class MenuOrdering {
public:
    typedef std::unordered_map<std::string, std::vector<std::string>>::const_iterator iter;

    /**
    * Initializes menu
    */
    MenuOrdering();

    /**
     * Reads through string of items ordered seperated by commas
     * @param iterator pointing to correct meal in std::unordered_map menu
     * @param std::string of items that need to be read
     * @return std::vector storing quantities of main, side, drink, and dessert (if appropriate),
     *         and empty vector if any item is out of range
     */
    std::vector<int> readItems(const iter &, const std::string &);

    /**
     * Returns an error message if a main is missing, a side is missing, or an inappropriately
     * amount of food is ordered
     * @param iterator pointing to correct meal in std::unordered_map menu
     * @param std::vector storing quantities of main, side, drink, and dessert (if appropriate)
     * @return std::string of invalid input error message, if necessary, empty std::string if not
     */
    std::string checkValidInput(const iter &, const std::vector<int> &);

    /**
     * Returns an correctly displayed meal in ordering of main, side, drink
     * @param iterator pointing to correct meal in std::unordered_map menu
     * @param std::vector storing quantities of main, side, drink, and dessert (if appropriate)
     * @return std::string of correctly displayed meal
     */
    std::string printOrder(const iter &, const std::vector<int> &);

    /**
     * Processes order and input and returns displayed order if input is valid, error message if
     * if input is invalid
     * @param std::string order input
     * @return std::string of correctly displayed meal or error message
     */
    std::string getMeal(std::string &);

    /**
     * Returns whether inputted item is on menu
     * @param iterator pointing to correct meal in std::unordered_map menu
     * @param std::string of item
     * @return true if item is on the menu, false if item is not on the menu
     */
    bool inRange(const iter&, std::string&);

private:

    /**
     * Private std::unordered_map storing menu items
     */
    std::unordered_map<std::string, std::vector<std::string>> menu;
};

#endif // EVIVE_KELSEY_MIU_MENUORDERING_H