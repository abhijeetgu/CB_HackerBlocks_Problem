#include<iostream>
using namespace std;

//Impelementing Templement queue class
template<typename T>
class queue
{
    T *arr;
    int cs;
    int ms;
    int f;
    int r;

public:
    //Constructor
    queue(int ds=6)
    {
        ms=ds;
        cs=0;
        f=0;
        r=ms-1;
        arr=new T[ms];
    }

    //push:enqueue data
    bool isfull(){

        return cs==ms;
    }
    bool isempty()
    {

        return cs==0;
    }

    void push(T data)
    {
        if(!isfull())
        {
            r=(r+1)%ms;
            arr[r]=data;
            cs++;
        }
    }
    void pop()
    {
        if(!isempty())
        {
            f=(f+1)%ms;
            cs--;
        }
    }
    T front()
    {
        return arr[f];
    }

};

int main()
{
    queue<int> q(10);

    for(int i=0;i<8;i++)
    {
        q.push(i);
    }

    q.pop();
    q.push(8);

    while(!q.isempty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}
