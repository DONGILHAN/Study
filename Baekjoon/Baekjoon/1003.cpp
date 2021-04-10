#include <iostream>
using namespace std;

int main()
{
    int T, N, F[42]={0, 1};
    for( int a=2; a<=40;a++)
        F[a]=F[a-1]+F[a-2];
    cin >> T;
    for (int a=0; a<T;a++)
    {
        cin>>N;
        if (N==0)
            cout<<"1 0\n";
        else
            cout << F[N-1]<< " "<<F[N]<<"\n";
    }
}
