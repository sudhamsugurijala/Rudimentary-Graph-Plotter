#include <fstream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

 struct val {
 int Q[722],
     q[722];
 } v;

 int b,d,sol,n=0;

 class graph {

 public:

  void allot() {

   for (int j=0;j<722;j++)
   v.Q[j]=123;

  }

  graph() {

  sol=0;
  allot();

  clrscr();
  fstream file("menu.dat", ios::out | ios::in);
  char c;

  while(!file.eof()) {
   file.get(c);
   if(n==0) {
   delay(70);
   cout<<c;
   }
   else cout<<c;
  }
    n++;

  cout<<"\n\n Choose function 1 : ";
  cin>>b;

  if(b==1 || b==2 || b==3) {

  cout<<"\n Choose function 2 : ";
  cin>>d;

  if(d==1 || d==2 || d==3) {

 int gm,gd=DETECT;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  plot(b);
  plot(d);
  getch();
  closegraph();
  clrscr();
  cout<<"\n\n Number of solutions / Points of intersection : "<<sol;

   }   else { cout<<"\n Wrong choice!! Aborting!!";
	      delay(1000);
	      exit(0);  }
  }    else { cout<<"\n Wrong choice!! Aborting!!";
	      delay(1000);
	      exit(0);  }
 }

 void plot(int a) {

 float x,y;
 float pi=3.14159265;
 int ox=720,oy=500;

  if(a==1) {
  line(ox/2,0,ox/2,oy); // y axis
  line(0,oy/2,ox,oy/2); // x axis

   for (int i=-360;i<=360;i++) {
   x=ox/2+i;
   y=oy/2-sin(i*pi/180)*30;
   delay(1);
   putpixel(x,y,WHITE);

   v.q[i+360]=y;

   if(v.q[i+360]==v.Q[i+360]) {
    sol++;
    setcolor(RED);
    circle(x,y,4);
     }

   else  v.Q[i+360]=v.q[i+360];

   }
 }

  else if(a==2){
  line(ox/2,0,ox/2,oy); // y axis
  line(0,oy/2,ox,oy/2); // x axis

    for (int i=-360;i<=360;i++) {
    x=ox/2+i;
    y=oy/2-cos(i*pi/180)*30;
    delay(1);
    putpixel(x,y,GREEN);

   v.q[i+360]=y;

   if(v.q[i+360]==v.Q[i+360]) {
    sol++;
    setcolor(RED);
    circle(x,y,4);
     }

   else  v.Q[i+360]=v.q[i+360];
    }
  }

  else if(a==3){
  line(ox/2,0,ox/2,oy); // y axis
  line(0,oy/2,ox,oy/2); // x axis

    for (int i=-360;i<=360;i++) {
    x=ox/2+i;
    y=oy/2-tan(i*pi/180)*30;
    delay(1);
    putpixel(x,y,YELLOW);

    v.q[i+360]=y;

    if(v.q[i+360]==v.Q[i+360]) {
    sol++;
    setcolor(RED);
    circle(x,y,4);
     }

   else  v.Q[i+360]=v.q[i+360];
    }
   }
 }

 ~graph() {}

 };


 void main() {
 clrscr();
 char z='y';
 while(z=='y') {

 graph obj;

 delay(1000);
 cout<<"\n\n Try Again ? (Y/N) : ";
 cin>>z;

 }

 cout<<"\n\n Programme Terminating...";
 delay(2000);

}