#include <iostream>
#include <queue>
using namespace std;

int N, temp;
priority_queue<int,vector<int>, greater<int>> plusq;
priority_queue<int> minusq;
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        if (temp == 0)
            if (plusq.empty() && minusq.empty())
                printf("0\n");
            else if (!plusq.empty() && minusq.empty()) {
                printf("%d\n", plusq.top());
                plusq.pop();
            } else if (plusq.empty() && !minusq.empty()) {
                printf("%d\n", minusq.top());
                minusq.pop();
            } else {
                if (plusq.top() >= (-1) * minusq.top()) {
                    printf("%d\n", minusq.top());
                    minusq.pop();
                } else {
                    printf("%d\n", plusq.top());
                    plusq.pop();
                }
            }
        else if (temp > 0)
            plusq.push(temp);
        else
            minusq.push(temp);
    }
}