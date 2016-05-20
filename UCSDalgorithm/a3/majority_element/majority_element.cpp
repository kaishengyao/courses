#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
    unordered_map<int, int> m_data;
    for (auto & p : a){
        if (m_data.find(p) == m_data.end())
            m_data[p] = 1;
        else
            m_data[p] = m_data[p] + 1;
    }
    
    int idx; 
    float sz = right - left;
    sz /= 2.0; 
//    cout << "sz " << sz << endl;
    for (auto &p : m_data){
  //      cout << "i " << p.first << " c " << p.second << endl;
        if (p.second > sz) return p.first;
    }
    return -1; 
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
