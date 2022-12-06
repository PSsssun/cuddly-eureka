#include "test2.h"
const double data::data1 = 2;
// ⬆️ 不能添加 static 关键字
// static的用法有好几种，在类中成员函数的声明使用static关键字则是规定说该成员函数为该类所有实例所共享
// 也就是所谓的"one-per-class"，
// 而在.cpp文件中使用static关键字的作用也是说该函数或变量仅仅只有该文件可以访问，这就与第一个用法冲突了

int main(){
    hey();
}