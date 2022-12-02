#include <stdio.h>
#include <stdlib.h>
#define ll long long

char* decToHex(char *dec) {
    ll decNum = 0;
    for (int i = 0; dec[i] != '\0'; ++i) {
        decNum *= 10;
        decNum += (dec[i] - '0');
    }
    char* hex;
    const char *elements = "0123456789ABCDEF";
    int counter = 0;
    if (!decNum)
        return "0\0";
    ll temp = decNum;
    while (temp) {
        counter++;
        temp /= 16;
    }
    hex = malloc((counter + 1) * sizeof(char));
    hex[counter] = '\0';
    while (decNum) {
        hex[--counter] = elements[decNum % 16];
        decNum /= 16;
    }
    return hex;
}


int main() {
    char str[20];
    printf("Type in any number: \n");
    scanf("%19s", str);
    char *result = decToHex(str);
    printf("%s", result);
    free(result);
}
