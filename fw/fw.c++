#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkParameters(int numberOfChildren, int totalWeight, vector<int>& arrWeightOfChildren) {
    if (numberOfChildren < 1 || numberOfChildren > 200000) return false;
    if (totalWeight < 1 || totalWeight > 1000000000) return false;
    if (arrWeightOfChildren.size() != numberOfChildren) return false;
    for (int weight : arrWeightOfChildren) {
        if (weight < 1 || weight > 1000000000) return false;
    }
    return true;
}

int Calculate(vector<int>& arrWeightOfChildren, int totalWeight) {
    int nCounter = 0;
    sort(arrWeightOfChildren.begin(), arrWeightOfChildren.end());
    
    int left = 0, right = arrWeightOfChildren.size() - 1;
    while (left <= right) {
        if (arrWeightOfChildren[left] + arrWeightOfChildren[right] <= totalWeight) {
            left++;
        }
        right--;
        nCounter++;
    }
    return nCounter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int p1, p2;
    cin >> p1 >> p2;
    vector<int> arrWeightOfChildren(p1);
    for (int i = 0; i < p1; ++i) {
        cin >> arrWeightOfChildren[i];
    }
    if (checkParameters(p1, p2, arrWeightOfChildren)) {
        cout << Calculate(arrWeightOfChildren, p2) << endl;
    } else {
        cout << "Invalid parameters" << endl;
    }
    return 0;
}