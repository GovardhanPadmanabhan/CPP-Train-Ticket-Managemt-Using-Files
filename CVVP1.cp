#include<stdlib.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
#include<math.h>
#include<iomanip.h>




class train
{
 int trainno,nofafseat,nofasseat,noffsseat,nofacseat,nofssseat,plat;
 char trainname[60],startingpoint[60],destination[60],time[10];
 public : train()
	  {
	   plat=0;
	   trainno=0;
	   nofafseat=0;
	   nofasseat=0;
	   noffsseat=0;
	   nofacseat=0;
	   nofssseat=0;
	   strcpy(time,"/0");
	   strcpy(trainname,"/0");
	   strcpy(startingpoint,"/0");
	   strcpy(destination,"/0");
	  }

	  void input();
	  void display();

	  int returntr()
	   {return trainno;}

	  int returnaf()
	   {return nofafseat;}

	  int returnas()
	   {return nofasseat;}

	  int returnfs()
	   {return noffsseat;}

	  int returnac()
	   {return nofacseat;}

	  int returnss()
	   {return nofssseat;}

}tr;


void train::input()
{
 clrscr();
 gotoxy(10,7);
 cout<<"ENTER THE TRAIN NUMBER ";
 gotoxy(57,7);
  cin>>trainno;
 gotoxy(10,9);
 cout<<"ENTER THE NUMBER OF A/C FIRST CLASS SEATS";
 gotoxy(57,9);
  cin>>nofafseat;
 gotoxy(10,10);
 cout<<"ENTER THE NUMBER OF A/C SECOND CLASS SEATS";
 gotoxy(57,10);
  cin>>nofasseat;
 gotoxy(10,11);
 cout<<"ENTER THE NUMBER OF FIRST CLASS SLEEPER SEATS";
 gotoxy(57,11);
  cin>>noffsseat;
 gotoxy(10,12);
 cout<<"ENTER THE NUMBER OF A/C CHAIR CAR SEATS";
 gotoxy(57,12);
  cin>>nofacseat;
 gotoxy(10,13);
 cout<<"ENTER THE NUMBER OF SECOND CLASS SLEEPER SEATS";
 gotoxy(57,13);
  cin>>nofssseat;
 gotoxy(10,15);
 cout<<"ENTER THE TRAIN NAME";
 gotoxy(57,15);
  gets(trainname);
 gotoxy(10,17);
 cout<<"ENTER THE STARTING POINT ";
 gotoxy(57,17);
  gets(startingpoint);
 gotoxy(10,18);
 cout<<"ENTER THE DESTINATION ";
 gotoxy(57,18);
  gets(destination);
 gotoxy(10,20);
 cout<<"ENTER THE PLATFORM NUMBER";
 gotoxy(57,20);
  cin>>plat;
 gotoxy(10,22);
 cout<<"ENTER THE DEPARTURE TIME(in 24 hours format)";
 gotoxy(57,22);
  cin>>time;
}


void train::display ()
{
 clrscr();
 gotoxy(10,7);
 cout<<"TRAIN NUMBER ";
 gotoxy(47,7);
 cout<<trainno;
 gotoxy(10,9);
 cout<<"TRAIN NAME ";
 gotoxy(47,9);
 cout<<trainname;
 gotoxy(10,11);
 cout<<"NO OF A/C FIRST CLASS SEATS ";
 gotoxy(47,11);
 cout<<nofafseat;
 gotoxy(10,12);
 cout<<"NO OF A/C SECOND CLASS SEATS ";
 gotoxy(47,12);
 cout<<nofasseat;
 gotoxy(10,13);
 cout<<"NO OF FIRST CLASS SLEEPER SEATS ";
 gotoxy(47,13);
 cout<<noffsseat;
 gotoxy(10,14);
 cout<<"NO OF A/C CHAIR CLASS SEATS ";
 gotoxy(47,14);
 cout<<nofacseat;
 gotoxy(10,15);
 cout<<"NO OF SECOND CLASS SLEEPER SEATS ";
 gotoxy(47,15);
 cout<<nofssseat;
 gotoxy(10,17);
 cout<<"STARTING POINT ";
 gotoxy(47,17);
 cout<<startingpoint;
 gotoxy(10,18);
 cout<<"DESTINATION ";
 gotoxy(47,18);
 cout<<destination;
 gotoxy(10,20);
 cout<<"PLATFORM NUMBER ";
 gotoxy(47,20);
 cout<<plat;
 gotoxy(10,22);
 cout<<"DEPARTURE TIME ";
 gotoxy(47,22);
 cout<<time;
 gotoxy(10,33);
 cout<<"PRESS ANY KEY TO CONTINUE ";
 getch();
}


class  tickets
{
 int resno,toaf,nofaf,toas,nofas,tofs,noffs,toac,nofac,toss,nofss,age;
 char status[40],name[40];
 public: tickets();
	 int ret();
	 void reservation();
	 void cancellation();
	 void display();
}tick;


tickets::tickets()
{
 resno=0;
 toaf=0;
 nofaf=0;
 toas=0;
 nofas=0;
 tofs=0;
 noffs=0;
 toac=0;
 nofac=0;
 toss=0;
 nofss=0;
 age=0;
 strcpy(status,"/0");
 strcpy(name,"/0");
}


int tickets::ret()
{return resno;}


void tickets::display()
{
 int f=0;
 clrscr();
 ifstream fn("Ticket1.dat",ios::binary);
 fn.seekg(0);
 if(!fn)
  cout<<"ERROR IN THE FILE ";

 X:
   gotoxy(10,10);
   cout<<"ENTER THE RESERVATION NO ";
   gotoxy(10,12);
   int n;
    cin>>n;
   while(!fn.eof())
   {
    fn.read((char*)&tick,sizeof(tick));
    gotoxy(10,10);
    if(n==resno)
    {
     clrscr();
     f=1;
     gotoxy(10,10);
     cout<<"NAME ";
     gotoxy(30,10) ;
     cout<<name;
     gotoxy(10,12);
     cout<<"AGE ";
     gotoxy(30,12);
     cout<<age;
     gotoxy(10,14);
     cout<<"PRESENT STATUS ";
     gotoxy(30,14);
     cout<<status;
     gotoxy(10,16);
     cout<<"RESERVATION NUMBER ";
     gotoxy(30,16);
     cout<<resno;
     gotoxy(10,18);
     cout<<"PRESS ANY KEY TO CONTINUE ";
     getch();
    }
   }
   if(f==0)
   {
    clrscr();
    gotoxy(10,10);
    cout<<"UNRECOGINIZED RESERVATION NO !!! WANT TO RETRY ?(Y/N) ";
    char a;
    gotoxy(10,12);
     cin>>a;
    if(a=='y'||a=='Y')
    {
     clrscr();
     goto X;
    }
    else
    {
     gotoxy(10,12);
     cout<<"PRESS ANY KEY TO CONTINUE";
     getch();
    }
   }
   fn.close();
}


void tickets::reservation()
{
 clrscr();
 gotoxy(10,10);
 cout<<"RESERVATION ";
 gotoxy(10,12);
 cout<<"ENTER THE TRAIN NO: ";
 int tno,f=0;
  cin>>tno;
 ofstream file;
 ifstream fin("Train1.dat",ios::binary|ios::in);
 fin.seekg(0);
 if(!fin)
 {
  clrscr();
  gotoxy(10,10);
  cout<<"ERROR IN THE FILE ";
 }
 clrscr();
 while(!fin.eof())
 {
  fin.read((char*)&tr,sizeof(tr));
  int z;
  z=tr.returntr();
  if(tno==z)
  {
   f=1;
   nofaf=tr.returnaf();
   nofas=tr.returnas();
   noffs=tr.returnfs();
   nofac=tr.returnac();
   nofss=tr.returnss();
  }
 }
 if(f==1)
 {
  file.open("Ticket1.dat",ios::binary|ios::app);
  S:
    clrscr();
    gotoxy(10,10);
    cout<<"NAME:";
     gets(name);
    gotoxy(10,12);
    cout<<"AGE:";
     cin>>age;
    clrscr();
    gotoxy(10,6);
    cout<<"SELECT THE CLASS IN WHICH YOU WISH TO TRAVEL";
    gotoxy(10,8);
    cout<<"1.A/C FIRST CLASS ";
    gotoxy(10,10);
    cout<<"2.A/C SECOND CLASS " ;
    gotoxy(10,12);
    cout<<"3.FIRST CLASS SLEEPER " ;
    gotoxy(10,14);
    cout<<"4.A/C CHAIR CAR " ;
    gotoxy(10,16);
    cout<<"5.SECOND CLASS SLEEPER ";
    gotoxy(10,18);
    cout<<"ENTER YOUR CHOICE ";
    gotoxy(30,18);
    int c;
     cin>>c;
    switch(c)
    {
     case 1: toaf++;
	     resno=rand();
	     if((nofaf-toaf)>0)
	     {
	      strcpy(status,"confirmed");
	      gotoxy(10,20) ;
	      cout<<"STATUS";
	      gotoxy(30,20);
	      cout<<status;
	      gotoxy(10,22);
	      cout<<"RESERVATION NO";
	      gotoxy(30,22);
	      cout<<resno;
	      getch();
	      file.write((char*)&tick,sizeof(tick));
	      break;
	     }
	     else
	     {
	      strcpy(status,"pending");
	      gotoxy(10,20);
	      cout<<"STATUS";
	      gotoxy(30,20);
	      cout<<status;
	      gotoxy(10,22);
	      cout<<"RESERVATION NO";
	      gotoxy(30,22);
	      cout<<resno;
	      getch();
	      file.write((char*)&tick,sizeof(tick));
	      break;
	     }

     case 2: toas++;
	     resno=rand();
	     if((nofas-toas)>0)
	     {
	      strcpy(status,"confirmed");
	      gotoxy(10,20);
	      cout<<"STATUS";
	      gotoxy(30,20);
	      cout<<status;
	      gotoxy(10,22);
	      cout<<"RESERVATION NO";
	      gotoxy(30,22);
	      cout<<resno;
	      getch();
	      file.write((char*)&tick,sizeof(tick));
	      break;
	     }
	     else
	     {
	      strcpy(status,"pending");
	      gotoxy(10,20);
	      cout<<"STATUS";
	      gotoxy(30,20);
	      cout<<status;
	      gotoxy(10,22);
	      cout<<"RESERVATION NO";
	      gotoxy(30,22);
	      cout<<resno;
	      getch();
	      file.write((char*)&tick,sizeof(tick));
	      break;
	     }

     case 3: tofs++;
	     resno=rand();
	     if((noffs-tofs)>0)
	     {
	      strcpy(status,"confirmed");
	      gotoxy(10,20);
	      cout<<"STATUS";
	      gotoxy(30,20);
	      cout<<status;
	      gotoxy(10,22);
	      cout<<"RESERVATION NO";
	      gotoxy(30,22);
	      cout<<resno;
	      getch();
	      file.write((char*)&tick,sizeof(tick));
	      break;
	     }
	     else
	     {
	      strcpy(status,"pending");
	      gotoxy(10,20);
	      cout<<"STATUS";
	      gotoxy(30,20);
	      cout<<status;
	      gotoxy(10,22);
	      cout<<"RESERVATION NO";
	      gotoxy(30,22);
	      cout<<resno;
	      getch();
	      file.write((char*)&tick,sizeof(tick));
	      break;
	     }

     case 4: toac++;
	     resno=rand();
	     if((nofac-toac)>0)
	     {
	      strcpy(status,"confirmed");
	      gotoxy(10,20) ;
	      cout<<"STATUS";
	      gotoxy(30,20);
	      cout<<status;
	      gotoxy(10,22);
	      cout<<"RESERVATION NO";
	      gotoxy(30,22);
	      cout<<resno;
	      getch();
	      file.write((char*)&tick,sizeof(tick));
	      break;
	     }
	     else
	     {
	      strcpy(status,"pending");
	      gotoxy(10,20);
	      cout<<"STATUS";
	      gotoxy(30,20);
	      cout<<status;
	      gotoxy(10,22);
	      cout<<"RESERVATION NO";
	      gotoxy(30,22);
	      cout<<resno;
	      getch();
	      file.write((char*)&tick,sizeof(tick));
	      break;
	     }

     case 5: toss++;
	     resno=rand();
	     if((nofss-toss)>0)
	     {
	      strcpy(status,"confirmed");
	      gotoxy(10,20);
	      cout<<"STATUS";
	      gotoxy(30,20);
	      cout<<status;
	      gotoxy(10,22);
	      cout<<"RESERVATION NO";
	      gotoxy(30,22);
	      cout<<resno;
	      getch();
	      file.write((char*)&tick,sizeof(tick));
	      break;
	     }
	     else
	     {
	      strcpy(status,"pending");
	      gotoxy(10,20);
	      cout<<"STATUS";
	      gotoxy(30,20);
	      cout<<status;
	      gotoxy(10,22);
	      cout<<"RESERVATION NO";
	      gotoxy(30,22);
	      cout<<resno;
	      getch();
	      file.write((char*)&tick,sizeof(tick));
	      break;
	     }
    }
    gotoxy(10,24);
    cout<<"DO YOU WISH TO CONTINUE BOOKING TICKETS (Y/N) ? ";
    gotoxy(57,28);
    char n;
     cin>>n;
    if(n=='y'||n=='Y')
     goto S;

 }
 if(f==0)
 {
  clrscr();
  gotoxy(10,10);
  cout<<"ERROR IN THE TRAIN NUMBER ENTERED !!!";
  getch();
 }
 file.close();
 fin.close();
}


void tickets::cancellation()
{
 clrscr();
 ifstream fin;
 fin.open("Ticket1.dat",ios::binary|ios::in);
 ofstream file;
 file.open("Temp1.dat",ios::binary|ios::out|ios::app);
 fin.seekg(0);
 gotoxy(10,10);
 cout<<"ENTER THE RESERVATION NO ";
 int r,f=0;
  cin>>r;
 if(!fin)
  cout<<"ERROR IN THE FILE !!!";
 while(!fin.eof())
 {
  fin.read((char*)&tick,sizeof(tick));
  int z;
  z=tick.ret();
  if(z!=r)
   file.write((char*)&tick,sizeof(tick));
  if(z==r)
   f=1;
 }
 file.close();
 fin.close();
 remove("Ticket1.dat");
 rename("Temp1.dat","Ticket1.dat");
 if(f==0)
 {
  gotoxy(10,12);
  cout<<"NO SUCH RESERVATION IS MADE !!! PLEASE RETRY ";
  getch();
 }
 else
 {
  gotoxy(10,12);
  cout<<"RESERVATION CANCELLED";
  getch();
 }
}


void main()
{
 int ch,k;
 char j[30],n;
 clrscr();
 W:
   clrscr();
   gotoxy(35,8);
   cout<<"WELCOME";
   gotoxy(20,15);
   cout<<"GO TO";
   gotoxy(25,16);
   cout<<"1.ADMINISTRATOR SETTINGS";
   gotoxy(25,17);
   cout<<"2.TICKET BOOKING";
   gotoxy(25,18);
   cout<<"3.EXIT";
   gotoxy(20,25);
   cout<<"ENTER YOUR CHOICE ";
    cin>>k;
   if(k==1)
   {
    clrscr();
    gotoxy(20,10);
    cout<<"ENTER THE PASSWORD " ;
     gets(j);
    gotoxy(20,30);
    cout<<"CHECKING PLEASE WAIT.....";
    Y:
      if(strcmp(j,"CVV")==0)
      {
       delay(900);
       ofstream fout("Train1.dat",ios::binary|ios::app);
       tr.input();
       fout.write((char*)&tr,sizeof(tr));
       fout.close();
       gotoxy(10,25);
       cout<<"DO YOU WISH TO CONTINUE UPDATING ?(Y/N)";
       cin>>n;
       if(n=='y'||n=='Y')
	goto Y;
       else
	goto W;
      }
      else
       goto W;
   }
   if(k==2)
   {
    Z:
      clrscr();
      gotoxy(25,8) ;
      cout<<"RAILWAY TICKET RESERVATION";
      gotoxy(25,9);
      cout<<"==========================";
      gotoxy(20,13) ;
      cout<<"1.TRAIN DETAILS";
      gotoxy(20,15);
      cout<<"2.RESERVING A TICKET ";
      gotoxy(20,17);
      cout<<"3.CANCELLING A TICKET";
      gotoxy(20,19);
      cout<<"4.DISPLAY THE PRESENT TICKET STATUS ";
      gotoxy(20,21);
      cout<<"5.EXIT";
      gotoxy(20,23);
      cout<<"6.BACK";
      gotoxy(20,25);
      cout<<"\nENTER YOUR CHOICE: ";
       cin>>ch;
      switch(ch)
      {
       case 1: fstream fin("Train1.dat",ios::binary|ios::in);
	       fin.seekg(0);
	       clrscr();
	       if(!fin)
	       {
		clrscr();
		gotoxy(10,10);
		cout<<"ERROR IN THE FILE !!!";
	       }
	       else
	       {
		clrscr();
		while(!fin.eof())
		{
		 fin.read((char*)&tr,sizeof(tr));
		 tr.display();
		}
	       }
	       fin.close();
	       goto Z;

       case 2: tick.reservation();
	       goto Z;

       case 3: tick.cancellation();
	       goto Z;

       case 4: tick.display();
	       goto Z;

       case 5: exit(0);

       case 6: goto W;
      }
      getch();
   }

   if(k==3)
    exit(0);
}