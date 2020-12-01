#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void home_page();
void about_us();
void search_package();
void flight();
void hotels();
void vacation();
void organized_tour();
void login();
bool sign_up();
bool agent_login();
bool customer_login();
void agent_menu();
void customer_menu();

int main()
{
	home_page();
}
void home_page()
{
	int choice=0;
	cout << "HELLO Welcome to the travel agency Vacation 4 U" << endl;
	while (choice != 6)
	{
		cout << "====================================" << endl;
		cout << "Home Page menu:\n1.About us\n2.Search package\n3.Recommended package\n4.Log-in\n5.sign up\n6.Exit" <<endl;
		cout << "====================================" << endl;
		cout << "Please enter your choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			about_us();
			break;
		case 2:
			search_package();
			break;
		case 3:

			break;
		case 4:
			login();
			break;
		case 5:
			sign_up();
			break;
		case 6:
			break;
		default:
			cout << "ERROR input ,please enter a number between 1-6 " << endl;
			break;
		}
	}

}
void about_us()
{
	cout << "When we started in 2003, we set out to do things differently. We wanted to show all flight options in one place, creating a simple alternative to the confusing sites that make travel feel like hard work.Fast forward to todayand we’ve gone from a flight search engine to a global leader in travel.We're proud that more than 100 million people across the world (that's quite a few!) rely on our appand website each month to help them with their travel plans.Dedicated to making travel as simple as possible, we help eachand every one of them find the best options across flights, hotels, and car rentals to book the perfect trip." << endl;
	cout << endl;

}
void search_package()
{
	int choice;
	cout << "What are you looking for?" << endl;
	cout << "1.Flight\n2.Hotels\n3.Vacation\n4.Organized tour\n5.return to Home page" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		flight();
		break;
	case 2:
		hotels();
		break;
	case 3:
		vacation();
		break;
	case 4:
		organized_tour();
		break;
	case 5:
		home_page();

	default:
		cout << "ERROR input please insert a number between 1-5" << endl;
		break;
	}
}
void login()
{
	//להכניס פה רישום או לוותר על רישום מהלוג אין
	bool user_type;
	cout << "Agent or client?\nTo log in as an agent press 1,To log in as an customer press something else " << endl;
	cin >> user_type;
	if (user_type)
	{
		if (agent_login())//If the login is successful transfer to the appropriate menu
			agent_menu();
		

	}
	else if (customer_login())
		customer_menu();


}

bool agent_login()
{
	long id, company_code;
	cout << "ID number:" << endl;
	cin >> id;
	if (id)
	{
		cout << "company code:" << endl;
		cin >> company_code;
		if (company_code)
			return true;
		else
		{
			cout << "inncorect company code" << endl;
			return false;
		}
	}
	else
	{
		cout << "the id does'nt exsit" << endl;
		return false;
	}
}

bool customer_login()
{

	long id, password;
	cout << "ID number:" << endl;
	cin >> id;
	//לחפש במאגר האם התז קיים בו ולהחזיר אמת שקר בהתאם
	if (id)
	{
		cout << "password:" << endl;
		cin >> password;
		if (password)
			return true;
		else
		{
			cout << "inncorect password" << endl;
			return false;
		}
	}
	else
	{
		cout << "the id does'nt exsit" << endl;
		return false;
	}
}
void agent_menu()
{
	
	int choice = 0;
	
	while (choice != 5)
	{
		cout << "====================================" << endl;
		cout << "Menu:\n1.Add package\n2.customer's order\n3.Answer customer\n4.Package DB\n5.return to home page" << endl; 
		cout << "====================================" << endl;
		cout << "Please enter your choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			
			break;
		case 2:
		
			break;
		case 3:

			break;
		case 4:
			
			break;
		case 5:
			home_page();
			break;
		
		default:
			cout << "ERROR input ,please enter a number between 1-5 " << endl;
			break;
		}
	}
	
}
void customer_menu()
{}
bool sign_up()
{
	//אחרי כל קליטה עדכון של המסד נתונים
	long id, password;
	string name, last_name;
	char email[30];
	do
	{
		cout << "ID number:" << endl;
		cin >> id;
	} while (id);
	{
		cout << "The ID already exists" << endl;
	}
	cout << "name:" << endl;
	cin >> name;
	cout << "last name:" << endl;
	cin >> last_name;
	cout << "password" << endl;
	cin >> password;
	cout << "Email:" << endl;
	cin >> email;
	//להוסיף תנאי אם הכנסת הפרטים למאגר  הצליחה להחזיר אמת אחרת שקר  
	return true;
	
}

void flight()
{
	//TODO להוסיף את הפילטרים ולעשות קישור לדאטה בייס בפלוס בדיקות קלט לתאריך
	string destination, source;
	int day, month, year;
	bool direction;
	cout << "date:\n\nday" << endl;
	cin >> day;
	cout << "month" << endl;
	cin >> month;
	cout << "year" << endl;
	cin >> year;
	cout << "source" << endl;
	cin >> source;
	cout << "destination" << endl;
	cin >> destination;

}

void hotels()
{
	//TODO להוסיף את הפילטרים ולעשות קישור לדאטה בייס
	string destination;
	int day, month, year, num_of_star;
	cout << "date:\nday" << endl;
	cin >> day;
	cout << "month" << endl;
	cin >> month;
	cout << "year" << endl;
	cin >> year;
	cout << "destination" << endl;
	cin >> destination;
}
void vacation()
{
	flight();
	hotels();
}
void organized_tour()
{
	//TODO
}
