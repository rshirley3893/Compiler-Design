#include <stdio.h>
#include <string.h>

struct table {
    char var[10];
    int value;
} tbl[20];

int n = 0;

void create() {
    int i;
    printf("Enter number of entries: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter variable and value: ");
        scanf("%s%d", tbl[i].var, &tbl[i].value);
    }
}

void insert() {
    if(n >= 20)
        printf("Table is full\n");
    else {
        printf("Enter variable and value: ");
        scanf("%s%d", tbl[n].var, &tbl[n].value);
        n++;
    }
}

void modify() {
    char v[10];
    int i;

    printf("Enter variable to modify: ");
    scanf("%s", v);

    for(i = 0; i < n; i++) {
        if(strcmp(tbl[i].var, v) == 0) {
            printf("Enter new value: ");
            scanf("%d", &tbl[i].value);
            return;
        }
    }

    printf("Variable not found\n");
}

void search() {
    char v[10];
    int i;

    printf("Enter variable to search: ");
    scanf("%s", v);

    for(i = 0; i < n; i++) {
        if(strcmp(tbl[i].var, v) == 0) {
            printf("Location: %d\nValue: %d\n", i + 1, tbl[i].value);
            return;
        }
    }

    printf("Variable not found\n");
}

void display() {
    int i;

    printf("\nVARIABLE\tVALUE\n");
    for(i = 0; i < n; i++)
        printf("%s\t\t%d\n", tbl[i].var, tbl[i].value);
}

int main() {
    int ch;

    do {
        printf("\n1.Create  2.Insert  3.Modify  4.Search  5.Display  6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: create(); break;
            case 2: insert(); break;
            case 3: modify(); break;
            case 4: search(); break;
            case 5: display(); break;
            case 6: break;
            default: printf("Invalid choice\n");
        }
    } while(ch != 6);

    return 0;
}