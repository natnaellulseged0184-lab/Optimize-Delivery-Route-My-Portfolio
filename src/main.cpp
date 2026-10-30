#include <iostream>
#include <vector>

#include "brute_force.h"
#include "distance.h"
#include "divide_conquer.h"
#include "greedy.h"
#include "location.h"

int main() {
    std::vector<Location> deliveries = {
        {"A", 0.0, 0.0},
        {"B", 2.0, 3.0},
        {"C", 5.0, 1.0},
        {"D", 4.0, 6.0}
    };

    std::cout << "========================================\n";
    std::cout << "   DELIVERY ROUTE OPTIMIZATION SYSTEM\n";
    std::cout << "========================================\n\n";

    const Location start("A", 0.0, 0.0);
    const Location end("D", 4.0, 6.0);
    std::cout << "Distance from A to D: " << euclideanDistance(start, end) << "\n\n";

    std::cout << "Brute Force route:\n";
    const auto bruteRoute = bruteForceTSP(deliveries);
    for (const auto& loc : bruteRoute) {
        std::cout << loc.name << " -> ";
    }
    std::cout << "(start)\n\n";

    std::cout << "Nearest Neighbor route:\n";
    const auto greedyRoute = nearestNeighborRoute(deliveries);
    for (const auto& loc : greedyRoute) {
        std::cout << loc.name << " -> ";
    }
    std::cout << "(start)\n\n";

    std::cout << "Closest pair using divide and conquer:\n";
    const auto closestPair = closestPairDivideAndConquer(deliveries);
    std::cout << closestPair.first.name << " and " << closestPair.second.name << "\n";

    return 0;
}
