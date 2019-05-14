/*
Nama			: Ahmad Faaiz Al-auza'i
NPM				: 140810180023
Tanggal dibuat	: 15/05/2019 
Deskripsi       : Tree
***********************************************/
#include <iostream>
using namespace std;

struct Simpul
{
    int info;
    Simpul *right;
    Simpul *left;
};

typedef Simpul *pointer;
typedef pointer Tree;

void insertBST(Tree &Root, pointer pBaru)
{
    if (Root == NULL)
        Root = pBaru;
    else if (pBaru->info < Root->info)
        insertBST(Root->left, pBaru);
    else if (pBaru->info > Root->info)
        insertBST(Root->right, pBaru);
    else
        cout << "sudah ada";
}

void CreateSimpul(pointer &pBaru)
{
    pBaru = new Simpul;
    cout << "Masukkan angka : ";
    cin >> pBaru->info;
    pBaru->left = NULL;
    pBaru->right = NULL;
}

void preOrder(Tree Root)
{
    if (Root != NULL)
    {
        cout << Root->info << " ";
        preOrder(Root->left);
        preOrder(Root->right);
    }
}
void inOrder(Tree Root)
{
    if (Root != NULL)
    {
        inOrder(Root->left);
        cout << Root->info << " ";
        inOrder(Root->right);
    }
}
void postOrder(Tree Root)
{
    if (Root != NULL)
    {
        postOrder(Root->left);
        postOrder(Root->right);
        cout << Root->info << " ";
    }
}
void notasiKurung(Tree Root)
{
    if (Root != NULL)
    {
        
        cout << "(";
        cout << Root->info;
        notasiKurung(Root->left);
        notasiKurung(Root->right);
        cout << ")";
    }
}

int main(){
    pointer p;
    Tree root;
    root = NULL;
    int menu;
    int n;

    while (1){
        cout << "----MENU----" << endl;
        cout << "1.Insert Data" << endl;
        cout << "2.Traversal preOrder" << endl;
        cout << "3.Traversal inOrder" << endl;
        cout << "4.Traversal postOrder" << endl;
        cout << "5.Exit" << endl;
        cout << "Pilih menu: "; cin >> menu;
        
        switch (menu){
        case 1:
            cout << "Masukkan banyak angka : "; cin >> n;
            for (int i = 0; i < n; i++)
            {
                CreateSimpul(p);
                insertBST(root, p);
            }
            notasiKurung(root);
            cout << endl;
            break;
        case 2:
            preOrder(root);
            cout << endl;
            break;
        case 3:
            inOrder(root);
            cout << endl;
            break;
        case 4:
            postOrder(root);
            cout << endl;
            break;
        case 5:
            return 0;
        
        default:
            cout << "Menu tidak tersedia!" << endl;
            break;
        }
    }
    
}