#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_size_ok(int size);
template <typename T>
    void display_message(const string&, const vector<T> &);
int main(int argc, char const *argv[])
{
    is_size_ok(1026);
    return 0;
}
bool is_size_ok(int size)
{
    const int max_size = 1024;
    const string msg("Requested size is not supported");
    vector<int> vec = {1,5,8,9,47,31,16,48};
    if (size <= 0 || size > max_size)
    {
        display_message(msg,vec);
        return false;
    }
    else
        return true;
}

template <typename T>
void display_message(const string &msg,
                        const vector<T> &vec)
{
    cout<<msg<<endl;
    for(int ix=0;ix<vec.size();++ix)
    {
        T t = vec[ix];
        cout<<t<<" ";
    }
    cout<<endl;
}
