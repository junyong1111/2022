#include <iostream>

using namespace std;

typedef struct Room{
    int startTime ;
    int finishTime;
}room;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase= 0;
    cin >> testCase;

    while(testCase--)
    {
        int size = 0;
        cin >> size;
        room * R = new room[size+1];
        int answer = 0;

        for(int i=0; i<size; i++)
            cin >> R[i].startTime >> R[i].finishTime;

        for(int i=0; i<size-1; i++){
            int min = R[i].finishTime;
            int idx = i;
            for(int j=i+1; j<size; j++)
            {
                if(min>R[j].finishTime)
                {
                    min = R[j].finishTime;
                    idx = j;
                }
            }
            room temp;
            temp.startTime = R[idx].startTime;
            temp.finishTime = min;
            R[idx].startTime = R[i].startTime;
            R[idx].finishTime = R[i].finishTime;
            R[i].startTime = temp.startTime;
            R[i].finishTime = temp.finishTime;
        }
        
        answer ++;
        int finishTime  = R[0].finishTime;
        for(int i=1; i<size; i++)
        {
            if(R[i].startTime >=finishTime)
            {
                answer ++;
                finishTime = R[i].finishTime;
            }
        }
        cout << answer << "\n";

        // for(int i=0; i<size; i++){
        //     cout << R[i].startTime << " "<< R[i].finishTime <<" ";
        // }
        // cout <<endl;
    
    }
    return 0;
}