#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
// n is num
string decimalToBinary(int n)
{
    if (n == 0)
        return "0";
    string binary = "";
    while (n > 0)
    {
        binary = ((n & 1) == 0 ? "0" : "1") + binary;
        n = n >> 1;
    }
    return binary;
}

// x-bit binary representation of num
void func(int num)
{
    cout << bitset<32>(num);
    cout << bitset<64>(num);
}
