/*
*******************************************************************************************************
                                        Task_4_description
*******************************************************************************************************
Consider the following C program and answer the following questions:
1. Describe what the compute_array() function in the code does?
2. Is the program memory safe? If not, how could the program be made memory safe while retaining its
original functionality?
*******************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* compute_array(char* string_combined) 
{
    int n = strlen(string_combined); // get len of str
    int* array_1 = (int*)malloc(sizeof(int)*n); // allocate memory for ints for strlen
    array_1[0] = 0; // initially a 0
    for (int i = 1; i < n; i++) 
    {
        array_1[i] = 0;
        // while index and the array value < n, and the input's relevant index based on array_1, based on i
        // is equal to the input's relevant index based on sum of array_1, based on i and the current index
        while(((i + array_1[i]) < n) && (string_combined[array_1[i]] == string_combined[i + array_1[i]])) 
        {
            (array_1[i])++;
        }
    }
    // counts the number of same characters based on the spacing of the string, where the spacing is equal to
    // the index of the initial character, it goes through each character and get their indexes, which will be
    // the spacing to compare 2 characters, since it goes through each character, the index gradually increases
    // it will compare until the end of the string.
    // the compare starts from the first character of the string
    return array_1;
}

int main()
{
    char* string_1 = "abc";
    char* separator = "$";
    char* string_2 = "abcacbabcabddbabcaxabc";
   
    char string_combined[200];
    strcpy(string_combined, string_1);
    strcat(string_combined, separator);
    strcat(string_combined, string_2);
    int* array_1 = compute_array(string_combined);
    int n = strlen(string_combined);
    int m = strlen(string_1);
   
    for (int i = 0; i < n; i++) 
    {
        if (array_1[i] == m) 
        {
            // returns index of where it started on string 2
            printf("%d ", i - m - 1);
        }
    }

    // not memory safe, as the array is not freed in the end
    free(array_1);
    return 0;
}