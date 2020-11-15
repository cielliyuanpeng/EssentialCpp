using namespace std;//bug1:.h文件中也要using namespace
bool seq_elem(int pos,int& elem);
const vector<int> *fibon_seq(int size);
const int seq_cnt = 4;
bool is_size_ok(int size);
inline const vector<int> *fibon_seq(int size)
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
extern const vector<int> *fibon_seq(int size);
const int a = 5;
bool fibon_elem(int pos, int &elem,
                const vector<int> *(*seq_ptr)(int));
extern const vector<int>* (*seq[])(int);