#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
int main(int argc, char const *argv[])
{
    string user_name;
    int usr_val;
    int true_val;
    int num_tries=1,num_right=0;
    double usr_score = 0.0;
    char usr_choose;
    bool istry = true;
    const int max_tries = 3;
    const double pi = 3.14;
    ifstream infile("seq_data.txt");
    ofstream outfile("seq_data.txt",ios_base::app);
    if(!outfile){
        cerr<<"Unable to save session data";
    }
    else
    {
        outfile<<user_name<<' '<<num_tries<<' '<<num_right<<endl;
    }
    
    cout<<"Try another sequense?Y/N\n";
    cin>>usr_choose;
    if(usr_choose!='Y'&&usr_choose!='y') istry = false;
    if(!istry) cout<<"Your score is "<<usr_score<<"\nbye\t";
    switch (num_tries)
    {
    case 0:case 1:case 2:case 3:
        cout<<"first try ha?\n";
        break;
    
    default:
        cout<<"Nothing is default\n";
        break;
    }
    const int seq_size = 18;
    //int pell_seq[seq_size];
    vector<int> pell_seq(seq_size);
    pell_seq[0]=1;
    pell_seq[1]=2;
    for (int ix = 2; ix < seq_size; ix++)
    {
        pell_seq[ix]=pell_seq[ix-2]+2*pell_seq[ix-1];
    }
    int elem_seq[seq_size]={
        1,2,3, //Fibonacci
        3,4,7, //Lucas
        2,5,12, //Pell
        3,6,10, //Triangular
        4,9,16, //Square
        5,12,22 //Pentagonal
    };
    int *poi = 0;
    double *pd = 0;
    string *ps = 0;
    vector<int> fib,luc,pel,tri,sqr,pen;
    const int seq_cnt = 6;
    vector<int> *seq_addrs[seq_cnt]={
        &fib,&luc,&pel,&tri,&sqr,&pen
    };


    

    bool go_for_it = true;

    cout<<"ok";
    return 0;
}
