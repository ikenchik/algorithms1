/*
#include <iostream>
using namespace std;
int gcdExtended(int a, int b, int* x, int* y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
int main() {
    int a = 28, b = 16, x, y;
    int gcd = gcdExtended(a, b, &x, &y);
    cout << "GCD(" << a << ", " << b << ") = " << gcd << endl;
    cout << "x = " << x << ", y = " << y;
    return 0;
}*/

/*
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
int modulo(int base, int exponent, int mod)
{
    int result = 1;
    base = base % mod;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}
bool isPrime(int n, int k)
{
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;
    while (k > 0)
    {
        int a = 2 + rand() % (n - 4);
        if (gcd(n, a) != 1) return false;
        if (modulo(a, n - 1, n) != 1) return false;
        k--;
    }
    return true;
}
int generatePrime()
{
    int num;
    bool found = false;
    while (!found)
    {
        num = rand() % 100; // генерируем случайное число в диапазоне 0-99
        if (isPrime(num, 5)) // проверяем на простоту пять раз
            found = true;
    }
    return num;
}
int generatePrivateKey(int phi, int publicKey)
{
    int k = 1;
    int privateKey = 0;
    while (true)
    {
        privateKey = (k * phi + 1) / publicKey;
        if (phi % privateKey == 0) // убеждаемся, что найденное число является делителем phi
            break;
        k++;
    }
    return privateKey;
}
int main()
{
    srand(time(NULL));
    // генерируем два простых числа
    int p = generatePrime();
    int q = generatePrime();
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    int n = p * q; // вычисляем n
    int phi = (p - 1) * (q - 1); // вычисляем phi
    cout << "n: " << n << endl;
    cout << "phi: " << phi << endl;
    int publicKey = 0;
    for (int i = 2; i < phi; i++)
    {
        if (gcd(i, phi) == 1) // ищем первое число, которое является взаимно простым с phi
        {
            publicKey = i;
            break;
        }
    }
    cout << "Public key: " << publicKey << endl;
    int privateKey = generatePrivateKey(phi, publicKey); // генерируем закрытый ключ
    cout << "Private key: " << privateKey << endl;
    // шифруем сообщение
    string message = "Ilya Yushkin";
    string encrypted = "";
    for (int i = 0; i < message.length(); i++)
    {
        int c = message[i];
        c = modulo(c, publicKey, n);
        encrypted += char(c);
    }
    cout << "Encrypted message: " << encrypted << endl;
    // расшифруем сообщение
    string decrypted = "";
    for (int i = 0; i < encrypted.length(); i++)
    {
        int c = encrypted[i];
        c = modulo(c, privateKey, n);
        decrypted += char(c);
    }
    cout << "Decrypted message: " << decrypted << endl;
    return 0;
}*/