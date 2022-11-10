#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string>
using namespace std;
template<typename T>
string octal_string(T n)
{
    static_assert(is_integral<T>::value, "Integer required.");
    if (numeric_limits<T>::is_signed && n == numeric_limits<T>::min())
    {
        return "-1" + string(numeric_limits<T>::digits, '0');
    }

    string buffer;
    buffer.reserve(numeric_limits<T>::digits + 1);

    bool negative = (n < 0);
    if (negative)
        n = -n;

    do
    {
        buffer += char('0' + n % 8);
        n = n / 8;
    } while (n > 0);

    if (negative)
        buffer += '-';

    return string(buffer.crbegin(), buffer.crend());
}

template<typename T>
string to_binary_string(T n)
{
    static_assert(is_integral<T>::value, "Integer required.");
    if (numeric_limits<T>::is_signed && n == numeric_limits<T>::min())
    {
        return "-1" + string(numeric_limits<T>::digits, '0');
    }

    string buffer;
    buffer.reserve(numeric_limits<T>::digits + 1);

    bool negative = (n < 0);
    if (negative)
        n = -n;

    do
    {
        buffer += char('0' + n % 2);
        n = n / 2;
    } while (n > 0);

    if (negative)
        buffer += '-';

    return std::string(buffer.crbegin(), buffer.crend());
}


char symbol(int n) {
    char out[] = { '0','1','2','3','4','5','6','7','8','9',
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
    'Q','R','S','T','U','V','W','X','Y','Z' };
    return out[n];
}
void ten_base(int n, int base) {
        if (n < base) {
            cout << symbol(n);
            return;
        }
        ten_base(n / base, base);
        cout << symbol(n % base);
}
int f(int n, int level, int& depth) {
    if ( level > depth ) {
            depth = level;
            cout << "Level =" << level+1 << endl;
            return  (n, level+1, depth);
        
    }
    //if (n > 1) {
        return n;
    //}
}

int main() {
    int depth = 0;
   
    int number;
    int res_sys;
    cout << "Enter number -> ";
    cin >> number;
    cout << "Enter sys -> ";
    cin >> res_sys;
    cout << "Number " << number << " in system " << res_sys << " = ";
    ten_base(number, res_sys);
    cout << endl;
    f(10, 1, depth);
    cout << "Depth = " << depth+1 << endl;
    cout << endl;
    cout << "_________________________" << endl;
    int a;
    cout << "Enter number for binary = "; cin >> a;
    cout <<"|" << "binarty = " << to_binary_string(a) <<"|"<< endl;
    int b;
    cout << "Enter number for octal = "; cin >> b;
    cout << "|" << "eight = " << octal_string(b) <<"|" << endl;
    cout << "_________________________" << endl;

    return 0;
}

