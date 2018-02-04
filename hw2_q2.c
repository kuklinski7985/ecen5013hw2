#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
//#include <linux/slab.h>

int main(void)
{
  //printf("Homework2 - problem 2: Tracking System Calls\n");
  //printf("This is something interesting!\n");

  char outChar[] = "E";
  char testString[128];
  char testString2[16];
  char readIn;

  int q2file = creat("hw2q2.txt", O_RDWR);
  chmod("hw2q2.txt",S_IRUSR | S_IWUSR| S_IRGRP| S_IWGRP | S_IROTH | S_IWOTH);
  q2file = open("hw2q2.txt",O_WRONLY | O_EXCL);

  q2file = write(q2file,outChar, strlen(outChar));
  q2file = close(q2file);

  q2file = open("hw2q2.txt", O_WRONLY | O_APPEND);
  uint32_t* newarray = (uint32_t*)malloc((sizeof(size_t))*16);

  q2file = read(0, testString,128);
  q2file = write(q2file,testString,strlen(testString));

  q2file = fflush(stdout);

  q2file = close(q2file);

  FILE *userfile = fopen("hw2q2.txt", "r");

  readIn = getc(userfile);
  //fgets(testString2);

  close(q2file);
  free(newarray);
  return 0;
}
