#include "../hpp/Coulist.hpp"
#include <iostream>
using namespace std;
Coulist::Coulist(){
    head = new Course;
    head->next = NULL;
    size = 0;
}

void Coulist::addcourse(int bhv,string namev,string teacherv,int creditv,string catagoryv,string collegev,int assessmentv){
    Course* p = new Course(bhv,namev,teacherv,creditv,catagoryv,collegev,assessmentv);
    p->next = head;
    head = p;
    size++;
}

bool Coulist::delcourse(int bhv){
    Course *p = head,*pre = NULL;
    while(p->next){
        pre = p;
        if(p->getbh() == bhv){
            pre->next = p->next;
            delete p;
            size--;
            return true;
        }
    }
    return false;
}
void Coulist::showcourse(){
    Course* p = head;
    while(p->next != NULL){
        cout << "�γ̱��:" << p->getbh() << ' ';
        cout << "�γ�����:" << p->getname() << ' ';
        cout << "�γ�����:" << p->getassessment() << ' ';
        cout << "�γ�ѧ��:" << p->getcredit() << ' ';
        cout << "�Ͽν�ʦ:" << p->getteacher() << ' ';
        cout << "����ѧԺ:" << p->getcollege() << endl;
        p = p->next;
    }
}

bool Coulist::findcourse(){
    int choice_1;
    string teacherv,collegev;
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
            string namev;
            cin >> namev;
            if(findname(namev))
                findname(namev)->showcourse();
            else
                return false;
            break;
        }
        case 3:{
            //����ʦ����
            cout << "�������ʦ����:" << endl;
            cin >> teacherv;    
            if(findteacher(teacherv))
                findteacher(teacherv)->showcourse();
            else
                return false;
            break;
        }
        case 4:{
            //��ѧԺ����
            cout << "������ѧԺ����:" << endl;
            cin >> collegev;
            if(findcollege(collegev))
                findcollege(collegev)->showcourse();
            else
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
    int choice_1,assessmentv;
    string teacherv,collegev;
    Course* course;//��ʱ���������ҵ��Ŀγ̣��������溯�����ε���
    cin >> choice_1;//�û�����Ҫ��β��ң�
    switch(choice_1){
        case 1:{
            //���γ̱�Ų���
            cout << "��������Ҫ���ۿγ̵Ŀγ̱��:" << endl;
            int bhv;
            cin >> bhv;
            course = findbh(bhv);
            if(course){
                course->showcourse();
                cout << "��������Ըÿγ̵�����:" << endl;
                cin >> assessmentv;
                course->setassessment(assessmentv);
            }
            else
                return false;
            break;
        }
        case 2:{
            //���γ����Ʋ���
            cout << "��������Ҫ���۵Ŀγ�����:" << endl;
            string namev;
            cin >> namev;
            course = findname(namev);
            if(course){
                course->showcourse();
                cout << "��������Ըÿγ̵�����:" << endl;
                cin >> assessmentv;
                course->setassessment(assessmentv);
            }
            else
                return false;
        }
        case 3:{
            //����ʦ����
            cout << "��������Ҫ���ۿγ̵Ľ�ʦ����:" << endl;
            cin >> teacherv;    
            course = findteacher(teacherv);
            if(course){
                course->showcourse();
                cout << "��������Ըÿγ̵�����:" << endl;
                cin >> assessmentv;
                course->setassessment(assessmentv);
            }
            else
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
    cout << "���۳ɹ�!���������ۺ�Ŀγ���Ϣ" << endl;
    course->showcourse();
    system("pause");
    return true;
}

bool Coulist::modifycourse(int bhv){
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
        system("pause");
        return true;
    }
    else
        return false;
}

Course* Coulist::findbh(int bhv){
    Course* p = head;
    while(p != NULL){
        if(p->getbh() == bhv)
            return p;
        p = p->next;
    }
    cout << size << endl;
    cout << "���޴˿�" << endl;
    return NULL;
}

Course* Coulist::findname(string namev){
    Course* p = head;
    while(p != NULL){
        if(p->getname() == namev)
            return p;
        p = p->next;
    }
    cout << "���޴˿�" << endl;
    return NULL;
}

Course* Coulist::findteacher(string teacherv){
    Course* p = head;
    while(p != NULL){
        if(p->getteacher() == teacherv)
            return p;
        p = p->next;
    }
    cout << "���޴˿�" << endl;
    return NULL;
}

Course* Coulist::findcollege(string collegev){
    Course* p = head;
    while(p != NULL){
        if(p->getcollege() == collegev)
            return p;
        p = p->next;
    }
    cout << "���޴˿�" << endl;
    return NULL;
}