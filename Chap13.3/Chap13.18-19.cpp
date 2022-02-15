// Chap13.3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// Exercise 13.18-13.19
//

#include <iostream>
#include <string>
#include <format>

class Employee {
public:
    //默认构造函数
    Employee (const std::string& name):
        name_(name), id_(total_id_++) { std::cout << "Default Constructor" << std::endl; }
    // 阻止赋值
    Employee& operator=(const Employee&) = delete;
    // 阻止拷贝构造
    Employee (const Employee&) = delete;
    const int id() { return id_; }
    const std::string name() { return name_; }
private:
    std::string name_;
    int id_;
    static int total_id_;
};
// 类的静态成员被所有对象共享。不建议类内初始化，否则需要加inline
int Employee::total_id_ = 0;

int main()
{
    std::cout << "Hello World!\n";
    Employee person1("Tom");
    std::cout << std::format("Name: {} id: {}", person1.name(), person1.id()) << std::endl;
    Employee person2("Jerry");
    std::cout << std::format("Name: {} id: {}", person2.name(), person2.id()) << std::endl;
    //person2 = person1; //报错：“Employee &Employee::operator =(const Employee &)”: 尝试引用已删除的函数，已隐式删除函数
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
