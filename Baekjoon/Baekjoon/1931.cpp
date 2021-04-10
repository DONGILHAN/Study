#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;
int N;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
    int l, r;
    int answer = 1;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> l >> r;
        v.push_back(make_pair(l, r));
    }
    sort(v.begin(), v.end(), comp);

    int start = 0, end = 1;
    while (end < N) {
        if (v[end].first >= v[start].second) {
            answer++;
            start = end;
        }
        end++;
    }
    cout << answer;
}