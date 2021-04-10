#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt, N, M, tmp, answer;
vector<int> v;
vector<int> important;
int main() {
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        v.clear();
        important.clear();
        answer = 0;
        cin >> N >> M;
        for (int j = 0; j < N; j++) {
            cin >> tmp;
            v.push_back(tmp);
            if (j == M)
                important.push_back(1);
            else
                important.push_back(0);
        }
        while (true) {
            int max = *max_element(v.begin(), v.end());
            if (v[0] == max) {
                answer++;
                if (important[0] == 1)
                    break;
                else {
                    v.erase(v.begin());
                    important.erase(important.begin());
                }
            } else {
                tmp = v[0];
                v.erase(v.begin());
                v.push_back(tmp);
                tmp = important[0];
                important.erase(important.begin());
                important.push_back(tmp);
            }
        }
        cout << answer << "\n";
    }
}