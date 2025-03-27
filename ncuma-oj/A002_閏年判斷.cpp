#include <iostream>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	bool det;
	
	if (n%400==0){
		det = true;	
	} else if (n%100==0){
		det = false;
	} else if (n%4==0){
		det = true;
	} else{
		det = false;
	}
	
	if (det){
		cout << "閏年";
	}else{
		cout << "平年";
	}

}