#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

#include "distance.h"
#include "location.h"

int main() {
    const Location a("A", 0.0, 0.0);
    const Location b("B", 3.0, 4.0);

    const double expected = 5.0;
    const double actual = euclideanDistance(a, b);

    assert(std::fabs(actual - expected) < 1e-9);
    std::cout << "Distance test passed.\n";
    return 0;
}
