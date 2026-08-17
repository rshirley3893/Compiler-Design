#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generateAssembly(char line[])
{
    char result[10], op1[10], op2[10], operator;
    int matched;

    matched = sscanf(line, "%s = %s %c %s",
                     result, op1, &operator, op2);

    if (matched == 4)
    {
        printf("MOV AX, %s\n", op1);

        switch (operator)
        {
            case '+':
                printf("ADD AX, %s\n", op2);
                break;

            case '-':
                printf("SUB AX, %s\n", op2);
                break;

            case '*':
                printf("MUL %s\n", op2);
                break;

            case '/':
                printf("MOV DX, 0\n");
                printf("MOV BX, %s\n", op2);
                printf("DIV BX\n");
                break;
        }

        printf("MOV %s, AX\n", result);
    }
    else
    {
        sscanf(line, "%s = %s", result, op1);

        printf("MOV AX, %s\n", op1);
        printf("MOV %s, AX\n", result);
    }

    printf("\n");
}

int main()
{
    char tac[100][100];
    int n, i;

    printf("Enter number of three-address code lines: ");
    scanf("%d", &n);

    getchar();

    printf("Enter the three-address code:\n");

    for (i = 0; i < n; i++)
    {
        fgets(tac[i], sizeof(tac[i]), stdin);
        tac[i][strcspn(tac[i], "\n")] = '\0';
    }

    printf("\nGenerated 8086 Assembly Code:\n\n");

    for (i = 0; i < n; i++)
    {
        generateAssembly(tac[i]);
    }

    return 0;
}