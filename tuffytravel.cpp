#include "route.hpp"
#include <iostream>

int main() {
  char action = ' ';
  RouteManager manager;

  std::cout << "Welcome to TuffyTravel!\n\n";
  do {
    std::cout << "What do you want to do? \n";
    std::cout << "R - Create routes\n";
    std::cout << "D - Display routes\n";
    std::cout << "F - Find route\n";
    std::cout << "S - Save routes\n";
    std::cout << "L - Load routes\n";
    std::cout << "X - Exit\n";
    std::cout << "Action: ";
    std::cin >> action;
    std::cout << "\n";
    std::cin.ignore();

    if (action == 'R' || action == 'r') {
      manager.add(create_route());
    } else if (action == 'D' || action == 'd') {
      manager.display_routes();
    } else if (action == 'F' || action == 'f') {
      manager.find_route(get_time_to_leave());
    } else if (action == 'S' || action == 's') {
      manager.save_routes(get_filename());
    } else if (action == 'L' || action == 'l') {
      manager.load_routes(get_filename());
    }

  } while (action != 'x' && action != 'X');
  std::cout << "Thank you for using TuffyTravel!\n";

  return 0;
}
