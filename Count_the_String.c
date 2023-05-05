//Count the string with its no. of space and word
#include<stdio.h>
#include<conio.h>
int main()
{
    char ch[56];
    int i,j,k;
    printf("Enter any String:");
    gets(ch);

    int length;
    length = strlen(ch);
    printf("The length of the string is %d", length);

    for(i=0;ch[i]!='\0';i++)
    {
        k=1;
        for(j=i+1;ch[j]!='\0';j++)
        {
            if(ch[i]==ch[j])
            {
                k++;
                ch[j]='`';
            }    
        }
        if (ch[i]!='`')
       printf("\n%c appeared - %d",ch[i],k);
        
    }

    return(0);
}
