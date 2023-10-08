//
//  main.c
//  a1
//
//  Created by 杨二宝 on 20/09/2023.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


#define NSIZE 4

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {1,2,3,4};
    int** resultMatrix = NULL;
    int*  matrixColNums = NULL;
    int resultCount = 0;
    
    resultMatrix = (int**)calloc(100, sizeof(int*));
    assert(resultMatrix);
    
    matrixColNums = (int*)calloc(100, sizeof(int));
    assert(matrixColNums);
    
    resultMatrix[0] = (int*)calloc(NSIZE, sizeof(int));
    assert(resultMatrix[0]);
    resultMatrix[0][0] = 1;
    matrixColNums[0] = 1;
    resultCount++;
    
    for(int i=1;i<NSIZE;i++){
        int currentNum = arr[i];
        int oldResultCount = resultCount;
        for(int j=0;j<oldResultCount;j++){
            int arrayLen = matrixColNums[j];
            int* array = resultMatrix[j];
            for(int k=0;k<=arrayLen;k++){
                
                int* newArray = (int*)calloc(NSIZE, sizeof(int));
                assert(newArray);
                int t=0;
                int e=0;
                while(e<k){
                    newArray[t++] = array[e++];
                }
                // insert arr[i] into the position of k;
                newArray[t++] = currentNum;
                while(e<arrayLen){
                    newArray[t++] = array[e++];
                }
                
                // append newArray to matrix
                resultMatrix[resultCount] = newArray;
                matrixColNums[resultCount] = arrayLen+1;
                resultCount++;
            }
        }
    }
    
    
    for(int i=0;i<resultCount;i++){
        if(matrixColNums[i]==4){
            for(int j=0;j<matrixColNums[i];j++){
                printf("%d ", resultMatrix[i][j]);
            }
        }
        printf("\n");
    }

    
    return 0;
}

