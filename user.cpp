//
// Created by 24034 on 24-12-14.
//

#include "user.h"
#include "plane.h"

void usermenu(){
    int choice;
    while(1){
        cout<<"1.查询航班信息"<<endl;
        cout<<"2.订票"<<endl;
        cout<<"3.退票"<<endl;
        cout<<"4.查询个人信息"<<endl;
        cout<<"5.修改个人信息"<<endl;
        cout<<"6.退出"<<endl;
        cout<<"请输入你的选择：";
        cin>>choice;
        switch(choice){
            case 1:
                //查询航班信息
                searchMyPlane();
                break;
            case 2:
                //订票
                orderTicket();
                break;
            case 3:
                //退票
                returnTicket();
                break;
            case 4:
                //查询个人信息
                searchUserInfo();
                break;
            case 5:
                //修改个人信息
                changeUserInfo();
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

void connectAndFillUserList() {
    userist = new user;
    userist->next = nullptr;
    user* p = userist;
    ifstream fin("D:\\CLion\\projects\\FlightManageSystem\\user.txt");
    if (!fin.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }
    while (true) {
        auto* newUser = new user;
        if (!(fin >> newUser->name
                  >> newUser->passwd
                  >> newUser->card)) {
            delete newUser;  // Release memory
            break;           // Exit loop
        }
        p->next = newUser;
        newUser->next = nullptr;
        p = newUser;
    }
    fin.close();
}

//查询航班信息
void searchMyPlane(){
    plane *p;
    p = planeOrder;
    while(p!=NULL){
        cout<<"航班号："<<p->id<<endl;
        cout<<"起飞城市："<<p->startCity<<endl;
        cout<<"降落城市："<<p->finCity<<endl;
        cout<<"起飞时间："<<p->takeOffTime<<endl;
        cout<<"降落时间："<<p->takeTime<<endl;
        cout<<"座位数："<<p->site<<endl;
        cout<<"票价："<<p->price<<endl;
        cout<<endl;
        p=p->next;
    }
}

//订票
void orderTicket(){
    int id;
    cout<<"请输入航班号：";
    cin>>id;
    plane *p;
    p = planelist;
    while(p!=NULL){
        if(p->id==id){
            if(p->site>0){
                p->site--;
                cout<<"订票成功"<<endl;
            }else{
                cout<<"座位已满"<<endl;
            }
            return;
        }
        p=p->next;
    }
    cout<<"没有找到该航班"<<endl;
}

//退票
void returnTicket(){
    int id;
    cout<<"请输入航班号：";
    cin>>id;
    plane *p;
    p = planelist;
    while(p!=NULL){
        if(p->id==id){
            p->site++;
            cout<<"退票成功"<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"没有找到该航班"<<endl;
}

//查询个人信息
void searchUserInfo(){
    //输入自己的姓名和密码
    string name;
    cout<<"请输入你的姓名：";
    cin>>name;
    user *p;
    p = userist;
    while(p!=NULL){
        if(p->name == name){
            cout<<"姓名："<<p->name<<endl;
            cout<<"密码："<<p->passwd<<endl;
            cout<<"身份证号："<<p->card<<endl;
            return;
        }
        p=p->next;
    }
}

//修改个人信息
void changeUserInfo() {
    user *p;
    p = userist;
    string name;
    cout << "请输入你的姓名：";
    cin >> name;
    while (p != NULL) {
        if (p->name == name) {
            cout << "请输入新密码：";
            cin >> p->passwd;
            cout << "请输入新身份证号：";
            cin >> p->card;
            cout << "修改成功" << endl;
            return;
        }
        p = p->next;
    }
    cout << "没有找到该用户" << endl;
}
