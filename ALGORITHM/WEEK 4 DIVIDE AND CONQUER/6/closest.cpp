#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cfloat>

struct point  
{  
    int x;
	int y;  
};  

using std::vector;
using std::string;
using std::pair;
using std::min;

void heap_x(point a[],int n,int i)
{int temp_x,temp_y;
 int largest = i;
 int left = 2*i + 1;
 int right = 2*i + 2;
 if(left < n && a[left].x > a[largest].x)
 largest = left;
 if(right < n && a[right].x > a[largest].x)
 largest = right;
 if(largest != i)
 {
  temp_x = a[largest].x;
  a[largest].x = a[i].x;
  a[i].x = temp_x;

  temp_y = a[largest].y;
  a[largest].y = a[i].y;
  a[i].y = temp_y;


  heap_x(a,n,largest);
 }
}


void heapsort_x(point a[],int n)
{int i;
 int temp_x,temp_y;
 for(i=(n/2)-1;i>=0;i-- )
 heap_x(a,n,i);
 for(i=n-1;i>=0;i--)
 {
  temp_x = a[i].x;
  a[i].x = a[0].x;
  a[0].x = temp_x;
  
  temp_y = a[i].y;
  a[i].y = a[0].y;
  a[0].y = temp_y;
  
  
  heap_x(a,i,0);
 }
}

void heap_y(point a[],int n,int i)
{int temp_x,temp_y;
 int largest = i;
 int left = 2*i + 1;
 int right = 2*i + 2;
 if(left < n && a[left].y > a[largest].y)
 largest = left;
 if(right < n && a[right].y > a[largest].y)
 largest = right;
 if(largest != i)
 {
  temp_x = a[largest].x;
  a[largest].x = a[i].x;
  a[i].x = temp_x;

  temp_y = a[largest].y;
  a[largest].y = a[i].y;
  a[i].y = temp_y;


  heap_y(a,n,largest);
 }
}


void heapsort_y(point a[],int n)
{int i;
 int temp_x,temp_y;
 for(i=(n/2)-1;i>=0;i-- )
 heap_y(a,n,i);
 for(i=n-1;i>=0;i--)
 {
  temp_x = a[i].x;
  a[i].x = a[0].x;
  a[0].x = temp_x;
  
  temp_y = a[i].y;
  a[i].y = a[0].y;
  a[0].y = temp_y;
  
  
  heap_y(a,i,0);
 }
}

double min(double x, double y)
{
	return (x<y)? x:y ;
}


double final_strip(point strip[], int n, double distance) 
{ 
    double min = distance;   
  
    for (int i=0;i<n;i++) 
    {
	    for (int j=i+1 ; j<n && (strip[j].y-strip[i].y)<min ; j++) 
        {
		    if ((sqrt(pow((strip[i].x - strip[j].x),2) + pow((strip[i].y - strip[j].y),2))) < min) 
                min =  sqrt(pow((strip[i].x - strip[j].x),2) + pow((strip[i].y - strip[j].y),2));



  		}
	}
    return min; 
} 

double naive(point p[], int n) 
{ 
    double min = DBL_MAX; 
    for (int i = 0; i<n; i++) 
    {
	    for (int j = i+1; j<n; j++) 
        {
		    if((sqrt(pow((p[i].x - p[j].x),2) + pow((p[i].y - p[j].y),2))) < min) 
                min = sqrt(pow((p[i].x - p[j].x),2) + pow((p[i].y - p[j].y),2)); 
    	}
	}
	return min; 
} 

double closest_pair(point p_x[], point p_y[], int n) 
{ 
    double base;
	if (n <= 3) 
    {
    	base = naive(p_x, n);
    	return base;
	}     

    int mid = n/2; 
    point mid_point = p_x[mid]; 
  
  
    point p_y_left[mid];   
    point p_y_right[n-mid];   
    int li = 0, ri = 0;  
    for (int i=0; i<n; i++) 
    { 
      if (p_y[i].x <= mid_point.x && li<mid) 
         p_y_left[li++] = p_y[i]; 
      else
         p_y_right[ri++] = p_y[i]; 
    } 
  
    double d_left = closest_pair(p_x, p_y_left, mid); 
    double d_right = closest_pair(p_x + mid, p_y_right, n-mid); 
  
    double distance = min(d_left, d_right); 
  
    point strip[n]; 
    int j = 0; 
    for (int i = 0; i < n; i++) 
    {
	    if (abs(p_y[i].x - mid_point.x) < distance) 
        {
		    strip[j] = p_y[i], j++; 
		}
	}
	double strip_close;
    strip_close =  final_strip(strip, j, distance); 
	return min(strip_close,distance);
} 

double minimal_distance(vector<int> x, vector<int> y) {
  //write your code here
  size_t n = x.size();
  point p[n];
  int i;
  for(i=0;i<n;i++)
  {
  	p[i].x = x[i];
  	p[i].y = y[i];
  }
  point p_x[n];
  point p_y[n];
  for(i=0;i<n;i++)
  {
  	p_x[i] = p[i];
  	p_y[i] = p[i];
  }
  
  heapsort_x(p_x, n);
  heapsort_y(p_y, n);

//  for(i=0;i<n;i++)
//  {
//	std::cout << p_x[i].x << " " << p_x[i].y << std::endl; 
//  }
//  for(i=0;i<n;i++)
//  {
//	std::cout << p_y[i].x << " " << p_y[i].y << std::endl; 
//  }

  double answer;
  answer = closest_pair(p_x,p_y,n); 	
  return answer;
}

int main() {

	while(1)
	{

		  size_t n;
		  n = rand()%7 + 2;
		  std::cout << n << std::endl;
		  vector<int> x(n);
		  vector<int> y(n);
		  for (size_t i = 0; i < n; i++) {
		    x[i] = rand()%10 ;
		    y[i] = rand()%10 ;
		  }

		  for (size_t i = 0; i < n; i++) {
		    std::cout << x[i] << " " << y[i] << std::endl; 
		  }


		  point p[x.size()];
		  int i;
		  for(i=0;i<x.size();i++)
		  {
		  	p[i].x = x[i];
		  	p[i].y = y[i];
		  }

		double res1 = naive(p,x.size());
		double res2 = minimal_distance(x, y);
		if(res1 != res2)
		{
			std::cout << res1 << " " << res2 << std::endl;
			break;
		}
		else
		{
			std::cout << res1 << " " << res1 << std::endl;
			continue;
			
		}
	}


//  size_t n;
//  std::cin >> n;
//  vector<int> x(n);
//  vector<int> y(n);
//  for (size_t i = 0; i < n; i++) {
//    std::cin >> x[i] >> y[i];
//  }
//  std::cout << std::fixed;
//  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
