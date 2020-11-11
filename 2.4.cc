#include <iostream>
#include <vector>
using namespace std;
bool fibon_elem(int pos, int &elm);
const vector<int>* fibon_seq(int pos);

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
const vector<int> *fibon_seq(int pos)
{
    const int max_size = 50;
    static vector<int> elems;
    if(pos<=0||pos>max_size){
        cerr<<"invalid size"<<endl;
        return 0;
    }
    for(int ix= elems.size();ix<pos;++ix){
        if(ix == 0||ix == 1){
            elems.push_back(1);
        }
        else elems.push_back(elems[ix-1]+elems[ix-2]);
    }

    return &elems;
}
