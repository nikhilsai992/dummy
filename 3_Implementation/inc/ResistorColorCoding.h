#ifndef __RESISTORCOLORCODING_H__
#define __RESISTORCOLORCODING_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/**
 * @brief features of color band
 * 
 */
typedef struct mult
{
    float mul_value;
    char mul_color[7];
    float tol_value;
    float ppm_value;
}RE_CO;


/**
 * @brief calculate index value by color
 * 
 * @param color 
 * @return int 
 */
int calValByCol(char color[]);

/**
 * @brief calculate resistance based on first 3 bands
 * 
 * @param band1 
 * @param band2 
 * @param band3 
 * @return int 
 */
int calRes_5_6(int band1, int band2, int band3);

/**
 * @brief calculate resistance based on first 2 bands
 * 
 * @param band1 
 * @param band2 
 * @return int 
 */
int calRes_4(int band1,int band2);

/**
 * @brief selects the multiplier based on band color
 * 
 * @param band 
 * @return float 
 */
float selMul(int band);

/**
 * @brief calculates tolerance value based on band color
 * 
 * @param band 
 * @return float 
 */
float tolVal(int band);

/**
 * @brief calculates PPM value based on band color
 * 
 * @param band 
 * @return int 
 */
int calPPM(int band);

/**
 * @brief driver code
 * 
 */
void resistor_color_coding();

#endif
