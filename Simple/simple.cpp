#include<conio.h>
#include<iostream>
#include<fstream>
#define endl "\n"
#define is ==
#define isnot !=
#define next cout<<endl
using namespace std;

/*
Session Variables
After Login it will be Updated.
*/
static string _NAME = "";
static string _EMAIL = "";
static string _MOB = "";
static string _DOB = "";
bool flagLogin = false;

/* Function Prototype Declarations*/
int men();
int women();
int signout();
int cart();
int Discounted();
int NonDiscounted();
int signin();
int signup();
int MenClothes(bool);
int MenFootwearDiscounted();

/*
	Tools class having functions -
	1. wait
	2. clear
	3. option
	4. signup
	5. signin
*/
class tools;

class tools{
private:
	string name,email,mobile,dob,password;
public:
	string x;
 
 /* Wait Function */
 void _wait(){
 	cout<<endl<<"press enter to continue...";
 	getch();
 }

 /* Clear Screen */
 void _clear(){
 	system("cls");
 }

 /*Option Taker*/
 int _option(){
 	int n;
 	cout<<"enter option: ";
 	cin>>n;
 	return n;
 }

 /* Signup Form */
 void _signup(){
 	cout<<endl;
 	cout<<"Enter Name: "<<endl;
 	getchar();
 	getline(cin,x);
 	this->name=x;
 	cout<<"Email-id: "<<endl;
 	cin>>x;
 	this->email=x;
 	cout<<"Password: "<<endl;
 	cin>>x;
 	this->password=x;
 	cout<<"DOB: "<<endl;
 	cin>>x;
 	this->dob=x;
 	cout<<"Mobile no.: "<<endl;
 	cin>>x;
 	this->mobile=x;
 	/*
		Files in which it is saved - 
		1. username
		2. password
		3. name
		4. dob
		5. mobile

		ios::app
 	*/
 	ofstream fout;
 	
 	fout.open("UserData/username.sari",ios::app);
 	fout<<this->email;
 	fout<<"\n";
 	fout.close();

 	fout.open("UserData/password.sari",ios::app);
 	fout<<this->password;
 	fout<<"\n";
 	fout.close();

 	fout.open("UserData/name.sari",ios::app);
 	fout<<this->name;
 	fout<<"\n";
 	fout.close();

 	fout.open("UserData/dob.sari",ios::app);
 	fout<<this->dob;
 	fout<<"\n";
 	fout.close();

 	fout.open("UserData/mobile.sari",ios::app);
 	fout<<this->mobile;
 	fout<<"\n";
 	fout.close();
 }

/*Sign in Form*/
 void _signin(){
 	cout<<"Email-id: "<<endl;
 	cin>>x;
 	this->email=x;
 	cout<<"Password: "<<endl;
 	cin>>x;
 	this->password=x;

 	/* CHECK DATA */

 	ifstream fin1,fin2,fin3,fin4,fin5;
 	string user,pass,name,mob,dob;
 	fin1.open("UserData/username.sari",ios::in);
	fin2.open("UserData/password.sari",ios::in);
	fin3.open("UserData/name.sari",ios::in);
	fin4.open("UserData/dob.sari",ios::in);
	fin5.open("UserData/mobile.sari",ios::in);

 	while(getline(fin1,user,'\n')){

 		/*User Authentication*/
 		getline(fin2,pass,'\n');

 		/*User Data*/
 		getline(fin3,name,'\n');
 		getline(fin4,dob,'\n');
 		getline(fin5,mob,'\n');

 		if(this->email == user && this->password == pass){
 			cout<<"\nLogin Successfull ... \n";
 			_NAME = name;
 			_EMAIL = user;
 			_DOB = dob;
 			_MOB = mob;
 			flagLogin = true;
 			break;
 		}
 	}
 }
};

/* Linked List*/
/* Same as Linked List Node*/
class CartNode{
public:
	int itemId;
	string itemName;
	float price;
	CartNode *nextItem;
};

/* Same as Linked List Functions
	1. Add in end
	2. Delete by id
*/
class Cart{
public:
	void AddItem(CartNode **head,int itemID,string itemName,float price){
		CartNode *new_item = new CartNode();
		new_item->itemID = itemID;
		new_item->itemName = itemName;
		new_item->price = price;
		new_item->nextItem = NULL;

		if(head == NULL){
			*head = new_item;
		}else{
			CartNode *temp = *head;
			while(temp->new_item!=NULL){
				temp = temp->nextItem;
			}
			temp->nextItem = new_item;
		}
	}
}


int main(){
  tools obj;

  while(true){
	obj._clear();
	cout<<"     *WELCOME\n     **TO*\n** SARREE SHOPPING **";
	cout<<endl;
	cout<<"WELCOME..."<<_NAME;
	cout<<endl;
	if(flagLogin isnot true){
		cout<<"MAIN_MENU\n1. MEN\n2. WOMEN\n3. SIGNIN\n4. SIGNUP\n5. EXIT ";
		next;
	}else{
		cout<<"MAIN_MENU\n1. MEN\n2. WOMEN\n3. CART\n4. SIGNOUT\n5. EXIT ";
		next;
	}
	if(flagLogin is true){
		next;
		next;
		cout<<"Welcome, "<<_NAME<<"\n";
		cout<<"Email : "<<_EMAIL<<"\n";
		cout<<"Mobile Number : "<<_MOB<<"\n";
		next;
	}
	int option=obj._option();
		switch(option){
			case 1: men();break;
			case 2: break;
			case 3: {
				if(flagLogin isnot true){
					signin();
				}else{
					cart();
				}
			}
			break;
			case 4: {
				if(flagLogin isnot true){
					signup();
				}else{
					signout();
				}
			} break;
			case 5: exit(0);break;
		}
	}
		return 0;
	}

int signin(){
	tools obj;
	obj._clear();
	cout<<endl<<"***SIGN IN**"<<endl;
	cout<<"       PAGE        "<<endl;
	obj._signin();
 	obj._wait();
 	return 0;
}

int signup(){
 	tools obj;
	obj._clear();
	cout<<endl<<"***SIGN UP**"<<endl;
	cout<<"       PAGE        ";
	obj._signup();
	obj._wait();
	return 0;
}


int men(){
	tools obj;
	obj._clear();
	cout<<"     *WELCOME\n     **TO*\n** SARREE SHOPPING **";
	next;
	cout<<"WELCOME..."<<_NAME;
	next;
	cout<<"\n1. Discounted\n2. NonDiscounted\n3. Back ";
	next;
	int option=obj._option();
	switch(option){
		case 1: Discounted();break;
		case 2: NonDiscounted();break;
		case 3: return 0;break;
	}
	obj._wait();
	return 0;
}

int Discounted(){
	tools obj;
	obj._clear();
	cout<<"     *WELCOME\n     **TO*\n** SARREE SHOPPING **";
	next;
	cout<<"WELCOME..."<<_NAME;
	next;
	cout<<"MAIN_MENU\n1. Clothes\n2. Footwears\n3. Back ";
	next;
	int option=obj._option();

	switch(option){
		case 1: MenClothes(true);break;
		case 2: MenFootwearDiscounted();break;
		case 3: return 0;
	}
	obj._wait();
	return 0;
}

int NonDiscounted(){
	return 0;
}

int women(){
	return 0;
}

int signout(){
	flagLogin = false;
	_NAME = _EMAIL = _MOB = _DOB = "";
	return 0;
}

int cart(){
	return 0;
}

int MenClothes(bool isDiscounted = false){
	CartNode *head = NULL;
	if(isDiscounted is true){
		// show discounted clothes
		cout<<"Item Id\tItem Name\tActual Price\tDiscount\tGST\tBuy Price";next;
		cout<<"101\tShirt 01\tRs  560\t\t20 %\t\t5 %\tRs. 558.6";next;
		cout<<"102\tShirt 01\tRs  560\t\t20 %\t\t5 %\tRs. 558.6";next;
		cout<<"103\tShirt 01\tRs  560\t\t20 %\t\t5 %\tRs. 558.6";next;
		cout<<"104\tShirt 01\tRs  560\t\t20 %\t\t5 %\tRs. 558.6";next;
		cout<<"105\tShirt 01\tRs  560\t\t20 %\t\t5 %\tRs. 558.6";next;

		int itemId;
		cout<<"Enter Item Id : ";
		switch(itemId){
			case 101:{
				//add item in cart.

			}break;
		}

	}else{
		// show non discounted clothes
	}
	return 0;
}

int MenFootwearDiscounted(){
	return 0;
}