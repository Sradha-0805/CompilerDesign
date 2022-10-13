#include<stdio.h>
#include<stdlib.h>
int main()
{
	int EE = 0, EO = 1, OO = 2, OE = 3, n, i, j = 0, state = 0;;
	
	printf("Enter the number of elements in the input sttring\n");
	scanf("%d", &n);
	char input_string[n];
	for( i = 0; i < n; i++)
	 {
	   printf("Enter the input string\n");
		scanf("%c", &input_string[i]);
		 /*if((input_string[i] != 'a' ) || (input_string[i] != 'b'))
		    {
		    		printf("Invalid string");
		    		break;
		    } */
	  }
	  
	  while(1)
 {
 	  if(input_string[j] == '\n')
 	  		break;
	  if(state == 0)
	  {
	  		state = (input_string[j++] == 'a') ? OE : EO; 
	  }
	  else if( state == 1)
	  {
	  		state = (input_string[j++] == 'a') ? OO : EE;
	  }
	  else if( state == 2)
	  {
	  		state = (input_string[j++] == 'a') ? EO : OE;
	  }
	  else if(state == 3)
	  {
	  		state = (input_string[j++] == 'a') ? EE : OO;
	  }
	
 }
 
 if(state == EE)
 {
 		printf("input string accepted\n");
 }
 else
 	printf("input string not accepted\n");
 }	
		
