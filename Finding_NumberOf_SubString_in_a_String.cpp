#include <iostream>
//#include<string>
using namespace std;

// Returns true if s1 is substring of s2
int isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();
    int count=0;
    int i;

    /* A loop to slide pat[] one by one */
    for (i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            count++;

    }
    if(count==0)
    {
        return -1;
    }
    else
    {
        return count;
    }


}

/* Driver program to test above function */
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s2;
        cin>>s2;
        string s1 = "gfg";
        cout<<isSubstring(s1,s2)<<endl;
    }
    return 0;
}
