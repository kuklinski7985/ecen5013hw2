#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/syscalls.h>
#include <linux/types.h>


SYSCALL_DEFINE3(bubsort, __user int*, presort, int, size, __user int*, postsort)
{
  int i,x,j;
  int holdingvar = 0;
  int *unsort = NULL;
  int *sorted = NULL;
  unsigned long check = 0;

  int *sortHolding = NULL;
  printk(KERN_NOTICE "Entered syscall bubsort 334\n");
  printk(KERN_NOTICE "size of input array: %d\n",size);
  
 
  unsort = (int*)kmalloc((sizeof(int)*size),GFP_KERNEL);
  if(unsort == NULL)
    {
      printk(KERN_WARNING "kmalloc failed for unsort\n");
      return EFAULT;
    }
  
  sorted = (int*)kmalloc((sizeof(int)*size),GFP_KERNEL);
  if(sorted == NULL)
    {
      printk(KERN_WARNING "kmalloc failed for sorted\n");
      return EFAULT;
    }
  sortHolding = sorted;

  //check = copy_from_user(unsort,presort,(sizeof(int)*size));

  check = copy_from_user(unsort,presort,4*size);
  if (check != 0)
    {
      printk(KERN_WARNING "copy_from_user has issues\n");
      return EFAULT;
    }
  
  check = 0;

  for(i=0; i<size; i++)
    {
      *sorted = *unsort;
      unsort++;
      sorted++;
    }

  sorted = sortHolding;
   
  for(x=0; x<size; x++)
   {
     for(j=0; j<(size-1); j++)
       {
	 if(*(sorted+j) < *(sorted+j+1))
	   {
	     holdingvar = *(sorted+j);
	     *(sorted+j) = *(sorted+j+1);
	     *(sorted+j+1) = holdingvar;
	   }
       }
   }
   sorted = sortHolding;

   //check = copy_to_user(postsort,sorted,(sizeof(int)*size));

   check = copy_to_user(postsort,sorted,4*size);
   if (check !=0)
     {
       printk(KERN_WARNING "copy_to_user has issues\n");
       return EFAULT;
     }
   check = 0;

   kfree(unsort);
   kfree(sorted);
   printk(KERN_NOTICE "Leaving sycall bubsort 334\n");
   return 0;
}


/*void realSort(int *unbuff, int size, int *sortbuff)
{
  int i,x,j;
  
  for(i=0; i<size; i++)
    {
      *sortbuff = *unbuff;
      unbuff++;
      sortbuff++;
    }

  sortbuff-=(size);
  
  int holdingvar = 0;
  for(x=0; x<size; x++)
    {
      for(j=0; j<(size-1); j++)
	{
	  if(*(sortbuff+j) < *(sortbuff+j+1))
	    {
	      holdingvar = *(sortbuff+j);
	      *(sortbuff+j) = *(sortbuff+j+1);
	      *(sortbuff+j+1) = holdingvar;
	    }
	}
    }
  return;
  }*/

