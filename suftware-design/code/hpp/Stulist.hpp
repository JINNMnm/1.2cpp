#ifndef STULIST_HPP
#define STULIST_HPP

#include "Course.hpp"
#include "Student.hpp"
class Stulist{
    public:
        Stulist();
        bool stuidentity();//ѧ�������֤
        void addstu(string numv,string pwv);//���ѧ��
        void delstu();//ɾ��ѧ��
        bool checkifstu(string numv,string pwv);//�鿴ѧ��
    private:
        int size;//ѧ������
        Student *head;
};

#endif