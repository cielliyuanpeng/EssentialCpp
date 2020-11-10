#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    ifstream infile("testtxt.txt");
    vector<string> context;
    if(!infile){
        cout<<"cant open file"<<endl;
    }
    else{
        string temp;
        int idx = 0;
        while(infile >> temp){
            context.push_back(temp);
        }
        // for (int i = 0; i < context.size()&&context[i]!=""; i++)
        // {
        //     cout<<context[i]<<endl;
        // }
        sort(context.begin(),context.end());
        for (int i = 0; i < context.size(); i++)
        {
            cout << context[i] << endl;
        }
    }
}