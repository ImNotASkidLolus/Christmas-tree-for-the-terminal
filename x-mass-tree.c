#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>

int size;
char light = 'o';
char* star = "☆";
int starNumber = 1;
int radnomForSnow;

const char* colors[] ={"\e[1;33m", "\e[0;34m", "\e[0;35m","\e[0;31m", "\e[0;95m",};
//const char* colors[] ={"\e[1;32m", "\e[0;31m", "\e[0;37m"};

char* printSpaces(){
    struct winsize w;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
        perror("ioctl");
        return "";
    }
    char* spaces = malloc(500);  // pick a size you need
    spaces[0] = '\0';  
    int random2;
    for(int i = 0; i < w.ws_col/4 + 5; i++){
        random2 = rand() %  (w.ws_col/4 + 5 + 1);
        if(i == random2){
            strcat(spaces,".");
        }else{
            strcat(spaces, " ");
        }
    }   
    return spaces;
}

int main(){
    size = 12;
    char spaces[1000];
    memset(spaces,' ', (15*3/2)-1);
    spaces[15*3/2 - 1] = '\0';

    int min2 = 0, max2 = size - 1;
    int random = rand() % (max2 - min2 + 1) + min2;
    int length = sizeof(colors)/sizeof(colors[0]);
    while(1){
        srand(time(NULL));
        int min = 0, max = length - 1;
        int number = rand() % (max - min + 1) + min;
        printf("\x1b[2J");
        printf("\x1b[H");
        printf("\033[1;37m%s\033[0m", printSpaces());

        //print the tree
        for (int y = 0; y < size; y++){
            // print the snow
            radnomForSnow = rand() % ((size - y) - 0 + 1) + 0;
            for (int s = size - y; s>=0; s--){
                if(s == radnomForSnow){
                    printf("\e[0;37m. \e[0;0m");
                }else{
                    printf(" ");
                }
            }
            //print the actuall tree
            for (int x = 0; x < y; ++x){
                number = rand() % (max - min + 1) + min;
                random = rand() % (max2 - min2 + 1) + min2;
                if(y == 1){
                    printf("\e[0;33m%s\e[0;0m", star);
                    star = "✴";
                }    
                else if(y != random && (y %2 == 0 && x%2 != 0 || (x == 0 && y%2 == 0))){
                        printf("%s%c \e[0;0m",colors[number], light);
                        light = 'O';
                }else{
                    printf("\e[0;32m* \e[0;0m");
                    light = 'o';
                }
            }
            //print the snow on the other side
            for (int s = size - y; s>=0; s--){
                if(s == radnomForSnow){
                    printf("\e[0;37m.\e[0;0m");
                }else{
                    printf(" ");
                }
            }
            printf("\033[1;37m%s\033[0m", printSpaces());
            printf("\n");
            printf("\033[1;37m%s\033[0m", printSpaces());

        }
        //print the trunk
        printf("\e[0;31m           wwWww\033[1;37m%s\033[0m\e[0;0m\n",printSpaces());
        printf("\033[1;37m%s\033[0m", printSpaces());
        printf("\e[0;31m           wwWww\033[1;37m%s\033[0m\e[0;0m\n", printSpaces());
        printf("\033[1;37m%s\033[0m", printSpaces());       
        printf("\e[0;31m   🎁      wwWww  🎁     🎁\033[1;37m%s\033[0m\e[0;0m\n", printSpaces());
        printf("\033[1;37m%s\033[0m", printSpaces());

        printf("\n");
        printf("\033[1;37m%s\033[0m", printSpaces());
        printf("\e[0;31mMerry \e[0;0m\e[0;37mChristmas\e[0;0m \e[0;31mto\e[0;0m \e[0;37mevery\e[0;0m \e[1;33mCODER\e[0;0m\n");
        printf("\033[1;37m%s\033[0m", printSpaces());
        printf("    \e[0;31mWish\e[0;0m \e[0;37myou\e[0;0m \e[0;31mhappy\e[0;0m \e[0;37mcoding!\e[0;0m");
        printf("\033[1;37m%s\033[0m", printSpaces());
        fflush(stdout);
        usleep(10000);
    }
}   
