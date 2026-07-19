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
		cout<<u<<'\n';
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
	set<string>ans;
	string s;
	cin>>s;
	int n=s.sz();

	auto cre = [&](auto&& self,string &x,vector<bool> &v)->void{
		FOR(i,0,n){
			if(v[i]) continue;
			if(x.sz()==n-1){
				ans.insert(x+s[i]);
				return;
			}
			x+=s[i];
			v[i]=true;
			self(self,x,v);
			v[i]=false;
			x.pop_back();
		}
	};

	vector<bool>v(n,false);
	string t="";

	cre(cre,t,v);

	cout<<ans.sz()<<endl;
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