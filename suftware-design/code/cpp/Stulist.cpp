#include "../hpp/Stulist.hpp"
#include <iostream>
#include <string>
using namespace std;
Stulist::Stulist(){
    //��ʼ��ѧ������
    head = new Student;
    head->next = NULL;
    size = 0;
}
Student* Stulist::checkifstu(string numv,string pwv){
    //�鿴�Ƿ������ѧ���˺�
    Student *p = head;
    while(p != NULL){
        if(p->getnum() == numv && p->getpw() == pwv)
            return p;
        p = p->next;
    }
    return NULL;
}
Student* Stulist::stuidentity(){
    //��ʱ�洢ѧ�ź�����
    system("cls");
    string num,pw;
    cout << "������ѧ��:" << endl;
    cin >> num;
    cout << "(���ִ�Сд)����������:" << endl;
    cin >> pw;
    return checkifstu(num,pw);
}
void Stulist::addstu(string numv,string pwv){
    //���ѧ��
    Student *p = new Student(numv,pwv);
    p->next = head;
    head = p;
    size++;
}