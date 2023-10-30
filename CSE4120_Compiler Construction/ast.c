#include <stdio.h>
#include <stdlib.h>
#include "varlist.h"
#include "ast.h"

AST *make_num_ast(int n)
{
    AST *ast = (AST *)malloc(sizeof(AST));
    ast->kind = Number;
    ast->num = n;
    ast->id = NULL;
    ast->left = NULL;
    ast->right = NULL;
    return ast;
}

AST *make_id_ast(char *s)
{
    AST *ast = (AST *)malloc(sizeof(AST));
    ast->kind = Identifier;
    ast->num = 0;
    ast->id = s;
    ast->left = NULL;
    ast->right = NULL;
    return ast;
}

AST *make_binop_ast(NODE_KIND kind, AST *oprnd_1, AST *oprnd_2)
{
    AST *ast = (AST *)malloc(sizeof(AST));
    ast->kind = kind;
    ast->num = 0;
    ast->id = NULL;
    ast->left = oprnd_1;
    ast->right = oprnd_2;
    return ast;
}

// TODO: Fill in
AST *make_neg_ast(AST *oprnd)
{
    AST *ast = (AST *)malloc(sizeof(AST));
    ast->kind = Neg;
    ast->num = 0;
    ast->id = 0;
    ast->left = oprnd;
    ast->right = NULL;

    /*if (oprnd->kind == Number)
    {
        ast->kind = Number;
        ast->num = (-1) * oprnd->num;
        ast->id = NULL;
        ast->left = NULL;
        ast->right = NULL;
    }
    else if (oprnd->kind == Identifier)
    {
        AST *tmp1 = (AST *)malloc(sizeof(AST));
        AST *tmp2 = (AST *)malloc(sizeof(AST));
        tmp1 = make_num_ast(0);
        tmp2 = make_id_ast(oprnd->id);
        ast = make_binop_ast(Sub, tmp1, tmp2);
    }*/

    // printf("Unimplemented: make_neg_ast()\n");
    return ast;
}

// TODO: Fill in
int eval_ast(VarNode *vars, AST *ast)
{
    AST *tmpast = (AST *)malloc(sizeof(AST));
    VarNode *tmpvar = (VarNode *)malloc(sizeof(VarNode));
    int a = 0, b = 0;
    if (ast->left != NULL)
    {
        if (ast->left->kind == Identifier)
            a = lookup_var(vars, ast->left->id);
        else if (ast->left->kind == Number)
            a = ast->left->num;
        else
        {
            a = eval_ast(vars, ast->left);
            ast->left->num = a;
        }
    }
    if (ast->right != NULL)
    {
        if (ast->right->kind == Identifier)
            b = lookup_var(vars, ast->right->id);
        else if (ast->right->kind == Number)
            b = ast->right->num;
        else
        {
            b = eval_ast(vars, ast->right);
            ast->right->num = b;
        }
    }
    switch (ast->kind)
    {
    case Add:
        return a + b;
    case Sub:
        return a - b;
    case Mul:
        return a * b;
    case Div:
        return a / b;
    case Neg:
        ast->kind = Number;
        ast->num = -1 * a;
        return (-1) * a;
    }
    // printf("Unimplemented: eval_ast()\n");
}

void free_ast(AST *ast)
{
    switch (ast->kind)
    {
    case Number:
        break;
    case Identifier:
        free(ast->id);
        break;
    case Add:
    case Sub:
    case Mul:
    case Div:
        free_ast(ast->left);
        free_ast(ast->right);
        break;
    case Neg:
        free_ast(ast->left);
        break;
    }
    free(ast);
}
