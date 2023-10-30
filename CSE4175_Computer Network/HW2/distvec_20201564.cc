#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX_COST 987654321

vector<pair<pair<int, int>, int>> edge;
typedef struct table
{
    int next_hop;
    int cost;
} table;
table routing[110][110];
int dist[110];
int n, m;

void init(FILE *fin1)
{
    int i;
    int tmpa, tmpb, tmpc;
    fscanf(fin1, "%d", &n);
    while ((fscanf(fin1, "%d%d%d", &tmpa, &tmpb, &tmpc)) != EOF)
    {
        m += 2;
        edge.push_back(make_pair(make_pair(tmpa, tmpb), tmpc));
        edge.push_back(make_pair(make_pair(tmpb, tmpa), tmpc));
        routing[tmpa][tmpb].next_hop = tmpb;
        routing[tmpa][tmpb].cost = tmpc;
        routing[tmpb][tmpa].next_hop = tmpa;
        routing[tmpb][tmpa].cost = tmpc;
    }
    for (i = 0; i < n; i++)
    {
        routing[i][i].next_hop = i;
        routing[i][i].cost = 0;
    }
}

void route(int k)
{
    int i, j, source, destination, cost;

    for (i = 0; i < n; i++)
    {
        dist[i] = MAX_COST;
    }
    dist[k] = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            source = edge[j].first.first;
            destination = edge[j].first.second;
            cost = edge[j].second;
            if (dist[source] != MAX_COST && dist[destination] >= dist[source] + cost)
            {
                if (dist[destination] == dist[source] + cost)
                {
                    if (routing[k][destination].next_hop > routing[k][source].next_hop)
                    {
                        if (source != k)
                            routing[k][destination].next_hop = routing[k][source].next_hop;
                        else
                            routing[k][destination].next_hop = destination;
                    }
                }

                else if (dist[destination] > dist[source] + cost)
                {
                    dist[destination] = dist[source] + cost;
                    routing[k][destination].cost = dist[destination];
                    if (source != k)
                        routing[k][destination].next_hop = routing[k][source].next_hop;
                    else
                        routing[k][destination].next_hop = destination;
                }
            }
        }
    }
}

void message(char *argv, FILE *fout)
{
    FILE *fin2 = fopen(argv, "r");
    bool message_flag = true;
    int source, destination;
    char tmpstring[150];
    if ((fscanf(fin2, "%d%d ", &source, &destination)) == EOF)
        message_flag = false;
    fgets(tmpstring, sizeof(tmpstring), fin2);

    while (message_flag)
    {
        int cur = source;
        if (routing[cur][destination].cost == 0 || routing[cur][destination].cost == MAX_COST)
        {
            fprintf(fout, "from %d to %d cost infinite hops unreachable message %s", source, destination, tmpstring);
            memset(tmpstring, 0, sizeof(tmpstring));
            if ((fscanf(fin2, "%d%d ", &source, &destination)) == EOF)
                message_flag = false;
            fgets(tmpstring, sizeof(tmpstring), fin2);
            continue;
        }
        fprintf(fout, "from %d to %d cost %d hops ", source, destination, routing[source][destination].cost);
        while (cur != destination)
        {
            fprintf(fout, "%d ", cur);
            cur = routing[cur][destination].next_hop;
        }
        fprintf(fout, "message %s", tmpstring);
        memset(tmpstring, 0, sizeof(tmpstring));
        if ((fscanf(fin2, "%d%d ", &source, &destination)) == EOF)
            message_flag = false;
        fgets(tmpstring, sizeof(tmpstring), fin2);
    }
    fprintf(fout, "\n");
}

void change(char *input, char *argv, FILE *fin3, FILE *fout)
{
    bool change_flag = true, new_flag;
    int source, destination, cost;
    int i, j, k;
    if ((fscanf(fin3, "%d%d%d", &source, &destination, &cost)) == EOF)
        change_flag = false;
    while (change_flag)
    {
        new_flag = true;
        for (i = 0; i < m; i++)
        {
            if ((edge[i].first.first == source && edge[i].first.second == destination) || (edge[i].first.first == destination && edge[i].first.second == source))
            {
                new_flag = false;
                if (cost == -999)
                {
                    edge.erase(edge.begin() + i);
                    edge.erase(edge.begin() + i);
                    m -= 2;
                }
                else
                {
                    edge[i].second = cost;
                    edge[i + 1].second = cost;
                }
                for (j = 0; j < n; j++)
                {
                    for (k = 0; k < n; k++)
                    {
                        if (routing[j][k].next_hop == source || routing[j][k].next_hop == destination)
                        {
                            routing[j][k].cost = MAX_COST;
                            routing[j][k].next_hop = -1;
                            routing[k][j].cost = MAX_COST;
                            routing[k][j].next_hop = -1;
                        }
                    }
                }
                break;
            }
        }
        if (new_flag)
        {
            edge.push_back(make_pair(make_pair(source, destination), cost));
            edge.push_back(make_pair(make_pair(destination, source), cost));
            m += 2;
        }

        for (i = 0; i < n; i++)
        {
            route(i);
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i != j && (routing[i][j].cost > 0 && routing[i][j].cost < MAX_COST))
                    fprintf(fout, "%d %d %d\n", j, routing[i][j].next_hop, routing[i][j].cost);
                else if (i == j)
                    fprintf(fout, "%d %d %d\n", j, j, 0);
            }
            fprintf(fout, "\n");
        }
        message(argv, fout);
        if ((fscanf(fin3, "%d%d%d", &source, &destination, &cost)) == EOF)
            change_flag = false;
    }
    fclose(fin3);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        cout << "usage: distvec topologyfile messagesfile changesfile";
        return 0;
    }
    FILE *fin1 = fopen(argv[1], "r");
    FILE *fin2 = fopen(argv[2], "r");
    FILE *fin3 = fopen(argv[3], "r");
    FILE *fout = fopen("output_dv.txt", "w");
    int i, j;

    if (!fin1 || !fin2 || !fin3)
    {
        cout << "Error: open input file";
        return 0;
    }

    init(fin1);
    fclose(fin1);
    for (i = 0; i < n; i++)
    {
        route(i);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j && routing[i][j].cost > 0)
                fprintf(fout, "%d %d %d\n", j, routing[i][j].next_hop, routing[i][j].cost);
            else if (i == j)
                fprintf(fout, "%d %d %d\n", j, routing[i][j].next_hop, routing[i][j].cost);
        }
        fprintf(fout, "\n");
    }
    message(argv[2], fout);
    fclose(fin2);
    change(argv[1], argv[2], fin3, fout);
    fclose(fout);
    printf("Complete. Output file written to output_dv.txt\n");
    return 0;
}