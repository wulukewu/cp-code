#include <iostream>

using namespace std;

int main() {

	string s;
	cin >> s;
	int n = s.size();
	
	char t;
	int c = 'a' - 'A';

	for(int i=0; i<n; i++){
		t = s[i];
		if(t>='A' and t<='Z'){
			t += c;
		}else if(t>='a' and t<='z'){
			t -= c;
		}
		
		cout << t;
	}	
}