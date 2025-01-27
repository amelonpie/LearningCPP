﻿// Chap10.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void page341()
{
    // p.341
    int a1[] = { 0,1,2,3,4,5,6,7,8,9 };
    printf("sizeof(a1):%d, sizeof(*a1):%d\n", sizeof(a1), sizeof(*a1));
    /*
        it print 40, 4. It is because:
        sizeof(pointer) is the size that the pointer points to. Here is an int array with 10 element, each element 4 bytes, so 40 bytes
        sizeof(*pointer) is the size that the type the pointer points to. Here is int, 4 byte
    */
    // To create a new array that has the same size of a1
    int a2[sizeof(a1) / sizeof(*a1)];
    auto ret = copy(begin(a1), end(a1), a2);
    for (const auto& value : a2) 
    {
        std::cout << value << ' ';
    }
}

bool isShorter(const string & s1, const string & s2)
{
    return s1.size() < s2.size();
}

void elimDups(vector<string>& words)
{
    sort(words.begin(), words.end()); // 为什么首先要按字典序排序使相邻单词重复出现：因为std::unique只能把相邻的重复单词往后移动，不是全局的unique
    // Eliminates all except the first element from every consecutive group of equivalent elements from the range [first, last) and returns a past-the-end iterator for the new logical end of the range.
    auto end_unique = unique(words.begin(), words.end());
    if (end_unique == words.end())
    {
        cerr << "no duplicated words in vector" << endl;
    }
    else
    {
        words.erase(end_unique, words.end());
    }
}

template <typename T>
void print_vector(vector<T>& words)
{
    for (const auto& word : words)
    {
        cout << word << ' ';
    }
    cout << endl;
}

 void exercise10_11()
 {
     vector<string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
     cout << "Before: ";
     print_vector(vec);
     elimDups(vec);
     stable_sort(vec.begin(),vec.end(),isShorter); // isShorter叫做comparison function object which returns ​true if the first argument is less than (i.e. is ordered before) the second. 就是用来自定义排序的定义的
     cout << "After: ";
     print_vector(vec);
 }

 void page353()
 {
     int i = 1;
     auto bbb = [](int i) {
         if (i > 0) {
             return i;
         }
         return -i;

     };

     std::vector<int> vi = { -1, 0, 3, 5, -3 };
     print_vector(vi);
     //std::transform(vi.begin(), vi.end(), vi.begin(), bbb); // the same as below but better accords to the original text
     std::transform(vi.begin(), vi.end(), vi.begin(), [](int i) {
         if (i > 0) {
             return i;
         }
         return -i;
         });
     print_vector(vi);
 }

 void exercise10_13() 
 {
     return;
 }

int main()
{
    std::cout << "Hello World!\n";
    //page341();
    //exercise10_11();
    //page353();
    //exercise10_13();
    //exercise10_16();
    //exercise10_19();
    /* lambda
    * 我对lambda捕获列表的理解：lambda相当于一个类，lambda函数就是一个lambda对象。对于局部(当前函数所在的scope)non-static变量不能直接访问，需要通过捕获列表[]将其放进lambda类中，成为this->var （实际使用上没这么复杂，只用于理解捕获列表），不然就不能访问
    * lambda的形参列表就是普通类内member method的形参列表。这个理解是正确的，因为chap10.3.3就这么说了。。。
    */
    
    
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
