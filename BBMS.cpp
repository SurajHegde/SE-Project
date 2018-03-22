#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int k=1,l=1;
class hospital
{
	public:
	int HPID;
	int contactno;
	char rhesius;
	char type;
			void h_register()
		{
			HPID=k;

			cout<<"\nEnter contact no:";
			cin>>contactno;
			cout<<"Your HPID is: "<<HPID<<endl;
		}
	void payment_check(){
		char ch;
		cout<<"Has payment been made?(Y/N)";
		cin>>ch;
		if(ch=='Y'){
			cout<<"Transaction complete";
		}
		else{
			cout<<"Transaction incomplete";
		}
	}

};
class donor
{
	public:
	int fitness;
	char name[10];
	int contact;
	int DNR;
	char r;	//r-rhesius
	char t; //t-type
		void d_register()
		{
			char str[2];
			cout<<"Enter Name:";
			cin>>name;
			cout<<"Enter ContactNo:";
			cin>>contact;
			cout<<"\nEnter fitness state( 1-fit, 0-unfit):";
			cin>>fitness;
			cout<<"\nEnter type:";
			cin>>str;
			if(strcmp(str,"AB")==0)
			{
				t='x';
			}
			else
			{
				t=str[0];
			}
			cout<<"\nEnter Rhesius: ";
			cin>>r;
			DNR=l;
			cout<<"Your DNR is: "<<DNR;

		}
		void d_updation()
		{
			int choice;
			cout<<"\nEnter choice:\n1.Update fitness state\n2.Update contact number";
			cin>>choice;
			switch(choice)
			{
				case 1:
					cout<<"\nEnter new fitness state:";
					cin>>fitness;
					break;
				case 2:
					cout<<"\nEnter contact number:";
					cin>>contact;
					break;
				default: cout<<"\nInvalid input!";

			}

		}

};
class bloodpacket
{
public:
	char t_1;//type
	char r_1;//rhesius
	int expiry;

};
class bloodbank
{
	public:
int username;
int password;
class donor d[5];
class hospital h[5];
class bloodpacket b[24];
	bloodbank(int a,int b)
	{
		username=a;
		password=b;
	}
int authenticate()
{
	int y,z;
cout<<"Enter username";
cin>>y;
cout<<"Enter password";
cin>>z;
int x;
if(y==username&&z==password)
{
	x=2;
	return x;
}
else
return 0;
}
void b_register()
{
d[l].d_register();
l=l+1;
}
void update()
{
	int r;
	cout<<"Enter DNR:";
	cin>>r;
	if(r>=l)
	{
		cout<<"DNR doesnt exist";return;
	}
	else
	d[r].d_updation();
}
void h_registration()
{

	h[k].h_register();
	k=k+1;
}

void accept(){
	int hid, flag = 0, i;
	char req_t, req_r;
	cout<<"Enter HPID: ";
	cin>>hid;
	if(hid>=k){
		cout<<"Enter valid HPID\n";
		return;
	}
	cout<<"Enter required blood type: ";
	cin>>req_t;
	cout<<"Enter required rhesius type: ";
	cin>>req_r;
	switch(req_t){
		case 'A':if(req_r=='+'){
					for(i=0;i<3;i++){
						if(b[i].expiry<2017){
							flag = 300;
							b[i].t_1 = '0';
							b[i].r_1 = '0';
							b[i].expiry = 0;
							break;
						}
					}
				}
				else{
					for(i=3;i<6;i++){
						if(b[i].expiry<2017){
							flag = 1000;
							b[i].t_1 = '0';
							b[i].r_1 = '0';
							b[i].expiry = 0;
							break;
						}
					}
				}
				break;
		case 'B':if(req_r=='+'){
					for(i=6;i<9;i++){
						if(b[i].expiry<2017){
							flag = 400;
							b[i].t_1 = '0';
							b[i].r_1 = '0';
							b[i].expiry = 0;
							break;
						}
					}
				}
				else{
					for(i=9;i<12;i++){
						if(b[i].expiry<2017){
							flag = 800;
							b[i].t_1 = '0';
							b[i].r_1 = '0';
							b[i].expiry = 0;
							break;
						}
					}
				}
				break;
		case 'O':if(req_r=='+'){
					for(i=12;i<15;i++){
						if(b[i].expiry<2017){
							flag = 300;
							b[i].t_1 = '0';
							b[i].r_1 = '0';
							b[i].expiry = 0;
							break;
						}
					}
				}
				else{
					for(i=15;i<18;i++){
						if(b[i].expiry<2017){
							flag = 2000;
							b[i].t_1 = '0';
							b[i].r_1 = '0';
							b[i].expiry = 0;
							break;
						}
					}
				}
				break;
		case 'x':if(req_r=='+'){
					for(i=18;i<21;i++){
						if(b[i].expiry<2017){
							flag = 500;
							b[i].t_1 = '0';
							b[i].r_1 = '0';
							b[i].expiry = 0;
							break;
						}
					}
				}
				else{
					for(i=21;i<24;i++){
						if(b[i].expiry<2017){
							flag = 2000;
							b[i].t_1 = '0';
							b[i].r_1 = '0';
							b[i].expiry = 0;
							break;
						}
					}
				}
				break;
		default: break;
	}
	if(flag!=0){
		cout<<"Cost of the required Blood Packet is: "<<flag;
		h[hid].payment_check();
	}
	else{
		cout<<"Required Blood Packet not available";
	}
}

void donate(){
	int a,i;
	cout<<"Enter DNR: ";
	cin>>a;
	if(a>=l){
		cout<<"Enter valid DNR\n";
		return;
	}
	if(d[a].fitness==0){
		cout<<"Person is unfit to donate\n";
		return;
	}
	char t, r;
	t = d[a].t;
	r = d[a].r;
	switch(t){
		case 'A':if(r=='+'){
					for(i=0;i<3;i++){
						if(b[i].expiry<2017){
							b[i].t_1 = d[a].t;
							b[i].r_1 = d[a].r;
							cout<<"Enter expiry: ";
							cin>>b[i].expiry;
							break;
						}
					}
				}
				else{
					for(i=3;i<6;i++){
						if(b[i].expiry<2017){
							b[i].t_1 = d[a].t;
							b[i].r_1 = d[a].r;
							cout<<"Enter expiry: ";
							cin>>b[i].expiry;
							break;
						}
					}
				}
				break;
		case 'B':if(r=='+'){
					for(i=6;i<9;i++){
						if(b[i].expiry<2017){
							b[i].t_1 = d[a].t;
							b[i].r_1 = d[a].r;
							cout<<"Enter expiry: ";
							cin>>b[i].expiry;
							break;
						}
					}
				}
				else{
					for(i=9;i<12;i++){
						if(b[i].expiry<2017){
							b[i].t_1 = d[a].t;
							b[i].r_1 = d[a].r;
							cout<<"Enter expiry: ";
							cin>>b[i].expiry;
							break;
						}
					}
				}
				break;
		case 'O':if(r=='+'){
					for(i=12;i<15;i++){
						if(b[i].expiry<2017){
							b[i].t_1 = d[a].t;
							b[i].r_1 = d[a].r;
							cout<<"Enter expiry: ";
							cin>>b[i].expiry;
							break;
						}
					}
				}
				else{
					for(i=15;i<18;i++){
						if(b[i].expiry<2017){
							b[i].t_1 = d[a].t;
							b[i].r_1 = d[a].r;
							cout<<"Enter expiry: ";
							cin>>b[i].expiry;
							break;
						}
					}
				}
				break;
		case 'x':if(r=='+'){
					for(i=18;i<21;i++){
						if(b[i].expiry<2017){
							b[i].t_1 = d[a].t;
							b[i].r_1 = d[a].r;
							cout<<"Enter expiry: ";
							cin>>b[i].expiry;
							break;
						}
					}
				}
				else{
					for(i=21;i<24;i++){
						if(b[i].expiry<2017){
							b[i].t_1 = d[a].t;
							b[i].r_1 = d[a].r;
							cout<<"Enter expiry: ";
							cin>>b[i].expiry;
							break;
						}
					}
				}
				break;
		default: break;
	}
	cout<<b[2].expiry;
}
};
main()
{
	int ch, count = 0;
	class bloodbank b(123,123);
	while(count < 3)
	{
	if(b.authenticate()==0){
	cout<<"\nInvalid Access";
	count++;
	}
	else
		break;
	}

	if(count==3){
	cout<<"Invalid access attempted beyond 3 times, exiting";
	return 1;
	}

	{
		while(1)
		{
			cout<<"\nEnter choice";
			cout<<"\n1)Add donor 2)Update donor 3)Add hospital 4)Donate 5)Exit ";
			cin>>ch;
			switch(ch)
			{
				case 1:
					b.b_register();
					break;
				case 2:
					b.update();
					break;
				case 3:
					b.h_registration();
					break;
				case 4:
					b.donate();
					break;
				case 5:
					return 0;
				default:cout<<"\nInvalid Entry!";
			}
		}
	}

}
