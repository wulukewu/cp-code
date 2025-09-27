#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	d
	queue < int > N;
	queue < int > C;
	queue < int > U;

	int ans = 0;
	for(int i=0; i<n; i++){
		if(s[i]=='N'){
			N.push(i);
		}else if(s[i]=='C'){
			if(!N.empty() and N.front()<i){
				C.push(i);
			}
		}else{
			if(!N.empty() and !C.empty() and N.front()<C.front() and C.front()<i){
				ans++;
				N.pop();
				C.pop();
				//while(!N.empty()) N.pop();
			}
		}
		if(N.empty()) while(!C.empty()) C.pop();
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}
