#ifndef COURSE_HPP
#define COURSE_HPP
#include <string>
using namespace std;
class Course{
    public:
        Course* next;
        Course(int bhv = -1,string namev = "",string teacherv = "",int creditv = -1,string catagoryv = "",string collegev = "",int assessmentv = -1,int dayv = 0,int timev = 0):bh(bhv),name(namev),teacher(teacherv),catagory(catagoryv),credit(creditv),college(collegev),assessment(assessmentv),day(dayv),time(timev){};//构造函数
        void showcourse();//显示课程

        int getbh()const{return bh;}//获取编号
        int getassessment()const{return assessment;}//获取课程评价
        int getcredit()const{return credit;}//获取学分
        string getname()const{return name;}//获取课程名称
        string getteacher()const{return teacher;}//获取认课教师
        string getcollege()const{return college;}//获取开课学院
        string getcatagory()const{return catagory;}//获取课程类别
        int getday()const{return day;}//获取上课日期(周几)
        int gettime()const{return time;}//获取上课时间(第几节)

        void setbh(int bhv){bh = bhv;}//设置编号
        void setassessment(int assessmentv){assessment = assessmentv;}//设置课程评价
        void setcredit(int creditv){credit = creditv;}//设置学分
        void setname(string namev){name = namev;}//设置课程名称
        void setteacher(string teacherv){teacher = teacherv;}//设置认课教师
        void setcollege(string collegev){college = collegev;}//设置开课学院
        void setcatagory(string catagoryv){catagory = catagoryv;}//设置课程类别
        void setday(int dayv){day = dayv;}//设置上课日期(周几)
        void settime(int timev){time = timev;}//设置上课时间(第几节)
    private:
        int bh;//编号
        int assessment;//课程评价
        int credit;//学分
        string name;//课程名称  
        string teacher;//认课教师
        string catagory;//课程性质
        string college;//开课学院
        int day;//上课日期(周几)
        int time;//上课时间
};
#endif