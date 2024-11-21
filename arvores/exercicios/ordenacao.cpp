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

node *search(node *curr, int x)
{
    if (curr == NULL)
    {
        return NULL;
    }
    else if (x == curr->info)
    {
        return curr;
    }
    else if (x < curr->info)
    {
        return search(curr->left, x);
    }
    else
    {
        return search(curr->right, x);
    }
}

node *point_smaller(node *&curr)
{
    node *aux = curr;
    if (curr->left == NULL)
    {
        curr = curr->right;
        return aux;
    }
    else
    {
        return point_smaller(curr->left);
    }
}

bool remove(node *&curr, int x)
{
    node *aux;
    if (curr == NULL)
    {
        return false;
    }
    if (x == curr->info)
    {
        aux = curr;
        if (curr->left == NULL)
        {
            curr = curr->right;
        }
        else if (curr->right == NULL)
        {
            curr = curr->left;
        }
        else
        {
            aux = point_smaller(curr->right);
            curr->info = aux->info;
        }
        delete aux;
        return true;
    }
    else if (x < curr->info)
    {
        return remove(curr->left, x);
    }
    else
    {
        return remove(curr->right, x);
    }
}

// profundidade

void pre_order(node *curr)
{
    if (curr != NULL)
    {
        cout << curr->info << endl;
        pre_order(curr->left);
        pre_order(curr->right);
    }
}

void pos_order(node *curr)
{
    if (curr != NULL)
    {
        pos_order(curr->left);
        pos_order(curr->right);
        cout << curr->info << endl;
    }
}

void destruct(node *&curr)
{
    if (curr != NULL)
    {
        destruct(curr->left);
        destruct(curr->right);
        delete curr;
        curr = NULL;
    }
}

void in_order_asc(node *curr)
{
    if (curr != NULL)
    {
        in_order_asc(curr->left);
        cout << curr->info << endl;
        in_order_asc(curr->right);
    }
}

void in_order_desc(node *curr)
{
    if (curr != NULL)
    {
        in_order_desc(curr->right);
        cout << curr->info << " ";
        in_order_desc(curr->left);
    }
}

// largura

void in_level(node *curr)
{
    list<node *> visit_queue;
    if (curr != NULL)
    {
        visit_queue.push_back(curr);
        while (!visit_queue.empty())
        {
            node *aux = visit_queue.front();
            visit_queue.pop_front();
            if (aux->left != NULL)
            {
                visit_queue.push_back(aux->left);
            }
            if (aux->right != NULL)
            {
                visit_queue.push_back(aux->right);
            }

            cout << aux->info << endl;
        }
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

    in_order_desc(root);

    return 0;
}
