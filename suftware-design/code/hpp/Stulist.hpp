#ifndef STULIST_HPP
#define STULIST_HPP

#include "Student.hpp"
class Stulist{
    public:
        Stulist();
        Student* stuidentity();//学生身份认证
        Student* checkifstu(string numv,string pwv);//查看学生

        void addstu(string& numv,string& pwv,int& numofchosenv,int (&chosen)[25]);//添加学生
        void write()const;//写入文件
    private:
        int size;//学生数量
        Student *head;
};

#endif