#ifndef BTREETEST_H
#define BTREETEST_H

#include "bptree.h"

template <typename T>
vector<int> test_remove(T& tree)
{
    vector<int> nums;
    for(int i=1; i<200; i++)
    {
        nums.push_back(i);
    }
    for(int i=0; i<nums.size(); i++)
    {
        tree.insert(nums[i]);
    }

    while (true) {
        char input;
        cout << "[T]ree [I]nsert [B]egin [E]nd [D]elete [C]lear  [S]earch  "
                     " e[X]it: ";
        cin >> input;
        switch (tolower(input))
        {

            case 'd':
            {
                int input;
                cin >> input;
               tree.remove(input);

                break;
            }

            case 'i':
            {
                int input;
                cin >> input;
                tree.insert(input);
                break;
            }
            case 'c':
                tree.clear_tree();
                break;
            case 's': {
                int input;
                cin >> input;
                if (tree.search(input) != nullptr)
                    cout << "found" << endl;
                else
                    cout << "not found" << endl;
                break;
            }
            case 'b':
                cout<< "Smallest: " << *(tree.begin()) << endl;
                break;
            case 'e':
                cout << "Largest: " << *(tree.end()) << endl;
                break;

            default:
                cout << "invalid input" << endl;
        }
        cout << tree;

    }
}


#endif // BTREETEST_H
