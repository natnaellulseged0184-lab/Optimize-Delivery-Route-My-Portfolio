#include "divide_conquer.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <utility>
#include <vector>

std::pair<Location, Location> closestPairDivideAndConquer(const std::vector<Location>& locations) {
    if (locations.size() < 2) {
        return {Location(), Location()};
    }

    if (locations.size() == 2) {
        return {locations[0], locations[1]};
    }

    std::vector<Location> sorted = locations;
    std::sort(sorted.begin(), sorted.end(), [](const Location& a, const Location& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    double minDistance = std::numeric_limits<double>::infinity();
    std::pair<Location, Location> bestPair = {sorted[0], sorted[1]};

    for (size_t i = 0; i < sorted.size(); ++i) {
        for (size_t j = i + 1; j < sorted.size(); ++j) {
            const double dx = sorted[i].x - sorted[j].x;
            const double dy = sorted[i].y - sorted[j].y;
            const double distance = std::sqrt(dx * dx + dy * dy);

            if (distance < minDistance) {
                minDistance = distance;
                bestPair = {sorted[i], sorted[j]};
            }
        }
    }

    return bestPair;
}
