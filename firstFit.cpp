#include<iostream>
using namespace std;

void firstfit(int block[],int process[],int n,int m){
    int allocation[n] = {0};

    for(int i=0; i<m; i++){
        for(int j =0; j<n; j++){
            if(block[j] >= process[i]){
                allocation[i] = j+1;
                block[j] = block[j] - process[i];
                break;
            }
        }
    }

    cout<<"process\t "<<"allocated block"<< endl;
    for(int i=0; i<n; i++){
        if(allocation[i] > 0){
            cout<<process[i]<<"\t   "<<allocation[i]<<endl;
        }
        else{
            cout<<process[i]<<"\t   "<<"Not allocated"<<endl;
        }
    }
}

int main(){
    int block[5] = {100,200,50,120,40};
    int process[5] = {160,80,50,100,200};

    int n = sizeof(block)/sizeof(block[0]);
    int m = sizeof(process)/sizeof(process[0]);

    firstfit(block,process,n,m);

    return 0;
}
