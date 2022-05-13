// Chap15.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()  
{
    std::cout << "Hello World!\n";
}



/*
关于exercise 15.4 (b)选项网络上部分答案有冲突，且大家没有解析之我的解析
https://github.com/huangmingchuan/Cpp_Primer_Answers/issues/89
正确。如果只是看P532“派生类的声明”这一节，会认为b是错误的“这是定义而不是声明”。而实际上，只要写在头文件.hpp里的都是声明，只不过声明分为了有定义的声明（比如该选项class Derived : private Base { ... // 这里面是Derived类的接口的声明} ;）和没有定义的声明（比如p532的最后一行代码和p533的第一行代码class Bulk_quote;）。up主可能是弄混了“实现”和“定义”的区别。实现是在.cpp资源文件里，而声明一个类（无论是否定义了其成员）是在.hpp头文件里。
*/