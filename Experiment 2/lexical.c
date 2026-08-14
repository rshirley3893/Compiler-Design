#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *key[]={"int","float","char","double","void","for","if","else","return","while","do"};
char *head[]={"stdio.h","string.h","ctype.h","conio.h"};

int main()
{
    FILE *f;
    char s[50],c;
    int i,n;

    printf("Enter file: ");
    scanf("%s",s);
    f=fopen(s,"r");

    if(!f) {
        printf("File not found");
        return 0;
    }

    while((c=fgetc(f))!=EOF)
    {
        if(c=='/')
        {
            char x=fgetc(f);
            if(x=='/')
                while((c=fgetc(f))!='\n' && c!=EOF);
            else if(x=='*')
                while((c=fgetc(f))!=EOF && !(c=='*'&&fgetc(f)=='/'));
            else {
                printf("Operator: /\n");
                ungetc(x,f);
            }
        }
        else if(isalpha(c))
        {
            i=0;
            do {
                s[i++]=c;
                c=fgetc(f);
            } while(isalnum(c)||c=='.'||c=='_');

            s[i]=0;
            ungetc(c,f);

            for(n=0;n<11;n++)
                if(!strcmp(s,key[n])) break;

            if(n<11) printf("Keyword: %s\n",s);
            else {
                for(n=0;n<4;n++)
                    if(!strcmp(s,head[n])) break;
                printf(n<4 ? "Header: %s\n" : "Identifier: %s\n",s);
            }
        }
        else if(isdigit(c))
        {
            i=0;
            do {
                s[i++]=c;
                c=fgetc(f);
            } while(isdigit(c)||c=='.');

            s[i]=0;
            ungetc(c,f);
            printf("Number: %s\n",s);
        }
        else if(strchr("+-*/%=!",c))
            printf("Operator: %c\n",c);

        else if(strchr(",;(){}[]<>",c))
            printf("Delimiter: %c\n",c);
    }

    fclose(f);
    return 0;
}