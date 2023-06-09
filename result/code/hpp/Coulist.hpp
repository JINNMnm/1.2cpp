#ifndef COULIST_HPP
#define COULIST_HPP
#include "Course.hpp"
class Coulist{
    public:
        Coulist();//构造函数
        bool addcourse(int bhv,string namev,string teacherv,int creditv,string catagoryv,string collegev,int assessmentv,int dayv,int timev);//添加课程
        bool delcourse(int bhv);//按照课程编号删除课程
        bool modifycourse(int bhv);//修改课程
        bool checkif_teacher_have_time(int dayv,int timev,string teacherv);//检查教师是否有空
        bool checkif_teacher_have_time(int dayv,int timev,string teacherv,int except_bh);//检查教师除了编号为except_bh的课程之外是否有空
        
        bool find_and_assesscourse();//查找需要评价的课程，并且给予评价
        bool sortcourse();//总排序，具体分为以下两部分
        void sort_credit();//按照学分排序
        void sort_college();//按照学院排序
        
        bool findcourse();//查找课程的大类，具体包括以下四点。如果没有找到就返回false，找到了就返回true
        Course* findbh(int bhv)const;//按照编号查找课程
        bool findname(string namev)const;//按照名称查找课程
        bool findteacher(string teacherv)const;//按照教师查找课程
        bool findcollege(string collegev)const;//按照学院查找课程

        void write();//写入文件
        void showcourse();//显示课程
        int getsize()const{return size;};//获得总课程数
        void swapcourse(Course*p,Course*q);//交换课程

    private:
        int size = 0;
        Course *head;
};
#endif