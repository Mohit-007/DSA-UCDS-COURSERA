#include <iostream>

// get the (n+2)th fibonacci numbers -1 = sum of n fibonacci numbers

long long pisano_period(long long m)
{
	long long previous = 0;
	long long current = 1;
	long long tmp_previous;
	int i=0;
	for(i=0;i<m*m;i++)
	{
		tmp_previous = (long long)(previous + current)%m;
		previous = current;
		current = tmp_previous;
		if(previous == 0 && current == 1)
		{
			return i+1;
		}
	}
}


int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

// note : it is unit digit problem (%10) then get pisano period of 10
// get the (n+2) th fibonacci number
// type cast for long long 

int fibonacci_sum_fast(long long n) {
    // write your code here
	long long pp = (long long) pisano_period(10);
	long long k = (long long) (n+2)%pp ;
	
//  if (k == 0)
//        return 0;
//	else if(k == 1)
//		return 1;

	if(n <= 1)
		return n;
	
    long long previous = 0;
    long long current  = 1;
    long long tmp_previous;
	for (int i = 0; i < k-1; i++) 
	{
        tmp_previous = (long long) (previous)%10;
        previous = current%10;
        current = tmp_previous + current%10;
    }
	
	if(((long long) current%10) == 0)
		return 9;
	else
		return (long long) (current%10) - 1	;
}


int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n);
	std::cout << fibonacci_sum_fast(n);
}
