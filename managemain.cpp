//π‹¿Ì÷˜≥Ã–Ú 

#include <stdio.h>
#include "manage.h"
#include <stdlib.h>
#include "Struct.h"

extern int logsign;
extern Adminif Ad;
struct Goods adm;

//œ∏∑÷≥Ã–Ú ‰»Î—È÷§
struct Adminif adprint,*ad;

	int inputchoose()	
{
	int get;// ‰»Î 
	scanf("%d",&get);

		switch(get)
		{ 
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
            case 6:
            case 7:
			case 0:
			break; 
			default:
			printf("Invalid input, please try again.\n");//∆‰À˚«Èøˆ£¨÷ÿ∏¥‘À––
			inputchoose();
			break;
		}
		// ‰»Î’˝≥££¨∑µªÿ ‰»Î÷µ 
	return get;
}


//load check≥Ã–Ú 
int loadcheck()
{
    system("clear");
	if(logsign==1)
	return 1;
//have been loaded
//…Ë÷√ ‰»Î±Íº«»Áπ˚Œ™1£¨‘Úµ«¬Ω£¨0Œ™ÕÀ≥ˆ 
int loadcheck1;
	while (1)
	{
	printf("(1) load\t");
	printf("(0) return\n");
	
	scanf("%d",&loadcheck1);
	if(loadcheck1!=1&&loadcheck1!=0)
	{ 
    	printf("Invalid input, please try again.\n");
		continue; 
	} 
	if(loadcheck1==1)//÷¥––µ«¬Ω≥Ã–Ú
	{
        loginad();//¥À¥¶º”∫Ø ˝
        if (logsign==1)
            return 1;
        if (logsign==0)
            return 0;
	}
	if(loadcheck1==0)
        return 0;
	}
} 

//œ∏∑÷∫Ø ˝		
	int managechoose()
{
    fflush(stdin);
    system("clear");
	printf("\nPlease choose what to do\n");
	printf("(1) Order search\n");
	printf("(2)	Commodity management\n");
	printf("(3) Personal management\n");
	printf("(4) Market statistics\n");
    printf("(5) Market business\n");        //sellPrice*sellAmount
    printf("(6) Market margins\n");         //(sellPrice-inPrice)*sellAmount
    printf("(7) Need supplyment\n");
    //printf("	administer management (please input 8)\n");
	printf("(0) Back\n");
	//µ˜”√ ‰»Î—È÷§≥Ã–Ú
	int get=inputchoose();
	// ‰»Î—È÷§∑µªÿ÷µ≤ªŒ™¡„ºÃ–¯
    class functions func;
    strcpy(adm.shop,Ad.shop);
	switch(get)
		{ 
			case 1:
			ordersearch();
                break;
			//∂©µ•≤È—Ø
			case 2:
			commmanage();
			break;
			//…Ã∆∑π‹¿Ì
			case 3:
			personalmanage();
			break;
			//∏ˆ»À–≈œ¢π‹¿Ì
			case 4:
            func.amountSequenceInSameStore();
			break;
			// –≥°Õ≥º∆ 
            case 5:
            func.businessSequenceInSameStore();
            break;
            case 6:
            func.marginsSequenceInSameStore();
            break;
            case 7:
            func.supplySequenceInSameStore();
            break;
			case 0:
            return 0;
  		}
  		return 0;
}

extern int managemain()
{
    //ºÏ≤Èµ«¬Ω◊¥Ã¨
    if(loadcheck()==0)
        return 0;
    //∑µªÿ÷µŒ™0 ±ÕÀ≥ˆ≥Ã–Ú£¨µ«¬Ω∫ÛºÃ–¯
    
    //œ∏∑÷≥Ã–Ú
    managechoose();
    getchar();
    return 0;
}
//π‹¿Ì÷˜≥Ã–ÚΩ· ¯
