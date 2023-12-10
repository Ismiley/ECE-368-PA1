#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell_array.h"

long *Array_Load_From_File(char *filename, int *size){

    // convert file name to size
        // parse number from beginning of file name
        // parse letter from file name -> 
        //   if K, multiply by 1000   , if M, multiply by 1,000,000
    char nameNumber[3] = "aaa";
    int i = 0;
    int j = 0;
    int multiplier = 0;
    while(filename[i] != '\0'){
        if(filename[i] == '/'){
            j = 0;
            for(int a = 0; a < 3; a++){
                nameNumber[a] = 'a';
            }
        }
        if(filename[i] >= '0' && filename[i] <= '9'){
            nameNumber[j] = filename[i];
            j++;
        }
        else if(filename[i] == 'K'){
            multiplier = 1000;
        }
        else if(filename[i] == 'M'){
            multiplier = 1000000;
        }
        i++;
    }
    int nameNumberInt = atoi(nameNumber);
    nameNumberInt = nameNumberInt * multiplier;
    * size = nameNumberInt;

    // declare long pointer of correct size
    long * arrayFromFile = (long*) malloc(*size * sizeof(long));

    // fill in values of array
    // load file
    FILE *fptr = fopen(filename, "rb");

    // if file fails to open or cannot allocate sufficient memory
    if(fptr == NULL || arrayFromFile == NULL){
        * size = 0;
        long * ret = NULL;
        return ret;
    }

    // read each binary number, separated by spaces
    // populate array value with binary number 
    fread(arrayFromFile, sizeof(long), * size, fptr);

    // close file
    fclose(fptr);
    
    // return long pointer
    return arrayFromFile;
}

int Array_Save_To_File(char *filename, long *array, int size){

    // open file
    FILE *fptr = fopen(filename, "wb");

    //if array is null or size == 0, create empty file
    //--> do a test case to check

    if(array == NULL || size == 0){
        fclose(fptr);
        return size;
    }
    else{
        // read values from array one by one till size (for loop) and add write to file
        fwrite(array, sizeof(long), size , fptr);

        // close file
        fclose(fptr);

        return size;
    }

    
}

void Array_Shellsort(long *array, int size, long *n_comp){

    // get sequence for shell sort (3(f(n - 1) + 1)
    int numSeq = 1;
    int numSeqCounter = 0;
    if(size == 0){
        return;
    }
    while(numSeq < size){
        numSeq = 3 * numSeq + 1;
        numSeqCounter += 1;
    }

    int * seq = (int *) malloc(sizeof(int) * numSeqCounter);
    numSeq = 1;
    int counter = 0;
    while(numSeq < size){
        seq[counter] = numSeq;
        numSeq = 3 * numSeq + 1;
        counter += 1;
    }

    *n_comp = 0;

    // perform shell sort
    for(int i = numSeqCounter - 1; i >= 0; i--){
        //printf("%d ", seq[i]);

        for(int j = seq[i]; j < size; j++){
            *n_comp += 1;
            long temp = array[j];
            int k;
            for(k = j; k >= seq[i] && array[k-seq[i]] > temp; k -= seq[i]){
                array[k] = array[k - seq[i]];
                *n_comp += 1;
            }
            array[k] = temp;
        }
    }
   
    free(seq);

    return;

}