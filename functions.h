//
//  functions.h
//  XiaoXueQi
//  包含管理数据库以及与链表有关的一些函数
//  Created by 张瀚文 2016213259 on 17/9/12.
//  Copyright © 2017年 张瀚文 2016213259. All rights reserved.
//

#ifndef functions_h
#define functions_h
#include <iostream>
#include "Struct.h"                           //引用结构体的头文件

using namespace std;

class functions {                             //此类包含若干函数
public:
    int option(int);                          //此函数根据不同需求选择界面并输入，返回值为其它函数的操
    struct Goods *openLink();                        //创建链表的函数，用于商品排序，返回值为链表的头指针
    struct Cust *openCustLink();                     //打开链表用于搜索相同的账户名
    //void deleteAmountLink(struct Goods *,struct Goods *);   //用于检索并删除一个节点，返回头指针
    //void deleteBusinessLink(struct Goods *,struct Goods *); //用于检索并删除一个节点，返回头指针
    //void deleteMarginsLink(struct Goods *,struct Goods *);  //用于检索并删除一个节点，返回头指针
    //void deleteInterLink(struct Goods *,struct Goods *);    //用于检索并删除一个节点，返回头指针
    void deleteLink(struct Goods *);    //用于检索并删除一个节点，返回头指针
    void deleteManagerLink(struct Goods *);
    //void deleteRestLink(struct Goods *,struct Goods *);     //用于检索并删除一个节点，返回头指针
    void deleteCustLink(struct Cust *);       //用于检索并删除一个节点，返回头指针
    //void freelink(struct Goods *);                   //关闭链表
    struct Goods *forYou();               //推荐板块的函数，参数为头指针，返回值为用户所需商品,NULL为返回，参数值为是否已登录判断符
    struct Goods *search();               //搜索板块的函数，参数为头指针，返回值为用户所需商品,NULL为返回，参数值为是否已登录判断符
    struct Goods *allGoods();             //浏览所有商品的函数，参数为头指针，返回值为用户所需商品,NULL为返回，参数值为是否已登录判断符
    struct Goods *amountSequence();           //基于销量创建一个包含所有商品的新链表，并返回头指针
    //struct Goods *amountSequence2();
    struct Goods *shopSearch();               //创建一个包含所有相同店铺名称的新链表，并返回头指针
    struct Goods *nameSearch();               //创建一个包含所有相同商品名称的新链表，并返回头指针
    struct Goods *print();                //根据新的头指针打印商品列表，并返回查看商品的指针
    struct Goods *printManager(int);             //不含登录选项，供管理员使用
    int sameNameCheck(char [11]);             //检查用户注册账号是否重复
    void amountSequenceInSameStore();  //供管理员使用，按销量排序同一个商店中的商品并打印
    void businessSequenceInSameStore();//供管理员使用，按营业额排序同一个商店中的商品并打印
    void marginsSequenceInSameStore(); //供管理员使用，按利润排序同一个商店中的商品并打印
    void supplySequenceInSameStore();  //供管理员使用，打印出需要补充的商品
private:
    struct Goods *priceSequence();            //基于价格供管理员使用，按营业额排序
    struct Goods *interSequence();            //加权排序并创建一个包含所有商品的新链表，并返回头指针
    struct Goods *compareAmount(struct Goods *);    //从链表中筛选出销量最大的那一个，并进行下一步操作，返回一个新开辟的结构体，数据为最大者的数据
    struct Goods *comparePrice(struct Goods *);     //从链表中筛选出价格最大的那一个，并进行下一步操作，返回一个新开辟的结构体，数据为最大者的数据
    struct Goods *compareInter(struct Goods *);     //从链表中筛选出销量最大的那一个，并进行下一步操作，返回一个新开辟的结构体，数据为最大者的数据
    struct Goods *amountRank();               //根据销量创建一个有20个元素的新链表，并返回头指针
    struct Goods *priceRank();                //根据价格高低创建一个有20个元素的新链表，并返回头指针
    struct Goods *interRank();                //加权排序并创建一个有20个元素的新链表，并返回头指针
    struct Goods *nameMatch(struct Goods *,char);   //从链表中筛选出需要的商品名字，并进行下一步操作，返回一个新开辟的结构体，数据为符合者的数据
    struct Goods *shopMatch(struct Goods *,char);   //从链表中筛选出需要的店铺名字，并进行下一步操作，返回一个新开辟的结构体，数据为符合者的数据
    struct Goods *shopMatch2(struct Goods *);
    struct Cust *IDMatch(struct Cust *);             //从链表中筛选出需要的账户名字，并进行下一步操作，返回一个新开辟的结构体，数据为符合者的数据
    void linkUp();             //把新结构体链接至新链表
    void linkManagerUp();
    void linkCustUp(struct Cust *);           //把新结构体链接至新链表
    //void nameDeleteLink(struct Goods *,struct Goods *);     //删除找出需要者后链表之前的部分，以简化操作
    //void shopDeleteLink(struct Goods *,struct Goods *);     //删除找出需要者后链表之前的部分，以简化操作
    struct Goods *businessSequence();         //供管理员使用，按营业额排序并创建一个包含所有商品的新链表，并返回头指针
    struct Goods *marginsSequence();          //供管理员使用，按利润排序并创建一个包含所有商品的新链表，并返回头指针
    struct Goods *compareBusiness(struct Goods *);  //从链表中筛选出销量最大的那一个，并进行下一步操作，返回一个新开辟的结构体，数据为最大者的数据
    struct Goods *compareMargins(struct Goods *);   //从链表中筛选出利润最大的那一个，并进行下一步操作，返回一个新开辟的结构体，数据为最大者的数据
    struct Goods *singleShop();       //供管理员使用，找到自己的店铺，返回店铺所有商品的头指针
    struct Goods *restSequence();             //供管理员使用，按库存排序商品
    struct Goods *compareRest(struct Goods *);      //供管理员使用，找出库存较少的商品
};

#endif /* functions_h */
