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
void printB(int x, int n){
	string s="";
	FOR(i,0,n){
		s+=(x%2)+'0';
		x/=2;
	}
	reverse(ALL(s));
	print(s);
}
int M=1e9+7;

void solve(){
	int n;
	cin>>n;
	int ans=0,t;
	vector<bool>v(1<<n+1,false);
	v[0]=true;
	printB(0,n);

	auto cre=[&](auto&& self,int x)->void{
		FOR(i,0,n){
			t=(1<<i)&x ? x-(1<<i) : x+(1<<i);
			if(!v[t]){
				printB(t,n);
				v[t]=true;
				self(self,t);
				break;
			}
		}
	};

	cre(cre,ans);

}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}