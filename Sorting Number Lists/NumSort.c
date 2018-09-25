#include <stdio.h>
#include <string.h>

void sortDoubleArray(int *array, int num, int sortorder){
    int i, j, temp;

    //acsending sort
    if(sortorder==0){
        for (i = 0; i < num; i++)
        {
            for (j = 0; j < (num - i - 1); j++)
            {
                if (array[j] > array[j + 1])
                {
                    temp = array[j];
                    array[j + 1] = temp;
                }
            }
        }
    }
    
    //desending sort
    else if(sortorder==1)
    {
        for (i = 0; i < num; i++)
        {
            for (j = 0; j < (num - i - 1); j++)
            {
                if (array[j] < array[j + 1])
                {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    //lol wut is sorting
    else
    {
        printf("Wrong sort conditions dingus.\n");
    }
}

int main(int argc, char ** argv){

    int array[10000];
    int i, num, sortorder, integer;

    //Checking args
    if(argc!=4)
    {
        printf("USAGE:\n");
        printf("ProgramName [-a | -d | -h] inputFileName outputFileName\n");
        printf("-a \t to sort in ascending order\n");
        printf("-d \t to sort in decending order\n");
        printf("-h \t to display this help message\n");
        return 1;
    }
    else if(strcmp(argv[1], "-a")==0)
    {
        printf("Ascending order selected!\n");
        sortorder=0;
    }
    else if(strcmp(argv[1], "-d")==0)
    {
        printf("Descending order selected!\n");
        sortorder=1;
    }

    //file pointers
    FILE *outputfile;
    FILE *inputfile;

    //check to see if output file exists
    outputfile=fopen(argv[3], "r");
    if(outputfile!=NULL)
    {
        printf("File %s already exists. Do you want to replace it? (y/n): ", argv[3]);
        char choice;
        scanf("%c", &choice);
        switch (choice)
        {
            case 'y':
            case 'Y':
                //continue on
                fclose(outputfile);
                break;
            case 'n':
            case 'N':
                //quit program
                printf("Program will terminate.\n");
                fclose(outputfile);
                return 1;
        }
    }

    //overwrite/create output file
    outputfile=fopen(argv[3], "w+");
    if(outputfile==NULL)
    {
        printf("Outfile not opened, program will terminate.\n");
        return 1;
    }

    //open input file
    inputfile=fopen(argv[2],"r");
    if(inputfile==NULL)
    {
        printf("Infile not opened, program will terminate.\n");
        return 1;
    }

    //starting counters
    i=0, num=1;

    //infinite scan for integers
    while(fscanf(inputfile, "%d", &integer) != EOF)
    {
        array[i]=integer;
        i++;
        num++;
    }
    
    //passing array to function with given parameters
    sortDoubleArray(array, num, sortorder); 

    //printing results
    printf("Sorted array is...\n");
    i=0;
    while(array[i]!='\0')
    {
        printf("%d\n", array[i]);
        fprintf(outputfile, "%d\n", array[i]);
        i++;
    }

    //closing file streams and program
    fclose(inputfile);
    fclose(outputfile);
    return 0;
}