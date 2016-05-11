#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

std::vector<int> currency(3,0);

int get_change(int n) {

    currency[0] = 10; currency[1] = 5; currency[2] = 1;

    int step = 0; 
    int total_coins = 0;
    vector<int> assign;
    /// safe move
    while (n > 0)
    {
        int k = n / currency[step]; 
        n %= currency[step]; 
        
        assign.push_back(k);
        //cout << k << endl;
        total_coins += k;
        step++;
    }
    
    return total_coins;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
