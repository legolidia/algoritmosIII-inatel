#include <iostream>
#include <list>
using namespace std;

struct node
{
    int info;
    node *left;
    node *right;
};

void insert(node *&curr, int new_info)
{
    if (curr == NULL)
    {
        curr = new node;
        curr->info = new_info;
        curr->left = NULL;
        curr->right = NULL;
    }
    else
    {
        if (new_info < curr->info)
        {
            insert(curr->left, new_info);
        }
        else
        {
            insert(curr->right, new_info);
        }
    }
}

void pre_order(node *curr, int x, int *cont, bool *found)
{
    if (curr != NULL && !(*found))
    {
        (*cont)++;
        if (curr->info == x)
        {
            *found = true;
        }
        pre_order(curr->left, x, cont, found);
        pre_order(curr->right, x, cont, found);
    }
}

void pos_order(node *curr, int x, int *cont, bool *found)
{
    if (curr != NULL)
    {
        pos_order(curr->left, x, cont, found);
        pos_order(curr->right, x, cont, found);

        if (!(*found))
        {
            (*cont)++;
            if (curr->info == x)
            {
                *found = true;
            }
        }
    }
}

void in_order_asc(node *curr, int x, int *cont, bool *found)
{
    if (curr != NULL && !(*found))
    {
        in_order_asc(curr->left, x, cont, found);
        if (!(*found))
        {
            (*cont)++;
            if (curr->info == x)
            {
                *found = true;
                return; // Pare a execução ao encontrar o nó
            }
        }
        in_order_asc(curr->right, x, cont, found);
    }
}

int main()
{
    node *root = NULL;

    int n;
    cin >> n;
    while (n != -1)
    {
        insert(root, n);
        cin >> n;
    }

    int x;
    cin >> x;

    int c1 = 0, c2 = 0, c3 = 0;

    // Pre-order
    bool found = false;
    pre_order(root, x, &c1, &found);

    // Reset for in-order
    found = false;
    c2 = 0; // Reset counter
    in_order_asc(root, x, &c2, &found);

    // Reset for post-order
    found = false;
    c3 = 0; // Reset counter
    pos_order(root, x, &c3, &found);

    // Comparando os contadores e imprimindo o nome da melhor ordenação
    if (c1 < c2 && c1 < c3)
    {
        cout << "Pre" << endl; // Pre-order foi o mais rápido
    }
    else if (c2 < c1 && c2 < c3)
    {
        cout << "Em" << endl; // In-order foi o mais rápido
    }
    else
    {
        cout << "Pos" << endl; // Post-order foi o mais rápido
    }

    return 0;
}
