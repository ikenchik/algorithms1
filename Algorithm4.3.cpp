#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
void countChars(string str) {
    unordered_map<char, int> charCount;
    for (char c : str) {
        if (charCount.find(c) == charCount.end()) { 
            charCount[c] = 1;
        }
        else {
            charCount[c]++;
        }
    }
    for (auto p : charCount) {
        cout << p.first << ": " << p.second << endl;
    }
}
int main() {
    string str;
    setlocale(LC_ALL, "rus");
    cout << "Ввод строки: ";
    getline(cin, str);
    countChars(str);
    return 0;
}