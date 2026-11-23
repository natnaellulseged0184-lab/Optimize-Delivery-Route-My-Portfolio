#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "brute_force.h"
#include "distance.h"
#include "divide_conquer.h"
#include "greedy.h"
#include "location.h"

namespace {
constexpr double kEpsilon = 1e-9;

void require(bool condition, const std::string& message) {
    if (!condition) { std::cerr << "FAILED: " << message << '\n'; std::exit(EXIT_FAILURE); }
}

bool sameLocation(const Location& a, const Location& b) {
    return a.name == b.name && std::fabs(a.x - b.x) < kEpsilon && std::fabs(a.y - b.y) < kEpsilon;
}

bool containsEveryLocationOnce(const std::vector<Location>& route, const std::vector<Location>& locations) {
    if (route.size() != locations.size()) return false;
    std::vector<bool> matched(locations.size(), false);
    for (const Location& stop : route) {
        bool found = false;
        for (std::size_t i = 0; i < locations.size(); ++i) {
            if (!matched[i] && sameLocation(stop, locations[i])) { matched[i] = true; found = true; break; }
        }
        if (!found) return false;
    }
    return true;
}

double routeLength(const std::vector<Location>& route) {
    double total = 0.0;
    for (std::size_t i = 1; i < route.size(); ++i) total += euclideanDistance(route[i - 1], route[i]);
    return total;
}

template <typename Function>
double measureMilliseconds(Function function, int repetitions = 1000) {
    const auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < repetitions; ++i) function();
    const std::chrono::duration<double, std::milli> elapsed = std::chrono::steady_clock::now() - start;
    return elapsed.count() / repetitions;
}

void testDistance() {
    require(std::fabs(euclideanDistance({"A", 0, 0}, {"B", 3, 4}) - 5.0) < kEpsilon, "3-4-5 distance should be 5.");
    require(std::fabs(euclideanDistance({"A", -1, -1}, {"B", -1, -1})) < kEpsilon, "Distance to self should be zero.");
}

void testRoutes() {
    const std::vector<Location> locations = {{"A", 0, 0}, {"B", 2, 3}, {"C", 5, 1}, {"D", 4, 6}};
    const auto greedy = nearestNeighborRoute(locations);
    require(containsEveryLocationOnce(greedy, locations), "Nearest Neighbor must visit each location exactly once.");
    require(sameLocation(greedy.front(), locations.front()), "Nearest Neighbor should start at the first location.");
    const auto bruteForce = bruteForceTSP(locations);
    require(containsEveryLocationOnce(bruteForce, locations), "Brute Force must return each location exactly once.");
    require(routeLength(bruteForce) <= routeLength(greedy) + kEpsilon, "Brute Force route must not be longer than greedy.");
    require(nearestNeighborRoute({}).empty(), "Nearest Neighbor should accept an empty input.");
    require(bruteForceTSP({}).empty(), "Brute Force should accept an empty input.");
}

void testClosestPair() {
    const std::vector<Location> locations = {{"A", 0, 0}, {"B", 2, 3}, {"C", 5, 1}, {"D", 4, 6}};
    const auto pair = closestPairDivideAndConquer(locations);
    require(std::fabs(euclideanDistance(pair.first, pair.second) - std::sqrt(13.0)) < kEpsilon, "Closest distance should be sqrt(13).");
    const auto noPair = closestPairDivideAndConquer({});
    require(noPair.first.name.empty() && noPair.second.name.empty(), "Empty input should return default locations.");
}

void benchmarkAlgorithms() {
    const std::vector<Location> locations = {{"A", 0, 0}, {"B", 2, 3}, {"C", 5, 1}, {"D", 4, 6}, {"E", 7, 4}, {"F", 8, 0}};
    std::cout << "Average execution time (milliseconds):\n";
    std::cout << "  Nearest Neighbor: " << measureMilliseconds([&] { (void)nearestNeighborRoute(locations); }) << '\n';
    std::cout << "  Brute Force: " << measureMilliseconds([&] { (void)bruteForceTSP(locations); }, 20) << '\n';
    std::cout << "  Closest Pair: " << measureMilliseconds([&] { (void)closestPairDivideAndConquer(locations); }) << '\n';
}
}  // namespace

int main() {
    testDistance();
    testRoutes();
    testClosestPair();
    benchmarkAlgorithms();
    std::cout << "All Member 6 tests passed.\n";
    return EXIT_SUCCESS;
}
