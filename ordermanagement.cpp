//
//  ordermanagement.cpp
//  XiaoXueQi
//
//  Created by 张慧琦 on 17/9/12.
//  Copyright © 2017年 张慧琦. All rights reserved.
//

#include<stdio.h>
#include <iostream>
#include <iomanip>
#include "Struct.h"
#include <string.h>
using namespace std;
struct Order paylist[20];
extern int login();
extern int logsign;
extern struct Cust gustnow;

int ordersearch(int *j)//∂©µ•À—À˜º«¬º
{
    int nums;
    nums=*j;
    struct Order nowlist;//¡Ÿ ±∂¡»Îø™±Ÿƒ⁄¥Ê
    FILE*theorder;
    if((theorder=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Order.txt","r"))==NULL)
    {
        printf("The shopping list is empty!\n\n");
        printf("Press any key to exit\n");
        char ch;
        ch=getchar();
        ch=getchar();
        return 0;
    }
    //¥¥Ω®theorderŒƒº˛£¨”√”⁄∂¡»°OrderŒƒº˛
    cout<<'\n'<<setiosflags(ios::left)<<setw(27)<<"orderNO"<<setw(18)<<"orderDate"
    <<setw(13)<<"orderName"<<setw(9)<<"amount"<<setw(14)<<"singleprice"
    <<setw(9)<<"price"<<setw(7)<<"shop"<<endl;
    while((fscanf(theorder,"%s %s %s %d %f %f %s %s",nowlist.orderNO,
                nowlist.date,nowlist.name,&nowlist.amount,
                &nowlist.oneprice,&nowlist.price,nowlist.shop,nowlist.goodsNO))!=EOF)
        
        {
       
        char userid[11];
        for(int i=0;i<10;i++)
            userid[i]=nowlist.orderNO[i];
      
        if(strcmp(userid,gustnow.ID)==0)
        {
            strcpy(paylist[nums].orderNO,nowlist.orderNO);
            strcpy(paylist[nums].date,nowlist.date);
            strcpy(paylist[nums].name,nowlist.name);
            paylist[nums].amount=nowlist.amount;
            paylist[nums].oneprice=nowlist.oneprice;
            paylist[nums].price=nowlist.price;
            strcpy(paylist[nums].shop,nowlist.shop);
            strcpy(paylist[nums].goodsNO,nowlist.goodsNO);
            
            cout<<setiosflags(ios::left)<<setw(27)<<nowlist.orderNO<<setw(18)<<nowlist.date<<setw(13)
                <<nowlist.name<<setw(9)<<nowlist.amount<<setiosflags(ios::fixed)
                <<setprecision(2)<<setw(14)<<nowlist.oneprice<<setiosflags(ios::fixed)
                <<setprecision(2)<<setw(9)<<nowlist.price<<setw(7)<<nowlist.shop<<endl;
            *j=*j+1;
        }
    }//while end
    *j=*j-1;
    fclose(theorder);
    return 1;
}//∂©µ•À—À˜¬º»Î≥Ã–ÚΩ· ¯

int pay(int *j)
{
    int nums;
    nums=*j;
    FILE *hand;
    hand=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/handedorder.txt","a");
    if(hand==NULL)
    {
        printf("fail to open the file.\n");
        return 0;
    }
    for(int k=0;k<=nums;k++)
    {
        fprintf(hand,"%s %s %s %d %f %f %s %s\n",paylist[k].orderNO,
                paylist[k].date,paylist[k].name,paylist[k].amount,
                paylist[k].oneprice,paylist[k].price,paylist[k].shop,paylist[k].goodsNO);
    }
    fclose(hand);
    return 0;
}

int cover(int *j)
{
    int nums;
    nums=*j;
    struct Goods adprint;
    
    FILE *order;//Œƒº˛¡˜
    order=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Goods.txt","a+");
    
    if(order==NULL)
    {
        printf("fail to pay.\n");
        return 0;
    }
    
    
    long int row;
    for(int k=0;k<=nums;k++)//∂‘Ω·ππ ˝◊È√ø“ª∏ˆ…Ã∆∑Ω¯––∏≤∏«
    {
        
        while(1)
            //∂¡»°GOODSŒƒº˛√ø“ª––£¨»Áπ˚Œ™ø’Õ£÷π
        {
            
            if(!(row=fscanf(order,"%s %f %s %s %f %f %d %d %s %s %s",
                            adprint.goodsNO,&adprint.off,adprint.startTime,
                            adprint.endTime,&adprint.sellPrice,&adprint.inPrice,
                            &adprint.restAmount,&adprint.sellAmount,
                            adprint.description,adprint.clasification,adprint.shop)))
            {
                printf("Fail to pay!\n");
                return 0;
            }
            //÷––ºÏÀ˜≤¢º«¬º∑µªÿ≥§∂»ªÚEOF
            if(strcmp(adprint.goodsNO,paylist[k].goodsNO)==0)//∑¢œ÷∂‘”¶…Ã∆∑±‡∫≈ 
            {
                adprint.restAmount=adprint.restAmount-paylist[k].amount;
                adprint.sellAmount=adprint.sellAmount+paylist[k].amount;
                //–ﬁ∏ƒø‚¥Êœ˙¡ø 
                fseek(order,row,SEEK_CUR);//“∆∂ØŒƒº˛÷∏’Î 
                fprintf(order,"%s %f %s %s %f %f %d %d %s %s %s\n",adprint.goodsNO,
                        adprint.off,adprint.startTime,adprint.endTime,
                        adprint.sellPrice,adprint.inPrice,adprint.restAmount,adprint.sellAmount,
                        adprint.description,adprint.clasification,adprint.shop);
                
                struct Cust adprint2;
                
                FILE *order2;//Œƒº˛¡˜
                order2=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Custer.txt","a+");
                
                if(order==NULL)
                {
                    printf("fail to pay.\n");
                    return 0;
                }
                
                
                long int row2;
                
                
                while(1)
                    //∂¡»°GOODSŒƒº˛√ø“ª––£¨»Áπ˚Œ™ø’Õ£÷π
                {
                    
                    if(!(row2=fscanf(order2,"%s %s %s %s %s %f %d",adprint2.ID,
                                     adprint2.password,adprint2.name,adprint2.phone,
                                     adprint2.mail,&adprint2.money,&adprint2.sex)))
                    {
                        printf("Fail to pay!\n");
                        return 0;
                    }
                    //÷––ºÏÀ˜≤¢º«¬º∑µªÿ≥§∂»ªÚEOF
                    if(strcmp(adprint2.ID,gustnow.ID)==0)//∑¢œ÷∂‘”¶…Ã∆∑±‡∫≈
                    {
                        adprint2.money=adprint2.money-paylist[k].price;
                        
                        //–ﬁ∏ƒø‚¥Êœ˙¡ø
                        fseek(order2,row2,SEEK_CUR);//“∆∂ØŒƒº˛÷∏’Î
                        fprintf(order2,"%s %s %s %s %s %f %d",adprint2.ID,
                                adprint2.password,adprint2.name,adprint2.phone,
                                adprint2.mail,adprint2.money,adprint2.sex);
                    }		 //∏≤∏«‘≠–≈œ¢
                    if(row2==EOF)
                    {
                        fclose(order2);
                        break;	//Œƒº˛Œ≤Ã¯≥ˆ—≠ª∑
                    }
                } //while —≠ª∑Ω· ¯
                
                
                
                
            }		 //∏≤∏«‘≠–≈œ¢
            if(row==EOF)
                break;	//Œƒº˛Œ≤Ã¯≥ˆ—≠ª∑		
            
        } //while —≠ª∑Ω·
        
    }//for—≠ª∑Ω· ¯ 
    //∫Ø ˝Ω· ¯ 
    fclose(order);
    
    //change personal info
    
    //end
    
    
    
    
    
    
    
    return 0;
}

int ordermanagement()
{
    if(logsign!=2)
    {
        printf("you haven't log in!\n");
        login();
    }
    int j=0;
    int a=0;
    while(1)
    {
        system("clear");
        printf("What do you want to do?\n");
        printf("(1) Check your order\t\t");
        printf("(2) Back\n");
        fflush(stdin);
        std::cin>>a;    //Ω¯––—°‘Ò
        a=1;
        if(a!=1&&a!=2)
            printf("Invalid input, try again!\n");
        else
            break;
    }//ª∂”≠Ω¯»Î∂©µ•≤È—ØœµÕ≥£¨—°‘Ò≤È—Ø∂©µ•ªÚÕÀ≥ˆ
    if(a==2)
    {
        return 0;
    }
    //ÕÀ≥ˆ
    else if(a==1)
    {
        if(ordersearch(&j)==0)
            return 0;
        //≤È—Ø≤¢œ‘ æ“—µ«¬º”√ªßµƒ∂©µ•
        int c=0;
        while(1)
        {
            printf("(1) pay.\t");
            printf("(2) to abandon the order.\t");
            printf("(0) Back\n");
            scanf("%d",&c);
            if(c!=1&&c!=2&&c!=0)
                printf("Invalid input, try again!\n");
            else
                break;
        }//—°‘Ò∏∂øÓªÚÕÀ≥ˆ
        if(c==2)
        {
            remove("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Order.txt");
            printf("Abandoned!\n");
            printf("Press any key to exit\n");
            char ch;
            ch=getchar();
            ch=getchar();
            return 0;
        }
            //ÕÀ≥ˆ
        else if(c==1)
        {
            pay(&j);
            printf("Success!\n\n");
            printf("Press any key to exit\n");
            char ch;
            ch=getchar();
            ch=getchar();
            cover(&j);
            remove("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Order.txt");
        }
        else
            return 0;
            //∏∂øÓ
    }//–ﬁ∏ƒ≤¢Ã·Ωª∂©µ•
    return 0;
}
