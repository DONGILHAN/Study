#include <iostream>
using namespace std;

int N, K;
int A[11] = {0, };
int answer = 0;
int main() {
    int a;
    cin >> N >> K;
    for(a=1 ; a<=N ; a++)
        cin>>A[a];
    a=N;
    while(K!=0) {
        if(K >= A[a]) {
            answer++;
            K -= A[a];
        }
        else
            a--;
    }
    cout<<answer;
}