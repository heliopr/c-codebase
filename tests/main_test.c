#include <stdio.h>


void testArray();

void test(const char *name, void (*testFun)()) {
    printf("TEST %s\n", name);
    (*testFun)();
    printf("TEST %s passed\n\n", name);
}

int main() {
    test("Array", testArray);
    printf("All tests passed\n");
}