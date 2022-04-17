#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int check  = 0;
    int cnt = 0;
    cin >>check;
    for(int i =0; i<5; i++){
        int temp ;
        cin >>temp;
        if(temp == check)
            cnt ++;
    }
    cout << cnt;
    return 0;
}
