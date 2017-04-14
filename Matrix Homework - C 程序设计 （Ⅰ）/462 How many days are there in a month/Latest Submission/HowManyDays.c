#include <stdio.h>

int main ()
{
    int year = 0;
    int month = 0;
    int days = 0;
    int flag = 0;
    scanf("%d%d",&year,&month);    
    if((year>=0)&&(year<=9999)&&(month>=1)&&(month<=12))
    {
    	if(((year%4==0)&&(year%100!=0))||(year%400==0)) 
    		flag = 1;
        if(month!=2)
        {
        	switch(month)
        	{
        		case 1:
        		    days = 31;
        		    break;
        		case 3:
        		    days = 31;
        		    break;
        		case 4:
        		    days = 30;
        		    break;
        		case 5:
        		    days = 31;
        		    break;
        		case 6:
        		    days = 30;
        		    break;
        		case 7:
        		    days = 31;
        		    break;
        		case 8:
        		    days = 31;
        		    break;
        		case 9:
        		    days = 30;
        		    break;
        		case 10:
        		    days = 31;
        		    break;
        		case 11:
        		    days = 30;
                 break;
        		default:
        		    days = 31;
        		    break;
        	}
        }
        else if(flag)
        {
        	days = 29;
        }   
        else
        {
            days = 28;
        }       	
        printf("%04d/%02d has %d days.\n",year,month,days);
    }
    else
    {
    	printf("Invalid Input Detected.\n");
    }
    
    return 0;
}