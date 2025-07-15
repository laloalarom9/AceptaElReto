#include <stdio.h>
int main()
{
    int i,nFechas,dia,mes;
    scanf("%d",&nFechas);
    for(i=0;i<nFechas;i++)
    {
        scanf("%d",&dia);
        scanf("%d",&mes);
        if((dia==25 && mes==12))
        {
            printf("SI\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    
    return 0;
}