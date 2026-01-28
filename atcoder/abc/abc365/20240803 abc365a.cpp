// ==================================================
// Problem   : ABC365_A - Leap Year
// URL       : https://atcoder.jp/contests/abc365/tasks/abc365_a
// ==================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
// #define int long long
using namespace std;
#include <fstream>

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int y;
    cin >> y;

    int a;
    if(y%4==0){
        if(y%100==0){
            if(y%400==0){
                a=366;
            }else{
                a=365;
            }
        }else{
            a=366;
        }
    }else if(y%100==0){
        if(y%400==0){
            a=366;
        }else{
            a=365;
        }
    }else{
        a=365;
    }

    cout << a;
}
