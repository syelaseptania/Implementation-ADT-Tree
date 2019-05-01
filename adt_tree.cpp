#include <iostream> //NAMA : SYELA SEPTANIA
#include <stdio.h>  //NPM  : 1817051058
#include <stdlib.h>
using namespace std;

//pendeklarasian struct sebuah tree awal
struct Node{
      int data;
      Node *kiri;
      Node *kanan;
};



//fungsi untuk menambahkan node baru
void tambah(Node **root, int databaru)
{
      //jika root masih kosong
      if((*root) == NULL)
      {
            //pembuatan node baru
            Node *baru;
            //pengalokasian memori dari node yang telah dibuat
            baru = new Node;
            //inisialisasi awal node yang baru dibuat
            baru->data = databaru;
            baru->kiri = NULL;
            baru->kanan = NULL;
            (*root) = baru;
            (*root)->kiri = NULL;
            (*root)->kanan = NULL;
            cout<<"Data bertambah!"<<endl;
      }
     //jika data yang akan dimasukkan lebih kecil daripada elemen root, maka akan diletakkan di node sebelah kiri.
      else if(databaru<(*root)->data)
            tambah(&(*root)->kiri, databaru);
     //jika data yang akan dimasukkan lebih besar daripada elemen root, maka akan diletakkan di node sebelah kanan
      else if(databaru>(*root)->data)
            tambah(&(*root)->kanan, databaru);
     //jika saat dicek data yang akan dimasukkan memiliki nilai yang sama dengan data pada root
      else if(databaru == (*root)->data)
            cout<<"Data sudah ada!";
}

//fungsi yang digunakan untuk mencetak tree secara preOrder
void preOrder(Node *root)
{
      if(root != NULL){
            cout<<root->data<<endl;
            preOrder(root->kiri);
            preOrder(root->kanan);
      }
}

//fungsi yang digunakan untuk mencetak tree secara inOrder
void inOrder(Node *root)
{
      if(root != NULL){
            inOrder(root->kiri);
            cout<<root->data<<endl;
            inOrder(root->kanan);
      }
}

//fungsi yang digunakan untuk mencetak tree secara postOrder
void postOrder(Node *root)
{
      if(root != NULL){
            postOrder(root->kiri);
            postOrder(root->kanan);
            cout<<root->data<<endl;
      }
}

//fungsi utama
int main()
{
      //deklarasikan variabel
      int pil, date;// c;
      Node *tree; //*t;
      tree = NULL; //inisialisasi node pohon
      //perulangan do-while
      do
      {
            system("cls"); //bersihkan layar
            cout<<"\t<<__________PROGRAM  ADT TREE__________>>"<<endl;
            cout<<"\n\t======================================="<<endl;
            cout<<"\nPilihan :"<<endl;
            cout<<"\n\n"<<endl;
            cout<<"           1) Tambah\n"<<endl;
            cout<<"           2) Lihat pre order\n"<<endl;
            cout<<"           3) Lihat in order\n"<<endl;
            cout<<"           4) Lihat post order\n"<<endl;
            cout<<"           5) Exit\n"<<endl;
            cout<<"Pilihan : "<<endl;
            cout<<"============================================"<<endl;
            cin >> pil;
            switch(pil)
            {
            //jika pil bernilai 1
            case 1 :
                  cout<<"\nINPUT : "<<endl;
                  cout<<"\n-------"<<endl;
                  cout<<"\nData baru : "<<endl;
                  scanf("%d", &date);
                  //panggil fungsi untuk menambah node yang berisi data pada tree
                  tambah(&tree, date);
                  system("pause");
                  break;

            //jika pil bernilai 2
            case 2 :
                  cout<<"\nOUTPUT PRE ORDER : "<<endl;
                  cout<<"\n------------------\n"<<endl;
                  if(tree!=NULL)
                       //panggil fungsi untuk mencetak data secara preOrder
                        preOrder(tree);
                  else
                        cout<<"belum ada!"<<endl;
                    system("pause");
                  break;

            //jika pil bernilai 3
            case 3 :
                  cout<<"\nOUTPUT IN ORDER : "<<endl;
                  cout<<"\n------------------\n"<<endl;
                  if(tree!=NULL)
                       //panggil fungsi untuk mencetak data secara inOrder
                        inOrder(tree);
                  else
                        cout<<"belum ada!"<<endl;
                system("pause");
                  break;

            //jika pil bernilai 4
            case 4 :
                  cout<<"\nOUTPUT POST ORDER : "<<endl;
                  cout<<"\n------------------\n"<<endl;
                  if(tree!=NULL)
                       //panggil fungsi untuk mencetak data secara postOrder
                        postOrder(tree);

                  else
                        cout<<"belum ada!"<<endl;
                system("pause");
                  break;
            }
            cin.get();
      }while(pil != 5); //akan diulang jika input tidak samadengan 5
      return EXIT_FAILURE;
}

