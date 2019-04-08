/*
 * =====================================================================================
 *
 *       Filename:  
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thanks to github you know it
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author: Mahmut Erdem ÖZGEN   m.erdemozgen@gmail.com
 *   
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <iostream>

int main(int argc, const char *argv[]) {
    long long int basePopulation = 7432663275;
    long long int population = basePopulation;
    long long int increase = 0;

    double growthRate = 0.0113f;
    int sample = 0;

    std::cout << "Program to project world population\n" << std::endl;
    std::cout << "Enter a sample size (no of projection years): ";
    std::cin >> sample;

    printf("\n*** Population projection for %d years ***\n", sample);

    printf("Year\t\tPopulation\t\tIncrease\n");

    for (int i = 1; i <= sample; i++) {
        increase = population * growthRate;

        printf(
            "%d\t\t%lld\t\t%lld%s\n", i, population, increase,
            (population > basePopulation * 2) ? " - Population Doubled" : "");

        population += increase;
    }
    return 0;
}
