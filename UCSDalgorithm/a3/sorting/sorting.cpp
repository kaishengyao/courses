#include <iostream>
#include <vector>
#include <map>
#include <utility>

using std::vector;
using std::swap;
using std::pair;
using namespace std;

int partition2(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

void display_vector(const vector<int>& a, string str)
{
    cout << endl;
    cout << str << " ";
    for (auto p : a)
        cout << p << " ";
    cout << endl;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

pair<int, int> partition3(vector<int> &a, int l, int r) {
    vector<int> left, right, middle;
//    cout << "l " << l << " r " << r << endl;
    int x = a[l];
    //  cout << "pivot " << x << endl;
    for (int i = l; i <= r; i++) {
        if (a[i] < x)
        {
            left.push_back(a[i]);
        }
        else if (a[i] == x)
        {
            middle.push_back(a[i]);
        }
        else if (a[i] > x)
        {
            right.push_back(a[i]);
        }
    }
  //  display_vector(left, "left");
  //  display_vector(middle, "middle");
  //  display_vector(right, "right");
    copy(left.begin(), left.end(), a.begin() + l);
    copy(middle.begin(), middle.end(), a.begin() + l + left.size());
    copy(right.begin(), right.end(), a.begin() + l + left.size() + middle.size());
    return std::make_pair<int, int>(l + left.size(), l + left.size() + middle.size());
}

void randomized_quick_sort3(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    pair<int, int> m = partition3(a, l, r);
//    cout << m.first << " " << m.second << endl;
//    for (auto p : a)
//        cout << p << " ";
//    cout << endl;
    randomized_quick_sort3(a, l, m.first - 1);
    randomized_quick_sort3(a, m.second, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort3(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
