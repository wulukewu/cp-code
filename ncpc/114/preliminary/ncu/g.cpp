#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	queue < int > N;
	queue < int > C;
	queue < int > U;
/*	N.push(0);
	C.push(0);
	U.push(0);
*/

	int ans = 0;
	for(int i=0; i<n; i++){
		if(s[i]=='N'){
			if(!C.empty() and !U.empty() and i<C.front() and C.front()<U.front()){
				ans++;
				C.pop();
				U.pop();
			}else{
				N.push(i);
			}
		}else if(s[i]=='C'){
			if(!N.empty() and !U.empty() and N.front()<i and i<U.front()){
				ans++;
				N.pop();
				U.pop();
			}else if(!N.empty() and N.front()<i){
				C.push(i);
			}
		}else{
			if(!N.empty() and !C.empty() and N.front()<C.front() and C.front()<i){
				ans++;
				N.pop();
				C.pop();
			}else if(!C.empty() and C.front()<i){
				U.push(i);
			}
		}
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
