#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    // distances from every city to every city
    vector<vector<int>> distance(size_t(n), vector<int>(size_t(n), 10000000));

    for (size_t i = 0; i < size_t(n); ++i) {
      distance[i][i] = 0;  // distance to itself
    }

    // fill distances with info from edges
    for (auto& edge : edges) {
      distance[size_t(edge[0])][size_t(edge[1])] = edge[2];
      distance[size_t(edge[1])][size_t(edge[0])] = edge[2];
    }

    // Floyd-Warshall algorithm for all pairs
    for (size_t k = 0; k < size_t(n); ++k) {
      for (size_t i = 0; i < size_t(n); ++i) {
        for (size_t j = 0; j < size_t(n); ++j) {
          // shortest path from i to j
          distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
        }
      }
    }

    int res = -1;           // result city with least reachable cities
    int cur_min = INT_MAX;  // current minimum of reachable cities
    for (size_t i = 0; i < size_t(n); ++i) {
      int count = 0;  // number of reachable cities within threshold
      for (size_t j = 0; j < size_t(n); ++j) {
        if (i != j && distance[i][j] <= distanceThreshold) {
          ++count;
        }
      }
      if (count <= cur_min) {  // update current minimum
        cur_min = count;
        res = int(i);
      }
    }
    return res;
  }

  void output(int n, vector<vector<int>>& edges, int distanceThreshold) {
    cout << "For " << n << " cities, distance threshold = " << distanceThreshold
         << ", edges array: {";
    for (auto edge : edges) {
      cout << "\n\t" << edge[0] << " -> " << edge[1] << " (weight " << edge[2]
           << ")";
    }
    cout << "\n}, the city with least reachable neighbors is city "
         << findTheCity(n, edges, distanceThreshold) << '\n';
  }
};

int main() {
  Solution s;
  vector<vector<int>> e1 = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
  s.output(4, e1, 4);
  vector<vector<int>> e2 = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3},
                            {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
  s.output(5, e2, 2);
  return 0;
}