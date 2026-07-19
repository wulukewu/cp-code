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
signed main(){
	Fio;
	int n;
	int M=1e9+7;
	cin>>n;
	vector<int>arr(n+1,0);
	arr[0]=1;
	FOR(i,0,n+1){
		FOR(j,1,7){
			if(i-j>=0) {
				arr[i]+=arr[i-j];
				arr[i]%=M;
			}
		}
	}
	cout<<arr[n];
}