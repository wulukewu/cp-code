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
	int n,q;
	cin>>n>>q;
	vector<vector<int>>arr(32,vector<int>(n+1));
	arr[0][0]=-1;
	FOR(i,1,n){
		cin>>arr[0][i];
		// arr[0][i]--;
	}
	FOR(i,1,32){
		arr[i][0]=-1;
		FOR(j,1,n){
			if(arr[i-1][j]==-1) arr[i][j]=-1;
			else arr[i][j]=arr[i-1][arr[i-1][j]-1];
		}
		// print(arr[i]);
		// if(i==2) break;
	}
	int a,b;
	FOR(i,0,q){
		cin>>a>>b;
		FOR(j,0,30){
			if((b&(1<<j))){
				// cout<<b<<' '<<j<<endl;
				a=arr[j][a-1];
			}
			if(a==-1) break;
		}
		cout<<a<<endl;
	}
}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}