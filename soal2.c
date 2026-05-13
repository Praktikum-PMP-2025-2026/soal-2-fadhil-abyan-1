/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : Dynamic Structures
 *   Hari dan Tanggal    : Rabu, 13 Mei 2026
 *   Nama (NIM)          : Muhammad Fadhil Abyan (13224008)
 *   Nama File           : soal2.c
 *   Deskripsi           : Nyari Island ama largest pulau
 */

 #include <stdio.h>
 #include <stdlib.h>

// Contoh test case:
// 11000
// 11010
// 00101
// 00011
//ISLANDS 4
// LARGEST 4

int findMax(int* arr, int N){
    int max = -1; // karena nilai sum kebetulan tidak mungkin > 0
    for(int i = 0; i < N; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

void cariTetangga(int R, int C, int arr[R][C], int* island, int* largest){
    *island = 0;
    *largest = 0;
    int nampung_sum[50] ={0};

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            int sum = 1;
            printf("%d %d, %d\n", i, j, arr[i][j]);
            if(arr[i][j] == 1){
                int k = j;
                int l = i;

                if(k < C -1){
                    while(arr[i][k+1] == 1 && k < C){
                    sum++;
                    k++;
                }
                k = j;
                }
                
                
                if(k > 0){
                    while(arr[i][k-1] == 1 && k >= 0){
                    sum++;
                    k--;
                }
                }
                

                if(l <R -1){
                    while(arr[l+1][j] == 1 && l < R){
                    sum++;
                    l++;
                    }
                    l = i;
                }
                

                if(l > 0){
                    while(arr[l-1][j] == 1 && l >= 0){
                    sum++;
                    l--;
                }
                }
                
            
                if(sum > 1){
                    *island++;
                }
            }
            if(sum > 1){
                nampung_sum[*island] = sum;
            }   
        }
    }

    *largest = findMax(nampung_sum, *island);
 }

 
 int main(){
    int R, C;
    scanf("%d %d", &R, &C);
    int arr[R][C];

    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            scanf("%d", &arr[i][j]);
        }
    }


    int island;
    int largest;

    cariTetangga(R,C, arr, &island, &largest);

    printf("ISLANDS %d\n", island);
    printf("LARGEST %d", largest);




    return 0;
 }
