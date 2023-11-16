#include<iostream>
#include<iomanip>
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

void PrintTree(Node *cur, int padding = 0) // RVL princips - 90 gradi
{
  if(cur != NULL)
  {
    PrintTree(cur->right, padding+=5);
    cout << setw(padding) << "[" << cur->data << "]" << endl;
    PrintTree(cur->left, padding);
  }
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

  return 0;
}

Node *FindNode(Node *root, int x)
{
  Node *cur = new Node;
  cur = root;

  while((cur->data > x && cur->left != NULL) || (cur->data <= x && cur->right != NULL) && cur->data != x)
  {
    while(cur->data > x && cur->left != NULL && cur->data != x)
    {
      cur = cur->left;
    }
    while(cur->data <= x && cur->right != NULL && cur->data != x)
    {
      cur = cur->right;
    }
  }

  if(cur->data == x)
  {
    cout << "\nSuccessfully Found! :)\n";
  }
  else
  {
    cur = NULL;
    cout << "\nSorry! There is no your Node! :(\n";
  }

  return cur;
}

Node *FindParent(Node *root, int x)
{
  Node *cur = new Node;
  Node *parent;
  cur = root;

  while((cur->data > x && cur->left != NULL) || (cur->data <= x && cur->right != NULL) && cur->data != x)
  {
    while(cur->data > x && cur->left != NULL && cur->data != x)
    {
      parent = cur;
      cur = cur->left;
    }
    while(cur->data <= x && cur->right != NULL && cur->data != x)
    {
      parent = cur;
      cur = cur->right;
    }
  }

  if(root->data == x || cur->data != x)
  {
    parent = NULL;
  }

  return parent;
}

int NodesCount(Node *cur)
{
  if(cur != NULL)
  {
    return 1 + NodesCount(cur->left) + NodesCount(cur->right);
  }
  else return 0;
}

Node *SwapTree(Node *cur)
{
  Node *temp1 = NULL;
  Node *temp2 = NULL;

  if(cur != NULL)
  {
    temp1 = SwapTree(cur->left);
    temp2 = SwapTree(cur->right);
    cur->right = temp1;
    cur->left = temp2;
  }
  return cur;
}

Node *RemoveNode(Node *root)
{
  Node *x, *y, *temp;

  int value;
  cout << "Enter which Node need to remove: ";
  cin >> value;
  x = FindNode(root, value);

  if(x != NULL)
  {
    // Node who is a root
    if(x == root)
    {
      // root who has no children
      if(x->left == NULL && x->right == NULL)
      {
        delete root;
        cout << "\nTree was fully removed!" << endl;
        return NULL;
      }
      // root who has only right child
      if(x->left == NULL)
      {
        root = x->right;
        delete x;
        cout << "\nRoot was successfully removed!" << endl;
        return root;
      }
      // root who has only left child
      if(x->right == NULL)
      {
        root = x->left;
        delete x;
        cout << "\nRoot was successfully removed!" << endl;
        return root;
      }
      // two children
      temp = x->left;
      y = x->right;
      root = temp;
      while(temp->right != NULL) temp = temp->right;
      temp->right = y;
      delete x;
      cout << "\nRoot was successfully removed!" << endl;
      return root;
    }

    y = FindParent(root, value);

    // Node who has no children
    if(x->left == NULL && x->right == NULL && x != root)
    {
      if(y->left == x) y->left = NULL;
      else y->right = NULL;
      delete x;
    }

    // Node who has 1 child
    if(x->left == NULL && x->right != NULL && x != root)
    {
      if(y->left == x) y->left = x->right;
      else y->right = x->right;
      x->right = NULL;
      delete x;
    }
    if(x->left != NULL && x->right == NULL && x != root)
    {
      if(y->left == x) y->left = x->left;
      else y->right = x->left;
      x->left = NULL;
      delete x;
    }

    // Node who has 2 children
    if(x->left != NULL && x->right != NULL && x != root)
    {
      if(y->left == x)
      {
        temp = x->left;
        y->left = x->left;
        while(temp->right != NULL) temp = temp->right;
        temp->right = x->right;
        x->left = NULL;
        x->right = NULL;
      }
      else
      {
        temp = x->right;
        y->right = x->right;
        while(temp->left != NULL) temp = temp->left;
        temp->left = x->left;
        x->left = NULL;
        x->right = NULL;
      }
      delete x;
    }
    cout << "\nNode was successfully removed!" << endl;
  }
  return root;
}

int main()
{
  Node *root = NULL;
  enum KEYS { num1 = 49, num2 = 50, num3 = 51 , num4 = 52, num5 = 53, num6 = 54, num7 = 55, num8 = 56, num9 = 57, num10 = 45, num11 = 61, num12 = 112 };
  /*
  num10 = 45; it is   -
  num11 = 61; it is   =
  num12 = 112; it is  p
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
      cout << "\n--------------- ADD ----------------\n";
      cout << "2. Add Node\n";
      cout << "\n-------------- PRINT  --------------\n";
      cout << "3. Print Root value\n";
      cout << "4. Print Tree\n";
      cout << "5. Print PreOrder (VLR)\n";
      cout << "6. Print InOrder (LVR)\n";
      cout << "7. Print PostOrder (LRV)\n";
      cout << "\n--------------- FIND ---------------\n";
      cout << "8. Find Node\n";
      cout << "\n-------------- REMOVE --------------\n";
      cout << "9. Remove Node\n";
      cout << "\n--------- COUNT & TURNING ----------\n";
      cout << "10. Count How many Nodes (-)\n";
      cout << "11. Swap Tree (=)\n";
      cout << "\n-------------- STOP --------------\n";
      cout << "12. Stop Program (p)\n\n";
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
        case num2: // add node
        {
          if(root)
          {
            AddNode(root);
          }
          else cout << "Tree does not exists!\n";
          break;
        }
        case num3:
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
        case num4:
        {
          if(root)
          {
            cout << "Tree elements:\n\n";
            PrintTree(root);
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num5:
        {
          if(root)
          {
            cout << "Tree elements (VLR):\n";
            PreOrder(root);
          }
          else cout << "Tree does not exists!\n";
          break;
        }
        case num6:
        {
          if(root)
          {
            cout << "Tree elements (LVR):\n";
            InOrder(root);
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num7:
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
        case num8: // find
        {
          if(root)
          {
            int x;
            cout << "Enter which Node need to find: ";
            cin >> x;
            FindNode(root, x);
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num9: // remove
        {
          if(root)
          {
            root = RemoveNode(root);
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num10: // count
        {
          if(root)
          {
            int count = NodesCount(root);
            cout << "There is " << count << " Node/s in the tree!\n";
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num11: // swap
        {
          if(root)
          {
            SwapTree(root);
            cout << "Tree has been swapped!" << endl;
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num12:
        {
          cout << "\nProgram is stopped! Goodbye!"; ProgEnd(); break;
        }
        default: cout << "Incorrect input!\n";
      }
    } while(choice != num12);

  system("pause>nul");
  return 0;
}
