#include <iostream>
#include <deque>
#include <string>
using namespace std;

int N, num;
deque<int> dq;
string operation;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> operation;
        if (operation == "push") {
            cin >> num;
            dq.push_back(num);
        } else if (operation == "pop") {
            if (dq.empty())
                cout << "-1\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        } else if (operation == "size")
            cout << dq.size() << "\n";
        else if (operation == "empty") {
            if (dq.empty())
                cout << "1\n";
            else
                cout << "0\n";
        } else if (operation == "front") {
            if (dq.empty())
                cout << "-1\n";
            else
                cout << dq.front() << "\n";
        } else if (operation == "back") {
            if (dq.empty())
                cout << "-1\n";
            else
                cout << dq.back() << "\n";
        }
    }
}