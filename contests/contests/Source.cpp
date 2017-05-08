#define _CRT_SECURE_NO_WARNINGS
#define mp(a, b) make_pair(a, b)
#define all(a) a.begin(), a.end()
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <set>


typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector< std::pair<int, int> > vpii;
typedef std::vector< std::string > vs;

using namespace std;

struct node
{
	vi chl;
	int len;
};

void upd(vector<node>& arr, int idx, int len)
{
	arr[idx].len += len;
	for (int i = 0; i < arr[idx].chl.size(); i++)
	{
		
		upd(arr, arr[idx].chl[i], len);
	}
	
}

int main(int argc, char** argv)
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int n;
	cin >> n;
	
	vector<node> arr(n + 1);
	vpii inp(n+1);
	int buf;
	
	for (int i = 0; i < n; i++)
	{
		cin >> buf;
		if (buf == -1)
			continue;
		arr[buf].chl.push_back(i);
		upd(arr, i, arr[buf].len + 1);
	
	}

	int max = -1;
	for (int i = 0; i < n; i++)
		max = std::max(max, arr[i].len);
	cout << max + 1;
	return 0;
}