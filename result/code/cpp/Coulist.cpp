#include "../hpp/Coulist.hpp"
#include <iostream>
#include <fstream>
using namespace std;
Coulist::Coulist(){
    //����һ�������ڱ�������
    head = new Course;
    head->next = NULL;
    size = 0;
}

void Coulist::write(){
    //д���ļ�
    ofstream out("../txt/course.txt");
    Course* p = head->next;
    while(p){
        out << p->getbh() << ' ';
        out << p->getname() << ' ';
        out << p->getteacher() << ' ';
        out << p->getcredit() << ' ';
        out << p->getcatagory() << ' ';
        out << p->getcollege() << ' ';
        out << p->getassessment() << endl;
        p = p->next;
    }
    out.close();
}

void Coulist::addcourse(int bhv,string namev,string teacherv,int creditv,string catagoryv,string collegev,int assessmentv){
    //��ӿγ�
    Course* p = new Course(bhv,namev,teacherv,creditv,catagoryv,collegev,assessmentv);
    p->next = head->next;
    head->next = p;
    size++;
}

bool Coulist::sortcourse(){
    //�����򣬾����Ϊ����������
    //����ѧ������
    //����ѧԺ����
    int choice_1;
    cin >> choice_1;
    switch(choice_1){
        case 1:{
            //��ѧ������
            system("cls");
            cout << "��ѧ������ǰ���ݣ�" << endl << endl;
            this->showcourse();
            this->sort_credit();
            cout << "��ѧ����������ݣ�" << endl << endl;
            this->showcourse();
            break;
        }
        case 2:{
            //��ѧԺ����
            system("cls");
            cout << "��ѧԺ����ǰ���ݣ�" << endl << endl;
            this->showcourse();
            this->sort_college();
            cout << "��ѧԺ��������ݣ�" << endl << endl;
            this->showcourse();
            break;
        }
        default:{
            cout << "�����������������" << endl;
            return false;
        }
    }
    return true;
}

void Coulist::swapcourse(Course*p,Course*q){
    //�����γ�
    int temp;
    string temp1;
    temp = p->getbh();
    p->setbh(q->getbh());
    q->setbh(temp);
    temp = p->getassessment();
    p->setassessment(q->getassessment());
    q->setassessment(temp);
    temp = p->getcredit();
    p->setcredit(q->getcredit());
    q->setcredit(temp);
    temp1 = p->getname();
    p->setname(q->getname());
    q->setname(temp1);
    temp1 = p->getteacher();
    p->setteacher(q->getteacher());
    q->setteacher(temp1);
    temp1 = p->getcollege();
    p->setcollege(q->getcollege());
    q->setcollege(temp1);
    temp1 = p->getcatagory();
    p->setcatagory(q->getcatagory());
    q->setcatagory(temp1);
}

void Coulist::sort_credit(){
    //��ѧ������
    Course *p = head->next,*q = NULL,*mini = NULL;
    while(p->next){
        q = p->next;
        mini = p;
        while(q){
            if(mini->getcredit() > q->getcredit()){
                mini = q;
            } 
            q = q->next;
        }
        if(mini != p){
            swapcourse(mini,p);
        }
        p = p->next;
    }
}


void Coulist::sort_college(){
    //��ѧԺ����
    Course *p = head->next,*q = NULL,*mini = NULL;
    while(p->next){
        q = p->next;
        mini = p;
        while(q){
            if(mini->getcollege() > q->getcollege()){
                mini = q;
            } 
            q = q->next;
        }
        if(mini != p){
            swapcourse(mini,p);
        }
        p = p->next;
    }
}

bool Coulist::delcourse(int bhv){
    //ɾ���γ���Ϣ
    Course *p = head->next,*pre = head;
    while(p){
        if(p->getbh() == bhv){
            pre->next = p->next;
            delete p;
            size--;
            return true;
        }
        pre = p;
        p = p->next;
    }
    return false;
}

void Coulist::showcourse(){
    //��ʾ���пγ���Ϣ
    Course* p = head->next;
    while(p){
        p->showcourse();
        p = p->next;
    }
}

bool Coulist::findcourse(){
    //���ҿγ���Ϣ
    int choice_1,count = 0;
    string teacherv,collegev,namev;
    cin >> choice_1;//�û�����Ҫ��β��ң�
    switch(choice_1){
        case 1:{
            //���γ̱�Ų���
            cout << "������γ̱��:" << endl;
            int bhv;
            cin >> bhv;
            if(findbh(bhv))
                findbh(bhv)->showcourse();
            else
                return false;
            break;
        }
        case 2:{
            //���γ����Ʋ���
            cout << "������γ�����:" << endl;
            cin >> namev;
            if(!findname(namev))
                return false;
            break;
        }
        case 3:{
            //����ʦ����
            cout << "�������ʦ����:" << endl;
            cin >> teacherv;    
            if(!findteacher(teacherv))
                return false;
            break;
        }
        case 4:{
            //��ѧԺ����
            cout << "������ѧԺ����:" << endl;
            cin >> collegev;
            if(!findcollege(collegev))
                return false;
            break;
        }
        default:{
            //�������
            cout << "�������" << endl;
            return false;
            break;
        }
    }
    return true;
}

bool Coulist::find_and_assesscourse(){
    //���ҿγ���Ϣ������
    int choice_1,assessmentv;
    Course* course;//��ʱ���������ҵ��Ŀγ̣��������溯�����ε���
    cout << "��������Ҫ���ۿγ̵Ŀγ̱��:" << endl;
    int bhv;
    cin >> bhv;
    course = findbh(bhv);
    if(course){
        course->showcourse();
        cout << "��������Ըÿγ̵�����(100����):" << endl;
        while(cin >> assessmentv){
            if(assessmentv >= 0 && assessmentv <= 100)
                break;
            else
                cout << "�����������������" << endl;
        }//��֤�����������0-100֮��
        course->setassessment(assessmentv);
    }
    else{
        return false;
    }
    cout << "���۳ɹ�!���������ۺ�Ŀγ���Ϣ" << endl;
    course->showcourse();
    system("pause");
    return true;
}

bool Coulist::modifycourse(int bhv){
    //�޸Ŀγ���Ϣ
    int bhv2,creditv;
    string namev,teacherv,catagoryv,collegev;
    Course* target = findbh(bhv);
    if(target){
        cout << "�Ѳ�ѯ����ڿΣ������ǿγ���Ϣ��" << endl;
        target->showcourse();
        cout << "�밴����˳������γ���Ϣ���γ̱�� �γ����� �ον�ʦ ѧ�� �γ���� ����ѧԺ(Ϊ��ƽ,���޷��޸Ŀγ̵�����)" << endl;
        cin >> bhv2 >> namev >> teacherv >> creditv >> catagoryv >> collegev;
        target->setbh(bhv2);
        target->setname(namev);
        target->setteacher(teacherv);
        target->setcredit(creditv);
        target->setcatagory(catagoryv);
        target->setcollege(collegev);
        return true;
    }
    else
        return false;
}

Course* Coulist::findbh(int bhv)const{
    // ���γ̱�Ų��ҿγ�
    Course* p = head->next;
    while(p){
        if(p->getbh() == bhv)
            return p;
        p = p->next;
    }
    cout << "���޴˿�" << endl;
    return NULL;
}

bool Coulist::findname(string namev)const{
    //���γ����Ʋ��ҿγ�
    Course* p = head->next;
    int count = 0;
    while(p){
        if(p->getname() == namev){
            p->showcourse();
            count++;
        }
        p = p->next;
    }
    if(count == 0){
        cout << "���޴˿�" << endl;
        return false;
    }
    else
        cout << "�����ҵ�" << count << "�ſγ�" << endl;
    return true;
}

bool Coulist::findteacher(string teacherv)const{
    //����ʦ���ҿγ�
    Course* p = head->next;
    int count = 0;
    while(p){
        if(p->getteacher() == teacherv){
            p->showcourse();
            count++;
        }
        p = p->next;
    }
    if(count == 0){
        cout << "���޴˿�" << endl;
        return false;
    }
    else
        cout << "�����ҵ�" << count << "�ſγ�" << endl;
    return true;
}

bool Coulist::findcollege(string collegev)const{
    //��ѧԺ���ҿγ�
    Course* p = head->next;
    int count = 0;
    while(p){
        if(p->getcollege() == collegev){
            p->showcourse();
            count++;
        }
        p = p->next;
    }
    if(count == 0){
        cout << "���޴˿�" << endl;
        return false;
    }
    else
        cout << "�����ҵ�" << count << "�ſγ�" << endl;
    return true;
}