#include <iostream>
#include <vector>

struct segment
{
	int x;
	int y;
};

using std::vector;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) 
{
  vector<int> cnt(points.size());
  //write your code here

  int n = starts.size();
  segment line[n];
  int i;
  int j;
  int a;

  for(i=0;i<n;i++)
  {
  	line[i].x = starts[i];
  	line[i].y = ends[i];
  }
  int z = points.size();
  
  for(i=0;i<z;i++)
  {
  	a=0;
  	
	for(j=0;j<n;j++)
  	{

  		if(points[i] >= line[j].x && points[i] <= line[j].y)
		{
			a = a+1;  	
		}

		else if(points[i] <= line[j].x)
		{
			j = n;	
		}	

		
	}
		cnt[i] = a;

  }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  //vector<int> cnt = naive_count_segments(starts, ends, points);
	vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
