//以传引用和传指针的方式实现bubble sort和display
#include <iostream>
#include <vector>

using namespace std;
void bubble_sort_by_reference(vector<int> &vec)
{
    for (int ix = 0; ix < vec.size(); ix++)
    {
        for (int iy = ix+1; iy < vec.size(); iy++)
        {
            if(vec[iy]<vec[ix]) swap(vec[iy],vec[ix]);
        }
    }
}
void display_by_pointer(const vector<int> *vec)
{
    if(!vec)
    {
        cout<<"null pointer"<<endl;
        return;
    } 
    for(int i=0;i<vec->size();i++)
    {
        cout<<(*vec)[i]<<" "<<(((i+1)%4)?"":"\n");
    }
    cout<<endl;
}
void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    vector<int> vec = {5,8,9,7,4,5,8,1,8,3,9};
    bubble_sort_by_reference(vec);
    display_by_pointer(&vec);
}