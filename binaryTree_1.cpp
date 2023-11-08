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

// preorder; VLR
// inorder; LVR
// postorder; LRV

void PreOrder(Node *p) // VLR
{
  if(p != NULL)
  {
    cout << p->data << " ";
    PreOrder(p->left);
    PreOrder(p->right);
  }
}

void InOrder(Node *p) // LVR
{
  if(p != NULL)
  {
    InOrder(p->left);
    cout << p->data << " ";
    InOrder(p->right);
  }
}

void PostOrder(Node *p) // LRV
{
  if(p != NULL)
  {
    PostOrder(p->left);
    PostOrder(p->right);
    cout << p->data << " ";
  }
}

Node *AddNode(Node *root)
{
  //create node
  Node *newNode, *cur;
  newNode = CreateNode();

  cur = root;

  while((cur->data > newNode->data && cur->left != NULL) || (cur->data <= newNode->data && cur->right != NULL))
  {
    while(cur->data > newNode->data && cur->left != NULL)
    {
      cur = cur->left;
    }
    while(cur->data <= newNode->data && cur->right != NULL)
    {
      cur = cur->right;
    }
  }

  if(cur->data > newNode->data && cur->left == NULL)
  {
    cur->left = newNode;
  }
  if(cur->data <= newNode->data && cur->right == NULL)
  {
    cur->right = newNode;
  }

/*
  // for left loop
  if(newNode->data < cur->data)
  {
    while(newNode->data < cur->data && cur->left != NULL) // work until new data is smaller than current data && current left child is something
    {
      cur = cur->left; // go under left child
    }
    // when loop is gone, it means that it is last child and under is nothing -> new if, which again compare datas values to decide which side to add new value
    if(newNode->data >= cur->data) // if new data value is larger or equivallent -> needs to add in right child
    {
      cur->right = newNode;
    }
    else cur->left = newNode; // if smaller than in left child
  }
  // for right loop
  else if(newNode->data >= cur->data)
  {
    if(newNode->data >= cur->data)
    {
      while(newNode->data >= cur->data && cur->right != NULL)
      {
        cur = cur->right; // go under right child
      }
      if(newNode->data < cur->data) // if new data value is smaller -> needs to add in left child
      {
        cur->left = newNode;
      }
      else cur->right = newNode; // if larger than in right child
    }
  }
*/
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
  cout << "\n Author: Vladislav Ryazancev\n Ver: 1.2.7\n Date (start): 18.10.2023 / 14:28\n Date (end): xx.11.2023 / 16:13\n\n";

  do
    {
      system("pause>nul");
      system("cls");

      cout << "\n\t\tMENU \n\n";
      cout << "-------------- CREATE --------------\n";
      cout << "1. Create Root\n";
      cout << "\n-------------- PRINT  --------------\n";
      cout << "2. Print Root value\n";
      cout << "3. Print PreOrder (VLR)\n";
      cout << "4. Print InOrder (LVR)\n";
      cout << "5. Print PostOrder (LRV)\n";
      cout << "\n--------------- ADD ----------------\n";
      cout << "6. Add Node\n";
      cout << "\n-------------- REMOVE --------------\n";
      cout << "7. \n";
      cout << "8. \n";
      cout << "9. \n";
      cout << "10.  (-)\n";
      cout << "11.  (=)\n";
      cout << "12.  (p)\n";
      cout << "13.  ([)\n";
      cout << "\n-------------- STOP --------------\n";
      cout << "14. Stop Program (])\n\n";
      cout << "-----------------------------------\n\n";

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
            cout << "Tree elements (VLR):\n";
            PreOrder(root);
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num4:
        {
          if(root)
          {
            cout << "Tree elements (LVR):\n";
            InOrder(root);
          }
          else cout << "Tree does not exists!\n";
          break;
        }
        case num5:
        {
          if(root)
          {
            cout << "Tree elements (LRV):\n";
            PostOrder(root);
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num6:
        {
          if(root)
          {
            AddNode(root);
          }
          else cout << "Tree does not exists!\n";
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
