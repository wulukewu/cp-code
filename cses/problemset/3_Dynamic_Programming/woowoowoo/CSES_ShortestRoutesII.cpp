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

bool solve(){
	int n,m,q,a,b,c;
	cin>>n>>m>>q;
	vector<vector<int>>arr(n+1,vector<int>(n+1,2e18));
	FOR(i,0,m){
		cin>>a>>b>>c;
		arr[a][b]=min(c,arr[a][b]);
		arr[b][a]=min(c,arr[a][b]);
	}
	FOR(i,1,n+1) arr[i][i]=0;
	FOR(k,1,n+1){
		FOR(i,1,n+1){
			FOR(j,1,n+1){
				arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
			}
		}
	}

	// FOR(i,0,n+1) print(arr[i]);

	FOR(i,0,q){
		cin>>a>>b;
		cout<<(arr[a][b]==(int)2e18 ? -1: arr[a][b])<<endl;
	}

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