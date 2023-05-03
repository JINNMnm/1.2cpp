#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include "Coulist.hpp"
using namespace std;
class Student{
    public:
        Student* next;
        Student(string numv = "",string pwv = "",int numofchosenv = 0,int chosenv[10] = {0}):num(numv),pw(pwv),numofchosen(numofchosenv){
            //���캯��
            for(int i = 0;i < numofchosen;i++){
                chosen[i] = chosenv[i];
            }
        }
        void addchosen(const Coulist& coulist);//�����пγ���ѡ�Σ�����const�Է�ֹ�޸�courlist
        void delchosen(int bhv);//�˳����Ϊbhv�Ŀ�
        void showchosen();//�鿴��ѡ�γ̱��
        void del_nonecourse(const Coulist& coulist);//ɾ����coulist�Ѿ������ڣ����Ǹ�ѧ���Ѿ�ѡ�˵Ŀγ�
        string getnum(){return num;}//��ȡѧ��
        string getpw(){return pw;}//��ȡ����
        int getnumofchosen(){return numofchosen;}//��ȡ��ѡ�γ�����
        int getchosen(int i){return chosen[i];}//��ȡ��ѡ�γ̱��
    private:
        int chosen[10];//��ѡ�γ̱��
        int numofchosen;//��ѡ�γ�����
        string num;//ѧ��
        string pw;//����
};

#endif