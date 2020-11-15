#include <iostream>
#include <vector>
using namespace std;
inline bool is_size_ok(int size);
inline const vector<int> *fibon_seq(int size);
bool fibon_elem(int pos, int &elem);

int main(){
    int size = 5;
    int elem;
    if(fibon_elem(size,elem)){
        cout<<"fibon "<<size<<" is "<<elem<<endl;
    }

}

bool is_size_ok(int size){
    const int max_size = 1024;
    if(size<0||size>max_size){
        cerr<<"size is valid"<<endl;
        return false;
    }
    else return true;
}

const vector<int>* fibon_seq(int size){
    static vector<int> elems;
    if(!is_size_ok(size)){
        return 0;
    }
    else{
        for(int ix = elems.size();ix<size;ix++){
            if(ix == 0||ix == 1){
                elems.push_back(1);
            }
            else elems.push_back(elems[ix-1]+elems[ix-2]);//bug2 忘记加else控制
        }
        return &elems;//bug1 忘记return vector地址,不会报错
    }
    
}
bool fibon_elem(int pos, int &elem){
    const vector<int> *pseq = fibon_seq(pos);
    if(!pseq){
        elem = 0;
        return false;
    } 
    else{
        elem = (*pseq)[pos-1];
        return true;
    }

}
