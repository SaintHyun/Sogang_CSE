#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_IN 10000000
#define MAX_PAT 3000

char input[MAX_IN];
char pattern[MAX_PAT];

int main(void)
{
	FILE *f_in, *f_pat, *f_out;

	if((f_in = fopen("string.txt", "r")) == NULL){
		printf("The string file does not exist.\n");
	}
	if((f_pat = fopen("pattern.txt", "r")) == NULL){
		printf("The pattern file does not exist.\n");
	}

	if((f_out = fopen("result_naive.txt","w")) == NULL){
		printf("The result_naive.txt file was does be created.\n");
	}

	fgets(input, MAX_IN, f_in);
	fgets(pattern, MAX_PAT, f_pat);

	fclose(f_in);
	fclose(f_pat);

	int count=1;
	int *index;

	int i, j, start = 0;
	int lasts = strlen(input)-1;
	int lastp = strlen(pattern)-1;
	int endmatch = lastp;

	index = (int *)malloc(sizeof(int)*1);

	for(i=0;endmatch<=lasts;endmatch++, start++){
		if(input[endmatch] == pattern[lastp])
			for(j=0, i=start;j<lastp && input[i] == pattern[j];i++, j++);
		if (j == lastp){
			index = realloc(index, sizeof(int)*count);
			index[count-1]=start;
			count++;
		}
	}
	count--;

	int k;
	fprintf(f_out, "%d\n", count);
	if(count != 0)
	{
		for(k=0;k<count;k++)
		{
			fprintf(f_out, "%d ", index[k]);
		}
	}

	fclose(f_out);

	printf("Program complete. Result saved to result_naive.txt\n");

	free(index);

	return 0;
}
