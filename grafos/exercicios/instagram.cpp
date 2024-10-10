#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    int n;
    int x;

    cin >> n;

    string usuarios[n];
    string nome;

    list<int> seguidores[n];
    list<int>::iterator it;

    int segue;

    cin.ignore();
    for (int i = 0; i < n; i++)
    {

        getline(cin, nome);
        usuarios[i] = nome;
    }

    for (int i = 0; i < n; i++)
    {

        cin >> segue;
        while (segue != -1)
        {
            seguidores[segue].push_back(i);
            cin >> segue;
        }
    }

    cin >> x;

    for (it = seguidores[x].begin(); it != seguidores[x].end(); it++)
    {
        cout << usuarios[*it] << endl;
    }

    return 0;
}