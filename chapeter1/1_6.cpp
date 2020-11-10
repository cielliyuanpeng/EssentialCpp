#include <iostream>
#include <string>
using namespace std;
int main(){
    
    string input_num="";
    

    while(1){
        int res=0;
        cout<<"please input some number"<<endl;
        cin>>input_num;
        bool charisnum=true;
        for (int i = 0; i < input_num.size(); i++)
        {
            if(!charisnum) break;
            char num = input_num[i];
            switch ( input_num[i] )
            {
            case '0':case '1':case '2':case '3':case '4':
            case '5':case '6':case '7':case '8':case '9':
                res += input_num[i]-'0';
                break;
            
            default:
                cout<<"please input numbers"<<endl;
                charisnum=false;
                break;
            }
            
        }
        cout<<"your input res is "<<res<<endl;
    }

    

}