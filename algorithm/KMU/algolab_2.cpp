// 주가 분석

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int testCase = 0;
    cin >> testCase ;

    while(testCase--){
        int Num = 0;
        cin >> Num ;
        int pre = 0;
        int cur = 0;
        int check = 0;
        int cnt = 0;

        for(int i=0; i<Num; i++){
            cin >> cur ;
            if(cur!=pre){
                if(i==0){pre=cur;}

                if(pre<cur)
                    check = cur;

                if(pre>cur && check == pre)
                        cnt ++;
            }
            pre = cur;
        } //for 종료
        cout << cnt <<endl;
    } //while
    return 0;
}
        
                  
    