#include <stdio.h>
#include <string.h>

int count = 0;
int i = 0;
int l = 0;

char key[4][12] = {"int", "float", "char", "double"};

char dstr[100][100];
char estr[100][100];

struct table
{
    char var[10];
    char dt[10];
} tbl[20];

void entry(char *declaration);
int check(char[]);
int search(char[]);
void typecheck(char *expression);

int main()
{
    printf("\nIMPLEMENTATION OF TYPE CHECKING\n");

    printf("\nDECLARATIONS (type END to finish):\n");

    while (1)
    {
        printf("\t");

        fgets(dstr[i], sizeof(dstr[i]), stdin);
        dstr[i][strcspn(dstr[i], "\n")] = '\0';

        if (strcmp(dstr[i], "END") == 0)
            break;

        entry(dstr[i]);
        i++;
    }

    printf("\nEXPRESSIONS (type END to finish):\n");

    while (1)
    {
        printf("\t");

        fgets(estr[l], sizeof(estr[l]), stdin);
        estr[l][strcspn(estr[l], "\n")] = '\0';

        if (strcmp(estr[l], "END") == 0)
            break;

        l++;
    }

    printf("\nSEMANTIC ANALYZER (TYPE CHECKING):\n");

    for (i = 0; i < l; i++)
    {
        typecheck(estr[i]);
    }

    return 0;
}

void entry(char *declaration)
{
    char datatype[10];
    char varname[10];

    sscanf(declaration, "%s %[^;];", datatype, varname);

    if (!check(datatype))
    {
        printf("Invalid datatype: %s\n", datatype);
        return;
    }

    if (search(varname) != -1)
    {
        printf("The variable '%s' is already declared\n", varname);
        return;
    }

    strcpy(tbl[count].dt, datatype);
    strcpy(tbl[count].var, varname);

    count++;
}

int check(char t[])
{
    int in;

    for (in = 0; in < 4; in++)
    {
        if (strcmp(key[in], t) == 0)
            return 1;
    }

    return 0;
}

int search(char variable[])
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (strcmp(tbl[i].var, variable) == 0)
            return i;
    }

    return -1;
}

void typecheck(char *expression)
{
    char result[10];
    char op1[10];
    char op2[10];
    char operator;

    sscanf(expression, "%s = %s %c %[^;];",
           result, op1, &operator, op2);

    int rIndex = search(result);
    int o1Index = search(op1);
    int o2Index = search(op2);

    if (rIndex == -1)
    {
        printf("Undefined variable: %s\n", result);
        return;
    }

    if (o1Index == -1)
    {
        printf("Undefined variable: %s\n", op1);
        return;
    }

    if (o2Index == -1)
    {
        printf("Undefined variable: %s\n", op2);
        return;
    }

    if (strcmp(tbl[o1Index].dt, tbl[o2Index].dt) == 0)
    {
        if (strcmp(tbl[rIndex].dt, tbl[o1Index].dt) == 0)
        {
            printf("No type mismatch in expression: %s\n",
                   expression);
        }
        else
        {
            printf("Type mismatch: Lvalue and Rvalue must be same in '%s'\n",
                   expression);
        }
    }
    else
    {
        printf("Type mismatch between operands in '%s'\n",
               expression);
    }
}