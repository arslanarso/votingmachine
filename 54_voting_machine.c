#include <stdio.h>
#define CHAR_SIZE 15
#define SIZE 10

int main()
{
	int option;
	char cat_name[CHAR_SIZE];
	char categories[SIZE][CHAR_SIZE];
	int cat_num;
	int i, j;
	int cat;
	int votes[SIZE] = {0};
	int vote_num = 0;
	int small, large, pos_small, pos_large;
	
	printf("\n ============================");
	printf("\n ||                        ||");
	printf("\n ||     VOTING MACHINE     ||");
	printf("\n ||        ver. 1.0        ||");
	printf("\n ||                        ||");
	printf("\n ============================");
	printf("\n");
	
	do
	{
		printf("\n ****** MAIN MENU ******");
		printf("\n [1] Enter categories");
		printf("\n [2] Enter votes");
		printf("\n [3] Show results");
		printf("\n [4] Display statistics");
		printf("\n [5] Exit");
		
		printf("\n\n Enter your choice: ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1:
				printf(" Enter category name: ");
				scanf("%s", cat_name);
				
				printf(" Enter number of categories: ");
				scanf("%d", &cat_num);
				
				for(i=0; i<cat_num; i++)
				{
					printf(" Enter category %d: ", i+1);
					scanf("%s", categories[i]);
				}
				
				break;
			
			case 2:
				do
				{
					vote_num++;
					printf("\n VOTE: %d", vote_num);
					printf("\n What is your favorite %s?", cat_name);
					
					for(i=0; i<cat_num; i++)
					{
						printf("\n [%d] %s", i+1, categories[i]);
					}
					printf("\n [%d] Finish", cat_num+1);
					
					printf("\n Enter your choice: ");
					scanf("%d", &cat);
					votes[cat-1]++;
				} while(cat != (cat_num+1));
				
				vote_num--;
				
				break;
			
			case 3:
				printf("\n ****** Voting Results ******");
				printf("\n %15s \t Votes \t Histogram\n", cat_name);
				
				for(i=0; i<cat_num; i++)
				{
					printf(" %15s \t %d \t ", categories[i], votes[i]);
					
					for(j=1; j<=votes[i]; j++)
						printf("*");
					
					printf("\n");
				}
				
				break;
			
			case 4:
				small = votes[0];
				
				for(i=1; i<cat_num; i++)
				{
					if(votes[i] < small)
					{
						small = votes[i];
						pos_small = i;
					}
				}
				
				large = votes[0];
				
				for(i=1; i<cat_num; i++)
				{
					if(votes[i] > large)
					{
						large = votes[i];
						pos_large = i;
					}
				}
				
				printf("\n Number of votes: %d", vote_num);
				printf("\n The most popular %s is: %s", cat_name, categories[pos_large]);
				printf("\n The least popular %s is: %s", cat_name, categories[pos_small]);
				printf("\n");
				
				break;
			
			case 5:
				break;
			
			default:
				printf(" ERROR: Invalid choice!\n");
		}
		
	} while(option != 5);

	
	
	return 0;
	
	
}
