#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "varlist.h"

// TODO: Fill in
VarNode *make_varlist(char *var, int val, VarNode *next)
{
    VarNode *NewNode = (VarNode *)malloc(sizeof(VarNode));
    NewNode->var = var;
    NewNode->val = val;
    NewNode->next = next;
    // printf("Unimplemented: make_varlist()\n");
    return NewNode;
}

// TODO: Fill in
int lookup_var(VarNode *head, char *var)
{
    VarNode *tmp = (VarNode *)malloc(sizeof(VarNode));
    tmp = head;
    while (tmp != NULL)
    {
        if (!strcmp(var, tmp->var))
        {
            return tmp->val;
        }
        tmp = tmp->next;
    }
    // printf("Unimplemented: lookup_var()\n");
    return 0;
}

// TODO: Fill in
void free_varlist(VarNode *head)
{
    VarNode *list = (VarNode *)malloc(sizeof(VarNode));
    VarNode *tmp = (VarNode *)malloc(sizeof(VarNode));
    tmp = head;
    list = head;
    while (tmp != NULL)
    {
        list = list->next;
        free(tmp);
        tmp = list;
    }
    // printf("Unimplemented: free_varlist()\n");
    return;
}
