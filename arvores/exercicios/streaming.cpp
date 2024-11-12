#include <iostream>
#include <string>

using namespace std;

struct Filme
{
    string nome;
    string genero;
    int duracao;
    int idade;
    int ano;
};

struct treenode
{
    Filme filme;
    struct treenode *left;
    struct treenode *right;
};

typedef treenode *treenodeptr;

void tInsert(treenodeptr &p, Filme filme)
{
    if (p == NULL)
    {
        p = new treenode;
        p->filme = filme;
        p->left = NULL;
        p->right = NULL;
    }
    else if (filme.nome < p->filme.nome)
    {
        tInsert(p->left, filme);
    }
    else
    {
        tInsert(p->right, filme);
    }
}

Filme *tSearch(treenodeptr p, string nome)
{
    if (p == NULL)
    {
        return NULL;
    }
    else if (nome == p->filme.nome)
    {
        return &p->filme;
    }
    else if (nome < p->filme.nome)
    {
        return tSearch(p->left, nome);
    }
    else
    {
        return tSearch(p->right, nome);
    }
}

int main()
{
    treenodeptr root = NULL;
    Filme filme;

    int op;
    cin >> op;
    while (op != 0)
    {
        switch (op)
        {
        case 1:
        {
            cin.ignore();
            getline(cin, filme.nome);
            getline(cin, filme.genero);
            cin >> filme.duracao >> filme.idade >> filme.ano;

            tInsert(root, filme);
            break;
        }
        case 2:
        {
            cin.ignore();

            string nomeBusca;
            getline(cin, nomeBusca);

            Filme *filmeEncontrado = tSearch(root, nomeBusca);
            if (filmeEncontrado != NULL)
            {
                cout << "Nome: " << filmeEncontrado->nome << endl;
                cout << "Genero: " << filmeEncontrado->genero << endl;
                cout << "Duracao: " << filmeEncontrado->duracao << " mins" << endl;
                cout << "Classificacao: " << filmeEncontrado->idade << endl;
                cout << "Ano: " << filmeEncontrado->ano << endl;
            }
            else
            {
                cout << "Filme nao encontrado" << endl;
            }
            break;
        }
        default:
            cout << "Operacao invalida" << endl;
            break;
        }

        cin >> op;
    }

    return 0;
}
