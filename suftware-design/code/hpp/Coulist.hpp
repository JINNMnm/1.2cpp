#ifndef COULIST_HPP
#define COULIST_HPP
#include "Course.hpp"
class Coulist{
    public:
        Coulist();//���캯��
        void addcourse(int bhv,string namev,string teacherv,int creditv,string catagoryv,string collegev,int assessmentv);//��ӿγ�
        bool delcourse(int bhv);//���տγ̱��ɾ���γ�
        bool modifycourse(int bhv);//�޸Ŀγ�
        bool findcourse();//���ҿγ̵Ĵ��࣬������������ĵ㡣���û���ҵ��ͷ���false���ҵ��˾ͷ���true
        bool find_and_assesscourse();//������Ҫ���۵Ŀγ̣����Ҹ�������
        bool sortcourse();//�����򣬾����Ϊ����������
        void sort_credit();//����ѧ������
        void sort_college();//����ѧԺ����
        Course* findbh(int bhv)const;//���ձ�Ų��ҿγ�
        Course* findname(string namev)const;//�������Ʋ��ҿγ�
        Course* findteacher(string teacherv)const;//���ս�ʦ���ҿγ�
        Course* findcollege(string collegev)const;//����ѧԺ���ҿγ�
        void write();//д���ļ�
        void showcourse();//��ʾ�γ�
        int getsize()const{return size;};//����ܿγ���
        void swapcourse(Course*p,Course*q);//�����γ�

    private:
        int size = 0;
        Course *head;
};
#endif