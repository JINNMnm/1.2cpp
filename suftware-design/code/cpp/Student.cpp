#include "../hpp/Student.hpp"
#include <iostream>
using namespace std;


void Student::showchosen(){
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

void Student::addchosen(){
    this->showchosen();
    int numv;
    cout << "������Ҫѡ�Ŀγ̱��:" << endl;
    cin >> numv;
    chosen[numofchosen++] = numv;
    cout << "ѡ�γɹ�" << endl;
    this->showchosen();
}

void Student::delchosen(){
    if(numofchosen == 0) {cout << "��û�������ֵ�" << endl;return ;}
    this->showchosen();
    numofchosen--;
    int numv,i;
    cout << "������Ҫ�˵Ŀγ̱��" << endl;
    cin >> numv;
    for(i = 0;i < numofchosen;i++){
        if(chosen[i] == numv){
            for(int j = i;j < numofchosen;j++){
                chosen[j] = chosen[j+1];
            }
            break;
        }
    }
    if(i == numofchosen){
        cout << "��û��ѡ���ſ�" << endl;
        return ;
    }
    cout << "�˿γɹ�" << endl;
    this->showchosen();
}