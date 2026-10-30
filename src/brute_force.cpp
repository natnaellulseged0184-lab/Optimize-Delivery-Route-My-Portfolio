#include "brute_force.h"

#include <algorithm>
#include <limits>
#include <vector>

std::vector<Location> bruteForceTSP(const std::vector<Location>& locations) {
    if (locations.empty()) {
        return {};
    }

    std::vector<Location> bestRoute = locations;
    double bestDistance = std::numeric_limits<double>::infinity();

    std::vector<Location> route = locations;
    do {
        double totalDistance = 0.0;
        for (size_t i = 1; i < route.size(); ++i) {
            const double dx = route[i - 1].x - route[i].x;
            const double dy = route[i - 1].y - route[i].y;
            totalDistance += std::sqrt(dx * dx + dy * dy);
        }

        if (totalDistance < bestDistance) {
            bestDistance = totalDistance;
            bestRoute = route;
        }
    } while (std::next_permutation(route.begin(), route.end()));

    return bestRoute;
}
