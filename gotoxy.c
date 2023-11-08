#include <stdio.h>
#include <conio.h>
#include <windows.h>

COORD coord = {0, 0};
int nmr, sks, total_sks = 0;
    float mutu, sm, total_sm = 0, ips;
    char kode[5], nama_mk[50], grade[2];


void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void inputKodeMk() {
    gotoxy(12, 3 +nmr);
    scanf("%s", &kode);
}


void inputNamaMk() {
    gotoxy(27, 3 +nmr);
    scanf("%s", &nama_mk);
}

int main() {


    printf("KARTU HASIL STUDI: Tia Mustika, Shevilla Darmawati, Dhimas Nurhidayat\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("No.        KODE MK         NAMA MK            SKS            GRADE          MUTU           SxM\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    gotoxy(0, 11);
    printf("-------------------------------------------------------------------------------------------------\n");
    gotoxy(34, 12);
    printf("TOTAL");
    gotoxy(0, 13);
    printf("-------------------------------------------------------------------------------------------------\n");
    gotoxy(85, 14);
    printf("IPS");
    gotoxy(0, 15);
    printf("-------------------------------------------------------------------------------------------------\n");

    for (nmr = 1; nmr <= 7; nmr++) {
        gotoxy(1, 3 + nmr);
        printf("%d.", nmr);

        inputKodeMk();

        inputNamaMk();

        gotoxy(47, 3 + nmr);
        scanf("%d", &sks);
        gotoxy(62, 3 + nmr);
        scanf("%2s", &grade);

        if (strcasecmp(grade, "A") == 0) {
            mutu = 4.0;
        } else if (strcasecmp(grade, "A-") == 0) {
            mutu = 3.7;
        } else if (strcasecmp(grade, "B+") == 0) {
            mutu = 3.3;
        } else if (strcasecmp(grade, "B") == 0) {
            mutu = 3.0;
        } else if (strcasecmp(grade, "B-") == 0) {
            mutu = 2.7;
        } else if (strcasecmp(grade, "C+") == 0) {
            mutu = 2.3;
        } else if (strcasecmp(grade, "C") == 0) {
            mutu = 2.0;
        } else if (strcasecmp(grade, "C-") == 0) {
            mutu = 1.7;
        } else if (strcasecmp(grade, "D") == 0) {
            mutu = 1;
        } else if (strcasecmp(grade, "E") == 0) {
            mutu = 0;
        }

        sm = sks * mutu;

        gotoxy(76, 3 + nmr);
        printf("%.2f", mutu);
        gotoxy(90, 3 + nmr);
        printf("%.2f \n", sm);

        //buat nyetak tot sks
        total_sks += sks;
        gotoxy(45, 12);
        printf("%d", total_sks);

        //buat nyetak tot sm
        total_sm += sm;
        gotoxy(90, 12);
        printf("%.2f", total_sm);

        //buat nyetak ips
        ips = total_sm / total_sks;
        gotoxy(90, 14);
        printf("%.2f", ips);
    }

    return 0;
}
