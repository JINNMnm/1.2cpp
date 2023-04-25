
#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
using namespace std;
class Student{
    public:
        Student* next;
        Student(string numv = "",string pwv = ""):num(numv),pw(pwv){};
        string getnum(){return num;}
        string getpw(){return pw;}
    private:
        string num;//Ñ§ºÅ
        string pw;//ÃÜÂë
};

#endif