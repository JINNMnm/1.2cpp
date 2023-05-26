#include "../hpp/Student.hpp"
#include "../hpp/Coulist.hpp"
#include "../hpp/Course.hpp"
#include "../hpp/Chosenlist.hpp"
#include <iostream>
#include <algorithm>
using namespace std;


bool Student::initchosen(int (&chosenv)[25],int numofchosenv){
    //��ʼ����ѡ�γ�
    for(int i = 0;i < numofchosenv;i++){
        if(!chosenlist.addchosen(chosenv[i])){
            return false;
        }
    }
    return true;
}

void Student::showchosen(const Coulist &coulist){
    //�鿴��ѡ�γ̱��
    Chosen* p = this->chosenlist.gethead()->next;
    while(p){
        coulist.findbh(p->getbh())->showcourse();
        p = p->next;
    }
    cout << endl;   
}

void Student::addchosen(const Coulist& coulist){
    //ѧ��ѡ��
    int bhv;
    cout << "������Ҫѡ�Ŀγ̱�ţ�";
    cin >> bhv;
    Chosen* p = this->chosenlist.gethead()->next;

    //���γ��Ƿ����
    if(!coulist.findbh(bhv)){
        cout << "�γ̲�����" << endl;
        return;
    }

    //����Ƿ��Ѿ�ѡ��
    if(this->chosenlist.getsize() == this->chosenlist.getmaxsize()){
        cout << "ѡ������" << endl;
        return;
    }

    //����Ƿ��Ѿ�ѡ�˸ÿ�
    p = this->chosenlist.gethead()->next;
    while(p){
        if(p->getbh() == bhv){
            cout << "�Ѿ�ѡ�˸ÿ�" << endl;
            return;
        }
        p = p->next;
    }

    //���ѡ�ε�ʱ���Ƿ��ͻ
    p = this->chosenlist.gethead()->next;
    while(p){
        Course* m = coulist.findbh(p->getbh());
        Course* n = coulist.findbh(bhv);
        if(m->getday() == n->getday() && m->gettime() == n->gettime()){
            cout << "ѡ��ʱ������" << p->getbh() <<"�γ̳�ͻ" << endl;
            return;
        }
        p = p->next;
    }

    //ѡ�γɹ�
    this->chosenlist.addchosen(bhv);
    cout << "ѡ�γɹ�,����������º��ѡ�α��" << endl;
    this->showchosen(coulist);
}

bool Student::delchosen(){
    //�˳����Ϊbhv�Ŀ�
    int bhv;
    cout << "������Ҫ�˳��Ŀγ̱�ţ�";
    cin >> bhv;
    if(this->chosenlist.delchosen(bhv)){
        return true;
    }else{
        return false;
    }

}

void Student::del_nonecourse(const Coulist& coulist){
    //ɾ����coulist�Ѿ������ڣ����Ǹ�ѧ���Ѿ�ѡ�˵Ŀγ�
    Chosen* p = this->chosenlist.gethead()->next;
    while(p){
        if(!coulist.findbh(p->getbh())){
            this->chosenlist.delchosen(p->getbh());
        }
        p = p->next;
    }
}