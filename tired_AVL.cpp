// Balanced Binary Search Tree

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left_node;
    struct node *right_node;
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// spartan, what is your profession,
void height_checker(struct node *root)
{

    struct node *present_left_node;
    struct node *present_right_node;
    if (root == NULL)
    {
        cout << "Empty Tree, Exiting...";
        return;
    }


    int left_count = 0;
    int right_count = 0;

    // for traversal towards left most path
    present_left_node = root;

    while (present_left_node->left_node != NULL)
    {
        present_left_node = present_left_node->left_node;

        left_count++;
        if (present_left_node->left_node == NULL)
        {
            cout << "\nLEFT of Left Path is NULL at level " << left_count << " ." << endl;
        }
        if (present_left_node->right_node == NULL)
        {
            cout << "\nRIGHT of Left Path is NULL at level " << left_count << " ." << endl;
        }

        // to checking heriachal left of right subtrees
        if (present_left_node->right_node != NULL)
        {
            struct node *temp = present_left_node->right_node;

            // while (temp->left_node != NULL)
            // {
            //     temp = temp->left_node;

            // left_count++;
            if (temp->left_node == NULL)
            {
                cout << "\nLEFT of inner Right Parent of LEFT Path is NULL at level " << left_count << " ." << endl;
            }
            if (temp->right_node == NULL)
            {
                cout << "\nRIGHT of inner Right Parent of LEFT Path is NULL at level " << left_count << " ." << endl;
            }
        }
    }

    // for traversal towards right most path
    present_right_node = root;

    while (present_right_node->right_node != NULL)
    {
        present_right_node = present_right_node->right_node;

        right_count++;
        if (present_right_node->right_node == NULL)
        {
            cout << "\nRIGHT of Right Path is NULL at level " << right_count << " ." << endl;
        }
        if (present_right_node->left_node == NULL)
        {
            cout << "\nLEFT of Right Path is NULL at level " << right_count << " ." << endl;
        }

        // to checking heriachal right of left subtrees
        if (present_right_node->left_node != NULL)
        {
            struct node *temp = present_right_node->left_node;

            
            if (temp->left_node == NULL)
            {
                cout << "\nLEFT of inner Left Parent of Right Path is NULL at level " << right_count << " ." << endl;
            }
            if (temp->right_node == NULL)
            {
                cout << "\nRIGHT of inner Left Parent of Right Path is NULL at level " << right_count << " ." << endl;
            }
        }
    }

    cout << "\nLeft most height is " << left_count << endl;
    cout << "\nRight most height is " << right_count << endl;
}

struct node *insert(struct node *root, int value)
{

    // Base case for Recusrion.

    if (root == NULL)
    { // Checking if it is a DISTINGUISHED Node.
        struct node *new_node = new struct node;
        new_node->data = value;      // Assigning Value to it.
        new_node->left_node = NULL;  // Assigning Left to NULL.
        new_node->right_node = NULL; // Assigning Right to NULL.
        return new_node;
    }

    // if equal value to any previous node's value, it gets ignored.

    if (value < root->data)
    {
        root->left_node = insert(root->left_node, value); // Recalling the Function again for every Left Value(Recursive Calling)
    }
    else if (value > root->data)
    {
        root->right_node = insert(root->right_node, value); // Recalling the Function again for every Right Value(Recursive Calling)
    }
    else if(value == root->data){
         root->right_node = insert(root->right_node, value);
    }

    return root;
}

void pre_order_display(struct node *root, int data)
{ // Root,Left,Right
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " "; // root node data
    pre_order_display(root->left_node, root->left_node->data);
    pre_order_display(root->right_node, root->right_node->data);
}

void in_order_display(struct node *root)
{ // Left,Root,Right
    if (root == nullptr)
    {
        return;
    }
    in_order_display(root->left_node);
    cout << root->data << " "; // root node data
    in_order_display(root->right_node);
}

void post_order_display(struct node *root)
{ // Left,Right,Root
    if (root == nullptr)
    {
        return;
    }
    post_order_display(root->left_node);
    post_order_display(root->right_node);
    cout << root->data << " "; // root node data
}

int main()
{
    struct node *root = NULL;

    int choice;
    do
    {
        cout << "\nEnter your choice:\n1. Insert into Binary Search Tree\n2. Pre-Order Display\n3. In-Order Display\n4. Post-Order Display\n5. Clear Screen\n6. Check Height\n0. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "To Stop Inserting(enter -1): "; // Until User Does'nt Enter -1

        M:
            int value;
            cout << "\nEnter value to insert: ";
            cin >> value;

            while (value != -1)
            {

                root = insert(root, value);
                goto M;
            }

            break;

        case 2:
            cout << "\nPre-Order Display: ";
            int c;

            pre_order_display(root, root->data);
            cout << endl;
            break;

        case 3:
            cout << "\nIn-Order Display: ";
            in_order_display(root);
            cout << endl;
            break;

        case 4:
            cout << "\nPost-Order Display: ";
            post_order_display(root);
            cout << endl;
            break;

        case 5:

            system("CLS");
            break;

        case 6:

            height_checker(root);
            break;

        case 0:
            cout << "\nExiting program.\n";
            break;

        default:
            cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
