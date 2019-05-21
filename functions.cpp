//
//  functions.cpp
//  XiaoXueQi
//  为functions.h中函数定义的解释性.cpp文件
//  Created by 张瀚文 2016213259 on 17/9/12.
//  Copyright © 2017年 张瀚文 2016213259. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
#include "Struct.h"
#include "functions.h"

using namespace std;

extern int login();
extern int manage();
extern int logsign;

struct Goods *data;
struct Goods *singleGood;

extern struct Goods *goodshead;
extern struct Goods *newhead;
extern struct Cust *custshead;
extern struct Cust *newcustshead;
extern struct Goods adm;

int functions::option(int out) {                               //此函数根据不同需求选择界面并输入，返回值为其它函数的操作
    
    int choise;
    
    switch(out) {
            
        case 0:                                                //Groceries()的输出
            system("clear");
            cout<<"(1) For you\n"
            <<"(2) Search\n"
            <<"(3) All goods\n"
            <<"What do you want to do?\n"
            <<"(9) Back           (0)Customer centre"<<endl;
            break;
            
        case 1:                                                //forYou()的输出
            system("clear");
            cout<<"Recommend by(top 10):\n"
            <<"\n(1) Price\n"
            <<"(2) salesamount\n"
            <<"(3) Intergration\n"
            <<"What do you want to do?\n"
            <<"(9) Back           (0)Customer centre"<<endl;
            break;
            
        case 2:                                                //search()的输出
            system("clear");
            cout<<"Search by:\n"
            <<"\n(1) Name\n"
            <<"(2) Shop\n"
            <<"What do you want to do?\n"
            <<"(9) Back           (0)Customer centre"<<endl;
            break;
            
        case 3:                                                //allGoods()的输出
            system("clear");
            cout<<"Sequenced by:\n"
            <<"\n(1) Price\n"
            <<"(2) Sales amount\n"
            <<"What do you want to do?\n"
            <<"(9) Back           (0)Customer centre"<<endl;
            break;
    }
    
    for(;;) {                                                  //防止误输
        cin>>choise;
        if(choise<0||(choise>3&&choise<9)||(choise==3&&out==3)||choise>9)
            cout<<"Please input the right numbers only!\n\n"
            <<"Input again:";
        else
            break;
    }
    cout<<endl;
    
    return choise;
}

struct Goods *functions::openLink() {                                 //创建链表的函数，用于商品排序，返回值为链表的头指针
    
    fstream goodsfile;
    goodsfile.open("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Goods.txt",ios::in);
    
    if(!goodsfile.is_open()) {
        cerr<<"Error when opening the file!"<<endl;
        return NULL;
    }
    
    struct Goods *g1,*g2,*g3=nullptr;
    //extern struct Goods *goodshead;
    char message[1024];
    
    g1=new struct Goods;                                              //申请新内存
    
    goodsfile.getline(message,1024,'\n');
    sscanf(message,"%s %f %s %s %f %f %d %d %s %s %s",
           g1->goodsNO,&g1->off,g1->startTime,g1->endTime,
           &g1->sellPrice,&g1->inPrice,&g1->restAmount,
           &g1->sellAmount,g1->description,
           g1->clasification,g1->shop);                        //将一行赋与结构体

    if(!goodsfile.eof()) {                             //当g1不指向空时，执行操作
        
        goodshead=g1;
        while(!goodsfile.eof()) {
            
            g2=new struct Goods;
            g1->next=g2;
            g3=g1;
            
            goodsfile.getline(message,1024,'\n');
            sscanf(message,"%s %f %s %s %f %f %d %d %s %s %s",
                   g2->goodsNO,&g2->off,g2->startTime,g2->endTime,
                   &g2->sellPrice,&g2->inPrice,&g2->restAmount,
                   &g2->sellAmount,g2->description,
                   g2->clasification,g2->shop);
            
            g1=g2;
        }
        
        g3->next=NULL;
    }
    else
        goodshead=NULL;                                             //否则头指针为空
    
    goodsfile.close();
    
    return goodshead;                                               //返回头指针
}

struct Cust *functions::openCustLink() {
    
    fstream custfile;
    custfile.open("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Custer.txt",ios::in);
    
    if(!custfile.is_open()) {
        cerr<<"Error when opening the file!"<<endl;
        return NULL;
    }
    
    struct Cust *c1,*c2,*c3=nullptr,*head=NULL;
    char message[1024];
    
    c1=new struct Cust;                                               //申请新内存
    
    custfile.getline(message,1024,'\n');
    
    sscanf(message,"%s %s %s %d %s %s %s %f",
           c1->ID,c1->password,c1->name,&c1->sex,
           c1->phone,c1->mail,c1->address,&c1->money);         //将一行赋与结构体
    
    if(custfile.eof()) {                                  //当g1不指向空时，执行操作
        
        head=c1;
        while(custfile.eof()) {
            
            c2=new struct Cust;
            c1->next=c2;
            c3=c1;
            
            char getw;
            do {
                getw=cin.get();
                strcat(message,&getw);
            } while(getw!='\n');
            
            sscanf(message,"%s %s %s %d %s %s %s %f",
                   c1->ID,c1->password,c1->name,&c1->sex,
                   c1->phone,c1->mail,c1->address,&c1->money);
            c1=c2;
        }
        
        c3->next=NULL;
    }
    else
        head=NULL;                                             //否则头指针为空
    
    custfile.close();
    
    return head;                                               //返回头指针
}


 
void functions::deleteLink(struct Goods *data) {
    
    struct Goods *g1=goodshead,*g2=nullptr;
    bool count=false;
    
    while(g1!=NULL) {
        
        if((!strcmp(g1->goodsNO,data->goodsNO))&&(g1==goodshead)) {          //比较是否为头指针
            if(goodshead->next==NULL)
                goodshead=NULL;
            else
                goodshead=g1->next;                                            //指向下一个
            break;
        }
        else if((!strcmp(g1->goodsNO,data->goodsNO))&&(g1->next==NULL)) {
            
            if(count)                                                        //g2是否为g1上一个
                g2->next=NULL;
            else
                goodshead->next=NULL;
            break;
        }
        else {
            
            if(strcmp(g1->goodsNO,data->goodsNO)) {
                
                g2=g1;
                g1=g1->next;
            }
            else {
                g2->next=g1->next;
                break;
            }
            count=true;                                     //根据布尔值来判断执行情况
        }
    }
}

void functions::deleteManagerLink(struct Goods *data) {    //删除节点，供管理员调用
    
    struct Goods *g1=goodshead,*g2=nullptr;
    bool count=false;
    
    while(g1!=NULL) {
        
        if((!strcmp(g1->goodsNO,data->goodsNO))&&(g1==goodshead)) {
            if(goodshead->next==NULL)
                goodshead=NULL;
            else
                goodshead=g1->next;
            break;
        }
        else if((!strcmp(g1->goodsNO,data->goodsNO))&&(g1->next==NULL)) {
            
            if(count)                                                        //g2是否为g1上一个
                g2->next=NULL;
            else
                goodshead->next=NULL;
            break;
        }
        else {
            
            if(strcmp(g1->goodsNO,data->goodsNO)) {
                
                g2=g1;
                g1=g1->next;                       //指向下一个
            }
            else {
                g2->next=g1->next;
                break;
            }
            count=true;         //同上
        }
    }
}

/*
void functions::deleteRestLink(struct Goods *goodshead,struct Goods *data) {
    
    struct Goods *g1=goodshead,*g2=nullptr;
    
    while(g1!=NULL) {
        
        if((g1->restAmount==data->restAmount)&&(g1==goodshead))
        {
            goodshead=g1->next;
            break;
        }
        else if((g1->restAmount==data->restAmount)&&(g1->next==NULL))
        {
            g1=NULL;
        }
        else
        {
            if(g1->restAmount!=data->sellAmount)
            {
                g2=g1;
                g1=g1->next;
            }
            else
            {
                g2->next=g1->next;
                break;
            }
        }
    }
}
*/

void functions::deleteCustLink(struct Cust *data) {         //判断登录时的删除节点
    
    struct Cust *c1=custshead,*c2=nullptr;
    bool count=false;
    
    while(c1!=NULL) {
        
        if((!strcmp(c1->ID,data->ID))&&(c1==custshead)) {
            if(custshead->next==NULL)
                custshead=NULL;
            else
                custshead=c1->next;
            break;
        }
        else if((!strcmp(c1->ID,data->ID))&&(c1->next==NULL)) {
            
            if(count)                                                        //c2是否为c1上一个
                c2->next=NULL;
            else
                custshead->next=NULL;
            break;
        }
        else {
            
            if(strcmp(c1->ID,data->ID)) {
                
                c2=c1;
                c1=c1->next;                  //移动指针，指向下一个
            }
            else {
                c2->next=c1->next;
                break;
            }
            count=true;
        }
    }
}

/*
void functions::freelink(struct Goods *head) {
    struct Goods *g1=head,*g2;
    while(g1!=NULL) {
        
        g2=g1->next;
        delete g1;
        g1=g2;
    }
    delete g1;
}
*/

struct Goods *functions::forYou() {       //推荐板块的函数，参数为头指针，返回值为用户所需商品,NULL为返回
    
    switch(option(1)) {
        case 1:  newhead=functions::priceRank();break;      //根据价格高低创建一个有20个元素的新链表，并返回头指针
        case 2:  newhead=functions::amountRank();break;     //根据销量创建一个有20个元素的新链表，并返回头指针
        case 3:  newhead=functions::interRank();break;      //基于以上两个进行加权排序并创建一个有20个元素的新链表，并返回头指针
        case 0:
            if(logsign==2)
                manage();
            else
                logsign=login();                               //当执行完此步骤后，返回NULL，因此不需要break;
        case 9:  return NULL;
    }
    return newhead;
}

struct Goods *functions::search() {       //搜索板块的函数，参数为头指针，返回值为用户所需商品,NULL为返回
    
    switch(option(2)) {
        case 1:  newhead=functions::nameSearch();break;     //创建一个包含所有相同商品名称的新链表，并返回头指针
        case 2:  newhead=functions::shopSearch();break;     //创建一个包含所有相同店铺名称的新链表，并返回头指针
        case 0:
            if(logsign==2)
                manage();
            else
                logsign=login();                               //当执行完此步骤后，返回NULL，因此不需要break;
        case 9:  return NULL;
    }
    return newhead;
}

struct Goods *functions::allGoods() {     //浏览所有商品的函数，参数为头指针，返回值为用户所需商品,NULL为返回
    
    switch(option(3)) {
        case 1:  newhead=functions::priceSequence();break;  //基于价格创建一个包含所有商品的新链表，并返回头指针
        case 2:  newhead=functions::amountSequence();break; //基于销量创建一个包含所有商品的新链表，并返回头指针
        case 0:
            if(logsign==2)
                manage();
            else
                logsign=login();                               //当执行完此步骤后，返回NULL，因此不需要break;
        case 9:  return NULL;
    }
    return newhead;
}

struct Goods *functions::amountSequence() { //基于销量创建一个包含所有商品的链表

    struct Goods *temp;
    extern struct Goods *data;
    temp=new struct Goods;
    newhead=new struct Goods;          //kaipiyikuaineicunkongjian
    
    while(goodshead!=NULL) {
        
        *temp=*goodshead;                        //移动法：1.找出匹配项 2.匹配项连接至新链表 3.删除旧链表中的匹配项 4.重复直到旧链表为空
        data=functions::compareAmount(temp);
        functions::linkUp();
        functions::deleteLink(temp);
        if(goodshead->next==NULL)
            break;
    }
    return newhead;
}

struct Goods *functions::shopSearch() {
    
    struct Goods *temp;
    temp=new struct Goods;
    newhead=new struct Goods;
    
    cout<<"Please input the name of the shop:"<<endl;      //询问是否按折扣购买
    char sh[20];
    cin>>sh;
    
    cout<<"Do you want those with discount only?  (y/n)"<<endl;
    char ch;
    for(;;) {
        cin>>ch;
        if(ch!='y'&&ch!='n')
            cout<<"Please input y or n only!"<<endl;
        else
            break;
    }
    
    while(goodshead!=NULL) {
        
        *temp=*goodshead;                         //移动法：1.找出匹配项 2.匹配项连接至新链表 3.删除旧链表中的匹配项 4.重复直到旧链表为空
        strcpy(temp->shop,sh);
        data=functions::shopMatch(temp,ch);
        functions::linkUp();
        functions::deleteLink(data);
        if(!strcmp(data->goodsNO,"\0"))
            break;
    }
    if(!strcmp(newhead->shop,"\0"))
        cout<<"The shop does not exist!"<<endl;
    
    return newhead;                             //全局变量，故此处返回值不起作用
}

struct Goods *functions::nameSearch() {
    
    struct Goods *temp;
    temp=new struct Goods;                   //搜索商品名字
    newhead=new struct Goods;
    
    cout<<"Please input the name:"<<endl;
    char nm[20];
    cin>>nm;
    
    cout<<"Do you want those with discount only?  (y/n)"<<endl;
    
    char ch;
    for(;;) {
        cin>>ch;
        
        if(ch!='y'&&ch!='n')
            cout<<"Please input y or n only!"<<endl;
        else
            break;
    }
    
    while(goodshead!=NULL) {
        
        *temp=*goodshead;                      //移动法：1.找出匹配项 2.匹配项连接至新链表 3.删除旧链表中的匹配项 4.重复直到旧链表为空
        strcpy(temp->description,nm);
        data=functions::nameMatch(temp,ch);
        functions::linkUp();
        functions::deleteLink(data);
        if(!strcmp(data->goodsNO,"\0"))
            break;
    }
    
    if(!strcmp(newhead->description,"\0"))             //报错
        cout<<"The name does not exist!"<<endl;
    
    return newhead;
}

struct Goods *functions::print() {             //打印链表并选择
    
    struct Goods *g1=newhead;
    singleGood= new struct Goods;
    
    int serial=1;
    
    system("clear");
    cout<<setw(12)<<"goodsNO"<<setw(8)<<"name"<<setw(12)
    <<"sellPrice"<<setw(11)<<"discount"<<setw(21)<<"discount start time"
    <<setw(19)<<"discount end time"<<setw(8)<<"shop\n"<<endl;                //输入开头部分
        
    for(;g1->next!=NULL;serial++) {                                    //输入数据
        cout<<'('<<setw(2)<<serial<<')'<<setw(8)<<g1->goodsNO<<setw(8)
        <<g1->description<<setw(12)<<g1->sellPrice<<setw(11)
        <<g1->off<<setw(21)<<g1->startTime<<setw(19)<<g1->endTime
        <<setw(7)<<g1->shop<<endl;
        g1=g1->next;
    }
        
    cout<<"\nWhich one do you want to choose?"<<endl                    //提示
    <<"(0) Back      (100)Customer centre"<<endl;
        
    int getn;
    for(;;) {
        
        cin>>getn;
            
        if(getn<0||(getn>serial&&getn!=100))
            cout<<"Please input the right code only!"<<endl;
        else
            break;
    }
        
    if(getn==0)
            
        return NULL;
        
    else if(getn==100) {
        
        if(logsign==2)
            manage();                //非选择商品的输入项
        else
            login();
    }
        
    else {
        g1=newhead;
        for(int check=1;check<getn;check++) {
                
            struct Goods *g2;
            g2=g1->next;                          //移动指针到要返回处
            g1=g2;
                
            if(g1->next==NULL) {
                cout<<"The good does not exit!"<<endl;
                return NULL;
            }
        }
        singleGood=g1;
        singleGood->next=NULL;                           //返回指针
    }
    cout<<"You chose "<<singleGood->goodsNO<<endl<<endl;
    
    return singleGood;
}

struct Goods *functions::printManager(int a) {               //此处注释上同
    
    extern Goods *goodshead;
    if(a==0||a==2)
        newhead=amountSequence();
    else if(a==1)
        newhead=priceSequence();
    else if(a==3) {
        cout<<"No supplyment is needed!"<<endl;
        return NULL;
    }
    struct Goods *g1=newhead;
    
    int serial=1;
    
    cout<<setw(12)<<"goodsNO"<<setw(8)<<"name"<<setw(12)
    <<"sellPrice"<<setw(11)<<"discount"<<setw(21)<<"discount start time"
    <<setw(19)<<"discount end time"<<setw(8)<<"shop\n"<<endl;
    
    for(;g1->next!=NULL;serial++) {
        cout<<'('<<setw(2)<<serial<<')'<<setw(8)<<g1->goodsNO<<setw(8)
        <<g1->description<<setw(12)<<g1->sellPrice<<setw(11)
        <<g1->off<<setw(21)<<g1->startTime<<setw(19)<<g1->endTime
        <<setw(7)<<g1->shop<<endl;
        g1=g1->next;
    }
    
    cout<<"\n(0) Back"<<endl;
    
    int getn;
    for(;;) {
        
        cin>>getn;
        
        if(getn!=0)
            cout<<"Please input the right code only!"<<endl;
        else
            break;
    }
    return NULL;
}

int functions::sameNameCheck(char ID[11]) {
    
    struct Cust *newhead=NULL,*temp,*dat;
    temp=new struct Cust;
    
    strcpy(temp->ID,ID);
    
    newhead=new struct Cust;

    custshead=openCustLink();
    
    while(custshead!=NULL) {
        
        *temp=*custshead;
        dat=functions::IDMatch(temp);
        functions::linkCustUp(dat);                         //移动法：1.找出匹配项 2.匹配项连接至新链表 3.删除旧链表中的匹配项 4.重复直到旧链表为空
        functions::deleteCustLink(dat);
        if(custshead==NULL)
            break;
    }
    
    if(!strcmp(newhead->ID,"\0"))
        return 0;
    else
        return 1;
}

void functions::amountSequenceInSameStore() {

    goodshead=functions::openLink();                        //移动法：1.找出匹配项 2.匹配项连接至新链表 3.删除旧链表中的匹配项 4.重复直到旧链表为空
    newhead=functions::singleShop();
    goodshead=functions::printManager(0);

    cout<<"Press any key to continue"<<endl;
    char ch;
    cin>>ch;
}

void functions::businessSequenceInSameStore() {
    
    goodshead=functions::openLink();                          //移动法：1.找出匹配项 2.匹配项连接至新链表 3.删除旧链表中的匹配项 4.重复直到旧链表为空
    newhead=functions::singleShop();
    newhead=functions::printManager(1);

    
    cout<<"Press any key to continue"<<endl;;
    char ch;
    cin>>ch;
}

void functions::marginsSequenceInSameStore() {

    newhead=functions::openLink();                         //移动法：1.找出匹配项 2.匹配项连接至新链表 3.删除旧链表中的匹配项 4.重复直到旧链表为空
    newhead=functions::singleShop();
    newhead=functions::printManager(2);
    
    cout<<"Press any key to continue"<<endl;;
    char ch;
    cin>>ch;
}

void functions::supplySequenceInSameStore() {
    
    newhead=functions::openLink();                          //移动法：1.找出匹配项 2.匹配项连接至新链表 3.删除旧链表中的匹配项 4.重复直到旧链表为空
    newhead=functions::singleShop();
    newhead=functions::printManager(3);
    
    cout<<"Press any key to continue"<<endl;;
    char ch;
    cin>>ch;
}

struct Goods *functions::priceSequence() {
    
    struct Goods *temp;
    extern struct Goods *data;
    temp=new struct Goods;
    newhead=new struct Goods;
    
    while(goodshead!=NULL) {

        *temp=*goodshead;                              //移动法：1.找出匹配项 2.匹配项连接至新链表 3.删除旧链表中的匹配项 4.重复直到旧链表为空
        data=functions::comparePrice(temp);
        functions::linkUp();
        functions::deleteLink(temp);
        if(goodshead->next==NULL)
            break;
    }
    return newhead;
}

struct Goods *functions::interSequence() {
    
    struct Goods *temp;
    extern struct Goods *data;
    temp=new struct Goods;
    
    newhead=new struct Goods;
    
    while(goodshead!=NULL) {
        
        *temp=*goodshead;                             //移动法：1.找出匹配项 2.匹配项连接至新链表 3.删除旧链表中的匹配项 4.重复直到旧链表为空
        temp->sellPrice=(goodshead->sellPrice+goodshead->sellAmount)/2;
        data=functions::compareInter(temp);
        functions::linkUp();
        functions::deleteLink(temp);
        if(goodshead->next==NULL)
            break;
    }
    return newhead;
}

struct Goods *functions::compareAmount(struct Goods *temp) {
    
    struct Goods *g1=goodshead,*g2=nullptr;
    extern struct Goods *data;
    data=new struct Goods;
    
    while (g1!=NULL) {
        
        if(temp->sellAmount<=g1->sellAmount)               //通过销量扫描链表并找到最大值
            *temp=*g1;
        
        g2=g1->next;
        g1=g2;
    }
    *data=*temp;
    
    return data;
}

struct Goods *functions::comparePrice(struct Goods *temp) {             //通过价格扫描链表并找到最大值
    
    struct Goods *g1=goodshead,*g2=nullptr;
    extern struct Goods *data;
    data=new struct Goods;
    
    while (g1!=NULL) {
        
        if(temp->sellPrice<=g1->sellPrice)
            *temp=*g1;
        
        g2=g1->next;
        g1=g2;
    }
    
    *data=*temp;
    
    return data;
}

struct Goods *functions::compareInter(struct Goods *temp) {              //综合排序扫描链表并找到最大值
    
    struct Goods *g1=goodshead,*g2=nullptr;
    extern struct Goods *data;
    data=new struct Goods;
    
    while (g1!=NULL) {
        
        if(temp->sellPrice<=(g1->sellPrice+g1->sellAmount)/2) {
            *temp=*g1;
            temp->sellPrice=(g1->sellPrice+g1->sellAmount)/2;
        }
        g2=g1->next;
        g1=g2;
    }
    *data=*temp;
    
    return data;
}

struct Goods * functions::amountRank() {
    
    struct Goods *g1=nullptr,*g2,*g3,*g4;
    newhead=amountSequence();
    g3=newhead;
                                                                  //将销量最大的前十个重新排序组合成新链表
    for(int i=0;g3!=NULL&&i<20;i++) {
        if(i==0)
            g1=new struct Goods;
        
        *g1=*g3;
        g4=g3->next;
        g3=g4;
        
        g2=new struct Goods;
        g2=g1->next;
        g1=g2;
    }
    newhead=g1;
    
    return newhead;
}

struct Goods * functions::priceRank() {
    
    struct Goods *g1=nullptr,*g2,*g3,*g4;                      //将价格最小的前十个重新排序组合成新链表
    newhead=priceSequence();
    g3=newhead;

    
    for(int i=0;g3!=NULL&&i<20;i++) {
        if(i==0)
            g1=new struct Goods;
        
        *g1=*g3;
        g4=g3->next;
        g3=g4;
        
        g2=new struct Goods;
        g2=g1->next;
        g1=g2;
    }
    newhead=g1;
    
    return newhead;
}

struct Goods * functions::interRank() {
    
    struct Goods *g1=nullptr,*g2,*g3,*g4;
    newhead=interSequence();
    g3=newhead;                                              //将综合排序前十个重新排序组合成新链表

    
    for(int i=0;g3!=NULL&&i<20;i++) {
        if(i==0)
            g1=new struct Goods;
        
        *g1=*g3;
        g4=g3->next;
        g3=g4;
        
        g2=new struct Goods;
        g2=g1->next;
        g1=g2;
    }
    newhead=g1;
    
    return newhead;
}


struct Goods *functions::nameMatch(struct Goods *temp,char ch) {
    
    struct Goods *g1=goodshead,*g2=nullptr;
    extern struct Goods *data;
    data=new struct Goods;
    
    while(g1!=NULL) {
        
        if(ch=='n'){
            
            if(!strcmp(g1->description,temp->description))
                *data=*g1;
         
            g2=g1->next;
            g1=g2;
        }
        else {
            
            if(!strcmp(g1->description,temp->description)&&g1->off!=1.0)
                *data=*g1;
                
                g2=g1->next;
                g1=g2;
        }
    }
    return data;
}

struct Goods *functions::shopMatch(struct Goods *temp,char ch) {
    
    struct Goods *g1=goodshead,*g2=nullptr;
    data=new struct Goods;
    
    while(g1!=NULL) {
        
        if(ch=='n'){
            
            if(!strcmp(g1->shop,temp->shop))
                *data=*g1;
            
            g2=g1->next;
            g1=g2;
        }
        else {
            
            if(!strcmp(g1->shop,temp->shop)&&g1->off!=1.0)
                *data=*g1;
            
            g2=g1->next;
            g1=g2;
        }
    }
    return data;
}

struct Goods *functions::shopMatch2(struct Goods *temp) {
    
    struct Goods *g1=goodshead,*g2=nullptr;
    data=new struct Goods;
    
    while(g1!=NULL) {
        
        if(strcmp(g1->shop,temp->shop))
            *data=*g1;
            
        g2=g1->next;
        g1=g2;
        
    }
    return data;
}

struct Cust*functions::IDMatch(struct Cust *temp) {
    struct Cust *g1=custshead,*g2=nullptr,*data;
    data=new struct Cust;
    
    while(g1!=NULL) {
        
        if(!strcmp(g1->ID,temp->ID)) {
            *data=*g1;
            break;
        }
        else {
            while(strcmp(g1->ID,temp->ID)) {
                g2=g1->next;
                g1=g2;
            }
            *data=*g1;
        }
    }
    return data;
}

void functions::linkUp() {
    
    struct Goods *g1,*g2,*g3=nullptr;
    g3=new struct Goods;
    g1=newhead;
    
    if(!strcmp(newhead->goodsNO,"\0")) {
        *newhead=*data;
        newhead->next=NULL;
    }
    else {
        while(g1->next!=NULL) {
            g2=g1->next;
            g1=g2;
        }
        g1->next=g3;
        *g3=*data;
        g3->next=NULL;
    }
}

void functions::linkManagerUp() {
    
    struct Goods *g1,*g2,*g3=nullptr;
    g3=new struct Goods;
    g1=newhead;
    
    if(!strcmp(newhead->shop,"\0")) {
        *newhead=*data;
        newhead->next=NULL;
    }
    else {
        while(g1->next!=NULL) {
            g2=g1->next;
            g1=g2;
        }
        g1->next=g3;
        *g3=*data;
        g3->next=NULL;
    }
}

void functions::linkCustUp(struct Cust * dat) {
    
    struct Cust *c1,*c2,*c3=nullptr;
    c2=new struct Cust;
    c1=newcustshead;
    
    if(!strcmp(newcustshead->ID,"\0")) {
        *newcustshead=*dat;
        newcustshead->next=NULL;
    }
    else {
        while(c1->next!=NULL) {
            c2=c1->next;
            c1=c2;
        }
        c1->next=c3;
        *c3=*dat;
        c3->next=NULL;
    }
}

/*
void functions::nameDeleteLink(struct Goods *goodshead,struct Goods *data) {
    
    struct Goods *g1=goodshead,*g2=nullptr;
    
    while(g1!=NULL) {
        
        if(!strcmp(g1->description,data->description)&&(g2!=NULL)) {
            goodshead=g1->next;
            break;
        }
        else if(!strcmp(g1->description,data->description)&&(g2==NULL)) {
            g1=NULL;
            goodshead=NULL;
        }
        else
            goodshead=NULL;
    }
}

void functions::shopDeleteLink(struct Goods *goodshead,struct Goods *data) {
    
    struct Goods *g1=goodshead,*g2=nullptr;
    
    while(g1!=NULL) {
        
        if(!strcmp(g1->shop,data->shop)&&(g2!=NULL)) {
            goodshead=g1->next;
            break;
        }
        else if(!strcmp(g1->shop,data->shop)&&(g2==NULL)) {
            g1=NULL;
            goodshead=NULL;
        }
        else
            goodshead=NULL;
    }
}
*/

struct Goods *functions::businessSequence() {
    
    struct Goods *temp;
    extern struct Goods *data;
    temp=new struct Goods;
    newhead=new struct Goods;
    
    while(newhead!=NULL) {
        
        *temp=*newhead;                                           //移动法：1.找出匹配项 2.匹配项连接至新链表 3.删除旧链表中的匹配项 4.重复直到旧链表为空
        temp->sellAmount=newhead->sellAmount*newhead->sellPrice;
        data=functions::compareBusiness(temp);
        functions::linkManagerUp();
        functions::deleteLink(temp);
        if(goodshead->next==NULL)
            break;
    }
    return newhead;
}

struct Goods *functions::marginsSequence() {
    
    struct Goods *temp;
    extern struct Goods *data;
    temp=new struct Goods;
    newhead=new struct Goods;
    
    while(goodshead!=NULL) {
        
        *temp=*newhead;
        temp->sellAmount=newhead->sellAmount*(newhead->sellPrice-newhead->inPrice);
        data=functions::compareMargins(temp);            //移动法：1.找出匹配项 2.匹配项连接至新链表 3.删除旧链表中的匹配项 4.重复直到旧链表为空
        functions::linkManagerUp();
        functions::deleteLink(temp);
        if(goodshead->next==NULL)
            break;
    }
    return newhead;
}

struct Goods *functions::compareBusiness(struct Goods *temp) {            //找到营业额的最大者
    
    struct Goods *g1=newhead,*g2=nullptr;
    extern struct Goods *data;
    data=new struct Goods;
    
    while (g1!=NULL) {
        
        if(temp->sellAmount<=g1->sellAmount*g1->sellPrice)
            *temp=*g1;
        
        g2=g1->next;
        g1=g2;
    }
    *data=*temp;
    
    return data;
}

struct Goods *functions::compareMargins(struct Goods *temp) {                //找到利润的最大者
    
    struct Goods *g1=newhead,*g2=nullptr;
    extern struct Goods *data;
    data=new struct Goods;
    
    while (g1!=NULL) {
        
        if(temp->sellAmount<=g1->sellAmount*(g1->sellPrice-g1->inPrice))
            *temp=*g1;
        
        g2=g1->next;
        g1=g2;
    }
    *data=*temp;
    
    return data;
}

struct Goods *functions::singleShop() {                  //将单一商店的商品组合在一起
    
    extern Adminif Ad;
    struct Goods *temp;
    temp=new struct Goods;
    newhead=new struct Goods;
    
    char sh[20];
    strcpy(sh,Ad.shop);
    
    
    while(goodshead!=NULL) {
        
        *temp=*goodshead;
        strcpy(temp->shop,sh);                       //移动法：1.找出匹配项 2.匹配项连接至新链表 3.删除旧链表中的匹配项 4.重复直到旧链表为空
        data=functions::shopMatch2(temp);
        functions::linkUp();
        functions::deleteLink(data);
        if(!strcmp(data->goodsNO,"\0"))
            break;
    }
    
    return newhead;
}

struct Goods *functions::restSequence() {             //将剩余量排序
    
    struct Goods *temp;
    extern struct Goods *data;
    temp=new struct Goods;
    newhead=new struct Goods;
    
    while(newhead!=NULL) {
        
        *temp=*newhead;
        temp->restAmount=newhead->restAmount;            //移动法：1.找出匹配项 2.匹配项连接至新链表 3.删除旧链表中的匹配项 4.重复直到旧链表为空
        data=functions::compareRest(temp);
        functions::linkUp();
        functions::deleteLink(temp);
        if(goodshead->next==NULL)
            break;
    }
    return newhead;
}

struct Goods *functions::compareRest(struct Goods *temp) {      //找到剩余量最大者
    
    struct Goods *g1=newhead,*g2=nullptr;
    extern struct Goods *data;
    data=new struct Goods;
    
    while (g1!=NULL) {
        
        if(g1->restAmount<=5)
            *temp=*g1;
        
        g2=g1->next;
        g1=g2;
    }
    *data=*temp;
    
    return data;
}
