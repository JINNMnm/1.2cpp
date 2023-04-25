#include "../hpp/Stulist.hpp"
#include <iostream>
#include <string>
using namespace std;
Stulist::Stulist(){
    //初始化学生链表
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
    string num,pw;//临时存储学号和密码
    cout << "请输入学号:" << endl;
    cin >> num;
    cout << "(区分大小写)请输入密码:" << endl;
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