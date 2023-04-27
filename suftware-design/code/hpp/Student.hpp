#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include "Coulist.hpp"
using namespace std;
class Student{
    public:
        Student* next;
        Student(string numv = "",string pwv = "",int numofchosenv = 0,int chosenv[10] = {0}):num(numv),pw(pwv),numofchosen(numofchosenv){
            for(int i = 0;i < numofchosen;i++){
                chosen[i] = chosenv[i];
            }
        }//构造函数
        void addchosen(const Coulist& coulist);//在已有课程中选课，加入const以防止修改courlist
        void delchosen(int bhv);//退出编号为bhv的课
        void showchosen();//查看已选课程编号
        void del_nonecourse(const Coulist& coulist);//删除在coulist已经不存在，但是该学生已经选了的课程
        string getnum(){return num;}
        string getpw(){return pw;}
        int getnumofchosen(){return numofchosen;}
        int getchosen(int i){return chosen[i];}
    private:
        int chosen[10];//已选课程编号
        int numofchosen;//已选课程数量
        string num;//学号
        string pw;//密码
};

#endif