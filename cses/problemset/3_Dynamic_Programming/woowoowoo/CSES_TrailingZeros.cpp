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
template<typename T>
void printp(T a){
	for(auto u:a){
		cout<<u.F<<' '<<u.S<<endl;
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
	int n;
	cin>>n;
	int ans=0,x=1,y=1;
	FOR(i,1,14){
		x*=10;
		y*=5;
		ans+=n/x;
		ans+=n/y-n/x;
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