#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::priority_queue;

class thread 
{
	public:
		int identity;
        long long new_free_time;
	    thread(int identity) 
		{
            this->identity = identity;
            new_free_time = 0;
        }
};

struct thread_compare {
	bool operator()(const thread &t1, const thread &t2) const 
	{
		if(t1.new_free_time == t2.new_free_time)
			return t1.identity > t2.identity;
		else
            return t1.new_free_time > t2.new_free_time;
	}
};

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;
//  vector<thread> thread;
//  vector<thread> temp;
  

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
/*    
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }
*/		
	assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
	priority_queue<thread, vector<thread>, thread_compare> xy;
	for(int i = 0; i < num_workers_; i++) 
	{
		xy.push(thread(i));
	}
	for (int i = 0; i < jobs_.size(); i++) 
	{
		thread free_thread = xy.top();
		xy.pop();
		assigned_workers_[i] = free_thread.identity;
		start_times_[i] = free_thread.new_free_time;
		free_thread.new_free_time += jobs_[i];
		xy.push(free_thread);
	}
  }
  


//	void heap(int i)
//	{
//		
//		 int min = i;
//		 int left = 2*i + 1;
//		 int right = 2*i + 2;
//		 int n = thread.size();
//		 if(left < n && (thread[left].finish_time < thread[min].finish_time) || (thread[left].finish_time == thread[min].finish_time && thread[left].thread_index < thread[min].thread_index))
//		 	min = left;
//		 if(right < n && (thread[right].finish_time < thread[min].finish_time) || (thread[right].finish_time == thread[min].finish_time && thread[right].thread_index < thread[min].thread_index))
//			 min = right;
//		 if(min != i)
//		 {
//		 	std::swap(thread[i] ,thread[min]);
//		 	heap(min);
//		 }
//	}


 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
