#include <stdio.h>
#include "stdlib.h"

int checker(char el) {
    char* types = ",.:;!?";
    for (int i = 0; types[i] != '\0' ; ++i) {
        if (el == types[i]) return 1;
    }
    return 0;
}

char* removeWhitespaces(char* str) {
    char *newstr = calloc(201, sizeof(char));
    int counter = 0;
    int ans = 0;
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; ++i) {
        if (!(str[i] == ' ') || (!checker(str[i + 1])))
            newstr[counter++] = str[i];
        else
            ans++;
    }
    printf("%d\n", ans);
    return newstr;
}

int main() {
    char str[201];
    printf("Type in string: \n");
    fgets(str, 200, stdin);
    char *result = removeWhitespaces(str);
    printf("%s", result);
    free(result);
}
