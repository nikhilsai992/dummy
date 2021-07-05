/**
 * @file SignalsandSystems.c
 * @author Cuddapah Nikhil Sai 
 * @brief  Signals and system functionalities
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "SignalsandSystems.h"

/**
 * @brief A submenu for all the signals and systems operationss
 * 
 */
void SignalsAndSystems()
{
    int userSignalsSysOption;
    printf("****Welcome to Signals and Systems Menu****\n");
    printf("1.Linear Convolution\n2.Circular Convolution\n3.Cross Correlation\n4.Auto Correlation\n5.Exit\n");
    printf("\nEnter your choice\n");
    scanf("%d", &userSignalsSysOption);
    switch(userSignalsSysOption)
    {
        case 1:  ;
            // Linear Convolution
            int m,n,x[15],h[15];
            printf("\n enter length of first sequence");
            scanf("%d",&m);
            printf("\n enter length of second sequence");
            scanf("%d",&n);
            if((m>0&&m<8)&&(n>0&&n<8))

            {
              int i;  
              printf("Enter values for i/p x(n):\n");
            int count1=0,count2=0;
            for(i=0;i<m;i++)
            {if(scanf("%d",&x[i])==1)
            count1++;
            }
            printf("Enter Values for i/p h(n) \n");
            for(i=0;i<n; i++)
            {if(scanf("%d",&h[i])==1)
            count2++;
            
            }
            if(count1==m && count2== n){
              int oplength1=linear_conv1(m,n,x,h);
              printf("\nThe length of output sequence is %d\n",oplength1);
              break;}
              else{
              printf("Invalid Samples!!");
              break;}

            }
            else
            { printf("\nIncorrect sequence length.\n Please enter in the range of 1 to 7.\n");
            break;
            }

        case 2: ;
            // Circular Convolution
            int m2,n2,x2[30],h2[30];
            printf("\n enter length of first sequence");
            scanf("%d",&m2);
            printf("\n enter length of second sequence");
            scanf("%d",&n2);
            if((m2>0&&m2<15)&&(n2>0&&n2<15))

            {
              int i;  
              printf("Enter values for i/p x(n):\n");
            int count1=0,count2=0;
            for(i=0;i<m2;i++)
            {if(scanf("%d",&x2[i])==1)
            count1++;
            
            }
            printf("Enter Values for i/p h(n) \n");
            for(i=0;i<n2; i++)
            {if(scanf("%d",&h2[i])==1)
            count2++;
             
            
            }
            if(count1==m2 && count2== n2){
              int oplength2=circular_conv(m2,n2,x2,h2);
              printf("\nThe length of output sequence is %d\n",oplength2);
              break;}
              else{
              printf("Invalid Samples!!");
              break;}

            }
            else
            { printf("\nIncorrect sequence length.\n Please enter in the range of 1 to 14.\n");
            break;
            }



            
        case 3: ;
            // Circular Convolution
            int m3,n3,x3[30],h3[30];
            printf("\n enter length of first sequence");
            scanf("%d",&m3);
            printf("\n enter length of second sequence");
            scanf("%d",&n3);
            if((m3>0&&m3<15)&&(n3>0&&n3<15))

            {
              int i;  
              printf("Enter values for i/p x(n):\n");
            int count1=0,count2=0;
            for(i=0;i<m3;i++)
            {if(scanf("%d",&x3[i]))
            count1++;
            }
            printf("Enter Values for i/p h(n) \n");
            for(i=0;i<n3; i++)
            {if(scanf("%d",&h3[i])==1)
            count2++;
            
            }
            if(count1==m3 && count2== n3){
              int oplength3=cross_corr(m3,n3,x3,h3);
              printf("\nThe length of output sequence is %d\n",oplength3);
              break;}
              else{
              printf("Invalid Samples!!");
              break;}

            }
            else
            { printf("\nIncorrect sequence length.\n Please enter in the range of 1 to 14.\n");
            break;
            }
        case 4:  ;
            // Auto Correlation
            int m4,x4[30];
            printf("\n enter length of input sequence");
            scanf("%d",&m4);
            
            if((m4>0&&m4<15))
            {
              int it;  
              printf("Enter values for i/p x(n):\n");
            int count1=0;
            for(it=0;it<m4;it++)
            {if(scanf("%d",&x4[it])==1)
            count1++;
            
            }
            
            if(count1==m4){
              int oplength4=auto_corr(m4,x4);
              printf("\nThe length of output sequence is %d\n",oplength4);
              break;}
              else{
              printf("Invalid Samples!!");
              break;}

            }
            else
            { printf("\nIncorrect sequence length.\n Please enter in the range of 1 to 14.\n");
            break;
            }
        case 5:
            printf("Exiting Signals and Systems Menu...");
            break;
        default:
            printf("Wrong option entered. Please enter the correct choice\n");
            break;
    }
}

/**
 * @brief 
 * 
 * @param m number of samples in the first sequence
 * @param n number of samples in the second sequence
 * @param x array of first sequence
 * @param h array of second sequence
 * @return int number of output sequence samples
 */
int linear_conv1(int m, int n, int x[] , int h[])
{
    int y[15];
    int i,j;
   
   
    // padding of zeors
    for(i=m;i<=m+n-1;i++)
    x[i]=0;
    for(i=n;i<=m+n-1;i++)
    h[i]=0;
    /* convolution operation */
    for(i=0;i<m+n-1;i++)
    {
     y[i]=0;
     for(j=0;j<=i;j++)
      {
         y[i]=y[i]+(x[j]*h[i-j]);
      }
    }
     //displaying the o/p
    for(i=0;i<m+n-1;i++)
     {
       printf("%d \t",y[i]);
     }
     printf("\n");
     return m+n-1;
}

/**
 * @brief 
 * 
 * @param m number of samples in the first sequence
 * @param n number of samples in the second sequence
 * @param a array of first sequence
 * @param b array of second sequence
 * @return int number of output sequence samples
 */
int circular_conv(int m,int n,int x[],int h[])
{   int y[30],i,j, k,x2[30],a[30];
    int length;
    if(m>n)
    length=m;
    else
    length=n;

    printf(" enter the first sequence\n");
    
    if(m-n!=0) /*If length of both sequences are not equal*/
    {
       if(m>n) /* Pad the smaller sequence with zero*/
       {
        for(i=n;i<m;i++)
        h[i]=0;
        n=m;
       }
       for(i=m;i<n;i++)
       x[i]=0;
       //m=n;
    }
    y[0]=0;
    a[0]=h[0];
    for(j=1;j<n;j++) /*folding h(n) to h(-n)*/
    a[j]=h[n-j];
    /*Circular convolution*/
    for(i=0;i<n;i++)
    y[0]+=x[i]*a[i];
    for(k=1;k<n;k++)
    {
        y[k]=0;
         /*circular shift*/
        for(j=1;j<n;j++)
        x2[j]=a[j-1];
        x2[0]=a[n-1];

       for(i=0;i<n;i++)
       {
        a[i]=x2[i];
        y[k]+=x[i]*x2[i];
       }
    }
     /*displaying the result*/
     printf(" the circular convolution is\n");
     for(i=0;i<n;i++)
     printf("%d \t",y[i]);
     printf("\n");
     return length;

}

/**
 * @brief 
 * 
 * @param m number of samples in the first sequence
 * @param n number of samples in the second sequence
 * @param a array of first sequence
 * @param b array of second sequence
 * @return int number of output sequence samples
 */
int cross_corr(int m,int n, int x[], int h[])
{
    int y[30],i,j, k,x2[30],a[30],p,rh2[30];
    
   
    int d;
    for(j=n-1,d=0;j>=0;d++,j--)
    {
      rh2[d]=h[j];
    }
    for(j=0;j<n;j++)
    h[j]=rh2[j];
     /*If length of both sequences are not equal*/
     /* Pad the smaller sequence with zero*/
    p=m+n-1;
    for(i=n;i<p;i++)
    {
      h[i]=0;
    }
    for(i=m;i<p;i++)
    {
      x[i]=0;
    }

     y[0]=0;
     a[0]=h[0];
     for(j=1;j<p;j++) /*folding h(n) to h(-n)*/
     a[j]=h[p-j];
     /*Circular convolution*/
     for(i=0;i<p;i++)
     y[0]+=x[i]*a[i];
     for(k=1;k<p;k++)
     {
         y[k]=0;
         /*circular shift*/
         for(j=1;j<p;j++)
         x2[j]=a[j-1];
         x2[0]=a[p-1];
         for(i=0;i<p;i++)
         {
           a[i]=x2[i];
           y[k]+=x[i]*x2[i];
         }
     }
      /*displaying the result*/
     printf(" the cross correlation is\n");
     for(i=0;i<p;i++)
     printf("%d \t",y[i]);
     printf("\n");
     return m+n-1;

}

/**
 * @brief 
 * 
 * @param m number of samples in the input sequence
 * @param a array of input sequence
 * @return int number of output sequence samples 
 */
int auto_corr(int m,int x[])
{
     int h[30],y[30],i,j, k,x2[30],a[30],p;
    
    int n=m;int d;
    for(j=n-1,d=0;j>=0;d++,j--)
    {
      h[d]=x[j];
    }
   
    p=m+n-1;
    for(i=n;i<p;i++)
    {
      h[i]=0;
    }
    for(i=m;i<p;i++)
    {
      x[i]=0;
    }

     y[0]=0;
     a[0]=h[0];
     for(j=1;j<p;j++) /*folding x(n) to x(-n)*/
     a[j]=h[p-j];
     /*Circular convolution*/
     for(i=0;i<p;i++)
     y[0]+=x[i]*a[i];
     for(k=1;k<p;k++)
     {
         y[k]=0;
         /*circular shift*/
         for(j=1;j<p;j++)
         x2[j]=a[j-1];
         x2[0]=a[p-1];
         for(i=0;i<p;i++)
         {
           a[i]=x2[i];
           y[k]+=x[i]*x2[i];
         }
     }
      /*displaying the result*/

     printf(" the Auto correlation is\n");
     for(i=0;i<p;i++)
     printf("%d \t",y[i]);
     printf("\n");
     return m+n-1;

 
}
