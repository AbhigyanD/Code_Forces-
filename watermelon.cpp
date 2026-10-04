#include <stdio.h>

int main() {
    int w;
    scanf("%d", &w); // Read the weight of the watermelon
    printf("%s\n", (w % 2 == 0 && w > 2) ? "YES" : "NO");
    return 0;
}