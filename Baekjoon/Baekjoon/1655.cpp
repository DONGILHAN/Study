#include <iostream>
#include <queue>
using namespace std;

int N, temp;
priority_queue<int,vector<int>, greater<int>> bigq;
priority_queue<int> smallq;
int main() {
    scanf("%d", &N);
    scanf("%d", &temp);
    printf("%d\n", temp);
    bigq.push(temp);
    for (int i = 0; i < N - 1; i++) {
        scanf("%d", &temp);
        if (temp > bigq.top())
            bigq.push(temp);
        else
            smallq.push(temp);
        if (bigq.size() - smallq.size() == 2) {
            smallq.push(bigq.top());
            bigq.pop();
        } else if (bigq.size() - smallq.size() == -2) {
            bigq.push(smallq.top());
            smallq.pop();
        }
        if (bigq.size() == smallq.size())
            printf("%d\n", smallq.top());
        else {
            if (bigq.size() > smallq.size())
                printf("%d\n", bigq.top());
            else
                printf("%d\n", smallq.top());
        }
    }
}