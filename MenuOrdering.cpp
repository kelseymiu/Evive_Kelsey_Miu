//  Name: MenuOrdering.cpp
// Author: Kelsey Miu
// Purpose: Evive Assessment

#include "MenuOrdering.h"

MenuOrdering::MenuOrdering() {
    menu["breakfast"] = {"Eggs", "Toast", "Coffee"};
    menu["lunch"] = {"Sandwich", "Chips", "Soda"};
    menu["dinner"] = {"Steak", "Potatoes", "Wine", "Cake"};
}

std::vector<int> MenuOrdering::readItems(const iter &it,
                                         const std::string &order) {
    std::vector<int> items((it->second).size(), 0);
    std::stringstream ss(order);
    std::string line;
    while (getline(ss, line, ',')) {
        if (inRange(it, line)) {
            items[std::stoi(line) - 1]++;
        } else {
            return {};
        }
    }
    return items;
}

std::string MenuOrdering::checkValidInput(const iter &it, const std::vector<int> &items) {
    // checking whether input is a meal
    if (it == menu.end()) {
        return "Unable to process: Not a meal";
    }

    std::string output;

    // checking whether main and sides are ordered
    if (items[0] == 0) {
        output += "Unable to process: Main is missing";
        if (items[1] == 0) {
            output += ", side is missing";
        }
        return output;
    } else if (items[1] == 0) {
        output += "Unable to process: Side is missing";
        return output;
    } else if (it->first == "dinner" && items[3] == 0) {
        return "Unable to process: Dessert is missing";
    }

    // checking that the proper quantities are ordered
    if (items[0] > 1) {
        return ("Unable to process: " + it->second[0] +
                " cannot be ordered more than once");
    }
    if (it->first != "lunch" && items[1] > 1) {
        return ("Unable to process: " + it->second[1] +
                " cannot be ordered more than once");
    }
    if (it->first != "breakfast" && items[2] > 1) {
        return ("Unable to process: " + it->second[2] +
                " cannot be ordered more than once");
    }
    return output;

}

std::string MenuOrdering::printOrder(const iter &it, const std::vector<int> &items) {
    std::string output;

    // getting main
    output += (it->second[0] + ", ");
    // getting sides
    output += it->second[1];
    if (it->first == "lunch" && items[1] > 1)
        output += ('(' + std::to_string(items[1]) + ')');
    output += ", ";
    // getting drink and dessert if necessary
    if (it->first != "dinner" && items[2] != 0)
        output += it->second[2];
    if (it->first == "breakfast" && items[2] > 1)
        output += ('(' + std::to_string(items[2]) + ')');
    else if (it->first != "dinner" && items[2] == 0)
        output += "Water";
    if (it->first == "dinner") {
        if (items[2] != 0)
            output += (it->second[2] + ", ");
        output += ("Water, " + it->second[3]);
    }
    return output;
}

std::string MenuOrdering::getMeal(std::string &order) {

    auto loc = order.find(' ');
    if (loc == std::string::npos) return "Unable to process: Invalid order format";
    std::string meal = order.substr(0, loc);
    std::transform(meal.begin(), meal.end(), meal.begin(), ::tolower);

    iter it = menu.find(meal);
    std::vector<int> items = readItems(it, order.substr(loc + 1));
    if (items.empty()) {
        return "Unable to process: Ordered items are out of range";
    }

    std::string checkValid = checkValidInput(it, items);
    if (checkValid != "") {
        return checkValid;
    }

    return printOrder(it, items);
}

bool MenuOrdering::inRange(const iter &it, std::string &line) {
    if (std::stoi(line) < 0 || std::stoi(line) > it->second.size()) {
        return false;
    }
    return true;
}