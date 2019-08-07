#include<bits/stdc++.h>
using namespace std;

class EncryptionDecryption {
	private:
		string outputstring;
		string inputstring;
		string encpass;
		string decpass;
		int enckey;
		int deckey;
		int temp;
		char tempc;
	public:
		EncryptionDecryption();
		EncryptionDecryption(string);	
		void setInputString(string);
		~EncryptionDecryption();
		int checkEncPass(string);
		int checkDecPass(string);
		void getOutputString();
		void setKey(string);
		void doEncryption();
		void doDecryption();
};

//function for Encryption
// taking characters from 33 to 126 (ASCII)
void EncryptionDecryption::doEncryption() {
	int key = enckey;
	for(int i=0;i<inputstring.size();i++) {
		temp = (int)inputstring[i];
		temp = temp + key;
		temp = temp%94;
		if(temp<0) temp+=94;
		temp = temp + 33;
		tempc = (char)temp;
		outputstring += tempc; 
		key++;
	}

}

//function for Decryption
void EncryptionDecryption::doDecryption() {
	int key = deckey;
	for(int i=0;i<inputstring.size();i++) {
		temp = (int)inputstring[i];
		temp = temp + key;
		temp = temp%94;
		if(temp<0) temp+=94;
		temp-=33;
		if(temp < 33) temp+=94;
		tempc = (char)temp;
		outputstring += tempc;
		key--;
	}
}



void EncryptionDecryption::getOutputString() {
	outputstring += '\0';
	cout << "The Encrypted/Decrypted string is"  <<" : "<<outputstring;	
	outputstring="";
}

//check the password
int EncryptionDecryption::checkEncPass(string pass) {
	if(pass!=encpass)
	{	
		return 0;
	}	
	else {
		return 1;
	}	
}

//check the password
int EncryptionDecryption::checkDecPass(string pass) {
	if(pass!=decpass)
	{	
		return 0;
	}	
	else {
		return 1;
	}	
}

//Initializer
EncryptionDecryption::EncryptionDecryption() {
	inputstring = "";
	outputstring = "";
	encpass= "111"; //this is the password
	decpass= "000";
	temp= 0;
	tempc='\0';
}


EncryptionDecryption::EncryptionDecryption(string e) { 
	inputstring = e;
}

void EncryptionDecryption::setInputString(string f) {
	inputstring=f;
}

EncryptionDecryption::~EncryptionDecryption() {
}

void EncryptionDecryption::setKey(string key){
	int k=0;
	for(int i=0;i<key.size();i++){
		k = k + (int)key[i];
		k %= 94;
	}
	enckey = k;
	deckey = -1*k;
}

//The program begins here
int main() 

{

	string inputstring;
	string pass;
	char ch;
	bool quit=false;
	EncryptionDecryption O1; //creating object

	//Which operation you want to perform
		cout << "\n******************************************";
		cout << "\nMenu\n";
		cout << "1. Encryption\n";
		cout << "2. Decryption\n";
		cout << "3. Quit\n";
		cout << "******************************************";
		

	while(!quit)
	{
		quit = false;
		cout << "\nEnter the choice to perform the task";
		cout << "\nEnter 1 or 2 or 3: ";	
		cin >> ch;
		

		switch(ch)
		{
			case '1':
				cout << "Enter word to Encrypt: ";
				cin.ignore();
				getline(cin, inputstring);
					
				O1.setInputString(inputstring); //set the encryption text
				
				cout << "Enter the password to proceed Encryption: ";
				getline(cin, pass);
				
				if(O1.checkEncPass(pass)==1) { //check encryption password and then do encryption if the password is correct
					cout<<"Enter the Key for Encryption : ";
					string key;
					getline(cin, key);
					O1.setKey(key);
					O1.doEncryption();
					O1.getOutputString();
				}
				else {
					cout << endl << "The password you entered is Incorrect the, Encryption will not proceed.\nTry Again \n";
					break;
				}
	
				break;

			case '2':
				cout << "Enter word to Decrypt: ";
				cin.ignore();
				getline(cin, inputstring);

				O1.setInputString(inputstring); //set the decryption string

				cout << "Enter the password to proceed Decryption: ";
				getline(cin, pass);
				
				if(O1.checkDecPass(pass)==1) { //check decryption password and then do decryption if the password is correct
					cout<<"Enter the Key for Encryption : ";
					string key;
					getline(cin, key);
					O1.setKey(key);
					O1.doDecryption();
					O1.getOutputString();
				}
				else {
					cout << endl << "The password you entered is Incorrect the, Decryption will not proceed.\nTry Again \n";
					break;
				} 		
				break;

			case '3':
				cout<< "Exiting the program";
				quit=true;
				break;
			case '\n':
        		case '\t':
        		case ' ':
            			break;			   
			default:
				cout<<"Wrong Choice";
				quit=false;
				break;	
			}
		cout << "\n\n";
	}

	return 0;
}
