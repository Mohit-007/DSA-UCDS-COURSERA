#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <cstdlib>


using std::vector;
using std::string;
using std::max;
using std::min;

using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) 
{
  //write your code here
  int n = exp.size();
  int operands = (n + 1) / 2;

  long long mini[operands][operands];
  long long maxi[operands][operands];

//  memset(min, 0, sizeof(min)); // initialize to 0
//  memset(max, 0, sizeof(max)); // initialize to 0
  for(int i=0;i<operands;i++)
  {
  	for(int j=0;j<operands;j++)
	{
		mini[i][j] = 0;
		maxi[i][j] = 0;
	}	
  }	
  for(int i=0;i<operands;i++) 
  {
		mini[i][i] = strtoull(exp.substr(2 * i, 1));
		maxi[i][i] = stol(exp.substr(2 * i, 1));
  }

  for(int s=0; s<operands-1;s++) 
  {
	for(int i=0;i<operands-s-1;i++) 
	{
		int j = i + s + 1;
		long long min_value = LLONG_MAX;
		long long max_value = LLONG_MIN;

		for(int k=i;k<j;k++) 
		{
			long long a = eval(mini[i][k], mini[k + 1][j], exp[2 * k + 1]);
			long long b = eval(mini[i][k], maxi[k + 1][j], exp[2 * k + 1]);
			long long c = eval(maxi[i][k], mini[k + 1][j], exp[2 * k + 1]);
			long long d = eval(maxi[i][k], maxi[k + 1][j], exp[2 * k + 1]);

			min_value = min(min_value, min(a, min(b, min(c, d))));
			max_value = max(max_value, max(a, max(b, max(c, d))));

		}
		mini[i][j] = min_value;
		maxi[i][j] = max_value;
	}
  }
  
  return 0;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
