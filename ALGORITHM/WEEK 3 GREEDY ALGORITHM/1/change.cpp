#include <iostream>

int get_change(int m) {
  //write your code here
  int n = 0,i;
  int a[3] = {10, 5, 1};
  for(i=0;i<3;i++)
  {
		n = n + m/a[i];
		m = m%a[i];
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
