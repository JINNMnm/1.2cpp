#ifndef COULIST_HPP
#define COULIST_HPP
#include "Course.hpp"
#include "Student.hpp"

class Coulist{
    public:
        Coulist();
        void addcou(int bhv,string namev,int assessmentv,int creditv,string teacherv,string collegev);//��ӿγ�
        void showcou();//��ʾ�γ�
    private:
        int size = 0;
        Course *head;
};
#endif