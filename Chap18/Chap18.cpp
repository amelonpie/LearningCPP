#include <iostream>
#include <vector>
using namespace std;
struct Base1 
{
    void print(int) const 
    {
        std::cout << "Base1 Print Used" << std::endl;
    };
protected:
    int ival;
    double dval;
    char cval;
private:
    int* id;
};
struct Base2 
{
    void print(double) const {
        std::cout << "Base2 Print Used" << std::endl;
    };
protected:
    double fval;
private:
    double dval;
};

struct Derived : public Base1 
{
    void print(std::string)
    {
        std::cout << "Derived Print Used" << std::endl;
    };
protected:
    std::string sval;
    double dval;
};

struct MI : public Derived, public Base2 
{

    void print(std::vector<double>) {};
    //解决方案1：定义自己的接受int输入的print（最好）
    //void print(int x) 
    //{
    //    Base1::print(x);
    //}
    // 解决方案2：使用using声明，在使用MI的对象时显式指出是使用间接基类Base1的函数。
    using Base1::print;
protected:
    int* ival;
    std::vector<double> dvec;
    void foo(double);
};

void MI::foo(double cval)
{
    int dval;
    // Exercise 18.27
    //a
    // 除了父类private member外的所有成员，和自身的所有成员1
    //b
    // 那些同名的
    //c
    dval = Base1::dval + Derived::dval;
    //d
    Base2::fval = dvec.back();
    //e
    sval[0] =  Base1::cval;
    // 也可以用front, at(0), 或者迭代器方法*cbegin
}

void main()
{
    MI mi;
    mi.print(42);
    // 解决方案3：加上前缀限定符
    mi.Base1::print(42);
}

/*分析
* Exercise18.26出错的根本原因：在不同的作用域中无法重载函数。
* 如果类MI注释掉line 40，那么出错的原因则为二义性。先查找到Derived(string)，发现无法将int转换为string。继续向上查找，产生了二义性。
* 即：形参列表无论是否相同，多重继承都可能产生二义性。即使只在一个基类中是Public，其他基类是private，也可能出错。
* 最好的解决方案：在Derived中定义自己的新版本。
*/
/*Exercise18.28题点也相似， foo虽然在Derived1和Derived2中形参列表不一样，但由于VMI没有定义自己的foo，故向上搜寻时会出现二义性。
*/