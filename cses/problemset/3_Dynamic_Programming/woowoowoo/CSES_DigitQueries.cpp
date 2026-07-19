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
	// if(n<=9) cout<<n<<endl;
	int x=9;
	FOR(i,0,18){
		if(n<=x*(i+1)){
			int ans=x/9+(n+i)/(i+1)-1;
			int cnt=i+1-(n+i)%(i+1);
			// cout<<ans<<endl;
			while(--cnt>0) ans/=10;
			cout<<ans%10<<endl;
			return;
		}
		n-=x*(i+1);
		x*=10;
	}
}


signed main(){
	Fio;
	int T=1;
	cin>>T;
	while(T--) {
		solve();
	}
}