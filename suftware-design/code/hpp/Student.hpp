#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
using namespace std;
class Student{
    public:
        Student* next;
        Student(string numv = "",string pwv = "",int numofchosenv = 0):num(numv),pw(pwv),numofchosen(numofchosenv){};
        void addchosen();//选课
        void delchosen();//退课
        void showchosen();//查看已选课程
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