#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

#define SIZE 10001


using namespace std;

int solution(vector<int> topping) {
    int len = topping.size();
    
   
    int answer = -1;
    int Cnt = 0;
    int cmp = 10001;

    for(int i=0; i<len; i++){
        // set<int>Obro;
        // set<int>Ybro;
        bool check = false;
        

        vector<int>Obro(SIZE, 0);
        vector<int>Ybro(SIZE, 0);
        int Osz = 0;
        int Ysz = 0;
        Obro[topping[0]] = 1;
        Osz++;

        for(int j=1; j<len; j++){
            while(j<=i){
                if(Obro[topping[j]]==0){
                    Obro[topping[j]] = 1;
                    Osz++;
                    if(Osz>cmp){return Cnt;}
                }   
                j++;
            } //while
            
            if(Ybro[topping[j]]==0){
                Ybro[topping[j]] = 1;
                Ysz++;
            }     
        } //_for j

        if(Osz == Ysz){
            cmp = Osz;
            Cnt++;
        }
    } //_For i
    answer = Cnt ;

    return answer;
}