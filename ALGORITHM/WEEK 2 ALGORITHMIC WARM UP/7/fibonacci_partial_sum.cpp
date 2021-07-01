#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) 
{
    long long sum = 0;
    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) 
	{
        if (i >= from) 
		{
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

// get pisano period  

long long pisano_period(long long m)
{
	long long previous = 0;
	long long current = 1;
	long long temp;
	long long i=0;
	for(i=0;i<m*m;i++)
	{
		temp = (long long)(previous + current)%m;
		previous = current;
		current = temp;
		if(previous == 0 && current == 1)
		{
			return i+1;
		}
	}
}

// get the nth fibonacci numbers

long long fibonacci_fast(long long n) 
{
    // write your code here
	if(n<=1)
		return n;

	long long f[n+1];
	f[0] = 0;
	f[1] = 1;
	long long i = 0;
	for(i=2;i<=n;i++)
	{
		f[i] = (long long) f[i-1] + f[i-2];
	}
    return f[n];
}

// it return the f(n)%m value 

long long get_fibonacci_huge_fast(long long n,long long m)
{
	long long remainder = (long long) n%pisano_period(m);
	return (long long)fibonacci_fast(remainder)%m;
}

// k = n%pp(10) (it will compute the unit digit of nth fibonacci numbers)
// pp(10) = 60

long long get_fibonacci_last_digit_fast(long long k)
{
	if(k<=1)
		return k;
	int previous = 0;
	int current = 1;
	
	for(int i=0;i<k-1;i++)
	{
		int temp_previous = previous%10;
		previous = current%10;
		current = temp_previous + current%10;	
	}	
	return current%10;
}

// it take the f(m) and f(n) 
// if f(m) and f(n) !equal then 
// get unit digit of f(m+1) - f(n+1) =>  ... + f(n) - ... + f(m) = f(m) + ... + f(n) 
// if equal ... f(m) = ... f(n) 

long long get_fibonacci_partial_sum_fast(long long from, long long to) 
{
	long long n,m;
	if(from == to)
		return get_fibonacci_last_digit_fast((long long) from % 60);
	else
	{
		//from = (long long) from % 60;
		//to = (long long) to % 60;
		n = (long long) get_fibonacci_huge_fast(from + 2,10) - 1;
		m = (long long) get_fibonacci_huge_fast(to + 2,10) - 1;
		std::cout << m << " " << n << std::endl;
	}
	int q = (long long) (m-n);
	if((long long)q < 0)
		return (10 - q)%10;
	else
		return q%10;	
}


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
