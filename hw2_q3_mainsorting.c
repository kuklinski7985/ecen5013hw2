#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
//#include <sys/syscall.h>
#include <linux/kernel.h>
//#include "syssort.h"

void printArray(uint32_t * input, uint32_t size);

int main()
{
  
  uint8_t arraySize = 15;                
  time_t timeme;                //used for setting random numbers
  
  /***creating unsorted array - user space***/
  uint32_t * unSortArray;
  unSortArray = (int32_t*)malloc((sizeof(size_t)*arraySize));
  if(unSortArray == NULL)
   {
     printf("Unsorted Array init failed");
     return 1;
   }

  /***creating sorted array - user space***/
  uint32_t * sortArray;
  sortArray = (int32_t*)malloc((sizeof(size_t)*arraySize));
  if(sortArray == NULL)
  {
     printf("sorted array init failed");
     return 1;
  }

  /***initializing unsorted array in user space with random number***/
  srand((uint32_t)time(&timeme));          //sets seed for rand
  for (uint8_t i = 0; i<arraySize; i++)
  {
    *unSortArray = (rand()%100);
    unSortArray++;   
  }

  unSortArray = unSortArray - (arraySize);     //reset unsort array in order to print
  printf("array prior to sort\n");
  printArray(unSortArray, arraySize);

  syscall(334,unSortArray,arraySize,sortArray);

  printf("\narray after sort\n");
  printArray(sortArray, arraySize);
			       
  free(unSortArray);
  free(sortArray);

			       
  return 0;
}

void printArray(uint32_t * input, uint32_t size)
{
  int i;
  for (i=0;i<size;i++)
    {
      printf("%d ",*input);
      input++;
    }
  printf("\n");
  return;
}



