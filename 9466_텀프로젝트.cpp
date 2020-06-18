#include <iostream>
#include <vector>
using namespace std;
vector<int> student;
vector<int> visited;
vector<int> saveStartNode;

int dfs(int start, int current, int cnt) {
    // current를 이미 방문했고, dfs시작했을 때의 start값과 current의 시작 값이
    // 같은 경우에 cycle임.
    if (visited[current] != 0) {
        if (saveStartNode[current] != start) {
            return 0;
        }
        return cnt - visited[current];
    }
    saveStartNode[current] = start;
    visited[current] = cnt;
    return dfs(start, student[current], cnt + 1);
}
int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        student = vector<int>(n + 1, 0);
        visited = vector<int>(n + 1, 0);
        saveStartNode = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &student[i]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {  //방문하지 않은 경우
                ans += dfs(i, i, 1);
            }
        }
        printf("%d\n", n - ans);
    }
    return 0;
}