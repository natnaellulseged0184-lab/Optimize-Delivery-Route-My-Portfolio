#include "greedy.h"

#include <algorithm>
#include <limits>
#include <vector>

#include "distance.h"

std::vector<Location> nearestNeighborRoute(const std::vector<Location>& locations) {
    if (locations.empty()) {
        return {};
    }

    std::vector<Location> route;
    std::vector<bool> visited(locations.size(), false);
    size_t currentIndex = 0;

    route.push_back(locations[currentIndex]);
    visited[currentIndex] = true;

    while (route.size() < locations.size()) {
        double minDistance = std::numeric_limits<double>::infinity();
        size_t nextIndex = 0;

        for (size_t i = 0; i < locations.size(); ++i) {
            if (!visited[i]) {
                const double dist = euclideanDistance(route.back(), locations[i]);
                if (dist < minDistance) {
                    minDistance = dist;
                    nextIndex = i;
                }
            }
        }

        route.push_back(locations[nextIndex]);
        visited[nextIndex] = true;
    }

    return route;
}
