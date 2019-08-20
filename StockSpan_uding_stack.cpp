#include<iostream>
#include<stack>

using namespace std;

void PrintSpan(int *a,int n)
{
    stack<int> s;
    s.push(0);
    cout<<"1"<<" ";

    for(int i=1;i<n;i++)
    {
        while(s.empty()==false && a[s.top()]<=a[i])
        {
            s.pop();
        }
        int stock= (s.empty()) ? (i+1) : (i-s.top());
        cout<<stock<<" ";
        s.push(i);

    }

}
int main()
{
    int n,a[10000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    PrintSpan(a,n);
    cout<<"END";
}
