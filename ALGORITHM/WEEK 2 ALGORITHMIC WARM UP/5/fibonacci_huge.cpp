#include <iostream>

// if n and m given 

/*
1) get the pisano period of numbers
2) modulo (n % pisano period)
3) 

*/


long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

// property (repeatation of fibonacci numbers)

// m possess a period p 
// f(i) & f(i+p) % m (it will give same reminder)

// how to get the pisano period ?
// if m is a number f(0)%m = 0 and f(1)%m = 1 then
// loop 0 -> m*m where again a f(i)%m = 0 and f(i+1)%m == 1
// i will give the pisano period


long long pisano_period(long long m)
{
	long long previous = 0;
	long long current = 1;
	long long temp_previous;
	int i=0;
	for(i=0;i<m*m;i++)
	{
		temp_previous = (long long)(previous + current)%m;
		previous = current;
		current = temp_previous;
		if(previous == 0 && current == 1)
		{
			return i+1;
		}
	}
}

// apply n%pp (it will give the first repeatation number that give all unique %)
// apply loop for k and get the nth fibonacci number and finally return modulo m

// note : apply modulo m in loop (it will prevent integer overflow)

long long get_fibonacci_huge_fast(long long n, long long m) 
{
	long long pp = (long long)pisano_period(m);
//	std::cout << pp << std::endl;
	long long k = (long long) n%pp ;
	
//  if (k == 0)
//        return 0;
//	else if(k == 1)
//		return 1;

    long long previous = 0;
    long long current  = 1;
	long long temp_previous = k;
    for (int i = 1; i < k; i++) {
        temp_previous = (long long) (previous + current)%m;
        previous = current;
        current = temp_previous;
    }

    return (long long) temp_previous % m;
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
	std::cout << get_fibonacci_huge_fast(n, m) << '\n';
	return 0;
}
