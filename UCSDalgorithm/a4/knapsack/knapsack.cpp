#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using std::vector;
using std::cout;
using std::endl;

int optimal_weight(int W, const vector<int> &w) {
    int current_weight = 0;
    int * value = new int[w.size() * (W+1)];
    memset(value, 0, w.size() * (W + 1)* sizeof(int));

    for (size_t i = 0; i < w.size(); ++i) {
        for (int wgt = 0; wgt <= W; wgt++)
        {
            if (i >= 1)
                value[wgt * w.size() + i] = value[wgt * w.size() + i - 1];
            if (wgt >= w[i]){
                int vv = value[(wgt - w[i]) * w.size() + i - 1] + w[i];

                if (value[wgt * w.size() + i] < vv)
                    value[wgt*w.size() + i] = vv;
            }
//            cout << i << " " << wgt << " " << value[wgt*w.size() + i] << " " << endl;
        }
    }

    int owgt = value[(W+1)*w.size() - 1];
    delete value;

    return owgt;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
