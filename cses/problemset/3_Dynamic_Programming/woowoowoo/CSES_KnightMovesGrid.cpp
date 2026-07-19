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
	vector<T>bit;int size=3e5;
	fenwick(int s){size=s;bit=vector<T>(size,0);}
	int lb(int x){return x&(-x);}
	void up(int x,T y){for(int i=x;i<size;i+=lb(i))bit[i]+=y;}
	T sum(int x){T res=0;for(int i=x;i>=1;i-=lb(i))res+=bit[i];return res;}
};

template<class T>
class segment{
public:
	int n;vector<int>arr;
	segment(vector<T>&init){
		n=init.sz();arr=vector<T>(n*2,0);
		for(int i=0;i<n;i++)arr[i+n]=init[i];
		for(int i=n-1;i>0;i--){arr[i]=action(arr[i*2],arr[i*2 | 1]);}
	}
	int action(int a,int b){
		return min(a,b);    //###############
	}
	void modify(int x,int y){
		arr[x+n-1]=y;       //###############
		for(int i=(n+x-1)/2;i>=1;i/=2){
			arr[i]=action(arr[i*2],arr[i*2+1]);
		}
	}
	int query(int l,int r){
		int res=INT_MAX;		//###########
		for(l+=n-1,r+=n-1;l<=r;l/=2,r/=2){
			if(l&1) res=action(res,arr[l++]);
			if(!(r&1)) res=action(res,arr[r--]);}
		return res;
	}
};

int M=1e9+7;

void solve(){
	int n;
	cin>>n;
	vector<vector<int>>arr(n,vector<int>(n,0));
	arr[0][0]=1;
	queue<pair<int,int>>q;
	q.push({0,0});

	int d[8][2]={
		{1,2},
		{1,-2},
		{2,1},
		{2,-1},
		{-1,2},
		{-1,-2},
		{-2,1},
		{-2,-1}
	};

	while(!q.empty()){
		FOR(i,0,8){
			int x=q.front().F+d[i][0],y=q.front().S+d[i][1];
			if(x>=n || y>=n || x<0 || y<0) continue;
			if(arr[x][y]) continue;
			arr[x][y]=arr[q.front().F][q.front().S]+1;
			q.push({x,y});
		}
		q.pop();
	}

	FOR(i,0,n) FOR(j,0,n) arr[i][j]--;

	FOR(i,0,n) print(arr[i]);
}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}