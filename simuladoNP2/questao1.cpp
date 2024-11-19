#include <iostream>

using namespace std;

// dois tipos predefinidos de chave e valor | torta: preço (int)
typedef int KeyType;
typedef int ValueType;

// dado dos nós que vão ser adicionados na árvore
struct DataType
{
    KeyType key;
    ValueType value;
};

struct Node
{
    DataType data; // chave e valor
    Node *right;
    Node *left;
};

// nó raiz e chave e valor
void insert(Node *&curr, DataType data)
{
    if (curr == NULL)
    {
        curr = new Node;
        curr->data = data;
        curr->right = NULL;
        curr->left = NULL;
    }
    else
    {
        if (data.key >= curr->data.key)
        {
            insert(curr->right, data);
        }
        else if (data.key < curr->data.key)
        {
            insert(curr->left, data);
        }

        // DEVE SER INSERIDO PELO VALOR
        // if (data.value >= curr->data.value)
        // {
        //     insert(curr->right, data);
        // }
        // else if (data.value < curr->data.value)
        // {
        //     insert(curr->left, data);
        // }

        // se mudar na main a inserção, pode manter a função
    }
}

// correta
Node *search(Node *curr, KeyType key)
{
    if (curr == NULL)
        return NULL;
    if (key == curr->data.key)
    {
        return curr;
    }
    else
    {
        if (key > curr->data.key)
        {
            return search(curr->right, key);
        }
        else if (key < curr->data.key)
        {
            return search(curr->left, key);
        }
    }
    return NULL;
}

// se manter a função anterior, deve-se trocar a ordem de key e value
void show_ordered(Node *curr)
{
    if (curr->left != NULL)
        show_ordered(curr->left);
    // cout << curr->data.key << ":" << curr->data.value << endl;
    cout << curr->data.value << ":" << curr->data.key << endl;
    if (curr->right != NULL)
        show_ordered(curr->right);
}

Node *disconnect_lesser(Node *&curr)
{
    Node *aux = curr;
    if (aux->left == NULL)
    {
        curr = curr->right;
        return aux;
    }
    else
    {
        return disconnect_lesser(curr->left);
    }
}

int remove(Node *&curr, KeyType old_key)
{
    if (curr == NULL)
    {
        return 0;
    }
    Node *aux;
    if (curr->data.key == old_key)
    {
        aux = curr;
        if (curr->left == NULL)
        {
            curr = aux->right;
        }
        else if (curr->right == NULL)
        {
            curr = aux->left;
        }
        else
        {
            aux = disconnect_lesser(curr->right);
            curr->data = aux->data;
        }
        delete aux;
        return 1;
    }
    else
    {
        if (old_key > curr->data.key)
        {
            return remove(curr->right, old_key);
        }
        else if (old_key < curr->data.key)
        {
            return remove(curr->left, old_key);
        }
    }
    return 0;
}

void destruct(Node *&curr)
{
    if (curr->left != NULL)
        destruct(curr->left);
    if (curr->right != NULL)
        destruct(curr->right);
    delete curr;
    curr = NULL;
    return;
}

int main()
{
    Node *root = NULL;
    DataType aux;

    int t, pf;
    float em, p, a, d;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> em >> p >> a >> d;
        pf = em * p * a + d + a;

        aux.key = pf;
        aux.value = i;

        insert(root, aux);
    }

    show_ordered(root);

    return 0;
}