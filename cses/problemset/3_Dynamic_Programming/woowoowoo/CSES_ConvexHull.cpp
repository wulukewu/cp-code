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

int cross(pair<int,int>a, pair<int,int>b, pair<int,int>c){
	return ((a.F-b.F)*(b.S-c.S)-(a.S-b.S)*(b.F-c.F));
}

void solve(){
	int n;
	cin>>n;
	vector<pair<int,int>>arr(n);
	FOR(i,0,n) cin>>arr[i].F>>arr[i].S;
	sort(ALL(arr));
	vector<pair<int,int>>ans(n*2+2);
	int m=0;
	FOR(i,0,n){
		while(m>=2 && cross(ans[m-2],ans[m-1],arr[i])<0) m--;
		ans[m++]=arr[i];
	}

	// print(ans);

	int t=m+1;
	for(int i=n-2;i>=0;--i){
		while(m>=t && cross(ans[m-2],ans[m-1],arr[i])<0) m--;
		ans[m++]=arr[i];
	}

	// print(ans);

	cout<<m-1<<endl;
	FOR(i,0,m-1){
		// cout<<ans[i]<<endl;
		cout<<ans[i].F<<' '<<ans[i].S<<endl;
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