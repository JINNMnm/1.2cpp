#ifndef COURSE_HPP
#define COURSE_HPP
#include <string>
using namespace std;
class Course{
    public:
        Course* next;
        
        Course(int bhv = -1,string namev = "",string teacherv = "",int creditv = -1,string catagoryv = "",string collegev = "",int assessmentv = -1):bh(bhv),name(namev),teacher(teacherv),catagory(catagoryv),credit(creditv),college(collegev),assessment(assessmentv){};
        void showcourse();//��ʾ�γ�

        int getbh()const{return bh;}
        int getassessment()const{return assessment;}
        int getcredit()const{return credit;}
        string getname()const{return name;}
        string getteacher()const{return teacher;}
        string getcollege()const{return college;}
        string getcatagory()const{return catagory;}

        void setbh(int bhv){bh = bhv;}
        void setassessment(int assessmentv){assessment = assessmentv;}
        void setcredit(int creditv){credit = creditv;}
        void setname(string namev){name = namev;}
        void setteacher(string teacherv){teacher = teacherv;}
        void setcollege(string collegev){college = collegev;}
        void setcatagory(string catagoryv){catagory = catagoryv;}
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