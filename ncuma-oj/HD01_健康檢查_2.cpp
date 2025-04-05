#include <iostream>
#include <vector>

using namespace std;

signed main(){
    int n;
    cin >> n;

    vector < vector < pair < string, int > > > arr(4);

    string s;
    double w, h;
    int bmi;
    for(int i=0; i<n; i++){
        cin >> s >> w >> h;
        // cout << w << ' ' << h << endl;

        bmi = w / ((h/100)*(h/100));
        // cout << bmi << endl;

        if(bmi<19){
            arr[0].push_back(make_pair(s, bmi));
        }else if(bmi < 24){
            arr[1].push_back(make_pair(s, bmi));
        }else if(bmi < 27){
            arr[2].push_back(make_pair(s, bmi));
        }else{
            arr[3].push_back(make_pair(s, bmi));
        }
    }

    cin >> s;

    int idx;
    if(s=="輕")idx=0;
    else if(s=="中")idx=1;
    else if(s=="重")idx=2;
    else idx=3;

    for(int i=0; i<arr[idx].size(); i++){
        cout << arr[idx][i].first << ' ' << arr[idx][i].second << endl;
    }

}