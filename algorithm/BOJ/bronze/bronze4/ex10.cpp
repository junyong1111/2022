#include <iostream>

using namespace std;

int main(){

    int H , M, S , T;
    cin >> H >> M >> S >> T;

    while(T!=0){
        if(T>=3600){
            H = H+ T/3600; 
            T = T%3600;
        }
        else if(T>=60){
            M = M+ T/60;
            T = T%60;
        }
        else{
            S = S+T;
            T = 0;
        }
    }

    if(S>=60){
        M = M+ (S/60);
        S = S%60;
    }

    if(M>=60){
        H= H+ (M/60);
        M = M%60;
    }

    if(H>=24){
        H = H%24;
    }
    


    cout << H << " " << M << " " << S ;



    return 0;
}