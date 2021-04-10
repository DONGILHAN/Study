#include <iostream>

using namespace std;

//1049
double N=0, M=0;
double lines[50][2] = {0,};
int main()
{
    double answer=0;
    cin >> N >> M;
    for (int a=0; a<M;a++)
    {
        cin>>lines[a][0]>>lines[a][1];
        lines[a][0]/=6;
    }
    double minpkg=lines[0][0];
    double minone=lines[0][1];
    for(int a=0; a<M;a++)
    {
        if(minpkg >= lines[a][0])
            minpkg = lines[a][0];
        if(minone >= lines[a][1])
            minone = lines[a][1];
    }
    if (minone <= minpkg)
        answer = minone*N;
    else
    {
        while(N>=6)
        {
            answer += (minpkg*6);
            N-=6;
        }
        if((N*minone) <= (minpkg*6))
            answer += (N*minone);
        else
            answer += (minpkg*6);
    }
    cout<<answer;
}