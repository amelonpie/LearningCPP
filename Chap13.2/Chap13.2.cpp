// Chap13.2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// HasPtr 练习
//

#include <iostream>
#include<string>

class HasPtr {
public:    
    // 默认构造函数，从一个string构造新的对象，如无输入则为空string
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) { std::cout << "Default Constructor" << std::endl; }
    // 拷贝构造函数，拷贝所有成员，以指针的方式
    HasPtr(const HasPtr& p):
        ps(p.ps), i(p.i) { std::cout << "Copy Constructor" << std::endl; }
    ~HasPtr() { std::cout << "Destructor" << std::endl; }
private:
    std::string* ps;
    int i;
};

void exercise_13_5(){
    HasPtr ptr1("What");
    HasPtr ptr2(ptr1);
}

int main()
{
    std::cout << "Hello World!\n";
    //exercise_13_5();
    // Other exercise
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
