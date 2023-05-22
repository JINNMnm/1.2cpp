#include "../hpp/Stulist.hpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
Stulist::Stulist(){
    //��ʼ��ѧ������,�����ڱ�������
    head = new Student;
    head->next = NULL;
    size = 0;
}

void Stulist::write(){
    //д���ļ�
    ofstream out("../txt/student.txt");
    Student* p = head->next;
    while(p){
        out << p->getnum() << ' ';
        out << p->getpw()   << ' ';//д��ѧ�ź�����
        out << p->getnumofchosen()  << ' ';//д����ѡ�γ�����
        for(int i = 0;i < p->getnumofchosen();i++)
            out << p->getchosen(i) << ' ';//д����ѡ�γ̱��
        out << endl;
        p = p->next;
    }
    out.close();
}

Student* Stulist::checkifstu(string numv,string pwv){
    //�鿴�Ƿ������ѧ���˺�
    Student *p = head->next;
    while(p){
        if(p->getnum() == numv && p->getpw() == pwv)
            return p;
        p = p->next;
    }
    return NULL;
}

Student* Stulist::stuidentity(){
    //ѧ�������֤
    system("cls");
    string num,pw;
    cout << "������ѧ��:" << endl;
    cin >> num;
    cout << "(���ִ�Сд)����������:" << endl;
    cin >> pw;
    return checkifstu(num,pw);
}

void Stulist::addstu(string& numv,string& pwv,int& numofchosenv,int (&chosenv)[10]){
    //���ѧ��
    Student *p = new Student(numv,pwv,numofchosenv,chosenv);
    p->next = head->next;
    head->next = p;
    size++;
}