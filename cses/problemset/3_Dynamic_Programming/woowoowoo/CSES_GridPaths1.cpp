#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define Fio ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
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
signed main(){
	Fio;
	int n;
	cin>>n;
	vector<vector<int>>arr(n,vector<int>(n,0));
	string s;
	FOR(i,0,n){
		cin>>s;
		FOR(j,0,n){
			if(s[j]=='*') arr[i][j]=-1;
		}
	}
	arr[0][0]=(arr[0][0]==-1 ? 0 : 1);
	FOR(i,0,n){
		FOR(j,0,n){
			if(arr[i][j]==-1) continue;
			if(i-1>=0 && arr[i-1][j]!=-1) arr[i][j]+=arr[i-1][j];
			if(j-1>=0 && arr[i][j-1]!=-1) arr[i][j]+=arr[i][j-1];
			arr[i][j]%=M;
		}
	}
	cout<<(arr[n-1][n-1]==-1 ? 0 : arr[n-1][n-1]);

}