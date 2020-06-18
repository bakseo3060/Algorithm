#include <iostream>
#include <queue>
using namespace std;
int main(void) {
    int n, k;
    queue<int> q;
    printf(" sibal");
    scanf("%d %d", &n ,&k);
    for(int i=1; i <=n; i++) {
        q.push(i);
    }
    printf("<");
    while(!q.empty()) {
        for(int i=1; i<k; i++) {
            int val=q.front();
            q.pop();
            q.push(val);
        }
        if(q.size() != 1)
            printf("%d, ",q.front());
        else
            printf("%d",q.front());
        q.pop();
    }
    printf(">");
}