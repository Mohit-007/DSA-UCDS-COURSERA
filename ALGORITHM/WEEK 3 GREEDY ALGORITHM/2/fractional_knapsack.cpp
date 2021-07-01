#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

using std::vector;





double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  // write your code here
  int n = values.size();

  double a[n];
  int i;  
  for(i=0;i<n;i++)
  {
  	 a[i] = (double) values[i]/weights[i];
  }
  int j = 0;	
  for(j=0;j<n;j++)
  {
  	double max = 0;
  	int max_index = 0;

	for(i=0;i<n;i++)
  	{
		if(weights[i] != 0)
	  	{
		  	if(max < (double) a[i])
			{
				max = (double) a[i];
				max_index = i;
			}	
		}
	}
//  	std::cout << max_index << std::endl;
	
	if(capacity > weights[max_index])
  	{
  		capacity = capacity - weights[max_index];
		value = (double) value + values[max_index];
		values[max_index] = 0; 	
		weights[max_index] = 0;
		a[max_index] = 0;
		
	}
	else
	{
		value = (double) value + (double) capacity*a[max_index];
		capacity = 0;
		break;
	}
  }

  return value;


}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
