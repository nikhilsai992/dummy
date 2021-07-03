#include "SignalsandSystems.h"
void SignalsAndSystems();
int linear_conv(int m, int n);
int circular_conv(int m, int n);
int cross_corr(int m, int n);
int auto_corr(int m);
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
            int m,n;
            printf("\n enter length of first sequence");
            scanf("%d",&m);
            printf("\n enter length of second sequence");
            scanf("%d",&n);
            int oplength1;
            oplength1=linear_conv(m,n);
            printf("\nThe length of output sequence is %d\n",oplength1);
            break;

        case 2: ;
            //
            int m2,n2;
            printf("\n enter length of first sequence");
            scanf("%d",&m2);
            printf("\n enter kength of second sequence");
            scanf("%d",&n2);
            int oplength2;
            oplength2=circular_conv(m2,n2);
            printf("\nThe length of output sequence is %d\n",oplength2);


            break;
        case 3: ;
            //
            int m3,n3;
            printf("\n enter length of first sequence");
            scanf("%d",&m3);
            printf("\n enter length of second sequence");
            scanf("%d",&n3);
            int oplength3;
            oplength3=cross_corr(m3,n3);
            printf("\nThe length of output sequence is %d\n",oplength3);
            break;
        case 4:  ;
            //
            int m4;
            printf("\n enter length of input sequence");
            scanf("%d",&m4);
            int oplength4;
            oplength4=auto_corr(m4);
            printf("\nThe length of output sequence is %d\n",oplength4);
            break;
        case 5:
            printf("Exiting Signals and Systems Menu...");
            break;
        default:
            printf("Wrong option entered. Please enter the correct choice\n");
            break;
    }
}

int linear_conv(int m,int n)
{
    int x[15],h[15],y[15];
    int i,j;
    printf("Enter values for i/p x(n):\n");
    for(i=0;i<m;i++)
    scanf("%d",&x[i]);
    printf("Enter Values for i/p h(n) \n");
    for(i=0;i<n; i++)
    scanf("%d",&h[i]);
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
       printf("\n The Value of output y[%d]=%d",i-1,y[i]);
     }
     return m+n-1;

}

int circular_conv(int m,int n)
{   int x[30],h[30],y[30],i,j, k,x2[30],a[30];
    printf(" enter the first sequence\n");
    for(i=0;i<m;i++)
    scanf("%d",&x[i]);
    printf(" enter the second sequence\n");
    for(j=0;j<n;j++)
    scanf("%d",&h[j]);
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
       m=n;
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
     return n;

}

int cross_corr(int m,int n)
{
    int x[30],h[30],y[30],i,j, k,x2[30],a[30],p,rh2[30];
    printf(" enter the first sequence\n");
    for(i=0;i<m;i++)
    scanf("%d",&x[i]);
    printf(" enter the second sequence\n");
    for(j=0;j<n;j++)
    {
      scanf("%d",&h[j]);
      
    }
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
     return m+n-1;

}

int auto_corr(int m)
{
     int x[30],h[30],y[30],i,j, k,x2[30],a[30],p,rh2[30];
    printf(" enter the input sequence\n");
    for(i=0;i<m;i++)
    scanf("%d",&x[i]);
    int n=m;int d;
    for(j=n-1,d=0;j>=0;d++,j--)
    {
      h[d]=x[j];
    }
    
    
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
     printf(" the Auto correlation is\n");
     for(i=0;i<p;i++)
     printf("%d \t",y[i]);
     return m+n-1;

 
}
