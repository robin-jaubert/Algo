#include <iostream>
#include "cnode.hpp"
#include "crdtree.h"

using namespace std;

void treeTest(){
    CRDTree<int> arbreTest(7);
    arbreTest.Add(14);
    arbreTest.Add(5);
    arbreTest.Add(47);
    arbreTest.Add(7);
    arbreTest.Add(20);
    arbreTest.Add(3);
    arbreTest.Show();
}

int main(int argc, char *argv[])
{
    treeTest();
    return 0;
}
