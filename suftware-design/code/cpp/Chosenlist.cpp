#include "../hpp/Chosenlist.hpp"
#include <iostream>
using namespace std;

Chosenlist::Chosenlist(){
    //���캯��
    head = new Chosen;
    head->next = NULL;
    maxsize = 25;
    size = 0;
}

bool Chosenlist::addchosen(int bhv){
    //��ӿγ�
    if(size >= maxsize){
        cout << "ѡ������" << endl;
        return false;
    }
    Chosen* p = new Chosen(bhv);
    p->next = head->next;
    head->next = p;
    size++;
    return true;
}

bool Chosenlist::delchosen(int bhv){
    //���տγ̱��ɾ���γ�
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