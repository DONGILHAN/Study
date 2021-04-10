#include <iostream>
#include <deque>
using namespace std;

int N, answer;
deque<int> dq;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        dq.push_back(i);
    while (dq.size() != 1) {
        dq.pop_front();
        answer = dq.front();
        dq.push_back(dq.front());
        dq.pop_front();
    }
    if(N==1)
        cout<< "1";
    else
        cout << answer;
}