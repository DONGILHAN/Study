#include <iostream>
#include <algorithm>
using namespace std;

char temp1[1002];
char temp2[1002];
char one[1002];
char two[1002];
int dp[1001][1001]={0, };
int a, b;
int main()
{
    cin>>temp1;
    cin>>temp2;
    for (int a=1; a<=1001;a++) {
        one[a] = temp1[a - 1];
        two[a] = temp2[a - 1];
    }

    for(a=1;one[a];a++)
        for(b=1;two[b];b++)
            dp[a][b] = max({ dp[a][b - 1], dp[a - 1][b],
                             dp[a - 1][b - 1] + (one[a] == two[b])});
    cout << dp[a-1][b-1];
}