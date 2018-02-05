#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <linux/kernel.h>
#include "link_list.h"


int main()
{

  llnode_t* testing;
  llnode_t* at_end;
  llnode_t* another;
  
  testing = insert_at_begin(NULL, 7);
  if(testing == NULL)
    {
      printf("FAILURE!!!!!\n");
    }
  
  at_end = insert_at_end(testing, 5);
  another = insert_at_end(at_end, 3);

  lldata_t* inspect;
  inspect = GET_LIST_CONTAINER(testing,lldata_t,linker);
  printf("addr: %p | data: %d\n",(void*)&(inspect->linker), inspect->data);

  lldata_t* inspect2;
  inspect2 = GET_LIST_CONTAINER(at_end,lldata_t,linker);
  printf("addr: %p | data: %d\n",(void*)&(inspect2->linker), inspect->data);

  inspect = GET_LIST_CONTAINER(another,lldata_t,linker);
  printf("addr: %p | data: %d\n",(void*)&(inspect->linker), inspect->data);

  uint32_t nodecount;
  nodecount = size(testing);
  printf("nodecount: %d\n",nodecount);


  
  return 0;
}
