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
Student* Stulist::checkifstu(string numv,string pwv){
    //查看是否有这个学生账号
    Student *p = head;
    while(p != NULL){
        if(p->getnum() == numv && p->getpw() == pwv)
            return p;
        p = p->next;
    }
    return NULL;
}
Student* Stulist::stuidentity(){
    //临时存储学号和密码
    system("cls");
    string num,pw;
    cout << "请输入学号:" << endl;
    cin >> num;
    cout << "(区分大小写)请输入密码:" << endl;
    cin >> pw;
    return checkifstu(num,pw);
}
void Stulist::addstu(string numv,string pwv){
    //添加学生
    Student *p = new Student(numv,pwv);
    p->next = head;
    head = p;
    size++;
}