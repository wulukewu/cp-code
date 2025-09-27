#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	
	string x;
	bool ans = false;
	for(int i=0; i<n; i++){
		cin >> x;
		if(x==s) ans = true;
	}
	
	if(ans) cout << "Yes" << endl;
	else cout << "No" << endl;
}
