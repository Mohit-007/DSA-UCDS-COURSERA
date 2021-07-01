#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next [Letters];

	Node ()
	{
		fill (next, next + Letters, NA);
	}

	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}
};

typedef vector<Node> trie;
int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

void build(const vector <string>& patterns, vector<Node> &tree)
{	
	int i,j;
	int n = patterns.size();
	for(i=0;i<n;i++)
	{
		int z = 0;
		for(j=0;j<patterns[i].size();j++)
		{
			int ind = letterToIndex(patterns[i][j]);
			if (z >= tree.size())
				tree.resize(z + 1);
			
			if(tree[z].next[ind] != -1)
				z = tree[z].next[ind];
			else
			{
				tree[z].next[ind] = tree.size();
				z = tree[z].next[ind];
				tree.resize(z + 1);
			}
		}
	}

}

vector <int> solve (const string& text, int n, const vector <string>& patterns)
{
	vector <int> result;

	// write your code here

	vector<Node> tree;
	build(patterns, tree);
	int i,j;
	
	for(i=0;i<text.size();i++)
	{
		int ind = letterToIndex(text[i]);
		int z = 0;
		if(tree[z].next[ind] != -1)
		{
			int flag = 1;
			for(j = i;!tree[z].isLeaf();j++)
			{
				if(j >= text.size())
				{
					flag = 0;
					break;
				}
				ind = letterToIndex(text[j]);
				if(tree[z].next[ind] != -1)
					z = tree[z].next[ind];
				else
				{
					flag = 0;
					break;
				}
			}
			if(flag)
			{
				result.push_back(i);
			}
		}
	}


	return result;
}

int main (void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
