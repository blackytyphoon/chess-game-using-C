   #include<stdio.h>
   #include<stdlib.h>

int b[8][8] ={
{21,31,41,55,66,41,31,21},              
{1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{-1,-1,-1,-1,-1,-1,-1,-1},
{-21,-31,-41,-66,-55,-42,-32,-22}
};


   


int main()
{
int i,m;
int x1,x2,y1,y2;
int c=1,k=1,j=1;
again:
while(j!=0)
{ int x1,x2,y1,y2;   
x1=0;
x2=0;
y1=0;
y2=0;
 

	printf("below is chess board cordinates\n\n\n");
  for(i=0;i<8;i++)
    {
        for(m=0;m<8;m++)
        printf("%d %d   ",i,m);
        printf("\n");
    }
    printf("\n\n\n below is chess board\n\n");
    for(i=0;i<8;i++)
    {
        for(m=0;m<8;m++)
        printf("%d  ",b[i][m]);
        printf("\n");
    }
   
 getchar();
if(j%2==1)
{printf("for white pieces \n");
 printf("enter the row and column of the piece to be moved");
 scanf("%d %d",&y1,&x1);
 printf("enter the row and column where to be moved");
 scanf("%d %d",&y2,&x2);
if(x1>=0 && x1<=7 || x2>=0 && x2<=7 || y1>=0 && y1<=7 || y2>=0 && y2<=7)
{ 
  if(b[y1][x1]==1)
    { 
       if((y2-y1)==1 && x1==x2)
          {
              b[y2][x2]=1;
              b[y1][x1]=0;
              j++;
              goto again;
          }
          else if(y2==y1+1 && x2==x1-1 || y2==y1+1 && x2==x1+1)
          {
            b[x1][y1]=0;
            b[x2][y2]=1;
            j++;
            goto again;
          }
          else 
          {
              printf("move not possible");
               goto again;
          
           }

    }
     else if(b[y1][x1]==21)
     {
         if (y2== y1) {
    // The move is along the same row
    int colStep = (x2 > x1) ? 1 : -1;
    int col;
    for (col = x1 + colStep; col != x2; col += colStep) {
      if (b[y1][col] != 0) {
        printf(" There is a piece blocking the horizontal path");
        goto again;
      }
      else
      {
         b[y2][x2]=21;
         b[y1][x1]=0;
         j++;
          goto again;
      }
    }

   
  } else if (x2 == x1) {
    // The move is along the same column
    int rowStep = (y2 > y1 ) ? 1 : -1;
    int row;
    for (row =  y1 + rowStep; row != y2; row += rowStep) {
      if (b[row][x1] != 0) {
       printf(" There is a piece blocking the horizontal path");
         goto again;
      }
      else
      {
         b[y2][x2]=21;
         b[y1][x1]=0;
         j++;
           goto again;
         }
    
}
     }
    
    
}
else if(b[y1][x1]==31)
{
 int rowDiff = abs(y2 - y1);
  int colDiff = abs(x2 - x1);
  if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2) ) {
            if(b[y2][x2]<=0)
            {
           b[y2][x2]=31;
           b[y1][x1]=0;
           j++;
             goto again;
            }
            else{
            printf(" invalid move");
          goto again;
            }

  }
  else{
            printf(" invalid move");
         goto again;
            } 
}
else if(b[y1][x1]==41)
{
   if (abs(y2 - y1) != abs(x2 - x1)) {
    // The move is not along a diagonal
      printf(" invalid move");
          goto again;
  }
  int rowStep = (y2> y1) ? 1 : -1;
  int colStep = (x2> x1) ? 1 : -1;
  int row, col;
  for (row = y1 + rowStep, col = x1 + colStep; row != y2 && col != x2; row += rowStep, col += colStep) {
    if (b[row][col] != 0 ) {
      printf(" invalid move");
          goto again;
    }
  }
  if(b[y2][x2]<=0)
            {
           b[y2][x2]=31;
           b[y1][x1]=0;
           j++;
            goto again;
            }


}
else if(b[y1][x1]==55)
{
if (y1 == y2) {
    // The move is along the same row
    int colStep = (x2 > x1) ? 1 : -1;
    int col;
    for (col = x1 + colStep; col != x2; col += colStep) {
      if (b[y1][col] != 0) {
        printf(" invalid move");
         goto again;
      }
    }
      b[y2][x2]=55;
           b[y1][x1]=0;
           j++;
             goto again;
  } else if (x1 == x2) {
    // The move is along the same column
    int rowStep = (y2 > y1) ? 1 : -1;
    int row;
    for (row = y1 + rowStep; row != y2; row += rowStep) {
      if (b[row][x1] != 0) {
         printf(" invalid move");
         goto again;
      }
    }
       b[y2][x2]=55;
           b[y1][x1]=0;
           j++;
          goto again;
  } else if (abs(y2 - y1) == abs(x2 - x1)) {
    // The move is along a diagonal
    int rowStep = (y2 > y1) ? 1 : -1;
    int colStep = (x2 > x1) ? 1 : -1;
    int row, col;
    for (row =y1  + rowStep, col = x1 + colStep; row != y2 && col != x2; row += rowStep, col += colStep) {
      if (b[row][col] != 0) {
          printf(" invalid move");
          goto again;
      }
    }
     b[y2][x2]=55;
           b[y1][x1]=0;
           j++;
             goto again;
  } else {
     printf(" invalid move");
          goto again;
  }
}
else if(b[y1][x1]==66)
{
	 int rowDiff = abs(y2 - y1);
  int colDiff = abs(x2 - x1);
  if (rowDiff > 1 || colDiff > 1) {
    printf(" invalid move");
          goto again;
  }
  if (b[y2][x2] != 0 && b[y2][x2] / 10 == b[y1][x1] / 10) {
    printf(" invalid move");
          goto again;
  }
  b[y2][x2]=66;
           b[y1][x1]=0;
           j=0;
          printf("white lost");
}
}
else
{
    printf("move not possible ");
 goto again;
}
}
else
{printf("for black pieces \n");
 printf("enter the row and column of the piece to be moved");
 scanf("%d %d",&y1,&x1);
 printf("enter the row and column where to be moved");
 scanf("%d %d",&y2,&x2);
 if(x1>=0 && x1<=7 || x2>=0 && x2<=7 || y1>=0 && y1<=7 || y2>=0 && y2<=7)
{ 
  if(b[y1][x1]==-1)
    { 
       if((y2-y1)==-1 && x1==x2)
          {
              b[y2][x2]=-1;
              b[y1][x1]=0;
              j++;
              goto again;
          }
          else if(y2==y1-1 && x1==x2-1 || y2==y1-1 && x1==x2+1)
          {
            b[x1][y1]=0;
            b[x2][y2]=-1;
            j++;
            goto again;
          }
          else 
          {
              printf("move not possible");
               goto again;
          
           }

    }
     else if(b[y1][x1]==-21)
     {
         if (y2== y1) {
    // The move is along the same row
    int colStep = (x1 > x2) ? 1 : -1;
    int col;
    for (col = x1 + colStep; col != x2; col -= colStep) {
      if (b[y1][col] != 0) {
        printf(" There is a piece blocking the horizontal path");
        goto again;
      }
      else
      {
         b[y2][x2]=-21;
         b[y1][x1]=0;
         j++;
          goto again;
      }
    }

   
  } else if (x2 == x1) {
    // The move is along the same column
    int rowStep = (y1 > y2 ) ? 1 : -1;
    int row;
    for (row =  y1 + rowStep; row != y2; row -= rowStep) {
      if (b[row][x1] != 0) {
       printf(" There is a piece blocking the horizontal path");
         goto again;
      }
      else
      {
         b[y2][x2]=-21;
         b[y1][x1]=0;
         j++;
           goto again;
         }
    
}
     }
    
    
}
else if(b[y1][x1]== -31)
{
 int rowDiff = abs(y1 - y2);
  int colDiff = abs(x1 - x2);
  if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2) ) {
            if(b[y2][x2]<=0)
            {
           b[y2][x2]=-31;
           b[y1][x1]=0;
           j++;
             goto again;
            }
            else{
            printf(" invalid move");
          goto again;
            }

  }
  else{
            printf(" invalid move");
         goto again;
            } 
}
else if(b[y1][x1]==-41)
{
   if (abs(y1 - y2) != abs(x1 - x2)) {
    // The move is not along a diagonal
      printf(" invalid move");
          goto again;
  }
  int rowStep = (y1> y2) ? 1 : -1;
  int colStep = (x1> x2) ? 1 : -1;
  int row, col;
  for (row = y1 - rowStep, col = x1 - colStep; row != y2 && col != x2; row -= rowStep, col -= colStep) {
    if (b[row][col] != 0 ) { 
      printf(" invalid move");
          goto again;
    }
  }
  if(b[y2][x2]>=0)
            {
           b[y2][x2]=-41;
           b[y1][x1]=0;
           j++;
            goto again;
            }


}
else if(b[y1][x1]==-55)
{
if (y1 == y2) {
    // The move is along the same row
    int colStep = (x1 > x2) ? 1 : -1;
    int col;
    for (col = x1 - colStep; col != x2; col -= colStep) {
      if (b[y1][col] != 0) {
        printf(" invalid move");
         goto again;
      }
    }
      b[y2][x2]=-55;
           b[y1][x1]=0;
           j++;
             goto again;
  } else if (x1 == x2) {
    // The move is along the same column
    int rowStep = (y1 > y2) ? 1 : -1;
    int row;
    for (row = y1 - rowStep; row != y2; row -= rowStep) {
      if (b[row][x1] != 0) {
         printf(" invalid move");
         goto again;
      }
    }
       b[y2][x2]=-55;
           b[y1][x1]=0;
           j++;
           continue ;
  } else if (abs(y2 - y1) == abs(x2 - x1)) {
    // The move is along a diagonal
    int rowStep = (y1 > y2) ? 1 : -1;
    int colStep = (x1 > x2) ? 1 : -1;
    int row, col;
    for (row =y1  - rowStep, col = x1 + colStep; row != y2 && col != x2; row -= rowStep, col -= colStep) {
      if (b[row][col] != 0) {
          printf(" invalid move");
          goto again;
      }
    }
     b[y2][x2]=-55;
           b[y1][x1]=0;
           j++;
             goto again;
  } else {
     printf(" invalid move");
          goto again;
  }
}
else if(b[y1][x1]==-66)
{
	 int rowDiff = abs(y2 - y1);
  int colDiff = abs(x2 - x1);
  if (rowDiff > 1 || colDiff > 1) {
    printf(" invalid move");
          goto again;
  }
  if (b[y2][x2] != 0 && b[y2][x2] / 10 == b[y1][x1] / 10) {
    printf(" invalid move");
          goto again;
  }
  b[y2][x2]=55;
           b[y1][x1]=0;
           j=0;
          goto again;
}
}
else
{
    printf("move not possible ");
 goto again;
}
	
}
}
}
