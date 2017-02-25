#define _CRT_SECURE_NO_WARNINGS
#define mp(a, b) make_pair(a, b)

#include <iostream>
#include <algorithm>
#include <vector>

typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::vector< std::pair<int, int> > vpii;

using namespace std;


int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	long long a;
	cin >> a;
	if (abs(a) < 1e9)
		cout << "0 " << a;
	else
	{

	}
	return 0;
}