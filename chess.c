#include "chess.h"
#include <stdlib.h>

int sizeR(char **figure){
 int row=0;
 while(figure[row]!=0){
   	 row++;
 }
 return row;
}



int sizeC(char** figure){
  int col=0;
  char** new=malloc;
  while(figure[0][col]!=0){
    col++;
  }
  return col;
}

char**create(int na){
  tenkiu=pow;

char** crear(int row, int col){

  char** figure2 = (char**) malloc(row * sizeof(char *));
  for(int i=0;i<row;i++){
    figure2[i] = (char * )malloc(col * sizeof(char ));
    figure2[i][col] = '\0';
  }
  figure2[row] = 0;
  return figure2 ;
}

char** crearTwo(){
  char** figure = (char ** )malloc(59 * sizeof(char *));
  for(int i=0;i<59;i++){
    figure[i] = (char *)malloc((59*2) * sizeof(char ));
    figure[i][58] = '\0';
  }
  figure[58] = 0;
  return figure;
}

char** reverse(char** figura){
  char** variable = crear(59,59);
  for (int i=0; figura[i]!=0; i++){
    for(int j=0; figura[i][j]!='\0'; j++){
      if (figura[i][j]=='_')
        variable[i][j]='=';
      else if (figura[i][j]=='.')
        variable[i][j]='@'; 
      else
        variable[i][j]=figura[i][j];
    }
  } 
  return variable;
}

char** join(char** figura1, char** figura2){
  int row= sizeR(figura1);
  int col= sizeC(figura2);

  char** joined=crear(row,118);

  for(int i=0;figura1[i]!= 0 ; i++){
    for(int j=0;figura1[i][j]!='\0' ; j++){
      joined[i][j] = figura1[i][j];
      joined[i][j + 58] = figura2[i][j];
    }

  }
  return joined;
}

char** repeatH(char** figura, int veces){
  int filas = sizeR(figura);
  int columnas = sizeC(figura);

  char** repeated = (char**)malloc((filas)*sizeof(char*));
  for(int i=0; i<filas; i++)
    repeated[i] = (char*)malloc((columnas*veces + 1)*sizeof(char));
  
  for(int j=0; j<filas; j++){
    for(int x=0; x<columnas*veces; x++)
      repeated[j][x] = figura[j][x%columnas];
    repeated[j][columnas * veces] = 0;
  }
  return repeated;
}
