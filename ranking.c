#include<stdio.h>
#include<stdlib.h>
void  removeDuplicates(int* a,int *numofplayers)// removes the duplicate among the arrays and resizes the length
{
	for(int i=0;i<(*numofplayers);i++)
	{
		for(int j=0;j<(*numofplayers);j++)
		{
			if(a[j]==a[j+1])
			{
				for(int k=j+1;k<(*numofplayers);k++)
				{
					a[k]=a[k+1];
				}
				(*numofplayers)--;
			}
		}
	}
	
}
 void ranking(int *a,int numofplayers,int myScore,int* bestFar) // provides the ranking
 {
 	int rank;
 	int j=0;
 	if(myScore>a[0]) // Check if myScore is greater than highest number in the array 
 	{
 		rank=1;
 	}
 	else if(myScore<a[numofplayers-1]) // Check if myScore is lesser than lowest number in the array
 	{
 		rank=numofplayers+1;
 	}
 	else
 	{
 		while(a[j]>=myScore && j<numofplayers) // checks if myscore is in Between the arrays
 		{
 			j++;
 		}
 		if(a[j-1]==myScore) // if myScore is equal to an element in the array, then rank is shared
 		rank=j;
 	else
 		rank=j+1; // here element is not equal to the element, so rank has to higher than the last element before match
 	}
 	if(rank<*bestFar) //re-assign the best rank 
 		*bestFar=rank;
 }
 void display(int *lengths,int numofplayers) //display the array
 {
 	for(int i=0;i<numofplayers;i++)
	{
		printf("%d",lengths[i]);
	}
 }
void main()
{
	int numofplayers;
	scanf("%d",&numofplayers);
	int *lengths=(int*)calloc(numofplayers,sizeof(int));
	for(int i=0;i<numofplayers;i++)
	{
		scanf("%d",&lengths[i]);
	}
	display(lengths,numofplayers);
	removeDuplicates(lengths,&numofplayers);
	printf("\n");
	//display(lengths,numofplayers);
	int noOfmyAttempts;
	printf("\n");
	scanf("%d",&noOfmyAttempts);
	int *myAttempts=(int*)calloc(noOfmyAttempts,sizeof(noOfmyAttempts));
	int bestFar=numofplayers*2;
	for(int i=0;i<noOfmyAttempts;i++)
	{
		scanf("%d",&myAttempts[i]);
		ranking(lengths,numofplayers,myAttempts[i],&bestFar);
		printf("%d\n",bestFar);
	}
	
}