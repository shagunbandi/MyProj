/*
		 &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
		 & COMPUTER SCIENCE PROJECT WORK &
		 &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

	      SOFTWARE FOR THE USE IN COMPUTERS SHOP

		      ***INTRODUCTION***

		     /////////////////////////////
			 NAME:- SHAGUN BANDI
		       CLASS:- XII   SEC:- 'B'
		     /////////////////////////////

			####################
			#  iNSPiRE APPLE   #
			####################

/*
		      ### HEADER FILES ###
*/
#include<fstream.h>    //for reading and writing files
#include<conio.h>      //for clrscr()
#include<string.h>     //for string characters
#include<stdio.h>      //for gets and puts function
#include<process.h>    //for exit function
#include<iomanip.h>    //for setw function
#include<dos.h>        //for delay and sleep function

class consumer
{
	int cno;
	char cname[20];
	char adress[20];
	char sn[9],scn[9],bn[9],pn[9];
	float i;
	public:

	//FUNCTION TO ENTER THE VALUES

	public:
	void entry()
	{
		clrscr();
		gotoxy(32,4);
		cputs("iNSPiRE APPLE");
		gotoxy(5,8);
		cputs("Customer ID :");
		gotoxy(5,10);
		cputs("Customer name :");
		gotoxy(5,12);
		cputs("Customer adress :");
		gotoxy(5,14);
		cputs("Customer Service number :");
		gotoxy(5,16);
		cputs("Costumer Smart card number :");
		gotoxy(5,18);
		cputs("Costumer Phone number :");
		gotoxy(5,20);
		cputs("Customer Bill number :");
		gotoxy(45,8);
		cin>>cno;
		gotoxy(45,10);
		gets(cname);
		gotoxy(45,12);
		gets(adress);
		gotoxy(45,14);
		gets(sn);
		gotoxy(45,16);
		gets(scn);
		gotoxy(45,18);
		gets(pn);
		gotoxy(45,20);
		gets(bn);
	}
	//FUNCTION TO DISPLAY THE VALUES
	void display()
	{
		cout<<"\n\n\tCustomer ID :\t\t\t"<<cno;
		cout<<"\n\n\tCustomer name :\t\t\t"<<cname;
		cout<<"\n\n\tCustomer adress :\t\t"<<adress;
		cout<<"\n\n\tCustomer Service number :\t"<<sn;
		cout<<"\n\n\tCostumer Smart card number :\t"<<scn;
		cout<<"\n\n\tCostumer Phone number :\t\t"<<pn;
		cout<<"\n\n\tCustomer Bill number :\t\t"<<bn;
		cout<<endl;
	}

	int rcno()
	{
		return cno;
	}

//FUNCTION TO WRITE THE VALUES

void write()
{
	char ch;
	consumer c;
	fstream f1;
	c.entry();
	f1.open("iNSPiRE APPLE.dat",ios::app|ios::binary);
	f1.write((char*)&c,sizeof(c));
	f1.close();
}

//FUNCTION TO READ THE VALUES

void read()
{
	consumer c;
	fstream f1;
	f1.open("iNSPiRE APPLE.dat",ios::in|ios::binary);
	while(f1.read((char*)&c,sizeof(c)))
	{
		
		c.display();
		if(f1.eof())
		cout<<"\n\n   End of the file reached\n\n";
	}
	f1.close();
}

//FUNCTION FOR SEARCHING THE RECORD

void search()
{
	consumer c;
	int rn;
	char found='n';
	ifstream f1("iNSPiRE APPLE.dat",ios::in);
	cout<<"\n\n Enter Customer ID you want to SEARCH :\t";
	cin>>rn;
	while(!f1.eof())
	{
		f1.read((char*)&c,sizeof(c));
		if(c.rcno()==rn)
		{
			c.display();
			found='y';
			break;
		}
	}
	if(found=='n')
	cout<<"\n\n\tRECORD NOT FOUND!!!!!!!!!!!!!\n"<<endl;
	f1.close();
}

//FUNCTION TO DELELTE THE RECORD

void del()
{
	ifstream f1("iNSPiRE APPLE.dat",ios::in);
	ofstream f2("temp.dat",ios::out);
	int rno;
	char found='f',confirm='n';
	cout<<"\n\n Enter Customer ID you want to DELETE :\t";
	cin>>rno;
	while(!f1.eof())
	{
		f1.read((char*)&c,sizeof(c));
		if(c.rcno()==rno)
		{
			c.display();
			found='t';
			cout<<"\n\n Are you sure want to DELETE this record ? (y/n)\t";
			cin>>confirm;
			if(confirm=='n')
			f2.write((char*)&c,sizeof(c));
		}
		else
		f2.write((char*)&c,sizeof(c));
	}
	if(found=='f')
	cout<<"\n\n\tRECORD NOT FOUND\n";
	f1.close();
	f2.close();
	remove("iNSPiRE APPLE.dat");
	rename("temp.dat","iNSPiRE APPLE.dat");
	f1.open("iNSPiRE APPLE.dat",ios::in);
	clrscr();
	cout<<"\n\n\n Now the file contains\n\n\n";
	while(!f1.eof())
	{
		f1.read((char*)&c,sizeof(c));
		if(f1.eof())
		c.display();
	}
	f1.close();
}

//FUNCTION TO MODIFY THE RECORD

void update()
{
	fstream f1("iNSPiRE APPLE.dat",ios::in | ios::out | ios::binary);
	int rno;
	long pos;
	char found='f';
	cout<<"\n\n Enter the Customer ID you want to MODIFY :\t";
	cin>>rno;
	while(!f1.eof())
	{
		pos=f1.tellg();
		f1.read((char*)&c,sizeof(c));
		if(c.rcno()==rno)
		{
			c.entry();
			f1.seekg(pos);
			f1.write((char*)&c,sizeof(c));
			found='t';
			break;
		}
	}
	if(found=='f')
	cout<<"\n\n\tRECORD NOT FOUND\n";
	f1.seekg(0);
	clrscr();
	cout<<"\n Now the file contains\n\n";
	c.display();
	f1.close();
	getch();
}

//STARTING OF THE VOID MAIN

void main()
{
	unsigned d,j,choice;
	char sn[9],scn[9],bn[9],pn[9];
	unsigned long int sum=0,add=0,total=0,e,f,g,h,i,k,l,w,x,y,z;
	long int npod=1000,npho=500,npad=500,nmac=500,AppWat=1000,MagMou=2000,AppKey=2000,AppEar=1000;
	unsigned int m=0,n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0;
	long int iPod=0,ipad=0,awa=0,mam=0,apk=0,ape=0,p1=0,p2=0,g1=0,j1=0,mac=0,imac=0,iph=0,ipho=0;
	char pu,str[10],yes,et;
	clrscr();

	// WELCOME SCREEN

	clrscr();
	lab:;
	clrscr();
	gotoxy(1,6);
	cputs("                          COMPUTER SCIENCE PROJECT WORK                         \n");
	printf("                                                                                \n");
	printf("********************************************************************************");
	cout<<"\n";
	cputs ("                       !!!!  WELCOME TO iNSPiRE APPLE !!!!                      \n");
	printf("********************************************************************************\n");
	printf("********************************************************************************\n");
	gotoxy(2,18);
	cputs("                       SCHOOL:-VIDYA BHAVAN PUBLIC SCHOOL                       \n");
	cout<<"\n";
	printf("********************************************************************************\n");
	printf("********************************************************************************\n");
	gotoxy(1,25);
	cputs("                        SUBJECT TEACHER:-MRS. DEEPA SANIL                       ");
	cout<<"\n\n";
	printf("********************************************************************************\n");
	printf("********************************************************************************\n");
	gotoxy(1,32);
	cputs("                              BY:- SHAGUN BANDI                         \n");
	gotoxy(1,34);
	cputs("                                 CLASS:- XII                                  \n");
	gotoxy(1,36);
	cputs("                              YEAR:- 2013-2014                            \n");
	cout<<"\n\n";
	printf("********************************************************************************\n");
	printf("********************************************************************************\n");
	cout<<"\n\n";
	gotoxy(12,48);
	cputs("PRESS ENTER TO CONTINUE!!!!!!");
	getch();
	clrscr();

	//DETAILS OF THIS PROJECT

	gotoxy(5,5);
	cputs("WELCOME TO THE WORLD OF TECHNOLOGY .");
	gotoxy(5,10);
	cputs("THIS PROJECT CONTAINS SOME ITEMS AND SIMPLE THING YOU HAVE TO DO IS:-");
	gotoxy(5,12);
	cputs("ENTER THE NAME , CUSTOMER ID , SERIAL NUMBER , SMART CARD NUMBER etc.");
	gotoxy(5,14);
	cputs("THEN PURCHASE THE ITEMS AND REMEMBER THE QUANTITY ITEMS CARRY.");
	gotoxy(5,16);
	cputs("YOU CAN ALSO MODIFY , DELETE , SEARCH A RECORD.");
	gotoxy(5,18);
	cputs("YOU CAN ALSO ALL RECORDS YOU HAVE ENTERED IN YOUR COMPUTER.");
	gotoxy(5,20);
	cputs("BUT DO NOT EXPECT FOR ANY DISCOUNT.");
	gotoxy(5,22);
	cputs("WE HOPE THAT YOU WILL BE SATISFIED WITH OUR SERVICE.");
	gotoxy(5,24);
	cputs("FOR ANY COMPLAINS LOG INTO OUR OFFICIAL WEBSITE 'www.apple.co.in'");
	getch();
	clrscr();

	//LOADING THE PROJECT

	gotoxy(32,9);
	cputs("********************");
	gotoxy(32,11);
	cputs("LOADING YOUR PROJECT");
	gotoxy(32,13);
	cputs("********************");
	gotoxy(32,15);
	cputs("PLEASE WAIT.........");
	delay(500);
	gotoxy(32,35);
	cputs("10 % completed..");
	delay(500);
	gotoxy(32,35);
	cputs("20 % completed...");
	delay(500);
	gotoxy(32,35);
	cputs("30 % completed....");
	delay(500);
	gotoxy(32,35);
	cputs("40 % completed.....");
	delay(500);
	gotoxy(32,35);
	cputs("50 % completed......");
	delay(500);
	gotoxy(32,35);
	cputs("60 % completed.......");
	delay(500);
	gotoxy(32,35);
	cputs("70 % completed........");
	delay(500);
	gotoxy(32,35);
	cputs("80 % completed.........");
	delay(500);
	gotoxy(32,35);
	cputs("90 % completed..........");
	delay(500);
	gotoxy(32,35);
	cputs("100 % completed...........");
	delay(500);

	// TO PURCHASE ,SEARCH ,MODIFY ,DELETE ,DISPLAY ALL RECORDS ,DETAILS ,NEW CUSTOMER

	again:;
	clrscr();
	cout<<"\n\t\t\t    ^^^^^^^^^^^^^^^^^^^^^^^^^^^";
	cout<<"\n\t\t\t    !=========================!\n";
	cout<<"\n\t\t\t    !****  iNSPiRE APPLE  ****!\n";
	cout<<"\n\t\t\t    !=========================!";
	cout<<"\n\t\t\t    ^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n\n\n";
	cout<<"  \t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
	cout<<"\n\n\t\t\t*     1.NEW CUSTOMER              *";
	cout<<"\n\n\t\t\t*     2.DETAILS                   *";
	cout<<"\n\n\t\t\t*     3.SEARCH A RECORD           *";
	cout<<"\n\n\t\t\t*     4.DELETE A RECORD           *";
	cout<<"\n\n\t\t\t*     5.MODIFY A RECORD           *";
	cout<<"\n\n\t\t\t*     6.DISPLAY ALL RECORDS       *";
	cout<<"\n\n\t\t\t*     7.QUANTITY AVAILABLE        *";
	cout<<"\n\n\t\t\t*     0.EXIT                      *\n";
	cout<<"\n\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
	cout<<"\n\n\n\n\t Enter your choice :\t";
	cin>>d;
	switch(d)
	{
	case 1:
	clrscr();
	cout<<"\n\n\n\t\t\t iNSPiRE APPLE";
	cout<<"\n\n\n\t\t\t COSUMER INFORMATION";

	// TO ENTER THE DETAILS OF THE COSTUMER

	write();

	// ITEMS AND THIER RATES

	start:
	cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N):\n\n";
	cin>>pu;
	if(pu=='Y'||pu=='y')
	{
		clrscr();

		// PURCHASE LIST

		items:;
		cout<<"\n\t\t\t\t*************";
		cout<<"\n\t\t\t\tPURCHASE LIST";
		cout<<"\n\t\t\t\t*************\n\n\n\n";
		cout<<"\n\n\t\t\t1.ipod";
		cout<<"\n\n\t\t\t2.iphone";
		cout<<"\n\n\t\t\t3.iPad";
		cout<<"\n\n\t\t\t4.iMac";
		cout<<"\n\n\t\t\t5.Other Accessories ";
		cout<<"\n\n\n\t\t\tEnter your choice\t";
		cin>>choice;

		//DETAILS OF iPOD

		if(choice==1)
		{

			//ITEMS AND RATES

			loop1:;
			clrscr();
			cout<<"\n\n\t\t\t\tiPod\n\n";
			cout<<"\n     ITEMS\t\t\t\t\t\tRATE\n\n";
			cout<<"  1. iPod Shuffle 2  GB\t\t\t\t\t3700\n";
			cout<<"  2. iPod Nano    16 GB\t\t\t\t\t11900\n";
			cout<<"  3. iPod Touch   16 GB\t\t\t\t\t16900\n";
			cout<<"  4. iPod Touch   32 GB\t\t\t\t\t20900\n";
			cout<<"  5. iPod touch   64 Gb\t\t\t\t\t24900\n";

			cout<<"\n\n\tWhich iPod you want to purchase\t";
			cin>>p1;
			if(p1==1)
			{
			iPod=3700;
			}
			else if(p1==2)
			{
			iPod=11900;
			}
			else if(p1==3)
			{
			iPod=16900;
			}
			else if (p1==4)
			{
			iPod=16900;
			}
			else if(p1==5)
			{
			iPod=20900;
			}
			else if(p1==6)
			{
			iPod=24900;
			}
			else if(p1==0)
			{
			goto items;
			}
			else if(p1!=1||p1!=2||p2!=3||p1!=4||p1!=5||p1!=6)
			{
				cout<<"\n\n\t\tOOPS!!!!!!!  Wrong choice\n\n";
				getch();
				goto loop1;
			}
			cout<<"\n\tQUANTITY: \t";
			cin>>m;
			npod-=m;
			cout<<"\n\tDo you want to purchase more(y/n)";
			cin>>yes;
			if(yes=='y')
			{
				clrscr();
				goto items;
			}
			else
			{
				clrscr();
				goto cash;
			}
		}

		//DETAILS OF iPHONE

		if(choice==2)
		{
			loop2:;
			clrscr();
			cout<<"\n\n\t\t\t\tiPhone\n\n";
			cout<<"\n    ITEMS\t\t\t\t\tRATE\n\n";
			cout<<"  1.iPhone 6 Plus\t\t\t\t55000\n";
			cout<<"  2.iPhone 6     \t\t\t\t49000\n";
			cout<<"  3.iPhone 5s    \t\t\t\t44000\n";
			cout<<"  4.iPhone 5c    \t\t\t\t35000\n";
			cout<<"  5.iPhone 4s    \t\t\t\t24000\n";
			cout<<"\n\n\tWhich iPhone do you want to purchase\t";
			cin>>ipho;
			if(ipho==1)
			{
			iph=55000;
			}
			else if(ipho==2)
			{
			iph=49000;
			}
			else if(ipho==3)
			{
			iph=44000;
			}
			else if(ipho==4)
			{
			iph=35000;
			}
			else if(ipho==5)
			{
			iph=24000;
			}
			else if(ipho==0)
			{
			goto items;
			}
			else if(ipho!=1||ipho!=2||ipho!=3||ipho!=4||p1!=5)
			{
				cout<<"\n\n\tOOPS!!!!!!!  Wrong choice\n\n";
				getch();
				goto loop2;
			}
			cout<<"\n\n\tQUANTITY:\t ";
			cin>>n;
			npho-=n;
			cout<<"\n\tDo you want to purchase more(y/n)";
			cin>>yes;
			if(yes=='y')
			{
				clrscr();
				goto items;
			}
			else
			{
			clrscr();
			goto cash;
			}
		}

		//DETAILS OF iPAD

		if(choice==3)
		{
			loop3:;
			clrscr();
			cout<<"\n\n\t\t\t\tiPad\n\n";
			cout<<"\n     ITEMS\t\t\t\tRATE\n\n";
			cout<<"  1. iPad Air 2 \t\t\t35900\n";
			cout<<"  2. iPad Air   \t\t\t28900\n";
			cout<<"  3. iPad Mini 3\t\t\t28900\n";
			cout<<"  4. iPad Mini 2\t\t\t21900\n";
			cout<<"  5. iPad Mini  \t\t\t17900\n";
			cout<<"\n\n\tWhich iPad you want to purchase\t";
			cin>>p2;
			if(p2==1)
			{
			ipad=35900;
			}
			else if(p2==2)
			{
			ipad=28900;
			}else if(p2==3)
			{
			ipad=28900;
			}else if(p2==4)
			{
			ipad=21900;
			}else if(p2==5)
			{
			ipad=17900;
			}
			else if(p2==0)
			{
			goto items;
			}
			else if(p2!=1||p2!=2||p2!=3||p2!=4||p2!=5)
			{
				cout<<"\n\n\tOOPS!!!!!!!  Wrong choice\n\n";
				getch();
				goto loop3;
			}
			cout<<"\n\tQUANTITY:\t ";
			cin>>o;
			npad-=o;
			cout<<"\n\tDo you want to purchase more(y/n)";
			cin>>yes;
			if(yes=='y')
			{
				clrscr();
				goto items;
			}
			else
			{
				clrscr();
				goto cash;
			}
		}

		//DETAILS OF MAC

		if(choice==4)
		{
			loop4:;
			clrscr();
			cout<<"\n\n\t\t\t\tMac\n\n";
			cout<<"\n    ITEMS\t\t\t\t\t\tRATE\n\n";
			cout<<"  1. MacBook Air\t\t\t\t\t65900\n";
			cout<<"  2. MacBook Pro\t\t\t\t\t78900\n";
			cout<<"  3. iMac       \t\t\t\t\t79900\n";
			cout<<"  4. Mac mini   \t\t\t\t\t36990\n";

			cout<<"\n\n\tWhich Mac you want to purchase\t";
			cin>>mac;
			if(mac==1)
			{
			imac=65900;
			}
			else if(mac==2)
			{
			imac=78900;
			}
			else if(mac==3)
			{
			imac=79900;
			}
			else if(mac==4)
			{
			imac=36900;
			}
			else if(mac==0)
			{
			goto items;
			}
			else if(mac!=1||mac!=2||mac!=3||mac!=4)
			{
				cout<<"\n\n\tOOPS!!!!!!!  Wrong choice\n\n";
				getch();
				goto loop4;
			}
			cout<<"\n\n\tQUANTITY:\t ";
			cin>>p;
			nmac-=p;
			cout<<"\n\tDO you want to purchase more(y/n)";
			cin>>yes;
			if(yes=='y')
			{
				clrscr();
				goto items;
			}
			else
			{
				clrscr();
				goto cash;
			}
		}

		//DETAILS OF OTHER ACCSSERIES

		if(choice==5)
		{
			loop5:;
			clrscr();
			cout<<"\n\n\t\t\t\tOther Accessories\n\n";
			cout<<"\n     ITEMS\t\t\t\t\tRATE\n";
			cout<<"\n  1.Apple Watch   \t\t\t\t\t20900\n";
			cout<<"\n  2.Magic Mouse   \t\t\t\t\t 5300\n";
			cout<<"\n  3.Apple Keyboard\t\t\t\t\t 3000\n";
			cout<<"\n  4.Apple earbuds \t\t\t\t\t 1790\n";
			cout<<"\n\n\tWhich product do you want to purchase\t";
			cin>>g1;
			if(g1==1)
			{
			awa=20900;
			}
			else if(g1==2)
			{
			mam=5300;
			}
			else if(g1==3)
			{
			apk=3000;
			}
			else if(g1==4)
			{
			ape=1790;
			}
			else if(g1==0)
			{
			goto items;
			}
			else if(g1!=1||g1!=2||g1!=3||g1!=4)
			{
				cout<<"\n\n\tOOPS!!!!!!!  Wrong choice\n\n";
				getch();
				goto loop5;
			}
			cout<<"\n\n\tQuantity:\t ";
			cin>>q;
			if(g1==1)
			{
				AppWat-=q;
				r=q;
			}
			if(g1==2)
			{
				MagMou-=q;
				s=q;
			}
			if(g1==3)
			{
				AppKey-=q;
				t=q;
			}
			if(g1==4)
			{
				AppEar-=q;
				u=q;
			}
			cout<<"\n\tDO you want to purchase more(y/n)";
			cin>>yes;
			if(yes=='y')
			{
				clrscr();
				goto items;
			}
			else
			{
				clrscr();
				goto cash;
			}
		}
		cout<<"\n\n\n";
		clrscr();
		cash:;
		cout<<"\n\n\n\n\n\n\t\t\t\t iNSPiRE APPLE\n";
		cout<<"\n\n\t\t\t\t  CASH MEMO\n";
		cout<<"\n\n";

		//TO DISPLAY THE INFORMATION OF THE CUSTOMER
		
		read();

		//TO DISPLAY THE CASH MEMO

		cout<<"\n\n\n";
		cout<<"===============================================================================";
		cout<<"\nITEMS"                            <<setw(40)<<"QUANTITY"<<setw(20)<<"PRICE(Rs.)";
		cout<<"\n===============================================================================";
		if(m>0)
		cout<<"\n\niPod"		<<setw(30)<<"\t"<<m<<setw(20)<<"Rs."<<m*iPod;
		if(n>0)
		cout<<"\n\niPhone"		<<setw(28)<<"\t"<<n<<setw(20)<<"Rs."<<n*iph;
		if(o>0)
		cout<<"\n\nipad"		<<setw(30)<<"\t"<<o<<setw(20)<<"Rs."<<o*ipad;
		if(p>0)
		cout<<"\n\nMac"			<<setw(31)<<"\t"<<p<<setw(20)<<"Rs."<<p*imac;
		if(r>0)
		cout<<"\n\nApple Watch"		<<setw(24)<<"\t"<<r<<setw(20)<<"Rs."<<r*awa;
		if(s>0)
		cout<<"\n\nMagic Mouse"		<<setw(24)<<"\t"<<s<<setw(20)<<"Rs."<<s*mam;
		if(t>0)
		cout<<"\n\nApple Keyboard"	<<setw(21)<<"\t"<<t<<setw(20)<<"Rs."<<t*apk;
		if(u>0)
		cout<<"\n\nApple earpods"	<<setw(22)<<"\t"<<u<<setw(20)<<"Rs."<<u*ape;


		e=m*iPod;
		f=n*iph;
		g=o*ipad;
		h=p*imac;
		i=r*awa;
		j1=s*mam;
		k=t*apk;
		l=u*ape;

		sum=e+f+g+h+i+j1+k+l;		     //TOTAL BILL
		add=m+n+o+p+r+s+t+u;		     //QUANTITY OF ITEMS
		cout<<"\n===============================================================================";
		cout<<"\n\nTOTAL:"<<setw(28)<<"\t"<<add<<setw(20)<<"Rs."<<sum;
		money:;
		cout<<"\n\n\n\n\t\t\tEnter the cash paid\t";
		cin>>total;
		cout<<"\n\n\n\t\t\tCASH RECIEVED :"<<total;
		if(total<sum)
		{
			cout<<"\n\n\tThe money you paid is less !!!! Please pay more money";
			getch();
			goto money;
		}
		clrscr();
		cout<<"\n\n\n\n\n\t   NO CREDIT OF THE ADDITIONAL DUTY OF";
		cout<<"\n\n\t   CUSTOMS LEVIED UNDER SECTION (5) OF";
		cout<<"\n\n\t   SECTION-3 OF THE CUSTOMS TARIFF ACT";
		cout<<"\n\n\t   1975 HAVE BEEN AVAILED/SHALL BE ADMISSABLE\n\n";
		cout<<"\n\n\n\n\n\t\tCASH RECEIVED :\t\t"<<total;
		cout<<"\n\n\t\tCASH AMOUNT :\t\t"<<sum;
		cout<<"\n\n\t\tBALANCE RETURNED :\t"<<total-sum;
		cout<<"\n\n\tTHANK YOU .\t\t\t\tVISIT US AGAIN\n";
		cout<<"\n\n\tTHANK YOU FOR USING OUR SERVICE\n\n";
		getch();
		goto again;
	}
	else
	{
		clrscr();
		getch();
		goto again;
	}

	case 2:

	//TO DISPLAY THE SHOP DETAILS

	clrscr();
	cout<<"\n\n\n\n\n\t\t\t\tSHOP DETAILS\n\n\n";
	cout<<"\n\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n";
	cout<<"\t\t  #   TIMING: 11 AM TO 11 PM	  		                    \n";
	cout<<"\t\t  #   COLLECT YOUR SMART CARD & BILL AFTER PAYMENT.              \n";
	cout<<"\t\t  #   DO NOT BREAK ANY SHOP ITEMS.                               \n";
	cout<<"\t\t  #   FOR ANY COMPLAINT CONTACT THE CHAIR PERSON.                \n";
	cout<<"\t\t  #   CHAIR PERSON :- MR. SHAGUN BANDI.                          \n";
	cout<<"\t\t  #   WELL QUALIFIED STAFF MEMBERS.                              \n";
	cout<<"\t\t  #   Email :- www.apple.co.in	                            \n";
	cout<<"\n\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n";
	getch();
	clrscr();
	goto again;

	case 3:

	//TO SEARCH THE RECORDS

	clrscr();
	search();
	getch();
	goto again;

	case 4:

	//TO DELETE THE RECORDS

	clrscr();
	del();
	getch();
	goto again;

	case 5:

	//TO MODIFY THE RECORDS

	clrscr();
	update();
	getch();
	goto again;

	case 6:

	//TO DISPLAY ALL SAVED RECORDS

	clrscr();
	read();
	getch();
	goto again;

	case 7:

	//TO DISPLAY THE QUANTITY AVAILABLE IN THE SHOP

	clrscr();

	cout<<"\n\t\t\tItems Avaliable in shop.\n\n\n";
	cout<<"===============================================================================";
	cout<<"\nITEMS"            <<setw(40)<<"QUANTITY";
	cout<<"\n===============================================================================";
	cout<<"\n\n\niPod"			<<setw(35)<<npod;
	cout<<"\n\n\niPhone"			<<setw(33)<<npho;
	cout<<"\n\n\nipad"			<<setw(35)<<npad;
	cout<<"\n\n\nMac"			<<setw(36)<<nmac;
	cout<<"\n\n\nApple watch"		<<setw(29)<<AppWat;
	cout<<"\n\n\nMagic Mouse"		<<setw(29)<<MagMou;
	cout<<"\n\n\nApple Keyboard"		<<setw(26)<<AppKey;
	cout<<"\n\n\nApple Earpods"		<<setw(27)<<AppEar;
	cout<<"\n*******************************************************************************";
	getch();
	goto again;

	case 0:

	//TO EXIT FROM THE PROGRAM

	clrscr();
	cout<<"\n\n\n\t\tARE YOU SURE TO EXIT FROM THE PROGRAM\t";
	cin>>et;
	if(et=='y'||et=='Y')
	{
	goto ex;
	}
	else
	{
	goto again;
	}
	ex:;
	clrscr();
	gotoxy(28,30);
	cout<<" THANK YOU FOR USING THE PROJECT\n\n\n\n ";
	delay(1000);
	cputs("HAVE A NICE DAY");
	gotoxy(45,45);
	cputs(" Press ENTER to EXIT.......");
	getch();
	exit(0);
	default:
	cout<<"\n\t\tOOPS!!!!!!!! Your choice is WRONG";
	getch();
	goto again;
	}
}
//END OF VOID MAIN
//END OF COMPUTERS DIRECTORY

