#include <iostream>
#include <cstdlib>

using namespace std;

//Julian David Ortiz Molina
//Arbol Binario- Insertar

struct Node {
    int dato;
    Node* right;
    Node* left;
};

void options(Node*& tree);
Node* createNode(int valor);
void insert(Node*& tree, int valor);
void deleteTree(Node* tree);

int main() {
    Node* tree = NULL;
    options(tree);
    deleteTree(tree); 
    return 0;
}

void options(Node*& tree) {
    int dato, lista;

    do {
        cout << "\tOpciones" << endl;
        cout << "1. Insertar un nodo al arbol" << endl;
        cout << "2. Salir" << endl;
        cout << "Opción: ";
        cin >> lista;

        switch (lista) {
            case 1:
                cout << "\nDigite un valor para insertar: ";
                cin >> dato;
                insert(tree, dato);
                cout << "\n";
                break;
        }
        system("pause");
        system("cls");
    } while (lista != 2);
}

Node* createNode(int valor) {
    Node* newNode = new Node();
    newNode->dato = valor;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void insert(Node*& tree, int valor) {
    if (tree == NULL) {
        tree = createNode(valor);
    } else {
        if (valor < tree->dato) {
            insert(tree->left, valor);
        } else {
            insert(tree->right, valor);
        }
    }
}

void deleteTree(Node* tree) {
    if (tree == NULL) return;
    deleteTree(tree->left);
    deleteTree(tree->right);
    delete tree;
}

