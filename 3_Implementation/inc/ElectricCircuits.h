/**
 * @file ElectricCircuits.h
 * @author Adithya Vamsi (PS: 99004994)
 * @brief 
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __ELECTRICCIRCUITS_H__
#define __ELECTRICCIRCUITS_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.142 // PI value is declared to be used throughout the program

/**
 * @brief Structure to calculate resonant frequency
 * 
 */
struct resofreq
{
    float l; // Inductance
    float c; //Capacitance
};

/**
 * @brief Structure for star-delta tranformations
 * 
 */
struct stardelta
{
    float res1,res2,res3;
};

/**
 * @Function to calculate Resistance Inducatance Parallel and Capacitor Series shortened as ripcs
 * 
 * @param n: Total Number of elements 
 * @param a: Pointer pointing to the value of each element
 * @return float: The final output is returned 
 */
float ripcs(int n, float *a);

/**
 * @brief: Function to calculate Resistance Inducatance Series and Capacitor Parallel shortened as riscp
 * 
 * @param n: Total Number of elements 
 * @param a: Pointer pointing to the value of each element
 * @return float: The final output is returned 
 */
float riscp(int n, float *a);

/**
 * @brief: Function to calculate series combination of RLC Circuit
 * 
 * @param r : Resistance
 * @param l : Inductance
 * @param c : Capacitance
 * @param f : Frequency
 * @return float : The final output is returned 
 */
float RLCS(float r, float l, float c, float f);

/**
 * @brief: Function to calculate parallel combination of RLC Circuit
 * 
 * @param r : Resistance
 * @param l : Inductance
 * @param c : Capacitance
 * @param f : Frequency
 * @return float : The final output is returned 
 */
float RLCP(float r, float l, float c, float f);

/**
 * @brief 
 * 
 * @param r : Resistance
 * @param c : Capacitance
 * @param f : Frequency
 * @return float 
 */
float RCP(float r, float c, float f);

/**
 * @brief 
 * 
 * @param r : Resistance
 * @param l : Inductance
 * @param f : Frequency
 * @return float 
 */
float RLP(float r, float l, float f);

/**
 * @brief : Function to calculate Resonant Frequency
 * 
 * @param a : Structure which contains two variables for inductance and capacitance
 * @return float : The final output is returned
 */
float resfreq(struct resofreq a);

/**
 * @brief 
 * 
 * @param rx : Resistor X
 * @param ry : Resistor y
 * @param rz : Resistor Z
 * @return struct stardelta 
 */
struct stardelta star_delta(float rx,float ry,float rz);

/**
 * @brief 
 * 
 * @param r1 : Resistor 1
 * @param r2 : Resistor 2
 * @param r3 : Resistor 3
 * @return struct stardelta 
 */
struct stardelta delta_star(float r1,float r2,float r3);

/**
 * @brief Driver Code
 * 
 */
void EC();
#endif