#include <stdio.h>  
#include <math.h>
#include <string.h>
int printOption() {
    int option;
    printf("1. Convert binary number to decimal number\n");
    printf("2. Convert octal number to decimal number\n");
    printf("3. Convert hexadecimal number to decimal number\n");
    printf("4. Exit.\n");
    printf("Please choose number (1-4) : ");
    scanf("%d", &option);
    if (option != 1 && option != 2 && option != 3 && option != 4) {
        printf("Re-enter the option !!!\n");
        scanf("%d", &option);
        fflush(stdin);
    }
    return option;
}
int checker(char x) {
    if (x == 48)
        return 0;
    else if (x == 49)
        return 1;
    else if (x == 50)
        return 2;
    else if (x == 51)
        return 3;
    else if (x == 52)
        return 4;
    else if (x == 53)
        return 5;
    else if (x == 54)
        return 6;
    else if (x == 55)
        return 7;
    else if (x == 56)
        return 8;
    else if (x == 57)
        return 9;
    else if (x == 65)
        return 10;
    else if (x == 66)
        return 11;
    else if (x == 67)
        return 12;
    else if (x == 68)
        return 13;
    else if (x == 69)
        return 14;
    else if (x == 70)
        return 15;
    else if (x == 97)
        return 10;
    else if (x == 98)
        return 11;
    else if (x == 99)
        return 12;
    else if (x == 100)
        return 13;
    else if (x == 101)
        return 14;
    else if (x == 102)
        return 15;
    else {
        return -1;
    }
}
 
void binary() {
    char s[200];
    int a[200], i, j, check = 0;
    while (check == 0) {
        check = 1;
        printf("Enter a binary number:");
        fflush(stdin);
        scanf("%s[^\n]s", s);
        for (i = 0; i < strlen(s); i++) {
            a[i] = checker(s[i]);
            if (a[i] == -1) {
                check = 0;
                printf("Re-Enter !!!\n");
                break;
            }
            if (a[i] != 1 && a[i] != 0) {
                printf("Re-Enter !!!\n");
                check = 0;
                break;
            }
        }
    }
    unsigned long long int bi = 0;
    for (j = 0, i = strlen(s) - 1; i >= 0; j++, i--)
        bi = bi + (a[i] * pow(2, j));
    printf("Decimal number is : %llu\n", bi);
}
 
void octal() {
    char s[200];
    int a[200], i, j, check = 0;
    while (check == 0) {
        check = 1;
        printf("Enter a octal number:");
        fflush(stdin);
        scanf("%s[^\n]s", s);
        for (i = 0; i < strlen(s); i++) {
            a[i] = checker(s[i]);
            if (a[i] == -1) {
                printf("Re-Enter !!!\n");
                check = 0;
                break;
            }
            if (a[i] > 7) {
                printf("Re-Enter !!!\n");
                check = 0;
                break;
            }
        }
    }
    long long int oc = 0;
    for (j = 0, i = strlen(s) - 1; i >= 0; j++, i--)
        oc = oc + (a[i] * pow(8, j));
    printf("Decimal number is : %lld\n", oc);
}

void hexa() {
    char c;
    char s[200];
    int a[200], i, j, check = 0, x;
    while (check == 0) {
        check = 1;
        printf("Enter a hexadecimal number:");
        fflush(stdin);
        scanf("%s[^\n]s", &s);
        fflush(stdin);
        for (i = 0; i < strlen(s); i++) {
            a[i] = checker(s[i]);
            if (a[i] == -1) {
                printf("Re-Enter !!!\n");
                check = 0;
                break;
            }
        }
    }
    long int hex = 0;
    for (j = 0, i = strlen(s) - 1; i >= 0; j++, i--)
        hex = hex + (a[i] * pow(16, j));
    printf("Decimal number is : %ld\n", hex);
}

int optionT1(char c) {
    while (1) {
        printf("\nDo you want to continue (Y/N):");
        fflush(stdin);
        char d;
        int k = scanf("%c%c", &c, &d);
        if (k != 2 || d != '\n') {
            printf("Re-Enter the option !\n");
            continue;
        }
        if (c == 'n' || c == 'N') {
            printf("----------------------------------\n");
            return 0;
        }
        if (c != 'n' && c != 'N' && c != 'y' && c != 'Y') {
            printf("Re-Enter the option !\n");
            continue;
        }
        return 1;
    }
}
int main() {
    int option;
    int c;
    int k;
    while (1) {
        option = printOption();
        while (1) {
            if (option == 1) {
                binary();
                k = optionT1(c);
                if (k == 0) {
                    break;
                }
            }
            if (option == 2) {
                octal();
                k = optionT1(c);
                if (k == 0) {
                    break;
                }
            }
            if (option == 3) {
                hexa();
                k = optionT1(c);
                if (k == 0) {
                    break;
                }
            }
            if (option == 4)
                return 0;
        }
    }
    return 0;
}
