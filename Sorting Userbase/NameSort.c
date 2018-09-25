#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char **argv)
{
	//Woo Variables
	int howmany;
	char **fname;
	char **lname;
	char *tmp;
	char *tmp2;

	//Read the unsorted file
	FILE *inputFile = fopen(argv[1], "r");

	if(inputFile == NULL)
	{
		printf("The file could not be opened or was not given.\n");
		return;
	}

	//Asks for how many names to sort from the list
	printf("How many names are in your list?\n");
	scanf("%d",&howmany);

	fname=malloc(howmany*sizeof( char *));
	lname=malloc(howmany*sizeof( char *));

    if(fname==NULL)
    {
        printf("To Much Deditated WAM required to do this\n");
        exit(0);
    }

    //This loop checks the first letters of all first and last names and makes sure they are capital letters for formal reasons
    for(int i=0;i<howmany;i++)
	{
	    fname[i]=malloc(51);
	    lname[i]=malloc(51);
		fscanf(inputFile, "%50s %50s", fname[i], lname[i]);

		if(fname[i][0] >= 'a' && fname[i][0] <= 'z')
		{
			fname[i][0] -= 32;
		}
		if(lname[i][0] >= 'a' && lname[i][0] <= 'z')
		{
			lname[i][0] -= 32;
		}
	}

	//Check for sort by last names. Defaults to firstname if lastname is the same.
	for(int i =0;i<howmany;i++)
	{
		for(int j=0;j<howmany-1;j++)
		{
			if(strcmp(lname[j],lname[j+1])>0)
			{
				tmp=lname[j];
				lname[j]=lname[j+1];
				lname[j+1]=tmp;
				tmp2=fname[j];
				fname[j]=fname[j+1];
				fname[j+1]=tmp2;
			}
			else if(strcmp(lname[j],lname[j+1])==0)
			{
				if(strcmp(fname[j],fname[j+1])>0)
				{
					tmp=fname[j];
					fname[j]=fname[j+1];
					fname[j+1]=tmp;
					tmp2=lname[j];
					lname[j]=lname[j+1];
					lname[j+1]=tmp2;
				}
			}
		}
	}
	//opens the file to write out too and it also prints output in the text window to check for immediate correctness.
	FILE *outputFile = fopen(argv[2], "w");
	for(int i=0;i<howmany;i++)
	{
		printf("%s %s\n", fname[i], lname[i]);
		fprintf(outputFile, "%s %s\n", fname[i], lname[i]);
	}
	//properly closes and frees up allocated stuffs
	free(fname);
	free(lname);
	fclose(outputFile);
	fclose(inputFile);
}