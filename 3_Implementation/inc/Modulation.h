/**
 * @file Modulation.h
 * @author Hemanth Naik H R (PS: 99004990)
 * @brief 
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __MODULATION_H__
#define __MODULATION_H__

#include<stdio.h>
#include<stdlib.h>

/**
 * @brief structure for signal
 * 
 */
typedef struct signal
{
    float amplitude; //amplitude of the signal
    float frequency; //frequency of the signal
}SIG;

/**
 * @brief function for Double sideband full carrier signal
 * 
 */
void dsb_fc(void);

/**
 * @brief function for Double sideband suppressed carrier signal
 * 
 */
void dsb_sc(void);

/**
 * @brief function for single sideband suppressed carrier signal
 * 
 */
void ssb_sc(void);

/**
 * @brief function to calculate power of DSB-FC signal
 * 
 * @param mesg_amp : amplitude of message signal
 * @param carr_amp : amplitude of carrier signal
 * @param res : load resistance
 * @return float : The final output is returned
 */
float mod_power_dsbfc(float mesg_amp, float carr_amp, float res);

/**
 * @brief function to calculate efficiency of DSB-FC signal
 * 
 * @param mesg_amp : amplitude of message signal
 * @param carr_amp : amplitude of carrier signal
 * @return float : The final output is returned
 */
float mod_efficiency_dsbfc(float mesg_amp, float carr_amp);

/**
 * @brief function to calculate bandwidth of DSB-FC signal
 * 
 * @param mesg_freq : frequency of message signal
 * @return float : The final output is returned
 */
float mod_bw_dsbfc(float mesg_freq);

/**
 * @brief function to calculate power of DSB-SC signal
 * 
 * @param mesg_amp : amplitude of message signal
 * @param carr_amp : amplitude of carrier signal
 * @param res : load resistance
 * @return float : The final output is returned
 */
float mod_power_dsbsc(float mesg_amp, float carr_amp, float res);

/**
 * @brief function to calculate efficiency of DSB-SC signal
 * 
 * @param mesg_amp : amplitude of message signal
 * @param carr_amp : amplitude of carrier signal
 * @return float : The final output is returned
 */
float mod_efficiency_dsbsc(float mesg_amp, float carr_amp);

/**
 * @brief function to calculate bandwidth of DSB-SC signal
 * 
 * @param mesg_freq : frequency of message signal
 * @return float : The final output is returned
 */
float mod_bw_dsbsc(float mesg_freq);

/**
 * @brief function to calculate power of SSB-SC signal
 * 
 * @param mesg_amp : amplitude of message signal
 * @param carr_amp : amplitude of carrier signal
 * @param res : load resistance
 * @return float : The final output is returned
 */
float mod_power_ssbsc(float mesg_amp, float carr_amp, float res);

/**
 * @brief function to calculate efficiency of SSB-SC signal
 * 
 * @param mesg_amp : amplitude of message signal
 * @param carr_amp : amplitude of carrier signal
 * @param res : load resistance
 * @return float : The final output is returned
 */
float mod_efficiency_ssbsc(float mesg_amp, float carr_amp, float res);

/**
 * @brief function to calculate bandwidth of SSB-SC signal
 * 
 * @param mesg_freq : frequency of message signal
 * @return float : The final output is returned
 */
float mod_bw_ssbsc(float mesg_freq);
/**
 * @brief Driver Code
 * 
 */
void AnalogComm();
#endif
