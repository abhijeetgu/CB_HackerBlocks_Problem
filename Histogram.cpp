#include <bits/stdc++.h>
#include <fstream>
#include <ctime>
#include <chrono>


using namespace std;

long long arr[10000000];
int main()
 {

        long long n;
        cin>>n;

        for(long long i=0;i<n;i++)
        cin>>arr[i];



        long long max_area=-1;
        stack<long long>s;
        long long i=0;
        while(i<n)
        {
            if(s.empty()||arr[s.top()]<=arr[i])
            {
                s.push(i++);
            }
            else
            {
                long long top_index=s.top();
                s.pop();

                long long currarea=arr[top_index]*(s.empty()?i:i-1-s.top());

                if(currarea>max_area)
                max_area=currarea;
            }
        }


        while(!s.empty())
        {
            long long top_index=s.top();
            s.pop();

            long long currarea=arr[top_index]*(s.empty()?i:i-1-s.top());

            if(currarea>max_area)
            max_area=currarea;
    }

    cout<<max_area<<endl;


	return 0;
}
