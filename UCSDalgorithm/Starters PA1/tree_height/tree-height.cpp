#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class TreeHeight {
  int n;             
  std::vector<int> parent;

public:
  void read() {
    std::cin >> n;
    parent.resize(n);
    for (int i = 0; i < n; i++)
      std::cin >> parent[i];
  }

  /**
  suppose node[k] is not yet accessed, then its height is determined by the first
  child who visits his parent first, telling him how many children paths have been passed
  i.e., the parent's depth is determined by the max{depth[k], depth[child[k]]+1}
    if depth[k] = -1, that means this parent hasn't go up to visit his parent, 
    then this upward propagation needs to up again
  */
  int compute_height() {
    // Replace this code with a faster implementation
    int maxHeight = 0;
    std::vector<int> depth(n, -1);

    for (int vertex = 0; vertex < n; vertex++) {
      int height = 0;
      for (int i = vertex; i != -1; i = parent[i])
      {
          height++;
//          cout << "h[" << i << "] " << height << endl;
          int this_height = std::max<int>(depth[i], height);
          if (depth[i] < height)
          {
              depth[i] = height;
//              cout << "d+[" << i << "] " << depth[i] << endl;
          }
          else{
              break;
          }
      }
    }
    maxHeight = *std::max_element(depth.begin(), depth.end());
    return maxHeight;
  }

  /* old code
  int compute_height() {
      // Replace this code with a faster implementation
      int maxHeight = 0;
      for (int vertex = 0; vertex < n; vertex++) {
          int height = 0;
          for (int i = vertex; i != -1; i = parent[i])
              height++;
          maxHeight = std::max(maxHeight, height);
      }
      return maxHeight;
  }
  */
};

int main() {
  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read();
  std::cout << tree.compute_height() << std::endl;
}
