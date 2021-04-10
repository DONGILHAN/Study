#include <iostream>
using namespace std;

char need[52];
int num[52]={0, };
int now=0;

int main() {
    int i = 0;
    int answer = 0;
    gets(need);

    while (need[i] != '-') {
        if (need[i] == '+') {
            now++;
        } else {
            num[now] = (num[now] * 10) + (int(need[i]) - 48);
        }
        i++;
        if (need[i] == '\0')
            break;
    }
    i++;
    while (now >= 0) {
        answer += num[now];
        now--;
    }
    now = 0;
    num[now] = 0;
    while (true) {
        if ((need[i] == '+') || (need[i] == '-')) {
            answer -= num[now];
            num[now]=0;
        } else {
            if (need[i] == '\0') {
                answer -= num[now];
                break;
            }
            num[now] = (num[now] * 10) + (int(need[i]) - 48);
        }
        i++;
    }
    cout << answer;

}