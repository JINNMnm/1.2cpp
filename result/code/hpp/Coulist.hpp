#ifndef COULIST_HPP
#define COULIST_HPP
#include "Course.hpp"
class Coulist{
    public:
        Coulist();//���캯��
        bool addcourse(int bhv,string namev,string teacherv,int creditv,string catagoryv,string collegev,int assessmentv,int dayv,int timev);//��ӿγ�
        bool delcourse(int bhv);//���տγ̱��ɾ���γ�
        bool modifycourse(int bhv);//�޸Ŀγ�
        bool checkif_teacher_have_time(int dayv,int timev,string teacherv);//����ʦ�Ƿ��п�
        bool checkif_teacher_have_time(int dayv,int timev,string teacherv,int except_bh);//����ʦ���˱��Ϊexcept_bh�Ŀγ�֮���Ƿ��п�
        
        bool find_and_assesscourse();//������Ҫ���۵Ŀγ̣����Ҹ�������
        bool sortcourse();//�����򣬾����Ϊ����������
        void sort_credit();//����ѧ������
        void sort_college();//����ѧԺ����
        
        bool findcourse();//���ҿγ̵Ĵ��࣬������������ĵ㡣���û���ҵ��ͷ���false���ҵ��˾ͷ���true
        Course* findbh(int bhv)const;//���ձ�Ų��ҿγ�
        bool findname(string namev)const;//�������Ʋ��ҿγ�
        bool findteacher(string teacherv)const;//���ս�ʦ���ҿγ�
        bool findcollege(string collegev)const;//����ѧԺ���ҿγ�

        void write();//д���ļ�
        void showcourse();//��ʾ�γ�
        int getsize()const{return size;};//����ܿγ���
        void swapcourse(Course*p,Course*q);//�����γ�

    private:
        int size = 0;
        Course *head;
};
#endif