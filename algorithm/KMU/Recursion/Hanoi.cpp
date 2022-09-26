#include <iostream>
#define MAX_SIZE 1000

using namespace std;

void Hanoi(int Disk, int From, int Temp, int To);

int arr[MAX_SIZE];
int idx ;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    int tsetCase = 0;
    cin >> tsetCase;

    while(tsetCase--){
        int N = 0;
        cin >> N;
        idx = 0;
        Hanoi(N,1,2,3);
        cout << "\n";
    }

    return 0;

}

void Hanoi(int Disk, int From, int Temp, int To){
    if(Disk>0){
        Hanoi(Disk-1, From, To, Temp);
        if(To==3){
            arr[idx++] = Disk;
            cout << arr[idx-1] << " ";
        }
        if(From==3){
            idx--;
            if(idx==0){
                arr[idx] = 0;
                cout << arr[idx] <<" ";
            }
            else{
                cout << arr[idx-1] <<" ";
            }
        }
        Hanoi(Disk-1, Temp, From, To);
    }
}