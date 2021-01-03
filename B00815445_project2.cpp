#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
 
using namespace std;
#define N 1000

const char* board[N][N]; 
int quad = 0, no = 0;
int cord_x=0, cord_y=0;

void tromino(int x_board, int y_board, int x_missing, int y_missing, int board_size) 
{ 
	int half_size = board_size/2, x_center = 0, y_center = 0;

	x_center = x_board + half_size - 1;
	y_center = y_board + half_size - 1;

	string Tilename;
  
  	//printf("\nBoardsize is : %d", board_size);
	if (board_size == 2)
    {
    	if (strcmp(board[x_board][y_board + 1] , "0")==0 && strcmp(board[x_board + 1][y_board],"0")==0 && strcmp(board[x_board + 1][y_board + 1],"0")==0)
		{
	  		board[x_board][y_board + 1] = "LR";
	  		board[x_board + 1][y_board] = "LR";
	  		board[x_board + 1][y_board + 1] = "LR";
	  		
	  		Tilename = "LR";
		}
		if (strcmp(board[x_board][y_board], "0")==0 && strcmp(board[x_board + 1][y_board],"0")==0 && strcmp(board[x_board + 1][y_board + 1],"0")==0)
		{
			//printf( "%4s","LL" );
			board[x_board][y_board] = "LL";
			board[x_board + 1][y_board] = "LL";
			board[x_board + 1][y_board + 1] = "LL";

	  		Tilename = "LL";
		}
      
		if (strcmp(board[x_board][y_board + 1],"0")==0 && strcmp(board[x_board][y_board],"0")==0 && strcmp(board[x_board + 1][y_board + 1],"0")==0)
		{
			//printf( "%4s","UR" );
			board[x_board + 1][y_board + 1] = "UR";
			board[x_board][y_board + 1] = "UR";
			board[x_board][y_board] = "UR";
			
	  		Tilename = "UR";
		}
      
		if (strcmp(board[x_board][y_board + 1],"0")==0 && strcmp(board[x_board + 1][y_board],"0")==0 && strcmp(board[x_board][y_board],"0")==0)
		{
			//printf( "%4s","UL" );
	  		board[x_board][y_board] = "UL";
	  		board[x_board][y_board + 1] = "UL";
	  		board[x_board + 1][y_board] = "UL";

	  		Tilename = "UL";
		}
      	return;
    }
  	//printf("\nTilename is :%s", Tilename);	
	if (x_missing <= x_center)
    {
 		if (y_missing <= y_center)
		{
	  		if (strcmp(board[x_center][y_center + 1],"0") == 0 && strcmp(board[x_center + 1][y_center],"0") == 0 && strcmp(board[x_center + 1][y_center + 1],"0") == 0)
	    	{
	    		//printf( "%4s","LR" );
				board[x_center][y_center + 1] = "LR";
				board[x_center + 1][y_center] = "LR";
				board[x_center + 1][y_center + 1] = "LR";
				quad = 1;

				Tilename = "LR";
	    	}
	    	//printf("\nIts here");
		}
      	else
		{
			if (strcmp(board[x_center][y_center],"0") == 0 && strcmp(board[x_center + 1][y_center],"0") == 0 && strcmp(board[x_center + 1][y_center + 1],"0") == 0)
	    	{
	    		//printf( "%4s","LL" );
				board[x_center][y_center] = "LL";
				board[x_center + 1][y_center + 1] = "LL";
				board[x_center + 1][y_center] = "LL";
				quad = 2;

				Tilename = "LL";
			}
			//printf("\nIts here LL");
		}
		//printf("\nTilename in if :%s", Tilename);
    }
  	else
    {
		if (y_missing <= y_center)
		{
			if (strcmp(board[x_center][y_center + 1],"0") == 0 && strcmp(board[x_center][y_center],"0") == 0 && strcmp(board[x_center + 1][y_center + 1],"0") == 0)
	    	{
	    		//printf( "%4s","UR" );
				board[x_center][y_center] = "UR";
				board[x_center][y_center + 1] = "UR";
				board[x_center + 1][y_center + 1] = "UR";
				quad = 3;

				Tilename = "UR";
			}
		}
      	else
		{
			if (strcmp(board[x_center + 1][y_center],"0") == 0 && strcmp(board[x_center][y_center],"0") == 0 && strcmp(board[x_center][y_center + 1],"0") == 0)
	    	{
	    		//printf( "%4s","UL" );
				board[x_center][y_center] = "UL";
				board[x_center][y_center + 1] = "UL";
				board[x_center + 1][y_center] = "UL";
				quad = 4;

				Tilename = "UL";
			}
		}
	}
	//printf("\nTilename outside if else :%s", Tilename);
	if (quad == 1)
    {
		tromino (x_board, y_board, x_missing, y_missing, half_size);
		tromino (x_board, y_center + 1, x_center, y_center + 1, half_size);
		tromino (x_center + 1, y_board, x_center + 1, y_center, half_size);
 		tromino (x_center + 1, y_center + 1, x_center + 1, y_center + 1, half_size);
	}
	if (quad == 2)
    {
		tromino (x_board, y_board, x_center, y_center, half_size);
		tromino (x_board, y_center + 1, x_missing, y_missing, half_size);
		tromino (x_center + 1, y_board, x_center + 1, y_center, half_size);
		tromino (x_center + 1, y_center + 1, x_center + 1, y_center + 1, half_size);
    }
	if (quad == 3)
    {
		tromino (x_board, y_board, x_center, y_center, half_size);
 		tromino (x_board, y_center + 1, x_center, y_center + 1, half_size);
		tromino (x_center + 1, y_board, x_missing, y_missing, half_size);
 		tromino (x_center + 1, y_center + 1, x_center + 1, y_center + 1, half_size);
    }
    if (quad == 4)
    {
   		tromino (x_board, y_board, x_center, y_center, half_size);
		tromino (x_board, y_center + 1, x_center, y_center + 1, half_size);
		tromino (x_center + 1, y_board, x_center + 1, y_center, half_size);
		tromino (x_center + 1, y_center + 1, x_missing, y_missing, half_size);
	}
	//return Tilename;
}

int main () 
{
	int i,j,board_size, x_missing, y_missing,new_boardsize;
	string Tilename;

  	do
    { 
		printf ("\n-------------------------------------");
		printf ("\nPlease input n (the board size is 2^n) (0 to quit): ");
		scanf ("%d", &board_size);
      	new_boardsize = pow (2, board_size);

		if (board_size)
		{
	  		printf ("\nEnter x_coordinate of missing hole: ");
			scanf ("%d", &x_missing);
			printf ("\nEnter y_coordinate of missing hole: ");
			scanf ("%d", &y_missing);

			for (i = 0; i < new_boardsize; i++)
	    	{
				for (j = 0; j < new_boardsize; j++)
				{
					board[i][j] = "0";
				} 
			}
			board[x_missing][y_missing] = "-1";
	  
			tromino (0, 0, x_missing, y_missing, new_boardsize);
	  		
			for (i = 0; i < new_boardsize; i++)
	    	{
				for (j = 0; j < new_boardsize; j++)
				{
					if (i == x_missing && j == y_missing)
					{
						board[i][j] = "-1";
						printf ("%4s", "MS");
					}
					else
					{
						//Tilename = tromino (1, 1, x_missing, y_missing, pow(2,board_size));
						//printf("%4s", Tilename.c_str());
						printf ("%4s", board[i][j]);
					}
				}
				//Tilename = tromino (1, 1, x_missing, y_missing, new_boardsize);
				cout<<endl;
			}
		}
	}while(board_size);

	return EXIT_SUCCESS;
}