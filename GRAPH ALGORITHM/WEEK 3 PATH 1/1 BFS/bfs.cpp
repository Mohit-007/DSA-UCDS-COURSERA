#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <limits>

using std::vector;
using std::numeric_limits;
using std::queue;

int distance(vector<vector<int> > &adjacency_list, int s, int t) {
  //write your code here
  if (s == t) 
  {
	return 0;
  }
  int n = adjacency_list.size();
  vector<int> distance(n);
  int i;
  for(i=0;i<distance.size();i++)
  {
    distance[i] = INT8_MAX;
  }
  
  distance[s] = 0;
  
  queue<int> queue;
  
  queue.push(s);
  
  while(!queue.empty()) 
  {
    int u = queue.front();
	queue.pop();
	for(int i=0;i<adjacency_list[u].size();i++) 
	{
      int vertex = adjacency_list[u][i];
	  if(distance[vertex] == INT8_MAX) 
	  {
		queue.push(vertex);
		distance[vertex] = distance[u] + 1;
	  }
	}
  }
  
  if(distance[t] != INT8_MAX) 
  	return distance[t];
  
  
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
