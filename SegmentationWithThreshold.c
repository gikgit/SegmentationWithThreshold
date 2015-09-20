#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "Function.h"
 

int main(int argc, char *argv[])

{
  int i,j;
  int seuilMV;
  int length,width;

  float** Img;
  float** y;  
  float** x;  
 
  printf("Input a threshold: ");
  scanf("%d",&seuilMV);
 
  Img=LoadImagePgm(argv[1],&length,&width);
  x=fmatrix_allocate_2d(length,width);
  y=fmatrix_allocate_2d(length,width);
 

  for(i=0;i<length;i++){
	for(j=0;j<width;j++){
		x[i][j]=0;
		y[i][j]=0;
	}
  }
  
  for(i=0;i<length;i++){
	for(j=0;j<width;j++){
		if(Img[i][j]<seuilMV){
			x[i][j]=0;
		}
		else{
			x[i][j]=1;
		}
	}
  }

  for(i=0;i<length;i++){
	for(j=0;j<width;j++){
		if(x[i][j]==0){
			y[i][j]=0;
		}
		else{
			y[i][j]=255;
		}
	}
  }
  	
  SaveImagePgm("image_name",y,length,width);
  system("display image_name.pgm&");  

  free_fmatrix_2d(Img);
  free_fmatrix_2d(x);
  free_fmatrix_2d(y);
 
  printf("\n Ending... \n\n\n");
  return 0; 	 
}
