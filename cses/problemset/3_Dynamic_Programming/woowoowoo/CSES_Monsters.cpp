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
	int n,m;
	cin>>n>>m;
	vector<vector<int>>arr(n,vector<int>(m,0));
	string s;
	pair<int,int>st;
	queue<pair<int,int>>q;
	vector<vector<bool>>vv(n,vector<bool>(m,false));
	vector<vector<bool>>vvv(n,vector<bool>(m,false));
	vector<vector<char>>v(n,vector<char>(m,' '));
	vector<vector<int>>vi(n,vector<int>(m,0));
	FOR(i,0,n){
		cin>>s;
		FOR(j,0,m){
			if(s[j]=='#'){
				arr[i][j]=1;
			}
			if(s[j]=='A'){
				st.F=i;
				st.S=j;
				vvv[i][j]=true;
				v[i][j]='*';
			}
			if(s[j]=='M'){
				q.push({i,j});
				vv[i][j]=true;
			}
		}
	}
	if(st.F==n-1 || st.F==0 || st.S==0 || st.S==m-1){
		cout<<"YES\n0\n";
		return true;
	}

	queue<pair<int,int>>qa;
	qa.push(st);

	int dir[5]={1,0,-1,0,1};
	char dd[4]={'D','L','U','R'};
	int x,y;

	// FOR(i,0,n) print(arr[i]);

	while(!q.empty() || !qa.empty()){
		int a=q.sz(),b=qa.sz();
		FOR(i,0,a){
			FOR(j,0,4){
				x=q.front().F+dir[j];
				y=q.front().S+dir[j+1];
				if(x>=n || y>=m || x<0 || y<0) continue;
				if(arr[x][y] || vv[x][y]) continue;
				vv[x][y]=true;
				// v[x][y]='#';
				q.push({x,y});
			}
			q.pop();
		}
		FOR(i,0,b){
			FOR(j,0,4){
				x=qa.front().F+dir[j];
				y=qa.front().S+dir[j+1];
				if(x>=n || y>=m || x<0 || y<0) continue;
				if(arr[x][y] || v[x][y]!=' ' || vv[x][y] ) continue;
				v[x][y]=dd[j];
				vi[x][y]=vi[qa.front().F][qa.front().S]+1;
				qa.push({x,y});
			}
			qa.pop();
		}
	}

	// FOR(i,0,n) print(v[i]);
	int ans=INT_MAX;
	FOR(i,0,n) if(vi[i][0]) ans=min(ans,vi[i][0]);
	FOR(i,0,n) if(vi[i][m-1]) ans=min(ans,vi[i][m-1]);
	FOR(i,0,m) if(vi[0][i]) ans=min(ans,vi[0][i]);
	FOR(i,0,m) if(vi[n-1][i]) ans=min(ans,vi[n-1][i]);

	if(ans!=INT_MAX){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
		return true;
	}
	cout<<ans<<endl;

	auto find=[&](int x,int y)->void{
		vector<char>ans;
		while(x!=st.F || y!=st.S){
			ans.pb(v[x][y]);
			if(v[x][y]=='U'){
				x+=1;
			}
			else if(v[x][y]=='D'){
				x-=1;
			}
			else if(v[x][y]=='L'){
				y++;
			}
			else y--;

		}
		reverse(ALL(ans));
		print(ans);
	};

	FOR(i,0,n) if(vi[i][0]==ans){
		find(i,0);
		return true;
	}
	FOR(i,0,n) if(vi[i][m-1]==ans){
		find(i,m-1);
		return true;
	}
	FOR(i,0,m) if(vi[0][i]){
		find(0,i);
		return true;
	}
	FOR(i,0,m) if(vi[n-1][i]){
		find(n-1,i);
		return true;
	}

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