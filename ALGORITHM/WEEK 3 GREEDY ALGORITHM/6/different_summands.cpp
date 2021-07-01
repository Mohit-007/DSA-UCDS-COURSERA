#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  
  vector<int> summands;
  //write your code here
  int i = 1;
  int k = 0;
  while(i<=n)
  {
  	n = n - i;
  	if(n-i <= 0)
  	{
  		summands.push_back(n+i);
  		//summands[k] = n+i;
  		
  	}
  	else if(n == 0)
  	{
  		summands.push_back(i);
  		//summands[k] = i;
  		
  		break;
  	}
  	else
  	{
  		summands.push_back(i);
  		//summands[k] = i;
  			
	}
	k++;
  	i++;
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
