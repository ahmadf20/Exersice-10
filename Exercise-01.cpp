/*
Nama			: Ahmad Faaiz Al-auza'i
NPM				: 140810180023
Tanggal dibuat	: 15/05/2019 
Deskripsi       : Queue-Array
***********************************************/
#include <iostream>
using namespace std;

const int maxElemen = 255;
struct Queue {
    char isi[maxElemen];
    int head;
    int tail;
};
Queue Q;

int empty(Queue Q){
    return Q.head && Q.tail == -1;
}

void enqueue(Queue& Q, char elemen) {
    int posisiTemp;
    if (empty(Q)) { 
        Q.head = 0;
        Q.tail = 0;
        Q.isi[Q.tail] = elemen;
    }
    else {
        posisiTemp = Q.tail; 
        if (Q.tail < maxElemen-1 ) { 
            Q.tail = Q.tail+1;
        }
        else { 
            Q.tail = 0;
        }
        if (Q.tail == Q.head){
            cout << "Antrian sudah penuh" << endl;
            Q.tail = posisiTemp; 
        }
        else {
            Q.isi[Q.tail] = elemen;
        }
    }
}

void dequeue(Queue& Q, char& elemenHapus){
    if (empty(Q)) { 
        cout<<"Antrian kosong"<<endl;
    }
    else if (Q.head == Q.tail){ 
        elemenHapus = Q.isi[Q.head];
        Q.isi[Q.head] = ' ';
        Q.head = -1; 
        Q.tail = -1;
    }
    else { 
        elemenHapus = Q.isi[Q.head];
        Q.isi[Q.head] =' ';
        if (Q.head < maxElemen-1) {
            Q.head = Q.head+1;
        }
        else { 
            Q.head = 0;
        }
    }
}

int main()
{
    int n;
    char huruf;
    Q.head = -1;
    Q.tail = -1; 
    cout << "Banyak Data: "; cin >> n;
    for (int i = 0 ; i<n; i++){
        cout << "Huruf : "; cin >> huruf;
        enqueue(Q,huruf);
    }
    cout << "\n---OUTPUT---\n";
    cout << "[OUT]<--";
    for(int i = 0; i<n; i++){
        cout << "[" << Q.isi[i] << "]" << "<--";
    }
    cout << "[IN]";
    return 0;
}
