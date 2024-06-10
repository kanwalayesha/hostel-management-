#include <iostream>
#include <fstream>
#include<string>
#include <iomanip>
int c=0, c1=0;
using namespace std;
class Admin
{
protected:
    string enter_password;
    string password = "12";

public:
	string name;
    string time;
    string date;
    
	Admin (string p)
    {
        enter_password = p;
        if (password == enter_password)
        {
            cout << "Login successfully :)" << endl;
        }
        else
        {
            cout << "Invalid password :(" << endl;
            exit(0); // Exit the program if the password is invalid
        } 
   }
    
	Admin(string n, string t, string d)
    {
        name = n;
        time = t;
        date = d;
    }

    void AdminDetails()
    {
        ofstream onFile;
        onFile.open("Admin.txt");
        {
		
        onFile << "===================================================================================" << endl;
        onFile << "***" << setw(60) << "INFORMATION OF THE PERSON WHO ADMITTED THE STUDENT" << setw(20) << "***" << endl;
        onFile << "===================================================================================" << endl;
        onFile << "Name (Male / Female) =  " << name << endl;
        onFile << "Admission Time =  " << time << endl;
        onFile << "Admission Date =  " << date << endl;
        onFile.close();
        }
    }
    void displayAdmin()
    {
    	ifstream inFile;
        string line;
        inFile.open("Admin.txt");
        while (getline(inFile, line))
        {
            cout << line << "\n";
        }
        inFile.close();
	}
};
class Mess
{
private:
    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    string b_f[7] = {"Puri Channy", "Halva", "Anda Pratha", "Paya", "Desi Haleem", "Chai Partha", "Qeema"};
    string d_m[7] = {"Chicken", "Biryani", "Bhindi", "Dal", "Aloo", "Fried Rice", "White Chicken"};

public:
    void DayMenu()
    { 
    
    	string time;
    	cout <<"Chocie for => Breakfast / Dinner\n";
    	cin >> time;
    	if(time == "Breakfast" ||time == "breakfast" || time == "dinner"|| time == "Dinner")
    	{
	        for (int i = 0; i < 7; i++)
	        {
	        	if (time == "Breakfast" || time == "breakfast")
	        	{
	           		cout << i + 1 << "= " << time <<" Menu" << days[i] << " = " << b_f[i] << endl;
	            }
	        	else if (time == "Dinner" || time == "dinner")
	        	{
	            	cout << i + 1 << "= " << time <<" Menu" << days[i] << " = " << d_m[i] << endl;
	            }
	        }
        }

    //friend void sum(Mess, Student);
}
};
class Student : public Mess
{
public:
    int n;

    string name[200];
    string father_name[200];
    string address[200];
    string phone_no[200];
    int cnic_no[200];
    string choice[200];
   // string bill[200];
 //   string add_mess="10000";
    //string hostel_charges="15000";
  //  int s[200];
    
    void StudentInformation()
    {
        int n;
        cout << "The Number of Student You want to admit: " << endl;
        cin >> n;
        
        for (int i = c; i <n+c; i++)
        {
	        cout <<i+1 << ". Student"<< endl;
	        cin.ignore();
	        cout << "Student name: " << endl;
	        getline(cin, name[i]);
	        cout << "Father name: " << endl;
	        getline(cin, father_name[i]);
	        cout << "Address: " << endl;
	        getline(cin, address[i]);
	        cout << "Phone Number: " << endl;
	        getline(cin, phone_no[i]);
	        cout << "Student CNIC NO: " << endl;
	        cin >> cnic_no[i];
	        
        }
        c=c+n;
    }
    void saveInFile()
    {
    	ofstream student;
    	student.open("ayesha.txt", ios::app | ios::out );
    	if(student.fail())
    	{
    		cout <<"\nError Opening File\n\n";
		}
        for(int i=0; i<c; i++)
        {
        	student << cnic_no[i] << endl;
        	student << name[i] << endl;
        	student << father_name[i] << endl;
        	student << address[i] << endl;
        	student << phone_no[i] << endl;
        	
		}
		student.close();
	}
	void displayStudent()
	{
		
		int i=0;
		int id;
	
		cout <<"\nEnter the Student ID That you want to display: ";
		cin >> id;
		ifstream display;
		display.open("ayesha.txt", ios::app | ios::in );
		if(display.fail())
		{
			cout <<"\nError Opening File\n\n";
		}
		
		display >> cnic_no[i];
		display.ignore();
		getline(display,name[i]);
        getline(display,father_name[i]);
        getline(display,address[i]);
        getline(display, phone_no[i]);
        
		while(!display.eof())
		{
			if(cnic_no[i] == id)
			{
				cout <<"\nCongratulation! Hostel Student ID Displayed Successfully....\n";
				cout <<"ID: " << cnic_no[i] << endl;
				cout <<"Name: " <<name[i] << endl;
				cout <<"Father Name: " << father_name[i] << endl;
				cout <<"Address: " << address[i] << endl;
				cout <<"Phone No:  " << phone_no[i] << endl;
		    }
		    i++;
		    display >> cnic_no[i];
			display.ignore();
			getline(display,name[i]);
	        getline(display,father_name[i]);
	        getline(display,address[i]);
	        getline(display, phone_no[i]);
	        
		    
		}
		display.close();
		
	}
	void searchStudent()
	{
		system("cls");
		int i=0;
		int id;
	
		cout <<"\nEnter the Student ID That you want to Search: ";
		cin >> id;
		ifstream search;
		search.open("ayesha.txt", ios::app | ios::in );
		if(search.fail())
		{
			cout <<"\nError Opening File\n\n";
		}
		
		search >> cnic_no[i];
		search.ignore();
		getline(search,name[i]);
        getline(search,father_name[i]);
        getline(search,address[i]);
        getline(search, phone_no[i]);
        
		while(!search.eof())
		{
			if(cnic_no[i] == id)
			{
				cout <<"\nCongratulation! Hostel Student ID Searched Successfully.....\n";
				cout <<"ID: " << cnic_no[i] << endl;
				cout <<"Name: " <<name[i] << endl;
				cout <<"Father Name: " << father_name[i] << endl;
				cout <<"Address: " << address[i] << endl;
				cout <<"Phone No:  " << phone_no[i] << endl;
		    }
		    i++;
		    search >> cnic_no[i];
			search.ignore();
			getline(search,name[i]);
	        getline(search,father_name[i]);
	        getline(search,address[i]);
	        getline(search, phone_no[i]);
	        
		    
		}
		search.close();
		
	}
	void deleteStudent()
	{
		system("cls");
		int i=0;
		int id;
	
		cout <<"\nEnter the Student ID That you want to Delete: ";
		cin >> id;
		ofstream write;
		write.open("newfile.txt", ios::app | ios::out);
		ifstream deleteID;
		deleteID.open("ayesha.txt", ios::app | ios::in );
		
		if(write.fail())
		{
			cout <<"\nError Opening File\n\n";
		}
		
		deleteID >> cnic_no[i];
		deleteID.ignore();
		getline(deleteID,name[i]);
        getline(deleteID,father_name[i]);
        getline(deleteID,address[i]);
        getline(deleteID, phone_no[i]);
        
		while(!deleteID.eof())
		{
			if(cnic_no[i] != id)
			{
				
				write << cnic_no[i] << endl;
				write << name[i] << endl;
				write << father_name[i] << endl;
				write << address[i] << endl;
				write << phone_no[i] << endl;
		    }
		    i++;
		    deleteID >> cnic_no[i];
			deleteID.ignore();
			getline(deleteID,name[i]);
	        getline(deleteID,father_name[i]);
	        getline(deleteID,address[i]);
	        getline(deleteID, phone_no[i]);
	        
		    
		}
		deleteID.close();
		write.close();
		remove("ayesha.txt");
		rename("newfile.txt", "ayesha.txt");		
	
	}
		void updateStudent()
		{
			system("cls");
			int i=0;
			int id, cnic;
			string nam, fatherName, addres, phoneNo;
			
			cin.ignore();
	    	cout << "Student name: " << endl;
	        getline(cin, nam);
	        cout << "Father name: " << endl;
	        getline(cin, fatherName);
	        cout << "Address: " << endl;
	        getline(cin, addres);
	        cout << "Phone Number: " << endl;
	        getline(cin, phoneNo);
	        cout << "Student CNIC NO: " << endl;
	        cin >> cnic;
		
			cout <<"\nEnter the Student ID That you want to Update: ";
			cin >> id;
				ofstream update;
			update.open("file.txt", ios::app | ios::out);
			ifstream updateID;
			updateID.open("ayesha.txt", ios::app | ios::in );
			
			if(update.fail())
			{
				cout <<"\nError Opening File\n\n";
			}
			
			updateID >> cnic_no[i];
			updateID.ignore();
			getline(updateID,name[i]);
	        getline(updateID,father_name[i]);
	        getline(updateID,address[i]);
	        getline(updateID, phone_no[i]);
	        
			while(!updateID.eof())
			{
				if(cnic_no[i] != id)
				{
					update << cnic_no[i] << endl;
			    	update << name[i] << endl;
		    		update << father_name[i] << endl;
			    	update << address[i] << endl;
			    	update << phone_no[i] << endl;
					
			    }
			    else 
			    {
			    	update << cnic << endl;
					update << nam << endl;
					update << fatherName << endl;
					update << addres << endl;
					update << phoneNo << endl;
				}
			    i++;
			    
			    updateID >> cnic_no[i];
				updateID.ignore();
				getline(updateID,name[i]);
		        getline(updateID,father_name[i]);
		        getline(updateID,address[i]);
		        getline(updateID, phone_no[i]);
		        
			    
			}
			updateID.close();
			update.close();
			remove("ayesha.txt");
			rename("file.txt", "ayesha.txt");
			
		}
};

int main()
{

	string password, name, time, date;
	cout <<"Enter the Login Password\n";
	cin >> password;
	Admin a(password);
	cout << "===================================================================================" << endl;
    cout << "***" << setw(60) << "WHO IS ADMITTING THE STUDENT IN THE HOSTEL. THEY WROTE THEIR INFORMATION" << setw(20) << "***" << endl;
    cout << "===================================================================================" << endl;

    cin.ignore();
    cout <<"\nAdmin Details.\n\n";
    cout << "Name male/female: " << endl;
    getline(cin, name);
    cout << "Admission Time: " << endl;
    getline(cin, time);
    cout << "Admission Date: " << endl;
    getline(cin, date);
 	
 	// constructor calling
	Admin d(name, time, date);
	d.AdminDetails();
	d.displayAdmin();
	Mess m;
	m.DayMenu();
	Student s;
	int choice;
	menu:
	cout <<"1. Add" << endl;
	cout <<"2. Display" << endl;
	cout <<"3. Search" << endl;
	cout <<"4. Update" << endl;
	cout <<"5. Delete" << endl;
	cout <<"0. Exit" << endl;
	cout <<"\n\nEnter the user choice: ";
	cin >> choice;
	switch (choice)
	{
		case 1:
			s.StudentInformation();
			s.saveInFile();
			goto menu;
			break;
		case 2:
			s.displayStudent();
			goto menu;
			break;
		case 3:
			s.searchStudent();
			goto menu;
			break;
		case 4:
			s.updateStudent();
			goto menu;
			break;
		case 5:
			s.deleteStudent();
			goto menu;
			break;
		case 0:
		 	cout <<"\ninvalid Input\n\n";
		 	cout <<"Press 1 for exit / Press 2 for back to menu\n";
			cin >> choice;
			if (choice == 1)
			{
				cout <<"Thank You For Visiting My Hostel\n";
			}
			else if (choice ==2)
			{
				goto menu;
			}

		
	}
}
