// Chap13.28.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// exercise 13.28 和exericise 13.27 一个意思，定义使用引用计数的类，行为像shared_ptr。
// 不用被名字TreeNode迷惑，该题和树没有关系，就是练习拷贝控制
//

#include <iostream>
#include <string>
#include <format>

class TreeNode {
public:
    // 默认构造函数
    TreeNode(const std::string&s = std::string()) : 
        value(s), count(new int(1)), left(nullptr), right(nullptr) { std::cout << "Default Constructor" << std::endl; }
    // 拷贝控制成员：拷贝构造函数，拷贝赋值操作
    TreeNode(const TreeNode& rhs):
        value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) {
        ++*count;
        std::cout << std::format("Copy Constructor, lhs count: {}, rhs count: {}", *count, *rhs.count) << std::endl;
    }
    TreeNode& operator=(const TreeNode& rhs);
    ~TreeNode(){};

private:
    std::string value;
    int *count; //原书写的是int count，那么默认构造应该用count(0)
    TreeNode* left;
    TreeNode* right;
};

TreeNode& TreeNode::operator=(const TreeNode& rhs) {
    std::cout << std::format("Copy-assignment operator, lhs count: {}, rhs count: {}", *count, *rhs.count) << std::endl;
    ++ * rhs.count;
    if (-- * count == 0) {
        if (left) {
            delete left;
            left = nullptr;
        }
        if (right) {
            delete right;
            right = nullptr;
        }
        delete count;
        count = nullptr;
    }
    value = rhs.value;
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
    return *this;
}

TreeNode::~TreeNode() {
    if (-- * count == 0) {
        if (left) {
            delete left;
            left = nullptr;
        }
        if (right) {
            delete right;
            right = nullptr;
        }
        delete count;
        count = nullptr;
        // value是int类型，int是内置类型，内置类型会自动销毁。
    }
}

class BinStrTree {
public:
    // 默认构造函数
     BinStrTree() : root(new TreeNode()) {}
    // 拷贝构造函数
     BinStrTree(const BinStrTree& bst) : root()为什么是bst，需要了解树是什么才能继续写下去，这道题hold on;
    // 拷贝赋值操作符
    // 析构函数
private:
    TreeNode* root;
};

int main()
{
    std::cout << "Hello World!\n";
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
