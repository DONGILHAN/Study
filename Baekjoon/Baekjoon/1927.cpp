#include <iostream>
#include <queue>
using namespace std;

int N, temp;
priority_queue<int,vector<int>, greater<int>> pq;
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        if (temp == 0)
            if (pq.empty())
                printf("0\n");
            else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        else
            pq.push(temp);
    }
}