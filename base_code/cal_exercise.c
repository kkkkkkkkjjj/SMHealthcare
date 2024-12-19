//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

/*
    comments for dataflow by ayoung cho  : //* (# of step) ~ 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise


// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES];//{ exercise_name, cal per min} 
int exercise_list_size = 0;// 0 exercies has selected yet


/*
    description : read the information in "excercises.txt"
*/



void loadExercises(const char* EXERCISEFILEPATH) {
	
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    //*(1) read "exercise_txt" and save as {exercise_name, calories_burned_per_minute} form in exercise list
    /// put break condition fr. basecode.zip into while() by "&&"
    while (exercise_list_size < MAX_EXERCISES && 
    fscanf(file, "%s %d", exercise_list[exercise_list_size].exercise_name,&exercise_list[exercise_list_size].calories_burned_per_minute) == 2 ) 
    {
    //*(2) increase the number of exercise_list (6 IS THE MAX NUM OF EXERCISES)
    exercise_list_size++; 
    }
    //*(3) close the file
    fclose(file);
    
}// (24.12.18. by ayoungcho)


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
    			2. enter the duration of the exercise
    			3. enter the selected exercise and the total calories burned in the health data
*/

void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    //*(1) print every exercise in exercise_list 
    for(i=0; i< exercise_list_size; i++)
	{
    printf("%d. %s (%d kcal burned per min.)\n", i + 1, exercise_list[i].exercise_name, exercise_list[i].calories_burned_per_minute);
	}
	
    // ToCode: to enter the exercise to be chosen with exit option
    printf("Enter the diet : ");
    //*(1) get the diet choice form the player
    scanf("%i", &choice);
    //*(2) get the duration from player input
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);
    //*(3) calculate the calories burned during exercise 
    exercise_list[choice].calories_burned_duration = (exercise_list[choice].calories_burned_per_minute * duration);
	//*(4)  enter the calories burned during exercise into health_data
	health_data->exercises[health_data->exercise_count].calories_burned_duration = exercise_list[choice].calories_burned_duration;

    // ToCode: to enter the selected exercise and total calcories burned in the health data
	//*(1) copy exercise name into exercises.exercise_name 
	strcpy(health_data->exercises[health_data->exercise_count].exercise_name, exercise_list[choice ].exercise_name);
	//*(2) add calories burned during exercise to total calories in health_data
    health_data->total_calories_burned +=exercise_list[choice].calories_burned_duration;
	//*(3) increase # of exercise in health_data
	health_data->exercise_count++; 
	
}//(24.12.18 by ayoungcho)

