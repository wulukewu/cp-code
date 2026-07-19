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

template<typename T>
class fenwick{
public:
	vector<T>bit;
	int size=3e5;
	fenwick(int s){
		size=s;
		bit=vector<T>(size,0);
	}
	int lb(int x){
		return x&(-x);
	}

	void up(int x,int y){
		for(int i=x;i<size;i+=lb(i)) bit[i]+=y;
	}

	T sum(int x){
		T res=0;
		for(int i=x;i>=1;i-=lb(i)) res+=bit[i];
		return res;
	}

	void print(){
		for(int i=0;i<min((int)20,size);i++) cout<<bit[i]<<' ';
		cout<<endl;
	}
};
int M=1e9+7;


void solve(){
	fenwick<int>fen(3e5);
	int n,m;
	cin>>n>>m;
	vector<int>arr(n);
	FOR(i,0,n) {
		cin>>arr[i];
		fen.up(i+1,arr[i]);
	}

	int a,b,c;
	FOR(i,0,m){
		cin>>a>>b>>c;
		if(a==1){
			fen.up(b,-arr[b-1]);
			arr[b-1]=c;
			fen.up(b,arr[b-1]);
		}
		else{
			cout<<fen.sum(c)-fen.sum(b-1)<<endl;
		}
		// fen.print();
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