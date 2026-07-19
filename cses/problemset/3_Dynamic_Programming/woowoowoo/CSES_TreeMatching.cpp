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

void solve(){
	int n,a,b;
	cin>>n;
	vector<vector<int>>arr(n+1);
	vector<int>cnt(n+1,0);
	FOR(i,0,n-1){
		cin>>a>>b;
		arr[a].pb(b);
		arr[b].pb(a);
		cnt[a]++;
		cnt[b]++;
	}
	queue<int>q;
	FOR(i,0,n+1){
		if(cnt[i]==1) {
			q.push(i);
			// cnt[i]--;
		}
	}
	// print(cnt);
	int ans=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int y=-1;
		if(!cnt[x]) continue;
		for(auto& i:arr[x]){
			if(!cnt[i]) continue;
			else{
				y=i;
				break;
			}
		}
		ans++;
		cnt[x]=0;
		cnt[y]=0;
		// cout<<x<<' '<<arr[x][0]<<endl;
		for(auto& i:arr[y]){
			if(!cnt[i])continue;
			if((--cnt[i])==1) {
				// cout<<i<<endl;
				q.push(i);
			}
		}
		// print(cnt);
	}
	cout<<ans;
}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}