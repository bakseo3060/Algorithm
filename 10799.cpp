#include <iostream>
using namespace std;
int main()
{
    int n;
    int ans = 0;
    scanf("%d", &n);

    for (int i = 5; i <= n; i *= 5)
        ans += n / i;
    printf("%d\n", ans);
    return 0;
}