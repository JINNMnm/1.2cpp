#include "../hpp/Stulist.hpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
Stulist::Stulist(){
    //初始化学生链表
    head = new Student;
    head->next = NULL;
    size = 0;
}
void Stulist::write(){
    //写入文件
    ofstream out("../txt/student.txt");
    Student* p = head;
    while(p->next != NULL){
        out << p->getnum() << ' ';
        out << p->getpw()   << ' ';//写入学号和密码
        out << p->getnumofchosen()  << ' ';//写入已选课程数量
        for(int i = 0;i < p->getnumofchosen();i++)
            out << p->getchosen(i) << ' ';//写入已选课程编号
        out << endl;
        p = p->next;
    }
    out.close();
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
void Stulist::addstu(string& numv,string& pwv,int& numofchosenv,int (&chosenv)[10]){
    //添加学生
    Student *p = new Student(numv,pwv,numofchosenv,chosenv);
    p->next = head;
    head = p;
    size++;
}