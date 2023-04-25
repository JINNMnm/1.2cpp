#ifndef COURSE_HPP
#define COURSE_HPP
#include <string>
using namespace std;
class Course{
    public:
        Course* next;
        Course(int bhv = -1,string namev = "",string teacherv = "",int creditv = -1,string catagoryv = "",string collegev = "",int assessmentv = -1):bh(bhv),name(namev),teacher(teacherv),catagory(catagoryv),credit(creditv),college(collegev),assessment(assessmentv){};
        void showcourse();//显示课程
        int getbh(){return bh;}
        int getassessment(){return assessment;}
        int getcredit(){return credit;}
        string getname(){return name;}
        string getteacher(){return teacher;}
        string getcollege(){return college;}
        string getcatagory(){return catagory;}
        void setassessment(int assessmentv){assessment = assessmentv;}
        void setbh(int bhv){bh = bhv;}
        void setcredit(int creditv){credit = creditv;}
        void setname(string namev){name = namev;}
        void setteacher(string teacherv){teacher = teacherv;}
        void setcollege(string collegev){college = collegev;}
        void setcatagory(string catagoryv){catagory = catagoryv;}
    private:
        int bh;//编号
        int assessment;//课程评价
        int credit;//学分
        string name;//课程名称  
        string teacher;//认课教师
        string catagory;//课程性质
        string college;//开课学院
};
#endif