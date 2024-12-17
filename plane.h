//
// Created by 24034 on 24-12-14.
//

#ifndef FLIGHTMANAGESYSTEM_PLANE_H
#define FLIGHTMANAGESYSTEM_PLANE_H

#include <bits/stdc++.h>
using namespace std;

typedef struct plane
{
    int id; // 航班号
    string startCity; // 起飞城市
    string finCity; // 降落城市
    string takeOffTime; // 起飞时间
    string takeTime; // 降落时间
    int site; // 座位数
    int price; // 票价
    struct plane* next; // 结点的指针域
}plane;

extern plane *planelist;

//读取文件
void connectAndFillPlaneList();

#endif //FLIGHTMANAGESYSTEM_PLANE_H
