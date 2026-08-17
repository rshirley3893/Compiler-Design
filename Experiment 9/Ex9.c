#include <stdio.h>
#include <string.h>
#include <ctype.h>

char code[100][100];

int main()
{
    FILE *fp;
    int i = 0;

    printf("Enter Three Address Code:\n");
    printf("Press Ctrl+D after entering all lines.\n");

    fp = fopen("infile.txt", "w");

    char ch;

    while ((ch = getchar()) != EOF)
    {
        fputc(ch, fp);
    }

    fclose(fp);

    fp = fopen("infile.txt", "r");

    printf("\nUnoptimized Code:\n");

    while (fgets(code[i], sizeof(code[i]), fp))
    {
        printf("%s", code[i]);
        i++;
    }

    fclose(fp);

    int lines = i;

    printf("\nOptimized Code:\n");

    for (i = 0; i < lines; i++)
    {
        char lhs, op1, op2, opr;
        int val1, val2, res;

        if (sscanf(code[i], "%c=%c%c%c;", &lhs, &op1, &opr, &op2) == 4)
        {
            if (isdigit(op1) && isdigit(op2))
            {
                val1 = op1 - '0';
                val2 = op2 - '0';

                switch (opr)
                {
                    case '+':
                        res = val1 + val2;
                        break;

                    case '-':
                        res = val1 - val2;
                        break;

                    case '*':
                        res = val1 * val2;
                        break;

                    case '/':
                        res = val2 != 0 ? val1 / val2 : 0;
                        break;

                    default:
                        res = 0;
                }

                printf("%c=%d;\t// Constant Folding\n", lhs, res);
            }
            else if ((opr == '*' && op2 == '1') ||
                     (opr == '/' && op2 == '1'))
            {
                printf("%c=%c;\t// Algebraic Simplification\n",
                       lhs, op1);
            }
            else if (opr == '*' && op2 == '2')
            {
                printf("%c=%c+%c;\t// Strength Reduction\n",
                       lhs, op1, op1);
            }
            else
            {
                printf("%s", code[i]);
            }
        }
        else
        {
            printf("%s", code[i]);
        }
    }

    return 0;
}