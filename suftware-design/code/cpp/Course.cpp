#include "../hpp/Course.hpp"
#include <iostream>
using namespace std;

void Course::showcourse(){
    //��ʾ�γ���Ϣ
    cout << "�γ̱��:" << bh << ' ';
    cout << "�γ�����:" << name << ' ';
    cout << "�ον�ʦ:" << teacher << ' ';
    cout << "�γ�����:" << catagory << ' ';
    cout << "ѧ��:" << credit << ' ';
    cout << "����ѧԺ:" << college << ' ';
    if(assessment != -1)cout << "�γ�����:" << assessment << endl;
    else cout << "�ÿγ̻�û������" << endl;
}