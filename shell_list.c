#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell_list.h"

long movePointer(Node ** n1, int gap);

void swapNodes(Node ** hRef, int x, int y);

//void testSwap();

Node *List_Load_From_File(char *filename){
    // convert file name to size
        // parse number from beginning of file name
        // parse letter from file name -> 
        //   if K, multiply by 1000   , if M, multiply by 1,000,000
    int size;
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
    size = nameNumberInt;

     // fill in values of array
    // load file
    FILE *fptr = fopen(filename, "rb");
    
    // if file fails to open or cannot allocate sufficient memory
    if(fptr == NULL){
        Node *first = (Node *) malloc(sizeof(Node));
        return first;
    }

    // add nodes to linked list from file
        // make sure to save the head of the linked list
        // read in values one by one from file
    Node *temp;
    Node *last;

    Node *first = (Node *) malloc(sizeof(Node));
    fread(&(first->value), sizeof(long), 1, fptr);
    first->next = NULL;
    last = first;

    for(int x = 1; x < size; x++){
        temp = (Node *) malloc(sizeof(Node));
        fread(&(temp->value), sizeof(long), 1, fptr);
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }


    // close file
    fclose(fptr);


    return first;

}



int List_Save_To_File(char *filename, Node *list){
    // open file
    FILE *fptr = fopen(filename, "wb");

    int size = 0;

    if(fptr == NULL){
        fclose(fptr);
        return size;
    }

    else{

        while(list != NULL){
            fwrite(&(list->value), sizeof(long), 1, fptr);
            list = list->next;
            size += 1;
        }

        // close file
        fclose(fptr);

        return size;
    }
}

long movePointer(Node ** n1, int gap){
    int i = 0;
    while(i < gap){
        n1 = &((*n1)->next); 
        i += 1;
    }
    return (*n1)->value;
}

void swapNodes(Node ** hRef, int x, int y){
    
    Node * prevX = NULL;
    Node * currX = *hRef;    
    for(int i = 0; i < x; i++){
        prevX = currX;
        currX = currX->next;
    }

    Node * prevY = NULL;
    Node * currY = *hRef;
    for(int i = 0; i < y; i++){
        prevY = currY;
        currY = currY->next;
    }
    
    if(prevX != NULL){
        prevX->next = currY;
    }
    else{
        *hRef = currY;
    }

    if(prevY != NULL){
        prevY->next = currX;
    }
    else{
        *hRef = currX;
    }

    Node * temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

/*
void testSwap(){
    // make linked list
    Node * testList = (Node *) malloc(sizeof(Node));
    testList->value = 0;
    testList->next = NULL;
    Node * last = testList;
    Node * temp;
    for(int i = 1; i < 5; i++){
        temp = (Node *) malloc(sizeof(Node));
        temp->value = i;
        last->next = temp;
        last = temp;
    }

    // print first 5 elements
    Node * p2 = testList;
    for(int i = 0; i < 5; i++){
        printf("%ld ", p2->value);
        p2 = p2->next;
    }

    // swap first and last element
    swapNodes(&testList, 0, 4);

    // print first 5 elements
    p2 = testList;
    for(int i = 0; i < 5; i++){
        printf("%ld ", p2->value);
        p2 = p2->next;
    }

    // free list
    // free up linked list
    Node * n = testList;
    while(n){
        Node * n1 = n;
        n = n->next;
        free(n1);
    }
}
*/

Node *List_Shellsort(Node *list, long *n_comp){

    *n_comp = 0;

    // get size
    int size = 0;
    Node * dummy = list;
    while(dummy){
        dummy = dummy->next;
        size += 1;
    }

    // get sequence for shell sort (3(f(n - 1) + 1)
    int numSeq = 1;
    int numSeqCounter = 0;

    while(numSeq < size){
        numSeq = 3 * numSeq + 1;
        numSeqCounter += 1;
    }
    
    // shell sort linked list
    int j, k;
    Node ** n2 = &list;
    while(numSeq>=1)
    {
        for (j = numSeq; j < size; j++)
        {
            *n_comp += 1;

            for(k = j - numSeq; k >= 0; k = k - numSeq)
            {   
                *n_comp += 1;

                // calc val 1 
                long val1 = movePointer(n2, k + numSeq);
                n2 = &list;

                // calc val 2    
                long val2 = movePointer(n2, k);
                n2 = &list;
                
                if (val1 >= val2)
                    break;
                else
                {
                    swapNodes(n2, k, k+numSeq);
                }
            }
        }
        numSeq = (numSeq - 1) / 3;
    }

    // return head of list
    return list;
}