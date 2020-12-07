#include<fstream>
#include<iostream>
#include<string>

using namespace std;

struct Orders
{
	string m_package_id = " ";
	long m_customer_id = 0;
	int m_status = 0;

};
struct Customer
{

	long m_id = 0;
	string m_first_name = "Unknown";
	string m_last_name = "Unknown";
	string m_password = "Unknown";
	string m_email = "Unknown";
	string m_phone = "Unknown";
	int m_points = 0;
	bool m_friends = false;
	Orders* orders = {};


	friend ostream& operator<<(ostream& flux, Customer const& customer);
	friend istream& operator>>(istream& flux, Customer const& customer);
};
ostream& operator<<(ostream& flux, Customer const& customer)
{

	flux << customer.m_id << " " << customer.m_first_name << " " << customer.m_last_name << " " << customer.m_password << " " << customer.m_email << " " << customer.m_phone << endl;


	return flux;
}
istream& operator>>(istream& flux, Customer& customer)
{
	flux >> customer.m_id;
	flux >> customer.m_first_name;
	flux >> customer.m_last_name;
	flux >> customer.m_password;
	flux >> customer.m_email;
	flux >> customer.m_phone;
	return flux;
}

void Change_ID(Customer* arr, long id);
Customer* Read_File_Customer();
void View_DB();
int Size_DB();
void Sign_Up(Customer* arr);
void Home_Page();
void About_Us();
bool Find_ID(Customer* arr, long id);
bool Find_Password(Customer* arr, string password);
void Log_In();
void Log_In_Customer(Customer* arr);
void Customer_Menu(Customer* arr, int index);



int Size_DB()
{
	int size = 0;

	ifstream obj("CustomerDB.txt");
	if (!obj)
	{
		cerr << "ERROR FILE ";
		return 0;
	}
	else
	{
		obj >> size;

		obj.close();
	}
	return size;
}
void View_DB()
{
	int size = Size_DB();

	for (int i = 0; i < size ; i++)
	{
		cout << Read_File_Customer()[i].m_id << " " << Read_File_Customer()[i].m_first_name << " " << Read_File_Customer()[i].m_last_name << " " << Read_File_Customer()[i].m_password << " " << Read_File_Customer()[i].m_email << " " << Read_File_Customer()[i].m_phone << endl;

	}
}
Customer* Read_File_Customer()
{
	int size;

	ifstream obj("CustomerDB.txt");

	if (!obj)
	{
		cout << "error";
	}
	obj >> size;
	if (size == 0)
		obj.close();
	Customer* arr = new Customer[size];
	
	for (int i = 0; i < size; i++)
		obj >> arr[i].m_id >> arr[i].m_first_name >> arr[i].m_last_name >> arr[i].m_password >> arr[i].m_email >> arr[i].m_phone;

	obj.close();

	return arr;
}
void Sign_Up(Customer* arr)
{

	cout << "NEW CUSTOMER" << endl;
	cout << "Customer Details:" << endl;
	cout << "ID: ";
	long id;
	cin >> id;
	while ((Find_ID(arr, id)))
	{
		int choice = 0;
		cout << "ID already in our Customer DB" << endl;
		cout << "1- Try Again." << endl;
		cout << "2- Back To Menu For Log_In" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cin >> id;
			break;
		}
		default:
		{
			return;
			break;
		}
		}
	}
    cout << "First Name: ";
	string first_name;
	cin >> first_name;
	cout << "Last Name: ";
	string last_name;
	cin >> last_name;
	cout << "Password: ";
	string password;
	cin >> password;
	cout << "Email: ";
	string email;
	cin >> email;
	cout << "Phone Number: ";
	string phone;
	cin >> phone;


	Customer customer = { id, first_name, last_name, password, email, phone };// insert new user information

	int size = Size_DB();

	ofstream obj1("CustomerDB.txt");

	if (!obj1)
	{
		cerr << "ERROR OPENING CUSTOMER DB" << endl;
		exit(1);
	}
	else
	{
		
		Customer* temp = new Customer[size];

		for (int i = 0; i < size; i++)
		{
			temp[i].m_id = arr[i].m_id;
			temp[i].m_first_name = arr[i].m_first_name;
			temp[i].m_last_name = arr[i].m_last_name;
			temp[i].m_password = arr[i].m_password;
			temp[i].m_email = arr[i].m_email;
			temp[i].m_phone = arr[i].m_phone;
		}

		size++;

		arr = new Customer[size];

		for (int i = 0; i < size - 1; i++)
		{
			arr[i].m_id = temp[i].m_id;
			arr[i].m_first_name = temp[i].m_first_name;
			arr[i].m_last_name = temp[i].m_last_name;
			arr[i].m_password = temp[i].m_password;
			arr[i].m_email = temp[i].m_email;
			arr[i].m_phone = temp[i].m_phone;
		}

		arr[size - 1] = customer;

		obj1 << size << endl;
		for (int i = 0; i < size; i++)
		{
			obj1 << arr[i].m_id << " " << arr[i].m_first_name << " " << arr[i].m_last_name << " " << arr[i].m_password << " " << arr[i].m_email << " " << arr[i].m_phone << endl;
		}

		
		obj1.close();
	}
}
void Log_In_Customer(Customer* arr)
{
	int size = Size_DB();
	cout << "CUSTOMER LOG IN" << endl;
	cout << "ID: ";
	long id;
	cin >> id;
	while (!(Find_ID(arr, id)))
	{
		
		int choice = 0;
		cout << "No ID in our Customer DB" << endl;
		cout << "1- Try Again." << endl;
		cout << "2- Back To Menu for Sign_Up" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter ID: ";
			cin >> id;
			break;
		}
		default:
		{
			return;
			break;
		}
		}
	}
		
		cout << "Password: ";
		string password;
    	cin >> password;
		while (!(Find_Password(arr, password)))
		{
			int choice = 0;
			cout << "Password Incorrect" << endl;
			cout << "1- Try Again." << endl;
			cout << "2- Forgot Password" << endl;
			cout << "2- Back To Menu" << endl;
			cin >> choice;

			switch (choice)
			{
			case 1:
			{
				cout << "Enter Password: ";
				cin >> password;
				break;
			}
			case 2:
			{
				
				for (int i = 0; i < size ; i++)
				{
					if (id == arr[i].m_id)
						cout << "Your Password is: " << arr[i].m_password << " via email." << endl;
				}
				cout << "Enter Password: ";
				cin >> password;

				break;
			}
			default:
			{
				return;
				break;
			}
			}
		}

		int index = 0;

		for (int i = 0; i < size; i++)
		{
			if (id == arr[i].m_id && password == arr[i].m_password)
			{
				cout << "Welcome to Customer Menu" << endl;
				cout << arr[i];
				index = i;
			}
		}	

		Customer_Menu(arr, index);
}
void Change_ID(Customer* arr, long id)
{

	int size = Size_DB();
	
	ofstream obj1("CustomerDB.txt");
	

	if (!obj1)
	{
		cerr << "ERROR OPENING CUSTOMER DB" << endl;
		exit(1);
	}
	else
	{	

		obj1 << size << endl;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].m_id == id)
			{

				cout << "New ID" << endl;
				cin >> arr[i].m_id;
				obj1 << arr[i].m_id << " " << arr[i].m_first_name << " " << arr[i].m_last_name << " " << arr[i].m_password << " " << arr[i].m_email << " " << arr[i].m_phone << endl;
				
				
			}
			else
				obj1 << arr[i].m_id << " " << arr[i].m_first_name << " " << arr[i].m_last_name << " " << arr[i].m_password << " " << arr[i].m_email << " " << arr[i].m_phone << endl;
		}
		obj1.close();
	}
}
void About_Us()
{
	cout << "When we started in 2003, we set out to do things differently. We wanted to show all flight options in one place, creating a simple alternative to the confusing sites that make travel feel like hard work.Fast forward to todayand we’ve gone from a flight search engine to a global leader in travel.We're proud that more than 100 million people across the world (that's quite a few!) rely on our appand website each month to help them with their travel plans.Dedicated to making travel as simple as possible, we help eachand every one of them find the best options across flights, hotels, and car rentals to book the perfect trip." << endl;
	cout << endl;

}
void Log_In()
{
	
	bool user_type;
	cout << "1- Press 0 for Customer" << endl;
	cout << "2- Press 1 for Agent" << endl; 
	cin >> user_type;
	if (user_type)
	{
		cout << "";//if (agent_login())//If the login is successful transfer to the appropriate menu
			//agent_menu();
	}
	else
	{
		Log_In_Customer(Read_File_Customer());
	}


}
void Home_Page()
{
	int choice = 0;
	cout << "HELLO Welcome to the travel agency Vacation 4 U" << endl;
	while (choice != 6)
	{
		cout << "====================================" << endl;
		cout << "Home Page menu:\n1.About us\n2.Search package\n3.Recommended package\n4.Log-in\n5.sign up\n6.Exit" << endl;
		cout << "====================================" << endl;
		cout << "Please enter your choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			About_Us();
			break;
		
		case 2:
			//search_package();
			break;
		case 3:

			break;
		case 4:
			Log_In();
			break;
		case 5:
			Sign_Up(Read_File_Customer());
			break;
		case 6:
			break;
		default:
			cout << "ERROR input ,please enter a number between 1-6 " << endl;
			break;
		}
	}

}
bool Find_ID(Customer* arr, long id)
{
	int size = Size_DB();

	for (int i = 0; i < size; i++)
	{
		if (id == arr[i].m_id)
			return true;
	}
	return false;
}
bool Find_Password(Customer* arr, string password)
{
	int size = Size_DB();

	for (int i = 0; i < size; i++)
	{
		if (password == arr[i].m_password)
			return true;
	}
	return false;
}
void Customer_Menu(Customer* arr, int index)
{
	cout << arr[index];
}

int main()
{
	Home_Page();
	
	return 0;
}





