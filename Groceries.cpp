
//
//  Groceries.cpp
//  XiaoXueQi
//  浏览函数的.cpp文件，供主函数调用
//  Created by 张瀚文 2016213259 on 17/9/12.
//  Copyright © 2017年 张瀚文 2016213259. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "functions.h"
#include "Struct.h"

using namespace std;

extern int login();
extern void manage();
extern int order();
struct Goods *goodshead=NULL,*newhead=nullptr;
extern int logsign;

struct Goods *Groceries() {          //此为main函数调用的浏览项
    
    functions *func1,func;                      //声明指针对象，方便调用
    func1=&func;
    goodshead=func1->openLink();               //打开商品信息文件并整理形成链表
    
    switch(func1->option(0)) {                  //调用option(0)选择此时输出文字
            
        case 1: newhead=func1->forYou();break;//执行相关操作
        case 2: newhead=func1->search();break;
        case 3: newhead=func1->allGoods();break;
        case 0:
            if(logsign==2)
                manage();
            else
                login();                      //当执行完此步骤后，返回NULL，因此不需要break;
        case 9:  return NULL;
    }
    
    for(;;) {
        
        int returnValue=1;
        returnValue=order();
        if(!returnValue)
            break;
    }
    return NULL;
}
