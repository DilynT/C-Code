#include <stdio.h>
#include <stdlib.h>

int main()
{
	double x, y;
	char symbol;
	int menuoption;

	printf("Welcome To The Super Simple Calculator\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Options:\n");
	printf("	1. Guide\n");
	printf("	2. Mode Select\n");
	printf("	3. Exit\n");
	scanf("%d", &menuoption);

	switch(menuoption)
	{
		case 1: 
			printf("DEBUG: Guide\n");
			
			//guide();
			break;
		case 2:
			system ("clear");
			printf("Mode Select:\n");
			printf("\t1. Standard\n");
			printf("\t2. TBA\n");
			printf("\t3. TBA\n");
			printf("\t4. TBA\n");

			break;
		case 3:
			exit(0);
			break;
		default:
			printf("YOU FUCKING TWAT MUNCH CANT TYPE RIGHT\n");
			exit(0);
	}

	while(1)
	{
		scanf("%lf %c %lf", &x, &symbol, &y);
		switch(symbol)
		{
			case '+':
				printf("%.2lf + %.2lf = %.2lf\n", x, y, x+y);
				break;
			case '-':
				printf("%.2lf - %.2lf = %.2lf\n", x, y, x-y);
				break;
			case '*':
				printf("%.2lf * %.2lf = %.2lf\n", x, y, x*y);
				break;
			case '/':
				printf("%.2lf / %.2lf = %.2lf\n", x, y, x/y);
				break;
		}
	}
return 0;
}