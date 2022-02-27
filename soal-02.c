/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 3 - Pointers and Functions
*Percobaan        : -
*Hari dan Tanggal : Selasa, 1 Maret 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk menentukan index awal
void check_start(char *str, char *start, int *start_idx) {
	int i, j, found;
	
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == start[0]) {
			found = 1;
			for (j = 1; j < strlen(start); j++) {
				if (str[i+j] != start[j])
					found = 0;
			}
			printf("%d\n",found);
			if (found) {
				printf("start %d\n",i);
				*start_idx = i;
				printf("start %d\n",*start_idx);
				return;
			}
		}
	}
}

// Fungsi untuk menentukan index akhir
void check_end(char *str, char *end, int *end_idx) {
	int i, j, found;
	for (i = strlen(str); i >= 0 ; i--) {
		if (str[i] == end[0]) {
			found = 1;
			for (j = 1; j < strlen(end); j++) {
				if (str[i+j] != end[j])
					found = 0;
			}
			printf("%d\n",found);
			if (found) {
				printf("end %d\n",i);
				*end_idx = i + strlen(end) - 1;
				printf("end %d\n",*end_idx);
				return;
			}
		}
	}
}

int main() {
	char str[128], start[128], end[128];
	int start_idx, end_idx, i;
	
	// Input dari user
	printf("Masukkan string: ");
	scanf("%[^\n]%*c", str);
	printf("Masukkan awalan: ");
	scanf("%[^\n]%*c", start);
	printf("Masukkan akhiran: ");
	scanf("%[^\n]%*c", end);
	
	// Tentukan index awal dan akhir menggunakan fungsi check_start dan check_end
	check_start(str, start, &start_idx);
	//check_end(str, end, &end_idx);
	
	// Print output
	printf("Substring hasil: ");
	for (i = start_idx; i <= end_idx; i++)
		printf("%c", str[i]);
	
	return 0;
}
