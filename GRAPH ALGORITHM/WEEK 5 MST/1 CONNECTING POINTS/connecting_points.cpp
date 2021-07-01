#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;


struct edges 
{
  int u;
  int v;
  double w;
  
  edges(int p, int q, double r) 
  {
    u = p;
    v = q;
    w = r;
  }
};

struct graph
{
  int x;
  int y;

  int p;
  int r;
 	
  graph(int a, int b, int c = -1, int d = 0) 
  {
    x = a;
    y = b;
    p = c;
    r = d;
  }
};


void make_sets(int i, vector<graph> &node, vector<int> &a, vector<int> &b) 
{
  node.push_back(graph(a[i], b[i], i));
}

bool cmp(edges p, edges q) 
{
  return p.w < q.w;
}


double weights(int p1, int q1, int p2, int q2) 
{
  return sqrt((p1 - p2) * (p1 - p2) + (q1 - q2) * (q1 - q2));
}

int find(int i, vector<graph> &node) 
{
  if(i != node[i].p) 
  	node[i].p = find(node[i].p, node);
  
  return node[i].p;
}

void unions(int u, int v, vector<graph> &node) 
{
  int p = find(u, node);
  int q = find(v, node);
  
  if(p != q) 
  {
    if(node[p].r > node[q].r) 
		node[q].p = p;
    
	else 
	{
      node[p].p = q;
      
      if(node[p].r == node[q].r) 
	  	node[q].r = node[q].r + 1;
      
    }
  }
}


double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
  
  vector<graph> node;
  int i = 0,j = 0;
  for(i=0;i<x.size();i++) 
  {
	make_sets(i, node, x, y);
  }
  vector<edges> edge;
  for(i=0;i<x.size();i++) 
  {
    for(j=i+1;j<x.size();j++) 
	{
	  double w = weights(x[i], y[i], x[j], y[j]); 	
      edge.push_back(edges(i, j, w));
    }
  }
  int u,v;
  std::sort(edge.begin(), edge.end(), cmp);
  for(i=0;i<edge.size();i++) 
  {
    edges current_edge = edge[i];
    u = current_edge.u;
    v = current_edge.v;
    if(find(v, node) != find(u, node)) 
	{
      result = result + current_edge.w;
      unions(u, v, node);
    }
  }  
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
