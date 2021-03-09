/*
	TRUST THE PROCESS....
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define md 1000000007
#define mx 1e18
#define pb push_back
#define read(n) scanf("%d",&n)
#define prll int(x) prll intf("%d",x)
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<ll int,ll int>
#define ff first
#define ss second
#define f(a,b,c) for(ll int i=b;i<=c;i++)
#define T ll int t;cin>>t;while(t--)


/*It contains a function called solve2 which will given
the number of integers from 1 to C, which is coprime
to another number N. N's prime factorization and C
will be the parameters of the function solve2.
*/


ll int solve2(ll int C , vector<ll int>&primes) {
	ll int sz = primes.size();

	map<ll int, ll int>mapping;

	for (ll int i = 1; i < (1 << sz); i++) {
		ll int CurrentPrimeProduct = 1;
		for (int j = 0; j < sz; j++) {
			if (((1 << j)&i) == (1 << j)) {
				CurrentPrimeProduct *= primes[j];
			}
		}

		// cout << CurrentPrimeProduct << endl;

		mapping[__builtin_popcount(i)] += C / CurrentPrimeProduct;
	}

	ll int sign = 1;
	ll int ans = 0;
	for (int i = 1; i <= sz; i++) {
		ans += sign * (mapping[i]);
		sign *= -1;
	}

	return C - ans;
}

int main()
{
	fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	ll int t;
	cin >> t;

	while (t--) {
		ll int a , m;
		cin >> a >> m;

		ll int g = __gcd(a , m);

		ll int M = m;

		m /= g;

		vector<ll int>tmp;
		//now i want all the prime divisors of m inside the vector tmp

		bool h = false;
		ll int n = m;

		while (n % 2 == 0) {
			h = true;
			n = n / 2;
		}

		if (h) {
			tmp.pb(2);
		}

		for (ll int i = 3; i <= sqrt(n); i = i + 2) {

			h = false;

			while (n % i == 0) {
				h = true;
				n = n / i;
			}

			if (h) {
				tmp.pb(i);
			}
		}

		h = false;

		if (n > 2)  {
			h = true;
		}

		if (h)
			tmp.pb(n);


		//now i have the vector tmp containing all primes of m.
		// for (auto it : tmp)
		// 	cout << it << " ";

		// cout << endl;

		ll int maxCoefficient = (a + M - 1) / g;

		ll int minCoefficient = (a / g);

		ll int ansRight = solve2(maxCoefficient , tmp);

		ll int ansLEft = solve2(minCoefficient - 1 , tmp);

		ll int finalans = ansRight - ansLEft;

		//now finalans is basically the no of non divisble items in the range.


		cout << finalans << endl;
	}

	return 0;
}
