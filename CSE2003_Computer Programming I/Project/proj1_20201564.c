#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <termios.h>
#include <sys/time.h>
#include <unistd.h>

int b[25][40]={0,}, time_out, game_over, n, m, score=0;
int movecount=0, make_block=1,block,makecount=10,x,y,blockcount=25;

void init()
{
	n = 25, m = 40;
	time_out = game_over = 0;

	b[n/2][m/4]=64;   //First bird Position
	x=n/2; y=m/4;
}

void draw_board()
{
	system("clear");
	int i,j;
	printf("\nScore : %d\n",score);
	for(i=0; i<25; i++)
   	{
       	for(j=0; j<40; j++)
       	{
          	if(b[i][j]==0)  printf(" ");    // NULL
            else if(b[i][j]==43) printf("\033[32m%c\033[0m",b[i][j]);   //bird : Red
            else if(b[i][j]==64) printf("\033[31m%c\033[0m",b[i][j]);   //blocks : Green
        }
       	printf("\n");
    }
}

int temp_val = 0;

void Do(int sig) {
	system("clear");
	printf("%d. Call Do function!", ++temp_val);

	int i,j; //control variable

   	for(i=0; i<25; i++)   // Move right per Do
    {
        for(j=0; j<39; j++)
        {
            b[i][j]=b[i][j+1];
            if(b[i][j]==64) b[i][j]=0;
        }
	b[i][39]=0; // Last Column
    }
    if(sig!=-1)            //Yes signal
    {
	  	if(b[x-2][y]==43 || x-2<0)   // Meet blocks || Out of map
		{
			game_over=1;
			return;
		}
        b[x-2][y]=64;
        x=x-2,y=y;
        movecount=1;
    }
    else if(sig==-1 && movecount==1) // No signal && Yes prev. signal
    {
		if(b[x-1][y]==43 || x-2<0)   // Meet blocks || Out of map
		{
			game_over=1;
			return;
		}
        b[x-1][y]=64;
        x=x-1,y=y;
		movecount=0;
    }
	else if(sig==-1 && movecount==0)  //No signal && No prev. signal
	{
		if(b[x+1][y]==43 || x+1>25)   // Meet blocks || Out of map
		{
			game_over=1;
			return;
		}
		b[x+1][y]=64;
		x=x+1; y=y;
	}
	int c=0,d=0;
	for(i=0; i<25; i++)     //passed blocks successful
	{
		if(b[i][y]==43) c++;
		if(b[i][y-1]==43) d++;
	}
   	if(c==15 && d==0) score++;
	if(make_block==1) // It's time to start making blocks!
    {
       	block=(rand())%15+10;
       	make_block=0;
        blockcount=25;
       	makecount=10;
  	}
	if(makecount>=1)  //Making blocks
    {
        for(i=0; i<block-10; i++)
        {
            b[i][39]=43;
        }
        for(i=block; i<25; i++)
        {
            b[i][39]=43;
        }
        makecount--;
    }
    draw_board();
	blockcount--;
	if(blockcount==0) make_block=1;   // Passed 15 without blocks
	time_out = 0;
}

int getch(void)
{
	char   ch;
	int   error;
	static struct termios Otty, Ntty;

	fflush(stdout);
	tcgetattr(0, &Otty);
	Ntty = Otty;
	Ntty.c_iflag = 0;
	Ntty.c_oflag = 0;
	Ntty.c_lflag &= ~ICANON;
#if 1
	Ntty.c_lflag &= ~ECHO;
#else
	Ntty.c_lflag |= ECHO;
#endif
	Ntty.c_cc[VMIN] = 0;
	Ntty.c_cc[VTIME] = 1;

#if 1
#define FLAG TCSAFLUSH
#else
#define FLAG TCSANOW
#endif

	if (0 == (error = tcsetattr(0, FLAG, &Ntty)))
	{
		error = read(0, &ch, 1);
		error += tcsetattr(0, FLAG, &Otty);
	}

	return (error == 1 ? (int)ch : -1);
}


int GetCommand() {
	int ch = getch();

	switch (ch)
	{
	case 'd':
	case 'D': return 0;
	case 'w':
	case 'W': return 1;
	case 'a':
	case 'A': return 2;
	case 's':
	case 'S': return 3;
	default: return -1;
	}

	return -1;
}


int main() {
	int command = -1;
	srand(time(NULL));
	static struct sigaction act, oact;
	act.sa_handler = Do;
	sigaction(SIGALRM, &act, NULL);

	init();
	draw_board();

	do {
		if (time_out == 0) {
			ualarm(200000,0); /* 20,000 = 0.2 sec, call Do function */
			time_out = 1;
		}

		command = GetCommand();
		Do(command);

	} while (!game_over);

	system("clear");
	printf("\ngame over!\n");
}
