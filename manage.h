//
//  manage.h
//  XiaoXueQi
//  头文件，供managemin调用
//  Created by 孙卿皓 2016213248 on 17/9/12.
//  Copyright © 2017年 孙卿皓 2016213248. All rights reserved.
//

// 	ordersearch();			
//	commmanage();		
//	personalmanage();		
//	marketstat();		
//	adminmanage();

// 	ordersearch();
#ifndef manage_h
#define manage_h
#include <string.h>
#include <stdio.h>
#include "Struct.h"
#include "functions.h"

extern struct Adminif Ad;
extern int logsign;

//À—À˜∂©µ•≥Ã–Ú 

struct Goods newcommset; //Ω®¡¢Ω·ππ¥¢¥Ê–¬…Ã∆∑–≈œ¢ 
struct Adminif lastad;
 
   // ‰»ÎºÏ≤È°¢∑÷÷ß≥Ã–Ú 
   int inputcheck()
	{
        system("clear");
	int orderget;
	while(1)
		{
		//Àµ√˜º¸»ÎπÊ∑∂ 
		printf("(1) All the orders\t");
		printf("(2) Search the order\t");
		printf("(0) Back\n");
            while(1)
            {
                scanf("%d",&orderget);
                if(orderget<0||orderget>2)
                    printf("Invalid input, please do it again!\n");
                else
                    break;
            }
		switch (orderget) 
			{
			case 1:
			return 1;//≤Èø¥À˘”–∑µªÿ1 
			break;
			case 2:
			return 2;//∂©µ•À—À˜∑µªÿ2 
			break;
			case 0:
			return 0;//∑µªÿ∑µªÿ0
			}//swithΩ· ¯ 
		}//—≠ª∑Ω· ¯ 
	}// ‰»ÎºÏ≤È∫Ø ˝Ω· ¯
   //∫Ø ˝≤È’“≤¢¥Ú”°≥Ã–Ú 
 int allorders()
 {
	FILE *order;
 	order=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/handedorder.txt","r");
 	struct Order order1;
     int a=0;
 	while(fscanf(order,"%s %s %s %d %f %f %s",order1.orderNO,order1.date,order1.name,
	 		&order1.amount,&order1.oneprice,&order1.price,order1.shop)!=EOF)
	//∂¡»°Œƒº˛√ø“ª––£¨»Áπ˚Œ™ø’Õ£÷π 
 	{
 	//Ω´∏√––…ÃµÍ√˚”Îµ±«∞µ«¬Ω…Ã∆Ã–≈œ¢±»Ωœ 
 	if(strcmp(Ad.shop,order1.shop)==0)//∑¢œ÷∂©µ• ,–≈œ¢±»∂‘ 
 	//¥Ú”°∂©µ•–≈œ¢
	 { 
         a=printf("%s %s %s %d %f %f %s\n",order1.orderNO,order1.date,order1.name,
                order1.amount,order1.oneprice,order1.price,order1.shop);
	 }
   } //while —≠ª∑Ω· ¯ 
   fclose(order);//πÿ±’Œƒº˛¡˜
     if(!a)
        printf("\nThere are no orders.\n");
     else
         printf("\nall the orders are above.\n");
     fclose(order);
     printf("Press any key to exit\n");
     char ch;
     ch=getchar();
     ch=getchar();
   return 0;
 }//∫Ø ˝Ω· ¯

 int searchorder()  
 {
 	struct Order order1;
 	char orderneed[10];
 	printf("please input the order NO.（press 0 to return):") ;
     fflush(stdin);
 	scanf("%s",orderneed);
     if(!strcmp(orderneed,"0"))
         return 0;
 	FILE *order;//Œƒº˛¡˜ 
 	order=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/handedorder.txt","r");
 	if(order==NULL)
 	{
	 printf("fail to open\n") ;
        fclose(order);
	 return 0;
 	}
 	while(fscanf(order,"%s %s %s %d %f %f %s",order1.orderNO,order1.date,order1.name,
	 		&order1.amount,&order1.oneprice,&order1.price,order1.shop)!=EOF)
	//∂¡»°Œƒº˛√ø“ª––£¨»Áπ˚Œ™ø’Õ£÷π 
 	{
	
 	//Ω´∏√––∂©µ•√˚”Îµ± ‰»Îµ•∫≈±»Ωœ 
 	if(strcmp(orderneed,order1.orderNO)==0)//∑¢œ÷∂©µ• 
 	//¥Ú”°∂©µ•–≈œ¢
	 { 
         printf("%s %s %s %d %f %f %s\n",order1.orderNO,order1.date,order1.name,
                order1.amount,order1.oneprice,order1.price,order1.shop) ;
 	getchar(); 
 	fclose(order);//πÿ±’Œƒº˛¡˜
 	return 1;
	
 	break;//Ã¯≥ˆ—≠ª∑ 
	 }//∑«ø’ºÃ–¯∂¡»° 
   } //while —≠ª∑Ω· ¯ 
   printf("no order!\n") ;
     char ch;
     ch=getchar();
     ch=getchar();
   fclose(order);//πÿ±’Œƒº˛¡˜
   return 0;
 	
 }
 //ºÏ≤È ‰»Î≥Ã–Ú 
int inputcheck2()
{
		while(1)
		{
		//Àµ√˜º¸»ÎπÊ∑∂ 
		int orderget;
            system("clear");
		printf("(1) Struct new commodity info\n");
        printf("(2) Modify goods\n");
		printf("(0) Back\n");
            while(1)
            {
                fflush(stdin);
                scanf("%d",&orderget);
                if(orderget!=1&&orderget!=2&&orderget!=0)
                    printf("Invalid input, please do it again!\n");
                else
                    break;
            }
		switch (orderget) 
			{
			case 1:
			return 1;//–¬Ω®…Ã∆∑∑µªÿ1
                case 2:
                return 2;
			break;
			case 0:
			return 0;//∑µªÿ∑µªÿ0
			}//swithΩ· ¯ 
		}//—≠ª∑Ω· ¯ 
}// ‰»Î—È÷§Ω· ¯ 

//Ω®¡¢–¬…Ã∆∑≥Ã–Ú
	int choosecheck()
	{
		while(1)
		{
		//—°‘Ò≤Ÿ◊˜ 
		int todo;
            system("clear");
		printf("(1) Modify the info\n");
		printf("(2) Finish\n");
		printf("(0) Abandon\n");
            while(1)
            {
                fflush(stdin);
                scanf("%d",&todo);
                if(todo<0||todo>2)
                    printf("Invalid input, please do it again!\n");
                else
                    break;
            }
		switch (todo) 
			{
			case 1://–ﬁ∏ƒ
			return 1; 
			break;
			case 2:
			return 2;//ÕÍ≥…Ã·Ωª 
			break;
			case 0:
			return 0;//∑µªÿ∑µªÿ0
			}//swithΩ· ¯ 
		}//—≠ª∑Ω· ¯ 

	}//choosecheckΩ· ¯ 

int inputtime(char offdate[]) 
{
//’€ø€ ±º‰  ‰»Î 
	int wrongcheck=0;//…Ë÷√±®¥Ì±Íº« 
	 
	do{ 
	if(wrongcheck==1)
	printf("undue input\n");
	wrongcheck=0;//∏¸–¬±Íº« 
	printf("please input the time");
	printf("(eg. yyyy:mm:dd:hh:mm)\n");
	printf("input here:\n");
	//Ã· æ ‰»ÎπÊ‘Ú
        fflush(stdin);
	scanf("%s",offdate);
	//ºÏ≤È ‰»Î 
	for(int i=0;i<=15;i++)
	{
		if((i<=3)&&((offdate[i]<'0')||(offdate[i]>'9')))
		wrongcheck=1;
		if((i==4)&&(offdate[i]!=':'))
		wrongcheck=1;
		if((i>4)&&(i<=6)&&((offdate[i]<'0')||(offdate[i]>'9')))
		wrongcheck=1;
		if((i==7)&&(offdate[i]!=':'))
		wrongcheck=1;
		if((i>7)&&(i<=9)&&((offdate[i]<'0')||(offdate[i]>'9')))
		wrongcheck=1;
		if((i==10)&&(offdate[i]!=':'))
		wrongcheck=1;
		if((i>10)&&(i<=12)&&((offdate[i]<'0')||(offdate[i]>'9')))
		wrongcheck=1;
		if((i==13)&&(offdate[i]!=':'))
		wrongcheck=1;
		if((i>13)&&(i<=15)&&((offdate[i]<'0')||(offdate[i]>'9')))
		wrongcheck=1;	
	}//»’∆⁄ ‰»Î—È÷§Ω· ¯ 
	}while (wrongcheck==1);//do while —≠ª∑Ω· ¯ 
	return 0;
}

//º€∏Ò ‰»Î≥Ã–Ú	
int pricecheck(float pricenow)
{
	int pricesign=0;
	do
	{
		if(pricesign==1)
		printf("Invalid input, please try again.\n");
		pricesign=0;//∏¸–¬±Íº«
		printf("please input the price:\n") ;
        fflush(stdin);
		scanf("%f",&pricenow);
		if((pricenow<=0.00)||(pricenow>999999.99))
		pricesign=1;	
	}while(pricesign==1);
	return 0;
}
// ˝¡ø ‰»ÎºÏ≤È 
int amountcheck(int amountnow)
{
	int amountsign=0;
	do
	{
		if(amountsign==1)
		printf("Invalid input, please try again.\n");
		amountsign=0;//∏¸–¬±Íº«
		printf("please input the restamount:\n") ;
        fflush(stdin);
		scanf("%d",&amountnow);
		if(!(amountnow>0&&amountnow<999999999))
		amountsign=1;	
	}while(amountsign==1);
    return 0;
}

int searchcomm()
{
    struct Goods adprint;
    
    FILE *order;//Œƒº˛¡˜
    order=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Goods.txt","r+");
    long int row;
    while(1)
        //∂¡»°Œƒº˛√ø“ª––£¨»Áπ˚Œ™ø’Õ£÷π
    {
        
        
        
        if(!(row=fscanf(order,"%s %f %s %s %f %f %d %d %s %s %s",
                   adprint.goodsNO,&adprint.off,adprint.startTime,adprint.endTime,
                   &adprint.sellPrice,&adprint.inPrice,&adprint.restAmount,
                   &adprint.sellAmount,adprint.description,
                   adprint.clasification,adprint.shop)))
        {
            printf("The file has no record!\n");
            fclose(order);
            return 0;
        }
        //÷––ºÏÀ˜≤¢º«¬º∑µªÿ≥§∂»ªÚEOF
        if(strcmp(newcommset.goodsNO,adprint.goodsNO)==0)//∑¢œ÷∂‘”¶’Àªß
        {
            
            fseek(order,row,SEEK_CUR);//“∆∂ØŒƒº˛÷∏’Î
            fprintf(order,"%s %f %s %s %f %f %d %d %s %s %s",
                    adprint.goodsNO,adprint.off,adprint.startTime,adprint.endTime,
                    adprint.sellPrice,adprint.inPrice,adprint.restAmount,
                    adprint.sellAmount,adprint.description,
                    adprint.clasification,adprint.shop);
        }		 //∏≤∏«‘≠–≈œ¢
        if(row==EOF)
            break;	//Œƒº˛Œ≤Ã¯≥ˆ	
        
        
        //»Áπ˚≤ªœ‡µ»£¨ ≤√¥“≤≤ª◊ˆ 
        
    } //while —≠ª∑Ω· ¯ 
    printf("press any key to exit.\n") ;
    getchar(); 
    fclose(order);//πÿ±’Œƒº˛¡˜
    return 0;
    
}

int modifycomm()//–ﬁ∏ƒ’À∫≈–≈œ¢
{
    
    
    printf("the commodity ID is:") ;
    fflush(stdin);
    scanf("%s",newcommset.goodsNO);
    printf("please input the discount information");
    //’€ø€—È÷§
    printf("(eg. 0.2 means 80%% off):");
    float discount;
    fflush(stdin);
    scanf("%f",&discount) ;
    while(!(discount>0&&discount<1))
    {
        printf("\nInvalid input, please try again.");
        fflush(stdin);
        scanf("%f",&discount) ;
    }
    newcommset.off=discount;//’€ø€ ‰»ÎΩ· ¯
    //ø™ º ‰»Î’€ø€ ±º‰
    char offdate[16];//¡Ÿ ±¥¢¥Êoffdate
    //’€ø€ø™ º
    printf("now input when the discount start:\n");
    int inputtime(char []);
    inputtime(offdate);
    strcpy(newcommset.startTime,offdate);// ±º‰∏≥÷µ
    //’€ø€Ω· ¯
    printf("now input when it end:\n");
    int inputtime(char []);
    inputtime(offdate);
    strcpy(newcommset.endTime,offdate);// ±º‰∏≥÷µ
    //’€ø€ ±º‰ ‰»ÎÕÍ≥…
    //ø™ º ‰»Îº€∏Ò
    int pricecheck(float);//…˘√˜º€∏Ò ‰»Î∫Ø ˝
    printf("input the cost.\n");
    float pricenow=0.0;
    pricecheck(pricenow);
    newcommset.inPrice=pricenow; //Ω¯º€∏≥÷µÕÍ≥…
    printf("input the sell price.\n");
    pricecheck(pricenow);
    newcommset.sellPrice=pricenow;// €º€∏≥÷µÕÍ≥…
    // ˝¡ø ‰»Î
    int amountnow=0;
    amountcheck(amountnow);
    newcommset.restAmount=amountnow;
    //±‡º≠÷÷¿‡
    char clasify[60];
    
    printf("input the clasification.\n");
    fflush(stdin);
    scanf("%s",clasify);
    strcpy(newcommset.clasification,clasify);
    //÷÷¿‡±‡º≠ÕÍ≥… 
    strcpy(newcommset.shop,Ad.shop);
    //∏¥÷∆≥¨ –√˚
    searchcomm();
    return 0;
}//modifycommΩ· ¯

	int modifychoose()//–ﬁ∏ƒ—°‘Ò 
	{
		int input;
        system("clear");
		printf("Modify what?\n");
		printf("(1) When the discount start\n") ;
		printf("(2) When the discount end\n");
		printf("(3) The discount\n");
		printf("(4) Sell price\n");
		printf("(5) Amount\n");
		printf("(0) Back\n");
		while(1)
        {
            fflush(stdin);
            scanf("%d",&input);
            if(input<0||input>5)
                printf("Invalid input, please do it again!\n");
            else
                break;
        }
		char offdate[16];//¡Ÿ ±¥¢¥Êoffdate
        int output;
		if(input==1)
        {
			printf("now input when the discount start:\n");
			int inputtime(char []);
			inputtime(offdate);
			strcpy(newcommset.startTime,offdate);// ±º‰∏≥÷µ 
			output=1;
        }
		else if(input==2)
        {
			printf("now input when the discount end£∫\n");
			int inputtime(char []);
			inputtime(offdate);
			strcpy(newcommset.endTime,offdate);// ±º‰∏≥÷µ 
			//’€ø€ ±º‰ ‰»ÎÕÍ≥…
			output=2;
        }
        else if(input==3)
        {
			printf("please input the discount information\n");			  	//’€ø€—È÷§
			printf("discount(eg. 0.2 means 80%% off):");
			float discount;
            fflush(stdin);
			scanf("%f",&discount) ;
			if(!(discount>0&&discount<1))
			{
			printf("\n");
			printf("undue input,please input again:");
            fflush(stdin);
			scanf("%f",&discount) ;
			}
			newcommset.off=discount;//’€ø€ ‰»ÎΩ· ¯ 
			output=3;
        }
		else if(input==4)
        {
			float pricenow=0;
			pricecheck(pricenow);
			newcommset.sellPrice=pricenow;// €º€∏≥÷µÕÍ≥…
			output=4;
        }
        else if(input==5)
        {
			// ˝¡ø ‰»Î
			int amountnow=0;
			amountcheck(amountnow);
			newcommset.restAmount=amountnow;
			output=5;
        }
		else
            output=0;
        return output;
	}//–ﬁ∏ƒ—°‘Ò≥Ã–ÚΩ· ¯ 

int printfile()
{
	FILE *print;
	print=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Goods.txt","a");
	if(print==NULL)
	{
	printf("fail to open the file!");
        fclose(print);
	return 0;
	}
	fprintf(print,"%s %f %s %s %f %f %d %d %s %s %s\n",newcommset.goodsNO,newcommset.off,
	newcommset.startTime,newcommset.endTime,newcommset.sellPrice,newcommset.inPrice,
	newcommset.restAmount,newcommset.sellAmount,newcommset.description,
	newcommset.clasification,newcommset.shop);
    fclose(print);
	return 1;
}

int inputcheck3()
	{
	int orderget;
	while(1)
		{
		//Àµ√˜º¸»ÎπÊ∑∂
            system("clear");
		printf("(1) Modify personal info\n");
		printf("(2) Struct new administrator\n");
		printf("(0) Back\n");
            while(1)
            {
                fflush(stdin);
                scanf("%d",&orderget);
                if(orderget<0||orderget>2)
                    printf("Invalid input, please do it again!\n");
                else
                    break;
            }
		switch (orderget) 
			{
			case 1:
			return 1;//∏¸∏ƒπ‹¿Ì∑µªÿ1 
			break;
			case 2:
			return 2;//–¬Ω®π‹¿Ì∑µªÿ2 
			break;
			case 0:
			return 0;//∑µªÿ∑µªÿ0
			}//swithΩ· ¯ 
		}//—≠ª∑Ω· ¯ 
	}// ‰»ÎºÏ≤È∫Ø ˝Ω· ¯

int searchad()  
 {
 	struct Adminif adprint;
 	
 	FILE *order;//Œƒº˛¡˜ 
 	order=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Adminif.txt","r+");
	 long int row;
 	while(1)
	//∂¡»°Œƒº˛√ø“ª––£¨»Áπ˚Œ™ø’Õ£÷π 
 	{
 		
	row=fscanf(order,"%s %s %s %s %s %s",adprint.ID,adprint.password,adprint.name,
	 		adprint.phone,adprint.shop,adprint.mail);
 	//÷––ºÏÀ˜≤¢º«¬º∑µªÿ≥§∂»ªÚEOF 
 	if(strcmp(Ad.ID,adprint.ID)==0)//∑¢œ÷∂‘”¶’Àªß 
 	{

 	fseek(order,row,SEEK_CUR);//“∆∂ØŒƒº˛÷∏’Î 
 	fprintf(order,"%s %s %s %s %s %s",lastad.ID,lastad.password,lastad.name,
	 		lastad.phone,lastad.shop,lastad.mail);
	}		 //∏≤∏«‘≠–≈œ¢
	 		if(row==EOF)
	 		break;	//Œƒº˛Œ≤Ã¯≥ˆ	
	 
 	
	 //»Áπ˚≤ªœ‡µ»£¨ ≤√¥“≤≤ª◊ˆ 
	 
   } //while —≠ª∑Ω· ¯ 
   printf("press any key to return.\n") ;
   getchar(); 
   fclose(order);//πÿ±’Œƒº˛¡˜
   return 0;
 	
 }

int modifyad()//–ﬁ∏ƒ’À∫≈–≈œ¢
{
    int input;// ‰»ÎÃ· æ
    system("clear");
    printf("Modify what?\n");
    printf("(1) Password\n");
    printf("(2) Name\n");
    printf("(3) Phone\n");
    printf("(4) Shop\n");
    printf("(5) Mail\n") ;
    printf("(0) Back\n");
    fflush(stdin);
    scanf("%d",&input);
    switch(input)
    
    {
        case 1:
            printf("now input new password:\n");
            fflush(stdin);
            scanf("%s",lastad.password);//∏≥÷µ
            searchad(); //÷¥––∏≤∏«≥Ã–Ú
            return 1;
            break;
        case 2:
            printf("now input new name:\n");
            fflush(stdin);
            scanf("%s",lastad.name);
            searchad();
            return 2;
            break;
        case 3:
            printf("please input phone:\n");
            fflush(stdin);
            scanf("%s",lastad.phone);
            searchad();
            return 3;
            break;
        case 4:
            printf("please input shop:\n");
            fflush(stdin);
            scanf("%s",lastad.shop);
            searchad();
            return 4;
            break;
        case 5:
            printf("please input mail:\n");
            fflush(stdin);
            scanf("%s",lastad.mail);
            searchad();
            return 5;
            break;
        case 0:
            return 0;
            break;	
        default:
            break;
    }//switchΩ· ¯ 
    return 0;
}//modifyadΩ· ¯
 
 int buidnewad()			//–¬Ω®π‹¿Ì’Àªß 
 {
 	FILE *newad;
 	newad=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Adminif.txt","a+");	//¥Úø™Œƒº˛¡˜
 										//ø™ ºº«¬º 
 			printf("\nplease input the ID:\n");
            fflush(stdin);
 			scanf("%s",lastad.ID);
			printf("\nnow input new password:\n");
            fflush(stdin);
			scanf("%s",lastad.password);
			printf("\nnow input new name:\n");
            fflush(stdin);
			scanf("%s",lastad.name);
			printf("\nplease input phone:\n");
		  	fflush(stdin);
			scanf("%s",lastad.phone);
			printf("\nplease input shop:\n");
            fflush(stdin);
			scanf("%s",lastad.shop);
			while(1){						//” œ‰ ‰»Îº∞—È÷§ 
			printf("please input mail:\n");
            fflush(stdin);
			scanf("%s",lastad.mail);
			int mailcheck(char []);
			if(mailcheck(lastad.mail)==1)
			break;
			printf("Invalid input, please try again.");
			}
			//ø™ º¥Ú”°µΩŒƒº˛ 
	fprintf(newad,"%s %s %s %s %s %s\n",lastad.ID,lastad.password,
            lastad.name,lastad.phone,lastad.shop,lastad.mail);
     fclose(newad);
     return 0;
 }
 
 //” º˛—È÷§∫Ø ˝£¨∫œ∑®∑µªÿ1£¨∑Ò‘Ú∑µªÿ0	
 	int mailcheck(char arry[])
	 {
	 	int a=0;
	 	int b=0;
	 	int c=0;
	 	int d=0;
         int e=0;
	 	int i=0;
	 	while(arry[i]!='\0')
            {
	 		if(arry[i]=='@')
	 		a=1;
	 		if(arry[i]=='.')
            {
                b=1;
                d=i;
            }
         if((a==1)&&(i>0)&&(b!=1))
	 		c=1;
	 	 if((b==1)&&(i>d))
            e=1;
            i++;
     }
         if((e==1)&&(c==1))
	 	return 1;
	 	else 
            
	 	return 0;
 		
 	} 

int loginad()
{
	while (1)
	{

	char IDlog[11];
	char passwordlog[11];
	printf("please input your ID(0 to retrun):");
        fflush(stdin);
	scanf("%s",IDlog);
        if(!strcmp(IDlog,"0"))
            return 0;
	printf("please input your password(0 to retrun):");
        fflush(stdin);
	scanf("%s",passwordlog);
        if(!strcmp(passwordlog,"0"))
            return 0;
	
	// ‰»Î√‹¬Îº∞”√ªßID 
	extern struct Adminif adprint;
 	
 	FILE *order;//Œƒº˛¡˜ 
 	if((order=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Adminif.txt","r+"))==NULL)
    {
        printf("Fail to find the file!\n");
        fclose(order);
        return 0;
    }
 	long int row;
 	while(1)
	//∂¡»°Œƒº˛√ø“ª––£¨»Áπ˚Œ™ø’Õ£÷π 
 	{
 		
	row=fscanf(order,"%s %s %s %s %s %s",adprint.ID,adprint.password,adprint.name,
	 		adprint.phone,adprint.shop,adprint.mail);
 	//÷––ºÏÀ˜≤¢º«¬º∑µªÿ≥§∂»ªÚEOF 
 	if((strcmp(IDlog,adprint.ID)==0)&&(strcmp(passwordlog,adprint.password)==0))//∑¢œ÷∂‘”¶’Àªß 
 	{
        strcpy(Ad.ID,adprint.ID);
        strcpy(Ad.password,adprint.password);
        strcpy(Ad.name,adprint.name);
        strcpy(Ad.phone,adprint.phone);
        strcpy(Ad.shop,adprint.shop);
        strcpy(Ad.mail,adprint.mail);
 		printf("\nSuccess!\n");
        printf("Press any key to exit\n");
        char ch;
        ch=getchar();
        ch=getchar();
 		logsign=1;
 		return 1;

	}		 //∏≤∏«‘≠–≈œ¢
	if(row==EOF)
	break;	//Œƒº˛Œ≤Ã¯≥ˆ	
	 
	}//ƒ⁄≤„whileΩ· ¯ 

	while(1)
	{
  	int in123;
   	printf("Fail to log in\n");
   	printf("(1) try again\t") ;
   	printf("(2) Back\n");
    fflush(stdin);
   	scanf("%d",&in123);
    if(in123==1)
	 break;//ø™ ºœ¬“ª¬÷¥Û—≠ª∑ 
	if(in123==0)
	 return 0;//ÕÀ≥ˆµ«¬º£¨∑µªÿ0 
	if(in123!=1&&in123!=0) 
	printf("Invalid input, please try again.\n");//do nothing ,¥À—≠ª∑ºÃ–¯
	}
	}//Õ‚ŒßwhileΩ· ¯ 
}

int personalmanage()
{
    while(1)
        //Œﬁœﬁ—≠ª∑ø™ º
    {
        int checksign2=inputcheck3();//checksing◊˜Œ™∑µªÿ÷µ£¨±Ì æÀ˘◊ˆ≤Ÿ◊˜
        switch(checksign2)
        {
            case 1:
                //÷¥–––ﬁ∏ƒπ‹¿Ì‘±
                modifyad();
                break;
                //Ω¯––œ¬“ª¥Œ—≠ª∑
                
            case 2:
                buidnewad();
                printf("press any key to return\n");
                getchar();
                //Ãıº˛Ω· ¯
                break;//Ω¯––œ¬“ª¥Œ—≠ª∑ 
                
            case 0:
                return 0; 
                //∑µªÿ÷µŒ™0£¨ÕÀ≥ˆordersearch≤¢∑µªÿ0 
                
        }//—°‘ÒΩ· ¯ 	
    }//—≠ª∑Ω· ¯ 	
}

int newcomm()
{
    struct Goods newcommset; //Ω®¡¢Ω·ππ¥¢¥Ê–¬…Ã∆∑–≈œ¢
    int unequal; //Ω®¡¢…Ã∆∑√˚∫œ∑®±Íº«
    char IDnow[10];//Ω®¡¢…Ã∆∑√˚¡Ÿ ±ø’º‰
    while(1)
    {
        unequal=0; //∏¸–¬±Íº«
        FILE *structm;
        if((structm=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/goods.txt","a+"))==NULL)
        {
            printf("Fail to open the file!\n");
            fclose(structm);
            return 0;
        }
        //≥…π¶¥Úø™Œƒº˛
        printf("please input the ID of new commodity:(6 digits)\n") ;
        fflush(stdin);
        scanf("%s",IDnow);
        struct Goods check;
        //Œƒº˛À—À˜—≠ª∑
        while(fscanf(structm,"%s %f %s %s %f %f %d %d %s %s %s",check.goodsNO,&check.off,
                     check.startTime,check.endTime,&check.sellPrice,&check.inPrice,
                     &check.restAmount,&check.sellAmount,check.description,
                     check.clasification,check.shop)!=EOF)
            //∂¡»°Œƒº˛√ø“ª––£¨»Áπ˚Œ™ø’Õ£÷π
        {
            //Ω´∏√––∂©µ•√˚”Îµ± ‰»Îµ•∫≈±»Ωœ
            if(strcmp(IDnow,check.goodsNO)==0)//∑¢œ÷√˚◊÷÷ÿ∏¥
            {
                unequal=1;
                printf("This NO has been used\n") ;
                
                printf("Press any key to exit.\n");
                getchar();
                break;
                //Ã¯≥ˆƒ⁄≤„—≠ª∑
            }
        }//ƒ⁄≤„wile Ω· ¯
        if(unequal==0)
            break; //»Áπ˚±Íº«Œ™0.Ã¯≥ˆÕ‚≤„—≠ª∑
        fclose(structm);
    }//whileΩ· ¯
    
    strcpy(newcommset.goodsNO,IDnow);//√¸√˚
    printf("the new commodity name is %s\n",IDnow) ;
    printf("please input the discount information\n");
    //’€ø€—È÷§
    printf("discount(eg. 0.2 means 80%% off):");
    float discount;
    fflush(stdin);
    scanf("%f",&discount) ;
    while(!(discount>0&&discount<1))
    {
        printf("\nInvalid input, please try again.\n");
        fflush(stdin);
        scanf("%f",&discount) ;
    }
    newcommset.off=discount;//’€ø€ ‰»ÎΩ· ¯
    //ø™ º ‰»Î’€ø€ ±º‰
    char offdate[16];//¡Ÿ ±¥¢¥Êoffdate
    //’€ø€ø™ º
    printf("now input when the discount start:\n");
    int inputtime(char []);
    inputtime(offdate);
    strcpy(newcommset.startTime,offdate);// ±º‰∏≥÷µ
    //’€ø€Ω· ¯
    printf("now input when it end:\n");
    int inputtime(char []);
    inputtime(offdate);
    strcpy(newcommset.endTime,offdate);// ±º‰∏≥÷µ
    //’€ø€ ±º‰ ‰»ÎÕÍ≥…
    //ø™ º ‰»Îº€∏Ò
    float pricenow=0.0;
    printf("input the cost.\n");
    pricecheck(pricenow);
    newcommset.inPrice=pricenow; //Ω¯º€∏≥÷µÕÍ≥…
    printf("input the sell price.\n");
    pricecheck(pricenow);
    newcommset.sellPrice=pricenow;// €º€∏≥÷µÕÍ≥…
    // ˝¡ø ‰»Î
    int amountnow=0;
    amountcheck(amountnow);
    newcommset.restAmount=amountnow;
    //±‡º≠÷÷¿‡ 
    char clasify[60];
    
    printf("input the clasification.\n");
    scanf("%s",clasify);
    strcpy(newcommset.clasification,clasify);
    //÷÷¿‡±‡º≠ÕÍ≥… 
    strcpy(newcommset.shop,Ad.shop);
    //∏¥÷∆≥¨ –√˚b
    //Œ¥ÕÍ≥……Ã∆∑—°‘Ò
    //◊Ó∫Û∂©µ•—°‘Ò 
    while(1)
    {
        switch(choosecheck())
        {
            case 1:
                modifychoose(); //÷¥––—°‘Ò–ﬁ∏ƒ 
                break;
            case 2:
                printfile();
                return 1;//Ã¯≥ˆnewcomm 
            case 0:
                return 0;//Ã¯≥ˆnoewcomm 
        }
        
    }//◊Ó∫Û∂©µ•—°‘Ò—≠ª∑Ω· ¯ 
    
} //newcommΩ· ¯
//	commmanage();
int   commmanage()
{
    
    while(1)
    {//—≠ª∑ø™ º
        switch(inputcheck2()) //º¸»ÎºÏ≤È
        {
            case 1://–¬Ω®…Ã∆∑
                newcomm();
                break;//Ã¯≥ˆ—°‘Ò£¨ºÃ–¯—≠ª∑
                
            case 2:
                modifycomm() ;//–ﬁ∏ƒ…Ã∆∑
            case 0://∑µªÿ
                return 0; //ÕÀ≥ˆcommanage≥Ã–Ú
                
        }//—°‘ÒΩ· ¯ 
    }//—≠ª∑Ω· ¯ 
}

int ordersearch()
{
    //÷¥––∑÷÷ßº∞ ‰»ÎºÏ≤È≥Ã–Ú
    while(1)
        //Œﬁœﬁ—≠ª∑ø™ º
    {
        
        int checksign1=inputcheck();//checksing◊˜Œ™∑µªÿ÷µ£¨±Ì æÀ˘◊ˆ≤Ÿ◊˜
        switch(checksign1)
        {
            case 1:
                //÷¥––À—À˜»´≤ø∂©µ•
                allorders();
                break;
                //Ω¯––œ¬“ª¥Œ—≠ª∑
                
            case 2:
                searchorder();
                printf("press any key to exit\n");
                char ch;
                ch=getchar();
                ch=getchar();
                //Ãıº˛Ω· ¯
                break;//Ω¯––œ¬“ª¥Œ—≠ª∑
                
            case 0:
                return 0;
                //∑µªÿ÷µŒ™0£¨ÕÀ≥ˆordersearch≤¢∑µªÿ0
                
        }//—°‘ÒΩ· ¯
    }//—≠ª∑Ω· ¯
}//∂©µ•À—À˜≥Ã–ÚΩ· ¯

#endif
