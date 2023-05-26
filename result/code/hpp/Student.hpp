#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include "Coulist.hpp"
#include "Chosenlist.hpp"

using namespace std;
class Student{
    public:
        Student* next;
        Student(string numv = "",string pwv = ""):num(numv),pw(pwv){}//构造函数

        bool initchosen(int (&chosenv)[25],int numofchosenv);//初始化已选课程
        void addchosen(const Coulist& coulist);//在已有课程中选课，加入const以防止修改courlist
        bool delchosen();//退出课程功能
        void showchosen(const Coulist& coulist);//查看已选课程编号
        void del_nonecourse(const Coulist& coulist);//删除在coulist已经不存在，但是该学生已经选了的课程

        string getnum()const{return num;}//获取学号
        string getpw()const{return pw;}//获取密码
        Chosenlist getchosenlist()const{return chosenlist;}//获取已选课程链表
    private:
        Chosenlist chosenlist;//已选课程链表
        string num;//学号
        string pw;//密码
};

#endif