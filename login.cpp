//
//  login.cpp
//  XiaoXueQi
//  登录函数的.cpp文件，供主函数调用
//  Created by 占怡雯 2016213269 on 17/9/12.
//  Copyright © 2017年 占怡雯 2016213269. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Struct.h"
#include "functions.h"

struct Cust gustnow;//∑≈»Î÷˜∫Ø ˝
int resiger(); //◊¢≤·∫Ø ˝…˘√˜
void manage();
FILE *Custer;
int phoneCheck(char x[]);
int mailCheck(char x[]);
int logsign;//µ«¬Ω≥…π¶∑µªÿ2£¨ ß∞‹0
extern int login();//µ«¬Ω∫Ø ˝…˘√˜
struct Cust *custshead;
struct Cust *newcustshead;

void StructCust(){
    if(logsign!=2)
    {
    printf("Have you resigered?\n");
    int i;   //≈–∂œ «∑Ò“—æ≠◊¢≤·

    do{
        printf("If you have resigered, please input 0, else input 1.\n") ;
        fflush(stdin);
        scanf("%d",&i);
        
        switch(i)
        {
            case 0:
                logsign=login();
                break;
            case 1:resiger();
                    break;
            default:
                printf("Please input 0 or 1 only.\n");
                break;
        }
    } while(i!=0&&i!=1);
    }
    else
    {
        printf("Do you want to manage?(y,n)\n");
        char ch;
        for(;;) {
            scanf("%c",&ch);
            if(ch!='y'&&ch!='n')
                printf("Please input y or n only!\n");
            else
                break;
        }
        if(ch=='y')
            manage();
        else
        {
            printf("Press any key to continue.\n");
            char ch;
            ch=getchar();
            ch=getchar();
        }
    }
}

int login()
{
	while(1)
	{
        char ID[11];
        char password[11];
        printf("Please log in.\n");
        printf("please input your ID(press 0 to return):");
        fflush(stdin);
        scanf("%s",ID);
        if(strcmp(ID,"0")==0)
            return 0;
        printf("please input your password:");
        fflush(stdin);
        scanf("%s",password);
        if(strcmp(password,"0")==0)
            return 0;

        struct Cust adprint;
 	
        FILE *Custer;
        if((Custer=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Custer.txt","r+"))==NULL) //¥Úø™Œƒº˛ø¥ «∑Òƒ‹¥Úø™
        {
            printf("The file can not be opened\n");
            return 0;
        }
      
        long int row;
        while(1)
        {
                if(!(row=fscanf(Custer,"%s %s %s %s %s %f %d",adprint.ID,
                        adprint.password,adprint.name,adprint.phone,
                        adprint.mail,&adprint.money,&adprint.sex)))
                {
                    printf("The file has no record!\n");
                    return 0;
                }
            if(strcmp(ID ,adprint.ID )==0&&(strcmp(password,adprint.password)==0))//ºÏ—È√‹¬Î∫Õ’À∫≈ «∑Òœ‡∂‘”¶
            {
                strcpy(gustnow.ID,adprint.ID);
                strcpy(gustnow.password,adprint.password);
                strcpy(gustnow.name,adprint.name);
                gustnow.sex=adprint.sex;
                strcpy(gustnow.phone,adprint.phone);
                strcpy(gustnow.mail,adprint.mail);
                gustnow.money=adprint.money;
                
                printf("\nLog in as: %s\n",gustnow.ID);
                printf("success!\n\n");
                printf("Press any key to continue\n");
                char ch;
                ch=getchar();
                ch=getchar();
                logsign=2;
                fclose(Custer);
                return 2;
            }
            if(row==EOF)
                break;
        }

        while(1)
        {
            int in123;
            printf("fail to log in\n");
            printf("try again: press 1.\n") ;
            printf("exit :press 0\n");
            fflush(stdin);
            scanf("%d",&in123);
            if(in123==1)
                break;
            if(in123==0)
                return 0;
            //if(in123!=1&&in123!=0) ;
        }
    }
    return 0;
}
int idCheck()
{
	char*p;//ºÏ≤‚◊÷∑˚¥ÆŒª ˝
	int i=0,a,count=0;//º∆À„◊÷∑˚¥ÆŒª ˝
	p=gustnow.ID;
	while(*p!='\0'){
		count++;
		p++;
	}
	if(count<6||count>10)
	{
        printf("You have input wrong ID.\n");
        a=1;
    }
	else
    {
        do
        {
            i++;
            if(isalnum(gustnow.ID[i])==0)
            {
                a=1;
                break;
            }
            a=0;
        } while(i<(count-1));
    }
    if(a==1)
    {
        printf("You have input wrong ID.Input again.\n");
        return 1;
    }
    else
        return 0;
}

int passwordCheck1()
{
	char *p;//ºÏ≤‚◊÷∑˚¥ÆŒª ˝
	int i=0,a,count=0;
	p=gustnow.password;
    
	while(*p!='\0')
    {
		count++;
		p++;
	}
	if(count<6||count>10)
	{
        printf("You have input wrong password.\n");
        a=1;
    }
	else
    {
        do
        {
            i++;
            if(isalnum(gustnow.password[i])==0)
            {
                a=1;
                break;
            }
            a=0;
        } while(i<(count-1));
    }
        if(a==1)
        {
            printf("You have input wrong password.Input again.\n");
            return 1;
        }
        else
            return 0;
}

int resiger()
{   
    Custer=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Custer.txt","a+");
	char Linedata[80];
	fflush(stdin);
	do
    {
        while(1)
        {
        printf("Please input your ID(press 0 to return):\n");
        fflush(stdin);
	    scanf("%s",gustnow.ID);
        getchar();
        if(strcmp(gustnow.ID,"0")==0)
        {
            fclose(Custer);
            return 0;
        }
        functions func1;
        if(func1.sameNameCheck(gustnow.ID))
            printf("\nThe name has already been registered.\n");
        else
            break;
        }
    } while(idCheck());
    
	
	do{
        printf("\nPlease input your password(BETWEEN 6 AND 10)(press 0 to return):");
        fflush(stdin);
	    scanf("%s",gustnow.password);
        if(strcmp(gustnow.password,"0")==0)
        {
            fclose(Custer);
            return 0;
        }
    }
	while(passwordCheck1());
	
	printf("\nPlease input your personal name(LESS THAN 20)(press 0 to return):");
    fflush(stdin);
	scanf("%s",gustnow.name);
    if(strcmp(gustnow.name,"0")==0)
    {
        fclose(Custer);
        return 0;
    }
	
	printf("\nPlease input your telephone number(press 0 to return):\n");
	fflush(stdin);
	scanf("%s",gustnow.phone);
    if(strcmp(gustnow.phone,"0")==0)
    {
        fclose(Custer);
        return 0;
    }
	while(phoneCheck(gustnow.phone))
    {
		printf("You have input wrong telephone number(press 0 to return).Please input again\n");
        fflush(stdin);
		scanf("%s",gustnow.phone);
        if(strcmp(gustnow.phone,"0")==0)
        {
            fclose(Custer);
            return 0;
        }
	}
	
	printf("\nPlease input you mail(press 0 to return):\n");
    fflush(stdin);
	scanf("%s",gustnow.mail);
	while(mailCheck(gustnow.mail))
    {
		printf("You have input wrong mail(press 0 to return).Please input again");
        fflush(stdin);
		scanf("%s",gustnow.mail);
        if(strcmp(gustnow.mail,"0")==0)
        {
            fclose(Custer);
            return 0;
        }
    }
	
	printf("Please input you adress(press 0 to return).\n");
	
	fflush(stdin);
	scanf("%s",gustnow.address);
    if(strcmp(gustnow.address,"0")==0)
    {
        fclose(Custer);
        return 0;
    }
	
	gustnow.money=1000.00;
	
	printf("\nPlease input your sex(man for 0, women for 1)(press 2 to return):\n");
    fflush(stdin);
	scanf("%d",&gustnow.sex);
    if(gustnow.sex==2)
        return 0;
	while(gustnow.sex!=0&&gustnow.sex!=1)
    {
		printf("Please input 0 and 1 only:\n");
        fflush(stdin);
		scanf("%d",&gustnow.sex);
	}
	
	strcpy(Linedata,gustnow.ID);	strcat(Linedata," ");
	strcat(Linedata,gustnow.password);	strcat(Linedata," ");
	strcat(Linedata,gustnow.name);	strcat(Linedata," ");
	strcat(Linedata,gustnow.phone);  strcat(Linedata," ");
	strcat(Linedata,gustnow.mail);  strcat(Linedata," ");
	fputs(Linedata,Custer);
	fprintf(Custer,"%.2f ",1000.00);
	fprintf(Custer,"%d\n",gustnow.sex);
	fclose(Custer);
	printf("Registered Success!\n");
    fclose(Custer);
    return 0;
}

int phoneCheck(char x[])
{
	int length;
    int i=0;
	while(1)
    {
        i=0;
		for(;i<11;i++)
        {
			if(gustnow.phone[i]<=47||gustnow.phone[i]>=58)
				return 1;
		}
		length=(signed)strlen(gustnow.phone);
        
		if(length!=11)
			return 1;
        else
            return 0;
    }
}

int mailCheck(char x[])
{
	char *a,*b;
	a=strstr(x,"@");
	if(a!=NULL&&a!=x)
    {
		b=strstr(a,".");
		if(b!=NULL&&b!=a+1&&b+1!=NULL)
            return 0;
        else
            return 1;
	}
    else
        return 1;
}

void manage_()
{
    FILE *Custer;
    if((Custer=fopen("/Users/CharmingMac/Library/Developer/Xcode/DerivedData/XXQ-emkjdtwaklmnwnanmmhtwaceelzd/Build/Products/Debug/Custer.txt","r+"))==NULL) //¥Úø™Œƒº˛ø¥ «∑Òƒ‹¥Úø™
        printf("The file can not be opened\n");
    
    struct Cust adprint;
    long int row;
    
    while(1)//∂¡»°Œƒº˛√ø“ª–––≈œ¢
    {
        row=fscanf(Custer,"%s %s %s %s %s %f %d",adprint.ID,
                   adprint.password,adprint.name,adprint.phone,
                   adprint.mail,&adprint.money,&adprint.sex);
        if(strcmp(gustnow.ID ,adprint.ID )==0)
        {
            fseek(Custer,row,SEEK_CUR);
            fprintf(Custer,"%s %s %s %s %s %7.2f %d\n",adprint.ID,
                    adprint.password,adprint.name,adprint.phone,
                    adprint.mail,adprint.money,adprint.sex);
        }		//∏≤∏«‘≠–≈œ¢
        if(row==EOF)
            break;
        
    }
    //printf("press any key to exit.\n") ;
    //getchar();
    fclose(Custer);
}

void manage(){
	int mid=0;
    system("clear");
    printf("Please enter the item you want to modify\n");
    printf("(1) telephone number\n");
    printf("(2) for password\n");
    printf("(3) for email\n");
    printf("(4) for recharge\n");
    printf("(0) return\n");
	do {
        fflush(stdin);
		scanf("%d",&mid);
		fflush(stdin);
		if(mid==1) {
            while(1)
            {
                printf("Please input new telephone number:\n");
                fflush(stdin);
                scanf("%s",gustnow.phone);
                if(!phoneCheck(gustnow.phone))
                {
                    manage();
                    break;
                }
                else
                    printf("Wrong phone number, please input again!\n\n");
            }
		}
        if(mid==2)
        {
            while(1)
            {
                printf("\nPlease input new password:");
                fflush(stdin);
                scanf("%s",gustnow.password);
                if(!passwordCheck1())
                {
                    manage_();
                    break;
                }
                else
                    printf("Wrong password, please input again!\n\n");
            }
        }
		if(mid==3)
        {
            while(1)
            {
                printf("Please input new email:\n");
                fflush(stdin);
                scanf("%s",gustnow.mail);
                if(!mailCheck(gustnow.mail))
                {
                    manage_();
                    break;
                }
                else
                    printf("Wrong email number, please input again!\n\n");
            }
        }
		if(mid==4)
        {
            printf("Please input the money you want:\n");
            fflush(stdin);
			scanf("%f",&gustnow.money);
			manage_();
		}
        if(mid==0)
            break;
		if(mid<0||mid>4)
			printf("the number you enter is invalid, please enter another number\n");
	} while(mid<0||mid>4);
    printf("Press any key to comtinue.\n");
    char ch;
    ch=getchar();
    ch=getchar();
}
