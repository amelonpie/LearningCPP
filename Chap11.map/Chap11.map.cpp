// Chap11.map.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// All the exercises related to map container
//

#include <iostream>
#include <map>
#include <string>
#include <format>
#include <set>
#include <cctype>
#include <algorithm>

using namespace std;

void e_11_1() {
    // understand the use of map
    map<string, size_t> person_age = { {"Tom",1},
        {"Jerry",2}};
    cout << person_age["tom"] << endl;
    // If a key is undefined, then the corresponding value will be the default according to the value type.
    // For example, size_t uninitialized is 0
}

void e_11_3() {
    map<string, size_t> word_count; // empty counter
    string word; // input 
    cout << "Input your text, separated by space, no punctuation, end by enter, and start calculation by ctrl+z following a enter:" << endl;
    while (cin >> word) { // std::cin 用键盘输入默认以空白符为分割符的输入(也可以理解为空白符输入不进去)
        ++word_count[word]; // use the input word as the key, and pre-increase the corresponding pair
        //word_count[word] += 1;
    } // equivalent to word_count[word] += 1;
    for (const auto& elem : word_count) {
        cout << format("Word \"{}\" occurs {} {}.", elem.first, elem.second, (elem.second>1)? "times":"time") << endl;
    }
    // 在C++ STL 中map 采用红黑树实现，可以实现有序的Map.
}

string str_tolower(string s) {
    transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return tolower(c); });
    return s;
}

void e_11_4() {
    // Similar to e_11_3, but tolower the word and punctuation.
    map<string, size_t> word_count; 
    string word;
    cout << "Input your text, separated by punctuation, end by enter, and start calculation by ctrl+z following a enter:" << endl;
    while (cin >> word) {
        // convert to lowercase string
        auto lword = str_tolower(word); //tolower() is for unsigned char.
        // ignore the punctuation
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        ++word_count[lword];
       
    }
    for (const auto& elem : word_count) {
            cout << format("Word \"{}\" occurs {} {}.", elem.first, elem.second, (elem.second > 1) ? "times" : "time") << endl;
    }
    
}

int main()
{
    std::cout << "Hello World!\n";
    //e_11_1();
    //e_11_3();
    e_11_4();


    return 0;
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
