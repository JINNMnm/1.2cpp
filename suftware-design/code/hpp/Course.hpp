#ifndef COURSE_HPP
#define COURSE_HPP
#include <string>
using namespace std;
class Course{
    public:
        Course* next;
        Course(int bhv = 0,string namev = "",int assessmentv = 0,int creditv = 0,string teacherv = "",string collegev = ""):bh(bhv),name(namev),assessment(assessmentv),credit(creditv),teacher(teacherv),college(collegev){};
        int getbh(){return bh;}
        int getassessment(){return assessment;}
        int getcredit(){return credit;}
        string getname(){return name;}
        string getteacher(){return teacher;}
        string getcollege(){return college;}
        
    private:
        int bh;//���
        int assessment;//�γ�����
        int credit;//ѧ��
        string name;//�γ�����  
        string teacher;//�Ͽν�ʦ
        string college;//����ѧԺ
};
#endif