// 정사각형 출력

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int Num ;
    cin >> Num;
    char matrix[Num][Num];
    int N = 0;
    int M = 0;
    for(int i=0; i<Num; i++){
        for(int j=0; j<Num; j++){
            matrix[i][j] = '.';
        }
    }
        for(int x=0; x<Num; x++){
            if(M==0 || M==Num/2 || M == (Num-1))
                {
                    matrix[N][M] = '+';
                    matrix[Num-1][M++] = '+';    
                }
        
            else
            {
                matrix[N][M] = '-';
                matrix[Num/2][M] = '-';
                matrix[Num-1][M++] = '-';           
            }   

        } 
        for(int x=0; x<Num; x++){
        
             if(N==0 || N==Num/2 || N ==(Num-1)){
                matrix[--N][M] = '+';
                N++;
                matrix[N++][Num-1] = '+'; 
            }
            else{
                matrix[--N][M] = '|';
                N++;
                matrix[N][Num/2]= '|';
                matrix[N++][Num-1] = '|'; 
            }
        }
        N=0;
        M=0;
        for(int x=0; x<Num-2; x++){
            if(N==M){
                 if(M!=Num-2)
                 {
                     matrix[++N][++M] = '\\';
                     matrix[N][Num-M-1] = '/';
                 }           
            }
            else if(N == (Num-M)-1){
                matrix[++N][M++] = '/';
                cout << "N is " << N  << " " << endl;
            }
    
        }
        matrix[Num/2][Num/2] = '*';
     for(int i=0; i<Num; i++){
        for(int j=0; j<Num; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
}
       
 
    return 0;
}