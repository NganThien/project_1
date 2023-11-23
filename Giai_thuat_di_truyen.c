#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

int CT[10];
int n = 4;
int GTTN[10], kq;
int max1, max2, maxmoi1 = 0, maxmoi2 = 0;
int A[5], B[5];

//khoi tao quan the
void Taoquanthe(int n){
    for(int i = 0; i<n; i++){
        printf("Nhap ca the thu %d: ", i);
        scanf("%d", &CT[i]);
    }
}
//tinh gia tri thich nghi
void Giatrithichnghi(int n){
    int gttn;
    for(int i = 0; i<n; i++){
        gttn = 1000 - (CT[i]*CT[i]-64);
        GTTN[i] = gttn;
    }
}
//kiem tra gia tri thich nghi
int Kiemtra(int n){
    for(int i = 0; i<n; i++){
        if(GTTN[i]==1000) return (CT[i]);
    }
    return 0;
}
//tim ca the lai, chon loc lay 2 gia tri dau tien
void Timcathelai(){
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(GTTN[i]<GTTN[j]){
                int tmp = GTTN[i];
                GTTN[i] = GTTN[j];
                GTTN[j] = tmp;
            }
        }
    }
    max1 = sqrt(1064 - GTTN[0]);
    max2 = sqrt(1064 - GTTN[1]);
}
//lai ca the moi voi nhau tao quan the moi
void Laicathe(){
    for(int i = 0; i<5; i++){
        A[i] = 0;
        B[i] = 0;
    }
    while(max1!=0){
        
    }
}
