#ifndef STULIST_HPP
#define STULIST_HPP

#include "Course.hpp"
#include "Student.hpp"
class Stulist{
    public:
        Stulist();
        bool stuidentity();//学生身份认证
        void addstu(string numv,string pwv);//添加学生
        void delstu();//删除学生
        bool checkifstu(string numv,string pwv);//查看学生
    private:
        int size;//学生数量
        Student *head;
};

#endif