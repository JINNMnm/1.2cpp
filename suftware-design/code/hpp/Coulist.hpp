#ifndef COULIST_HPP
#define COULIST_HPP
#include "Course.hpp"
#include "Student.hpp"

class Coulist{
    public:
        Coulist();
        void addcourse(int bhv,string namev,string teacherv,int creditv,string catagoryv,string collegev,int assessmentv);//添加课程
        bool delcourse(int bhv);//按照课程编号删除课程
        bool modifycourse(int bhv);//修改课程
        bool findcourse();//查找课程的大类，具体包括以下四点。如果没有找到就返回false，找到了就返回true
        bool find_and_assesscourse();//查找需要评价的课程，并且给予评价
        Course* findbh(int bhv);//按照编号查找课程
        Course* findname(string namev);//按照名称查找课程
        Course* findteacher(string teacherv);//按照教师查找课程
        Course* findcollege(string collegev);//按照学院查找课程
        void showcourse();//显示课程
    private:
        int size = 0;
        Course *head;
};
#endif