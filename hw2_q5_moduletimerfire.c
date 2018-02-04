#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

struct timer_list namecount_timer;     //sets up timer list struct for a new timer

static char * nameString = "andrewkuklinski";
//int counter = 0;     //holds number of times fired value

module_param(nameString, charp,0000);
MODULE_PARM_DESC(nameString, "variable to hold your name");

static int delayTime = 500;      //HZ = 1 sec in jiffies

module_param(counter, int, 0000); //S_IRUSR | S_IWUSR | S_IRGRP |S_IWGRP | S_IROTH | S_IWOTH);
MODULE_PARM_DESC(delayTime, "length of time before next fire, in milliseconds");

void baby_back_ribs(unsigned long data)
{
  static int counter = 0;

  //this restarts the time to make it recurring
  mod_timer(&namecount_timer, jiffies+(delayTime*(HZ/1000)));
  counter++;

  printk(KERN_INFO "user timer name: %s | number of fires: %d\n",nameString,counter);
}

static int __init timer_mod_init(void)
//int init_module(void)
{
  printk(KERN_ALERT "moduletimerfire hw2q5 INIT\n");
  //sets timer_list Struct, callback function
  setup_timer(&namecount_timer, baby_back_ribs,0);

  //starts the timer
  mod_timer(&namecount_timer, jiffies+(delayTime*(HZ/1000)));
  
  return 0;
}

static void __exit timer_mod_exit(void)
//void cleanup_module(void)
{
  del_timer(&namecount_timer);
  printk(KERN_ALERT "moduletimerfire hw2q5 EXIT\n");
  //return 0;
}

module_init(timer_mod_init);
module_exit(timer_mod_exit);


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Count tracking every 500msec");
MODULE_AUTHOR("Andrew Kuklinski");
