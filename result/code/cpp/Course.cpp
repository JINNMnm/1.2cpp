#include "../hpp/Course.hpp"
#include <iostream>
#include <string>
#include <iomanip>  
using namespace std;

string todate(int day){
    //������ת��Ϊ����
    switch(day){
        case 1:return "����һ";
        case 2:return "���ڶ�";
        case 3:return "������";
        case 4:return "������";
        case 5:return "������";
        case 6:return "������";
        case 7:return "������";
    }
    return "����";
}

void Course::showcourse(){
    //��ʾ�γ���Ϣ,�����
    cout << "�γ̱��:" << setw(2) << setiosflags(ios::left) << bh ;
    cout << "�γ�����:" << setw(20) << setiosflags(ios::left) << name ;
    cout << "��ʦ:" << setw(8) << setiosflags(ios::left) << teacher ;
    cout << "ѧ��:" << setw(3) << setiosflags(ios::left) << credit ;
    cout << "�Ͽ�ʱ��:" << setw(10) << setiosflags(ios::left) << todate(day) << ' ' << "��" << time << "�ڿ�  " ;
    cout << "�γ����:" << setw(10) << setiosflags(ios::left) << catagory ;
    cout << "����ѧԺ:" << setw(11) << setiosflags(ios::left) << college ;
    if(assessment != -1)
        cout << "�γ�����:" << setw(5) << setiosflags(ios::left) << assessment ;
    else
        cout << "�γ�����:" << setw(5) << setiosflags(ios::left) << "��" ;
    cout << endl;
}