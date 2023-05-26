#include "../hpp/Chosenlist.hpp"
#include <iostream>
using namespace std;

Chosenlist::Chosenlist(){
    //构造函数
    head = new Chosen;
    head->next = NULL;
    maxsize = 25;
    size = 0;
}

bool Chosenlist::addchosen(int bhv){
    //添加课程
    if(size >= maxsize){
        cout << "选课已满" << endl;
        return false;
    }
    Chosen* p = new Chosen(bhv);
    p->next = head->next;
    head->next = p;
    size++;
    return true;
}

bool Chosenlist::delchosen(int bhv){
    //按照课程编号删除课程
    Chosen* p = head->next;
    Chosen* q = head;
    while(p){
        if(p->getbh() == bhv){
            q->next = p->next;
            delete p;
            size--;
            return true;
        }
        q = p;
        p = p->next;
    }
    return false;
}