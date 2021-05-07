#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int N, temp, cnt = 0;
vector <int> v;
int main() {
    v.push_back(INT_MIN);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp > v.back()) {
            v.push_back(temp);
            cnt++;
        }
        else {
            vector<int>::iterator low = lower_bound(v.begin(), v.end(), temp);
            *low = temp;
        }
    }
    cout << cnt;
}
