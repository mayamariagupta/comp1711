#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;


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

int main() {

    FITNESS_DATA fitness[1000];
    int line_buffer = 1000;
    char line[line_buffer];
    int counter = 0;

    FILE *input = fopen("FitnessData_2023.csv", "r");

    char date[20];
    char time[20];
    char steps[20];

    while (fgets(line, line_buffer, input)){
        
        tokeniseRecord(line,",",date,time,steps);

        strcpy(fitness[counter].date,date);
        strcpy(fitness[counter].time,time);
        fitness[counter].steps = atoi(steps);
        counter++;
    
    }

    printf("Number of records in file: ");
    printf("%d\n", counter);

    printf("%s",fitness[0].date);
    printf("/");
    printf("%s",fitness[0].time);
    printf("/");
    printf("%d\n",fitness[0].steps);

    printf("%s",fitness[1].date);
    printf("/");
    printf("%s",fitness[1].time);
    printf("/");
    printf("%d\n",fitness[1].steps);

    printf("%s",fitness[2].date);
    printf("/");
    printf("%s",fitness[2].time);
    printf("/");
    printf("%d\n",fitness[2].steps);

fclose(input);
    return 0;
}