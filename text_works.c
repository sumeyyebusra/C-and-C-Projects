#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_freq(char * cumle); // edatlarin toplam sayisini hesaplar
void get_numerics (char * kelime); // metinden sayisal degerleri alir
void count_words (char * cumle); // bir cumlenin kelimelerini sayar
void collect_stats (char metin[]); // butun istatistikleri toplar
void report(); //istatistikleri ekrana bastirir

char edat[][10] = {"in","at","to","for","of","from"};
int edat_sayisi[] = {0,0,0,0,0,0};
char sayilar[100][100];
int sayi_count = 0;
int kelime_sayisi, cumle_sayisi;

int main(void)
{
    FILE *fp;
    char metin[1000], dosya_adi[50];

    printf("Dosya adi giriniz: \n"); 
    scanf("%s", dosya_adi);

    if ((fp = fopen (dosya_adi, "r")) == NULL) {
         printf("Dosya acma hatasi!");
         exit(1);
    }
    fgets(metin, 1000, fp);
    collect_stats(metin);

    fclose(fp);

    return 0;
}

void collect_stats(char metin[]){
    char delim[] = ".";
    int i;

    char *cumle = strtok(metin, delim); //cumlelere ayirdik

    while(cumle != NULL){
        get_freq(cumle); //edatlari sayan fonksiyonu cagirdik
        count_words (cumle); //cumleleri sayan fonksiyonu cagırdık
        cumle = strtok(NULL, delim);
    }
    report(); //toplanan istatistikleri bastirdik

}
void get_freq(char *cumle){
    char kelime[100][100];
    int i,j,k,l,ctr;

    j=0; ctr=0;
    for(i=0;i<=(strlen(cumle));i++) //kelimelere ayirdik
    {
        if(cumle[i]==' '||cumle[i]=='\0')
        {
            kelime[ctr][j]='\0';
            ctr++;  
            j=0;    
        }
        else
        {
            kelime[ctr][j]=cumle[i];
            j++;
        }
    }
    for(k=0;k < ctr;k++){ // edatlari saydik
        for(l=0;l<=5;l++){
            if (strcmp(edat[l], kelime[k]) == 0){
                edat_sayisi[l] += 1;
            }
        }
    }

}

void count_words(char *cumle){
    cumle_sayisi += 1; //cumle sayisini bir arttırdık
    char kelime[100][100];
    int i,j,k,count;
    int count2 = 0;

    j=0; count=0;
    for(i=0;i<=(strlen(cumle));i++)
    {
        
        if(cumle[i]==' '||cumle[i]=='\0') //kelimelere ayirdik
        {
            kelime[count][j]='\0';
            count++;  
            j=0;    
        }
        else
        {
            kelime[count][j]=cumle[i];
            j++;
        }
    }
    for(k=0;k < count;k++){
        get_numerics(kelime[k]); //eger kelime bir sayi ise gerekli diziye yerlestirmek icin kelimeleri bu fonksiyona gonderdik
        if (strcmp(kelime[k],"\0") == 0){ // bos kelimeleri count'tan düsmek icin saydik
            count2 += 1;
        }
    }
    kelime_sayisi += count; //saydigimiz kelimeleri global degiskene ekledil
    kelime_sayisi -= count2; // bos kelimleri cikardik

}

void get_numerics (char * kelime){//sayilari sayilar dizisine ekledik
    if(kelime[0] >= 48 && kelime[0] <= 57){
        for (int i=0;i<strlen(kelime);i++){
            if (kelime[i] == '-'){
                sayi_count += 1;
                for(int j=0;j<(strlen(kelime)-i);j++){
                    sayilar[sayi_count][j] = kelime[j+i+1];
                }
            }
            else{
                sayilar[sayi_count][i] = kelime[i];
            }
        }
        sayi_count += 1;
    }
}

void report(){ // topladıgımız tum istatistikleri bastirdik
    printf("num of sentences: %d\n",cumle_sayisi);
    printf("num of words: %d\n",kelime_sayisi);
    printf("prepositions & their frequencies: \n");
    for (int i=0;i<=5;i++){
        printf("%s: %d\n",edat[i],edat_sayisi[i]);
    }
    for(int j=0;j<sayi_count;j++){
        printf("%s, ",sayilar[j]);
    }
    printf("\n");
}