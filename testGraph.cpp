#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    Graph test;
    test.readFileMatrix("input1.txt");
    test.displayMatrix();

    Graph test2;
    test2.readFileMatrix("input1.txt");
    test2.displayMatrix();
    return 0;
}
