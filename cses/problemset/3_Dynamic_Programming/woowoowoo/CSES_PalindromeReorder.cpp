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
		cout<<u;
	}
	// cout<<endl;
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
	string s;
	cin>>s;
	vector<int>arr(26,0);
	for(auto& i:s) arr[i-'A']++;
	int cnt=0;
	FOR(i,0,26) {
		if(arr[i]%2){
			cnt++;
		}
		if(cnt>1){
			cout<<"NO SOLUTION";
			return;
		}
	}
	string ans="";
	FOR(i,0,26){
		FOR(j,0,arr[i]/2)ans+=(char)(i+'A');
	}
	print(ans);
	FOR(i,0,26){
		if(arr[i]&1){
			cout<<(char)(i+'A');
		}
	}
	reverse(ALL(ans));
	print(ans);
}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}