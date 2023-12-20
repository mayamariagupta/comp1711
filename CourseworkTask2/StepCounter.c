#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }



int main(){

    char line[buffer];
    char filename[buffer];

    FITNESS_DATA list[500];
    
    char choice;
    int counter = 0;
    float mean = 0;

    char date[20];
    char time[10];
    char steps[5];

    while (true)
    {   
        printf("Menu Options:\n");
        printf("A: Specify filename to be imported\n"); 
        printf("B: Display the total number of records in the file\n"); 
        printf("C: Find the date and time of the timeslot with the fewest steps\n");  
        printf("D: Find the data and time of the timeslot with the largest number of steps\n");   
        printf("E: Find the mean step count of all the records in the file\n");       
        printf("F: Find the longest continuous period where the step count is above 500 steps\n"); 
        printf("Q: Quit\n"); 
        printf("Enter Choice: ");
        
        choice = getchar();

        while (getchar() != '\n');

        switch (choice)
        {

        case 'A':
        case 'a':
            printf("Please enter the name of the data file: ");

            fgets(line, buffer, stdin);
            sscanf(line, " %s ", filename);

            FILE *input = fopen(filename, "r");
            if (!input)
            {
                printf("Error: Could not find or open the file.\n");
                return 1;
            }
            else
            {
                printf("File successfully loaded.\n");
            }
            fclose(input);
            break;

        case 'B':
        case 'b':
            input = fopen(filename, "r");            
            counter = 0;
            while (fgets(line, buffer, input))
            {
                counter++;
            }
            printf("Total records: %d\n", counter);
            fclose(input);
            break;

        case 'C':
        case 'c':
            input = fopen(filename, "r");            
            counter = 0;
            FITNESS_DATA lowest_steps;
            while (fgets(line, buffer, input))
            {   

                tokeniseRecord(line, ",", date, time, steps); 
                strcpy(list[counter].date ,date);
                strcpy(list[counter].time, time);
                list[counter].steps = atoi(steps); 

                if (counter == 0)
                {
                    lowest_steps = list[counter];
                }
                else
                {
                    if (list[counter].steps < lowest_steps.steps)
                    {   
                        lowest_steps = list[counter];
                    }
                }
                counter++;
            }
            printf("Fewest steps: %s %s\n", lowest_steps.date, lowest_steps.time);
            fclose(input);
            break;

        case 'D':
        case 'd':
            input = fopen(filename, "r");            
            counter = 0;
            FITNESS_DATA highest_steps;
            while (fgets(line, buffer, input))
            {
                tokeniseRecord(line, ",", date, time, steps); //use the tokeniseRecord to 
                //copy all the temporary data from the cycle to the array of fitness_data
                strcpy(list[counter].date ,date);
                strcpy(list[counter].time, time);
                list[counter].steps = atoi(steps); 
                 
                if (counter == 0)
                {
                    highest_steps = list[counter];
                }
                else
                {
                    if (list[counter].steps > highest_steps.steps)
                    {
                    highest_steps = list[counter];
                    }
                }
                counter++;
            }
            printf("Largest steps: %s %s\n", highest_steps.date,highest_steps.time);
            fclose(input);
            break;

        case 'E':
        case 'e':
            input = fopen(filename, "r");            
            counter = 0;
            int total_steps = 0;
            int mean_steps = 0;
            while (fgets(line, buffer, input))
            {   
                tokeniseRecord(line, ",", date, time, steps);                
                total_steps += atoi(steps);
                counter++;
            }
            mean_steps = (total_steps + counter / 2) / counter;
            printf("Mean step count: %d\n", mean_steps);
            fclose(input);       
            break;

        case 'F':
        case 'f':
            input = fopen(filename, "r");            
            counter = 0;
                      
            while (fgets(line, buffer, input))
            {
                tokeniseRecord(line, ",", date, time, steps);
                strcpy(list[counter].date ,date);
                strcpy(list[counter].time, time);
                list[counter].steps = atoi(steps); 
                counter++;
            }
            
            FITNESS_DATA Current_Start_Period = {};
            FITNESS_DATA Current_End_Period = {};
            FITNESS_DATA Longest_Start_Period = {};
            FITNESS_DATA Longest_End_Period = {};
            int current_period_length = 0;
            int longest_period_length = 0;

            for (int i = 0; i < counter; i++) 
            {
                if(list[i].steps > 500)
                {
                    Current_End_Period = list[i];
                    current_period_length += 1;
                    if (current_period_length > longest_period_length)
                    {
                        longest_period_length = current_period_length;
                        Longest_Start_Period = Current_Start_Period;
                        Longest_End_Period = Current_End_Period;
                    }
                }
                else
                {
                    Current_Start_Period = list[i+1];
                    //Current_End_Period = {};
                    current_period_length = 0;
                }
            }   
            printf("Longest period start: %s %s\n", Longest_Start_Period.date,Longest_Start_Period.time);
            printf("Longest period end: %s %s\n", Longest_End_Period.date,Longest_End_Period.time);
            fclose(input);
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        default:
            printf("Invalid choice. Try again. \n");
            break;    
        }
    }
}
