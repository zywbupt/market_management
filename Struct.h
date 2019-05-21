//
//  Struct.h
//  XiaoXueQi
//  此文件包含程序所需所有结构体，以供统一调用
//  Created by 孙卿皓 2016213248 on 17/9/12.
//  Copyright © 2017年 孙卿皓 2016213248. All rights reserved.
//

#ifndef Struct_h
#define Struct_h

struct Cust {                  //顾客数据的结构体
    char ID[11];               //10位数字,下一个结构体同
    char password[11];         //10位数字
    char name[20];
    int sex;                   //man->1    woman->0
    char phone[12];
    char mail[40];
    char address[60];
    float money;               //用户余额
    struct Cust * next;
};

struct Adminif {               //管理员数据的结构体
    char ID[11];
    char password[11];
    char name[20];
    char phone[12];
    char shop[20];
    char mail[40];
    struct Adminif * next;
};

struct Goods {                 //商品数据的结构体
    char goodsNO[7];
    float off;                 //如：七折0.7
    char startTime[17];        //yyyy:mm:dd:hh:mm
    char endTime[17];
    float sellPrice;           //售价
    float inPrice;             //进价
    int restAmount;
    int sellAmount;
    char description[50];      //商品名
    char clasification[60];    //商品分类
    char shop[20];
    struct Goods * next;
};

struct Order {                 //订单数据的结构体
    char orderNO[30];
    char date[17];
    char name[30];             //用户姓名
    int amount;
    float oneprice;            //商品单价
    float price;
    char shop[20];
    char goodsNO[7];
    struct Order * next;
};

#endif /* Struct_h */
