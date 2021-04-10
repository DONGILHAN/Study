#include <iostream>
#include <algorithm>
using namespace std;

int answer[1000001]={0,0,1,1 };
int main()
{
    int N;
    cin>>N;
    for (int a=4;a<=N;a++)
    {
        answer[a] = answer[a-1]+1;
        if(a%2 == 0)
            answer[a] = min(answer[a], answer[a/2]+1);
        if(a%3 == 0)
            answer[a] = min(answer[a], answer[a/3]+1);
    }
    cout<<answer[N];
}