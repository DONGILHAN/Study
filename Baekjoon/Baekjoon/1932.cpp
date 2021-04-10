#include <iostream>
#include <algorithm>
using namespace std;

int answers[501][501]={0, };
int triangle[501][501]={0, };
int main()
{
    int N;
    cin >> N;
    int answer=0;
    for (int a=1; a<=N; a++) {
        for(int b=1;b<=a;b++) {
            cin >> triangle[a][b];
            answers[a][b] = max(answers[a - 1][b - 1], answers[a - 1][b]) + triangle[a][b];
        }
    }
    for(int a=1;a<=N;a++)
    {
        if (answer < answers[N][a])
            answer = answers[N][a];
    }
    cout<<answer;
}