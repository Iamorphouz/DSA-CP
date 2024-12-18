#include <iostream>
using namespace std;
void print1(int n)
{
    // ****
    // ****
    // ****
    // ****
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
};
void print2(int n)
{
    // *
    // **
    // ***
    // ****
    // *****
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
};
void print3(int n)
{
    // 1
    // 12
    // 123
    // 1234
    // 12345
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
};
void print4(int n)
{
    // 1
    // 22
    // 333
    // 4444
    // 55555
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
};
void print5(int n)
{
    // *****
    // ****
    // ***
    // **
    // *
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
};
void print6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j;
        }
        cout << endl;
    }
};
void print7(int n)
{
    //     *
    //    ***
    //   *****
    //  *******
    // *********
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
};
void print8(int n)
{
    //  *********
    //   *******
    //    *****
    //     ***
    //      *
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= 2 * n - (2 * i - 1); j++)
        {
            cout << "*";
        }
        // space
        for (int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
};
void print9(int n)
{
    //     *
    //    ***
    //   *****
    //  *******
    // *********
    // *********
    //  *******
    //   *****
    //    ***
    //     *

    // upper
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    // lower
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= 2 * n - (2 * i - 1); j++)
        {
            cout << "*";
        }
        // space
        for (int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
};
void print10(int n)
{
    // *
    // **
    // ***
    // ****
    // *****
    // ****
    // ***
    // **
    // *
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = 0;
        if (i <= n)
            stars = i;
        else
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
};
void print11(int n)
{
    // 1
    // 01
    // 101
    // 0101
    // 10101
    for (int i = 1; i <= n; i++)
    {
        int one = 0;
        if (i & 1)
            one = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << one;
            one = 1 - one;
        }
        cout << endl;
    }
};
void print12(int n)
{
    // 1        1
    // 12      21
    // 123    321
    // 1234  4321
    // 1234554321
    int space = 2 * n - 2;
    for (int i = 1; i <= n; i++)
    {
        // num
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        // space
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        // num
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        space -= 2;
        cout << endl;
    }
};
void print13(int n)
{
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // 11 12 13 14 15
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num++ << " ";
        }
        cout << endl;
    }
};
void print14(int n)
{
    // A
    // AB
    // ABC
    // ABCD
    // ABCDE
    for (int i = 1; i <= n; i++)
    {
        for (char j = 'A'; j <= 'A' + i - 1; j++)
        {
            cout << j;
        }
        cout << endl;
    }
};
void print15(int n)
{
    // ABCDE
    // ABCD
    // ABC
    // AB
    // A
    for (int i = 1; i <= n; i++)
    {
        for (char j = 'A'; j <= 'A' + (n - i); j++)
        {
            cout << j;
        }
        cout << endl;
    }
};
void print16(int n)
{
    // A
    // BB
    // CCC
    // DDDD
    // EEEEE
    for (int i = 1; i <= n; i++)
    {
        char ch = ('A' + i - 1);
        for (int j = 1; j <= i; j++)
        {
            cout << ch;
        }
        cout << endl;
    }
}
void print17(int n)
{
    //     A
    //    ABA
    //   ABCBA
    //  ABCDCBA
    // ABCDEDCBA
    int space = n - 1;
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        // char
        char ch = 'A';
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << ch;
            if (j < i)
                ch++;
            else
                ch--;
        }
        // space
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        space--;
        cout << endl;
    }
}
void print18(int n)
{
    // E
    // DE
    // CDE
    // BCDE
    // ABCDE
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A' + n - i;

        for (int j = 1; j <= i; j++)
        {
            cout << ch;
            ch += 1;
        }
        cout << endl;
    }
}
void print21(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || j == 1 || i == n || j == n)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}
void print19(int n)
{
}
void print20(int n)
{
}
void print22(int n)
{
}
int main()
{
    int n = 5;
    // cin >> n;

    print21(n);

    return 0;
}