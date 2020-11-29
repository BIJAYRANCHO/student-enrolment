#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <iomanip> 
#include <string.h>

using namespace std;
void StudentRecordsSubMenu();
void addStudent();
void viewStudent();

class student
{
   int SID;
   char SURNAME[30];
   char NAME
public:
   student() { }
   void getData(); 
   void displayData(); 
};
 
void student :: getData() {
   cout << "\nEnter SID No. :: ";
   cin >> SID;
   cin.ignore(); 
   cout << "\nEnter SURNAME :: ";
   cin.getline(SURNAME, 30);
   cout << "\nEnter NAME :: ";
   cin >> NAME;
}
 
void student :: displayData() {
   cout << "\nSID No. :: " << SID << endl;
   cout << "\nSURNAME :: " << SURNAME << endl;
   cout << "\nNAME :: " << NAME << endl;
}

 void Enrolments()
{

	string CODE;
	string SID;
	int CA;
	float EXAM;

}

int main()
{	
	int a;
	while(true)
	{
		cout<<"\t\t\t\tMAIN MENU"<<endl;
		cout<<"\t\t\t\t========="<<endl;
		cout<<"\t\t\t\t1.	Manage Student Records"<<endl;
		cout<<"\t\t\t\t2. 	Manage enrolment Records"<<endl;
		cout<<"\t\t\t\t3. 	Generate Student Reports"<<endl;
		cout<<"\t\t\t\t4.	Generate Course Summarics"<<endl;
		cout<<"\t\t\t\t5. 	Exit"<<endl;
		cout<<endl;
		cout<<"\t\t\t\t================================="<<endl;
		
		
		// ofstream 01("students.txt", ios::out);
		
		cout<<" enter your choice : ";
		cin>>a;
		switch(a)
		{
			case 1:
				StudentRecordsSubMenu();
				break;

			case 2:
				cout<<" enrolment Records";
				break;

			case 3:
				cout<<" Student Reports";
				break;

			case 4:
				cout<<" Course Summarics";
				break;

			case 5:
				cout<<" Exeted";
				exit(1);

			default :
			{
				cout<<" wrong choice "<<endl;
			}					
		}
	}
	
	return 0;

}

void StudentRecordsSubMenu()
{	int ch;
	while(true)
	{
	cout<<"MANAGE STUDENTS RECORD SUB MENU"<<endl;
	cout<<"================================="<<endl;
	cout<<endl;
	cout<<"1.	Add New Student Records"<<endl;
	cout<<"2.	View Student Records"<<endl;
	cout<<"3.	Return to MAIN MENU"<<endl;
	cout<<endl;
	cout<<"==================================="<<endl;
	
	cout<<"enter your choice : ";
	cin>>ch;

	switch(ch)
		{
			case 1:
				addStudent();
				break;
			case 2:
				viewStudent();	
				break;	
			default:
				cout<<"wrong choice"<<endl;	
		}	
	}
	

}
void viewStudent()
{
	ofstream fout; 
  
    string line; 
  
    
    fout.open("students.txt"); 
 
    while (fout) { 
  
        getline(cin, line); 
        if (line == "-1") 
            break; 
  
        // Write line in file 
        fout << line << endl; 
    } 
  
    fout.close(); 
  
    ifstream fin; 
  
    
    fin.open("students.txt"); 
  
    
    while (fin) { 
 
        getline(fin, line); 
  
        cout << line << endl; 
    } 
      fin.close(); 
  

}

void addStudent()
{

   student s[100]; 
   fstream file;
   int i;
 
   file.open("students.txt", ios :: out); // open file for writing
    cout << "\nWriting Student information to the file :- " << endl;
    cout << "\nEnter student's Details to the File :- " << endl;
 
   for (i = 0; i < sizeof(s)/sizeof(s[0]); i++)
    {
      s[i].getData();
      file.write((char *)&s[i], sizeof(s[i]));
    }
 
   file.close(); // close the file
 
   file.open("students.txt", ios :: in); 
   cout << "\nReading Student information to the file :- " << endl;
 
   for (i = 0; i < 3; i++)
    {
      file.read((char *)&s[i], sizeof(s[i]));
      s[i].displayData();
    }
 
   file.close();

}