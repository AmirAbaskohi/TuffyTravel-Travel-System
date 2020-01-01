#include "route.hpp"
#include <fstream>
#include <iostream>

Route create_route() {

  Route my_route;
  std::string name;
  unsigned short int time;

  std::cout << "Please enter the name of the route: ";
  std::getline(std::cin, name);
  my_route.set_name(name);

  std::cout << "Please enter the departure time of the route: ";
  std::cin >> time;
  std::cin.ignore();
  my_route.set_departure_time(time);

  std::cout << "Please enter the arrival time of the route: ";
  std::cin >> time;
  std::cin.ignore();
  my_route.set_arrival_time(time);
  std::cout << "\n";
  return my_route;
}

void RouteManager::display_routes() {
  std::cout << "Available Routes:\n\n";
  for (int i = 0; i < size_; i++) {
    routes_[i].display();
    std::cout << "\n";
  }
}

unsigned short int get_time_to_leave() {
  unsigned short int ttl = 0;
  std::cout << "Please enter the time you plan to leave: ";
  std::cin >> ttl;
  std::cin.ignore();
  return ttl;
}

std::string get_filename() {
  std::string filename;
  std::cout << "Please enter the filename: ";
  std::cin >> filename;
  std::cin.ignore();
  return filename;
}

void RouteManager::find_route(unsigned short int ttl) {
  if (size_ <= 0) {
    std::cout << "Sorry, there are no routes available.\n\n";
  } else {
    Route best_route;
    bool found_route = false;
    for (int i = 0; i < size_; i++) {
      if (!found_route && routes_[i].departure_time() >= ttl) {
        best_route = routes_[i];
        found_route = true;
      } else if (found_route && routes_[i].departure_time() >= ttl &&
                 routes_[i].departure_time() < best_route.departure_time()) {
        best_route = routes_[i];
        found_route = true;
      }
    }
    if (found_route) {
      std::cout << "We suggest you take this route:\n\n";
      best_route.display();
      std::cout << "\n";
    } else {
      std::cout << "Sorry, there is no route that leaves on or after the time "
                   "you plan to leave.\n\n";
    }
  }
}

void RouteManager::save_routes(const std::string& filename) {
  std::ofstream output_file;
  output_file.open(filename);
  output_file << size_ << "\n";
  for (int i = 0; i < size_; i++) {
    output_file << routes_[i].name() << "\n";
    output_file << routes_[i].departure_time() << "\n";
    output_file << routes_[i].arrival_time() << "\n";
  }
  output_file.close();
  std::cout << "File saved!\n\n";
}

void RouteManager::load_routes(const std::string& filename) {
  std::ifstream input_file;
  input_file.open(filename);
  if (input_file) {
    input_file >> size_;
    input_file.ignore();
    for (int i = 0; i < size_; i++) {
      std::string temp_name;
      int temp_departure_time = 0;
      int temp_arrival_time = 0;
      std::getline(input_file, temp_name);
      input_file >> temp_departure_time;
      input_file >> temp_arrival_time;
      input_file.ignore();

      routes_[i].set_name(temp_name);
      routes_[i].set_departure_time(temp_departure_time);
      routes_[i].set_arrival_time(temp_arrival_time);
    }
    std::cout << "File loaded!";
  } else {
    std::cout << "File does not exist.";
  }
  std::cout << "\n\n";
}
