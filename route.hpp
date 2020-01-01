#include <iostream>

class Route {
private:
  std::string name_;
  unsigned short int departure_time_;
  unsigned short int arrival_time_;

public:
  Route(const std::string& name, unsigned short int departure_time,
        unsigned short int arrival_time)
      : name_(name), departure_time_(departure_time),
        arrival_time_(arrival_time) {}
  Route() : Route("Home", 2000, 2200) {}

  void set_name(const std::string& name) { name_ = name; }

  void set_departure_time(unsigned short int departure_time) {
    departure_time_ = departure_time;
  }

  void set_arrival_time(unsigned short int arrival_time) {
    arrival_time_ = arrival_time;
  }

  std::string name() { return name_; }

  unsigned short int departure_time() { return departure_time_; }
  unsigned short int arrival_time() { return arrival_time_; }

  virtual void display() {
    std::cout << "Route: " << name_ << "\n";
    std::cout << "Departure time: " << departure_time_ << "\n";
    std::cout << "Arrival time: " << arrival_time_ << "\n";
  }

  virtual std::string save_string(){
    std::string s = "[Route]\n";
    s += name_;
    s += "\n";
    s += std::to_string(departure_time_);
    s += "\n";
    s += std::to_string(arrival_time_);
    s += "\n";
    return s;
  }
};

class RouteManager {
private:
  Route routes_[100];
  unsigned short int size_;

public:
  RouteManager() : size_(0) {}
  void add(const Route& route) { routes_[size_++] = route; }
  void display_routes();
  void find_route(unsigned short int ttl);
  void save_routes(const std::string& filename);
  void load_routes(const std::string& filename);
};

Route create_route();
unsigned short int get_time_to_leave();
std::string get_filename();
