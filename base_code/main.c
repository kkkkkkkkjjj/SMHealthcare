//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;

int main() {
	// To initialize the health data object
    HealthData health_data = {0};
    
    // Tocode: to read the list of the exercises and diets
    loadDiets(DIETFILEPATH); // print the list of diets
    loadExercises(EXERCISEFILEPATH); // print the list of exercises    

    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
    do {
    	if ( ){
            printf("You have consumed all your calories for today! \n");
		} 
		else{
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice);
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
            case 1:
            	// (1)input exercise and duration choice
            	inputExercise(&health_data);
            	// (2)upload on "health.txt" 
            	saveData(HEALTHFILEPATH, &health_data);
            	
                break;
                
            case 2:
            	// (1)input diet choice
            	inputDiet(&health_data);
                // (2)upload on "health.txt" 
                saveData(HEALTHFILEPATH,&health_data);
                
                break;
                
            case 3:
            	//(1)to print out the recommendtaion depending on the current total calories burned and intake 
            	printHealthData(&health_data);
                break;
                
            case 4:
            	
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
    } while (health_data.total_calories_intake - 1300 - health_data.total_calories_burned != 0  );// exit condition

    return 0;
}//(24.12.18. by ayoung cho)

