#include "../hpp/Course.hpp"
#include <iostream>
using namespace std;

void Course::showcourse(){
    cout << "�γ̱��:" << bh << ' ';
    cout << "�γ�����:" << name << ' ';
    cout << "�ον�ʦ:" << teacher << ' ';
    cout << "�γ�����:" << catagory << ' ';
    cout << "ѧ��:" << credit << ' ';
    cout << "����ѧԺ:" << college << ' ';
    if(assessment != -1)cout << "�γ�����:" << assessment << ' ';
    else cout << "�ÿγ̻�û������" << endl;
}