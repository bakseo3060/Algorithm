#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> lans(10000);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, n;
    long long maxK;

    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        cin >> lans[i];
    }

    maxK = *max_element(lans.begin(), lans.end());
    long long low = 1;
    long long high = maxK;
    while (low <= high) {
        long long sum = 0;
        long long maxLen = (low + high) / 2;
        for (int i = 0; i < k; i++) {
            sum += lans[i] / maxLen;
        }

        if (sum < n) {
            high = maxLen - 1;
        } else {
            low = maxLen + 1;
        }
    }
    cout << high << '\n';
    return 0;
}