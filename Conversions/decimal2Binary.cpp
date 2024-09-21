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
