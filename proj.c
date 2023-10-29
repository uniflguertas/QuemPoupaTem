#include <stdio.h>
#include "proj.h"
#include "string.h"

void limpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
};
