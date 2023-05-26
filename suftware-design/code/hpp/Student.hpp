#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include "Coulist.hpp"
#include "Chosenlist.hpp"

using namespace std;
class Student{
    public:
        Student* next;
        Student(string numv = "",string pwv = ""):num(numv),pw(pwv){}//���캯��

        bool initchosen(int (&chosenv)[25],int numofchosenv);//��ʼ����ѡ�γ�
        void addchosen(const Coulist& coulist);//�����пγ���ѡ�Σ�����const�Է�ֹ�޸�courlist
        bool delchosen();//�˳��γ̹���
        void showchosen(const Coulist& coulist);//�鿴��ѡ�γ̱��
        void del_nonecourse(const Coulist& coulist);//ɾ����coulist�Ѿ������ڣ����Ǹ�ѧ���Ѿ�ѡ�˵Ŀγ�

        string getnum()const{return num;}//��ȡѧ��
        string getpw()const{return pw;}//��ȡ����
        Chosenlist getchosenlist()const{return chosenlist;}//��ȡ��ѡ�γ�����
    private:
        Chosenlist chosenlist;//��ѡ�γ�����
        string num;//ѧ��
        string pw;//����
};

#endif