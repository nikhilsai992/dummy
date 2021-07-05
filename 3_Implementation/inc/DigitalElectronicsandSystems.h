/**
 * @file DigitalElectronicsandSystems.h
 * @author Somya Gupta
 * @brief This header file contains the definitions of all the functions used in the Digital ELectronics and Systems code
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __DIGITALELECTRONICSANDSYSTEMS_H__
#define __DIGITALELECTRONICSANDSYSTEMS_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/**
 * @brief This function is called when option number 4 is selected from the main driver code. This function contains all the required code to carry out the Digital systems feature of the project
 * 
 */
void DigitalSystems();
/**
 * @brief This function accepts a long int binary number which is used to convert it to a hexadecimal number and returned
 * 
 * @param binaryNumber 
 * @return long int 
 */
long int binToHexa(long int binaryNumber);
/**
 * @brief This function accepts a hexadecimal number in character array form along with the size of the array and prints the respective binary number
 * 
 * @param hexadecimalNum 
 * @param size 
 */
void hexaToBin(char hexadecimalNum[], int size);
/**
 * @brief This function accepts a long int binary number which is used to convert it to a octal number and is returned
 * 
 * @param binaryNum 
 * @return long int 
 */
long int binToOcta(long int binaryNum);
/**
 * @brief This function accepts a long int octal number and converts it to a binary number
 * 
 * @param octalNum 
 * @return long int 
 */
long int octaToBin(int octalNum);
/**
 * @brief This function accepts a long int decimal number and converts it to the respective octal number
 * 
 * @param decimalNumber 
 * @return long int 
 */
long int decToOcta(long int decimalNumber);
/**
 * @brief This function accepts a long int octal number and converts it to its respective decimal number
 * 
 * @param octalNumber 
 * @return long int 
 */
long int octaToDec(long int octalNumber);
/**
 * @brief This function accepts a long int binary number and converts it to the respective gray code and is returned
 * 
 * @param binaryNumber 
 * @return long int 
 */
long int binToGray(long int binaryNumber);
/**
 * @brief This function accepts a long int binary number and returns the converted decimal number
 * 
 * @param binaryNum 
 * @return long int 
 */
long int binToDec(long int binaryNum);
/**
 * @brief This function accepts a long int decimal number and returns the converted binary number
 * 
 * @param decimalNum 
 * @return long int 
 */
long int decToBin(long int decimalNum);
/**
 * @brief This function is used to accept a binary number and prints its 1's complement
 * 
 * @param binaryNum 
 * @param numOfBits 
 */
void onesComplement(char binaryNum[], int numOfBits);
/**
 * @brief This function is used to accept a binary number and prints its 2's complement
 * 
 * @param binaryNum 
 * @param numOfBits 
 */
void twosComplement(char binaryNum[], int numOfBits);
/**
 * @brief This function accepts two binary numbers as its arguments and return their sum
 * 
 * @param binaryNumber1 
 * @param binaryNumber2 
 */
void sumOfBin(long int binaryNumber1, long int binaryNumber2);
/**
 * @brief This function is used to check whether the given number is binary or not
 * 
 * @param binaryNum 
 * @return int 
 */
int binaryNumberValidator(long int binaryNum);

#endif