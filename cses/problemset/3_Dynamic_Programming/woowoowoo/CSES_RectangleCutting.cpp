// cp
#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define endl '\n'
#define sz size
#define Fio ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using PQG = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
void print(T a){
	for(auto u:a){
		cout<<u<<' ';
	}
	cout<<endl;
}
template <typename T>
void printQ(priority_queue<T> pq) {
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
int M=1e9+7;


vector<vector<int>>dp(501,vector<int>(501,-1));
int dps(int a,int b){
	if(a==b) return 0;
	if(a>b)swap(a,b);
	if(dp[a][b]!=-1) return dp[a][b];
	int res=INT_MAX;
	FOR(i,1,a){
		res=min(res,dps(b,a-i)+dps(i,b)+1);
	}
	FOR(i,1,b){
		res=min(res,dps(a,i)+dps(a,b-i)+1);
	}
	dp[a][b]=res;
	return res;
}
bool solve(){
	int a,b;
	cin>>a>>b;
	cout<<dps(a,b);
	// FOR(i,0,a+1) {
		// FOR(j,0,b+1) cout<<dp[i][j]<<' ';
		// cout<<endl;
	// }
	// cout<<"Yes\n";
	return true;
}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		if(!solve()) cout<<"No\n";
	}
}