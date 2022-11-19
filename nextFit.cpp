#include<iostream>
using namespace std;

void Nextfit(int block[],int process[],int m,int n){
    int allocation[n] = {0};
    int j = 0,count=0;

    for(int i=0; i<n; i++){
        while (j < m) {
            if (block[j] >= process[i]) {
                allocation[i] = j+1;
                block[j] = block[j] - process[i];
                count=0;
                break;
            }
            count++;
            if(count == m){
                break;
            }
            j = (j + 1) % m;
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
    int block[3] = {5,10,20};
    int process[4] = {10,20,25,4};

    int m = sizeof(block)/sizeof(block[0]);
    int n = sizeof(process)/sizeof(process[0]);

    Nextfit(block,process,m,n);

    return 0;
}
