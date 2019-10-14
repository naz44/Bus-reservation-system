
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;
static int p = 0;
class Bus_Reservation
{
protected:
  char busn[5];
  char driver[10];
  char arrival[5];
  char depart[5];
  char from[10];
  char to[10];
  char seat[8][4][10];
  char naam[10];
  char gen[10];
  int age;
  char ph[12];
  int tickn;
  char date[10];
  int tp;

public:
  void add_bus();
  void reserve_bus();
  void empty();
  void show_bus();
  void is_bus_available();
  void position(int i);
}bus[10];

void Bus_Reservation::add_bus()
{
  cout<<"Enter bus number: ";
  cin>>bus[p].busn;

  cout<<"Enter Driver's name: ";
  cin>>bus[p].driver;

  cout<<"Arrival time: ";
  cin>>bus[p].arrival;

  cout<<"Departure: ";
  cin>>bus[p].depart;

  cout<<"From: ";
  cin>>bus[p].from;

  cout<<"To: ";
  cin>>bus[p].to;

  cout<<"Ticket fare:";
  cin>>bus[p].tp;
  cout<<"Enter date"<<endl;
  cin>>bus[p].date;
   cout<<"\n Added Successfully....";

  bus[p].empty();
  p++;

  getch();

}

void Bus_Reservation::reserve_bus()
{
  int seat;
  char number[5];
  top:
  cout<<"Bus Service number: ";
  cin>>number;
  cout<<"number of passengers:"<<endl;
  cin>>tickn;
  cout<<"Phone number"<<endl;
  cin>>ph;
  int n,temp;
  temp=tickn;
  while(temp--)
  {
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    {
      if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "AV")==0)
      {
	cout<<"Enter passenger's name: ";
	cin>>naam;
	 cout<<"gender"<<endl;
	 scanf("%c",gen);
	  cout<<"age"<<endl;
	 cin>>age;
	strcpy(bus[n].seat[seat/4][(seat%4)-1],"NA");
	break;
      }
    else
      cout<<"The seat is already reserved.\n";
      }
 }

    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }}

  cout<<"**please report 20mins before arrival time"<<endl;

    cout<<"\n Added Successfully....";

  }


void Bus_Reservation::empty()
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seat[i][j], "AV");
    }
  }
}

void Bus_Reservation::show_bus()
{
  int n;
  char number[5];
  cout<<"Enter bus number: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
  while(n<=p)
  {
	cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"Bus no: "<<bus[n].busn
	<<"\nDriver: "<<bus[n].driver<<"\nArrival time: "
	<<bus[n].arrival<<"\nDeparture time: "<<bus[n].depart
	<<"\nFrom: "<<bus[n].from<<"\nTo: "<<
	bus[n].to<<"\n";
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	bus[0].position(n);

	int a=1;
	for (int i=0; i<8; i++)
	{
	for(int j=0;j<4;j++)
	{
	a++;
	if(strcmp(bus[n].seat[i][j],"AV")!=0)
	cout<<"\nThe seat no "<<(a-1)<<" is reserved"<<endl;
	}
	}
	break;
	}
	if(n>p)

	cout<<"Enter correct bus no: ";

	getch();
}

void Bus_Reservation::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j],"AV")==0)
	{
	  cout.width(5);
	  cout.fill(' ');
	  if(s>9)
	  cout<<"|_"<<s<<"_|"<<".";
	  else
	   cout<<"|_"<<s<<"__|"<<".";
	  cout.width(5);
	  cout.fill(' ');
	  cout<<bus[l].seat[i][j];
	  p++;
	}
	else
	{
	cout.width(5);
	cout.fill(' ');
	cout<<"|_"<<s<<"_|"<<".";
	cout.width(5);
	cout.fill(' ');
	cout<<"NA";
	}
      }
    }
    cout<<"\n*AV means available"<<endl<<"*NA means not available"<<endl;
    cout<<"\n\nThere are "<<p<<" seats empty in Bus Number: "<<bus[l].busn;
  }

void Bus_Reservation::is_bus_available()
{
  for(int n=0;n<p;n++)
  {
	cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"Bus number: "<<bus[n].busn<<"\nDriver: "<<bus[n].driver
	<<"\nArrival time: "<<bus[n].arrival<<"\nDeparture Time: "
	<<bus[n].depart<<"\nFrom: "<<bus[n].from<<"\nTo: "
	<<bus[n].to;
	cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
  }
getch();
}

int main()
{

Bus_Reservation ob;
int w;

cout<<"Welcome to Simulation of bus reservation system...\n";
do{
  cout<<"\n1. Add Bus\n";
  cout<<"2. Buses Available\n";
  cout<<"3. check availability of seats\n";
  cout<<"4. Reservation \n";
  cout<<"5. Exit";

  cout<<"\n\t\t\tEnter your choice:-> ";
  cin>>w;
  switch(w)
  {
    case 1:  bus[p].add_bus();
      break;
    case 4:  bus[p].reserve_bus();
      break;
    case 3:  bus[0].show_bus();
      break;
    case 2:  bus[0].is_bus_available();
      break;
    case 5:  cout<<"exiting......";
    break;
  }
}while(w!=5);
getch();
return 0;
}
