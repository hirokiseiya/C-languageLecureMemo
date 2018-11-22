#include <stdio.h>
 
void main()
{
    int i, n, j, t;
    int line[512];   
    double ave;//平均
    int sum =0 ;//合計
 
    FILE *fp;
 
    fp = fopen("Lesson5.txt", "r");

    if(fp == NULL) {
        printf("ファイルを開くことが出来ませんでした．¥n");
        return;
    }
 
    n = 0;
 
    while ( ! feof(fp) && n < 512) {
        fscanf(fp, "%d", &(line[n]));
        n++;
    }
 
    fclose(fp);
 
    n = n-1; 
 
    
    for(i=0; i<n; i++) {//sumにLesson5の点数を足していく
	    sum += line[i];
    }
	
    ave = (double)sum/n;//平均
	printf("ave: %lf \n", ave);

    for( i = 0 ; i < n ; i++ ){//並び変えソート
        for( j = i + 1 ; j < n ; j++ ){
            if( line[i] > line[j] ){
            t = line[i];
            line[i] = line[j];
            line[j] = t;
            }
        }
    }


    printf("med: %d \n", line[n/2]);//中央値
    printf("%d", n / 2);
    printf("%d", n);
}
