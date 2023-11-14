#include <stdio.h>
#include <conio.h>
#include <windows.h>

COORD coord = {0, 0};

void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

    int nmr, total_sks;
    int sksmku = 2;
    int sksinf = 3;
    float mutu, sm, total_sm, ips;
    char kode[5], nama_mk[50], grade[2];


void mku101(){
    gotoxy(12, 4);
    printf("MKU101");
    gotoxy(27, 4);
    printf("Agama");
    gotoxy(57, 4);
    printf("%d",sksmku);

}
void mku103(){
    gotoxy(12, 5);
    printf("MKU103");
    gotoxy(27, 5);
    printf("Bahasa Indonesia");
     gotoxy(57, 5);
    printf("%d",sksmku);
}
void inf101(){
    gotoxy(12, 6);
    printf("INF101");
    gotoxy(27, 6);
    printf("Kalkulus");
     gotoxy(57, 6);
    printf("%d",sksinf);
}
void inf103(){
    gotoxy(12, 7);
    printf("INF103");
    gotoxy(27, 7);
    printf("Pengenalan Komputasi");
     gotoxy(57, 7);
    printf("%d",sksinf);
}
void inf107(){
    gotoxy(12, 8);
    printf("INF107");
    gotoxy(27, 8);
    printf("Pengenalan Sistem Digital");
     gotoxy(57, 8);
    printf("%d",sksinf);
}
void inf105(){
    gotoxy(12, 9);
    printf("INF105");
    gotoxy(27, 9);
    printf("PTIK");
     gotoxy(57, 9);
    printf("%d",sksinf);
}
void mku105(){
    gotoxy(12, 10);
    printf("MKU105");
    gotoxy(27, 10);
    printf("Wawasan Kewirausahaan");
     gotoxy(57, 10);
    printf("%d",sksmku);
}
void ifnama_kode() {
    if (nmr == 1) {
        mku101();
    } else if (nmr == 2) {
        mku103();
    } else if (nmr == 3) {
        inf101();
    } else if (nmr == 4) {
        inf103();
    }else if (nmr == 5) {
        inf107();
    }else if (nmr == 6) {
        inf105();
    }else if (nmr == 7) {
        mku105();
    }
}


int main() {


    printf("KARTU HASIL STUDI: Tia Mustika, Shevilla Darmawati, Dhimas Nurhidayat\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("No.        KODE MK         NAMA MK                      SKS            GRADE          MUTU           SxM\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    gotoxy(0, 11);
    printf("--------------------------------------------------------------------------------------------------------\n");
    gotoxy(50, 12);
    printf("TOTAL");
    gotoxy(0, 13);
    printf("--------------------------------------------------------------------------------------------------------\n");
    gotoxy(90, 14);
    printf("IPS");
    gotoxy(0, 15);
    printf("--------------------------------------------------------------------------------------------------------\n");


    for (nmr = 1; nmr <= 7; nmr++) {
        gotoxy(1, 3 + nmr);
        printf("%d.", nmr);
        ifnama_kode();
        gotoxy(73, 3 + nmr);
        scanf("%2s", &grade);





        if (strcasecmp(grade,"A")==0) {
            mutu = 4.0;
        } else if (strcasecmp(grade,"A-")==0) {
            mutu = 3.7;
        } else if (strcasecmp(grade,"B+")==0) {
            mutu = 3.3;
        } else if (strcasecmp(grade,"B")==0) {
            mutu = 3.0;
        } else if (strcasecmp(grade,"B-")==0) {
            mutu = 2.7;
        } else if (strcasecmp(grade,"C+")==0) {
            mutu = 2.3;
        } else if (strcasecmp(grade,"C")==0) {
            mutu = 2.0;
        } else if (strcasecmp(grade,"C-")==0) {
            mutu = 1.7;
        } else if (strcasecmp(grade,"D")==0) {
            mutu = 1;
        } else if (strcasecmp(grade,"E")==0) {
            mutu = 0;
        }

       sm = (nmr == 3 || nmr == 4 || nmr == 5 || nmr == 6) ? sksinf * mutu : sksmku * mutu;

        gotoxy(86, 3 + nmr);
        printf("%.2f", mutu);
        gotoxy(100, 3 + nmr);
        printf("%.2f \n", sm);

        //buat nyetak tot sks
        total_sks += (nmr == 3 || nmr == 4 || nmr == 5 || nmr == 6) ? sksinf : sksmku;
        gotoxy(56, 12);
        printf(" %d\n", total_sks);

        //buat nyetak tot sm
        total_sm += sm;
        gotoxy(100, 12);
        printf("%.2f\n", total_sm);

        //buat nyetak ips
        ips= total_sm / total_sks;
        gotoxy(100, 14);
        printf("%.2f\n", ips);
    }



    return 0;
}
