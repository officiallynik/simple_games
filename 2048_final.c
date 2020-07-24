#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
int score=0,confirm=0;
char in,conf,userin;
int a[4][4];
void getno();
int chk();
int p=1;
int sc=0;
void move(char);
void display();

int main()
{
    int x,y;
    for(x=0;x<4;x++)
        for(y=0;y<4;y++)
            a[x][y]=0;

    printf("\tWELCOME TO 2048\n");
    printf("\tARE U READY TO PLAY!  PRESS 'y'\n\tWANNA EXIT PRESS 'n'\t\t\t");
    scanf("%c",&in);
    while(in!='n'){
        if(in=='y'){
            while(chk()==1)
            {
                if(confirm==1)
                    exit(0);

                getno();
                display();
                scanf("%c",&userin);
                fflush(stdin);//to clear the output buffer and move buffered data to console
                move(userin);

            }
            if(chk()==0)
            {
                system("cls");
                system("clear");  //some system uses clear and others cls to clear previous output so i have used both
                printf("\tTOUGH LUCK!!! GAME OVER\n");
                printf("\tYOUR FINAL SCORE: %d",sc);
                printf("\n\tTHANK YOU FOR PLAYING MY GAME\n");
                exit(0);
            }
        }
        if(in!='y')
        {
            printf("\tPLEASE ENTER VALID INPUT\n");
            scanf(" %c",&in);
        }

    }
    if(in=='n')
    {
        printf("\n\tOK! COME BACK LATER");
    }

}
void move(char ch)
{
    if(ch=='d')
    {
        int i,j,x,y;
        for(y=0;y<4;y++)
            {
                for(x=3;x>0;x--)
                {
                    for(i=0;i<x;i++)
                    {
                        for(j=3;j>0;j--)
                        {
                            if(a[y][j]==0)
                            {
                                a[y][j]=a[y][j-1];
                                a[y][j-1]=0;
                            }
                        }
                    }
                    if(a[y][x]==a[y][x-1])
                    {
                        a[y][x] = a[y][x] + a[y][x-1];
                        a[y][x-1]=0;

                    }
                }
            }
    }


    else if(ch=='a')
    {
        int i,j,x,y;
        for(y=0;y<4;y++)
            {
                for(x=0;x<3;x++)
                {
                    for(i=0;i<3;i++)
                    {
                        for(j=0;j<3;j++)
                        {
                            if(a[y][j]==0)
                            {
                                a[y][j]=a[y][j+1];
                                a[y][j+1]=0;
                            }
                        }
                    }
                    if(a[y][x]==a[y][x+1])
                    {
                        a[y][x] += a[y][x+1];
                        a[y][x+1]=0;

                    }
                }
            }
    }

    else if(ch=='w')
    {
        int x,y,i,j;
        for(x=0;x<4;x++)
            {
                for(y=0;y<3;y++)
                {
                    for(j=0;j<3;j++)
                    {
                        for(i=0;i<3;i++)
                        {
                            if(a[i][x]==0)
                            {
                                a[i][x]=a[i+1][x];
                                a[i+1][x]=0;
                            }
                        }
                    }
                    if(a[y][x]==a[y+1][x])
                    {
                        a[y][x]=a[y][x]+a[y+1][x];
                        a[y+1][x]=0;
                    }
                }
            }
    }

    else if(ch=='s')
    {
        int i,j,x,y;
        for(x=0;x<4;x++)
            {
                for(y=3;y>0;y--)
                {
                    for(j=0;j<3;j++)
                    {
                        for(i=3;i>0;i--)
                        {
                            if(a[i][x]==0)
                            {
                                a[i][x]=a[i-1][x];
                                a[i-1][x]=0;
                            }
                        }
                    }
                    if(a[y][x]==a[y-1][x])
                    {
                        a[y][x]=a[y][x]+a[y-1][x];
                        a[y-1][x]=0;

                    }
                }
            }
    }

    else if(ch=='q'){
        printf("\tPRESS 'q' AGAIN TO EXIT OR ANY OTHER BUTTON TO CONTINUE\n");
        scanf(" %c",&conf);
        if(conf=='q'){
            system("clear");
            system("cls");//some system uses clear and others cls to clear previous output so i have used both
            printf("\tFINAL SCORE: %d\n",sc);
            printf("\n\tTHANK YOU FOR PLAYING MY GAME\n");
            confirm=1;
        }
        else{

            printf("\tOK CONTINUE PLAYING\n");
            scanf(" %c",&userin);
            fflush(stdin);
            move(userin);
        }
    }

}
void getno()
{
    int x,y;
    int no=2,scc=0;
    if(p==1)
    {
        score=0;
        p=0;
    }
    else
    {
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scc=a[i][j]+scc;
            }

        }
        sc=scc+sc;
    }
    do
    {
        x=rand()%4;
        y=rand()%4;
    }while(a[x][y]!=0);
    a[x][y]=no;
}

int chk()
{
    int i,j,m,f=1;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(a[i][j]==0){
                f=0;
            }
        }
    }
    if(f==0)
        return 1;
    else
        return 0;
}

void display()
{
    system("clear");
    system("cls");//some system uses clear and others cls to clear previous output so i have used both
    printf("2048\n\n");
    printf("\t    w-Swipe up\n\na-Swipe left\t\td-Swipe right\n\n\t    s-Swipe down\n\n");
    printf("\t   PRESS 'q' TO EXIT\n\n");
    printf("\n\t   YOUR SCORE: %d\n\n\n",sc);
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
