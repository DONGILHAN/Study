#include <iostream>
#include <algorithm>
using namespace std;

int house[1001][4] = {0, };
int main() {
    int N;
    int cost[4];
    cin >> N;
    for (int a=1;a<=N;a++) {
        cin >> cost[1] >> cost[2] >> cost[3];
        house[a][1]= min(house[a-1][2], house[a-1][3]) + cost[1];
        house[a][2]= min(house[a-1][1], house[a-1][3]) + cost[2];
        house[a][3]= min(house[a-1][1], house[a-1][2]) + cost[3];
    }
    cout << min(house[N][1], (min(house[N][2], house[N][3])));
}
