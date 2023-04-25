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
        int bh;//编号
        int assessment;//课程评价
        int credit;//学分
        string name;//课程名称  
        string teacher;//认课教师
        string college;//开课学院
};
#endif