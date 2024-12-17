//
// Created by 24034 on 24-12-14.
//

#include "manager.h"
#include "plane.h"
#include "user.h"

void managermenu(){
    int choice;
    while(1){
        cout<<"1.查询航班信息"<<endl;
        cout<<"2.添加航班信息"<<endl;
        cout<<"3.删除航班信息"<<endl;
        cout<<"4.修改航班信息"<<endl;
        cout<<"5.查询所有乘客信息"<<endl;
        cout<<"6.退出"<<endl;
        cout<<"请输入你的选择：";
        cin>>choice;
        switch(choice){
            case 1:
                //查询航班信息
                searchPlane();
                break;
            case 2:
                //添加航班信息
                addPlane();
                break;
            case 3:
                //删除航班信息
                deletePlane();
                break;
            case 4:
                //修改航班信息
                changePlane();
                break;
            case 5:
                //查询乘客信息
                searchAllUserInfo();
                break;
            case 6:
                system("cls");
                return;
            default:
                cout<<"输入错误，请重新输入"<<endl;
        }
        system("pause");
        system("cls");
    }
}

//添加航班信息
void addPlane(){
    plane *p;
    p = planelist;
    while(p->next!=NULL){
        p=p->next;
    }
    plane *newPlane = new plane;
    cout<<"请输入航班号：";
    cin>>newPlane->id;
    cout<<"请输入起飞城市：";
    cin>>newPlane->startCity;
    cout<<"请输入降落城市：";
    cin>>newPlane->finCity;
    cout<<"请输入起飞时间：";
    cin>>newPlane->takeOffTime;
    cout<<"请输入降落时间：";
    cin>>newPlane->takeTime;
    cout<<"请输入座位数：";
    cin>>newPlane->site;
    cout<<"请输入票价：";
    cin>>newPlane->price;
    p->next = newPlane;
    newPlane->next = NULL;
}

//删除航班信息
void deletePlane(){
    int id;
    cout<<"请输入要删除的航班号：";
    cin>>id;
    plane *p;
    p = planelist;
    while(p->next!=NULL){
        if(p->next->id==id){
            plane *temp = p->next;
            p->next = p->next->next;
            delete temp;
            cout<<"删除成功"<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"没有找到该航班"<<endl;
}

//修改航班信息
void changePlane(){
    int id;
    cout<<"请输入要修改的航班号：";
    cin>>id;
    plane *p;
    p = planelist;
    while(p!=NULL){
        if(p->id==id){
            cout<<"请输入新的航班号：";
            cin>>p->id;
            cout<<"请输入新的起飞城市：";
            cin>>p->startCity;
            cout<<"请输入新的降落城市：";
            cin>>p->finCity;
            cout<<"请输入新的起飞时间：";
            cin>>p->takeOffTime;
            cout<<"请输入新的降落时间：";
            cin>>p->takeTime;
            cout<<"请输入新的座位数：";
            cin>>p->site;
            cout<<"请输入新的票价：";
            cin>>p->price;
            cout<<"修改成功"<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"没有找到该航班"<<endl;
}

//查询所有乘客信息
void searchAllUserInfo(){
    user *p;
    p = userist;
    while(p!=NULL){
        cout<<"用户名："<<p->name<<endl;
        cout<<"密码："<<p->passwd<<endl;
        cout<<"银行卡号："<<p->card<<endl;
        p=p->next;
    }
}