#include <iostream>

int main(){
  int a = 0;
  int b = 0;
  int sum = 0;
  std::cin >> a;
  std::cin >> b;
  if (a>=0 && a <=9 && b >= 0 && b <= 9)
  {
    sum = a + b;
    std::cout << sum;
    return 0;
  }else
    return -1;
}

