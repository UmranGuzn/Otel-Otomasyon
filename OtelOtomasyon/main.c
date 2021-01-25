#include <stdio.h>
#include <stdlib.h>

int main()
{
    char mevsim,odatipi,yenidensec,ucrettipi,sec;
    int hafta,kisisayisi,kisi,sayac=1,secim,dongu=0;
    int i,j,oran=0,odalar[36][100]={0};
    float ucret;


    do{
        printf("<<<<<<<<< OTEL OTOMASYON >>>>>>>>>>\n");
        printf("Hangi mevsimde konaklamak istersiniz ?\nBahar icin-->'B'\tYaz icin-->'Y'\tSonbahar icin-->'S'\t");
        scanf("%c",&mevsim); //mevsim bilgisi alindi
  switch(mevsim){

    case 'Y':// YAZ mevsimi
    case 'y':
        printf("Yazin kacinci haftasi konaklama yapacaksiniz ? [1-12]\t");
        scanf("%d",&hafta);
        if(hafta<1 || hafta>12){
            do{
                printf("Yazin kacinci haftasi konaklama yapacaksiniz ? [1-12]\t");
                scanf("%d",&hafta);
                sayac++;
                if(hafta>=1 && hafta<=12)
                    break;
                if(sayac==3)
                    return 0;
            }while(sayac!=3);
        }

        printf("\t---ODA TIPLERI---\n Standart Oda icin-->'S'\tDeluxe Oda icin-->'D'\tLarge Deluxe Oda icin-->'L'\t");
        scanf(" %c",&odatipi);
        if(odatipi=='S'|| odatipi=='s')//Standart oda
        {
            do{
                for(i=0;i<100;i++){
                    if(odalar[hafta-1][i]==0){
                        if((i+1)%2==1)
                            printf("%d -- ",i+1);
                    }
                }
                printf("\nnolu odalardan secim yapiniz!\t");
                scanf(" %d",&secim);
                if(secim%2==0 || odalar[12+hafta-1][secim-1]!=0){
                    printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                    scanf(" %c",&yenidensec);
                }
                else{
                    if(odalar[12+hafta-1][secim-1]==0){
                        odalar[12+hafta-1][secim-1]=1;
                        break;
                    }
                }
                if(yenidensec=='h')
                    return 0;
            }while(yenidensec!='H');


            printf("Kisi sayisi giriniz:\t");
            scanf("%d",&kisisayisi);
            if(kisisayisi==0)
                return 0;
            kisi=kisisayisi;

            do{
                if(kisisayisi>4){
                    do{
                        for(i=0;i<100;i++){
                            if(odalar[12+hafta-1][i]==0){
                                if((i+1)%2==1)
                                    printf("%d - ",i+1);
                            }
                        }
                        printf("Odalar en fazla 4 kisiliktir. Kapasiteyi aþan kisiler icin yeni bir oda seciniz:\t");
                        scanf("%d",&secim);
                        if(secim%2==0|| odalar[12+hafta-1][secim-1]!=0)
                        {

                            printf("Dolu oda seçtiniz! Tekrar denemek icin 'E' Cikmak için 'H' tiklayiniz.");
                            scanf(" %c",&yenidensec);
                        }
                        else{
                            if(odalar[12+hafta-1][secim-1]==0){
                                odalar[12+hafta-1][secim-1]=1;
                                break;
                            }
                        }
                        if(yenidensec=='h')
                            return 0;
                    }while(yenidensec!='H');
                }

                kisisayisi=kisisayisi-4;
                if(kisisayisi<=4)
                    break;
            }while(kisisayisi!=4);

            printf("Odeme Yontemi seciniz:\nOn odemli islem icin-->'O'\tHavale ile odeme icin-->'H'\tStandart Odeme icin-->'S'\t");
            scanf(" %c",&ucrettipi);
            switch(ucrettipi){
            case 'O':
            case 'o':
                ucret= 7*(kisi*60-(kisi*60*0.15));
                printf("TUTAR: %.2f $ \n",ucret);

                for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[12+i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : %d \n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);
                break;
            case 'H':
            case 'h':
                if(kisi>3 && kisi<=5){
                    ucret=7*((kisi*60)-30);
                    printf("TUTAR: %.2f $ \n",ucret);
                    for(i=0; i<12; i++)
                        {
                            for(j=0; j<100; j++)
                            {
                                if(odalar[12+i][j]==1)
                                    oran++;
                            }
                            printf("Baharin %d. haftasi doluluk orani = %d\n",i+1,oran);
                            oran=0;
                        }
                        printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                        scanf(" %c",&yenidensec);

                }
                else if(kisi>5){
                    ucret=7*((kisi*60)-45);
                    printf("TUTAR: %.2f $ \n",ucret);
                    for(i=0; i<12; i++)
                        {
                            for(j=0; j<100; j++)
                            {
                                if(odalar[12+i][j]==1)
                                    oran++;
                            }
                            printf("Baharin %d. haftasi doluluk orani =% %d\n",i+1,oran);
                            oran=0;
                        }
                        printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                        scanf(" %c",&yenidensec);

                }
                else{
                    ucret=7*60*kisi;
                    printf("TUTAR: %.f $ \n",ucret);
                      for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[12+i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);

                }
                break;
            case 'S':
            case 's':
                ucret=7*kisi*60;
                printf("TUTAR: %.2f $ \n",ucret);
                      for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[12+i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);

                }
                break;
            default:
                printf("Hata! Odeme yontemi yanlis secildi!");
                break;

        }


        if(odatipi=='D'|| odatipi=='d'){//DELUXE
            do{
                for(i=0;i<100;i++){
                    if(odalar[12+hafta-1][i]==0){
                        if((i+1)%2==0 && (i+1)%6!=0){
                            printf("%d -- ",i+1);
                        }
                    }
                  }
                printf("\nnolu odalardan secim yapiniz!\t");
                scanf(" %d",&secim);
                if(secim%2==1 || secim%6==0 || odalar[12+hafta-1][secim-1]!=0){
                    printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                    scanf(" %c",&yenidensec);
                }
                else{
                    if(odalar[12+hafta-1][secim-1]==0){
                        odalar[12+hafta-1][secim-1]=1;
                        break;
                    }
                }
                if(yenidensec=='h')
                    return 0;


                }while(yenidensec!='H');


                    printf("Kisi sayisi giriniz:\t");
                    scanf(" %d",&kisisayisi);
                if(kisisayisi==0)
                    return 0;
                kisi=kisisayisi;

                do{
                    if(kisisayisi>4){
                        do{
                            for(i=0;i<100;i++){
                                if(odalar[12+hafta-1][i]==0){
                                    if((i+1)%2==0 && (i+1)%6!=0)
                                        printf("%d - ",i+1);
                                }
                            }
                            printf("Odalar en fazla 4 kisiliktir. Kapasiteyi aþan kisiler icin yeni bir oda seciniz:\t");
                            scanf(" %d",&secim);
                        if(secim%2==1|| secim%6==0 || odalar[12+hafta-1][secim-1]!=0)
                        {

                            printf("Dolu oda seçtiniz! Tekrar denemek icin 'E' Cikmak için 'H' tiklayiniz.\t");
                            scanf(" %c",&yenidensec);
                        }
                        else{

                            if(odalar[12+hafta-1][secim-1]==0){

                                odalar[12+hafta-1][secim-1]=1;
                                break;
                            }
                        }
                        if(yenidensec=='h')
                            return 0;
                        }while(yenidensec!='H');
                    }

                    kisisayisi=kisisayisi-4;
                    if(kisisayisi<=4)
                        break;
                }while(kisisayisi!=4);


                printf("Odeme Yontemi seciniz:\nOn odemli islem icin-->'O'\tHavale ile odeme icin-->'H'\tStandart Odeme icin-->'S'\t");
                scanf(" %c",&ucrettipi);
        switch(ucrettipi){
            case 'O':
            case 'o':
                ucret=7*(kisi*90-(kisi*90*0.15));
                printf("TUTAR : %.2f $\n",ucret);
                for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[12+i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinda doluluk orani: % %d\n",i+1,oran);
                    oran=0;
                }
                printf("Yeni reervasyon icin--'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);
                break;
            case 'H':
            case 'h':
                if(kisi>3 && kisi<=5){
                    ucret=7*((kisi*90)-45);
                    printf("TUTAR: %.2f $ \n",ucret);
                      for(i=0;i<12;i++){
                        for(j=0;j<100;j++){
                        if(odalar[12+i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);

                }
                else if(kisi>5){
                    ucret=7*((kisi*90)-67.5);
                    printf("TUTAR: %.2f $ \n",ucret);
                      for(i=0;i<12;i++){
                        for(j=0;j<100;j++){
                        if(odalar[12+i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);
                }
                else{
                    ucret=7*90*kisi;
                    printf("TUTAR: %.2f $ \n",ucret);
                      for(i=0;i<12;i++){
                        for(j=0;j<100;j++){
                        if(odalar[12+i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);

                }
                break;
            case 'S':
            case 's':
                ucret=7*kisi*90;
                printf("TUTAR: %.2f $ \n",ucret);
                for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[12+i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);
                  break;
            default:
                printf("Hata! Odeme yontemi yanlis secildi!");
                break;
                }
            }
        else if(odatipi=='L' || odatipi=='l'){//LARGE-DELUXE
                do{
                for(i=0;i<100;i++){
                    if(odalar[12+hafta-1][i]==0){
                        if((i+1)%2==0 && (i+1)%6==0){
                            printf("%d -- ",i+1);
                        }
                    }
                  }
                printf("\nnolu odalardan secim yapiniz!\t");
                scanf(" %d",&secim);
                if(secim%2==1 || secim%6!=0 || odalar[12+hafta-1][secim-1]!=0){
                    printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                    scanf(" %c",&yenidensec);
                }
                else{
                    if(odalar[12+hafta-1][secim-1]==0){
                        odalar[12+hafta-1][secim-1]=1;
                        break;
                    }
                }
                if(yenidensec=='h')
                    return 0;


                }while(yenidensec!='H');


                    printf("Kisi sayisi giriniz:\t");
                    scanf(" %d",&kisisayisi);

                if(kisisayisi==0)
                    return 0;
                kisi=kisisayisi;
                do{
                    if(kisisayisi>7){
                        do{
                            for(i=0;i<100;i++){
                                if(odalar[12+hafta-1][i]==0){
                                    if((i+1)%2==0 && (i+1)%6==0)
                                        printf("%d - ",i+1);
                                }
                            }
                            printf("Odalar en fazla 7 kisiliktir. Kapasiteyi aþan kisiler icin yeni bir oda seciniz:\t");
                            scanf("%d",&secim);
                        if(secim%2==1|| secim%6!=0 || odalar[12+hafta-1][secim-1]!=0)
                        {

                            printf("Dolu oda seçtiniz! Tekrar denemek icin 'E' Cikmak için 'H' tiklayiniz.");
                            scanf(" %c",&yenidensec);
                        }
                        else{
                            if(odalar[12+hafta-1][secim-1]==0){
                                odalar[12+hafta-1][secim-1]=1;
                                break;
                            }
                        }
                        if(yenidensec=='h')
                            return 0;
                        }while(yenidensec!='H');
                    }
                    dongu++;
                    kisisayisi=kisisayisi-7;
                    if(kisisayisi<=7)
                        break;
                }while(kisisayisi!=7);


                printf("Odeme Yontemi seciniz:\nOn odemli islem icin-->'O'\tHavale ile odeme icin-->'H'\tStandart Odeme icin-->'S'\t");
                scanf(" %c",&ucrettipi);
                switch(ucrettipi){
            case 'O':
            case 'o':
                ucret=7*((400*dongu)-(400*dongu)*0.15);
                printf("TUTAR : %.2f $\n",ucret);
                for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[12+i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinda doluluk orani: % %d\n",i+1,oran);
                    oran=0;
                }
                printf("Yeni reervasyon icin--'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);
                break;
            case 'H':
            case 'h':
                    ucret=7*400*dongu;
                    printf("TUTAR: %.2f $ \n",ucret);
                      for(i=0;i<12;i++){
                        for(j=0;j<100;j++){
                        if(odalar[12+i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);

                break;
            case 'S':
            case 's':
                ucret=7*400*dongu;
                printf("TUTAR: %.2f $ \n",ucret);
                for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[12+i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);
                  break;
            default:
                printf("Hata! Odeme yontemi yanlis secildi!");
                break;
                }
    }

            else
                printf("Yanlis Oda Tipi!");
            break;

    case 'S':// SONBAHAR mevsimi
    case 's':
        printf("Sonbaharin kacinci haftasi konaklama yapacaksiniz ? [1-12]\t");
        scanf("%d",&hafta);
        if(hafta<1 || hafta>12){
            do{
                printf("Sonbaharin kacinci haftasi konaklama yapacaksiniz ? [1-12]\t");
                scanf("%d",&hafta);
                sayac++;
                if(hafta>=1 && hafta<=12)
                    break;
                if(sayac==3)
                    return 0;
            }while(sayac!=3);
        }

        printf("\t---ODA TIPLERI---\n Standart Oda icin-->'S'\tDeluxe Oda icin-->'D'\tLarge Deluxe Oda icin-->'L'\t");
        scanf(" %c",&odatipi);
        if(odatipi=='S'|| odatipi=='s')//Standart oda
        {
            do{
                for(i=0;i<100;i++){
                    if(odalar[24+hafta-1][i]==0){
                        if((i+1)%2==1)
                            printf("%d -- ",i+1);
                    }
                }
                printf("\nnolu odalardan secim yapiniz!\t");
                scanf(" %d",&secim);
                if(secim%2==0 || odalar[24+hafta-1][secim-1]!=0){
                    printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                    scanf(" %c",&yenidensec);
                }
                else{
                    if(odalar[24+hafta-1][secim-1]==0){
                        odalar[24+hafta-1][secim-1]=1;
                        break;
                    }
                }
                if(yenidensec=='h')
                    return 0;
            }while(yenidensec!='H');


            printf("Kisi sayisi giriniz:\t");
            scanf("%d",&kisisayisi);
            if(kisisayisi==0)
                return 0;
            kisi=kisisayisi;

            do{
                if(kisisayisi>4){
                    do{
                        for(i=0;i<100;i++){
                            if(odalar[24+hafta-1][i]==0){
                                if((i+1)%2==1)
                                    printf("%d - ",i+1);
                            }
                        }
                        printf("Odalar en fazla 4 kisiliktir. Kapasiteyi aþan kisiler icin yeni bir oda seciniz:\t");
                        scanf("%d",&secim);
                        if(secim%2==0|| odalar[24+hafta-1][secim-1]!=0)
                        {

                            printf("Dolu oda seçtiniz! Tekrar denemek icin 'E' Cikmak için 'H' tiklayiniz.");
                            scanf(" %c",&yenidensec);
                        }
                        else{
                            if(odalar[24+hafta-1][secim-1]==0){
                                odalar[24+hafta-1][secim-1]=1;
                                break;
                            }
                        }
                        if(yenidensec=='h')
                            return 0;
                    }while(yenidensec!='H');
                }

                kisisayisi=kisisayisi-4;
                if(kisisayisi<=4)
                    break;
            }while(kisisayisi!=4);

            printf("Odeme Yontemi seciniz:\nOn odemli islem icin-->'O'\tHavale ile odeme icin-->'H'\tStandart Odeme icin-->'S'\t");
            scanf(" %c",&ucrettipi);
            switch(ucrettipi){
            case 'O':
            case 'o':
                ucret= 7*(kisi*25-(kisi*25*0.15));
                printf("TUTAR: %.2f $ \n",ucret);

                for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[24+i][j]==1)
                            oran++;
                    }
                    printf("Sonbaharin %d. haftasinin doluluk orani : %d \n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);
                break;
            case 'H':
            case 'h':
                if(kisi>3 && kisi<=5){
                    ucret=7*(kisi*25-(25*0.5));
                    printf("TUTAR: %.2f $ \n",ucret);
                    for(i=0; i<12; i++)
                        {
                            for(j=0; j<100; j++)
                            {
                                if(odalar[24+i][j]==1)
                                    oran++;
                            }
                            printf("Sonbaharin %d. haftasi doluluk orani = %d\n",i+1,oran);
                            oran=0;
                        }
                        printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                        scanf(" %c",& yenidensec);

                }
                else if(kisi>5){
                    ucret=7*(kisi*25-(25*0.75));
                    printf("TUTAR: %.2f $ \n",ucret);
                    for(i=0; i<12; i++)
                        {
                            for(j=0; j<100; j++)
                            {
                                if(odalar[24+i][j]==1)
                                    oran++;
                            }
                            printf("Sonbaharin %d. haftasi doluluk orani =% %d\n",i+1,oran);
                            oran=0;
                        }
                        printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                        scanf(" %c",&yenidensec);

                }
                else{
                    ucret=7*25*kisi;
                    printf("TUTAR: %.f $ \n",ucret);
                      for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[24+i][j]==1)
                            oran++;
                    }
                    printf("Sonbaharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);

                }
                break;
            case 'S':
            case 's':
                ucret=7*kisi*25;
                printf("TUTAR: %.2f $ \n",ucret);
                      for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[24+i][j]==1)
                            oran++;
                    }
                    printf("Sonbaharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);

                }
                break;


        }


        if(odatipi=='D'|| odatipi=='d'){
            do{
                for(i=0;i<100;i++){
                    if(odalar[24+hafta-1][i]==0){
                        if((i+1)%2==0 && (i+1)%6!=0){
                            printf("%d -- ",i+1);
                        }
                    }
                  }
                printf("\nnolu odalardan secim yapiniz!\t");
                scanf(" %d",&secim);
                if(secim%2==1 || secim%6==0 || odalar[24+hafta-1][secim-1]!=0){
                    printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                    scanf(" %c",&yenidensec);
                }
                else{
                    if(odalar[24+hafta-1][secim-1]==0){
                        odalar[24+hafta-1][secim-1]=1;
                        break;
                    }
                }
                if(yenidensec=='h')
                    return 0;


                }while(yenidensec!='H');


                    printf("Kisi sayisi giriniz:\t");
                    scanf(" %d",&kisisayisi);
                if(kisisayisi==0)
                    return 0;
                kisi=kisisayisi;

                do{
                    if(kisisayisi>4){
                        do{
                            for(i=0;i<100;i++){
                                if(odalar[24+hafta-1][i]==0){
                                    if((i+1)%2==0 && (i+1)%6!=0)
                                        printf("%d - ",i+1);
                                }
                            }
                            printf("Odalar en fazla 4 kisiliktir. Kapasiteyi aþan kisiler icin yeni bir oda seciniz:\t");
                            scanf(" %d",&secim);
                        if(secim%2==1|| secim%6==0 || odalar[24+hafta-1][secim-1]!=0)
                        {

                            printf("Dolu oda seçtiniz! Tekrar denemek icin 'E' Cikmak için 'H' tiklayiniz.\t");
                            scanf(" %c",&yenidensec);
                        }
                        else{

                            if(odalar[24+hafta-1][secim-1]==0){

                                odalar[24+hafta-1][secim-1]=1;
                                break;
                            }
                        }
                        if(yenidensec=='h')
                            return 0;
                        }while(yenidensec!='H');
                    }

                    kisisayisi=kisisayisi-4;
                    if(kisisayisi<=4)
                        break;
                }while(kisisayisi!=4);


                printf("Odeme Yontemi seciniz:\nOn odemli islem icin-->'O'\tHavale ile odeme icin-->'H'\tStandart Odeme icin-->'S'\t");
                scanf(" %c",&ucrettipi);

        switch(ucrettipi){
            case 'O':
            case 'o':
                ucret=7*(kisi*50-(kisi*50*0.15));
                printf("TUTAR : %.2f $\n",ucret);
                for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[24+i][j]==1)
                            oran++;
                    }
                    printf("Sonbaharin %d. haftasinda doluluk orani: % %d\n",i+1,oran);
                    oran=0;
                }
                printf("Yeni reervasyon icin--'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);
                break;
            case 'H':
            case 'h':
                if(kisi>3 && kisi<=5){
                    ucret=7*((kisi*50)-25);
                    printf("TUTAR: %.2f $ \n",ucret);
                      for(i=0;i<12;i++){
                        for(j=0;j<100;j++){
                        if(odalar[24+i][j]==1)
                            oran++;
                    }
                    printf("Sonbaharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);

                }
                else if(kisi>5){
                    ucret=7*((kisi*50)-(50*0.75));
                    printf("TUTAR: %.2f $ \n",ucret);
                      for(i=0;i<12;i++){
                        for(j=0;j<100;j++){
                        if(odalar[24+i][j]==1)
                            oran++;
                    }
                    printf("Sonbaharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);
                }
                else{
                    ucret=7*50*kisi;
                    printf("TUTAR: %.2f $ \n",ucret);
                      for(i=0;i<12;i++){
                        for(j=0;j<100;j++){
                        if(odalar[24+i][j]==1)
                            oran++;
                    }
                    printf("Sonbaharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);

                }
                break;
            case 'S':
            case 's':
                ucret=7*kisi*50;
                printf("TUTAR: %.2f $ \n",ucret);
                for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[24+i][j]==1)
                            oran++;
                    }
                    printf("Sonbaharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);
                  break;
            default:
                printf("Hata! Odeme yontemi yanlis secildi!");
                break;
                }
            }
        else if(odatipi=='L' || odatipi=='l'){
                do{
                for(i=0;i<100;i++){
                    if(odalar[24+hafta-1][i]==0){
                        if((i+1)%2==0 && (i+1)%6==0){
                            printf("%d -- ",i+1);
                        }
                    }
                  }
                printf("\nnolu odalardan secim yapiniz!\t");
                scanf(" %d",&secim);
                if(secim%2==1 || secim%6!=0 || odalar[24+hafta-1][secim-1]!=0){
                    printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                    scanf(" %c",&yenidensec);
                }
                else{
                    if(odalar[24+hafta-1][secim-1]==0){
                        odalar[24+hafta-1][secim-1]=1;
                        break;
                    }
                }
                if(yenidensec=='h')
                    return 0;


                }while(yenidensec!='H');


                    printf("Kisi sayisi giriniz:\t");
                    scanf(" %d",&kisisayisi);

                if(kisisayisi==0)
                    return 0;
                kisi=kisisayisi;
                do{
                    if(kisisayisi>7){
                        do{
                            for(i=0;i<100;i++){
                                if(odalar[24+hafta-1][i]==0){
                                    if((i+1)%2==0 && (i+1)%6==0)
                                        printf("%d - ",i+1);
                                }
                            }
                            printf("Odalar en fazla 7 kisiliktir. Kapasiteyi aþan kisiler icin yeni bir oda seciniz:\t");
                            scanf("%d",&secim);
                        if(secim%2==1|| secim%6!=0 || odalar[24+hafta-1][secim-1]!=0)
                        {

                            printf("Dolu oda seçtiniz! Tekrar denemek icin 'E' Cikmak için 'H' tiklayiniz.");
                            scanf(" %c",&yenidensec);
                        }
                        else{
                            if(odalar[24+hafta-1][secim-1]==0){
                                odalar[24+hafta-1][secim-1]=1;
                                break;
                            }
                        }
                        if(yenidensec=='h')
                            return 0;
                        }while(yenidensec!='H');
                    }
                    dongu++;
                    kisisayisi=kisisayisi-7;
                    if(kisisayisi<=7)
                        break;
                }while(kisisayisi!=7);


                printf("Odeme Yontemi seciniz:\nOn odemli islem icin-->'O'\tHavale ile odeme icin-->'H'\tStandart Odeme icin-->'S'\t");
                scanf(" %c",&ucrettipi);
                switch(ucrettipi){
            case 'O':
            case 'o':
                ucret=7*((250*dongu)-(250*dongu)*0.15);
                printf("TUTAR : %.2f $\n",ucret);
                for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[24+i][j]==1)
                            oran++;
                    }
                    printf("Sonbaharin %d. haftasinda doluluk orani: % %d\n",i+1,oran);
                    oran=0;
                }
                printf("Yeni reervasyon icin--'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);
                break;
            case 'H':
            case 'h':
                    ucret=7*250*dongu;
                    printf("TUTAR: %.2f $ \n",ucret);
                      for(i=0;i<12;i++){
                        for(j=0;j<100;j++){
                        if(odalar[24+i][j]==1)
                            oran++;
                    }
                    printf("Sonbaharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);

                break;
            case 'S':
            case 's':
                ucret=7*250*dongu;
                printf("TUTAR: %.2f $ \n",ucret);
                for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[24+i][j]==1)
                            oran++;
                    }
                    printf("Sonbaharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'\t");
                scanf(" %c",&yenidensec);
                  break;
            default:
                printf("Hata! Odeme yontemi yanlis secildi!");
                break;
                }
    }
        else
                printf("Yanlis Oda Tipi!");
            break;
    case 'B':// Bahar mevsimi
    case 'b':
        printf("Baharin kacinci haftasi konaklama yapacaksiniz ? [1-12]\t");
        scanf("%d",&hafta);
        if(hafta<1 || hafta>12){
            do{
                printf("Baharin kacinci haftasi konaklama yapacaksiniz ? [1-12]\t");
                scanf("%d",&hafta);
                sayac++;
                if(hafta>=1 && hafta<=12)
                    break;
                if(sayac==3)
                    return 0;
            }while(sayac!=3);
        }

        printf("\t---ODA TIPLERI---\n Standart Oda icin-->'S'\tDeluxe Oda icin-->'D'\tLarge Deluxe Oda icin-->'L'");
        scanf(" %c",&odatipi);
        if(odatipi=='S'|| odatipi=='s'){//Standart oda
            do{
                for(i=0;i<100;i++){
                    if(odalar[hafta-1][i]==0){
                        if((i+1)%2==1)
                            printf("%d -- ",i+1);
                    }
                }
                printf("\nnolu odalardan secim yapiniz!\t");
                scanf("%d",&secim);
                if(secim%2==0 || odalar[hafta-1][secim-1]!=0){
                    printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                    scanf(" %c",&yenidensec);
                }
                else{
                    if(odalar[hafta-1][secim-1]==0){
                        odalar[hafta-1][secim-1]=1;
                        break;
                    }
                }
                if(yenidensec=='h')
                    return 0;
            }while(yenidensec!='H');
            printf("Kisi sayisi giriniz:\t");
            scanf("%d",&kisisayisi);
            if(kisisayisi==0)
                return 0;
            kisi=kisisayisi;

            do{
                if(kisisayisi>4){
                    do{
                        for(i=0;i<100;i++){
                            if(odalar[hafta-1][i]==0){
                                if((i+1)%2==1)
                                    printf("%d - ",i+1);
                            }
                        }
                        printf("Odalar en fazla 4 kisiliktir. Kapasiteyi aþan kisiler icin yeni bir oda seciniz:\t");
                        scanf("%d",&secim);
                        if(secim%2==0|| odalar[hafta-1][secim-1]!=0)
                        {

                            printf("Dolu oda seçtiniz! Tekrar denemek icin 'E' Cikmak için 'H' tiklayiniz.");
                            scanf(" %c",&yenidensec);
                        }
                        else{
                            if(odalar[hafta-1][secim-1]==0){
                                odalar[hafta-1][secim-1]=1;
                                break;
                            }
                        }
                        if(yenidensec=='h')
                            return 0;
                    }while(yenidensec!='H');
                }

                kisisayisi=kisisayisi-4;
                if(kisisayisi<=4)
                    break;
            }while(kisisayisi!=4);

            printf("Odeme Yontemi seciniz:\nOn odemli islem icin-->'O'\tHavale ile odeme icin-->'H'\tStandart Odeme icin-->'S'");
            scanf(" %c",&ucrettipi);
            switch(ucrettipi){
            case 'O':
            case 'o':
                ucret= 7*(kisi*40-(kisi*40*0.15));
                printf("TUTAR: %.2f $ \n",ucret);

                for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : %d \n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'");
                scanf(" %c",&yenidensec);
                break;
            case 'H':
            case 'h':
                if(kisi>3 && kisi<=5){
                    ucret=7*((kisi*40)-20);
                    printf("TUTAR: %.2f $ \n",ucret);
                    for(i=0; i<12; i++)
                        {
                            for(j=0; j<100; j++)
                            {
                                if(odalar[i][j]==1)
                                    oran++;
                            }
                            printf("Baharin %d. haftasi doluluk orani = %d\n",i+1,oran);
                            oran=0;
                        }
                        printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'");
                        scanf(" %c",&yenidensec);

                }
                else if(kisi>5){
                    ucret=7*((kisi*40)-30);
                    printf("TUTAR: %.2f $ \n",ucret);
                    for(i=0; i<12; i++)
                        {
                            for(j=0; j<100; j++)
                            {
                                if(odalar[i][j]==1)
                                    oran++;
                            }
                            printf("Baharin %d. haftasi doluluk orani =% %d\n",i+1,oran);
                            oran=0;
                        }
                        printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'");
                        scanf(" %c",&yenidensec);

                }
                else{
                    ucret=7*40*kisi;
                    printf("TUTAR: %.f $ \n",ucret);
                      for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'");
                scanf(" %c",&yenidensec);

                }
                break;
            case 'S':
            case 's':
                ucret=7*kisi*40;
                printf("TUTAR: %.2f $ \n",ucret);
                      for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'");
                scanf(" %c",&yenidensec);

                }
                break;

        }


        if(odatipi=='D'|| odatipi=='d'){
            do{
                for(i=0;i<100;i++){
                    if(odalar[hafta-1][i]==0){
                        if((i+1)%2==0 && (i+1)%6!=0){
                            printf("%d -- ",i+1);
                        }
                    }
                  }
                printf("nolu odalardan secim yapiniz!\t");
                scanf(" %d",&secim);
                if(secim%2==1 || secim%6==0 || odalar[hafta-1][secim-1]!=0){
                    printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                    scanf(" %c",&yenidensec);
                }
                else{
                    if(odalar[hafta-1][secim-1]==0){
                        odalar[hafta-1][secim-1]=1;
                        break;
                    }
                }
                if(yenidensec=='h')
                    return 0;


                }while(yenidensec!='H');
                    printf("Kisi sayisi giriniz:\t");
                    scanf(" %d",&kisisayisi);
                if(kisisayisi==0)
                    return 0;
                kisi=kisisayisi;
                do{
                    if(kisisayisi>4){
                        do{
                            for(i=0;i<100;i++){
                                if(odalar[hafta-1][i]==0){
                                    if((i+1)%2==0 && (i+1)%6!=0)
                                        printf("%d - ",i+1);
                                }
                            }
                            printf("Odalar en fazla 4 kisiliktir. Kapasiteyi aþan kisiler icin yeni bir oda seciniz:\t");
                            scanf(" %d",&secim);
                        if(secim%2==1|| secim%6==0 || odalar[hafta-1][secim-1]!=0)
                        {

                            printf("Dolu oda seçtiniz! Tekrar denemek icin 'E' Cikmak için 'H' tiklayiniz.");
                            scanf(" %c",&yenidensec);
                        }
                        else{
                            if(odalar[hafta-1][secim-1]==0){
                                odalar[hafta-1][secim-1]=1;
                                break;
                            }
                        }
                        if(yenidensec=='h')
                            return 0;
                        }while(yenidensec!='H');
                    }

                    kisisayisi=kisisayisi-4;
                    if(kisisayisi<=4)
                        break;
                }while(kisisayisi!=4);
                printf("Odeme Yontemi seciniz:\nOn odemli islem icin-->'O'\tHavale ile odeme icin-->'H'\tStandart Odeme icin-->'S'");
                scanf(" %c",&ucrettipi);
                switch(ucrettipi){
            case 'O':
            case 'o':
                ucret=7*(kisi*75-(kisi*75*0.15));
                printf("TUTAR : %.2f $\n",ucret);
                for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinda doluluk orani: % %d\n",i+1,oran);
                    oran=0;
                }
                printf("Yeni reervasyon icin--'E'\tCikis icin-->'H'");
                scanf(" %c",&yenidensec);
                break;
            case 'H':
            case 'h':
                if(kisi>3 && kisi<=5){
                    ucret=7*((kisi*40)-20);
                    printf("TUTAR: %.2f $ \n",ucret);
                      for(i=0;i<12;i++){
                        for(j=0;j<100;j++){
                        if(odalar[i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'");
                scanf(" %c",&yenidensec);

                }
                else if(kisi>5){
                    ucret=7*((kisi*40)-30);
                    printf("TUTAR: %.2f $ \n",ucret);
                      for(i=0;i<12;i++){
                        for(j=0;j<100;j++){
                        if(odalar[i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'");
                scanf(" %c",&yenidensec);
                }
                else{
                    ucret=7*40*kisi;
                    printf("TUTAR: %.2f $ \n",ucret);
                      for(i=0;i<12;i++){
                        for(j=0;j<100;j++){
                        if(odalar[i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'");
                scanf(" %c",&yenidensec);

                }
                break;
            case 'S':
            case 's':
                ucret=7*kisi*75;
                printf("TUTAR: %.2f $ \n",ucret);
                for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'");
                scanf(" %c",&yenidensec);
                  break;
            default:
                printf("Hata! Odeme yontemi yanlis secildi!");
                break;
                }
            }
        else if(odatipi=='L' || odatipi=='l'){
                do{
                for(i=0;i<100;i++){
                    if(odalar[hafta-1][i]==0){
                        if((i+1)%2==0 && (i+1)%6==0){
                            printf("%d -- ",i+1);
                        }
                    }
                  }
                printf("\nnolu odalardan secim yapiniz!\t");
                scanf(" %d",&secim);
                if(secim%2==1 || secim%6!=0 || odalar[hafta-1][secim-1]!=0){
                    printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                    scanf(" %c",&yenidensec);
                }
                else{
                    if(odalar[hafta-1][secim-1]==0){
                        odalar[hafta-1][secim-1]=1;
                        break;
                    }
                }
                if(yenidensec=='h')
                    return 0;


                }while(yenidensec!='H');


                    printf("Kisi sayisi giriniz:\t");
                    scanf("%d",&kisisayisi);

                if(kisisayisi==0)
                    return 0;
                kisi=kisisayisi;
                do{
                    if(kisisayisi>7){
                        do{
                            for(i=0;i<100;i++){
                                if(odalar[hafta-1][i]==0){
                                    if((i+1)%2==0 && (i+1)%6==0)
                                        printf("%d - ",i+1);
                                }
                            }
                            printf("Odalar en fazla 7 kisiliktir. Kapasiteyi aþan kisiler icin yeni bir oda seciniz:\t");
                            scanf("%d",&secim);
                        if(secim%2==1|| secim%6!=0 || odalar[hafta-1][secim-1]!=0)
                        {

                            printf("Dolu oda seçtiniz! Tekrar denemek icin 'E' Cikmak için 'H' tiklayiniz.");
                            scanf(" %c",&yenidensec);
                        }
                        else{
                            if(odalar[hafta-1][secim-1]==0){
                                odalar[hafta-1][secim-1]=1;
                                break;
                            }
                        }
                        if(yenidensec=='h')
                            return 0;
                        }while(yenidensec!='H');
                    }
                    dongu++;
                    kisisayisi=kisisayisi-7;
                    if(kisisayisi<=7)
                        break;
                }while(kisisayisi!=7);
                printf("Odeme Yontemi seciniz:\nOn odemli islem icin-->'O'\tHavale ile odeme icin-->'H'\tStandart Odeme icin-->'S'");
                scanf(" %c",&ucrettipi);
                switch(ucrettipi){
            case 'O':
            case 'o':
                ucret=7*((300*dongu)-(300*dongu)*0.15);
                printf("TUTAR : %.2f $\n",ucret);
                for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinda doluluk orani: % %d\n",i+1,oran);
                    oran=0;
                }
                printf("Yeni reervasyon icin--'E'\tCikis icin-->'H'");
                scanf(" %c",&yenidensec);
                break;
            case 'H':
            case 'h':
                    ucret=7*300*dongu;
                    printf("TUTAR: %.2f $ \n",ucret);
                      for(i=0;i<12;i++){
                        for(j=0;j<100;j++){
                        if(odalar[i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'");
                scanf(" %c",&yenidensec);

                break;
            case 'S':
            case 's':
                ucret=7*300*dongu;
                printf("TUTAR: %.2f $ \n",ucret);
                for(i=0;i<12;i++){
                    for(j=0;j<100;j++){
                        if(odalar[i][j]==1)
                            oran++;
                    }
                    printf("Baharin %d. haftasinin doluluk orani : % %d\n",i+1,oran);
                    oran=0;

                }
                printf("Yeni rezervasyon icin-->'E'\tCikis icin-->'H'");
                scanf(" %c",&yenidensec);
                  break;
            default:
                printf("Hata! Odeme yontemi yanlis secildi!");
                break;
                }
    }
        else
                printf("Yanlis Oda Tipi!");
            break;
            break;

   }if(yenidensec=='e')
            yenidensec=='E';

    }while(yenidensec=='E');

    return 0;
}
