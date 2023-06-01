#include <iostream>
#include <string>
using namespace std;
int main()
{
    string text;
    int key;
    setlocale(LC_ALL, "rus");
    cout << "Введите текст для шифрования: ";
    getline(cin, text);
    cout << "Введите ключ шифрования: ";
    cin >> key;
    for (int i = 0; i < text.length(); i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            c = tolower(c);
            c = 'a' + (c - 'a' + key) % 26;
            if (text[i] >= 'A' && text[i] <= 'Z')
            {
                c = toupper(c);
            }
        }
        text[i] = c;
    }
    cout << "Зашифрованный текст: " << text << endl;
    return 0;
}