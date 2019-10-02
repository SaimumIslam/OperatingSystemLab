#include<bits/stdc++.h>
using namespace std;

struct process
{
    string name;
    int arTime;
    int bTime;

    bool operator<(const process &p)const
    {
        return arTime > p.arTime;
    }
};
int main()
{
    priority_queue<process> que;
    int processNum,waitTime=0,totalWaitTime=0,tArTime=0;
    process pp,pq;

    process Arr[100];

    cout<<"Enter the number of process"<<endl;
    cin>>processNum;
    cout<<endl;

    for(int i=0; i<processNum; i++)
    {
        cout<<"Enter the process name"<<endl;
        cin>>pp.name;

        cout<<"Enter the burst time"<<endl;
        cin>>pp.bTime;

        cout<<"Enter the arriving time"<<endl;
        cin>>pp.arTime;

        que.push(pp);
        cout<<endl;
    }

    if(!que.empty())
    {
        pq=que.top();
        tArTime=pq.arTime;
    }
    int j=0;
    while(!que.empty())
    {
        pq=que.top();
        que.pop();

        Arr[j]=pq;
        j++;

        waitTime=tArTime-pq.arTime;
        if(waitTime<0)
        {
            waitTime=0;
            tArTime+=pq.arTime;
        }
        totalWaitTime+=waitTime;
        tArTime+=pq.bTime;


        cout<<"Processes  Burst time  Waiting time  tr time"<<endl;
        cout<<pq.name<<"\t\t"<<pq.bTime<<"\t"<<waitTime<<"\t\t"<<tArTime-pq.arTime<<endl;

    }
    cout<<"\nTotal waiting time : "<<totalWaitTime<<endl;
    cout<<"Average waiting time : "<<(double)totalWaitTime/processNum<<endl;

    cout<<"\n\nGhant chart\n"<<endl;
    for(int k=0; k<processNum; k++)
        for(int j=0; j<Arr[k].bTime; j++)
            cout<<"--";
    cout<<endl;
    cout<<"|";
    for(int k=0; k<processNum; k++)
    {
        for(int j=0; j<(Arr[k].bTime/2); j++)
            cout<<" ";
        cout<<Arr[k].name;
        for(int j=0; j<(Arr[k].bTime/2); j++)
            cout<<" ";
        cout<<"|";
    }
    cout<<endl;
    for(int k=0; k<processNum; k++)
        for(int j=0; j<Arr[k].bTime; j++)
            cout<<" --";
    cout<<endl;
    int tr=0;
    for(int k=0; k<processNum; k++)
    {
        if(k!=0)
            cout<<",";
        cout<<Arr[k].arTime;
        for(int j=0; j<Arr[k].bTime-1; j++)
            cout<<" ";
        tr+=Arr[k].bTime;
        cout<<tr;
    }
    return 0;
}
