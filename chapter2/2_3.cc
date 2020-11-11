#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void swap(int &a, int &b);
// void bubble_sort(vector<int> &vec, ofstream &ofil);
void bubble_sort(vector<int> &vec, ofstream *ofil=0);

int main(){
    vector<int> vec = {5, 8, 9, 7, 4, 5, 8, 1, 8, 3, 9};
    ofstream of("text_of1.txt");
    // bubble_sort(vec, of);
    //bubble_sort(vec, (&of));
    bubble_sort(vec);
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// void bubble_sort(vector<int> &vec, ofstream &ofil)
// {
//     for (int ix = 0; ix < vec.size(); ix++)
//     {
//         for (int jx = ix + 1; jx < vec.size(); jx++)
//         {
//             if (vec[ix] > vec[jx])
//             {
//                 ofil << "about to call swap! ix: " << ix
//                      << " jx " << jx << " swapping: "
//                      << vec[ix] << " with " << vec[jx] << endl;

//                 swap(vec[ix], vec[jx]);
//             }
//         }
//     }
// }
void bubble_sort(vector<int> &vec, ofstream *ofil)
{
    for (int ix = 0; ix < vec.size(); ix++)
    {
        for (int jx = ix + 1; jx < vec.size(); jx++)
        {
            if (vec[ix] > vec[jx])
            {
                if(ofil!=0){
                    (*ofil) << "about to call swap! ix: " << ix
                        << " jx " << jx << " swapping: "
                        << vec[ix] << " with " << vec[jx] << endl;
                }

                swap(vec[ix], vec[jx]);
            }
        }
    }
}

