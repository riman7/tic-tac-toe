#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <graphics.h>
using namespace std;

void design()
{
    settextstyle(10,0,6);
    int w=textwidth("Tic Tac Toe");
    outtextxy((400-w)/2,80,"Tic Tac Toe");
	line(160,220,160,460);
	line(160+1,220,160+1,460);
	line(160-1,220,160-1,460);

	line(80,300,320,300);
	line(80,300+1,320,300+1);
	line(80,300-1,320,300-1);

	line(80,380,320,380);
	line(80,380+1,320,380+1);
	line(80,380-1,320,380-1);

	line(240,220,240,460);
	line(240+1,220,240+1,460);
	line(240-1,220,240-1,460);

    settextstyle(10,0,2);
    int h=textheight("By Riman Maharjan and Sufal KC...");
    w=textwidth("By Riman Maharjan and Sufal KC...");
    outtextxy(400-w-5,600-h,"By Riman Maharjan and Sufal KC...");
}

//Turn 1 = x, 0 = O
void dis(int turn, int p)
{
    settextstyle(10,0,6);
    int w=0,h=0;
    if(turn==1){
        h=textheight("X");
        w=textwidth("X");
    }
    else{
        h=textheight("O");
        w=textwidth("O");
    }
    //space on each side of O or X (for centering)
    int x=(80-w)/2;
    int y=(80-h)/2;
    switch(p)
    {
    	//Turn 1 = x, 0 = O
        case 1:
            if(turn==1)
                outtextxy(x+80,y+220,"X");
            else
                outtextxy(x+80,y+220,"O");
            break;
        case 2:
            if(turn==1)
                outtextxy(x+160,y+220,"X");
            else
                outtextxy(x+160,y+220,"O");
            break;
        case 3:
            if(turn==1)
                outtextxy(x+240,y+220,"X");
            else
                outtextxy(x+240,y+220,"O");
            break;
        case 4:
            if(turn==1)
                outtextxy(x+80,y+300,"X");
            else
                outtextxy(x+80,y+300,"O");
            break;
        case 5:
            if(turn==1)
                outtextxy(x+160,y+300,"X");
            else
                outtextxy(x+160,y+300,"O");
            break;
        case 6:
            if(turn==1)
                outtextxy(x+240,y+300,"X");
            else
                outtextxy(x+240,y+300,"O");
            break;
        case 7:
            if(turn==1)
                outtextxy(x+80,y+380,"X");
            else
                outtextxy(x+80,y+380,"O");
            break;
        case 8:
            if(turn==1)
                outtextxy(x+160,y+380,"X");
            else
                outtextxy(x+160,y+380,"O");
            break;
        case 9:
            if(turn==1)
                outtextxy(x+240,y+380,"X");
            else
                outtextxy(x+240,y+380,"O");
            break;

    }
}

int fun(char *a){
    // return || 0 for no result || 1 for player 1 || 2 for player 2

    //diagonal check
    if((a[0]==a[4] && a[0]==a[8] && a[0]=='X') || (a[2]==a[4] && a[2]==a[6] && a[2]=='X'))
        return 1;
    else if((a[0]==a[4] && a[0]==a[8] && a[0]=='O') || (a[2]==a[4] && a[2]==a[6] && a[2]=='O'))
        return 2;

    // horizontal check
    if((a[0]==a[1] && a[1]==a[2] && a[0]=='X') || (a[3]==a[4] && a[4]==a[5] && a[3]=='X') || (a[6]==a[7] && a[7]==a[8] && a[6]=='X'))
        return 1;
    else if((a[0]==a[1] && a[1]==a[2] && a[0]=='O') || (a[3]==a[4] && a[4]==a[5] && a[3]=='O') || (a[6]==a[7] && a[7]==a[8] && a[6]=='O'))
        return 2;

    //vertical check
    if((a[0]==a[3] && a[3]==a[6] && a[0]=='X') || (a[1]==a[4] && a[4]==a[7] && a[1]=='X') || (a[2]==a[5] && a[5]==a[8] && a[2]=='X'))
        return 1;
    if((a[0]==a[3] && a[3]==a[6] && a[0]=='O') || (a[1]==a[4] && a[4]==a[7] && a[1]=='O') || (a[2]==a[5] && a[5]==a[8] && a[2]=='O'))
        return 2;
    return 0;
}
//a => array of state of board(O X 0)
void computer(char *a,int turn){
	//cnt-> O cell count, p-> empty cell count
    int cnt[8],p[8];
    for(int i=0;i<8;i++){
        cnt[i]=0;p[i]=-1;
    }
    // attack
    for(int i=0;i<9;i++){
        if(a[i]=='O'){
            cnt[i/3]++;
            //cnt 0,1,2 for horizontal
            cnt[3+i%3]++;
            //cnt 3,4,5 for vertiacal
            if(i%4==0)
                cnt[6]++;
            //cnt 6 for 1st diagnoal
            if(i==2 || i==4 || i==6)
                cnt[7]++;
            //cnt 7 for 2nd diagonal
        }
        //empty cell record
        else if(a[i]==0){
            p[i/3]=i;
            p[3+i%3]=i;
            if(i%4==0)
                p[6]=i;
            if(i==2 || i==4 || i==6)
                p[7]=i;
        }
    }
    //attack
    for(int i=0;i<8;i++){
        if(cnt[i]==2 && p[i]!=-1){
            dis(0,p[i]+1);
            a[p[i]]='O';
            return;
        }
        p[i]=-1;cnt[i]=0;
    }
    // defend
    for(int i=0;i<9;i++){
        if(a[i]=='X'){
            cnt[i/3]++;
            cnt[3+i%3]++;
            if(i%4==0)
                cnt[6]++;
            if(i==2 || i==4 || i==6)
                cnt[7]++;
        }
        else if(a[i]==0){
            p[i/3]=i;
            p[3+i%3]=i;
            if(i%4==0)
                p[6]=i;
            if(i==2 || i==4 || i==6)
                p[7]=i;
        }
    }
    for(int i=0;i<8;i++){
        if(cnt[i]==2 && p[i]!=-1){
            dis(0,p[i]+1);
            a[p[i]]='O';
            return;
        }
        p[i]=-1;cnt[i]=0;
    }
    //center choice
    if(a[4]==0){
        dis(0,5);
        a[4]='O';
        return;
    }
    //if none is matching
    for(int i=0;i<9;i++){
        if(a[i]==0){
            dis(0,1+i);
            a[i]='O';
            return;
        }
    }
}

int main()
{
    //Tic Tac Toe
    start:
    //400pixel in x-axis and 600 pixel in y-axis dialogue will init
    initwindow(400,600,"Tic Tac Toe");
    //create layout of cpp using defined function using cpp
    design();
    //x= 0 no-result, 1-player 1, 2-player 2
    int x=0;
    POINT pos;
    int turn=0;
    char b[9]={0};
    for(int i=0;i<9;i++)
        b[i]=0;
    settextstyle(10,0,3);
    int w=textwidth("Your Turn !!");
    outtextxy((400-w)/2,500,"Your Turn !!");
    while(x==0 && turn<=9)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&pos);
            long X=mousex();
            long Y=mousey();
            int mov=0;
            if(turn%2==0){
                if(X>80 && X<160 && Y>220 && Y<300 && b[0]==0)     //b1
                {
                    dis(1,1);
                    mov=1;
                    b[0]='X';
                }
                else if(X>160 && X<240 && Y>220 && Y<300 && b[1]==0)     //b2
                {
                    dis(1,2);
                    mov=1;
                    b[1]='X';
                }
                else if(X>240 && X<320 && Y>220 && Y<300 && b[2]==0)     //b3
                {
                    dis(1,3);
                    mov=1;
                    b[2]='X';
                }
                else if(X>80 && X<160 && Y>300 && Y<380 && b[3]==0)     //b4
                {
                    dis(1,4);
                    mov=1;
                    b[3]='X';
                }
                else if(X>160 && X<240 && Y>300 && Y<380 && b[4]==0)     //b5
                {
                    dis(1,5);
                    mov=1;
                    b[4]='X';
                }
                else if(X>240 && X<320 && Y>300 && Y<380 && b[5]==0)     //b6
                {
                    dis(1,6);
                    mov=1;
                    b[5]='X';
                }
                else if(X>80 && X<160 && Y>380 && Y<460 && b[6]==0)     //b7
                {
                    dis(1,7);
                    mov=1;
                    b[6]='X';
                }
                else if(X>160 && X<240 && Y>380 && Y<460 && b[7]==0)     //b8
                {
                    dis(1,8);
                    mov=1;
                    b[7]='X';
                }
                else if(X>240 && X<320 && Y>380 && Y<460 && b[8]==0)     //b9
                {
                    dis(1,9);
                    b[8]='X';
                    mov=1;
                }
                if(mov){
                    turn++;
                    x=fun(b);
                    delay(200);
                    if(x!=0 || turn==9)
                        break;
                    // computers turn
                    computer(b,turn);
                    turn++;
                    x=fun(b);
                }
            }
        }
    }
    cout<<"Thank You !!";
    if(x==1){
        settextstyle(10,0,3);
        int w=textwidth("You Wins !!");
        outtextxy((400-w)/2,500,"You Wins !!");
        w=textwidth("Play Again");
        int h=textheight("Play Again");
        outtextxy((400-w)/2,522,"Play again");
        while(true){
	        if(GetAsyncKeyState(VK_LBUTTON))
	        {
	            GetCursorPos(&pos);
	            long X=mousex();
	            long Y=mousey();
	            if(X>(400-w)/2&& X<((400-w)/2)+w && Y>522-h && Y< 522+h){
	            	goto start;
	            	break;
				}
	        }
    }
}
    else if(x==2){
        settextstyle(10,0,3);
        int w=textwidth("Computer Wins !!");
        outtextxy((400-w)/2,500,"Computer Wins !!");
        w=textwidth("Play Again");
        int h=textheight("Play Again");
        outtextxy((400-w)/2,522,"Play again");
        while(true){
	        if(GetAsyncKeyState(VK_LBUTTON))
	        {
	            GetCursorPos(&pos);
	            long X=mousex();
	            long Y=mousey();
	            if(X>(400-w)/2&& X<((400-w)/2)+w && Y>522-h && Y< 522+h){
	            	goto start;
	            	break;
				}
	        }
    }
}
    else if(x==0){
        settextstyle(10,0,3);
        int w=textwidth("Its a Draw !!");
        outtextxy((400-w)/2,500,"Its a Draw !!");
        w=textwidth("Play Again");
        int h=textheight("Play Again");
        outtextxy((400-w)/2,522,"Play again");
        while(true){
	        if(GetAsyncKeyState(VK_LBUTTON))
	        {
	            GetCursorPos(&pos);
	            long X=mousex();
	            long Y=mousey();
	            if(X>(400-w)/2&& X<((400-w)/2)+w && Y>522-h && Y< 522+h){
	            	goto start;
	            	break;
				}
	        }
	
    }
}
    getch();
    return 0;
}
