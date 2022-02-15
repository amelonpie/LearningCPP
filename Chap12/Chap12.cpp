// Chap12.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>
#include <string>

using namespace std;


void learn_copy_shared_ptr() {
    auto p = make_shared<int>(42);
    cout << *p << endl;

    auto q = p; // q和p指向相同的对象，并且两者地址相同。该对象现在有两个引用者
    cout << "Address of q and p is: " << q << " and " << p << " respectively." << endl;

    auto q1(p); // q和p指向相同的对象，并且两者地址相同。该对象现在有三个引用者
    cout << "Address of q1 and p is: " << q1 << " and " << p << " respectively." << endl;
}

void learn_reset1_shared_ptr() {
    auto p = make_shared<int>(42);
    cout << *p << endl;

    auto q = make_shared<string>(10,'9');
    cout << *q << endl;

    string newVal = "a";
 
    if (p.unique()) { // p is unique
        p.reset(); // 释放p
        cout << "Address of q and p is: " << q << " and " << p << " respectively." << endl;
        cout << "p is destroyed." << endl;
    } 
    
}

void learn_reset2_shared_ptr() {
    auto p = make_shared<int>(42);
    cout << *p << endl;

    auto q(p); // now q and p point to the same object.
    cout << *q << endl;

    string newVal = "a";

    if (!p.unique()) { // p is not unique
        p.reset(); // 释放p
        cout << "Address of q and p is: " << q << " and " << p << " respectively." << endl;
        cout << "p is destroyed, but q still points to that object." << endl;
    }
}

//void learn_reset3_shared_ptr(){
//    auto p = make_shared<int>(42);
//    cout << *p << endl;
//    
//    auto* q = new string(10,'9');
//    cout << *q << endl;
//
//    if (p.unique()) {
//        p.reset(new string(*q));
//        cout << "Address of q and p is: " << q << " and " << p << " respectively." << endl;
//    }
//}

void learn_reset4_shared_ptr() {
    std::shared_ptr<int> sp;  // empty

    sp.reset(new int);       // takes ownership of pointer
    *sp = 10;
    std::cout << *sp << '\n';

    sp.reset(new int);       // deletes managed object, acquires new pointer
    *sp = 20;
    std::cout << *sp << '\n';

    //sp.reset(new double); // 无法从“_Ux *”转换为“std::shared_ptr<int>”
    //sp.reset(new shared_ptr<double>); // 无法转换
    //*sp = 20.2;
    //std::cout << *sp << '\n';

    sp.reset();               // deletes managed object
    std::cout << sp << '\n';



    // “reinterpret_cast”: 无法从“std::shared_ptr<int>”转换为“std::shared_ptr<double>”
    // 转换要求构造函数或用户定义的转换运算符，而该运算符不能由 const_cast 或 reinterpret_cast 使用
    //shared_ptr<double> sp = reinterpret_cast<shared_ptr<double>>(sp);
    //std::cout << *sp << '\n';
}

int main()
{
    std::cout << "Hello World!\n";
    //learn_copy_shared_ptr();
    //learn_reset1_shared_ptr();
    //learn_reset2_shared_ptr();
    //learn_reset3_shared_ptr(); // 完全没看懂这部分在干嘛，为啥会编译失败，来自c++ primer的示例
    learn_reset4_shared_ptr();
    
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
