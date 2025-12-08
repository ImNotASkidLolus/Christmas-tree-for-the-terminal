#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <string.h>

int size;
char light = 'o';

//const char* colors[] ={"\e[1;33m", "\e[0;34m", "\e[0;35m", "\e[0;36m","\e[0;31m", "\e[0;37m", "\e[0;32m"};
const char* colors[] ={"\e[1;32m", "\e[0;31m", "\e[0;37m"};
int main(){
    struct winsize w;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
        perror("ioctl");
        return 1;
    }
    size = w.ws_col/5;

    char spaces[size*3/2];
    memset(spaces,' ', (size*3/2)-1);
    spaces[size*3/2 - 1] = '\0';

    int min2 = 0, max2 = size - 1;
    int random = rand() % (max2 - min2 + 1) + min2;

    int length = sizeof(colors)/sizeof(colors[0]);
    while(1){
        srand(time(NULL));
        int min = 0, max = length - 1;
        int number = rand() % (max - min + 1) + min;

        random = rand() % (max2 - min2 + 1) + min2;
        printf("\x1b[2J");
        printf("\x1b[H");
        printf("%s", spaces);

        //print the trees
        //print the rest of the tree
        for (int y = 0; y < size; y++){
            int radnomForSnow = rand() % ((size - y) - 0 + 1) + 0;
            for (int s = size - y; s>=0; s--){
                if(s == radnomForSnow){
                    printf("\e[0;37m.\e[0;0m");
                }else{
                    printf(" ");
                }
            }
            for (int x = 0; x < y; ++x){
                number = rand() % (max - min + 1) + min;
                if(y == 1){
                    printf("\e[0;33m# \e[0;0m");
                }else if((y != random && (y % 2 == 0 && x%2 == 0)) || (x != random && x % 3 == 0 && y % 2 == 0)){
                    printf("%s%c \e[0;0m",colors[number], light);
                }else{
                    printf("\e[0;32m* \e[0;0m");
                }
            }
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
        for(int i = 0; i < size/4; i++){
            for (int s = size/2 + 1*size/4; s >= 0; s--){
                printf(" ");
            }
            for (int j = 0; j < size/4; j++){
                printf("\e[0;31m* \e[0;0m");
            }
            printf("\n");
            printf("%s", spaces);
        }

        fflush(stdout);
        usleep(100000);
        printf("\x1b[2J");
        printf("\x1b[H");
        printf("%s", spaces);

        //print the trees
        //print the rest of the tree
        for (int y = 0; y < size; y++){
            int radnomForSnow = rand() % ((size - y) - 0 + 1) + 0;
            for (int s = size - y; s>=0; s--){
                if(s == radnomForSnow){
                    printf("\e[0;37m.\e[0;0m");
                }else{
                    printf(" ");
                }
            }
            for (int x = 0; x < y; ++x){
                number = rand() % (max - min + 1) + min;
                if(y == 1){
                    printf("\e[0;33m# \e[0;0m");
                }else if((y != random && y % 2 == 0 && x%2 == 0) || (x != random && x % 3 == 0 && y % 2 == 0)){
                    printf("%s%c \e[0;0m",colors[number], light);
                }else{
                    printf("\e[0;32m* \e[0;0m");
                }
            }
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
        for(int i = 0; i < size/4; i++){
            for (int s = size/2 + 1*size/4; s >= 0; s--){
                printf(" ");
            }
            for (int j = 0; j < size/4; j++){
                printf("\e[0;31m* \e[0;0m");
            }
            printf("\n");
            printf("%s", spaces);
        }

        fflush(stdout);
        usleep(100000);
    }
}
