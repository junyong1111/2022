#include <iostream>
#define MAX_SIZE 101
#define INF 2100000000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--)
    {
        int mSize = 0;
        cin >> mSize;

        int adjM[mSize+2][mSize+2];
        int nearest[MAX_SIZE] = {0};
        int distance[MAX_SIZE] ={0};

        for(int i=0; i<=mSize; i++){
            for(int j=0; j<=mSize; j++){
                adjM[i][j] = INF;
            }
        }
        for(int i=0; i<=mSize+1; i++)
            adjM[i][i] = 0;

        for(int i=1; i<=mSize; i++)
        {
            int nodeIdx = 0;
            cin >>nodeIdx;

            int nodeSz = 0;
            cin >>nodeSz;
            
            for(int j=0; j<nodeSz; j++)
            {
                int node = 0;
                int weight = 0;
                cin >> node >> weight;
                adjM[nodeIdx][node] = weight;
            }
        }
        for(int i=1; i<=mSize; i++){
            nearest[i] = 1;
            distance[i] = adjM[1][i];
        }
        int edgecnt = 0;
        int edgeanswer = 0;
        while(edgecnt < mSize-1)
        {
            int min = INF;
            int idx = 0;
            for(int i=2; i<=mSize; i++)
            {
                if(0<distance[i]&& distance[i]<min){
                    min = distance[i];
                    idx = i;
                }
            }
            edgecnt ++;
            edgeanswer += min;
            distance[idx] = distance[idx]*-1;

            for(int i=2; i<=mSize; i++)
            {
                if(distance[i] > adjM[i][idx])
                {
                    distance[i] = adjM[i][idx];
                    nearest[i] = idx;
                }
            }
        }
        
        cout << edgeanswer <<  "\n";
    
    } //while

    return 0;
}