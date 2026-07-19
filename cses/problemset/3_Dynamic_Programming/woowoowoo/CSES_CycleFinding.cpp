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
	int n,m;
	cin>>n>>m;
	vector<vector<int>>arr(m,vector<int>(3));
	FOR(i,0,m)
	{
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}

	vector<int>dis(n+1,2e18);
	vector<int>p(n+1,-1);
	int y=0;
	FOR(i,0,1+n){
		y=0;
		FOR(j,0,m){
			if(dis[arr[j][1]]>dis[arr[j][0]]+arr[j][2]){
				dis[arr[j][1]]=dis[arr[j][0]]+arr[j][2];
				p[arr[j][1]]=arr[j][0];
				y=arr[j][1];
			}
		}
	}

	if(!y){
		cout<<"NO";
		return;
	}
	cout<<"YES\n";
	FOR(i,1,n+1) y = p[y];

    vector<int> cycle;
    int cur = y;
	do {
	    cycle.pb(cur);
	    cur = p[cur];
	} while (cur != y);

    cycle.pb(y);
    reverse(cycle.begin(), cycle.end());
    print(cycle);

}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}