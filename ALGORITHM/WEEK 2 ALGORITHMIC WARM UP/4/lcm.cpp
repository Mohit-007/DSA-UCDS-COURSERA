#include <iostream>

// l <= a*b (least)

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

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


// property of lcm = a*b/gcd(a,b)

long long lcm_fast(int a, int b) {
	int gcd = gcd_fast(a,b);
	long long lcm = (long long) a*b/gcd;
	return (long long) lcm;	
}



int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  	std::cout << lcm_fast(a,b) << std::endl;
  return 0;
}
