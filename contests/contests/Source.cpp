
#define _CRT_SECURE_NO_WARNINGS
#define mp(a, b) make_pair(a, b)

#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::vector< std::pair<int, int> > vpii;

using namespace std;


ll ext_gcd(ll a, ll b, ll& x, ll& y)
{
	if (a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}
	else
	{
		ll x1, y1;
		ll gcd = ext_gcd(b%a, a, x1, y1);
		x = y1 - (b / a) * x1;
		y = x1;
		return gcd;
	}
}


int inv(int a, int m)
{
	ll x, y;
	ll gcd = ext_gcd(a, m, x, y);
	if (gcd != 1)
		return -1;
	else
	{
		x = (x % m + m) % m;
		return x;
	}
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int m;
	cin >> m;
	vector<int> obr(m+10);
	int x = -1, y = -1, diff = -1;
	for (int i = 1; i < m; i++)
		obr[i] = inv(i, m);
	for (int i = 1; i < m; i++)
	{

		//cout << obr[obr[i]] << " " << obr[i] << endl;
		if (obr[obr[i]] == i)
		{
			if (diff < abs(obr[obr[i]] - obr[i]))
			{
				diff = abs(obr[obr[i]] - obr[i]);
				x = obr[obr[i]];
				y = obr[i];
			}
		}
	}
	cout << x << " " << y;
	return 0;
}