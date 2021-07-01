#include <iostream>
#include <vector>
#include<limits>
#include<bits/stdc++.h>


using std::vector;

int negative_cycle(vector<vector<int> > &adjacency_list, vector<vector<int> > &cost) {
  //write your code here
  int n = adjacency_list.size();
  vector<long> distance(n, INT_MAX);
  distance[0] = 0;
  
  for(int i=0;i<n;i++) 
  {
    for(int u=0;u<n;u++)
	{
	  for(int k=0;k<adjacency_list[u].size();k++) 
	  {
	    int v = adjacency_list[u][k];
	    if(distance[v] > distance[u] + cost[u][k]) 
		{
		    distance[v] = distance[u] + cost[u][k];
		    
			if(i == n-1)
			{
				return 1;
			}	
			 
		}
	  }
	}
  }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
