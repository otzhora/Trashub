#define _CRT_SECURE_NO_WARNINGS

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

	vi f(n * 3 + 5, -1);
	int idx = 1;
	int answ_size = 0;
	if (n == 1)
		answ_size--;
	for (;;)
	{
		if (idx == n)
			break;
		if (f[idx + 1] == -1)
			f[idx + 1] = idx;
		if (idx + 1 == n)
			break;

		if (f[idx * 2] == -1)
			f[idx * 2] = idx;
		if (idx * 2 == n)
			break;

		if (f[idx * 3] == -1)
			f[idx * 3] = idx;
		if (idx * 3 == n)
			break;
		idx++;
	}
	//int j = 0;
	//int idx = 0;
	//f.push_back(make_pair(n, -1));
	//for (;;)
	//{
	//	if (f[idx].first == 1)
	//		break;
	//	if (f[idx].first < 1)
	//	{
	//		idx++;
	//		continue;
	//	}
	//	f.push_back(make_pair(f[idx].first - 1, idx));
	//	if (f[idx].first % 2 == 0)
	//	{
	//		f.push_back(make_pair(f[idx].first % 2, idx));
	//	}
	//	if (f[idx].first % 3 == 0)
	//	{
	//		f.push_back(make_pair(f[idx].first % 3, idx));
	//	}
	//	
	//	
	//	idx++;
	//}
	vi answer;
	idx = n;
	while (f[idx] != -1)
	{
		answer.push_back(idx);
		idx = f[idx];
	}
	answer.push_back(idx);
	//vector<int> answer;
	//idx = f.size() - 1;
	//while (f[idx].second != -1)
	//{
	//	answer.push_back(f[idx].first);
	//	idx = f[idx].second;
	//}
	//answer.push_back(f[idx].first);
	reverse(answer.begin(), answer.end());
	cout << answ_size + answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}