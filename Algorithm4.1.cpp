#include <iostream>
#include <vector>
using namespace std;
int hash_func(int key, int size) {
    return key % size;
}
int main() {
    vector<int> data = { 86, 90, 27, 29, 38, 39, 40 };
    vector<int> hash_table(7, -1);
    for (int num : data) {
        int index = hash_func(num, hash_table.size());
        while (hash_table[index] != -1) {
            index = (index + 1) % hash_table.size();
        }
        hash_table[index] = num;
    }
    for (int num : hash_table) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}