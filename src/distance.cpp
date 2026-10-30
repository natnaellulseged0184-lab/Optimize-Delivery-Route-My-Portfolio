#include "distance.h"

#include <cmath>

double euclideanDistance(const Location& a, const Location& b) {
    const double dx = a.x - b.x;
    const double dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}
