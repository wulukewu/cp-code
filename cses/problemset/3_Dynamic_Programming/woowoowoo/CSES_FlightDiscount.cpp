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

bool solve(){
	int n,m,a,b,c;
	cin>>n>>m;
	vector<vector<pair<int,int>>>arr(n+1);
	FOR(i,0,m){
		cin>>a>>b>>c;
		arr[a].pb({b,c});
	}

	PQG<tuple<int,int,int>>pq;
	vector<vector<int>>v(2,vector<int>(n+1,2e18));
	v[0][1]=0;
	v[1][1]=0;
	pq.push({0,1,1});
	int x,y,z;
	while(!pq.empty()){
		tuple<int,int,int> t=pq.top();
		x=get<0>(t);
		y=get<1>(t);
		z=get<2>(t);
		pq.pop();

		// cout<<x<<' '<<y<<' '<<z<<endl;
		// if(v[z][y]!=2e18 && v[z][y]!=0) continue;
		// v[z][y]=x;
		if(v[!z][y] <x) continue;

		for(auto& i:arr[y]){
			if(z){
				if(v[0][i.F]>x+i.S){
					v[0][i.F]=x+i.S;
					pq.push({x+i.S,i.F,1});
				}
				if(v[1][i.F]>x+i.S/2){
					v[1][i.F]=x+i.S/2;
					pq.push({x+i.S/2,i.F,0});
				}
			}
			else{
				if(v[1][i.F]>x+i.S){
					v[1][i.F]=x+i.S;
					pq.push({x+i.S,i.F,0});
				}
			}
		}

	}
	// print(v[0]);
	// print(v[1]);
	cout<<min(v[0][n],v[1][n]);

	// cout<<"Yes\n";
	return true;
}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		if(!solve()) cout<<"No\n";
	}
}