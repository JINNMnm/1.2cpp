#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
using namespace std;
class Student{
    public:
        Student* next;
        Student(string numv = "",string pwv = "",int numofchosenv = 0):num(numv),pw(pwv),numofchosen(numofchosenv){};
        void addchosen();//ѡ��
        void delchosen();//�˿�
        void showchosen();//�鿴��ѡ�γ�
        string getnum(){return num;}
        string getpw(){return pw;}
        int getnumofchosen(){return numofchosen;}
        int getchosen(int i){return chosen[i];}
    private:
        int chosen[10];//��ѡ�γ̱��
        int numofchosen;//��ѡ�γ�����
        string num;//ѧ��
        string pw;//����
};

#endif