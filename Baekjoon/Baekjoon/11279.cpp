#include <iostream>
#include <queue>
using namespace std;

int N, temp;
priority_queue<int> q;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        if (temp == 0) {
            if (q.empty())
                cout << "0\n";
            else {
                cout << q.top() << "\n";
                q.pop();
            }
        } else
            q.push(temp);
    }
}