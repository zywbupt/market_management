//
//  main.cpp
//  XiaoXueQi
//  主函数，包含用户和管理员两部分
//  Created by 张瀚文 2016213259 on 17/9/12.
//  Copyright © 2017年 张瀚文 2016213259. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "Struct.h"
#include "functions.h"

using namespace std;

extern struct Goods *Groceries();             //浏览
extern int managemain();                //管理员
extern void StructCust();                  //用户信息管理
extern void manage();                    //genggaiyonghuxinxi
extern int login();                     //登录
extern int ordermanagement();                  //管理订单

extern int logsign;                    //登录判断符
Adminif Ad;                        //管理员结构体
extern struct Cust gustnow;         //用户结构体
bool print;

void printWelcome();
void printGoodbye();
int choose(int);

int main() {
    
    printWelcome();
    int c1=0;
    logsign=0;
    
    while(c1!=4) {
        c1=choose(0);
        
        if(c1==1) {
            int c2=0;
            
            while(c2!=4) {
                c2=choose(1);
            
                if(c2==1)
                    Groceries();
                else if(c2==2)
                    StructCust();
                else if(c2==3)
                    ordermanagement();
            }
        }
        else if(c1==2)
            managemain();
    }
    printGoodbye();
    return 0;
}

void printWelcome() {
    void sleep();
    cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;sleep();
    cout<<"*                                                       *"<<endl;
    cout<<"*                      Welcome                          *"<<endl;sleep();
    cout<<"*         to the XiaoXueQiWuRenZu Online Shop           *"<<endl;sleep();
    cout<<"*                                                       *"<<endl;
    cout<<"*                     ╮(￣▽￣)╭                         *"<<endl;sleep();
    cout<<"*                                                       *"<<endl;
    cout<<"*                                                       *"<<endl;
    cout<<"*                      We have                          *"<<endl;sleep();
    cout<<"*                 The cheepest goods                    *"<<endl;sleep();
    cout<<"*                                                       *"<<endl;
    cout<<"*                      We have                          *"<<endl;sleep();
    cout<<"*                  The best shops                       *"<<endl;sleep();
    cout<<"*                                                       *"<<endl;
    cout<<"*               Start your exploration                  *"<<endl;sleep();
    cout<<"*                                                       *"<<endl;
    cout<<"*                                                       *"<<endl;
    cout<<"*                        NOW                            *"<<endl;sleep();
    cout<<"*                                                       *"<<endl;
    cout<<"*  <AD> Skating season coming, skating board 50% off!   *"<<endl;sleep();
    cout<<"*                                                       *"<<endl;
    cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;sleep();
    print=false;
}

void printGoodbye() {
    system("clear");
    void sleep();
    cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;sleep();
    cout<<"*                                                       *"<<endl;
    cout<<"*                      Goodbye                          *"<<endl;sleep();
    cout<<"*                                                       *"<<endl;
    cout<<"*                      We wish                          *"<<endl;
    cout<<"*             you had a pleasant journey                *"<<endl;sleep();
    cout<<"*                                                       *"<<endl;
    cout<<"*                                                       *"<<endl;
    cout<<"*                     Next time                         *"<<endl;sleep();
    cout<<"*             We shall have better good                 *"<<endl;sleep();
    cout<<"*                                                       *"<<endl;
    cout<<"*                     We shall                          *"<<endl;sleep();
    cout<<"*              have better experiences                  *"<<endl;sleep();
    cout<<"*                                                       *"<<endl;
    cout<<"*                      See you                          *"<<endl;sleep();
    cout<<"*                     Next time                         *"<<endl;
    cout<<"*                                                       *"<<endl;
    cout<<"*                 ©XiaoXueQiWuRenZu                     *"<<endl;sleep();
    cout<<"*                                                       *"<<endl;
    cout<<"*       <AD> Winter is coming, GOT hat 50% off!         *"<<endl;sleep();
    cout<<"*                                                       *"<<endl;
    cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl<<endl;sleep();

}

int choose(int choise) {
    
    char ch[20];
    for(;;) {
        if(!choise) {
            if(print)
                system("clear");
            printf("\nview as: (a) Customer    (b) Administrator    (d) Exit\n");
            print=true;
        }
        
        else {
            system("clear");
            printf("What do you want to do?\n");
            printf("(a) Browser    (b) Customer Centre     (c) Shopping list & pay        (d) Back\n");
        }
        cin>>ch;
        
        if((strcmp(ch,"a")&&strcmp(ch,"b")&&strcmp(ch,"c")&&strcmp(ch,"d")&&!choise)
           ||(strcmp(ch,"a")&&strcmp(ch,"b")&&strcmp(ch,"c")&&strcmp(ch,"d")&&choise))
            printf("\nInvalid input, Please input again!\n");
        else
            break;
    }
    
    if(!strcmp(ch,"a"))
        return 1;
    else if(!strcmp(ch,"b"))
        return 2;
    else if(!strcmp(ch,"c"))
        return 3;
    else
        return 4;
}

void sleep() {
    
    time_t start,end,t1;
    time(&start);
    end=start+1;
    
    for(;;) {
        time(&t1);
        if(t1==end)
            break;
    }
}
