#include <iostream>
using namespace std;
bool fibon_elem(int pos, int &elm)
{
    int num_1 = 1, num_2 = 1;
    elm = num_2;
    if (pos < 1 || pos > 45)
    {
        elm = 0;
        return false;
    }
    else
    {
        for (int ix = 3; ix <= pos; ix++)
        {
            elm = num_1 + num_2;
            num_1 = num_2;
            num_2 = elm;
        }
        return true;
    }
}
bool fibon_seq(int pos)
{
    int elm;
    if (!fibon_elem(pos, elm))
    {
        cout << "position invalid." << endl;
        return false;
    }
    for (int i = 1; i < pos; i++)
    {
        cout << "print fib seq for " << pos << endl;
        for (int i = 1; i <= pos; i++)
        {
            fibon_elem(i, elm);
            cout << elm << (!(i % 10) ? "\n" : " ");
        }
        cout << endl;
        return true;
    }
}
int main()
{
    int elm, pos;
    while (1)
    {
        cout << "Please input position " << endl;
        cin >> pos;
        if (fibon_elem(pos, elm))
        {
            cout << "fib is " << elm << endl;
            fibon_seq(pos);
        }
        else
        {
            cout << "invalid position " << endl;
        }
    }

    return 0;
}