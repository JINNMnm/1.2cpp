#ifndef STULIST_HPP
#define STULIST_HPP

#include "Student.hpp"
class Stulist{
    public:
        Stulist();
        Student* stuidentity();//ѧ�������֤
        Student* checkifstu(string numv,string pwv);//�鿴ѧ��

        void addstu(string& numv,string& pwv,int& numofchosenv,int (&chosen)[25]);//���ѧ��
        void write()const;//д���ļ�
    private:
        int size;//ѧ������
        Student *head;
};

#endif