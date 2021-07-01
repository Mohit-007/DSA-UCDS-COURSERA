#include <iostream>
#include <vector>
#include <algorithm>
  
using namespace std;

int get_change(int m) {
  //write your code here
  int i,j;
  int coin[3] = {1,3,4};
  int int_max = 1000 + 1;
  vector<int> money(m+1, int_max);
  money[0] = 0;Q
  for(i=1;i<=m;i++)
  {
  		for(j=0;j<3;j++)
  		{
  			if(i >= coin[j])
  			{
  				int value = coin[j];
				if(money[i - value] != int_max)
				{
					if(money[i - value] + 1 < money[i])
					{
						money[i] = money[i - value] + 1;
					}
				}
			}
		}
  }
  
  return money[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
