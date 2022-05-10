#include <iostream>
#include <string>

using namespace std;

string answer(string str ,string r)
{
    int len = str.length();
    if(len==1){return "0";}

    if(len<=2){
        if(str[0]-str[1] ==0){
            return r;
        }
        else{
            return "0";
        }
    }
    else{
        string temp ;
        int Num = len-1;
        int cnt = 0;
        for(int i=0; i<Num; i++){
            temp += str[i]; //10001 -> 100
        } // Num = 마지막을 제외함

        char test = str[Num-1] - str[Num];
        if(test<0){
            
            len = Num-2;
            cnt = 0;
            while(temp[len] == '0'){
                len--;
                cnt ++;
            } // 0이 안나올때까지
    
            temp[len] = temp[len] - 49 + '0'; // 자리수 하나 빼기

            for(int i=0; i<cnt; i++){
                len ++;
                temp[len] = 57;
            } // 9로 채워주는 반복문
            
            temp[Num-1] += 57 - str[Num] +1 ;
            r  += temp[Num-1]; 
           
            if(temp[0] == '0'){
                string swap;
                for(int k=1; k<temp.length(); k++){
                    swap += temp[k];
                }
                return answer(swap,r);
            }
            return answer(temp,r);

        } // 음수인경우
        else
            temp[Num-1] = test + '0';
            r  += temp[Num-1]; 
        return answer(temp,r);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCase = 0;
    cin >> testCase;
    while(testCase--)
    {
    string str;
    cin >> str;
    string R;
    int len = str.length();

    string ans = answer(str,R);
    if(ans=="0"){
        cout << ans <<"\n";
    }
    else
    {
    string temp;

    for(int i=ans.length()-1; i>=0; i--)
    {
        temp+= ans[i];
    }
    temp +=  str[len-1];
    cout << temp <<"\n";
    }
    } // 테스트 케이스
    return 0;
}
