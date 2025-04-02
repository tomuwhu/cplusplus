#include <iostream>
#include <vector>

using namespace std;

struct Point {
    long long x, y;
};

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    long long area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += points[i].x * points[j].y - points[j].x * points[i].y;
    }
    
    cout << abs(area) << "\n";
    return 0;
}
