#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char** argv){
    int num_arg = argc;
    for(int i = 0; i < num_arg; i++ ) {
      printf("%s\n", argv[i]);
    }

    int arg = strcmp(argv[1], "-a");
    char *mode = "w";
    if(arg == 0) {
      mode = "a";
      for (int i = 1; i<num_arg-1; i++){
          argv[i] = argv[i+1];
      }
      num_arg--;
    }

    FILE **outs = malloc(num_arg*sizeof(FILE *));
    outs[0] = stdout;
    for (int i = 1; i < num_arg; i++) {
      outs[i] = fopen(argv[i], mode);
    }

    char * buff = malloc(10000);
    while (fread(buff, 1, 10000, stdin))
      for (int i = 0; i < num_arg; i++){
        for (int j = 0; j < 10000; j++){
          if(buff[j]!='\0'){
            fprintf(outs[i], "%c", buff[j]);
          }
        }
      }

    printf("\n");
    for(int i = 1; i < num_arg; i++){
      fclose(outs[i]);
    }

    return 0;
}
