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
        cout << "�γ̱��:" << p->getbh() << ' ';
        cout << "�γ�����:" << p->getname() << ' ';
        cout << "�γ�����:" << p->getassessment() << ' ';
        cout << "�γ�ѧ��:" << p->getcredit() << ' ';
        cout << "�Ͽν�ʦ:" << p->getteacher() << ' ';
        cout << "����ѧԺ:" << p->getcollege() << endl;
        p = p->next;
    }
}