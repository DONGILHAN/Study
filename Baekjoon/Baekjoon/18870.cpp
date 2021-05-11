#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, temp;
vector<int> X, V;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        X.push_back(temp);
        V.push_back(temp);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    for (int i = 0; i < N; i++) {
        cout << lower_bound(V.begin(), V.end(), X[i]) - V.begin() << " ";
    }
}