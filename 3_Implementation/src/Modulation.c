#include "Modulation.h"


void AnalogComm()
{
    int sig_choice;
    printf("****\n\nWelcome to Analog Communication System of ECE EvalEngine****\n\n");
    printf("Select the required signal from the list below to find Efficiency or Power\n\n");
    printf("1. DSB FC(double SideBand Full Carrier)\n2. DSB SC(double SideBand Suppressed carrier)\n3. SSB SC(Single SideBand Suppressed carrier)\n4. Exit\n\n");
    if(scanf("%d",&sig_choice)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    switch (sig_choice)
    {
    case 1: dsb_fc();
            break;
    case 2: dsb_sc();
            break;
    case 3: ssb_sc();
            break;
    case 4: printf("Exiting...\n");
            exit(0);
            break;
    
    default: printf("\nInvalid choice, select a valid option\n");
        break;
    }
}

void dsb_fc()
{
    SIG message,carrier;
    float R;
    int dsbfc_choice, invalid = 1;
    printf("****DSB-FC****\n");
    printf("\nEnter Amplitude Am and frequency fm of the message signal from the signal format Am*cos(2*pi*fm*t) : \n");
    if(scanf("%f",&message.amplitude)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    if(scanf("%f",&message.frequency)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    printf("\nEnter Amplitude Ac and frequency fc of the carrier signal from the signal format Ac*cos(2*pi*fc*t) : \n");
    if(scanf("%f",&carrier.amplitude)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    if(scanf("%f",&carrier.frequency)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    printf("\nEnter the load Resistance : ");
    if(scanf("%f",&R)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    float bandwidth = mod_bw_dsbfc(message.frequency);
    printf("\n\nEnter\n1. To find power\n2. To find efficiency\n\n");
    scanf("%d",&dsbfc_choice);
    switch (dsbfc_choice)
    {
        case 1:
        {           
            float power = mod_power_dsbfc(message.amplitude, carrier.amplitude, R);
            if(power == -1)
            {
                printf("Enter a valid amplitude value\n");
            }
            else if(power == -2)
            {
                printf("Enter a valid resistance value\n");
            }
            else
            {
                invalid = 0;
                printf("Power: %0.2f W\n",power);
            }
            break;
        }

        case 2:   
        {
            float efficiency = mod_efficiency_dsbfc(message.amplitude,carrier.amplitude);
            if(efficiency==-1)
            {
                printf("Enter a valid amplitude value\n");
            }
            else
            {
                invalid = 0;
                printf("Efficiency: %0.2f\n",efficiency);
            }
            break;
        }
            
        default:    
        {
            printf("Enter a valid choice\n");
            break;
        }
    }
    if(invalid == 0)
    {
        if(bandwidth!=-1)
        {
            printf("Bandwidth: %0.2f Hz",bandwidth);
        }
        else
        {
            printf("Message frequency cannot be negative\n");
        }
    }
}

float mod_power_dsbfc(float mesg_amp, float carr_amp, float res)
{
    if(carr_amp<=0 || mesg_amp<=0)
    {
        return -1;
    }
    else if(res<=0)
    {
        return -2;
    }
    float mod_index = mesg_amp/carr_amp;
    float MI_sqr = mod_index*mod_index;
    float carr_power = (carr_amp*carr_amp)/(2*res);
    float power_dsbfc = carr_power*(1+(MI_sqr/2));
    return power_dsbfc;
}

float mod_efficiency_dsbfc(float mesg_amp, float carr_amp)
{
    if(carr_amp<=0 || mesg_amp<=0)
    {
        return -1;
    }
    float mod_index = mesg_amp/carr_amp;
    float efficiency_dsbfc = mod_index*mod_index/(2+mod_index*mod_index);
    return efficiency_dsbfc*100;
}

float mod_bw_dsbfc(float mesg_freq)
{
    if(mesg_freq>=0)
    {  
        return 2*mesg_freq;
    }
    return -1;
}

void dsb_sc()
{
    SIG message,carrier;
    float R;
    int dsbsc_choice, invalid = 1;
    printf("****DSB-SC****\n");
    printf("\nEnter Amplitude Am and frequency fm of the message signal from the signal format Am*cos(2*pi*fm*t) : \n");
    if(scanf("%f",&message.amplitude)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    if(scanf("%f",&message.frequency)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    printf("\nEnter Amplitude Ac and frequency fc of the carrier signal from the signal format Ac*cos(2*pi*fc*t) : \n");
    if(scanf("%f",&carrier.amplitude)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    if(scanf("%f",&carrier.frequency)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    printf("\nEnter the load Resistance : ");
    if(scanf("%f",&R)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    float bandwidth = mod_bw_dsbsc(message.frequency);
    printf("\n\nEnter\n1. To find power\n2. To find efficiency\n\n");
    scanf("%d",&dsbsc_choice);
    switch (dsbsc_choice)
    {
        case 1:
        {           
            float power = mod_power_dsbsc(message.amplitude, carrier.amplitude, R);
            if(power==-1)
            {
                printf("Enter a valid amplitude value\n");
            }
            else if(power==-2)
            {
                printf("Enter a valid resistance value\n");
            }
            else
            {
                invalid = 0;
                printf("Power: %0.2f W",power);
            }
            break;
        }

        case 2:   
        {
            float efficiency = mod_efficiency_dsbsc(message.amplitude,carrier.amplitude);
            if(efficiency == -1)
            {
                printf("Enter a valid amplitude value\n");
            }
            else
            {
                invalid = 0;
                printf("Efficiency: %0.2f ",efficiency);
            }
            break;
        }
            
        default:    
        {
            printf("Enter a valid choice\n");
            break;
        }
    }
    if(invalid==0)
    {
        if(bandwidth!=-1)
        {
            printf("\nBandwidth: %0.2f Hz\n",bandwidth);
        }
        else
        printf("Message frequency cannot be negative\n");
    }
}

float mod_power_dsbsc(float mesg_amp, float carr_amp, float res)
{
    if(mesg_amp<=0 || carr_amp<=0)
    {
        return -1; 
    }
    else if(res<=0)
    {
        return -2;
    }
    float power_dsbsc = (mesg_amp*mesg_amp*carr_amp*carr_amp)/(4*res);
    return power_dsbsc;
}

float mod_efficiency_dsbsc(float mesg_amp, float carr_amp)
{
    if(carr_amp<=0 || mesg_amp<=0)
    {
        return -1;
    }
    float mod_index = 2;
    float efficiency_dsbsc = mod_index/(2+mod_index);
    return efficiency_dsbsc*100;
}

float mod_bw_dsbsc(float mesg_freq)
{
    if(mesg_freq>=0)
    {  
        return 2*mesg_freq;
    }
    return -1;
}

void ssb_sc()
{
    SIG message,carrier;
    float R;
    int ssbsc_choice, invalid = 1;
    printf("****SSB-SC****\n");
    printf("\nEnter Amplitude Am and frequency fm of the message signal from the signal format Am*cos(2*pi*fm*t) : \n");
    if(scanf("%f",&message.amplitude)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    if(scanf("%f",&message.frequency)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    printf("\nEnter Amplitude Ac and frequency fc of the carrier signal from the signal format Ac*cos(2*pi*fc*t) : \n");
    if(scanf("%f",&carrier.amplitude)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    if(scanf("%f",&carrier.frequency)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    printf("\nEnter the load Resistance : ");
    if(scanf("%f",&R)==1);
    else
    {
        printf("Invalid Input!! Try again\n");
        exit(0);
    }
    printf("\n\nEnter\n1. To find power\n2. To find efficiency\n\n");
    float bandwidth = mod_bw_ssbsc(message.frequency);
    scanf("%d",&ssbsc_choice);
    switch (ssbsc_choice)
    {
        case 1:
        {           
            float power = mod_power_ssbsc(message.amplitude, carrier.amplitude, R);
            if(power==-1)
            {
                printf("Invalid amplitude value!! Try again\n");
            }
            else if(power == -2)
            {
                printf("Enter a valid resistance value\n");
            }
            else
            {
                invalid = 0;
                printf("Power: %0.2f W\n",power);
            }
            break;
        }

        case 2:   
        {
            float efficiency = mod_efficiency_ssbsc(message.amplitude,carrier.amplitude, R);
            if(efficiency == -1)
            {
                printf("Invalid amplitude value!! Try again\n");
            }
            else if(efficiency == -2)
            {
                printf("Enter a valid resistance value\n");
            }
            else
            {
                invalid = 0;
                printf("Efficiency: %0.2f",efficiency);
            }
            break;
        }
            
        default:    
        {
            printf("Enter a valid choice\n");
            break;
        }
    }
    if(invalid==0)
    {
        if(bandwidth!=-1)
        {
            printf("\nBandwidth: %0.2f Hz\n",bandwidth);
        }
        else
        {
            printf("Message frequency cannot be negative\n");
        }
    }
}

float mod_power_ssbsc(float mesg_amp, float carr_amp, float res)
{
    if(mesg_amp<=0 || carr_amp<=0)
    {
        return -1; 
    }
    else if(res<=0)
    {
        return -2;
    }
    float power_ssbsc = (mesg_amp*mesg_amp*carr_amp*carr_amp)/(8*res);
    return power_ssbsc;   
}

float mod_efficiency_ssbsc(float mesg_amp, float carr_amp, float res)
{
    if(mesg_amp<=0 || carr_amp<=0)
    {
        return -1; 
    }
    else if(res<=0)
    {
        return -2;
    }
    float ssbsc_carr_power = (mesg_amp*mesg_amp*carr_amp*carr_amp)/(8*res);
    float efficiency_ssbsc = ssbsc_carr_power/mod_power_ssbsc(mesg_amp,carr_amp,res);
    return efficiency_ssbsc*100;
}

float mod_bw_ssbsc(float mesg_freq)
{
    if(mesg_freq>=0)
        return mesg_freq;
    return -1;
}
