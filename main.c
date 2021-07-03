#include "DigitalElectronicsandSystems.h"
#include "Modulation.h"
#include "ElectricCircuits.h"
#include "ResistorColorCoding.h"
#include "SignalsandSystems.h"

int main()
{
    int menu;  //mmip=main menu input & smip=sub menu input

    printf("Welcome to ECE EvalEngine \n");
    printf("MENU:\n");
    printf("1. Resistor Color Coding\n 2. Electric Circuits\n3. Analog Communication System\n4. Digital Electronics and Systems\n5. Signals and Systems\n6. Exit\n ");
    printf("Please enter the preferred option:\n");
    scanf("%d", &menu); //get main-menu input


    switch (menu)
    {
    case 1:
        {/**
         * @brief For Resistor Color Coding
         * 
         */
    
            break;
        }

        case 2:
        {/**
         * @brief For Electric Circuits
         * 
         */
            
            break;
        }
        case 3:
        {/**
         * @brief For Analog Communication System
         * 
         */
            
            break;
        }
        case 4:
        {/**
         * @brief For Digital Electronics and Systems
         * 
         */
            
            break;
        }
        case 5:
        {/**
         * @brief For Signals and Systems
         * 
         */
           SignalsAndSystems();
            
            break;
        }
        case 6: //For EXITING THE APPLICATION
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
    return 0;
}
