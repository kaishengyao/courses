#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
using std::vector;

/// sort with index
vector<size_t> sort_indexes(const vector<double> &v) {

    // initialize original index locations
    vector<size_t> idx(v.size());
    for (size_t i = 0; i != idx.size(); ++i) idx[i] = i;

    // sort indexes based on comparing values in v
    sort(idx.begin(), idx.end(),
        [&v](size_t i1, size_t i2) {return v[i1] > v[i2]; });

    return idx;
};


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

    /// sort the items in descreasing value per weight order
  vector<double> vpw;
  for (int k = 0; k < values.size(); k++)
  {
      double val;
      if (weights[k] == 0)
          val = 0;
      else 
          val = (double)values[k] / (double)weights[k];

      vpw.push_back(val);
  }

  vector<size_t> sorted_idx = sort_indexes(vpw);

  double weight = 0;

  int ix = 0;
  while(0 < capacity && ix < values.size()){
      int id = sorted_idx[ix];
      while (weights[id] <= 0)
      {
          id = sorted_idx[ix];
          ix++;

          if (ix >= values.size())
              return value;
      }

      double alloc = std::min<float>(weights[id], capacity);
      value += alloc * vpw[id];
      capacity -= alloc; //cout << "c = " << capacity << endl;
      weights[id] -= alloc; //cout << "v = " << value;
//      cout << "w = " << weight << endl;
      ix++;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

//  std::cout.precision(10);
  cout << std::fixed;
  cout << std::setprecision(4);
  std::cout << optimal_value << std::endl;
  return 0;
}
