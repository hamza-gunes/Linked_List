#include <stdio.h>
#include <stdlib.h>

// Hamza Gunes - 05/12/2024 - Linked List

//Bagli listeler, bellegi dinamik ayirmak icin kullanilir. Her dugum bir anahtar deger, bir de sonraki dugumu isaret edecek pointer icerir.



struct liste{
	
	int anahtar;
	struct liste *ileri;
	
};




struct liste* DugumOlustur(int anahtar){
	
	struct liste *YeniDugum = (struct liste*)malloc(sizeof(struct liste));
	
	if (YeniDugum == NULL){
		
		printf("Dugum Olusturulamadi");
		exit(1);
	}
	
	YeniDugum->anahtar = anahtar;
	YeniDugum->ileri = NULL;
	
}




void ListeYazdir(struct liste *kok){
	
	
	if (kok->ileri == NULL) printf("%d",kok->anahtar);  //Sadece kok varsa koku yazdirir.
	
		
	struct liste *gezgin = kok;
	
	while(gezgin != NULL){
		
		
		printf("%d\n",gezgin->anahtar);
		gezgin = gezgin->ileri;
		
		
	}
	
	
}




void ListeninSonunaEkle(struct liste **kok, int anahtar){
	
	struct liste *gezgin = *kok;
	
	while(gezgin->ileri != NULL){
		
		gezgin = gezgin->ileri;
		
	}
	
	
	gezgin->ileri = DugumOlustur(anahtar);
		
	
}





int main(){
	
	
	struct liste *kok = DugumOlustur(10);
	
	ListeninSonunaEkle(&kok,20);
	ListeninSonunaEkle(&kok,30);
	ListeninSonunaEkle(&kok,40);
	
	
	ListeYazdir(kok);
	
			
	
	
}