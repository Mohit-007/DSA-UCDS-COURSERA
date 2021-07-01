#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n) {
  vector<int> sequence;
  vector<int> value(n+1)  ;
  int i;
  value[0] = 0;
  for(i=1;i<value.size();i++)
  {
		value[i] = value[i-1] + 1;
		if(i%2 == 0)
		{
			if(1 + value[i/2] < value[i])
			{
				value[i] = value[i/2] + 1;	
			}	
		}
		if(i%3 == 0)
		{
			if(1 + value[i/3] < value[i])
			{
				value[i] = 1 + value[i/3];
			}
		}
//		std::cout << value[i] << std::endl;
  }	 
  int k = n; 
  while(k > 1) 
  {
//  	std::cout << k << std::endl; 
    sequence.push_back(k);
    if(value[k-1] == value[k] - 1) 
	{
      k--;
    } 
	else if((value[k/2] == value[k] - 1) && k%2 == 0  ) 
	{
      k /= 2;
    } 
	else if((value[k/3] == value[k] - 1) && k%3 == 0  )
	{
      k /= 3;
    }
  }
  sequence.push_back(1);
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
