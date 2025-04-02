#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1; // 1-alapú indexelés tárolása
    }
    
    sort(a.begin(), a.end()); // Rendezés O(n log n)
    
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = a[left].first + a[right].first;
        if (sum == x) {
            cout << a[left].second << " " << a[right].second << endl;
            return 0;
        } else if (sum < x) {
            left++;
        } else {
            right--;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}