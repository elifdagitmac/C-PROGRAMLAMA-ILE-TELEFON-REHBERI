#include <stdio.h>
#include <string.h>

int main() {
    char isimler[10][50]; // 10 kişi kapasiteli rehber
    char numaralar[10][20];
    int kayitSayisi = 0;
    int secim;

    while(1) { // Program kullanıcı çıkana kadar döner
        printf("\n--- TELEFON REHBERI ---\n");
        printf("1. Yeni Kayit Ekle\n");
        printf("2. Rehberi Listele\n");
        printf("3. Isim ile Numara Ara\n");
        printf("4. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch(secim) {
            case 1:
                if(kayitSayisi < 10) {
                    printf("Isim girin: ");
                    scanf("%s", isimler[kayitSayisi]);
                    printf("Numara girin: ");
                    scanf("%s", numaralar[kayitSayisi]);
                    kayitSayisi++;
                    printf("Kayit basarili!\n");
                } else {
                    printf("Rehber dolu!\n");
                }
                break;

            case 2:
                printf("\n--- KAYITLI KISILER ---\n");
                for(int i = 0; i < kayitSayisi; i++) {
                    printf("%d. %s - %s\n", i+1, isimler[i], numaralar[i]);
                }
                if(kayitSayisi == 0) printf("Rehber henuz bos.\n");
                break;

            case 3:
                {
                    char aranan[50];
                    int bulundu = 0;
                    printf("Aranacak isim: ");
                    scanf("%s", aranan);
                    
                    for(int i = 0; i < kayitSayisi; i++) {
                        if(strcmp(isimler[i], aranan) == 0) {
                            printf("Bulundu! Numara: %s\n", numaralar[i]);
                            bulundu = 1;
                            break;
                        }
                    }
                    if(!bulundu) printf("Kisi bulunamadi.\n");
                }
                break;

            case 4:
                printf("Programdan cikiliyor...\n");
                return 0;

            default:
                printf("Gecersiz secim, tekrar deneyin.\n");
        }
    }

    return 0;
}