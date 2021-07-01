#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;

struct suff
{
    int ind;
    int r[2];

};

int cmp(suff p, suff q) 
{
    return (p.r[0] == q.r[0]) ? (p.r[1] < q.r[1]) : (p.r[0] < q.r[0]);
}

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
vector<int> BuildSuffixArray(const string& text) {
  vector<int> result;
  // Implement this function yourself

   
    suff s[text.length()];
	int i,k;
	
    for(i=0;i<text.length();i++) 
	{
        s[i].ind = i;
        
		s[i].r[0] = text[i] - 'a';
        
        if(i + 1 < text.length())
    	    s[i].r[1] =  text[i + 1] - 'a' ;
        else
	        s[i].r[1] = -1;
    }

    std::sort(s, s + text.length(), cmp);

    int ind[text.length()];

    for (k = 4; k < 2 * text.length(); k *= 2) 
	{
        int r = 0;
        int prev_rank = s[0].r[0];
        
		s[0].r[0] = r;
        ind[s[0].ind] = 0;

        for(i=1;i<text.length();i++) 
		{
            if(s[i].r[0] == prev_rank && s[i].r[1] == s[i - 1].r[1]) 
			{
                prev_rank = s[i].r[0];
                s[i].r[0] = r;
            } 
		
			else 
			{
                prev_rank = s[i].r[0];
                s[i].r[0] = ++r;
            }
        
		    ind[s[i].ind] = i;
        }

        for (i=0;i<text.length();i++) 
		{
            int next_ind = s[i].ind + k / 2;
         
		    if(next_ind < text.length())
	            s[i].r[1] = s[ind[next_ind]].r[0] ;
            else
    	        s[i].r[1] = -1;
        }

        std::sort(s, s + text.length(), cmp);
    }

    for(i=0;i<text.length();i++) 
		result.push_back(s[i].ind);
    
	  
  return result;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
