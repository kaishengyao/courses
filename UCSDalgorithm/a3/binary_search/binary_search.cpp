#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
using namespace std;

int binary_search(const vector<int> &a, int left, int right, int x) {
  if (left > right) return -1;
  int middle = right - left; 
  middle /= 2; 
  middle += left;
//  cout << "l " << left << " m " << middle <<  " r " << right << endl;
  if (a[middle] == x) return middle; /// found
  if (a.size() == 1) return -1; /// not found
  if (a[middle] < x) return binary_search(a, middle + 1, right, x);
  return binary_search(a, left, middle - 1, x);
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
//      std::cout << linear_search(a, b[i]) << ' ';
      std::cout << binary_search(a, 0, (int)a.size(), b[i]) << ' ';
  }
}
