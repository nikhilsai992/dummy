/**
 * @file SignalsandSystems.h
 * @author Cuddapah Nikhil Sai
 * @brief This header file contains the definitions of all the functions used in the Signals and Systems code
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __SIGNALSANDSYSTEMS_H__
#define __SIGNALSANDSYSTEMS_H__



#include <stdio.h>
#include <stdlib.h>

/**
 * @brief A submenu for all the signals and systems operations
 * 
 */
void SignalsAndSystems(void);

/**
 * @brief 
 * 
 * @param m number of samples in the first sequence
 * @param n number of samples in the second sequence
 * @param x array of first sequence
 * @param h array of second sequence
 * @return int number of output sequence samples
 */
int linear_conv1(int m, int n, int a[] , int b[]);

/**
 * @brief 
 * 
 * @param m number of samples in the first sequence
 * @param n number of samples in the second sequence
 * @param a array of first sequence
 * @param b array of second sequence
 * @return int number of output sequence samples
 */
int circular_conv(int m,int n,int a[],int b[]);

/**
 * @brief 
 * 
 * @param m number of samples in the first sequence
 * @param n number of samples in the second sequence
 * @param a array of first sequence
 * @param b array of second sequence
 * @return int number of output sequence samples
 */
int cross_corr(int m, int n, int a[] , int b[]);

/**
 * @brief 
 * 
 * @param m number of samples in the input sequence
 * @param a array of input sequence
 * @return int number of output sequence samples 
 */
int auto_corr(int m,int a[]);


#endif
