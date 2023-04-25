#ifndef COULIST_HPP
#define COULIST_HPP
#include "Course.hpp"
#include "Student.hpp"

class Coulist{
    public:
        Coulist();
        void addcou(int bhv,string namev,int assessmentv,int creditv,string teacherv,string collegev);//添加课程
        void showcou();//显示课程
    private:
        int size = 0;
        Course *head;
};
#endif