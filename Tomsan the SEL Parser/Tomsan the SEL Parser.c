#include <stdio.h>
#include <string.h>

int main()
{
    int numInput;
    
    scanf("%d",&numInput);
    
    while(numInput--)
    {
        char id1[3], id2[5], year1[3], year2[5], month[3], day[3], hour[3], minute[3], BMCorBIOS[3], Success_or_Fail[3];
        
        scanf("%s %s %s %s %s %s %s %s %s 00 %s",id1,id2,year1,year2,month,day,hour,minute,BMCorBIOS,Success_or_Fail);
        
        strcat(id2,id1);
        strcat(year2,year1);
        
        int idValue, yearValue, monthValue, dayValue, hourValue, minuteValue;
        sscanf(id2, "%x", &idValue);
        sscanf(year2, "%x", &yearValue);
        sscanf(month, "%x", &monthValue);
        sscanf(day, "%x", &dayValue);
        sscanf(hour, "%x", &hourValue);
        sscanf(minute, "%x", &minuteValue);
        
        printf("Record %d: %d/%02d/%02d %02d:%02d ",idValue,yearValue,monthValue,dayValue,hourValue,minuteValue);
        
        if(strcmp(BMCorBIOS,"d2")==0) printf("BIOS");
        else printf("BMC");
        
        if(strcmp(Success_or_Fail,"01")==0) printf(" Event Success\n");
        else printf(" Event Fail\n");
    }
    
    return 0;
}
