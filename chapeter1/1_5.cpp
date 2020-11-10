#include <iostream>
#include <string>
using namespace std;
int main(){
    string usr_name="";
    const int min_name_length = 2;
    cout<<"输入名字"<<endl;
    while(usr_name==""){
        cin>>usr_name;
        if(usr_name.size()<min_name_length){
            cout<<"Your name is too short,please use another name."<<endl;
            usr_name = "";
        }
        else{
            cout<<"Your name "<<usr_name<<" is saved"<<endl;
        }
    }
    return 0;
}