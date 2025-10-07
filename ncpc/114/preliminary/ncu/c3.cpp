#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define int long long
using ll = long long;
const ll MOD = 998244353;
void addmod(ll &a, ll b){ a = (a+b) % MOD;}
void timesmod(ll &a, ll b){ a = (a*b) % MOD;}
ll POW(ll a, ll b){ll res = 1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}

void solve(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin >> nums[i];
	}
	sort(nums.begin(),nums.end());
	int C = 1,ans = 0;
	for(int i=0;i<n;i++){
		//C = C * (n-i) / (i+1);
		timesmod(C, n-i);
		C = C*POW(i+1, MOD-2) % MOD;
		int add = nums[i];
		timesmod(add, C);
		addmod(ans, add);
	}
	cout << ans << endl;
}

signed main(){
	ios::sync_with_stdio(false), cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--) solve();
	return 0;
}
