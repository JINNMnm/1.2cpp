#include "../hpp/Course.hpp"
#include <iostream>
#include <string>
#include <iomanip>  
using namespace std;

string todate(int day){
    //将数字转换为日期
    switch(day){
        case 1:return "星期一";
        case 2:return "星期二";
        case 3:return "星期三";
        case 4:return "星期四";
        case 5:return "星期五";
        case 6:return "星期六";
        case 7:return "星期日";
    }
    return "错误";
}

void Course::showcourse(){
    //显示课程信息,左对齐
    cout << "课程编号:" << setw(2) << setiosflags(ios::left) << bh ;
    cout << "课程名称:" << setw(20) << setiosflags(ios::left) << name ;
    cout << "教师:" << setw(8) << setiosflags(ios::left) << teacher ;
    cout << "学分:" << setw(3) << setiosflags(ios::left) << credit ;
    cout << "上课时间:" << setw(10) << setiosflags(ios::left) << todate(day) << ' ' << "第" << time << "节课  " ;
    cout << "课程类别:" << setw(10) << setiosflags(ios::left) << catagory ;
    cout << "开课学院:" << setw(11) << setiosflags(ios::left) << college ;
    if(assessment != -1)
        cout << "课程评价:" << setw(5) << setiosflags(ios::left) << assessment ;
    else
        cout << "课程评价:" << setw(5) << setiosflags(ios::left) << "无" ;
    cout << endl;
}