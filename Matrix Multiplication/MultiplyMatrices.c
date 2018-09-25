// C program to multiply two square matrices.
#include <stdio.h>
#include <stdlib.h>

void multiply(int grid1[][10], int grid2[][10], int r1, int r2, int c1, int c2)
{
	int result[10][10];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < r2; k++)
                result[i][j] += grid1[i][k]*grid2[k][j];
        }
    }

    printf("Resulting matrix is \n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
            printf("%d ", result[i][j]);
         printf("\n");
    }
}

int main(int argc, char **argv)
{
	if(argc!=2)
	{
		printf("Command Line Arguements were incorrect.\n");
		printf("It should look like: (program-name) (first-matrix-file) (second-matrix-file)\n");
		exit(0);
	}

	int r1,c1,r2,c2;
	int fmatrix[10][10];
	int smatrix[10][10];
	int i;

	FILE * firstm;
	FILE * secondm;
	firstm=fopen(argv[1],  "r");
	secondm=fopen(argv[2], "r");
	
	if (firstm == NULL)    {
        printf("Cannot open the first matrix file. \n");
        exit(0);
    }
    if (secondm == NULL)    {
        printf("Cannot open the second matrix file. \n");
        exit(0);
    }
//filling in first matrix
	fscanf(firstm, "%d %d", &r1, &c1);
//	printf("DEBUG: %d %d\n", r1, c1);
	i=0;
	for(int x=0;x<r1;x++)
	{
		for(int y=0;y<c1;y++)
		{
			fscanf(firstm, "%d", &fmatrix[x][y]);
			printf("%d ", fmatrix[x][y]);
			i++;
		}
		printf("\n");
	}
    printf("\n");
    i=0;

//filling in second matrix
	fscanf(secondm, "%d %d", &r2, &c2);
//	printf("DEBUG: %d %d\n", r2, c2);
	i=0;
	for(int x=0;x<r2;x++)
	{
		for(int y=0;y<c2;y++)
		{
			fscanf(secondm, "%d", &smatrix[x][y]);
//			printf("%d ", smatrix[x][y]);
			i++;
		}
		printf("\n");
	}

    if(c1!=r2)
    {
    	printf("The matrix tables are incompatible and connot be multiplied\n");
    	exit(0);
    }
    multiply(fmatrix, smatrix, r1, r2, c1, c2);
    fclose(firstm);
    fclose(secondm);
    return 0;
}