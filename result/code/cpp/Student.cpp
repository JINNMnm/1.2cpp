#include "../hpp/Student.hpp"
#include "../hpp/Coulist.hpp"
#include "../hpp/Course.hpp"
#include <iostream>
#include <algorithm>
using namespace std;


void Student::showchosen(){
    //�鿴��ѡ�γ̱��
    sort(chosen,chosen + numofchosen);//����
    if(numofchosen == 0) 
        cout << "��Ŀǰһ�ſζ�ûѡ" << endl;
    else{
        cout << "�����������ѡ�γ̵ı��:" << endl;
        for(int i = 0;i < numofchosen;i++){
            cout << chosen[i] << ' ';
        }
        cout << endl;
    }
}

void Student::addchosen(const Coulist& coulist){
    //�����пγ���ѡ�Σ�����const�Է�ֹ�޸�courlist
    if(numofchosen == 10){
        cout << "���Ѿ�ѡ��10�ſ���,������ѡ��" << endl;
        return ;
    }
    this->showchosen();
    int bhv;
    cout << "������Ҫѡ�Ŀγ̱��:" << endl;
    cin >> bhv;
    for(int i = 0;i < numofchosen;i++){
        if(chosen[i] == bhv){
            cout << "���Ѿ�ѡ�����ſ���" << endl;
            return ;
        }
    }
    if(coulist.findbh(bhv) == NULL){
        return ;
    }
    chosen[numofchosen++] = bhv;
    cout << "ѡ�γɹ�" << endl;
    this->showchosen();
}

void Student::delchosen(int bhv){
    //�˳����Ϊbhv�Ŀ�
    int i;
    for(i = 0;i < numofchosen;i++){
        if(chosen[i] == bhv){
            for(int j = i;j < numofchosen - 1;j++){
                chosen[j] = chosen[j+1];
            }
            break;
        }
    }
    if(i == numofchosen){
        cout << "��û��ѡ���ſ�" << endl;
        return ;
    }
    numofchosen--;//�˿γɹ�,��ѡ�γ�������һ
    cout << "�˿γɹ�" << endl;
    this->showchosen();
}

void Student::del_nonecourse(const Coulist& coulist){
    //ɾ����coulist�Ѿ������ڣ����Ǹ�ѧ���Ѿ�ѡ�˵Ŀγ�
    for(int i = 0;i < numofchosen;i++){
        if(coulist.findbh(chosen[i]) == NULL){
            delchosen(chosen[i]);
        }
    }
    return;
}