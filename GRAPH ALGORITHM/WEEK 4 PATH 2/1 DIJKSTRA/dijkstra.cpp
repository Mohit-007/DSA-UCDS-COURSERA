#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using std::numeric_limits;

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::greater;
using std::make_pair;
const int infinity = numeric_limits<int>::max();
//
//struct graph 
//{
//  int i;
//  int d;
//  
//  graph(int p = 0, int q = 0) 
//  {
//  	i = p;
//  	d = q;
//  }
//};
//
//struct cmp 
//{
//	bool operator()(graph x, graph y)
//	{
//		return x.d > y.d;
//	}
//};

//int distance(vector<vector<int> > &adjacency_list, vector<vector<int> > &cost, int s, int t) {
//  //write your code her
//  vector<int> distance(adjacency_list.size(), infinity);
//  distance[s] = 0;
//
//  int i;
//
//  priority_queue<graph, vector<graph>, cmp> queue;
//  queue.push(graph(s, distance[s]));
//  
//  while(!queue.empty()) 
//  {
//	
//	graph u = queue.top();
//	queue.pop();
//	
//	int u_index = u.i;
//    
//	for(i=0;i<adjacency_list[u_index].size();i++) 
//	{
//    	
//	  int v = adjacency_list[u_index][i];
//	  if(distance[v] > distance[u_index] + cost[u_index][i]) 
//	  {
//	    distance[v] = distance[u_index] + cost[u_index][i];
//        queue.push(graph(v, distance[v])); 
//	  }
//	}	
//  }
//  
//  if(distance[t] == infinity)
//    return -1;
//
//  return distance[t];
//}


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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
