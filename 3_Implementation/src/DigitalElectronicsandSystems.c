/**
 * @file DigitalElectronicsandSystems.c
 * @author Somya Gupta
 * @brief This source file contains the entire code for the Digital Electronics and systems feature of the system.
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "DigitalElectronicsandSystems.h"

void DigitalSystems()
{
    /**
     * @brief Used to accept the user input for selecting any one of the given options from the submenu of Digital Electronics and systems
     * 
     */
    int userDigitalEcOption;
    printf("****Welcome to Digital Electronics and Systems Menu****\n");
    printf("1.Binary to Hexadecimal or Hexadecimal to Binary\n2.Binary to Octal or Octal to Binary\n3.Decimal to Octal or Octal to Decimal\n4.Binary to Gray Code\n5.Binary to Decimal or Decimal to Binary\n6.Find 1s complement of a number\n7.Find 2s complement of a number\n8.Sum of binary numbers\n9.Exit\n");
    printf("Enter your choice\n");
    scanf("%d", &userDigitalEcOption);
    /**
     * @brief Construct a new switch object to go to any of the given cases based on the user input
     * 
     */
    switch(userDigitalEcOption)
    {
        case 1:
            printf("Enter 1 for Binary to Hexadecimal\nEnter 2 for Hexadecimal to Binary\n");
            printf("Enter your choice: ");
            /**
             * @brief case1opt is used for taking user input for the given choices
             * 
             */
            int case1opt;
            scanf("%d", &case1opt);
            switch(case1opt)
            {
                case 1:
                    /**
                     * @brief this case is used for converting binary to hexadecimal
                     * 
                     */
                    printf("Please enter the Binary Number: ");
                    long int binaryNumForBinToHex;
                    scanf("%ld", &binaryNumForBinToHex);
                    if(binaryNumberValidator(binaryNumForBinToHex))
                    {
                        printf("%lX\n", binToHexa(binaryNumForBinToHex));
                    }
                    else
                    {
                        printf("Invalid Input. Kindly Enter the correct input.\n");
                    }
                    break;
                case 2:
                    /**
                     * @brief this case is used for converting hexadecimal to binary
                     * 
                     */
                    printf("Please Enter the hexadecimal number: ");
                    char hexadecimalNumForHexToBin[17];
                    scanf("%s",&hexadecimalNumForHexToBin);
                    hexaToBin(hexadecimalNumForHexToBin, 17); 
                    break;
                default:
                    printf("Wrong Option Entered. Please Enter the correct option.\n");
                    break;
            }
            break;
        case 2:
            printf("Enter 1 for Binary to Octal\nEnter 2 for Octal to Binary\n");
            /**
             * @brief case2opt is used for taking user input for the given choices
             * 
             */
            int case2opt;
            printf("Enter your choice: ");
            scanf("%d", &case2opt);
            switch(case2opt)
            {
                case 1:
                    /**
                     * @brief this case is used for converting binary to Octal
                     * 
                     */
                    printf("Please enter the Binary Number: ");
                    long int binaryNumForBinToOct;
                    scanf("%ld", &binaryNumForBinToOct);
                    if(binaryNumberValidator(binaryNumForBinToOct))
                    {
                        printf("%ld", binToOcta(binaryNumForBinToOct));
                    }
                    else
                    {
                        printf("Invalid Input. Kindly Enter the correct input.\n");
                    }
                    break;
                case 2:
                    /**
                     * @brief this case is used for converting Octal to binary
                     * 
                     */
                    printf("Please Enter the octal number: ");
                    long int octalNumForOctToBin;
                    scanf("%ld", &octalNumForOctToBin);
                    printf("%ld", octaToBin(octalNumForOctToBin));
                    break;
                default:
                    printf("Wrong Option Entered. Please Enter the correct option.\n");
                    break;
            }
            break;
        case 3:
            printf("Enter 1 for Decimal to Octal\nEnter 2 for Octal to Decimal\n");
            /**
             * @brief case3opt is used for taking user input for the given choices
             * 
             */
            int case3opt;
            printf("Enter your choice: ");
            scanf("%d", &case3opt);
            switch(case3opt)
            {
                case 1:
                    /**
                     * @brief this case is used for converting Decimal to Octal number
                     * 
                     */
                    printf("Please Enter the decimal number: ");
                    long int decimalNumForDecToOct;
                    scanf("%ld", &decimalNumForDecToOct);
                    printf("%ld", decToOcta(decimalNumForDecToOct));
                    break;
                case 2:
                    /**
                     * @brief this case is used for converting octal to decimal number
                     * 
                     */
                    printf("Please Enter the octal number: ");
                    long int octalNumForOctToDec;
                    scanf("%ld", &octalNumForOctToDec);
                    printf("%ld", octaToDec(octalNumForOctToDec));
                    break;
                default:
                    printf("Wrong Option Entered. Please Enter the correct option.\n");
                    break;
            }
            break;
        case 4:
            printf("Please Enter the binary number: ");
            /**
             * @brief This case is used for converting binary to gray code
             * 
             */
            long int binaryNumForBinToGray;
            scanf("%ld", &binaryNumForBinToGray);
            if(binaryNumberValidator(binaryNumForBinToGray))
            {
                printf("The gray code of %ld", binToGray(binaryNumForBinToGray));
            }
            else
            {
                printf("Invalid Input. Kindly Enter the correct input.\n");
            }
            break;
        case 5:
            printf("Enter 1 for Binary to Decimal\nEnter 2 for Decimal to Binary\n");
            /**
             * @brief case5opt is used for taking user input for the given choices
             * 
             */
            int case5opt;
            printf("Enter your choice: ");
            scanf("%d", &case5opt);
            switch(case5opt)
            {
                case 1:
                    /**
                     * @brief this case is used for converting binary to decimal number
                     * 
                     */
                    printf("Enter a binary number: ");
                    long int binaryNumForBinToDec;
                    scanf("%ld", &binaryNumForBinToDec);
                    if(binaryNumberValidator(binaryNumForBinToDec))
                    {
                        printf("%ld", binToDec(binaryNumForBinToDec));
                    }
                    else
                    {
                        printf("Invalid Input. Kindly Enter the correct input.\n");
                    }
                    break;
                case 2:
                    /**
                     * @brief this case is used for converting decimal number to binary
                     * 
                     */
                    printf("Please Enter the decimal number: ");
                    long int decimalNumForDecToBin;
                    scanf("%ld", &decimalNumForDecToBin);
                    printf("%ld", decToBin(decimalNumForDecToBin));
                    break;
                default:
                    printf("Wrong Option Entered. Please Enter the correct option\n");
                    break;
            }
            break;
        case 6: 
            /**
             * @brief this case is used for finding the one's complement of a number
             * 
             */
            printf("Enter the number of bits do you want to enter : ");
            int numOfBitsFor1sComplement;
            scanf("%d", &numOfBitsFor1sComplement);
            if(numOfBitsFor1sComplement>0 && numOfBitsFor1sComplement<100)
            {
                char binaryNumFor1scomplement[numOfBitsFor1sComplement + 1];          
                printf("\nPlease Enter the binary number : ");
                //gets_s(binaryNumFor1scomplement, numOfBitsFor1sComplement + 1);
                scanf("%s", &binaryNumFor1scomplement);
                onesComplement(binaryNumFor1scomplement, numOfBitsFor1sComplement);
            }
            else
            {
                printf("Wrong number of bits entered.\n");
                break;
            }
            break;
        case 7:
            /**
             * @brief this case is used for finding the 2's complement of a number
             * 
             */
            printf("Enter the number of bits do you want to enter : ");
            int numOfBitsFor2sComplement;
            scanf("%d", &numOfBitsFor2sComplement);
            if(numOfBitsFor2sComplement>0 && numOfBitsFor2sComplement<100)
            {
                char binaryNumFor2scomplement[numOfBitsFor2sComplement + 1];
                printf("\nPlease Enter the binary number : ");
                //gets_s(binaryNumFor2scomplement, numOfBitsFor2sComplement + 1);
                scanf("%s", &binaryNumFor2scomplement);
                twosComplement(binaryNumFor2scomplement, numOfBitsFor2sComplement);
            }
            else
            {
                printf("Wrong number of bits entered.\n");
                break;
            }
            break;
        case 8:
            /**
             * @brief this case is used for finding the sum of two binary numbers
             * 
             */
            printf("Enter the first binary number: ");
            long int binaryNumber1, binaryNumber2;
            scanf("%ld", &binaryNumber1);
            printf("Enter the second binary number: ");
            scanf("%ld", &binaryNumber2);
            sumOfBin(binaryNumber1, binaryNumber2);
            break;
        case 9:
            /**
             * @brief this case is used to exit the submenu.
             * 
             */
            printf("Exiting Digital Electronics and Systems Menu...\n");
            break;
        default:
            printf("Wrong option entered. Please enter the correct option.\n");
            break;
    }
}

long int binToHexa(long int binaryNumber)
{
    long int hexadecimalNum = 0, powerOf2 = 1;
    while (binaryNumber != 0)
    {
        hexadecimalNum = hexadecimalNum + (binaryNumber % 10) * powerOf2;
        powerOf2 = powerOf2 * 2;
        binaryNumber = binaryNumber / 10;
    }
    return hexadecimalNum;
}

//case 1:2
void hexaToBin(char hexadecimalNum[], int size)
{
    char binaryNum[65] =  "";
    int iteratorTerm = 0;
    for(iteratorTerm=0; hexadecimalNum[iteratorTerm]!='\0'; iteratorTerm++)
    {
        switch(hexadecimalNum[iteratorTerm])
        {
            case '0':
                strcat(binaryNum, "0000");
                break;
            case '1':
                strcat(binaryNum, "0001");
                break;
            case '2':
                strcat(binaryNum, "0010");
                break;
            case '3':
                strcat(binaryNum, "0011");
                break;
            case '4':
                strcat(binaryNum, "0100");
                break;
            case '5':
                strcat(binaryNum, "0101");
                break;
            case '6':
                strcat(binaryNum, "0110");
                break;
            case '7':
                strcat(binaryNum, "0111");
                break;
            case '8':
                strcat(binaryNum, "1000");
                break;
            case '9':
                strcat(binaryNum, "1001");
                break;
            case 'a':
            case 'A':
                strcat(binaryNum, "1010");
                break;
            case 'b':
            case 'B':
                strcat(binaryNum, "1011");
                break;
            case 'c':
            case 'C':
                strcat(binaryNum, "1100");
                break;
            case 'd':
            case 'D':
                strcat(binaryNum, "1101");
                break;
            case 'e':
            case 'E':
                strcat(binaryNum, "1110");
                break;
            case 'f':
            case 'F':
                strcat(binaryNum, "1111");
                break;
            default:
                printf("Invalid input. Please Enter the correct hexadecimal number.\n");
        }
    }
    printf("%s", binaryNum);
    return;
}

//case 2:1
long int binToOcta(long int binaryNum) {
    long int octalNum = 0, decimalNum = 0, iteratorTerm = 0;

    while (binaryNum != 0) {
        decimalNum += (binaryNum % 10) * pow(2, iteratorTerm);
        ++iteratorTerm;
        binaryNum /= 10;
    }
    iteratorTerm = 1;

    while (decimalNum != 0) {
        octalNum += (decimalNum % 8) * iteratorTerm;
        decimalNum /= 8;
        iteratorTerm *= 10;
    }
    return octalNum;
}
//case 2:2
long int octaToBin(int octalNum) {
    long int decimalNum = 0, iteratorTerm = 0, binaryNum = 0;

    // converting octal to decimal
    while (octalNum != 0) {
        decimalNum += (octalNum % 10) * pow(8, iteratorTerm);
        ++iteratorTerm;
        octalNum /= 10;
    }
    iteratorTerm = 1;

   // converting decimal to binary
    while (decimalNum != 0) {
        binaryNum += (decimalNum % 2) * iteratorTerm;
        decimalNum /= 2;
        iteratorTerm *= 10;
    }
    return binaryNum;
}

//case 3:1
long int decToOcta(long int decimalNumber)
{
    long int octalNumber = 0, iteratorTerm = 1;

    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * iteratorTerm;
        decimalNumber /= 8;
        iteratorTerm *= 10;
    }

    return octalNumber;
}

//case 3:2
long int octaToDec(long int octalNumber)
{
    long int decimalNumber = 0, iteratorTerm = 0;
    while(octalNumber != 0)
    {
        decimalNumber += (octalNumber%10) * pow(8,iteratorTerm);
        ++iteratorTerm;
        octalNumber/=10;
    }
    iteratorTerm = 1;

    return decimalNumber;
}

//case 4:1
long int binToGray(long int binaryNumber)
{
    long int grayNumber = 0, iteratorTerm = 0;
    while (binaryNumber != 0)
    {
        long int num1, num2;
        num1 = binaryNumber % 10;
        binaryNumber = binaryNumber / 10;
        num2 = binaryNumber % 10;
        if ((num1 && !num2) || (!num1 && num2))
        {
            grayNumber = grayNumber + pow(10, iteratorTerm);
        }
        iteratorTerm++;
    }
    return grayNumber;
}
//case 4:2

//case 5:1
long int binToDec(long int binaryNum) {
    int decimalNum = 0, iteratorTerm = 0;
    while (binaryNum != 0) {
        decimalNum += (binaryNum % 10) * pow(2, iteratorTerm);
        binaryNum /= 10;
        ++iteratorTerm;
    }
    return decimalNum;
}
//case 5:2
long int decToBin(long int decimalNum) {
    long int binaryNum = 0, iteratorTerm = 1;
    while (decimalNum != 0) {
        binaryNum += (decimalNum % 2) * iteratorTerm;
        decimalNum /= 2;
        iteratorTerm *= 10;
    }
    return binaryNum;
}

//case 6
void onesComplement(char binaryNum[], int numOfBits)
{
    char onescomplementNum[numOfBits + 1];
    for (int i = 0; i < numOfBits; i++)
    {
        if (binaryNum[i] == '0')
            onescomplementNum[i] = '1';
        else if (binaryNum[i] == '1')
            onescomplementNum[i] = '0';
    }
    onescomplementNum[numOfBits] = '\0';
    printf("%s", onescomplementNum);
}

//case 7
void twosComplement(char binaryNum[], int numOfBits)
{
    char onescomplementNum[numOfBits + 1], twoscomplementNum[numOfBits + 1];
    int carry = 1;
    for (int i = 0; i < numOfBits; i++)
    {
        if (binaryNum[i] == '0')
            onescomplementNum[i] = '1';
        else if (binaryNum[i] == '1')
            onescomplementNum[i] = '0';
    }
    onescomplementNum[numOfBits] = '\0';
    for (int i = numOfBits - 1; i >= 0; i--)
    {
        if (onescomplementNum[i] == '1' && carry == 1)
        {
            twoscomplementNum[i] = '0';
        }
        else if (onescomplementNum[i] == '0' && carry == 1)
        {
            twoscomplementNum[i] = '1';
            carry = 0;
        }
        else
        {
            twoscomplementNum[i] = onescomplementNum[i];
        }
    }
    twoscomplementNum[numOfBits] = '\0';
    printf("%s", twoscomplementNum);
}

//case 8
void sumOfBin(long int binaryNumber1, long int binaryNumber2)
{
    long int iteratorTerm = 0, remainder = 0, sumarray[20];
    while (binaryNumber1 != 0 || binaryNumber2 != 0)
    {
        sumarray[iteratorTerm++] = (binaryNumber1 % 10 + binaryNumber2 % 10 + remainder) % 2;
        remainder = (binaryNumber1 % 10 + binaryNumber2 % 10 + remainder) / 2;
        binaryNumber1 /= 10;
        binaryNumber2 /= 10;
    }
    if (remainder != 0)
        sumarray[iteratorTerm++] = remainder;
    --iteratorTerm;
    while (iteratorTerm >= 0)
        printf("%ld", sumarray[iteratorTerm--]);
}


int binaryNumberValidator(long int binaryNum)
{
    while(binaryNum)
    {
        if(binaryNum%10 != 0 && binaryNum%10 != 1)
        {
            return 0;
        }
        binaryNum/=10;
    }
    return 1;
}