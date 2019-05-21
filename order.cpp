//
//  order.cpp
//  XiaoXueQi
//  包含购买商品购买的函数
//  Created by 赵玉凡 2016213 on 17/9/12.
//  Copyright © 2017年 赵玉凡 2016213. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Struct.h"
#include "functions.h"
#include"time.h"
//”√ªßµƒµ«¬º◊¥Ã¨£¨1Œ™“—µ«¬º£¨0Œ™Œ¥µ«¬º
extern int login();   //µ«¬º 
extern int manage();  //◊¢≤·
extern struct Cust gustnow;
extern Goods *goodshead;
extern int logsign;
extern struct Goods *singleGood;

//”√ªß≤Èø¥œÍ«È≤¢œ¬∂©µ•
int order()
{
    int choice1,choice2,choice3;
    int ItemNumber;  //”√ªßπ∫¬Úµƒ÷÷¿‡£¨“‘º∞”√ªßπ∫¬Úµƒ ˝¡ø£¨’˚–Õ ˝◊È
    float price1;
    
    void GetLocalTime(char*);
    char strdate[17];
    GetLocalTime(strdate);

    while(1)
    {
        system("clear");
        printf("What do you want to do?\n");
        printf("(1) Look more details   (2) Check out\n");    //”√ªßø…—°‘Ò≤Èø¥œÍ«ÈªÚΩ·’À
        scanf("%d",&choice1);    //Ω¯––—°‘Ò
        if(choice1!=1&&choice1!=2)
            printf("Invalid input, try again!\n");
        else
            break;
    }
    if(choice1==1)
    {
    	//µ˜”√…Ã∆∑œÍ«È(’≈Â´Œƒ)
    /*
    printf("%s %f %s %s %f %f %d %d %s %s %s\n",
    sinleGood->goodsNO,sinleGood->off,sinleGood->startTime,
    sinleGood->endTime,sinleGood->sellPrice,sinleGood->inPrice,
    sinleGood->restAmount,sinleGood->sellAmount,
    sinleGood->description,sinleGood->clasification,sinleGood->shop);
    *//*
        while(1)
        {
            printf("\nChoose:(1)Get back    (2) Buy\n");    //”√ªßø…—°‘Ò≤Èø¥œÍ«ÈªÚΩ·’À
            scanf("%d",&choice2);    //Ω¯––—°‘Ò
            if(choice2!=1&&choice2!=2)
                printf("Invalid input, try again!\n");
            else
                break;
        }
        if(choice2==1)     //∑µªÿ‰Ø¿¿“≥√Ê
            return 0;
    */
        choice2=2;
        if(choice2==2)      //Ω¯»Îπ∫¬Ú
        {
            functions func1;
            singleGood=func1.print();
            if(singleGood==NULL)
                return 0;
            if(logsign!=2)   //Œ¥µ«¬º£¨«Î”√ªßµ«¬º
                login();//µ«¬º◊¥Ã¨±‰Œ™“—µ«¬º

            if(logsign==2)      //“—µ«¬º£¨Ω´…Ã∆∑º”»Î∂©µ•
            {
                system("clear");
                printf("Choose the number you want to buy(no more than 100):");
                scanf("%d",&ItemNumber);  //”√ªß—°‘Òπ∫¬Úº˛
                
                while(singleGood->restAmount<ItemNumber)      //»Ùø‚¥Ê…Ÿ”⁄”√ªß–Ë«Û£¨÷ÿ–¬ ‰»Î
                {
                    printf("Not enough storage, please input the number again:");
                    scanf("%d",&ItemNumber);
                }
                if(strcmp(strdate,singleGood->startTime)>0&&strcmp(strdate,singleGood->endTime)<0)
                    price1=ItemNumber*singleGood->sellPrice*singleGood->off;    //”√ªßπ∫¬Úƒ≥º˛…Ã∆∑µƒ◊‹º€∏Ò
                else
                    price1=ItemNumber*singleGood->sellPrice;
                
                for(int count=0;price1>gustnow.money;count++)
                {
                    if(count)
                        printf("You still don't have enough money\n");
                    else
                        printf("You don't have enough money\n");
                    while(1)
                    {
                        printf("please choose:\n");
                        printf("(1) Delete some items    (2) Deposit\n");
                        scanf("%d",&choice3);    //Ω¯––—°‘Ò
                        if(choice3!=1&&choice2!=2)
                            printf("Invalid input, try again!\n");
                        else
                            break;
                    }
                    if(choice3==1)
                    {
                        int num;
                        while(1)
                        {
                            printf("Please input the number you want to delete:");
                            scanf("%d",&num);
                            if(num>ItemNumber)
                                printf("You don't have %d of %s yet!\n",num,singleGood->description);
                            else if(num<=0)
                                printf("Input positive numbers only!\n");
                            else
                                break;
                        }
                        ItemNumber-=num;
                        if(strcmp(strdate,singleGood->startTime)>0&&strcmp(strdate,singleGood->endTime)<0)
                            price1=ItemNumber*singleGood->sellPrice*singleGood->off;    //”√ªßπ∫¬Úƒ≥º˛…Ã∆∑µƒ◊‹º€∏Ò
                        else
                            price1=ItemNumber*singleGood->sellPrice;
                    }
                    else
                    {
                        int a=0;
                        while(!a)
                        {
                            printf("Please input your password:");
                            char p[11];//ºÏ≤‚◊÷∑˚¥ÆŒª ˝
                            int i=0,cnt=0;
                            scanf("%s",p);
                            
                            cnt=(signed)strlen(p);
                            if(cnt<6||cnt>10)
                                a=2;
                            else
                            {
                                do
                                {
                                    i++;
                                    if(isalnum(gustnow.password[i])==0)
                                    {
                                        a=2;
                                        break;
                                    }
                                    a=0;
                                } while(i<(count-1));
                            }
                            if(a==2)
                            {
                                printf("You have input wrong password.Input again.\n");
                                a=0;
                            }
                            else
                            {
                                struct Cust adprint;
                                float monn;
                                while(1)
                                {
                                    printf("Please input the money you want to deposit:");
                                    scanf("%f",&monn);
                                    if(monn<=0)
                                        printf("Input positive money only!\n");
                                    else
                                        break;
                                }
                                gustnow.money+=monn;
                                FILE *order;//Œƒº˛¡˜
                                order=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Custer.txt","r+");
                                long int row;
                                while(1)       //∂¡»°Œƒº˛√ø“ª––£¨»Áπ˚Œ™ø’Õ£÷π
                                {
                                    if(!(row=fscanf(order,"%s %s %s %d %s %s %f",adprint.ID,
                                                    adprint.password,adprint.name,&adprint.sex,
                                                    adprint.phone,adprint.mail,&adprint.money)))
                                    {
                                        printf("The file has no record!\n");
                                        a=1;
                                        break;
                                    }
                                    
                                    if(strcmp(gustnow.ID,adprint.ID)==0)//∑¢œ÷∂‘”¶’Àªß
                                    {
                                        
                                        fseek(order,row,SEEK_CUR);//“∆∂ØŒƒº˛÷∏’Î
                                        fprintf(order,"%s %s %s %d %s %s %f",adprint.ID,
                                                adprint.password,adprint.name,adprint.sex,
                                                adprint.phone,adprint.mail,gustnow.money);
                                    }		 //∏≤∏«‘≠–≈œ¢
                                    if(row==EOF)
                                    {
                                        fclose(order);
                                        a=1;
                                        break;
                                    }
                                }
                                fclose(order);
                            }
                        }
                    }
                }
                
                FILE *ord;
                if((ord=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Order.txt","a+"))==NULL)
                {
                    printf("Cannot open the file!\n");
                    return 0;
                }
                char strID[60];
                strcpy(strID,gustnow.ID);
                strcat(strID,strdate);
                float onepricenow=0.00;
                if(strcmp(strdate,singleGood->startTime)>0&&strcmp(strdate,singleGood->endTime)<0)
                    onepricenow=(singleGood->sellPrice)*(singleGood->off);
                else
                    onepricenow=singleGood->sellPrice;
                fprintf(ord,"%s %s %s %d %f %f %s %s\n",strID,strdate,singleGood->description,ItemNumber,
                        onepricenow,price1,singleGood->shop,singleGood->goodsNO);
                fclose(ord);
                printf("%s is added to the shopping list.\n\n",singleGood->goodsNO);
            }
            else
                return 0;
        }
    }
    printf("Press any key to continue\n");
    char ch;
    ch=getchar();
    ch=getchar();
    return 0;
}

void GetLocalTime(char *LocalTime)
{
    
    
    time_t Nowtime;
    struct tm *t;
    time(&Nowtime);
    t = localtime(&Nowtime);
    
    sprintf(LocalTime,"%04d:%02d:%02d:%02d:%02d",1900+t->tm_year,1+t->tm_mon,t->tm_mday,t->tm_hour,t->tm_min);
}






/*
    if(choice1==2)     //Ω·’À
    {
        for(i=0; i<kind; i++)
        {
            Order.price+=Order.oneprice[kind];
        }
        if(Cust.money>=Order.price)
        {
            Cust.money-=price2;//ø€≥˝”√ªßΩ∂Ó
            Goods.//‘ˆº”…Ã∆∑œ˙¡ø£¨ºı…Ÿ…Ã∆∑ø‚¥Ê
            //…˙≥…∂©µ•
        }
        else
        {
            scanf("%d",&choice3);
            
            if(choice3==1)
            {
                //µ˜”√∂©µ•£¨‘ –Ì”√ªß…æ≥˝“——°‘Ò…Ã∆∑
            }
            else if(choice3==2)
            {
                //Ω¯»Î¥ÊøÓ“≥√Ê
            }
        }
    }
}
*/


/*
//…˙≥…µƒ∂©µ•–≈œ¢£®≤ªÕ¨≥¨ ––Œ≥…≤ªÕ¨Œƒº˛£©
int searchOrder()
{
	struct Order order1[1000];
    char orderneed[24];
    printf("please input the order NO.:") ;
    scanf("%s",orderneed);
    FILE *order;

    order=fopen("Order.txt","r");
    while(fscanf("%s %s %s %d %f %f %s",order1.orderNO,order1.date,order1.name,
                 &order1.amount,&order1.oneprice,&order1.price,order1.shop)!=NULL)
        //∂¡»°Œƒº˛√ø“ª––£¨»Áπ˚Œ™ø’Õ£÷π
    {
        //Ω´∏√––∂©µ•√˚”Îµ± ‰»Îµ•∫≈±»Ωœ
        if(strcmp(orderneed,Order.orderNO)//∑¢œ÷∂©µ•
                //¥Ú”°∂©µ•–≈œ¢
    {
        printf("    	print your order		\n") ;

            break;//Ã¯≥ˆ—≠ª∑
        }//∑«ø’ºÃ–¯∂¡»°
    } //while —≠ª∑Ω· ¯
    printf(" all the orders are above.\n") ;
    getchar();
    fclose(order);//πÿ±’Œƒº˛¡˜
    return 0;
}
*/
