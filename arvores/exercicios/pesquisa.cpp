#include <iostream>
using namespace std;

struct treenode
{
    int info;
    struct treenode *left;
    struct treenode *right;
};

// Definindo o tipo treenodeptr como um ponteiro para treenode
typedef treenode *treenodeptr;

void tInsert(treenodeptr &p, int x)
{
    if (p == NULL)
    {
        p = new treenode;
        p->info = x;
        p->left = NULL;
        p->right = NULL;
    }
    else if (x < p->info)
    {
        tInsert(p->left, x);
    }
    else
    {
        tInsert(p->right, x);
    }
}

treenodeptr tSearch(treenodeptr p, int x)
{
    if (p == NULL)
    {
        return NULL;
    }
    else if (x == p->info)
    {
        return p;
    }
    else if (x < p->info)
    {
        return tSearch(p->left, x);
    }
    else
    {
        return tSearch(p->right, x);
    }
}

treenodeptr tPointSmaller(treenodeptr &p)
{
    treenodeptr t = p;
    if (p->left == NULL)
    {
        p = p->right;
        return t;
    }
    else
    {
        return tPointSmaller(p->left);
    }
}

bool tRemove(treenodeptr &p, int x)
{
    treenodeptr t;
    if (p == NULL)
    {
        return false;
    }
    if (x == p->info)
    {
        t = p;
        if (p->left == NULL)
        {
            p = p->right;
        }
        else if (p->right == NULL)
        {
            p = p->left;
        }
        else
        {
            t = tPointSmaller(p->right);
            p->info = t->info;
        }
        delete t;
        return true;
    }
    else if (x < p->info)
    {
        return tRemove(p->left, x);
    }
    else
    {
        return tRemove(p->right, x);
    }
}

int main()
{
    int num, n;
    cin >> num;

    treenodeptr root = NULL;

    for (int i = 0; i < num; i++)
    {
        cin >> n;
        tInsert(root, n);
    }

    int x;
    cin >> x;

    (tSearch(root, x)) ? cout << "Encontrado" << endl : cout << "Nao encontrado" << endl;

    return 0;
}
