#include<stdio.h>
#include<stdlib.h>
#include<math.h>

char move;
int chk;
void display();
int b[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
int mo=0,chk=0;

void gameplay();

void play(int a[4][4])
{
    int i,j,x,y,conf=0;
    char move,confirm;
    while(chk!=16&&conf!=1){

        display(a);
        scanf(" %c",&move);
        if(move=='w'||move=='s'||move=='a'||move=='d'){
            mo++;
        }

        if(move=='q'){
            printf("PRESS 'q' AGAIN TO EXIT OR ANY OTHER BUTTON TO CONTINUE\n");
            scanf(" %c",&confirm);
            if(confirm=='q'){
                conf=1;
            }
        }

        if(move=='w'){
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    if(a[i][j]==0){
                        x=i;
                        y=j;
                    }
                }
            }
            if(x!=3){
                a[x][y]=a[x+1][y];
                a[x+1][y]=0;
            }
        }


        if(move=='s'){
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    if(a[i][j]==0){
                        x=i;
                        y=j;
                    }
                }
            }
            if(x!=0){
                a[x][y]=a[x-1][y];
                a[x-1][y]=0;
            }
        }

        if(move=='a'){
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    if(a[i][j]==0){
                        x=i;
                        y=j;
                    }
                }
            }
            if(y!=3){
                a[x][y]=a[x][y+1];
                a[x][y+1]=0;
            }
        }

        if(move=='d'){
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    if(a[i][j]==0){
                        x=i;
                        y=j;
                    }
                }
            }
            if(y!=0){
                a[x][y]=a[x][y-1];
                a[x][y-1]=0;
            }
        }
        chk=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(a[i][j]==b[i][j]){
                    chk++;
                }
            }
        }
    }


    if(chk==16){
        printf("\tYOU WIN!!!\n");
        printf("\tTOTAL NO. OF MOVES:%d\n",mo);
        printf("\tTHANK YOU FOR PLAYING MY GAME\n");
    }

}


int main()
{
    int n,x,y,user=2;
    char ini,ag;
    srand(time(0));
    printf("\tWELCOME TO NUMBER SLIDE GAME\n\tPRESS 'y' TO PLAY\n\tAND 'n' TO EXIT\n");
    scanf(" %c",&ini);
    if(ini=='y')
        user=1;
    else if(ini=='n')
        user=0;
    int user1=user;

    while(user!=0){
        if(user1==1){
            mo=0;
            gameplay();
            user1=0;
        }
        if(user!=1){
            printf("\tINVALID INPUT PRESS ANY BUTTON TO CONTINUE\n");
            scanf(" %c",&ini);
            if(ini=='y'){
                user=1;
                user1=1;
            }
            else if(ini=='n'){
                user=0;
            }
            else{
                user1=0;
            }
        }

        printf("\tWOULD YOU LIKE TO PLAY AGAIN : PRESS 'y' TO PLAY OR ANY OTHER BUTTON TO EXIT\n");
        scanf(" %c", &ag);
        if(ag=='y'){
            mo=0;
            gameplay();
        }
        else{
            break;
        }



    }
    if(user==0){
        printf("\tOK! PLAY AGAIN LATER\n");
    }
    return 0;
}

void display(int a[4][4])
{
    system("clear"); //some system uses clear and others cls to clear previous output so i have used both
    system("cls");
    printf("NUMBER SLIDE GAME\n\n");
    printf("\t    w-Swipe up\n\na-Swipe left\t\td-Swipe right\n\n\t    s-Swipe down\n\n");
    printf("IF YOU WANT TO STOP PRESS 'q'\n\n");
    printf("\n\t   NO. OF MOVES: %d\n\n\n",mo);
    printf("=================================================================");
    int k=0,i,j;
    for(i=0;i<4;i++){
        printf("\n");
        printf("|\t");
        for(j=0;j<4;j++){
            if(a[i][j]==0){
                printf("\t|");
            }
            else{
                printf("%d",a[i][j]);
                printf("\t|");
            }
            printf("\t");
        }
        if(i<3){
            printf("\n");
            printf("=================================================================");
        }
    }
    printf("\n");
    printf("=================================================================");
    printf("\n");


}

void gameplay()
{
    int a[4][4]={0};
    int n,x,y;
    for(int n=1;n<16;n++){
        do
        {
            x=rand()%4;
            y=rand()%4;
        }while(a[x][y]!=0);
        a[x][y]=n;
    }
    play(a);
}


