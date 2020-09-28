#include <iostream>
#include "sql.h"
#include "btreetest.h"

using namespace std;

int main(int argc, char const* argv[])
{
    SQL sql;
    sql.interative();
//    BPlusTree<int> tree;
//    test_remove(tree);
    cout << endl;
    return 0;
}

