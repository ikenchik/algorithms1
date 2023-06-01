#include <iostream>
#include <string>
using namespace std;
string encrypt(string text) {
    string key = "юукенгшщзхъфавыпролджэячсмитьбц";
    string encrypted = "";
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            encrypted += ' ';
        }
        else {
            int index = text[i] - 'а';
            encrypted += key[index];
        }
    }
    return encrypted;
}
int main() {
    setlocale(LC_ALL, "Russian");
    string text = "люблю животных";
    string encrypted = encrypt(text);
    cout << "Исходный текст: " << text << endl;
    cout << "Зашифрованный текст: " << encrypted << endl;
    return 0;
}