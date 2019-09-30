/*#include<iostream>
#include<vector>
#include<queue>
#include<functional>*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //deafault max_heap
    //priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> pq;  //min_heap

    int a[6]={4,1,12,0,3,9};
    //Insert element in pq
    for(int i=0;i<6;i++)
    {
        pq.push(a[i]);
    }
    //for printing
    while(!pq.empty())
    {
        cout<<pq.top()<<",";
         pq.pop();
    }
    return 0;
}
