#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct graph
{
	int source;
	int destination;
	int cost;
}graph;

void swap(graph *a, graph *b)
{
	graph temp;
	temp.source=(*a).source;
	temp.destination=(*a).destination;
	temp.cost=(*a).cost;
	(*a).source=(*b).source;
	(*a).destination=(*b).destination;
	(*a).cost=(*b).cost;
	(*b).source=temp.source;
	(*b).destination=temp.destination;
	(*b).cost=temp.cost;
}

void change(graph *a, graph b)
{
	(*a).source=b.source;
	(*a).destination=b.destination;
	(*a).cost=b.cost;
}

void sort(graph *tree, int i) // 힙 정렬
{
	graph temp;
	while(1)
	{
		if(i==1) break;
		if(tree[i].cost<tree[i/2].cost)
		{
			swap(&tree[i],&tree[i/2]);
			i/=2;
		}
		else break;
	}
}
			
struct graph del(graph *tree, int i) //힙 삭제 
{
	int parent=1,child=2;
	graph output,temp;
	change(&output,tree[1]);
	/*output.source=tree[1].source;
	output.destination=tree[1].destination;
	output.cost=tree[1].cost;*/
	change(&temp,tree[i]);
	/*temp.source=tree[i].source;
	temp.destination=tree[i].destination;
	temp.cost=tree[i].cost;*/
	i--;

	while(child<=i)
	{
		if(child<i && tree[child].cost>tree[child+1].cost) child++;
		if(temp.cost<=tree[child].cost) break;
		change(&tree[parent],tree[child]);
		/*tree[parent].source=tree[child].source;
		tree[parent].destination=tree[child].destination;
		tree[parent].cost=tree[child].cost;*/
		parent=child;
		child*=2;
	}
	change(&tree[parent],temp);
/*	tree[parent].source=temp.source;
	tree[parent].destination=temp.destination;
	tree[parent].cost=temp.cost;*/
	return output;
}

int search(int *mst, int n)
{
	int i=n;
	if(mst[n]<0) return n;
	while(mst[i]>=0) i=mst[i];
	mst[n]=i;
	return i;
}

bool cycle(int *mst, int source, int destination)
{
	int i;
	int source_root=search(mst,source);
	int destination_root=search(mst,destination);
	if(source_root==destination_root) return true;
	else return false;
}

void union1(int *mst, int n, int m)
{
	int rootn=search(mst,n);
	int rootm=search(mst,m);
	if(mst[rootn]<mst[rootm])
	{
		mst[rootm]+=mst[rootn];
		mst[rootm]=rootn;
	}
	else
	{
		mst[rootn]+=mst[rootm];
		mst[rootn]=rootm;
	}
}

int cost,edge;

int main(int argc, char *argv[])
{
	clock_t stime=clock();
	if(argc!=2)
	{
		printf("usage: ./hw3 input_filename\n");
		return 0;
	}
	FILE *fp1,*fp2;
	if((fp1=fopen(argv[1],"r"))==NULL)
	{
		printf("The input file does not exist\n");
		return 0;
	}
	fp2=fopen("hw3_result.txt","w");

	int v,e,index,i,*mst;
	graph *tree,temp;
	fscanf(fp1,"%d%d",&v,&e);
	tree=(graph*)malloc(sizeof(graph)*(e+5));
	index=e;
	tree[0].source=0;
	tree[0].destination=0;
	tree[0].cost=0;
	for(i=1; i<=e; i++)
	{
		fscanf(fp1,"%d%d%d",&tree[i].source,&tree[i].destination,&tree[i].cost);
		sort(tree,i);
	}
	fclose(fp1);
	mst=(int*)malloc(sizeof(int)*(v+5));
	for(i=0; i<v; i++) mst[i]=-1;
	
	while(1)
	{
		if(edge==v-1 || index==0) break;
		temp=del(tree,index);
		index--;
		if(!cycle(mst,temp.source,temp.destination))
		{
			union1(mst,temp.source,temp.destination);
			edge++;
			cost+=temp.cost;
			fprintf(fp2,"%d %d %d\n",temp.source,temp.destination,temp.cost);
		}
	}
	fprintf(fp2,"%d\n",cost);
	if(edge==v-1) fprintf(fp2,"CONNECTED\n");
	else fprintf(fp2,"DISCONNECTED\n");
	//fclose(fp2);
	clock_t etime=clock();
	printf("output written to hw3_result.txt.\n");
	printf("running time: %lf seconds\n",(double)(etime-stime)/CLOCKS_PER_SEC);
	return 0;
}


