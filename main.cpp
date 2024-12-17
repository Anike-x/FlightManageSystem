#include <bits/stdc++.h>
#include "user.h"
#include "manager.h"
#include "plane.h"
#include "login.h"

using namespace std;

plane *planelist = nullptr;
user *userist = nullptr;
manager *managerlist = nullptr;

int main() {
    connectAndFillPlaneList();
    int choice;
    while(1){
        cout<<"1.用户"<<endl;
        cout<<"2.管理员"<<endl;
        cout<<"3.退出"<<endl;
        cout<<"请输入你的选择：";
        cin>>choice;
        switch(choice){
            case 1:
                //用户
                checkUser();
                usermenu();
                break;
            case 2:
                //管理员
                checkManager();
                managermenu();
                break;
            case 3:
                return 0;
            default:
                cout<<"输入错误，请重新输入"<<endl;
        }
    }
}