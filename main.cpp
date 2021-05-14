#include <iostream>
#include <string>
#include "BFC.hpp"

int main() {

    std::cout << "Please enter your string here: ";
    BFC* bfc = new BFC();
    bfc->set_string_getter();
    std::cout << "Do you want spacing [y/n]: ";

    char yn;
    std::cin >> yn;
    std::cin.get();

    bfc->createBrainFuck((yn == 'y'));
    std::cin.get();
}