/**
 * filename: postage.c
 * */
#include <stdio.h>

int main()
{
    int denom[6]={0}, ret[6]={0};
    int i,postage;
    printf("Enter six denominations (decreasing): ");
    for (i=0; i<6;i++)
    {
        scanf("%d",&denom[i]);  // input 6 denominations
    }

    for (i=1; i<6;i++)
    {
        if (denom[i] >= denom[i-1]) // check denomination whether is in decreasing order or not         
        {
           printf("Not in decreasin order!\n");
           return 0;
        }
    }
    printf("Enter a postage: ");
    scanf("%d",&postage);

    for (i=0; i<6;i++)
    {
        if (denom[i] <= postage)    // if the postage less than denomination
        {
            ret[i]=postage/denom[i];  //calculate for how many same denomination
            postage = postage - denom[i]*ret[i]; 
        }
    }
    if (postage != 0) //if the postage is not 0, the 
    {
        printf("Cannot find combination!\n");
        return 0;
    }

    for (i=0; i<6;i++)
    {
        printf("$%d x %d\n",denom[i],ret[i]); //print the combination result. 
    }
    return 0;
}
