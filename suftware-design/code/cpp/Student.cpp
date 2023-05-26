#include "../hpp/Student.hpp"
#include "../hpp/Coulist.hpp"
#include "../hpp/Course.hpp"
#include "../hpp/Chosenlist.hpp"
#include <iostream>
#include <algorithm>
using namespace std;


bool Student::initchosen(int (&chosenv)[25],int numofchosenv){
    //初始化已选课程
    for(int i = 0;i < numofchosenv;i++){
        if(!chosenlist.addchosen(chosenv[i])){
            return false;
        }
    }
    return true;
}

void Student::showchosen(const Coulist &coulist){
    //查看已选课程编号
    Chosen* p = this->chosenlist.gethead()->next;
    while(p){
        coulist.findbh(p->getbh())->showcourse();
        p = p->next;
    }
    cout << endl;   
}

void Student::addchosen(const Coulist& coulist){
    //学生选课
    int bhv;
    cout << "请输入要选的课程编号：";
    cin >> bhv;
    Chosen* p = this->chosenlist.gethead()->next;

    //检查课程是否存在
    if(!coulist.findbh(bhv)){
        cout << "课程不存在" << endl;
        return;
    }

    //检查是否已经选满
    if(this->chosenlist.getsize() == this->chosenlist.getmaxsize()){
        cout << "选课已满" << endl;
        return;
    }

    //检查是否已经选了该课
    p = this->chosenlist.gethead()->next;
    while(p){
        if(p->getbh() == bhv){
            cout << "已经选了该课" << endl;
            return;
        }
        p = p->next;
    }

    //检查选课的时间是否冲突
    p = this->chosenlist.gethead()->next;
    while(p){
        Course* m = coulist.findbh(p->getbh());
        Course* n = coulist.findbh(bhv);
        if(m->getday() == n->getday() && m->gettime() == n->gettime()){
            cout << "选课时间与编号" << p->getbh() <<"课程冲突" << endl;
            return;
        }
        p = p->next;
    }

    //选课成功
    this->chosenlist.addchosen(bhv);
    cout << "选课成功,以下是你更新后的选课编号" << endl;
    this->showchosen(coulist);
}

bool Student::delchosen(){
    //退出编号为bhv的课
    int bhv;
    cout << "请输入要退出的课程编号：";
    cin >> bhv;
    if(this->chosenlist.delchosen(bhv)){
        return true;
    }else{
        return false;
    }

}

void Student::del_nonecourse(const Coulist& coulist){
    //删除在coulist已经不存在，但是该学生已经选了的课程
    Chosen* p = this->chosenlist.gethead()->next;
    while(p){
        if(!coulist.findbh(p->getbh())){
            this->chosenlist.delchosen(p->getbh());
        }
        p = p->next;
    }
}