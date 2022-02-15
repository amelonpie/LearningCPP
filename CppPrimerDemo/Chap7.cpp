// CppPrimerDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

class Account {
public:
    static double rate() { return interestRate; } // To show the current rate
    static void rate(double); // To set a new rate
    double getMyRate() { return myRate; }
    void setMyRate(double);
private:
    static double interestRate;
    static double initRate();
    double myRate;
};
void Account::rate(double newRate) {
    interestRate = newRate;
}
void Account::setMyRate(double flow){
    myRate = interestRate + flow;
}
double Account::interestRate = initRate();
double Account::initRate() {
    return 0.25;
};

int main()
{
    Account ac1, ac2;
    std::cout << "The interest rate of ac2 is currently : " << ac2.rate() << std::endl;
    Account::rate(0.32);
    std::cout << "The interest rate of ac1 and ac2 is currently : " << ac1.rate() << " " << ac2.rate() << std::endl;
    ac2.rate(0.35);
    std::cout << "The interest rate of ac1 and ac2 is currently : " << ac1.rate() << " " << ac2.rate() << std::endl;
    ac2.setMyRate(0.5);
    std::cout << "The interest rate of ac1 is currently : " << ac1.rate() << " " << ac2.getMyRate() << std::endl;
    // getchar();
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
