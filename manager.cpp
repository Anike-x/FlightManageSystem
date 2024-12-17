//
// Created by 24034 on 24-12-14.
//

#include "manager.h"
#include "plane.h"
#include "user.h"

void managermenu(){
    int choice;
    while(1){
        cout<<"1.��ѯ������Ϣ"<<endl;
        cout<<"2.��Ӻ�����Ϣ"<<endl;
        cout<<"3.ɾ��������Ϣ"<<endl;
        cout<<"4.�޸ĺ�����Ϣ"<<endl;
        cout<<"5.��ѯ���г˿���Ϣ"<<endl;
        cout<<"6.�˳�"<<endl;
        cout<<"���������ѡ��";
        cin>>choice;
        switch(choice){
            case 1:
                //��ѯ������Ϣ
                searchPlane();
                break;
            case 2:
                //��Ӻ�����Ϣ
                addPlane();
                break;
            case 3:
                //ɾ��������Ϣ
                deletePlane();
                break;
            case 4:
                //�޸ĺ�����Ϣ
                changePlane();
                break;
            case 5:
                //��ѯ�˿���Ϣ
                searchAllUserInfo();
                break;
            case 6:
                system("cls");
                return;
            default:
                cout<<"�����������������"<<endl;
        }
        system("pause");
        system("cls");
    }
}

//��Ӻ�����Ϣ
void addPlane(){
    plane *p;
    p = planelist;
    while(p->next!=NULL){
        p=p->next;
    }
    plane *newPlane = new plane;
    cout<<"�����뺽��ţ�";
    cin>>newPlane->id;
    cout<<"��������ɳ��У�";
    cin>>newPlane->startCity;
    cout<<"�����뽵����У�";
    cin>>newPlane->finCity;
    cout<<"���������ʱ�䣺";
    cin>>newPlane->takeOffTime;
    cout<<"�����뽵��ʱ�䣺";
    cin>>newPlane->takeTime;
    cout<<"��������λ����";
    cin>>newPlane->site;
    cout<<"������Ʊ�ۣ�";
    cin>>newPlane->price;
    p->next = newPlane;
    newPlane->next = NULL;
}

//ɾ��������Ϣ
void deletePlane(){
    int id;
    cout<<"������Ҫɾ���ĺ���ţ�";
    cin>>id;
    plane *p;
    p = planelist;
    while(p->next!=NULL){
        if(p->next->id==id){
            plane *temp = p->next;
            p->next = p->next->next;
            delete temp;
            cout<<"ɾ���ɹ�"<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"û���ҵ��ú���"<<endl;
}

//�޸ĺ�����Ϣ
void changePlane(){
    int id;
    cout<<"������Ҫ�޸ĵĺ���ţ�";
    cin>>id;
    plane *p;
    p = planelist;
    while(p!=NULL){
        if(p->id==id){
            cout<<"�������µĺ���ţ�";
            cin>>p->id;
            cout<<"�������µ���ɳ��У�";
            cin>>p->startCity;
            cout<<"�������µĽ�����У�";
            cin>>p->finCity;
            cout<<"�������µ����ʱ�䣺";
            cin>>p->takeOffTime;
            cout<<"�������µĽ���ʱ�䣺";
            cin>>p->takeTime;
            cout<<"�������µ���λ����";
            cin>>p->site;
            cout<<"�������µ�Ʊ�ۣ�";
            cin>>p->price;
            cout<<"�޸ĳɹ�"<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"û���ҵ��ú���"<<endl;
}

//��ѯ���г˿���Ϣ
void searchAllUserInfo(){
    user *p;
    p = userist;
    while(p!=NULL){
        cout<<"�û�����"<<p->name<<endl;
        cout<<"���룺"<<p->passwd<<endl;
        cout<<"���п��ţ�"<<p->card<<endl;
        p=p->next;
    }
}