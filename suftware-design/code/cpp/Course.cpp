#include "../hpp/Course.hpp"
#include <iostream>
using namespace std;

void Course::showcourse(){
    //显示课程信息
    cout << "课程编号:" << bh << ' ';
    cout << "课程名称:" << name << ' ';
    cout << "任课教师:" << teacher << ' ';
    cout << "课程性质:" << catagory << ' ';
    cout << "学分:" << credit << ' ';
    cout << "开课学院:" << college << ' ';
    if(assessment != -1)cout << "课程评价:" << assessment << endl;
    else cout << "该课程还没有评价" << endl;
}