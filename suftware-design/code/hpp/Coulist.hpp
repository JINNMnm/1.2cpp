#ifndef COULIST_HPP
#define COULIST_HPP
#include "Course.hpp"
#include "Student.hpp"

class Coulist{
    public:
        Coulist();
        void addcourse(int bhv,string namev,string teacherv,int creditv,string catagoryv,string collegev,int assessmentv);//��ӿγ�
        bool delcourse(int bhv);//���տγ̱��ɾ���γ�
        bool modifycourse(int bhv);//�޸Ŀγ�
        bool findcourse();//���ҿγ̵Ĵ��࣬������������ĵ㡣���û���ҵ��ͷ���false���ҵ��˾ͷ���true
        bool find_and_assesscourse();//������Ҫ���۵Ŀγ̣����Ҹ�������
        Course* findbh(int bhv);//���ձ�Ų��ҿγ�
        Course* findname(string namev);//�������Ʋ��ҿγ�
        Course* findteacher(string teacherv);//���ս�ʦ���ҿγ�
        Course* findcollege(string collegev);//����ѧԺ���ҿγ�
        void showcourse();//��ʾ�γ�
    private:
        int size = 0;
        Course *head;
};
#endif