#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <utility>

struct Location {
    std::string name;
    double x;
    double y;

    Location(std::string name = "", double x = 0.0, double y = 0.0)
        : name(std::move(name)), x(x), y(y) {}
};

#endif
