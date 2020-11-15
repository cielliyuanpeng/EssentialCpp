#include <iostream>
#include <vector>
using namespace std;
inline bool is_size_ok(int size);
inline const vector<int> *fibon_seq(int size);
bool fibon_elem(int pos, int &elem,const vector<int>* (*)(int)=0);

int main()
{
    int size = 5;
    int elem;
    const vector<int> *(*seq_ptr_all[])(int) = {
        fibon_seq
    };
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

const vector<int> *fibon_seq(int size)
{
    static vector<int> elems;
    if (!is_size_ok(size))
    {
        return 0;
    }
    else
    {
        for (int ix = elems.size(); ix < size; ix++)
        {
            if (ix == 0 || ix == 1)
            {
                elems.push_back(1);
            }
            else
                elems.push_back(elems[ix - 1] + elems[ix - 2]); //bug2 忘记加else控制
        }
        return &elems; //bug1 忘记return vector地址,不会报错
    }
}
bool fibon_elem(int pos, int &elem,
                const vector<int>*(*seq_ptr)(int))
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
