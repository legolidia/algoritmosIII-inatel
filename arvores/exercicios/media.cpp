#include <iostream>
#include <list>
#include <iomanip>
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

void soma_e_conta(node *curr, int &soma, int &conta)
{
    if (curr != NULL)
    {
        soma += curr->info;                     // Soma o valor do nó atual
        conta++;                                // Incrementa a contagem de nós
        soma_e_conta(curr->left, soma, conta);  // Percorre a subárvore esquerda
        soma_e_conta(curr->right, soma, conta); // Percorre a subárvore direita
    }
}

float media(node *curr)
{
    if (curr == NULL)
    {
        return 0.0; // Retorna 0 para árvore vazia
    }

    int soma = 0, conta = 0;
    soma_e_conta(curr, soma, conta); // Calcula soma e quantidade de nós
    return soma / (conta * 1.0);
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

    cout << fixed << setprecision(2);
    cout << "Media: " << media(root) << endl;

    cout << endl;

    return 0;
}
