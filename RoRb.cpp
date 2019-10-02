#include<bits/stdc++.h>
using namespace std;

struct process
{
    string name;
    int arTime=0;
    int bTime;
    int countTime;
};

int main()
{

    queue<process> que;
    int processNum,totalTime=0,tArTime=0,quantam,totalWaitTime=0;
    process pp,pq;
    unordered_map<string,int>mpp;
    process arr[10000];




    cout<<"Enter the number of process"<<endl;
    cin>>processNum;

    cout<<"Enter the Quantam Time"<<endl;
    cin>>quantam;

    cout<<endl;

    for(int i=0; i<processNum; i++)
    {
        cout<<"Enter the process name"<<endl;
        cin>>pp.name;

        cout<<"Enter the burst time"<<endl;
        cin>>pp.bTime;

        pp.countTime=pp.bTime;

        que.push(pp);
        arr[i]=pp;
        mpp[pq.name]=0;

        cout<<endl;
    }
    while(!que.empty())
    {
        pq=que.front();
        que.pop();

        //cout<<pq.name<<endl;

        if(pq.countTime<quantam)
            totalTime+=pq.countTime;
        else
            totalTime+=quantam;

        pq.countTime-=quantam;
        mpp[pq.name]+=totalTime-pq.arTime;
        pq.arTime=totalTime;

        if(pq.countTime>0)
            que.push(pq);
    }
    cout<<"Processes  Burst time  Waiting time  Turn around time"<<endl;
    for(int i=0; i<processNum; i++)
    {
        pq=arr[i];
        cout<<pq.name<<"\t\t"<<pq.bTime<<"\t"<<mpp[pq.name]-pq.bTime<<"\t\t"<<mpp[pq.name]<<endl;
        tArTime+=mpp[pq.name];
        totalWaitTime+=mpp[pq.name]-pq.bTime;
    }
    cout<<"\nTotal waiting time : "<<totalWaitTime<<endl;
    cout<<"Average waiting time : "<<(double)totalWaitTime/processNum<<endl;
    return 0;
}
