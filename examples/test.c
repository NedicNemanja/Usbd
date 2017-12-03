#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defn.h"
#include "AM.h"

#define NUM_OF_INSERTS 500

void main(void){
  AM_Init();
  AM_CreateIndex("TestBase", INTEGER, 4, STRING, 10);
  int fd = AM_OpenIndex("TestBase");
  float iff = 0.0;

  //INSERT
  for(int i=0; i<NUM_OF_INSERTS; i++){
    //string
    char str[5];
    sprintf(str, "%d", i);
    printf("(((%s)))", str);


    // iff = (float)i/10;
     AM_InsertEntry(fd,(void*) &i, (void*) &iff);
  }
  printf("PAO GIA SCAN\n");
  //SCAN
  char value1[5] = {'5', '0'};
  int scanDesc = AM_OpenIndexScan(fd, EQUAL, &value1);
  for(int i=0; i<NUM_OF_INSERTS; i++){
    char* value2 = AM_FindNextEntry(scanDesc);
    if( value2 == NULL)
      printf("%d.NULL\n", i);
    else
      printf("%s\n", value2);
  }

  AM_CloseIndex(fd);
}
