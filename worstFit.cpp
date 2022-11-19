#include <bits/stdc++.h>
using namespace std;

void worstfit(int block[], int process[], int n, int m){

    int allocation[n] = {0};
    int index,maxempty;

    for(int i = 0; i < m; i++){
        index = INT_MIN;
        maxempty = INT_MIN;

        for (int j = 0; j < n; j++){
            if (block[j] >= process[i]){
                if((block[j] - process[i]) > maxempty){
                    maxempty = block[j] - process[i];
                    index = j+1;
                }
            }
        }

        if(index != INT_MIN){
            block[index-1] = block[index-1] - process[i];
            allocation[i] = index;
        }
    }

    cout <<"process\t"<<"allocated block"<<endl;
    for (int i = 0; i < n; i++){
        if (allocation[i] > 0){
            cout<<process[i]<<"\t   "<<allocation[i]<<endl;
        }
        else{
            cout<<process[i]<<"\t   "<<"Not allocated"<< endl;
        }
    }
}

int main(){
    int block[5] = {80, 200, 50, 120, 50};
    int process[5] = {160, 80, 20, 80, 200};

    int n = sizeof(block) / sizeof(block[0]);
    int m = sizeof(process) / sizeof(process[0]);

    worstfit(block, process, n, m);

    return 0;
}
