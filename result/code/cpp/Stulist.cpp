#include "../hpp/Stulist.hpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
Stulist::Stulist(){
    //初始化学生链表,带有哨兵的链表
    head = new Student;
    head->next = NULL;
    size = 0;
}

void Stulist::write()const{
    //写入文件
    ofstream out("../txt/student.txt");
    Student* p = head->next;
    while(p){
        out << p->getnum() << ' ';
        out << p->getpw()   << ' ';//写入学号和密码
        Chosen* q = p->getchosenlist().gethead()->next;
        out << p->getchosenlist().getsize() << ' ';//写入已选课程数量
        while(q){
            out << q->getbh() << ' ';
            q = q->next;
        }
        out << endl;
        p = p->next;
    }
    out.close();
}

Student* Stulist::checkifstu(string numv,string pwv){
    //查看是否有这个学生账号
    Student *p = head->next;
    while(p){
        if(p->getnum() == numv && p->getpw() == pwv)
            return p;
        p = p->next;
    }
    return NULL;
}

Student* Stulist::stuidentity(){
    //学生身份验证
    system("cls");
    string num,pw;
    cout << "请输入学号:" << endl;
    cin >> num;
    cout << "(区分大小写)请输入密码:" << endl;
    cin >> pw;
    return checkifstu(num,pw);
}

void Stulist::addstu(string& numv,string& pwv,int& numofchosenv,int (&chosenv)[25]){
    //添加学生
    Student *p = new Student(numv,pwv);
    p->initchosen(chosenv,numofchosenv);
    p->next = head->next;
    head->next = p;
    size++;
}