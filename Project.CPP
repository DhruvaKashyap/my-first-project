 //Header files
 #include<iostream.h>
 #include<conio.h>
 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
 #include<ctype.h>
 #include<string.h>
 #include<dos.h>
 #include<process.h>
 #include<fstream.h>
 #include<graphics.h>
 int i;		//Global loop variable
 //Function to display login page
 void login_page()
 {
 textcolor(10);
 textbackground(0);
 gotoxy(25,5);
 cprintf("WELCOME TO SOCIAL-SECURITY-BANKING SYSTEM");
 gotoxy(26,10);
 cprintf("Enter Security number:");
 gotoxy(26,11);
 cprintf("Enter password:");
 gotoxy(26,12);
 cprintf("Press Enter to create new account");
 }
 //Function to generate a random password for the user
 void assign_password(char pass[])
 {
 char alphanum[][15]=
    {
    "0","1","2","3","4","5","6","7","8","9",
    "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"
    "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"
    "KOTE","ISHAPPY","ISSAD","ISHUNGRY","ISNTSAFE" ,"YES","BOAT","VIRUS","MORNING","SOMEONE"
    "FOOD","LUXURY","SYLLABLE","MARGARET","THATCHER","RENEGADE","BOISTROUS","QAUSIMODO","HELLFIRE",
    "HARAMBE","FOX","BLOOD","SWIFT","WALL","DRAGONS","ELDORADO","SONOROUS","BLINK","NO","SOUND",
    "MUMBO","SILLY","WILL","STALIN","EASY","HELP","YOU","ME","MINE","POKE","PHONE","WHAT",
    "HOW","LEAVE","LOVE","EAT","MY","FACE","COAL","METHANE","MOLTEN","LISTEN","PLEASE",
    "POUCH","PARROT","SLEEP","CALL","PRINCIPLE","SOLUTION","SCARED","BENZENE","MAN","BEAR",
    "COW","PIG","CROW","HOGWARTS"
    };                           //Passphrases

 time_t t;
 srand((unsigned) time(&t));
 srand(time(0));

 int l=6;               //password length
 int j=0,I=0;   	//loop var
 int ran;       	//random var
 int zz;        	//total phrase size
 int k;         	//random phrase size
 int p=0;       	//password array variable
 zz=sizeof(alphanum)/15;    //number of phrases
 while(I<l)
	{
 ran=rand()%zz;     			//internal randomisation
 if(strlen(alphanum[ran])==1)
		{
		pass[p]=alphanum[ran][0];         //for single letter
		I++;
		p++;
		}
  if(strlen(alphanum[ran])>2)    //for strings
		{
		k=strlen(alphanum[ran]);
		j=0;
		while(j<k && j+I<l)                          //randomising letters of string
			{
			if(alphanum[ran][j]>='A' && alphanum[ran][j]<='Z' && rand()%2==0)    //randomly converts capital to small
				{
				alphanum[ran][j]+=32;
				}
			else if(alphanum[ran][j]>='a' && alphanum[ran][j]<='z' && rand()%2==0)  //randomly converts small to capital
				{
				alphanum[ran][j]-=32;
				}
			pass[p]=alphanum[ran][j];
			p++;
			j++;
			}
		I+=strlen(alphanum[ran]);
		}
	}
 }
 //Function to take a character array as input and validate the data
 void check_name(char name[])
 {
 s:
 int flag=0;
 gets(name);
 for(i=0;i<strlen(name);i++)
	{
	if(isalpha(name[i])!=0)
		flag=1;
	else
		{
		flag=-1;
		break;
		}
	}
 if(flag==-1)
	{
	cout<<"\t\tInvalid characters.Please enter again:";
	goto s;
	}
 }
 //Function to obtain password from the user as input and display *
 void get_in_secret(char password[])
 {
 char ch;
  i=0;
 while(i<6)
	{
	ch=getch();
	if(ch!='\b')
		{
		password[i]=ch;
		cout<<"*";
		i++;
		}
	else
		{
		clreol();
		gotoxy(40+i,11);
		i--;
		}
	if(i<0)
		i=0;
	}
	cout<<endl;
 }
 //Function to take the phone number as input and validate the phone number
 void get_phone(int a[])
 {
 int f=0,temp[10]; //flag variable
 char ch;          //input character
 phone:
 for(i=0;i<10;i++)
	{
	ch=getch();
	if(isdigit(ch)==0)
		i--;
	else
		{
		temp[i]=ch-48;
		cout<<temp[i];
		}
	}
 if(a[0]==9 || a[0]==8 || a[0]==7)
 f=10;
 for(i=0;i<8;i++)
	{
	if(temp[i]==temp[i+1])
		f=-1;
	else
		f=10;
	}
 if(f!=10)
	{
	cout<<endl<<"Sorry,Incorrect number.Please Enter again.";
	cout<<endl;
	goto phone;
	}
 else
 for(i=0;i<10;i++)
	a[i]=temp[i];
 }
 //Function to take the account number as input and check the value
 void enter_accno(long int &a)
 {
 i=0;
 a=0;
 char ch='q';int no[8];
 for(i=0;i<8;i++)
	{
	ch=getche();
	if(isdigit(ch))
		{
		no[i]=ch-48;
		}
	else if(ch=='\b')
		{
		clrscr();
		login_page();
		gotoxy(48,10);
		for(int Y=0;Y<i-1;Y++)
			cout<<no[Y];
		i-=2;
		}
	else if(ch=='\r')
		{
		a=-1;
		break;
		}
	else
		{
		clrscr();
		login_page();
		gotoxy(48,10);
		for(int Y=0;Y<i;Y++)
			cout<<no[Y];
		i--;
		}
	}
	if(a!=-1)
   for(i=0;i<8;i++)
      a=no[i]+10*a;
 }
 //Function to output INCORRECT PASSWORD if the entered password is incorrect
 void Incorrect_password(int a,int b,int c)
 {
 gotoxy(a,b);
 textattr(RED + (8 <<4));
 cprintf("INCORRECT PASSWORD                        ");
 gotoxy(a,b+1);
 textcolor(c);
 textbackground(BLACK);
 }
 //Class that contains all attributes of card
 class card
 {
	char first_name[20];
	char last_name[20];
	char father_name[20];
	char password[6];
	char gender;
	int phone_number[10];
	float bank_balance;
	protected:
	long int no;
	public:
	char get_password(int t)
		{
			return(password[t]);
		}
	long int getno()
		{
			return(no);
		}
	void assign_no();        //Function to assign social security number
	void get_data();         //Function to take input from the user
	void modify_data();      //Function to modify user data
	void modify_password();  //Function to modify user password
	void show_data();        //Function to display data of new account
	void show_card();        //Function to display Social Security card
	void show_bank();        //Function to open bank portal
 };
 //Function to randomly assign Security number
 void card::assign_no()
 {
 no=0;
 int n[8];
	time_t t;
	srand((unsigned) time(&t));
	srand(time(0));
 for(i=0;i<8;i++)
	{
	n[i]=rand()%9+1;
	}
 for(i=0;i<8;i++)
		no=n[i]+10*no;
  }
 //Function to obtain data of the user
 void card::get_data()
 {
 char g,ch;
 assign_no();
 qwerty:
 cout<<"\n\t\t\tFirst name:";
 check_name(first_name);
 cout<<"\n\n\t\t\tLast name:";
 check_name(last_name);
 cout<<"\n\n\t\t\tFather's first name:";
 check_name(father_name);
 cout<<"\n\n\t\t\tGender(M/F/O)";
 gengen:
 g=getche();
 getch();
 if( g=='M'|| g=='F'|| g=='O'|| g=='m'|| g=='f'|| g=='o')
	gender=toupper(g);
 else
	{
	cout<<"\nPlease enter correct gender(M/F/O):";
	goto gengen;
	}
 cout<<"\n\n\t\t\tPhone number:";
	get_phone(phone_number);
 cout<<"\n\n\t\t\tConfirm?(y/n)";
 ch=getche();
 getch();
 cout<<endl;
 if(ch=='n' || ch=='N')
	{
	clrscr();
	goto qwerty;
	}
 assign_password(password);      //assigns random password
 bank_balance=0;                    //sets bank balance to zero
 }
 //Function to change the data of the card
 void card::modify_data()
 {
 char gh;
 cout<<"	 First name:";
 puts(first_name);
 cout<<"	  Press y to make any change.Press any other key to continue."<<endl;
 gh=getche();
 getch();
 if(gh=='y'||gh=='Y')
	{
	cout<<"	    First name:";
	check_name(first_name);
	}
 cout<<"	    Last name:";
 puts(last_name);
 cout<<"	       Press y to make any change.Press any other key to continue."<<endl;
 gh=getche();
 getch();
 if(gh=='y'||gh=='Y')
	{
	 cout<<"	Last name:";
	 check_name(last_name);
	}
 cout<<"		Father's first name:";
 puts(father_name);
 cout<<endl;
 cout<<"		Press y to make any change.Press any other key to continue."<<endl;
 gh=getche();
 getch();
 if(gh=='y'||gh=='Y')
	{
	 cout<<"		Father's first name";
	 check_name(father_name);
	}
 char g;
 cout<<"		Gender(M/F/O)"<<gender<<endl;
 cout<<"		Press y to make any change.Press any other key to continue."<<endl;
 gh=getche();
 getch();
 if(gh=='y'||gh=='Y')
	{
	 gg:
	 cout<<"		Gender:"<<endl;
	 g=getche();
	 getch();
	 if(g=='M'||g=='F'||g=='O'||g=='m'||g=='f'||g=='o')
		gender=toupper(g);
	 else
		{
		cout<<endl<<"Please enter correct gender(M/F/O):"<<endl;
		goto gg;
		}
	 }
 cout<<"		PHONE NUMBER:";
 for(i=0;i<10;i++)
 cout<<phone_number[i];
 cout<<endl;
 cout<<"		Press y to make any change.Press any other key to continue."<<endl;
 gh=getche();
 getch();
 if(gh=='y'||gh=='Y')
	{
	  cout<<"Enter new number:";
	  get_phone(phone_number);
	}
 }
 //Function for user to modify password
 void card::modify_password()
 {
 int flag=0;
 char ppnew1[6],ppnew2[6],ch;
 gotoxy(20,2);
 cout<<"Enter new password(6 char):";
 get_in_secret(ppnew1);
 rer:
 gotoxy(20,3);
 cout<<"Enter new password again:";
 get_in_secret(ppnew2);
 for(i=0;i<6;i++)
	{
	if(ppnew1[i]==ppnew2[i])
		{
		flag=1;
		}
	else
		{
		flag=-1;break;
		}
	}
 if(flag==1)
	{
	for(i=0;i<6;i++)
		password[i]=ppnew1[i];
	cout<<"Password successfully changed"<<endl;
	}
	else
	{
	cout<<"Incorrect second time.Press y to enter again.Press any other key to return to main menu.";
	ch=getche();
	getch();
	if(ch=='y' || ch=='Y')
	goto rer;
	}
 }
 //Function to output data
 void card::show_data()
	{
	cout<<"\nProcessing";
	for(int i=0;i<70;i++)
	{cout<<".";delay(25);}
	delay(1500);
	clrscr();
	cout<<"\tPLEASE NOTE DOWN YOUR ACCOUNT NUMBER AND PASSWORD\n"<<endl;
	textcolor(10);
	cout<<"Account number:	   "<<no<<endl;
	cout<<"First name:	   "<<first_name<<endl;
	cout<<"Last name:	   "<<last_name<<endl;
	cout<<"Father's first name:"<<father_name<<endl;
	cout<<"Gender:		   "<<gender<<endl;
	cout<<"Phone number:	   ";
	for(i=0;i<10;i++)
		cout<<phone_number[i];
	cout<<endl;
	cout<<"Password:	   ";
	for(i=0;i<6;i++)
		cout<<password[i];
	cout<<endl;
	getch();
 }
 //Function to access Bank account of the user
 void card::show_bank()
 {
 clrscr();
 char cc='y';
 cout<<"\t\t\tHello and welcome to banking"<<endl;
 cout<<"\n\n\t\ta.Withdraw\n\t\tb.Deposit\n\t\tc.Show\n\t\td.Exit"<<endl;
 char cho;
 while(cc=='y')
	{
	textcolor(10);
	cout<<"\t\t";
	cho=getche();
	getch();
	cout<<endl;
	switch(cho)
		{
		case 'a':
			{
			float rr;
			cout<<"\t\tEnter amount to be withdrawn:";
			chk1:
			cin>>rr;
			if(rr<bank_balance)
			{
			if(rr>50000)
				cout<<"\t\tNotifying income tax office"<<endl;
				bank_balance-=rr;
			}
			else if(rr<0)
			{
			cout<<endl<<"\t\tPlease enter correct values"<<endl;
			goto chk1;
			}
			else
			cout<<"\t\tNot enough cash in account"<<endl;
			cout<<"\t\tBalance is:"<<bank_balance<<endl;
			break;
			}
		case 'b':
			{
			float ff;
			cout<<"\t\tEnter deposit money:";
			chk2:
			cin>>ff;
			if(ff>10000)
			cout<<"\t\tNotifying income tax office"<<endl;
			else if(ff<0)
			{
			cout<<endl<<"\t\tPlease enter correct values"<<endl;
			goto chk2;
			}
			bank_balance+=ff;
			cout<<"\t\tBalance is:"<<bank_balance<<endl;
			break;
			}
		case 'c':
			{
			cout<<"\t\tBalance is:"<<bank_balance<<endl;
			break;
			}
		case 'd':
			{
			cc='n';
			break;
			}
		default:
		cout<<"\t\ta.Withdraw\nb.Deposit\nc.Show\nd.Exit"<<endl;
		}
	}
 }
 //Function to display the social security card
 void card::show_card()
 {
    char pattern[][8] =
    {       					//Array that contains user defined pattern for creating the barcode
	{1,1,1,1,1,1,1,1},            		//Represents 1
	{3,3,3,3,3,3,3,3},            		//Represents 2
	{7,7,7,7,7,7,7,7},            		//Represents 3
	{15,15,15,15,15,15,15,15},    		//Represents 4
	{31,31,31,31,31,31,31,31},              //Represents 5
	{63,63,63,63,63,63,63,63},              //Represents 6
	{125,125,125,125,125,125,125,125},      //Represents 7
	{205,205,205,205,205,205,205,205},      //Represents 8
	{                                       //Represents 9
	4294967295,4294967295,4294967295,
	4294967295,4294967295,4294967295,
	4294967295,4294967295
	},
    };
   long int a=no;
   char string[8],phone[11];
   for(i=0;i<10;i++)
   phone[i]=(char)phone_number[i]+48;
   phone[10]=NULL;
   char full_name[50];
   if(gender=='M')
   strcpy(full_name,"Mr ");
   else if(gender=='F')
   strcpy(full_name,"Mrs ");
   else
   strcpy(full_name,"X ");
   strcat(full_name,first_name);
   strcat(full_name," ");
   strcat(full_name,last_name);
   ltoa(a,string,10);
   int j;
   //request auto detection and initialise graphics mode
   int gdriver = DETECT, gmode, errorcode;
   int left, top, right, bottom,midx,midy;
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
   setcolor(WHITE);
   setfillstyle(SOLID_FILL,WHITE);
   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   left = getmaxx() / 2 - 150;
   top = 0;
   right = getmaxx() / 2 + 150;
   bottom =getmaxy();
   //Card border
   rectangle(left,top,right,bottom);
   floodfill(getmaxx()/3, getmaxy()/2, WHITE);
   //flag
   setcolor(CYAN);
   setfillstyle(SOLID_FILL,CYAN);
   rectangle(left,top+40,right,bottom/4-50);
   floodfill(left+20,top+42,CYAN);
   setcolor(GREEN);
   setfillstyle(SOLID_FILL,GREEN);
   rectangle(left,top+100,right,bottom-350);
   floodfill(left+20,top+102,GREEN);
   //Text and data
   setcolor(0);
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   settextstyle(DEFAULT_FONT, HORIZ_DIR,2);
   setcolor(BLUE);
   outtextxy(midx,midy-220,"GOVERNMENT OF INDIA");
   setcolor(0);
   outtextxy(midx,midy-150,"SOCIAL SECURITY");
   settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
   outtextxy(left+50,midy-50,"NAME:");
   settextjustify(LEFT_TEXT, CENTER_TEXT);
   outtextxy(left+50+30,midy-50,full_name);
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   outtextxy(left+87,midy-40,"Father's NAME:");
   settextjustify(LEFT_TEXT, CENTER_TEXT);
   outtextxy(left+90+70,midy-40,father_name);
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   outtextxy(left+80,midy-30,"Phone number:");
   settextjustify(LEFT_TEXT, CENTER_TEXT);
   outtextxy(left+90+60,midy-30,phone);
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   settextstyle(DEFAULT_FONT, HORIZ_DIR,2);
   outtextxy(midx,midy+50,string);
   setlinestyle(1,1,1);
   line(left,midy+100,right,midy+100);
   settextstyle(SANS_SERIF_FONT, HORIZ_DIR,1);
   outtextxy(midx-50,midy+120,"BARCODE:");
   //Barcode
   for(int i=0;i<strlen(string);i++)
   {
   j=string[i]-48;
   setfillpattern(pattern[j-1], RED);
   bar(midx+10+10*i,midy+120,midy+80+10*i,midy+130);
   }
   settextstyle(TRIPLEX_FONT, HORIZ_DIR,1);
   outtextxy(left+50,midy+170,"NAME:");
   settextjustify(LEFT_TEXT, CENTER_TEXT);
   outtextxy(left+50+30,midy+170,full_name);
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   outtextxy(left+90,midy+190,"Father's Name:");
   settextjustify(LEFT_TEXT, CENTER_TEXT);
   outtextxy(left+90+70,midy+190,father_name);
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   outtextxy(left+90,midy+210,"Phone number:");
   settextjustify(LEFT_TEXT, CENTER_TEXT);
   outtextxy(left+90+80,midy+210,phone);
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   getch();
   closegraph();
 }
 void main()
 {
 clrscr();
 long int a;
 int t,cho,flag,f1=9,l;
 char aaa[6],user_password[6],user1_password[6];
 char x,tt,c,ch='y',rr;
 strcpy(aaa,NULL);
 card C;      		//Object of card
 fstream file;
 opening:
 clrscr();
 file.open("test",ios::in|ios::out|ios::ate|ios::binary); //opening data file
 file.seekp(0,ios::end);
 file.seekg(0,ios::end);
 long fs;int n;     //Display number of active users
 fs=file.tellg();
 n=fs/sizeof(C);
 login_page();
 gotoxy(25,25);
 cprintf("We are proud of ");
 cout<<n;
 cprintf(" users");
 gotoxy(48,10);
 file.seekp(0);
 file.seekg(0);
 enter_accno(a);
 if(a<0)  //Creating new account
	{
	clrscr();
	gotoxy(20,7) ;
	file.seekp(0,ios::end);
	file.seekg(0,ios::end);
	C.get_data();
	file.write((char *)&C,sizeof(C));
	C.show_data();
	file.close();
	getch();
	goto opening;
	}
 else    //Logging into an account
	{
	f1=9;
	file.seekg(0);
	while(file.read((char *)&C,sizeof(C)))
		{
		if(C.getno()==a)
			{
			t=file.tellp();
			f1=0;
			break;
			}
		f1=10;
		}
	file.seekp(0);
	cout<<endl;
	get_password:
	file.seekp(0);
	gotoxy(41,11);
	get_in_secret(user_password);
	if(f1==0)
		{
		file.seekp(t-sizeof(C),ios::beg);
		for(i=0;i<6;i++)
			{
			if(user_password[i]==C.get_password(i))
				{
				flag=0;
				}
			else
				{
				flag=-1;
				break;
				}
			}
		if(flag!=0)
			{
			clreol();
			Incorrect_password(26,12,10);
			cout<<"Press y to try again or any other key to exit";
			textcolor(10);
			ch=getche();
			cout<<endl;
			if(ch=='y' || ch=='Y'	)
				{
				clrscr();
				login_page();
				gotoxy(48,10);
				cout<<a;
				goto get_password;
				}
			else
				{
				gotoxy(25,14);
				cout<<"Press y to exit or any other key to go to main menu";
				ch=getche();
				cout<<endl;
				if (ch=='y'|| ch=='Y')
					exit(0);
				else
					{
					file.close();
					clrscr();
					goto opening;
					}
				}
			}
		}
	if(f1!=0)
		{
		file.seekp(0);
		file.seekg(0);
		gotoxy(26,12);
		cout<<"ACCOUNT DOES NOT EXIST.TRY AGAIN?(y/n)";
		ch=getche();
		getch();
		cout<<endl;
		if(ch=='y'|| ch=='Y')
			{
			file.close();
			clrscr();
			login_page();
			gotoxy(48,10);
			goto opening;
			}
		else
			exit(0);
		}
 //Opening into account
	delay(1000);
	login_menu:
	clrscr();
	ch='y';
	gotoxy(20,1) ;
	while(ch=='y')    //Main menu
		{
		clrscr();
		cout<<"1.Show\n2.Modify account details\n3.Modify password\n4.Open bank account\n5.Return to login page\n6.Exit"<<endl;
		gotoxy(20,7);
		cout<<endl<<"Enter choice:";
		cin>>cho;
		switch(cho)
			{
			case 1:{//Showing the card
				file.seekp(t-sizeof(C),ios::beg);
				file.seekg(t-sizeof(C),ios::beg);
				C.show_card();
				getch();
				file.clear();
				break;
				}
			case 2:{//Modifying the details
				file.seekp(t-sizeof(C),ios::beg);
				file.seekg(t-sizeof(C),ios::beg);
				clrscr();
				gotoxy(20,3);
				cout<<"Do you want to modify your account details?(y/n)";
				rr=getche();
				getch();
				acc_modify:
				clrscr();
				cout<<endl;
				if(rr=='y'||rr=='Y')
					{
					cout<<"	         Requesting admin"<<endl;
					delay(500);
					cout<<"	         Request approved."<<endl;
					cout<<"	         Please enter password:"<<endl;
					gotoxy(41,4);
					get_in_secret(user_password);
					flag=10;
					for(i=0;i<6;i++)
						{
						if(user_password[i]==C.get_password(i))
							flag=0;
						else
							{
							flag=-1;
							break;
							}
						}
					if(flag==0)
						{
						file.seekp(t-sizeof(C),ios::beg);
						C.modify_data();
						file.write((char *)&C,sizeof(C));
						file.seekp(t-sizeof(C),ios::beg);
						break;
						}
					else
						{
						Incorrect_password(19,5,10);
						cout<<"Do you want to try again?(y/n)";
						ch=getche();
						cout<<endl;
						if(ch=='y')
							{
							goto acc_modify;
							}
						else
						goto login_menu;
						}
					}
				else if(rr=='n'||rr=='N')
					{
					file.close();
					goto login_menu;
					}
				break;
			       }
			case 3:
			       {//Modifying details
			       clrscr();
			       gotoxy(20,3);
			       cout<<"Do you want to change password?(y/n)";
			       ch=getche();
			       getch();
			       cout<<endl;
			       if(ch!='y')
					goto login_menu;
			       else if(ch=='y' || ch=='Y')
					{
					password_menu:
					clrscr();
					gotoxy(20,3);
					cout<<"Enter old password:";
					get_in_secret(user1_password);
					file.seekp(t-sizeof(C),ios::beg);
					file.seekg(t-sizeof(C),ios::beg);
					for(i=0;i<6;i++)
						aaa[i]=C.get_password(i);
					for(i=0;i<6;i++)
						{
						if(user1_password[i]==aaa[i])
							flag=0;
						else
							{
							flag=-1;
							break;
							}
						}
					if(flag==-1)
						{
						Incorrect_password(20,3,10);
						cout<<"Do you want to try again?(y/n)";
						ch=getche();
						cout<<endl;
						if(ch=='y')
							goto password_menu;
						else if(ch=='n')
							{
							gotoxy(20,5);
							cout<<"Do you want to exit?(y/n)";
							ch=getche();
							cout<<endl;
							if (ch=='y')
								exit(0);
							else
							goto login_menu;
							}
						else
						goto login_menu;
						}
					if(flag==0)
						{
						clrscr();
						file.seekg(t-sizeof(C),ios::beg);
						file.seekp(t-sizeof(C),ios::beg);
						C.modify_password();
						file.write((char *)&C,sizeof(C));
						}
					}
				break;
				}
			case 4:
			       {//Opening bank portal
				file.seekg(t-sizeof(C),ios::beg);
				file.seekp(t-sizeof(C),ios::beg);
				C.show_bank();
				file.write((char *)&C,sizeof(C));
				break;
			       }
			case 5:
				goto opening;
			case 6:
				exit(0);
			default:
				{
				cout<<"Please enter from the Main Menu"<<endl;
				goto login_menu;
				}
			}//SWITCH CLOSE
		}//WHILE CLOSE
	}//loggin close
 getch();
 }
