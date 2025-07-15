#include <stdio.h>

int main()
{
    int largoMax=120;
    int largoMin=90;
    int anchoMax=90;
    int anchoMin=45;
    int areaMin,areaMax,numCasos,medida,estimacion;
    areaMax=largoMax*anchoMax;
    areaMin=largoMin*anchoMin;
    
    scanf("%d",&numCasos);
    int i,areaMinTemp,areaMaxTemp;
    for(i=0;i<numCasos;i++)
    {
        scanf("%d",&medida);
        scanf("%d",&estimacion);
        areaMaxTemp=estimacion*areaMax;
        areaMinTemp=estimacion*areaMin;
        if(medida>=areaMinTemp && medida<=areaMaxTemp)
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