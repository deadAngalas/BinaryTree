#include<iostream>
#include<cstdlib>
#include<conio.h>
#define N 100

using namespace std;

void ProgEnd()
{
  system("cls");
  cout << "\n\n\t\t\tCLOSING...\n\n";
  cout <<"              ,---------------------------," << endl;
  cout <<"              |  ---------------------  |"<< endl;
  cout <<"              | |                       | |"<< endl;
  cout <<"              | |     Binary            | |"<< endl;
  cout <<"              | |         Search        | |"<< endl;
  cout <<"              | |              Tree     | |"<< endl;
  cout <<"              | |                       | |"<< endl;
  cout <<"              |  _____________________  |"<< endl;
  cout <<"              |___________________________|"<< endl;
  cout <<"            ,---_____     []     _______------,"<< endl;
  cout <<"            |      ______________           |"<< endl;
  cout <<"        ___________________________________   | ___"<< endl;
  cout <<"        |                                   |   |    )"<< endl;
  cout <<"        |  _ _ _                 [-------]  |   |   ("<< endl;
  cout <<"        |  o o o                 [-------]  |      _)_"<< endl;
  cout <<"        |__________________________________ |       "<< endl;
  cout <<"    -------------------------------------|      ( )"<< endl;
  cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  cout << endl;
}

struct Node
{
  int data;
  Node *left, *right;
};

Node *CreateNode()
{
  Node *newNode;
  newNode = new Node;
  cout << "\nEnter number to node: ";
  cin >> newNode->data;

  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

void PrintTree(Node *cur)
{
  // LVR (left vertex right)
  if(!cur) return;
  PrintTree(cur->left); // output left
  cout << cur->data << " ";
  PrintTree(cur->right);
}

Node *AddNode(Node *root)
{
  //create node
  Node *newNode, *cur;
  newNode = CreateNode();

  //loop
  cur = root;

  while(cur->left != NULL && cur->right != NULL) // big loop
  {
    while(newNode->data < cur->data || cur->left != NULL) // for left branch
    {
      cur = cur->left;
    }
    while(newNode->data >= cur->data || cur->right != NULL) // for right branch
    {
      cur = cur->right;
    }
  }
  // add node in the tree
  if(newNode->data < cur->data && cur->left == NULL) // cur->left == NULL
  {
    cur->left = newNode;
  }
  else if(newNode->data >= cur->data && cur->right == NULL) // cur->right == NULL
  {
    cur->right = newNode;
  }
  return 0;
}

int main()
{
  Node *root = NULL;
  enum KEYS { num1 = 49, num2 = 50, num3 = 51 , num4 = 52, num5 = 53, num6 = 54, num7 = 55, num8 = 56, num9 = 57, num10 = 45, num11 = 61, num12 = 112, num13 = 91, num14 = 93 };
  /*
  num10 = 45; it is   -
  num11 = 61; it is   =
  num12 = 112; it is  p
  num13 = 91; it is   [
  num14 = 93; it is   ]
  */
  int choice;

  system("cls");
  cout << "\n\t\tBinary Search Tree\n\n";
  cout << "\n Author: Vladislav Ryazancev\n Ver: 1.2.7\n Date (start): 18.10.2023 / 14:28\n Date (end): 11.10.2023 / 16:13\n\n";

  do
    {
      system("pause>nul");
      system("cls");

      cout << "\n What do you want to do: \n\n";
      cout << "1. Create root\n";
      cout << "2. Print root value\n";
      cout << "3. Print Tree\n";
      cout << "4. Add node\n";
      cout << "5. \n";
      cout << "6. \n";
      cout << "7. \n";
      cout << "8. \n";
      cout << "9. \n";
      cout << "10.  (-)\n";
      cout << "11.  (=)\n";
      cout << "12.  (p)\n";
      cout << "13.  ([)\n";
      cout << "14.  (])\n\n";

      choice = getch();

      switch(choice)
      {
        case num1: // create root
        {
          if(!root)
          {
            root = CreateNode();
          }
          else cout << "Root already exist!\n";
          break;
        }
        case num2:// print root value
        {
          if(root)
          {
            cout << "Root data: " << root->data << endl;
            cout << "Root left pointer: " << root->left << endl;
            cout << "Root right pointer: " << root->right << endl;
          }
          else cout << "Root does not exists! Create Root!\n";
          system("pause>nul");
          break;
        }
        case num3: // print tree
        {
          if(root)
          {
            PrintTree(root);
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num4: // add node
        {
          if(root)
          {
            AddNode(root);
          }
          else cout << "Tree does not exists!\n";
          break;
        }
        case num5:
        {

          system("pause>nul");
          break;
        }
        case num6:
        {

          system("pause>nul");
          break;
        }
        case num7:
        {

          system("pause>nul");
          break;
        }
        case num8:
        {

          system("pause>nul");
          break;
        }
        case num9:
        {

          system("pause>nul");
          break;
        }
        case num10:
        {

          system("pause>nul");
          break;
        }
        case num11:
        {

          system("pause>nul");
          break;
        }
        case num12:
        {

          system("pause>nul");
          break;
        }
        case num13:
        {
          system("pause>nul");
          break;
        }
        case num14: cout << "\nProgram is stopped! Goodbye!"; ProgEnd(); break;
        default: cout << "Incorrect input!\n";
      }
    } while(choice != num14);

  system("pause>nul");
  return 0;
}
