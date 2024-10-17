#include "chess.h"
#include "figures.h"
#include <stdio.h>

void print(char** figure){
  for(int i=0; i<58; i++){
    printf("%s\n", figure[i]);
  }
}

void display(){
  print(rook);
}
