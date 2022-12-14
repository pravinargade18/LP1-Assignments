#include<iostream>
using namespace std;

void findWaitingTime(int n,int at[],int bt[],int tempBurst[],int ct[],int wt[]){
    tempBurst[99] = 1000;
    int count = 0,smallest;

    for(int i = 0; count != n; i++){
        smallest = 99;
        for(int j = 0; j < n; j++){
            if(at[j] <= i && tempBurst[j] < tempBurst[smallest] && tempBurst[j] > 0){
                smallest = j;
            }
        }
            
        tempBurst[smallest]--;
        if(tempBurst[smallest] == 0){
            count++;
            ct[smallest] = i+1; 
            wt[smallest] = ct[smallest] - at[smallest] - bt[smallest];
        }
    }
}

void findTurnAroundTime(int n,int bt[],int wt[],int tat[]){
    for(int i=0; i<n; i++){
        tat[i] = bt[i]+wt[i];
    }
}

void findavgtime(int n,int at[],int bt[]){
    int wt[n],ct[n],tat[n],temp[n];
    float total_wt = 0,total_tat = 0;

    for(int i=0; i<n;i++){
        temp[i] = bt[i];
    }

    findWaitingTime(n,at,bt,temp,ct,wt);
    findTurnAroundTime(n,bt,wt,tat);

    cout <<" Arrival Time "<<" Burst Time "<<" Waiting Time "<<" Turn-Around Time "<<" Completion Time  "<<endl;
    for(int i=0; i<n; i++){
        total_wt += wt[i];
		total_tat += tat[i];

		cout<<"  "<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\t\t"<<ct[i]<<endl;
    } 
    cout<<"Average waiting time = "<<(float)total_wt/(float)n <<endl;
	cout<<"Average turn around time = "<<(float)total_tat/(float)n<<endl;
}

int main(){
    int bt[] = {5,3,6,5};
	int at[] = {1,1,2,3};

	findavgtime(4,at,bt);
    
    return 0;
}
