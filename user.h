//
// Created by 24034 on 24-12-14.
//

#ifndef FLIGHTMANAGESYSTEM_USER_H
#define FLIGHTMANAGESYSTEM_USER_H

#include <bits/stdc++.h>
#include "plane.h"
using namespace std;

typedef struct user
{
    string name;
    string passwd;
    string card;
    plane *userorder;
    struct user *next;//结点的指针域
}user;//乘客信息

extern user *userist;
extern plane *planeOrder;

void usermenu();
void connectAndFillUserList();
void searchMyPlane();
void orderTicket();
void returnTicket();
void searchUserInfo();
void changeUserInfo();

#endif //FLIGHTMANAGESYSTEM_USER_H
