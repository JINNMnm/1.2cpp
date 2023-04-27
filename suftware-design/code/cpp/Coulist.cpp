#include "../hpp/Coulist.hpp"
#include <iostream>
#include <fstream>
using namespace std;
Coulist::Coulist(){
    //构造函数
    head = new Course;
    head->next = NULL;
    size = 0;
}

void Coulist::write(){
    //写入文件
    ofstream out("../txt/course.txt");
    Course* p = head;
    while(p->next != NULL){
        out << p->getbh() << ' ';
        out << p->getname() << ' ';
        out << p->getteacher() << ' ';
        out << p->getcredit() << ' ';
        out << p->getcatagory() << ' ';
        out << p->getcollege() << ' ';
        out << p->getassessment() << endl;
        p = p->next;
    }
    out.close();
}

void Coulist::addcourse(int bhv,string namev,string teacherv,int creditv,string catagoryv,string collegev,int assessmentv){
    //添加课程
    Course* p = new Course(bhv,namev,teacherv,creditv,catagoryv,collegev,assessmentv);
    p->next = head;
    head = p;
    size++;
}

bool Coulist::sortcourse(){
    //总排序，具体分为以下两部分
    //按照学分排序
    //按照学院排序
    int choice_1;
    cin >> choice_1;
    switch(choice_1){
        case 1:{
            //按学分排序
            system("cls");
            cout << "按学分排序前数据：" << endl << endl;
            this->showcourse();
            this->sort_credit();
            cout << "按学分排序后数据：" << endl << endl;
            this->showcourse();
            break;
        }
        case 2:{
            //按学院排序
            system("cls");
            cout << "按学院排序前数据：" << endl << endl;
            this->showcourse();
            this->sort_college();
            cout << "按学院排序后数据：" << endl << endl;
            this->showcourse();
            break;
        }
        default:{
            cout << "输入错误，请重新输入" << endl;
            return false;
        }
    }
    return true;
}

void Coulist::swapcourse(Course*p,Course*q){
    //交换课程
    int temp;
    string temp1;
    temp = p->getbh();
    p->setbh(q->getbh());
    q->setbh(temp);
    temp = p->getassessment();
    p->setassessment(q->getassessment());
    q->setassessment(temp);
    temp = p->getcredit();
    p->setcredit(q->getcredit());
    q->setcredit(temp);
    temp1 = p->getname();
    p->setname(q->getname());
    q->setname(temp1);
    temp1 = p->getteacher();
    p->setteacher(q->getteacher());
    q->setteacher(temp1);
    temp1 = p->getcollege();
    p->setcollege(q->getcollege());
    q->setcollege(temp1);
    temp1 = p->getcatagory();
    p->setcatagory(q->getcatagory());
    q->setcatagory(temp1);
}

void Coulist::sort_credit(){
    //按学分排序
    Course *p = head,*q = NULL,*mini = NULL;
    while(p->next->next){
        q = p->next;
        mini = p;
        while(q->next){
            if(mini->getcredit() > q->getcredit()){
                mini = q;
            } 
            q = q->next;
        }
        if(mini != p){
            swapcourse(mini,p);
        }
        p = p->next;
    }
}


void Coulist::sort_college(){
    //按学院排序
    Course *p = head,*q = NULL,*mini = NULL;
    while(p->next->next){
        q = p->next;
        mini = p;
        while(q->next){
            if(mini->getcollege() > q->getcollege()){
                mini = q;
            } 
            q = q->next;
        }
        if(mini != p){
            swapcourse(mini,p);
        }
        p = p->next;
    }
}

bool Coulist::delcourse(int bhv){
    //删除课程信息
    Course *p = head->next,*pre = head;
    if(head->getbh() == bhv){
        head = head->next;
        size--;
        return true;
    }
    while(p->next){
        if(p->getbh() == bhv){
            pre->next = p->next;
            delete p;
            size--;
            return true;
        }
        pre = p;
        p = p->next;
    }
    return false;
}

void Coulist::showcourse(){
    //显示所有课程信息
    Course* p = head;
    while(p->next != NULL){
        p->showcourse();
        p = p->next;
    }
}

bool Coulist::findcourse(){
    //查找课程信息
    int choice_1;
    string teacherv,collegev;
    cin >> choice_1;//用户输入要如何查找？
    switch(choice_1){
        case 1:{
            //按课程编号查找
            cout << "请输入课程编号:" << endl;
            int bhv;
            cin >> bhv;
            if(findbh(bhv))
                findbh(bhv)->showcourse();
            else
                return false;
            break;
        }
        case 2:{
            //按课程名称查找
            cout << "请输入课程名称:" << endl;
            string namev;
            cin >> namev;
            if(findname(namev))
                findname(namev)->showcourse();
            else
                return false;
            break;
        }
        case 3:{
            //按教师查找
            cout << "请输入教师姓名:" << endl;
            cin >> teacherv;    
            if(findteacher(teacherv))
                findteacher(teacherv)->showcourse();
            else
                return false;
            break;
        }
        case 4:{
            //按学院查找
            cout << "请输入学院名称:" << endl;
            cin >> collegev;
            if(findcollege(collegev))
                findcollege(collegev)->showcourse();
            else
                return false;
            break;
        }
        default:{
            //输入错误
            cout << "输入错误" << endl;
            return false;
            break;
        }
    }
    return true;
}

bool Coulist::find_and_assesscourse(){
    //查找课程信息并评价
    int choice_1,assessmentv;
    string teacherv,collegev;
    Course* course;//临时变量储存找到的课程，以免下面函数二次调用
    cin >> choice_1;//用户输入要如何查找？
    switch(choice_1){
        case 1:{
            //按课程编号查找
            cout << "请输入你要评价课程的课程编号:" << endl;
            int bhv;
            cin >> bhv;
            course = findbh(bhv);
            if(course){
                course->showcourse();
                cout << "请输入你对该课程的评价:" << endl;
                cin >> assessmentv;
                course->setassessment(assessmentv);
            }
            else
                return false;
            break;
        }
        case 2:{
            //按课程名称查找
            cout << "请输入你要评价的课程名称:" << endl;
            string namev;
            cin >> namev;
            course = findname(namev);
            if(course){
                course->showcourse();
                cout << "请输入你对该课程的评价:" << endl;
                cin >> assessmentv;
                course->setassessment(assessmentv);
            }
            else
                return false;
        }
        case 3:{
            //按教师查找
            cout << "请输入你要评价课程的教师姓名:" << endl;
            cin >> teacherv;    
            course = findteacher(teacherv);
            if(course){
                course->showcourse();
                cout << "请输入你对该课程的评价:" << endl;
                cin >> assessmentv;
                course->setassessment(assessmentv);
            }
            else
                return false;
            break;
        }
        default:{
            //输入错误
            cout << "输入错误" << endl;
            return false;
            break;
        }
    }
    cout << "评价成功!以下是评价后的课程信息" << endl;
    course->showcourse();
    system("pause");
    return true;
}

bool Coulist::modifycourse(int bhv){
    //修改课程信息
    int bhv2,creditv;
    string namev,teacherv,catagoryv,collegev;
    Course* target = findbh(bhv);
    if(target){
        cout << "已查询到这节课，以下是课程信息：" << endl;
        target->showcourse();
        cout << "请按以下顺序输入课程信息：课程编号 课程名称 任课教师 学分 课程类别 开课学院(为公平,您无法修改课程的评价)" << endl;
        cin >> bhv2 >> namev >> teacherv >> creditv >> catagoryv >> collegev;
        target->setbh(bhv2);
        target->setname(namev);
        target->setteacher(teacherv);
        target->setcredit(creditv);
        target->setcatagory(catagoryv);
        target->setcollege(collegev);
        return true;
    }
    else
        return false;
}

Course* Coulist::findbh(int bhv)const{
    // 按课程编号查找课程
    Course* p = head;
    while(p != NULL){
        if(p->getbh() == bhv)
            return p;
        p = p->next;
    }
    cout << "查无此课" << endl;
    return NULL;
}

Course* Coulist::findname(string namev)const{
    //按课程名称查找课程
    Course* p = head;
    while(p != NULL){
        if(p->getname() == namev)
            return p;
        p = p->next;
    }
    cout << "查无此课" << endl;
    return NULL;
}

Course* Coulist::findteacher(string teacherv)const{
    //按教师查找课程
    Course* p = head;
    while(p != NULL){
        if(p->getteacher() == teacherv)
            return p;
        p = p->next;
    }
    cout << "查无此课" << endl;
    return NULL;
}

Course* Coulist::findcollege(string collegev)const{
    //按学院查找课程
    Course* p = head;
    while(p != NULL){
        if(p->getcollege() == collegev)
            return p;
        p = p->next;
    }
    cout << "查无此课" << endl;
    return NULL;
}