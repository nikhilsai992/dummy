#ifndef __SIGNALSANDSYSTEMS_H__
#define __SIGNALSANDSYSTEMS_H__

#include <stdio.h>
#include <stdlib.h>

void SignalsAndSystems(void);
int linear_conv(int m, int n);
int circular_coonv(int m,int n);
int cross_corr(int m, int n);
int auto_corr(int m);
#endif
