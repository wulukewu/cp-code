#include <iostream>
using namespace std;

int N;
int c, i;
vector <int> chess;

void dfs(){

    if(i == N){
        c++;
        return;
    }

    for (int j = 0; j < N; j++){
        bool det = true;
        for (int ii = 0; ii < i; ii++){
            int jj = chess[ii];

            if (j == jj || (abs(i-ii) == abs(j-jj))){
                det = false;
                break;
            }

        }
        
        if (det){
            chess[i] = j;
            i++;
            dfs();
            i--;
            chess[i] = -1;
        }
    }
}

int main(){
    cin >> N;
    chess = vector <int> (N, -1);
    c = 0;
    i = 0;
    dfs();
    cout << c;
}