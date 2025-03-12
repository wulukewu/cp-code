#include <iostream>
#include <math.h>

using namespace std;

int main() {

	string s;
	double h, w;
	double bmi;
	string state;
	for(int i=0; i<2; i++){
		cin >> s >> h >> w;
		
		h /= 100;
		bmi = w / pow(h, 2);
		
		// cout << bmi << endl;
		
		if(bmi<19){
			state="過輕";
		}else if(bmi<24){
			state="正常";
		}else if(bmi<27){
			state="過重";
		}else if(bmi<30){
			state="輕度肥胖";
		}else if(bmi<35){
			state="中度肥胖";
		}else{
			state="重度肥胖";
		}
		
		cout << s << "的身體狀況為" << state << endl;
	}
	
		
}