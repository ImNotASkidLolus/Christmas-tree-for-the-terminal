#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <string.h>

int lines = 0;
int lines2 = -2;
int lines3 = -4;
int lines4 = -6;
int lines5 = -8;
int lines6 = -10;
int lines7 = -12;
int size = 15;
char light = '#';
char spaces[1000] = " ";

const char* colors[] ={"\e[1;33m", "\e[0;34m", "\e[0;35m", "\e[0;36m","\e[0;31m", "\e[0;37m", "\e[0;32m"};
//const char* colors[] ={"\e[1;32m", "\e[0;31m", "\e[0;37m"};
int main(){
    struct winsize w;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
        perror("ioctl");
        return 1;
    }
    for (int yup = 0; yup < w.ws_col/3 - 5; yup++){
        strcat(spaces, " ");

    }

    while(1){
        srand(time(NULL));
        int min = 0, max = 6;
        int number = rand() % (max - min + 1) + min;
        printf("\x1b[2J");
        printf("\x1b[H");
        printf("%s", spaces);
        for (int y = 0; y < size; y++){
            for (int s = size - y; s>=0; s--){
                printf(" ");
            }
            for (int x = 0; x < y; ++x){
                number = rand() % (max - min + 1) + min;

                if(x == lines2 && x%2 != 0 && y %2 == 0){
                    printf("%s%c \e[0;0m",colors[number], light);
                }else if(x == lines && x%2 == 0 && y %2 == 0){
                    printf("%s%c \e[0;0m",colors[number], light);
                }else if(x == lines3 && x%2 != 0 && y %2 == 0){
                    printf("%s%c \e[0;0m",colors[number], light);
                }else if(x == lines4 && x%2 == 0 && y %2 == 0){
                    printf("%s%c \e[0;0m",colors[number], light);
                }else if(x == lines5 && x%2 != 0 && y %2 == 0){
                    printf("%s%c \e[0;0m",colors[number], light);
                }else if(x == lines6 && x%2 == 0 && y %2 == 0){
                    printf("%s%c \e[0;0m",colors[number], light);
                }else if(x == lines7 && x%2 == 0 && y %2 == 0){
                    printf("%s%c \e[0;0m",colors[number], light);
                }else{
                    printf("\e[0;32m* \e[0;0m");
                }
            }
            printf("\n");
            printf("%s", spaces);
        }
        for(int i = 0; i < size/3; i++){
            for (int s = size/2 + 1*size/4; s >= 0; s--){
                printf(" ");
            }
            for (int j = 0; j < size/3; j++){
                printf("\e[0;33m* \e[0;0m");
            }
            printf("\n");
            printf("%s", spaces);
        }
        if(lines < 10){
            lines++;
        }else{
            lines = 0;
        }
        if(lines2 < 10){
            lines2++;
        }else{
            lines2 = lines - 2;
        }
        if(lines3 < 10){
            lines3++;
        }else{
            lines3 = lines2 - 2;
        }
        if(lines4 < 10){
            lines4++;
        }else{
            lines4 = lines3 - 2;
        }
        if(lines5 < 10){
            lines5++;
        }else{
            lines5 = lines4 - 2;
        }
        if(lines6 < 10){
            lines6++;
        }else{
            lines6 = lines5 - 2;
        }
        if(lines7 < 10){
            lines7++;
        }else{
            lines7 = lines6 - 2;
        }
        fflush(stdout);
        usleep(100000);
    }
}
