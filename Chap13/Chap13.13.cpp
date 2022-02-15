// Chap13.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 拷贝控制练习, exercise 13.13
//

#include <iostream>
#include <string>

using namespace std;

struct X {
    // 添加copy-assignment operator and desctructor
    // If it is a struct, then all the members are public
    X() { cout << "X()" << endl; }
    X(const string &s, int n) : bookNo(s), units_sold(n) { cout << "X(const string &s, int n)" << endl; }
    // 添加正确的拷贝构造函数
    X(const X& orig) : bookNo(orig.bookNo), units_sold(orig.units_sold) { cout << "X(const X&)" << endl; }
    X& operator=(const X); // 本来是跟着{ cout << "X& operator=(const X&)" << endl; }的，由于显示原因，在结构体外单独指定
    ~X(){ cout << "~X()" << endl; };

    string bookNo ;
    int units_sold = 0;
};
//添加正确的拷贝赋值运算符
X& X::operator=(const X rhs){ 
    cout << "X& operator=(const X&)" << endl;
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    return *this;
}

void exercise_13_13_a() {
    // 将两个添加的函数作为引用参数和非引用参数传递
    // 引用参数：It should print out default constructor and destructor, empty string and undefined integer (if no default value).
    // 非引用参数：也可以正常生成和退出，毕竟根本没有调用拷贝赋值运算符（练习参见c题）
    X x;
    cout << x.bookNo << " " << x.units_sold << endl;
}
void exercise_13_13_b() {
    // 拷贝构造函数
    X x1("qwer", 1); // 调用了构造函数初始值列表
    cout << x1.bookNo << " " << x1.units_sold << endl;

    X x2(x1); // 调用了拷贝构造函数，但由于没有指定如何拷贝，于是是默认值
    cout << x2.bookNo << " " << x2.units_sold << endl;
    // 如果注释了自定义的拷贝构造函数，那么编译器合成的拷贝构造函数将会正确行为
    // 现在将拷贝构造函数正确定义, 将会正确输出
}

void exercise_13_13_c() {
    // 拷贝赋值运算符
    // 引用版本, as expected
    X x1("qwer", 1); // 调用了构造函数初始值列表
    X x2; // 调用了默认构造函数
    cout << x1.bookNo << " " << x1.units_sold << endl;
    cout << x2.bookNo << " " << x2.units_sold << endl;

    x2 = x1; // 调用了拷贝赋值运算符
    cout << x2.bookNo << " " << x2.units_sold << endl;

    // 非引用版本，只删去rhs前的&
    // 当执行x2=x1时，会调用拷贝构造函数和拷贝赋值运算符，然后调用析构函数
    // x2依然会被正确赋值
    // 分析：将一个对象作为实参argument传递给一个非引用类型的形参parameter，会调用拷贝构造函数(书上原话)
    // 然后
}

int main()
{
    std::cout << "Hello World!\n";

    //exercise_13_13_a(); // as expected
    //exercise_13_13_b(); // as expected
    exercise_13_13_c();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
