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
bool Stulist::checkifstu(string numv,string pwv){
    Student *p = head->next;
    while(p != NULL){
        if(p->getnum() == numv and p->getpw() == pwv)
            return true;
        p = p->next;
    }
    return false;
}
bool Stulist::stuidentity(){
    string num,pw;//��ʱ�洢ѧ�ź�����
    cout << "������ѧ��:" << endl;
    cin >> num;
    cout << "(���ִ�Сд)����������:" << endl;
    cin >> pw;
    if(checkifstu(num,pw) == true)
        return true;
    else
        return false;
}
void Stulist::addstu(string numv,string pwv){
    Student *p = new Student(numv,pwv);
    p->next = head;
    head = p;
    size++;
}