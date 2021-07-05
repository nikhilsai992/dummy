#include "ResistorColorCoding.h"

/**
 * @brief list of colors
 * 
 */
char color_list[12][7] = {"black","brown","red","orange","yellow","green","blue","violet","grey","white","gold","silver"};

/**
 * @brief array of colors with their features
 * 
 */
RE_CO mul_colors[10] = {{0.01,"silver",10,0},{0.1,"gold",5,0},{1,"black",0,0},{10,"brown",1,100},{100,"red",2,50},{1000,"orange",0,15},{10000,"yellow",0,25},{100000,"green",0.5,0},{1000000,"blue",0.25,0},{10000000,"violet",0.1,0}};

void resistor_color_coding()
{
    int num_bands;
    printf("Enter num of bands : ");
    scanf("%d",&num_bands);
    if(num_bands>3&&num_bands<7)
    {
        int i;
        int arr[num_bands];
        for(i=0;i<num_bands;i++)
        {
            char color[7];
            printf("\nEnter the band %d : ",i+1);
            scanf("%s",&color);
            int resVal = calValByCol(_strlwr(*color));
            if(resVal==-1)
            {
                printf("%s is invalid colour!! Try again\n",color);
                exit(0);
            }
            arr[i] = resVal;
        }
        float resistance, tolerance,selMulValue;
        int ppm=0;
        switch(num_bands)
        {
            case 4: 
                    {
                        selMulValue = selMul(arr[2]);
                        resistance = calRes_4(arr[0],arr[1]);
                        tolerance =  tolVal(arr[3]);
                        if(selMulValue==-1||tolerance==-1)
                        {
                            printf("\nInvalid color, Select a valid color for band 3 or band 4\n\n");
                        }
                        else
                        {
                            printf("\nThe resistance is %0.2f ohms with %0.2f%c tolerance and %d ppm\n\n",resistance*selMulValue,tolerance,'%',ppm);
                        }
                        break;
                    }
            case 5:
                    {
                        selMulValue = selMul(arr[3]);
                        resistance = calRes_5_6(arr[0],arr[1],arr[2]);
                        tolerance = tolVal(arr[4]);
                        if(selMulValue==-1||tolerance==-1)
                        {
                            printf("\nInvalid color, Select a valid color for band 4 or band 5\n");
                        }
                        else
                        {
                            printf("\nThe resistance is %0.2f ohms with %0.2f%c tolerance and %d ppm\n\n",resistance*selMulValue,tolerance,'%',ppm);
                        }
                        break;
                    }
            case 6:
                    {
                        selMulValue = selMul(arr[3]);
                        resistance = calRes_5_6(arr[0],arr[1],arr[2]);
                        tolerance = tolVal(arr[4]);
                        ppm = calPPM(arr[5]);
                        if(selMulValue==-1||tolerance==-1||ppm==-1)
                        {
                            printf("\nInvalid color, Select a valid color for band 4 or band 5 or band 6\n\n");
                        }
                        else
                        {
                            printf("\nThe resistance is %0.2f ohms with %0.2f%c tolerance and %d ppm\n\n",resistance*selMulValue,tolerance,'%',ppm);
                        }
                        break;
                    }
        }
    }
    else
    {
        printf("\nInvalid input!!, Number of bands should lie between 4 and 6");
    }
}

int calValByCol(char color[])
{
    int findCol;
    for(findCol=0;findCol<12;findCol++)
    {
        if(strcmp(color,color_list[findCol])==0)
            return findCol;
    }
    return -1;
}

int calRes_5_6(int band1, int band2, int band3)
{
    return (band3+(band2+(band1*10))*10);
}

int calRes_4(int band1,int band2)
{
    return (band1*10)+band2;
}

float selMul(int band)
{
    int i;
    for(i=0;i<10;i++)
    {
        if(strcmp(color_list[band],mul_colors[i].mul_color)==0)
        {
            return mul_colors[i].mul_value;
        }
    }
    return -1;
}

float tolVal(int band)
{
    int i;
    for(i=0;i<10;i++)
    {
        if(strcmp(color_list[band],mul_colors[i].mul_color)==0)
        {
            return mul_colors[i].tol_value;
        }
    }
    return -1;
}

int calPPM(int band)
{
    int i;
    for(i=0;i<10;i++)
    {
        if(strcmp(color_list[band],mul_colors[i].mul_color)==0)
        {
            return mul_colors[i].ppm_value;
        }
    }
    return -1;
}
