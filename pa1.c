#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell_array.h"
#include "list_of_list.h"

int main(int argc, char ** argv){

    if (argc != 3) {
        return EXIT_FAILURE;
    }

    

    int* size = (int*) malloc(sizeof(int));

    long * arrayFromFile = Array_Load_From_File(argv[1], size);
    //printf("%d\n", * size);

    long * n_comp = (long *) malloc(sizeof(long));

    long * testArray = malloc(sizeof(long) * 100);
    for(int i = 0; i < 100; i++){
        testArray[i] = 100 - i;
    }

    Array_Shellsort(arrayFromFile, *size, n_comp);
    //printf("\n");
    //printf("%ld\n", *n_comp);

    Array_Shellsort(testArray, 100, n_comp);
    free(testArray);

    int sizeLoaded = Array_Save_To_File(argv[2], arrayFromFile, * size);
    //printf("%d\n", sizeLoaded);

    free(size);
    free(n_comp);
    free(arrayFromFile);


    
   
    Node * linkedList = List_Load_From_File(argv[1]);

    
    Node * dummy = linkedList;
    int numSaved = List_Save_To_File(argv[2], dummy);
    //printf("\n%d", numSaved);
    


    long * n_comp2 = (long *) malloc(sizeof(long));
    
    linkedList = List_Shellsort(linkedList, n_comp2);

    //printf("\n%ld\n", *n_comp2);
    
    // print out first couple values of linked list
    /*
    Node * p2 = linkedList;
    for(int i = 0; i < 10; i++){
        printf("%ld ", p2->value);
        p2 = p2->next;
    }
    */


    Node * dummy2 = linkedList;
    int numSaved2 = List_Save_To_File(argv[2], dummy2);
    //printf("\n%d", numSaved2);


    free(n_comp2);


    // free up linked list
    Node * n = linkedList;
    while(n){
        Node * n1 = n;
        n = n->next;
        free(n1);
    }

    
    

    return EXIT_SUCCESS;
}
