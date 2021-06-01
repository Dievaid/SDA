#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <fstream>


#define TEST_FILE "../data/input_2.txt"
#define TEST_FILE_OUTPUT "../data/output_2.txt"
#define READ_MODE "r+"
#define WRITE_MODE "w+"

/**
 * @brief 
 * //TODO: Completeaza sectiunea
 * @param filename 
 * @param mode 
 * @return FILE* 
 */
FILE *openFile(const char *filename, const char *mode);

/**
 * @brief 
 * 
 * @param argument 
 * @return true or false
 */
bool isNull(void *argument);


/**
 * @brief 
 * 
 * @param argument 
 * @return true or false
 */
bool isNotNull(void *argument);