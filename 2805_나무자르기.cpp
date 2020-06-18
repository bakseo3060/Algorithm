#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, m;
    int maxHeight = 0;
    vector<int> trees;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        trees.push_back(temp);
    }

    int low, high;

    low = 0;
    high = *max_element(trees.begin(), trees.end());

    while (low <= high) {
        int h = (low + high) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (trees[i] >= h) sum += (trees[i] - h);
        }
        if (sum < m) {
            high = h - 1;
        } else {
            if (maxHeight < h) {
                maxHeight = h;
            }
            low = h + 1;
        }
    }
    printf("%d", maxHeight);
    return 0;
}