//
//  cal_healthdata.c
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


/*
    description : enter the exercise and diet history in "health_data.txt" 
    input parameters : health_data - data object in which the selected exercise and diet is stored
    return value : No
    
    operation : 1. save the chosen exercise and total calories burned 
    			2. save the chosen diet and total calories intake 
    			3. save the total remaining calrories
*/

void saveData(const char* HEALTHFILEPATH, const HealthData* health_data) {
    int i;
	
    //*(1) open the health_txt file 
    FILE* file = fopen(HEALTHFILEPATH, "w");
    
    if (file == NULL) {
        printf("There is no file for health data.\n");
        return;
    }

    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
	
    //*(1) write exercise history in "health_data.txt"
    for(i=0; i<(health_data->exercise_count); i++)//exercise_count : number of exercises player has selected 
    {
    fprintf(file, "%s",health_data->exercises[i].exercise_name);// write name
    fprintf(file, "- %dkcal\n",health_data->exercises[i].calories_burned_duration);	// write calories burned
	}
    //*(2) write total calories burned "health_data.txt"
    fprintf(file, "Total calories burned : %d", health_data->total_calories_burned);
    
    
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");
	
    //*(1) write diet history in "health_data.txt"
    for(i=0; i< (health_data->diet_count); i++)//diet count : number of diets player has selected
    {
    fprintf(file, "%s",health_data->diet[i].food_name);// write name 
    fprintf(file, "%dkcal\n",health_data->diet[i].calories_intake);//write calories
	}
	//*(2) write total calories intake in "health_data.txt"
    fprintf(file, "Total calories intake : %d", health_data->total_calories_intake);



    // ToCode: to save the total remaining calrories
    fprintf(file, "\n[Total] \n");
    fprintf(file, "Basal metabolic rate - 1300 kcal\n");
	
    //*(1) calculate the remaining calories and write in "health_data. txt"
    fprintf(file, "The remaining calories - %d kcal", (health_data->total_calories_intake-health_data->total_calories_burned-1300));
    //*(2) close the file
    fclose(file);
}//(24.12.15 by ayoung cho)

/*
    description : print the history of exercised and diets
    input parameters : health_data - data object in which the history of the exercise and diet is to be printed
    return value : No
    
    operation : 1. print out the saved history of exercises
    			2. print out the saved history of diets
    			3. print out the saved history of calories
*/

void printHealthData(const HealthData* health_data) {
     int i;
	
    // ToCode: to print out the saved history of exercises
     printf("=========================== History of Exercise =======================\n");
     
    //*(1) print every exercise history of the player
    for(i=0; i<(health_data->exercise_count); i++) 
    {
           printf("Exercise : %s, Calories burned : %d kcal\n",health_data->exercises[i].exercise_name, health_data->exercises[i].calories_burned_duration); 
    }
    printf("=======================================================================\n");

    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");
    //*(2) print every diet history of the player
	for(i=0; i< (health_data->diet_count); i++)
	{
       printf("Food : %s, Calories intake : %d kcal\n",health_data->diet[i].food_name, health_data->diet[i].calories_intake);
    }
    printf("=======================================================================\n");

    // ToCode: to print out the saved history of calories including basal metabolic rate
	
    // total calories burned, total calories intake, and the remaining calories
    //*(1) bring the data from health_data struct
    printf("============================== Total Calories =========================\n");
    printf("Basal Metabolic Rate : 1300 kcal\n");
    printf("Total calories burned : %d kcal\n", health_data->total_calories_burned);
    printf("Total calories intake : %d kcal\n", health_data->total_calories_intake);
    printf("The remaining calories :%d kcal\n", (health_data->total_calories_intake-health_data->total_calories_burned-1300));
    printf("=======================================================================\n \n");
    //(24.12.18. by ayoung cho) 
	
    // ToCode: to print out the recommendtaion depending on the current total calories burned and intake  
    //*(1)REMAINING CAL = 0  
    if((health_data->total_calories_intake-health_data->total_calories_burned-1300)==0)
    {
        printf("You have consumed all your calories for today!\n");
    }
    //*(2)REMAINING CAL < 0 
    else if((health_data->total_calories_intake-health_data->total_calories_burned-1300) < 0)
    {
        printf("[Warning] Too few calories!\n");
        //*(2) - 1 : INTAKE = 2000
        if(health_data->total_calories_intake == 2000)
        {
            printf("Your total calorie intake for todday has reached your goal!\n");
        }
        //*(2) - 2 : INTAKE < 2000
        else if(health_data->total_calories_intake < 2000)
        {
            printf("Your total calorie intake for today has not reached your goal, remember to eat more!!\n");
        }
        //*(2) - 3 : INTAKE > 2000
        else if(health_data->total_calories_intake > 2000)
        {
            printf("You have eaten more calories than planned today, but you have exercised too much!\n");
        }
    }
    //*(3) REMAINING CAL > 0 
    else if ((health_data->total_calories_intake-health_data->total_calories_burned-1300) > 0)
    {
        printf("Please exercise for your health!\n");
        //*(2) - 1 : INTAKE = 2000
        if(health_data->total_calories_intake == 2000)
        {
            printf("Your total calorie intake for today has reached your goal!\n");
        }
        //*(2) - 2 : INTAKE < 2000
        else if(health_data->total_calories_intake < 2000)
        {
            printf("Your total calorie intake for today has not reached your goal, remember to eat more!!\n");
        }
    }
    
	printf("=======================================================================\n");
    //(24.12.05. by ayoungcho)

}
