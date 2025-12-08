#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int size;
char light = 'o';
char* star[]= {"☆", "✴"};
int starNumber = 1;
int radnomForSnow;

const char* colors[] ={"\e[1;33m", "\e[0;34m", "\e[0;35m", "\e[0;36m","\e[0;31m", "\e[0;37m", "\e[0;32m"};
//const char* colors[] ={"\e[1;32m", "\e[0;31m", "\e[0;37m"};
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
        printf("%s", spaces);

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
                    printf("\e[0;33m%s \e[0;0m", star[0]);
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
            printf("\n");
            printf("%s", spaces);
        }
        //print the trunk
        printf("\e[0;31m           wwWww\e[0;0m\n");
        printf("\e[0;31m%s           wwWww\e[0;0m\n",spaces);        
        printf("\e[0;31m%s           wwWww\e[0;0m\n",spaces);

        printf("\n");
        printf("%s", spaces);
        printf("\e[0;31mMerry \e[0;0m\e[0;37mChristmas\e[0;0m \e[0;31mto\e[0;0m \e[0;37mevery\e[0;0m \e[1;33mCODER\e[0;0m\n %s  \e[0;31mWish\e[0;0m \e[0;37myou\e[0;0m \e[0;31mhappy\e[0;0m \e[0;37mcoding!\e[0;0m\n", spaces);

        fflush(stdout);
        usleep(100000);

    }
}
