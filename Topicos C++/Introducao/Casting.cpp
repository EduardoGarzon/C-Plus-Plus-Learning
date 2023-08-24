/*
    Conversores de tipos (casting)
*/

#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
    int intA = 10;
    float floatA = 10.55;

    // Casting em C
    floatA = (float)intA;
    cout << floatA << endl;
    printf("%f\n", floatA);

    floatA = 10.55;
    // Casting em C++, forma de funcao
    intA = int(floatA);
    cout << intA << endl;
    printf("%d\n", intA);

    system("pause");

    return 0;
}