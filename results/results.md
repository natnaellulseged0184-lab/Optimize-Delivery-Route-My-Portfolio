# Member 6: Testing and Evaluation

## Test coverage

`tests/tests.cpp` verifies Euclidean distance, valid routes from both route algorithms, empty-input handling, closest-pair correctness, and average execution time for all algorithms.

## Run the tests

Build from the repository root with a C++17 compiler:

```bash
g++ -std=c++17 -Iinclude tests/tests.cpp src/distance.cpp src/greedy.cpp src/brute_force.cpp src/divide_conquer.cpp -o tests/run_tests
./tests/run_tests
```

The program prints a failed requirement and exits with a non-zero code when a test fails. A successful run prints timing measurements followed by `All Member 6 tests passed.`

## Evaluation

| Algorithm | Validation | Expected growth | Trade-off |
| --- | --- | --- | --- |
| Nearest Neighbor | Visits every location once | O(n^2) | Fast heuristic; result may not be optimal. |
| Brute Force TSP | Visits every location once; route is no longer than greedy | O(n!) | Exact result for the checked routes, but impractical for many deliveries. |
| Closest Pair | Returns the pair with the minimum Euclidean distance | Current implementation: O(n^2) | Correct for small inputs. |

The benchmark uses six locations so brute force remains practical. Timings vary by compiler and computer, so they are printed during the test run rather than hard-coded in this report.
