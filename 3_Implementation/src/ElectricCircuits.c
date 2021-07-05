/**
 * @file ElectricCircuits.c
 * @author Adithya Vamsi (PS: 99004994)
 * @brief 
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "ElectricCircuits.h"
////////////////////////////
float ripcs(int n, float *a) //Calculates R-Parallel Comination||I-Parallel Comination||C-Series Comination
{
    float eqr;
    eqr = a[0];
    if (n == 1)
    {
        return (eqr);
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            float temp = (1 / eqr) + ((1 / a[i]));
            eqr = (1 / temp);
        }
        return eqr;
    }
}

float riscp(int n, float *a) //Calculates R-Series Comination||I-Series Comination||C-Parallel Comination
{
    if (n == 1)
    {
        return a[0];
    }
    else
    {
        float eqres = 0;
        for (int i = 0; i < n; i++)
        {
            eqres += a[i];
        }
        return eqres;
    }
}
////////////////////////////////////
//place holder for self defined function
////////////////////////////////////
float RLCS(float r, float l, float c, float f) //To Calculate RLC Series Combination
{
    float x_l=0;
    float x_c=0;
    if(l!=0){x_l = (2 * pi * f * l);}
    else{x_l=0;}
    if(c!=0){x_c = (1 / (2 * pi * f * c));}
    else{x_c=0;}
    if (!(x_l == 0 && x_c == 0))//Series RLC
    {
        float z = sqrt((pow(r, 2) + pow((x_l - x_c), 2)));
        return z;
    }
    else if(x_l==0 && x_c!=0)//Series RC
    {
        float z = sqrt((pow(r, 2) + pow((1/x_c), 2)));
        return z;
    }
    else if(x_l!=0 && x_c==0)//Series RL
    {
        float z = sqrt((pow(r, 2) + pow((x_l), 2)));
        return z;
    }
    else
    {
        return 0;
    }
}

float RLCP(float r, float l, float c, float f) //To Calculate RLC Parallel Combination
{
    double x_l, x_c;
    x_l = (2 * pi * f * l);
    x_c = (1 / (2 * pi * f * c));
    if (!(x_l == 0 && x_c == 0))
    {
        double z = sqrt((pow((1 / r), 2) + pow(((1 / x_l) - (1 / x_c)), 2)));
        if (z != 0)
        {
            return (1 / z); //To make sure division by zero is not encountered
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

float RLP(float r, float l, float f) //To Calculate RL Parallel Combination
{
    double x_l;
    x_l = (2 * pi * f * l);
    if (!(x_l == 0))
    {
        double z = sqrt((pow((1 / r), 2) + pow((1 / x_l), 2)));
        if (z != 0)
        {
            return (1 / z); //To make sure division by zero is not encountered
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

float RCP(float r, float c, float f) //To Calculate RL Parallel Combination
{
    double x_c;
    x_c = (1 / (2 * pi * f * c));
    if (!(x_c == 0))
    {
        double z = sqrt((pow((1 / r), 2) + pow((1 / x_c), 2)));
        if (z != 0)
        {
            return (1 / z); //To make sure division by zero is not encountered
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

float resfreq(struct resofreq a) //To Calculate Resonant Frequency
{
    float s = 0.0, result;
    s = a.l * a.c;
    result = sqrt(s);
    if (result != 0) //To make sure division by zero is not encountered
    {
        float freq = 1 / (2 * pi * result);
        return freq;
    }
    else
    {
        return 0;
    }
}
////////////////////////////////////
struct stardelta star_delta(float rx,float ry,float rz)
{
    struct stardelta result;
    result.res1=((rx+ry)+((rx*ry)/rz));
    result.res2=((ry+rz)+((ry*rz)/rx));
    result.res3=((rx+rz)+((rx*rz)/ry));
    
    return result;
}

struct stardelta delta_star(float r1,float r2,float r3)
{
    struct stardelta result;
    result.res1=((r1*r3)/(r1+r2+r3));
    result.res2=((r1*r2)/(r1+r2+r3));
    result.res3=((r2*r3)/(r1+r2+r3));
    
    return result;
}
////////////////////////////////////
////////////////////////////////////
void EC()
{
    int menu,sub_menu;
    typedef float f; //alias for float as f
    printf("****Welcome to Electric Circuits Menu****");
    printf("\n1. Resistor\n2. Capacitor\n3. Inductor\n4. RL / RC / RLC\n5. Resonant Frequency\n6. Star<->Delta Transformation\n7. Exit\n");
    printf("Please enter the preferred option:\n");
    scanf("%d", &menu); //get main-menu input

    //Function Pointers
    f (*series_resistor)(int, f *) = &riscp;
    f (*parallel_resistor)(int, f *) = &ripcs;
    f (*series_inductor)(int, f *) = &riscp;
    f (*parallel_inductor)(int, f *) = &ripcs;
    f (*series_capacitor)(int, f *) = &ripcs;
    f (*parallel_capacitor)(int, f *) = &riscp;

    switch (menu)
    {
    case 1: //For RESISTANCE
    {
        printf("SUBMENU:\n");
        printf("1. Series Resistance\n2. Parallel Resistance\n");
        printf("Please enter the preferred option:\n");
        scanf("%d", &sub_menu); //get sub-menu input
        switch (sub_menu)
        {
        case 1:
        {/**
         * @brief Series Resistance Calculation
         * 
         */
            int n; /*  number of resistors   */
            printf("enter number of Resistors\n");
            scanf("%d", &n);
            if (n == 0 || n>100)
            {
                printf("Invalid Input!! Try Again\n");
            }
            else
            {
                float *a = (float *)malloc(n * sizeof(float)); /* Dynamic Array Declaration  */
                // f a[n];
                for (int i = 0; i < n; i++) // loop to get indviduval impedance
                {
                    printf("enter resistance %d(unit in ohms)\n ", (i + 1));
                    if(scanf("%f", &a[i])==1);
                    else
                    {
                        printf("Invalid Input!! Try Again\n");
                        exit(0);
                    }
                }
                f res = (*series_resistor)(n, a);
                printf("\nequivalent series resistance = %f\n", res);
                free(a);
            }
            break;
        }

        case 2:
        {/**
         * @brief Parallel Resistance Calculation
         * 
         */
            int n; /*  number of resistors   */
            printf("enter number of Resistors\n");
            scanf("%d", &n);
            if (n == 0 || n>100)
            {
                printf("Invalid Input!! Try Again\n");
            }
            else
            {
                float *a = (float *)malloc(n * sizeof(float)); /* Dynamic Array Declaration  */
                //f a[n];
                for (int i = 0; i < n; i++) // loop to get indviduval impedance
                {
                    printf("enter resistance %d(unit in ohms)\n ", (i + 1));
                    if(scanf("%f", &a[i])==1);
                    else
                    {
                        printf("Invalid Input!! Try Again\n");
                        exit(0);
                    }
                }
                f res = (*parallel_resistor)(n, a);
                printf("\nequivalent parallel resistance = %f\n", res);
                free(a);
            }
            break;
        }
        default: //For Incorrect Inputs
        {
            printf("Oops! You have entered an invalid choice, Kindly try again !!");
            break;
        }
        }
        break;
    }
    case 2: //For CAPACITANCE
    {
        printf("SUBMENU:\n");
        printf("1. Series Capacitance\n2. Parallel Capacitance\n");
        printf("Please enter the preferred option:\n");
        scanf("%d", &sub_menu); //get sub-menu input
        switch (sub_menu)
        {
        case 1:
        {/**
         * @brief Series CAPACITANCE Calculation
         * 
         */
            int n; /*  number of resistors   */
            printf("enter number of Capacitors\n");
            scanf("%d", &n);
            if (n == 0 || n>100)
            {
                printf("Invalid Input!! Try Again\n");
            }
            else
            {
                float *a = (float *)malloc(n * sizeof(float)); /* Dynamic Array Declaration  */
                //f a[n];
                for (int i = 0; i < n; i++) // loop to get indviduval impedance
                {
                    printf("enter Capacitance %d(unit in farad)\n ", (i + 1));
                    if(scanf("%f", &a[i])==1);
                    else
                    {
                        printf("Invalid Input!! Try Again\n");
                        exit(0);
                    }
                }
                f res = (*series_capacitor)(n, a);
                printf("\nequivalent Series Capacitance = %f\n", res);
                free(a);
            }
            break;
        }

        case 2:
        {/**
         * @brief Parallel CAPACITANCE Calculation
         * 
         */
            int n; /*  number of resistors   */
            printf("enter number of Capacitors\n");
            scanf("%d", &n);
            if (n == 0 || n>100)
            {
                printf("Invalid Input!! Try Again\n");
            }
            else
            {
                float *a = (float *)malloc(n * sizeof(float)); /* Dynamic Array Declaration  */
                //f a[n];
                for (int i = 0; i < n; i++) // loop to get indviduval impedance
                {
                    printf("enter Capacitance %d(unit in farad)\n ", (i + 1));
                    if(scanf("%f", &a[i])==1);
                    else
                    {
                        printf("Invalid Input!! Try Again\n");
                        exit(0);
                    }
                }
                f res = (*parallel_capacitor)(n, a);
                printf("\nequivalent Parallel Capacitance = %f\n", res);
                free(a);
            }
            break;
        }
        default: //For Incorrect Inputs
        {
            printf("Oops! You have entered an invalid choice, Kindly try again !!");
            break;
        }
        }
        break;
    }
    case 3: //For INDUCTANCE
    {
        printf("SUBMENU:\n");
        printf("1. Series Indutance\n2. Parallel Inductance\n");
        printf("Please enter the preferred option:\n");
        scanf("%d", &sub_menu); //get sub-menu input
        switch (sub_menu)
        {
        case 1:
        {/**
         * @brief Series INDUCTANCE Calculation
         * 
         */
            int n; /*  number of resistors   */
            printf("enter number of Inductors\n");
            scanf("%d", &n);
            if (n == 0 || n>100)
            {
                printf("Invalid Input!! Try Again\n");
            }
            else
            {
                float *a = (float *)malloc(n * sizeof(float)); /* Dynamic Array Declaration  */
                //f a[n];                 /* Dynamic Array Declaration  */
                for (int i = 0; i < n; i++) // loop to get indviduval impedance
                {
                    printf("enter Inductance %d(unit in henry)\n ", (i + 1));
                    if(scanf("%f", &a[i])==1);
                    else
                    {
                        printf("Invalid Input!! Try Again\n");
                        exit(0);
                    }
                }
                f res = (*series_inductor)(n, a);
                printf("\nequivalent Series Indutance = %f\n", res);
                free(a);
            }
            break;
        }

        case 2:
        {/**
         * @brief Parallel INDUCTANCE Calculation
         * 
         */
            int n; /*  number of resistors   */
            printf("enter number of Inductors\n");
            scanf("%d", &n);
            if (n == 0 || n>100)
            {
                printf("Invalid Input!! Try Again\n");
            }
            else
            {
                float *a = (float *)malloc(n * sizeof(float)); /* Dynamic Array Declaration  */
                //f a[n];
                for (int i = 0; i < n; i++) // loop to get indviduval impedance
                {
                    printf("enter Inductance %d(unit in henry)\n ", (i + 1));
                    if(scanf("%f", &a[i])==1);
                    else
                    {
                        printf("Invalid Input!! Try Again\n");
                        exit(0);
                    }
                }
                f res = parallel_inductor(n, a);
                printf("\nequivalent Parallel Inductance = %f\n", res);
                free(a);
            }
            break;
        }
        default: //For Incorrect Inputs
        {
            printf("Oops! You have entered an invalid choice, Kindly try again !!");
            break;
        }
        }
        break;
    }
    case 4: //For RL / RC / RLC
    {
        printf("SUBMENU:\n");
        printf("1. RLC Series Impedance\n2. RLC Parallel Impedance\n3. RL Series Impedance\n4. RL Parallel Impedance\n 5. RC Series Impedance\n6. RC Parallel Impedance\n");
        printf("Please enter the preferred option:\n");
        scanf("%d", &sub_menu); //get sub-menu input
        switch (sub_menu)
        {
        case 1:
        {/**
         * @brief Series RLC Impedance Calculation
         * 
         */
            double r, l, c, fq; //Inputs
            printf("Enter the value of R(unit in ohm):\n");
            if(scanf("%lf", &r)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter the value of L(unit in henry):\n");
            if(scanf("%lf", &l)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter the value of C(unit in farad):\n");
            if(scanf("%lf", &c)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter the value of f(unit in hertz):\n");
            if(scanf("%lf", &fq)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            if (l != 0 && c != 0 && fq != 0) //To make sure division by zero is not encountered
            {
                f res = RLCS(r, l, c, fq);
                printf("Equivalent Series Impedance:%f ohms\n", res);
            }
            else
            {
                printf("Invalid Input!! Try Again\n");
            }
            break;
        }

        case 2:
        {/**
         * @brief Parallel RLC Impedance Calculation
         * 
         */
            double r, l, c, fq; //Inputs
            printf("Enter the value of R(unit in ohm):\n");
            if(scanf("%lf", &r)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter the value of L(unit in henry):\n");
            if(scanf("%lf", &l)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter the value of C(unit in farad):\n");
            if(scanf("%lf", &c)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter the value of f(unit in hertz):\n");
            if(scanf("%lf", &fq)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            if (l != 0 && c != 0 && fq != 0) //To make sure division by zero is not encountered
            {
                f res = RLCP(r, l, c, fq);
                printf("Equivalent Parallel Impedance:%f ohms\n", res);
            }
            else
            {
                printf("Invalid Input!! Try Again\n");
            }
            break;
        }
        case 3:
        {/**
         * @brief Series RL Impedance Calculation
         * 
         */
            double r, l, fq; //Inputs
            printf("Enter the value of R(unit in ohm):\n");
            if(scanf("%lf", &r)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter the value of L(unit in henry):\n");
            if(scanf("%lf", &l)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter the value of f(unit in hertz):\n");
            if(scanf("%lf", &fq)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            if (l != 0 && fq != 0) //To make sure division by zero is not encountered
            {
                f res = RLCS(r, l, 0.0, fq);
                printf("Equivalent Series Impedance:%f ohms\n", res);
            }
            else
            {
                printf("Invalid Input!! Try Again\n");
            }
            break;
        }

        case 4:
        {/**
         * @brief Parallel RL Impedance Calculation
         * 
         */
            double r, l, fq; //Inputs
            printf("Enter the value of R(unit in ohm):\n");
            if(scanf("%lf", &r)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter the value of L(unit in henry):\n");
            if(scanf("%lf", &l)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter the value of f(unit in hertz):\n");
            if(scanf("%lf", &fq)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            if (l != 0  && fq != 0) //To make sure division by zero is not encountered
            {
                f res = RLP(r, l, fq);
                printf("Equivalent Parallel Impedance:%f ohms\n", res);
            }
            else
            {
                printf("Invalid Input!! Try Again\n");
            }
            break;
        }
        case 5:
        {/**
         * @brief Series RC Impedance Calculation
         * 
         */
            double r, c, fq; //Inputs
            printf("Enter the value of R(unit in ohm):\n");
            if(scanf("%lf", &r)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            
            printf("Enter the value of C(unit in farad):\n");
            if(scanf("%lf", &c)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter the value of f(unit in hertz):\n");
            if(scanf("%lf", &fq)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            if ( c != 0 && fq != 0) //To make sure division by zero is not encountered
            {
                f res = RLCS(r, 0.0, c, fq);
                printf("Equivalent Series Impedance:%f ohms\n", res);
            }
            else
            {
                printf("Invalid Input!! Try Again\n");
            }
            break;
        }

        case 6:
        {/**
         * @brief Parallel RC Impedance Calculation
         * 
         */
            double r, c, fq; //Inputs
            printf("Enter the value of R(unit in ohm):\n");
            if(scanf("%lf", &r)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }

            printf("Enter the value of C(unit in farad):\n");
            if(scanf("%lf", &c)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter the value of f(unit in hertz):\n");
            if(scanf("%lf", &fq)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            if (c != 0 && fq != 0) //To make sure division by zero is not encountered
            {
                f res = RCP(r, c, fq);
                printf("Equivalent Parallel Impedance:%f ohms\n", res);
            }
            else
            {
                printf("Invalid Input!! Try Again\n");
            }
            break;
        }
        default: //For Incorrect Inputs
        {
            printf("Oops! You have entered an invalid choice, Kindly try again !!");
            break;
        }
        }
        break;
    }
    case 5: //For RESONANT FREQUENCY
    {
        struct resofreq a; //Inputs
        printf("Enter the value of L(unit in henry):\n");
        if(scanf("%f", &a.l)==1);
        else
        {
            printf("Invalid Input!! Try Again\n");
            exit(0);
        }
        printf("Enter the value of C(unit in farad):\n");
        if(scanf("%f", &a.c)==1);
        else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
        if (a.l != 0 && a.c != 0) //To make sure division by zero is not encountered
        {
            f res = resfreq(a);
            printf("Resonant Frequency: %f\n", res);
        }
        else
        {
            printf("Invalid Input!! Try Again\n");
        }

        break;
    }
    case 6:
    {
        printf("SUBMENU:\n");
        printf("1. Star to Delta Transformation\n2. Delta to Star Transformation\n");
        printf("Please enter the preferred option:\n");
        scanf("%d", &sub_menu); //get sub-menu input
        switch (sub_menu)
        {
        case 1:
        {/**
         * @brief Star to Delta Calculation
         * 
         */
            float rx,ry,rz; /*  resistances   */
            printf("Enter Rx:\n");
            if(scanf("%f", &rx)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter Ry:\n");
            if(scanf("%f", &ry)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter Rz:\n");
            if(scanf("%f", &rz)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            if (rx==0 && ry==0 && rz==0)
            {
                printf("Invalid Input!! Try Again\n");
            }
            else
            {
                struct stardelta results = star_delta(rx,ry,rz);
                printf("\nR1=%f   R2=%f    R3=%f\n", results.res1, results.res2, results.res3);
            }
            break;
        }

        case 2:
        {/**
         * @brief Delta to Star Calculation
         * 
         */
            float r1,r2,r3; /*  resistances   */
            printf("Enter R1:\n");
            if(scanf("%f", &r1)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter R2:\n");
            if(scanf("%f", &r2)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            printf("Enter R3:\n");
            if(scanf("%f", &r3)==1);
            else
            {
                printf("Invalid Input!! Try Again\n");
                exit(0);
            }
            if (r1==0 && r2==0 && r3==0)
            {
                printf("Invalid Input!! Try Again\n");
            }
            else
            {
                struct stardelta results = delta_star(r1,r2,r3);
                printf("\nRx=%f   Ry=%f    Rz=%f\n", results.res1, results.res2, results.res3);
            }
            break;
        }
        default: //For Incorrect Inputs
        {
            printf("Oops! You have entered an invalid choice, Kindly try again !!");
            break;
        }
        }
        break;
    }
    case 7: //For EXITING THE APPLICATION
    {
        printf("\nThanks for using the application\nHope to see you soon, byeee!\n");
        break;
    }
    default: //For Incorrect Inputs
    {
        printf("Oops! You have entered an invalid choice, Kindly try again !!");
        break;
    }
    }
}