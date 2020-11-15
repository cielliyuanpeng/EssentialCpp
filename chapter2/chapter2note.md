# Note for chapter2

## 2.1 如何编写函数

- 在main前声明函数;
- 声明函数的参数类型要和实现函数的参数类型一致
- 函数名称要具体,
- 注意返回类型和声明返回类型相同.
- 在出现错误时,极端的办法是exit(-1),普遍的做法是返回一个特定的值(exception)
- 对于超出范围(包括其他可运行但由于编译原因会出现运行结果不符合预期)的异常,我们手动给函数画上一个范围.v
- [ ] 第七章会讨论exception

## 2.2 调用函数

- 传参
    两种传递参数的方式: 传值 \ 传址
    其中,传址方式有传引用和传指针两种实现方式

    | | 引用 | 指针
    ----- | ---- | -----
    写法 | ```int &a``` | ```int *a```
    确定指向是否为空 | 不需要 | 需要 |

    为了速度更快,避免复制多余数据到函数中,声明形式参数时使用const关键字,表示对传入变量无修改

    ```c
    int fun(const vector<int>v)
    ```



- 作用域

  作用域 | 初始化 | 生命周期 |
  ---|---|---
  local scope| 指定初值时 | 函数内
  file scope | 定义时初始化为0 | 整个文件
  dynamic extent | 单值可以初始化,数组不行 | 从new到delete

  ```c++
  int *pia = new int[24];
  delete [] pia;
  //中间的[]代表删除所有对象;
  //内存泄漏:new的对象没被delete;
  ```

## 2.3默认参数

- 默认值从右到左声明,有默认值的靠右,没默认值的靠左;
- 可以在声明或者实现中声明默认参数,但不能俩都声明,一般放在头文件的声明处;
  
## 2.4使用局部静态对象

需求背景:调用fibonacci数列时每次计算浪费时间,file scope可能会打乱各个函数间的独立性,比较冒险

- 初始化局部静态对象的函数可以返回(const?非const?)局部静态对象的指针
  
```cpp
  for(int ix= elems.size();ix<pos;++ix)
```

  其中,elems.size()在算一个更大的值的时候会增长,在找更小的值的时候避免重算

## 2.5 声明inline函数

需求背景:在函数深度比较大(A调用B,B调用C,C调用D......)的时候可能会影响运行速度,这时,我们在函数声明位置加入inline关键字

```cpp
  inline bool is_size_ok(int size);
  inline const vector<int> *fibon_seq(int size);
```

请求编译器在每个调用节点上将函数内容展开,相当于把三个函数写到原来函数里面,提高性能.

- 常被inline的函数一般具有体积小,计算简单,调用频繁的特点

## 2.6提供重载函数

需求背景:需要一组功能类似的函数,传入不同参数的情况下皆可用,同时不希望定义多个函数名,希望用一个函数名,在输入参数不同的情况下实现不同的功能.

## 2.7定义并使用模板函数

需求背景:相同的函数内容针对不同的vector type
定义函数时使用关键字```template<typename T>```
example:

```cpp
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
```

## 2.8函数指针

需求背景:有很多函数具有相同返回类型和调用参数的函数,表达的意义也相近(返回Fibonacci seq,lucas seq,square seq .....)
在调用这些函数时,可以通过指向这些函数的指针作为变量进行访问,增加程序复用性.
例如

```cpp
//声明一个名为seq的函数指针,
//指向的函数返回类型是const vector<int>*,参数是int类型
const vector<int>* (*seq)(int)
```

返回类型 (*变量名) (参数类型)

- 函数指针数组

```cpp
    const vector<int> *(*seq_ptr_all[])(int) = {
        fibon_seq
    };
```

- 枚举类型辅助记忆

```cpp
    enum ns_type
    {
        ns_fib
    };
```

- 调用

```cpp
  seq_ptr_all[ns_fib]
```

## 2.9设定头文件

需求背景:使用某一函数前需要对其声明,当多个文件都要使用一个函数的时候,可以只在头文件中声明一次,在其他文件中调用即可

- 参数和返回类型需要改变时改变声明即可
- inline函数要定义在头文件中
- 非const的全局变量,要声明extern关键字
- const变量出文件即不可见,所以可以多次定义
- 用户自定义的头文件引用时用"",stl的用<>