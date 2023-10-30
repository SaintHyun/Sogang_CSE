#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_IN 10000000
#define MAX_PAT 3000

char input[MAX_IN];
char pattern[MAX_PAT];
int failure[MAX_PAT];

int main(void)
{
	/*FILE *f_in, *f_pat, *f_out;

	if((f_in = fopen("string.txt", "r")) == NULL){
		printf("The string file does not exist.\n");
	}
	if((f_pat = fopen("pattern.txt", "r")) == NULL){
		printf("The pattern file does not exist.\n");
	}

	if((f_out = fopen("result_kmp.txt","w")) == NULL){
		printf("The result_kmp.txt file was not be created.\n");
	}

	fgets(input, MAX_IN, f_in);
	fgets(pattern, MAX_PAT, f_pat)

	fclose(f_in);
	fclose(f_pat);*/
	gets(input); gets(pattern);

	int count = 1;
	int *index;

	index=(int *)malloc(sizeof(int)*count);

	int i, j;
	int end = strlen(pattern);
	failure[0] = -1;
	for(j=1;j<end;j++){
		i=failure[j-1];
		while((pattern[j]!=pattern[i+1] && i>=0)) i = failure[i];
		if(pattern[j] == pattern[i+1]) failure[j] = i+1;
		else failure[j] = -1;
	}

	i=0, j=0;
	int lens = strlen(input);
	int lenp = strlen(pattern);
	while(i<lens){
		if(input[i] == pattern[j]){i++; j++;}
		else if(j == 0) i++;
		else j = failure[j-1] + 1;

		if(j == lenp)
		{
			index=(int *)realloc(index, sizeof(int)*count);
			index[count-1]=i-lenp;
			count++;
		}
	}
	count--;


	printf("%d\n", count);
	if(count != 0)
	{
		for(i=0;i<count;i++)
		{
			printf( "%d ",index[i]);
		}
	}


	//fclose(f_out);

	printf("Program complete. Result saved to result_kmp.txt\n");

	return 0;
}
