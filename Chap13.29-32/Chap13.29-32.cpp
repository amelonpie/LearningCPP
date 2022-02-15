// Chap13.29-32.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 行为像值的类
//
/*
Exercise 13.29
HasPtr有自己定义的swap(HasPtr&, HasPtr&)函数，function body调用了swap(string*, string*)和swap(int, int)，
而后两者并未被自定义类定义，所以会调用std::swap(因为声明了using std::swap)去匹配模板，
故不会导致递归循环

Exercise 13.32
不会。之所以定义HasPtr类值版本的swap成员函数，就是为了避免在交换数值时进行拷贝操作，而只是交换指针
指向。对于类指针版本，已经是交换指针了。
*/

#include <iostream>
#include <string>
#include <format>

class HasPtr {
public:
    HasPtr(const std::string& str, int num) : ps_(new std::string(str)), i_(num) { std::cout << "Default Constructor" << std::endl; }
    ~HasPtr() { delete ps_; std::cout << "Destructor " << std::endl; } // Is there any way to print out the object name, e.g., item1?
    std::string* ps() { return ps_; }
    int i() { return i_; }
    friend void swap(HasPtr&, HasPtr&);
private:
    std::string* ps_;
    int i_;
};
inline
void swap(HasPtr& lhs, HasPtr& rhs) {
    using std::swap;
    swap(lhs.ps_, rhs.ps_);
    swap(lhs.i_, rhs.i_);
}

int main()
{
    std::cout << "Hello World!\n";
    HasPtr item1("Dream", 1);
    HasPtr item2("What", 2);
    std::cout << std::format("item1 {}, {}\nitem2 {}, {}", *item1.ps(), item1.i(), *item2.ps(), item2.i()) << std::endl;
    
    swap(item1, item2);
    std::cout << std::format("item1 {}, {}\nitem2 {}, {}", *item1.ps(), item1.i(), *item2.ps(), item2.i()) << std::endl;
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
