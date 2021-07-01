#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
	int num_refills = 0;
	int current_refills = 0;
	int last_refill = 0;
	stops.push_back(dist);	
	vector<int> stop(stops.size() + 1);	

	stop[0] = 0;
	for (int i=0; i < stops.size(); ++i) 
	{
		stop[i+1] = stops[i];
   	}

//	for (int i=0; i < stops.size()+1; ++i) 
//	{
//		std::cout << stop[i] << std::endl;
//   	}
	
	while(current_refills < stop.size()-1)
	{
		last_refill = current_refills;
		while((current_refills < stop.size()-1) && (stop[current_refills+1] - stop[last_refill] <= tank))
		{
			current_refills = current_refills + 1;
	//		std::cout << current_refills << "\t";
		}
	//	std::cout << std::endl;
		
		if(current_refills == last_refill)
		{
			return -1;
		}
		else if(current_refills < stop.size()-1)
		{
			num_refills = num_refills + 1;
	//		std::cout << num_refills << std::endl;
		}
	}
	return num_refills;	
}


int main() 
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
