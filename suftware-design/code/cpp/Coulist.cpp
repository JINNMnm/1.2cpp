#include "../hpp/Coulist.hpp"
#include <iostream>
using namespace std;
Coulist::Coulist(){
    head = new Course;
    head->next = NULL;
    size = 0;
}

void Coulist::addcou(int bhv,string namev,int assessmentv,int creditv,string teacherv,string collegev){
    Course *p = new Course(bhv,namev,assessmentv,creditv,teacherv,collegev);
    p->next = head;
    head->next = p;
    size++;
}

void Coulist::showcou(){
    Course* p = head->next;
    while(p != NULL){
        cout << "课程编号:" << p->getbh() << ' ';
        cout << "课程名称:" << p->getname() << ' ';
        cout << "课程评价:" << p->getassessment() << ' ';
        cout << "课程学分:" << p->getcredit() << ' ';
        cout << "认课教师:" << p->getteacher() << ' ';
        cout << "开课学院:" << p->getcollege() << endl;
        p = p->next;
    }
}