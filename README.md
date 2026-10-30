# Optimize Delivery Route

This project is a C++ application for route optimization using several algorithmic strategies.

## Project structure

- `src/` contains the main application and algorithm implementations.
- `include/` contains the public headers for all modules.
- `tests/` contains validation checks for core logic.
- `results/` stores computed outputs and summaries.

## Modules

- `distance` - calculates Euclidean distances between locations.
- `brute_force` - finds the best route by exhaustive search.
- `greedy` - builds a route using the nearest-neighbor heuristic.
- `divide_conquer` - identifies the closest pair in a set of points.

## Build

```bash
g++ src/main.cpp src/distance.cpp src/brute_force.cpp src/greedy.cpp src/divide_conquer.cpp -Iinclude -o delivery_route
./delivery_route
```

## Notes

This repository is structured to support incremental algorithm development and testing.
