#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//초기 입력
int temp, n, c;
vector<int> x;

int checkRouter(vector<int> x, int L, int c) {
    //가장 왼쪽에서부터 공유기를 설치한다.

    int cnt = 1;
    int lastLoc = x[0];
    for (int i = 1; i < n; i++) {
        if (lastLoc + L <= x[i]) {
            lastLoc = x[i];
            cnt++;
        }
    }

    return cnt;
}
int main(void) {
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        x.push_back(temp);
    }
    //오름차순으로 정렬
    sort(x.begin(), x.end());

    int low = 1;
    int high = x[n - 1] - 1;
    int answer = 0;
    while (low <= high) {
        int L = low + (high - low) / 2;
        int numCounter = checkRouter(x, L, c);

        if (numCounter >=
            c) {  //설치된 공유기의 개수가 C보다 많은 경우 간격을 늘려야함.
            answer = L;
            low = L + 1;

        } else {  //설치된 공유기의 개수가 C보다 작은 경우
            //간격을 줄여야함.
            high = L - 1;
        }
    }
    printf("%d", answer);
    return 0;
}