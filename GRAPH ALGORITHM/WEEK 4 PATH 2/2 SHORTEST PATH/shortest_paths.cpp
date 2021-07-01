#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void shortest_paths(vector<vector<int> > &adjacency_list, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  reachable[s] = 1;
  distance[s] = 0;
  queue<int> q;
  int n = adjacency_list.size();
  int i;
  for(i=0;i<n;i++) 
  {
    for(int u=0;u<n;u++)
	{
      for(int k=0;k<adjacency_list[u].size();k++) 
	  {
        int v = adjacency_list[u][k];
        if(distance[u]!= LLONG_MAX && distance[v] > distance[u] + cost[u][k]) 
		{
          distance[v] = distance[u] + cost[u][k];
          reachable[v] = 1;
          if (i == n-1) 
		  	q.push(v);
        }
      }
    }
  }
  
  vector<int> visited(n);
  while(!q.empty())
  {
    int u = q.front();
	q.pop();
	visited[u] = 1;
	shortest[u] = 0;
	for(int i=0;i<adjacency_list[u].size();i++) 
	{
	  int v = adjacency_list[u][i];
      if (!visited[v]) 
	  {
        q.push(v);
        visited[v] = 1;
        shortest[v] = 0;
	  }
	}
  }
  distance[s] = 0;  
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
