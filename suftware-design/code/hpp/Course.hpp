#ifndef COURSE_HPP
#define COURSE_HPP
#include <string>
using namespace std;
class Course{
    public:
        Course* next;
        Course(int bhv = -1,string namev = "",string teacherv = "",int creditv = -1,string catagoryv = "",string collegev = "",int assessmentv = -1):bh(bhv),name(namev),teacher(teacherv),catagory(catagoryv),credit(creditv),college(collegev),assessment(assessmentv){};//���캯��
        void showcourse();//��ʾ�γ�

        int getbh()const{return bh;}//��ȡ���
        int getassessment()const{return assessment;}//��ȡ�γ�����
        int getcredit()const{return credit;}//��ȡѧ��
        string getname()const{return name;}//��ȡ�γ�����
        string getteacher()const{return teacher;}//��ȡ�Ͽν�ʦ
        string getcollege()const{return college;}//��ȡ����ѧԺ
        string getcatagory()const{return catagory;}//��ȡ�γ����

        void setbh(int bhv){bh = bhv;}//���ñ��
        void setassessment(int assessmentv){assessment = assessmentv;}//���ÿγ�����
        void setcredit(int creditv){credit = creditv;}//����ѧ��
        void setname(string namev){name = namev;}//���ÿγ�����
        void setteacher(string teacherv){teacher = teacherv;}//�����Ͽν�ʦ
        void setcollege(string collegev){college = collegev;}//���ÿ���ѧԺ
        void setcatagory(string catagoryv){catagory = catagoryv;}//���ÿγ����
    private:
        int bh;//���
        int assessment;//�γ�����
        int credit;//ѧ��
        string name;//�γ�����  
        string teacher;//�Ͽν�ʦ
        string catagory;//�γ�����
        string college;//����ѧԺ
};
#endif