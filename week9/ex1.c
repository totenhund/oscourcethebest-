#include <stdio.h>

typedef struct{
    int memory, count;
}Frame;

void ageing(int frames[], int len){
  for(int i = 0; i < len; i++){
    int hit = 0;
    int miss = 0;
    int memory;
    double hit_miss_ratio;
    Frame p[frames[i]];
    FILE *file = fopen("Lab 09 input.txt", "r");
    for (int z = 0; z < frames[i]; z++){
        p[z].memory = 0;
        p[z].count = 0;
    }

    while (fscanf(file, "%d", &memory) != EOF){
        int found = -1;
        int j;
        int min = 256;

        for (int k = 0; k < frames[i]; k++){
            if (p[k].memory == memory){
                found = k;
                hit++;
            }else if (p[k].count < min || p[k].memory == 0){
                min = p[k].count;
                j = k;
            }

            p[k].count = p[k].count >> 1;
        }

        if (found != -1){
            p[found].count += 127;
        }else{
            p[j].memory = memory;
            p[j].count = 127;
            miss++;
        }
    }
    hit_miss_ratio = (double) hit / miss;
    printf("For %d page frames there is Hit/Miss ratio: %f\n", frames[i], hit_miss_ratio);
    fclose(file);
  }
}

int main(){
    int frames[3] = {10, 50, 100};
    ageing(frames, 3);
    return 0;
}
