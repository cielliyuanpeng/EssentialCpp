#include <iostream>
#include <vector>
#include "numseq.h"
using namespace std;

int main()
{
    int size = 5;
    cout<<a;
    int elem;
    const vector<int> *(*seq_ptr_all[])(int) = {
        fibon_seq};
    enum ns_type
    {
        ns_fib
    };
    if (fibon_elem(size, elem, seq_ptr_all[ns_fib]))
    {
        cout << "fibon " << size << " is " << elem << endl;
    }
}

bool is_size_ok(int size)
{
    const int max_size = 1024;
    if (size < 0 || size > max_size)
    {
        cerr << "size is valid" << endl;
        return false;
    }
    else
        return true;
}


bool fibon_elem(int pos, int &elem,
                const vector<int> *(*seq_ptr)(int))
{

    if (!seq_ptr)
    {
        elem = 0;
        return false;
    }
    const vector<int> *pseq = seq_ptr(pos);
    if (!pseq)
    {
        elem = 0;
        return false;
    }
    else
    {
        elem = (*pseq)[pos - 1];
        return true;
    }
}
