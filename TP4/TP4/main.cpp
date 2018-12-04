#include <iostream>
#include "cnode.hpp"
#include "crdtree.h"

using namespace std;

void treeTest(){
    CRDTree<int> arbreTest(7);
    arbreTest.Add(14);
    arbreTest.Add(5);
    arbreTest.Add(47);
    arbreTest.Add(6);
    arbreTest.Add(20);
    arbreTest.Add(3);
    arbreTest.Show();

    if (arbreTest.Find(15) == true) cout<<"oui"<<endl;
    else if (arbreTest.Find(15) == false) cout<<"non"<<endl;
}

int main(int argc, char *argv[])
{
    treeTest();
    return 0;
}
