#include<iostream>
using namespace std;

int main()
{
    int n,arr[10000];
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
      int stock=1;

      for(int j=i-1;j>=0;j--)
      {
          if(arr[j]<=arr[i])
          {
              stock++;
          }
          else
          {
              break;
          }
      }
      cout<<stock<<" ";
    }
    cout<<"END";
    return 0;


}
