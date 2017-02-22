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
	int n;
	cin >> n;

	vpii f(3 * n + 100, mp(-1, n+10));
	f[1] = mp(-1, 0);
	int idx = 1;

	for (int i = 1; i <= n; i++)
	{
		if (idx > n)
		{
			idx++;
			continue;
		}
		if (f[idx + 1].second > f[idx].second + 1)
		{
			f[idx + 1].second = f[idx].second + 1;
			f[idx + 1].first = idx;
		}
		if (f[idx * 2].second > f[idx].second + 1)
		{
			f[idx * 2].second = f[idx].second + 1;
			f[idx * 2].first = idx;
		}
		if (f[idx * 3].second > f[idx].second + 1)
		{
			f[idx * 3].second = f[idx].second + 1;
			f[idx * 3].first = idx;
		}
		idx++;
	}

	cout << f[n].second << endl;
	vi answer;
	idx = n;
	while (f[idx].first != -1)
	{
		answer.push_back(idx);
		idx = f[idx].first;
	}
	answer.push_back(idx);
	reverse(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";

		/*for (int i = 0; i < 3 * n + 100; i++)
			cout << i << " : " << f[i].first << " " << f[i].second << endl;*/
	return 0;
}