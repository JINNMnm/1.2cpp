#include "../hpp/Coulist.hpp"
#include <iostream>
using namespace std;
Coulist::Coulist(){
    head = new Course;
    head->next = NULL;
    size = 0;
}

void Coulist::addcourse(int bhv,string namev,string teacherv,int creditv,string catagoryv,string collegev,int assessmentv){
    Course* p = new Course(bhv,namev,teacherv,creditv,catagoryv,collegev,assessmentv);
    p->next = head;
    head = p;
    size++;
}

bool Coulist::delcourse(int bhv){
    Course *p = head,*pre = NULL;
    while(p->next){
        pre = p;
        if(p->getbh() == bhv){
            pre->next = p->next;
            delete p;
            size--;
            return true;
        }
    }
    return false;
}
void Coulist::showcourse(){
    Course* p = head;
    while(p->next != NULL){
        cout << "课程编号:" << p->getbh() << ' ';
        cout << "课程名称:" << p->getname() << ' ';
        cout << "课程评价:" << p->getassessment() << ' ';
        cout << "课程学分:" << p->getcredit() << ' ';
        cout << "认课教师:" << p->getteacher() << ' ';
        cout << "开课学院:" << p->getcollege() << endl;
        p = p->next;
    }
}

bool Coulist::findcourse(){
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
        system("pause");
        return true;
    }
    else
        return false;
}

Course* Coulist::findbh(int bhv){
    Course* p = head;
    while(p != NULL){
        if(p->getbh() == bhv)
            return p;
        p = p->next;
    }
    cout << size << endl;
    cout << "查无此课" << endl;
    return NULL;
}

Course* Coulist::findname(string namev){
    Course* p = head;
    while(p != NULL){
        if(p->getname() == namev)
            return p;
        p = p->next;
    }
    cout << "查无此课" << endl;
    return NULL;
}

Course* Coulist::findteacher(string teacherv){
    Course* p = head;
    while(p != NULL){
        if(p->getteacher() == teacherv)
            return p;
        p = p->next;
    }
    cout << "查无此课" << endl;
    return NULL;
}

Course* Coulist::findcollege(string collegev){
    Course* p = head;
    while(p != NULL){
        if(p->getcollege() == collegev)
            return p;
        p = p->next;
    }
    cout << "查无此课" << endl;
    return NULL;
}