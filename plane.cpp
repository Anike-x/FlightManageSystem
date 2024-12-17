//
// Created by 24034 on 24-12-15.
//
#include "plane.h"

void connectAndFillPlaneList(){
    planelist = new plane;
    planelist->next = nullptr;
    plane *p = planelist;
    ifstream fin("D:\\CLion\\projects\\FlightManageSystem\\plane.txt");
    if (!fin.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }
    while (true) {
        auto *newPlane = new plane;
        if (!(fin >> newPlane->id
                  >> newPlane->startCity
                  >> newPlane->finCity
                  >> newPlane->takeOffTime
                  >> newPlane->takeTime
                  >> newPlane->site
                  >> newPlane->price)) {
            delete newPlane;  // 释放内存
            break;            // 退出循环
        }
        p->next = newPlane;
        newPlane->next = nullptr;
        p = newPlane;
    }
    fin.close();
}