#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define int long long
using ll = long long;
const ll MOD = 998244353;
void addmod(ll &a, ll b){ a = (a+b) % MOD;}
void timesmod(ll &a, ll b){ a = (a*b) % MOD;}

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
		C *= n-i;
		C /= i+1;
		C %= MOD;
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
