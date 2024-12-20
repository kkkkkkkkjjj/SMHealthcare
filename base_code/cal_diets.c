//
//  cal_diets.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//

/*
    comments for dataflow by ayoung cho  : //*(# of step) ~ 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food


// list of diets 
static Diet diet_list[MAX_DIETS];  // lists of diets in "diet.txt"
static int diet_list_size = 0;


/*
    description : read the information in "diets.txt"
    
*/



void loadDiets(const char* DIETFILEPATH) {
	
    FILE *file;
    file = fopen(DIETFILEPATH, "r");// open the "diets_txt" and read 
    
    
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }
    
   // ToCode: to read a list of the diets from the given file
     //*(1) read "diets_txt" and save as {food_name, calories_ intake} form  in diet_list 
     /// (24.12.20 changed the code line 52 into simple form)
      while (fscanf(file, "%s %d", diet_list[diet_list_size].food_name,&diet_list[diet_list_size].calories_intake) != EOF){ 
         if( diet_list_size < MAX_DIETS) {
     //*(2) increase the number of diest_list (6 IS THE MAX NUM OF DIETS)    
            diet_list_size++;
         }
     //*(3) break if the number of diet_list is larger than 7
         else {
            break;
	 }
    //*(4) close the file
      }fclose(file);
    
}//(24.12.16.by ayoung.cho)


/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
    			
    warning   : 1. choice = exercise_list + 1 ; choice starts from 1, exercise_list starts from 0
            
*/

void inputDiet(HealthData* health_data) {
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
      //*(1) print every diet in diet_list : { food_name, (calories_intake kcal) } form
        printf("The list of diets:\n");
        for(i=0; i<diet_list_size; i++) {
           printf("%d. %s (%d kcal)\n", i+1, diet_list[i].food_name, diet_list[i].calories_intake);
        }

	
    // ToCode: to enter the diet to be chosen with exit option
        printf("Enter the diet : ");
        scanf("%i", &choice);        

	
    // ToCode: to enter the selected diet in the health data
      //*(1) enter the food name that player chose     
        strcpy(health_data->diet[health_data->diet_count].food_name ,diet_list[choice-1].food_name);

	
    // ToCode: to enter the total calories intake in the health data
      //*(1)  enter the calories intake of the food that player chose
        health_data->diet[health_data->diet_count].calories_intake = diet_list[choice-1].calories_intake;
      //*(2) to add calories intake to total calories intake in health_data
        health_data->total_calories_intake += diet_list[choice-1].calories_intake;
      //*(3) to add up the number of diets player chose
	health_data->diet_count++; 

	    
}//(24.12.18 by ayoungcho.. 24.12.19 modified by ayoungcho)
