/*
Nama		: Difa Bagasputra M
NPM			: 140810180057
Nama Program: UTS
Tahun		: 2019
*/

#include <iostream>
#include <string.h>

using namespace std;

struct ElemtList{
	char no;
    char tim[20];
    int gol;
    char asal[20];
	ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First){
	First = NULL;
}

//chubu miyazaki 1
//furano hokaido 2
//hirado nagasaki 1
//minamiuwa ehime 0
//toho suginami 3
//nankatsu sizuoka 3

void createElemt(pointer& pBaru){
	pBaru=new ElemtList;
	cout<<"Masukkan Nama Tim : ";cin>>pBaru->tim;
    cout<<"Masukkan banyak gol : ";cin>>pBaru->gol;
    cout<<"Masukkan Daerah Asal : ";cin>>pBaru->asal;
	pBaru->next=NULL;
}

void insertFirst(List& First, pointer pBaru){
	if(First==NULL)
		First=pBaru;
	else{
		pBaru->next=First;
		First=pBaru;
	}
}

void traversal(List First){
    int i=1;
	pointer pBantu;
	if(First==NULL){
		cout << "List kosong"<<endl;
	}
	else{
		pBantu=First;
		do{
			cout << i<<"."<<pBantu->tim<<" "<<pBantu->gol<<" "<<pBantu->asal;
            i++;
            cout<<endl;
			pBantu = pBantu->next;
		}while(pBantu!=NULL);
	}
}

void insertLast(List& First, pointer pBaru){

	pointer last;
	cout<<"Insert Last"<<endl;
	if(First==NULL){
		First=pBaru;
	}
	else{
		last=First;
		while(last->next!=NULL){
			last=last->next;
		}
	last->next=pBaru;
	}
}

void sort(List First){
	pointer pBantu;
	pointer pSort= new ElemtList;

	if (First== NULL) return;
	if (First->next == NULL) return;

	int swapped = 1;
	
	while (swapped) {
		swapped = 0;
		pBantu= First;
		while (pBantu->next != NULL) {
			if (pBantu->gol < pBantu->next->gol) {

				swapped = 1;

				pSort->gol = pBantu->gol;
				pBantu->gol = pBantu->next->gol;
				pBantu->next->gol = pSort->gol;

				strcpy(pSort->tim,pBantu->tim);
				strcpy(pBantu->tim,pBantu->next->tim);
				strcpy(pBantu->next->tim,pSort->tim);

				strcpy(pSort->asal,pBantu->asal);
				strcpy(pBantu->asal,pBantu->next->asal);
				strcpy(pBantu->next->asal,pSort->asal);
			}
		pBantu = pBantu->next;
		}
	}
}

int main()
{
    pointer p;
    List l;
    int n;

    createList(l);
    cout<<"Masukkan Banyak Tim : ";cin>>n;
    for(int i=0;i<n;i++){
        createElemt(p);
        insertLast(l,p);
    }

    traversal(l);

    sort(l);

    cout<<"==Setelah Sort==\n";
    traversal(l);

}