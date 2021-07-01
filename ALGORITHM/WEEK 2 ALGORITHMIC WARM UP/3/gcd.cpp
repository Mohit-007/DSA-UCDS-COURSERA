#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

// property gcd(a,b) = gcd(b,a') (a' = a%b)
// gcd(10,4) = 2


int gcd_fast(int a, int b) {
	
	if(b == 0)
	{
		return a;	
	}
	else
	{
		int k = a%b;
		return gcd_fast(b,k);
	}
}

// why time complexity improved ?
// a > a%b (it will improve the time complexity)

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  //std::cout << gcd_naive(a, b) << std::endl;

  return 0;
}
