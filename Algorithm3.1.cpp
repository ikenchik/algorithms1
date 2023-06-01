#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr = { 4, 2, 7, 5, 1, 6, 3 };
    make_heap(arr.begin(), arr.end(), greater<int>());
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}