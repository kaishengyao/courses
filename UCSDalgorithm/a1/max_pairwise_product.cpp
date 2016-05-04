#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using namespace std;

/// n^2 operation
int oldMaxPairwiseProduct(const vector<int>& numbers) {
  int result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

/// 2n pass of the data
long long MaxPairwiseProduct(const vector<int>& numbers) {
    long max1 = 0, max2 = 0;
    long imax1 = 0, imax2 = 0;
    long n = numbers.size();
    for (long i = 0; i < n; ++i) {
        if (numbers[i] > max1){
            max1 = numbers[i];
            imax1 = i;
        }
    }

    for (long i = 0; i < n; ++i) {
        if (i != imax1 && numbers[i] > max2)
        {
            imax2 = i;
            max2 = numbers[i];
        }
    }
//    cout << max2 << " " << imax2 << " " << max1 << " " << imax1 << endl;
    return max2 * max1;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
