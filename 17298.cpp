#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    /*
    방법 1
    수열을 탐색하면서 i 번째 위치일 때 i+1 과 비교.
    i+1 이 큰 경우 오큰수에 해당하므로 nge[i]에 해당 값을 넣는다.
    i+1 이 작은 경우 오큰수가 아니므로 인덱스인 i를 stack에 push
    매번 stack의 top을 idx로 두고 a[idx]와 a[i]를 비교하여 a[i]가 더 큰 경우
    nge[idx] = a[k] stack pop하고
    a[i]가 더 작은 경우 탐색 계속 진행
    */
    int n, x;
    int i=0;
    stack<int> not_found;

    scanf("%d",&n);
    int a[1000001];
    int nge[1000001];

    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i=0; i<n; i++) {
        while(not_found.empty() == false) {
            int idx = not_found.top();
            if(a[idx] < a[i]) {
                nge[idx] = a[i];
                not_found.pop();
            }else {
                break;
            }
        }           
        if(i != n-1) {
            if(a[i] <a[i+1]) {
                nge[i] = a[i+1];
            } else {
                not_found.push(i);
            }
        }
        
    } 
     // 마지막은 무조건 -1이므로.
    for(int i=0; i<n; i++) {
        if(nge[i] == 0) {
            nge[i] = -1;
        }
    }
    for(int i=0; i<n; i++) {
        printf("%d",nge[i]);
        if(i != n-1) 
            printf(" ");
    }
}