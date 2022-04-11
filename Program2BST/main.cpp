#include <iostream>
#include <limits>
#include "BSTree.h"
// #include "test_bst.h"

using namespace std;

void printOrders(BSTree *tree) {
  cout << "Preorder = ";
  tree->preOrder( );
  cout << "Inorder = ";
  tree->inOrder( );
  cout << "Postorder = ";
  tree->postOrder( );
}

int menu() {
  int choice = 0;
  cout << endl << "Enter menu choice: ";
  cout << endl;
  cout 
    << "1. Insert" << endl
    << "2. Remove" << endl
    << "3. Print" << endl
    << "4. Search" << endl
    << "5. Smallest" << endl
    << "6. Largest" << endl
    << "7. Height" << endl
    << "8. Quit" << endl;
  cin >> choice;
  
  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return choice;
}

int main( ) {
    // // Pass all your tests before running the executable main
    // run_tests();  // TODO: Remove before submitting
    // return 0;

    BSTree tree;

    int choice = menu();

    string entry;
  
    while (choice != 8) {
    
        if (choice == 1) {
          cout << "Enter string to insert: ";
          getline(cin, entry);
          cout << endl;
          tree.insert(entry);
          // tree.visualizeTree("exp.dot");
        } else if (choice == 2) {
          cout << "Enter string to remove: ";
          getline(cin, entry);
          cout << endl;
          tree.remove(entry);
          // tree.visualizeTree("exp.dot");
        } else if (choice == 3) {
          cout << "Preorder = ";
          tree.preOrder();
          cout << endl << "Inorder = ";
          tree.inOrder();
          cout << endl << "Postorder = ";
          tree.postOrder();
          cout << endl;
          // tree.visualizeTree("exp.dot");
        } else if (choice == 4) {
          cout << "Enter string to search for: ";
          getline(cin, entry);
          if (tree.search(entry))
          {
            cout << endl << "Found" << endl;
          }
          else
          {
            cout << endl << "Not Found" << endl;
          }
          
        } else if (choice == 5) {
          cout << "Smallest: ";
          cout << tree.smallest() << endl;
        } else if (choice == 6) {
          cout << "Largest: ";
          cout << tree.largest() << endl;
        } else if (choice == 7) {
          cout << "Enter string: ";
          getline(cin, entry);
          cout << endl;
          cout << "Height of subtree rooted at "<< entry << ": " << tree.height(entry) << endl;
        }
        //fix buffer just in case non-numeric choice entered
        choice = menu();
    }
    return 0;
}
/*
1
papa
1
quebec
1
alpha
1
hotel
1
india
1
juliet
1
kilo
1
bravo
1
alpha
1
lima
1
charlie
1
alpha
1
india
1
delta
1
epsilon
1
mike
1
nov
1
oscar
1
foxtrot
1
golf
2
alpha
2
bravo
2
oscar
2
epsilon
2
lima
2
alpha
2
hotel
2
alpha
3
8
*/