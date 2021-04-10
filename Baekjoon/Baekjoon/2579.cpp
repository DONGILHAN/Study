#include <iostream>
#include <algorithm>
using namespace std;

int stair[301] = {0, };
int answer[301] = {0, };

int main() {
    int N;
    cin >> N;
    for (int a = 1; a <= N; a++)
        cin >> stair[a];
    answer[1] = stair[1];
    answer[2] = max(stair[2], stair[1]+stair[2]);
    answer[3] = max(stair[1]+stair[3], stair[2]+stair[3]);
    for (int a= 4; a<=N; a++)
        answer[a] = max(answer[a-3] + stair[a-1] + stair[a], answer[a-2]+stair[a]);
    cout<<answer[N];
}