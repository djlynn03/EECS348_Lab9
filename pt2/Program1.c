#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	char months[128][128] = {"January", "February", "March", "April","May","June","July","August", "September","October","November","December"};
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;
	
	fp = fopen("./input.txt", "r");
	if (fp == NULL)
        exit(EXIT_FAILURE);
        
    printf("Monthly sales report for 2022:\n");
    printf("Month\t\tSales\n");
    int iter = 0;
    float sales[12];
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("%-8s\t$%8s", months[iter], line);
        sales[iter] = atof(line);
        
        iter++;
    }
    int min_index = 0;
    int max_index = 0;
    float sum = 0;
    for (int i = 0; i < 12; i++){
        if (sales[i] < sales[min_index]){
            min_index = i;
        }
        if (sales[i] > sales[max_index]){
            max_index = i;
        }
        sum += sales[i];
    }
    printf("\n");
    printf("Minimum sales:\t$%0.2f  (%s)\n", sales[min_index], months[min_index]);
    printf("Maximum sales:\t$%0.2f  (%s)\n", sales[max_index], months[max_index]);
    printf("Average sales:\t$%0.2f\n", sum / 12);
    printf("\n");
    printf("Six-Month Moving Average Report\n");
    float avg = 0;
    for (int i = 0; i < 7; i++){
        avg = 0;
        for (int j = 0; j < 6; j++){
            avg += sales[i + j];
        }
        printf("%-10s -  %-10s  $%0.2f\n", months[i], months[i+5], avg/6);
    }
    printf("\n");
    
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\t\tSales\n");
    
    max_index = 0;
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            if (sales[j] > sales[max_index]){
                max_index = j;
            }
        }
        printf("%-8s\t$%0.2f\n", months[max_index], sales[max_index]);
        sales[max_index] = 0;
    }
    
    
	fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
	
	
	return 0;
}
