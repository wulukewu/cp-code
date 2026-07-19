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
	int ans=0;
	vector<int>arr{4,8,4,0,0};
	// 11,12,13.22,23.32
	FOR(i,1,n+1){
		cout<<ans<<endl;
		if(i==1) ans+=6;
		else if(i==2) ans=28;
		else if(i==3) ans=96;
		else{
			arr[2]+=4;
			arr[3]+=4;
			arr[4]+=(i+1)*2-1-8;
			int t=0;
			t+=(((i+1)*(i+1))-3)*4;
			// cout<<t<<' ';
			t+=(((i+1)*(i+1))-4)*8;
			// cout<<t<<' ';
			t+=(((i+1)*(i+1))-5)*arr[2];
			// cout<<t<<' ';
			t+=(((i+1)*(i+1))-7)*arr[3];
			// cout<<t<<' ';
			t+=(((i+1)*(i+1))-9)*arr[4];
			// cout<<t<<' ';
			// print(arr);
			ans=t/2;
		}
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