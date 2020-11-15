#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_size_ok(int size);
void display_message(int size, string msg);
void display_message(string msg, int size);//顺序不同
int display_message(string msg);//数量不同
int main(int argc, char const *argv[])
{
    
    return 0;
}
bool is_size_ok(int size){
    const int max_size = 1024;
    const string msg("Requested size is not supported");
    if(size<=0||size>max_size){
        display_message(size,msg);
        return false;
    }
    else return true;
}
void display_message(int size, string msg){

}

int display_message(string msg){

}
