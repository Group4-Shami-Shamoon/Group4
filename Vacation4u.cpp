#define _CRT_SECURE_NO_WARNINGS
#include<fstream>
#include<iostream>
#include<string>
#include <sstream>
#include <climits>
#include <regex>

long log_in_id = 0;
int flag = 0;

#define CompanyCode "123"
#define AgentSalary 5000
#define ManagerID 123456789
#define ManagerCompanyCode "v4u"


using namespace std;


//////////////////////////////////////////STRUCT/////////////////////////////////////////////////////////////////


struct Date
{
	int m_day;
	int m_month;
	int m_year;
	Date()
	{
		m_day = 0;
		m_month = 0;
		m_year = 0;
	}
	friend ostream& operator << (ostream& os, const Date& d);
	friend istream& operator >> (istream& is, Date& d);

	bool operator==(const Date& d);
	bool operator<(const Date& d)
	{
		if (m_year > d.m_year)return false;
		else if (m_year < d.m_year)return true;
		else if (m_month > d.m_month)return false;
		else if (m_month < d.m_month)return true;
		else if (m_day > d.m_day)return false;
		else if (m_day <= d.m_day)return true;
		return false;
	}
	bool operator>(const Date& d)
	{
		if (m_year < d.m_year)return false;
		else if (m_year > d.m_year)return true;
		else if (m_month < d.m_month)return false;
		else if (m_month > d.m_month)return true;
		else if (m_day < d.m_day)return false;
		else if (m_day >= d.m_day)return true;
		return false;
	}
};
struct Messages {

	long m_message_id = 0;
	long m_customer_id = 0;
	string m_area = " ";
	string m_massege = " ";
};
struct Orders
{
	string m_package_id = " ";
	long m_customer_id = 0;
	bool m_friends = 0;
	string m_status = " ";

	friend ostream& operator<<(ostream& flux, Orders const& customer);
	friend istream& operator>>(istream& flux, Orders const& customer);
};
typedef struct
{
	string m_package_id;
	Date m_start;
	Date m_end;
	float m_price;
	string m_area;
	string m_origin;
	string m_destinion;
	int m_num_of_travelers;
	int m_quantity;
	int m_sales_counter;
	long m_agent_id;
	int m_points;
	bool m_organized_trip;
	string m_description;

}Packages;
typedef struct
{
	long m_id;
	string m_first_name;
	string m_last_name;
	string m_area;
	int m_sales;

}Agent;
typedef struct
{
	string m_flight_id;
	string m_departure_location;
	string m_arrival_location;
	Date m_departure_date;
	Date m_return_date;
	float m_price;
	string m_area;
	char m_class_f;
	int m_quantity;
	bool m_direct;
	bool m_one_way;
	int m_sales_counter;
	long m_agent_id;
	string m_description;


}Flights;
typedef struct
{
	string m_hotel_id;
	string m_hotel_name;
	string m_hotel_location;
	Date m_check_in;
	Date m_check_out;
	int m_guest;
	bool m_room_type; // true if suit false standart room.
	int m_rating;
	float m_price;
	int m_quantity;
	int m_sales_counter;
	long m_agent_id;
	string m_area;
	string m_description;
}Hotels;
struct Customer
{

	long m_id = 0;
	string m_first_name = "Unknown";
	string m_last_name = "Unknown";
	string m_password = "Unknown";
	string m_email = "Unknown";
	string m_phone = "Unknown";
	int m_points = 0;




	friend ostream& operator<<(ostream& flux, Customer const& customer);
	friend istream& operator>>(istream& flux, Customer const& customer);
};



ostream& operator<<(ostream& output, const Date& date)
{

	output << date.m_day << "/" << date.m_month << "/" << date.m_year << endl;
	return output;
}
istream& operator>>(istream& is, Date& d)
{

	bool flag = false;
	is >> d.m_day >> d.m_month >> d.m_year;
	while (!flag)
	{
		if (d.m_day != 0 || d.m_month != 0 || d.m_year != 0)
		{
			if (d.m_day < 1 || d.m_day>31 || d.m_month < 1 || d.m_month>12 || d.m_year < 2020 || d.m_year>2030 || cin.fail())
			{
				cin.clear(); // clear input buffer to restore cin to a usable state
				cin.ignore(INT_MAX, '\n'); // ignore last input
				cout << "invalid date. enter again:";
				is >> d.m_day >> d.m_month >> d.m_year;
				/*cout << "day:"; cin >> d;
				cout << "month:"; cin >> m;
				cout << "year:"; cin >> y;*/
			}
			else
			{
				flag = true;
			}
		}
		else
			flag = true;
	}
	return is;
}

ostream& operator<<(ostream& flux, Orders const& order)
{

	flux << "Package ID: " << order.m_package_id << endl;
	flux << "ID Customer: " << order.m_customer_id << endl;
	flux << "Friend: " << order.m_friends << endl;
	flux << "Status: " << order.m_status << endl;

	return flux;
}
istream& operator>>(istream& flux, Orders& order)
{
	flux >> order.m_package_id;
	flux >> order.m_customer_id;
	flux >> order.m_friends;
	flux >> order.m_status;

	return flux;
}

ostream& operator<<(ostream& flux, Customer const& customer)
{

	flux << "Id: " << customer.m_id << endl;
	flux << "First Name: " << customer.m_first_name << endl;
	flux << "Last Name: " << customer.m_last_name << endl;
	flux << "Password: " << customer.m_password << endl;
	flux << "Email: " << customer.m_email << endl;
	flux << "Phone Number: " << customer.m_phone << endl;
	flux << "Points: " << customer.m_points << endl;

	//<< customer.m_friends << endl; NO NEED FOR INFORMATION


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
	flux >> customer.m_points;

	return flux;
}

bool Date::operator==(const Date& d)
{
	if (m_day != d.m_day)
		return false;
	if (m_month != d.m_month)
		return false;
	if (m_year != d.m_year)
		return false;
	return true;
}


////////////////////////////////////////DATABASE/////////////////////////////////////////////////

//Statements Functions Database Size
int size_packages_DB();
int size_agent_DB();
int size_flights_DB();
int size_hotels_DB();
int size_customer_DB();
int size_orders_DB();
int size_messages_DB();
//Statements of reading functions from database
Agent* read_from_agent_DB();
Packages* read_from_packages_DB();
Flights* read_from_flights_DB();
Hotels* read_from_hotels_DB();
Customer* read_from_customer_DB();
Orders* read_from_orders_DB();
Messages* read_from_messages_DB();
//Statements of writing functions for a database
void write_to_packages_DB(Packages* p, int size);
void write_to_flights_DB(Flights* f, int size);
void write_to_hotels_DB(Hotels* h, int size);
void write_to_orders_DB(Orders* o, int size);
void write_to_messages_DB(Messages* m, int size);
void write_to_customers_DB(Customer* c, int size);
void write_to_agent_DB(Agent* a, int size);
void write_new_agent_to_agent_DB(Agent* a, int size);



//////////////////////////////////////////////////MANAGER/////////////////////////////////////////



void manager_menu();
void statistics_menu();
void report();
void most_packages_sales();
void tracking_sales_agent();
void view_agent_DB();
long long revenu_of_agency();
string input_name();
long input_id();
Packages best_sale_package();
Hotels best_sale_hotel();
Flights best_sale_flight();
void manager_login();
string input_area();
void add_new_agent(Agent* arr, int size);
Agent make_agent();

///////////////////////////////////SEARCH/////////////////////////////////


void search_package();
void packages(Packages* p);
Date input_date();
Date today_date();
string input_location();
int input_price();
int input_num();
bool iequals(const string& a, const string& b);
string input_name();

Flights* Increasing_farr_by_one(Flights* matching_flight, Flights flight, int size);
void print_match_flights(Flights match_flight);
void hotels();
Hotels* Increasing_harr_by_one(Hotels* matching_hotels, Hotels hotel, int size);
void print_match_hotels(Hotels match_hotel);

void flight();
void hotels();
bool check_dates(Date first, Date second);
char class_input();

//////////////////////////////////////////////////AGENT////////////////////////////////////////////

//Statements of functions to add

void add_package_menu(Agent* arr, int agent_index);
void add_new_package(Packages* arr, int agent_index);
void add_new_flight(Flights* arr, int agent_index);
void add_new_hotel(Hotels* arr, int agent_index);
Packages make_package(Agent* arr, int agent_index);
Flights make_flight(Agent* arr, int agent_index);
Hotels make_hotel(Agent* arr, int agent_index);
void add_order_arr(Orders** arr, int* size, Orders order);

//Update Function Statements

void update_package(Packages* arr, int index);
void update_flight(Flights* arr, int agent_index);
void update_hotel(Hotels* arr, int agent_index);
Packages update_p(Packages p);
Flights update_f(Flights f);
Hotels update_h(Hotels h);

//Remove Functions

void remove_package(Packages* arr, int index);
void remove_flight(Flights* arr, int agent_index);
void remove_hotel(Hotels* arr, int agent_index);
void remove_message(long id);

//Print Functions

void print_package(Packages p);
void print_flight(Flights f);
void print_hotel(Hotels h);

//Function statements is exist

bool is_exist_agent(long id);
bool is_exist_package(Packages* arr, string id);
bool is_exist_flight(Flights* arr, string id);
bool is_exist_hotel(Hotels* arr, string id);
bool is_exist_order(Orders* arr, string id);
bool is_exist_str(string* s, int size, string id);

//Functions for checking packages belonging to the agent

Packages* agent_packages(Packages* arr, int* p, long agent_id);
Flights* agent_flights(Flights* arr, int* f, long agent_id);
Hotels* agent_hotels(Hotels* arr, int* h, long agent_id);
void add_order_arr(Orders** arr, int* size, Orders order);

//Agent Functions

void view_package_DB(Agent* arr, int agent_index);
void agent_login(Agent* arr);
void agent_menu(Agent* arr, int index);
void customer_orders(Packages* p, Flights* f, Hotels* h, Orders* arr, long agent_id);
void answer_message(Agent* a_db, long agent_id);
void home_page();


////////////////////////////////////Recomanded/////////////////////////////////////////

void recommended();
Packages* only_packages_quantity();

int size_package_quantity();

//void print_package(Packages p);
bool make_reservation(string num_orders, string type);
void update_orders(string num_orders, int friends);
void print_people_from_the_same_package(string num_orders);

void upadate_customer_points(int point, string num_orders);

void change_agent_order(string num_orders);

void pay_with_paypal(int price);
void pay_with_points(string num_orders);




//////////////////////////////////////////////////////////CUSTOMER////////////////////////////////////////////////////////////////////////

// void Change_ID(Customer* arr, long id);

// Requirement for input / sign_up

string input_pw();
string input_email();
string removeSpaces(string str);
bool is_letters(string input);
bool is_numbers(string input);

//Print function
void view_customer_DB();
void view_orders_DB();

//Read from file
Customer* read_from_customer_DB();
Orders* read_from_orders_DB();
Messages* read_from_messages_DB();

//Size DB
int size_customer_DB();
int size_orders_DB();
int size_messages_DB();

//Write In File
void sign_up(Customer* arr);
void delete_account(Customer* arr, int index);

//ALL MENU (Customer)
void home_page();
void customer_menu(Customer* arr, int index);
void my_account(Customer* arr, int index);
void personal_details(Customer* arr, int index);
void change_details(Customer* arr, int index);

void about_us();

//Find in DB
bool find_ID(Customer* arr, long id);
bool find_password(Customer* arr, string password);
void log_in();
void log_in_customer(Customer* arr);
void order_history(Orders* arr_order, Customer* arr, int index);
void contact_us(Messages* arr_message, Customer* arr, int index);

//Update Details Information
void change_first_name(Customer* arr, int index, string first_name);
void change_last_name(Customer* arr, int index, string last_name);
void change_password(Customer* arr, int index, string password);
void change_email(Customer* arr, int index, string email);
void change_phone_number(Customer* arr, int index, string phone);



//////////////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////////////
int main()
{
	home_page();


	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////CUSTOMER///////////////////////////////////////////////////////////////////////

//Requirement for Sign_Up

bool is_letters(string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		int uppercaseChar = toupper(input[i]); //Convert character to upper case version of character
		if (uppercaseChar < 'A' || uppercaseChar > 'Z') //If character is not A-Z
		{
			return false;
		}
	}
	//At this point, we have gone through every character and checked it.
	return true; //Return true since every character had to be A-Z
}
bool is_numbers(string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		int uppercaseChar = toupper(input[i]); //Convert character to upper case version of character
		if (uppercaseChar < '0' || uppercaseChar > '9') //If character is not A-Z
		{
			return false;
		}
	}
	//At this point, we have gone through every character and checked it.
	return true; //Return true since every character had to be A-Z
}
string input_email()
{
	string p;
	regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	bool flag = false;
	cin >> p;
	while (!flag)
	{
		if (!regex_match(p, pattern))// || cin.fail())
		{
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(INT_MAX, '\n'); // ignore last input
			cout << "invalid Email. enter again:" << endl;
			cout << "Email:"; cin >> p;
		}
		else
		{
			flag = true;
		}
	}
	return p;
}
string input_pw()
{
	bool upper_case = false; //saves the result if upper-case characters were found.
	bool lower_case = false; //same for lower-case
	bool number_case = false; //same for number
	regex upper_case_expression{ "[A-Z]+" }; //uppercase search
	regex lower_case_expression{ "[a-z]+" }; //lowercase search
	regex number_expression{ "[0-9]+" }; //number search

	string pw;
	bool done = false; //let's assume we're not done
	cout << endl;
	cout << "For you Security" << endl;
	cout << "Type in a valid password\n";
	cout << "Minimum 1 Lower Case\nMinimum 1 Upper case\nMinimum 1 Number\nMinimum 9 Characters\nEnter password: ";
	while (!done)
	{ //do ask-for-password as long were not done
		cin >> pw;//get input
		if (pw.length() < 8) {
			cout << "Password too short\nPassword: ";
		}
		else {

			upper_case = std::regex_search(pw, upper_case_expression); //save the result, if the expression was found.
			lower_case = std::regex_search(pw, lower_case_expression); //....
			number_case = std::regex_search(pw, number_expression);


			//like: sum_of_positive_results
			int sum_of_positive_results = upper_case + lower_case + number_case;

			if (sum_of_positive_results < 3) { //not enough booleans were true!
				{
					cout << "Invalid Password:\n";
					cout << "Password: ";
				}

			}
			else { //otherwise it's valid!
				cout << "That's a valid Password!" << std::endl;
				done = true;
			}
		}

	}
	return pw;
}
string removeSpaces(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

//Print Function

void view_customer_DB()
{
	int size = size_customer_DB(); // Size of Manu Customer in DB

	for (int i = 0; i < size; i++)
	{
		// print DB
		cout << read_from_customer_DB()[i].m_id << " " << read_from_customer_DB()[i].m_first_name << " " << read_from_customer_DB()[i].m_last_name << " " << read_from_customer_DB()[i].m_password << " " << read_from_customer_DB()[i].m_email << " " << read_from_customer_DB()[i].m_phone << " " << read_from_customer_DB()[i].m_points << endl;

	}
}
void view_orders_DB()
{
	int size = size_orders_DB();

	for (int i = 0; i < size; i++)
	{
		cout << read_from_orders_DB()[i];
	}
}

void sign_up(Customer* arr)
{


	//Requirement Details For Sign Up
	cout << endl;
	cout << "==============SIGN UP===============" << endl;
	cout << endl;
	cout << "Customer Details:" << endl;
	cout << "ID: ";
	long id;
	id = input_id();

	while ((find_ID(arr, id)))
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
	cin.ignore();
	getline(cin, first_name);
	first_name = removeSpaces(first_name);

	while (!(is_letters(first_name)))
	{
		cout << "First name must contain only letters" << endl;
		cout << "First Name: ";
		cin.ignore();
		getline(cin, first_name);
		first_name = removeSpaces(first_name);
	}

	cout << "Last Name: ";
	string last_name;
	cin.ignore();
	getline(cin, last_name);
	last_name = removeSpaces(last_name);
	while (!(is_letters(last_name)))
	{
		cout << "Last name must contain only letters" << endl;
		cout << "Last Name: ";
		cin.ignore();
		getline(cin, last_name);
		last_name = removeSpaces(last_name);
	}
	cout << "Password: ";
	string password;
	password = input_pw(); // security check 

	cout << "Confirm Password: ";
	string confirm_password;
	cin.ignore();
	cin >> confirm_password;
	while (!(iequals(password, confirm_password)))
	{
		cout << "Incorrect Confirm Password: " << endl;
		cout << "Confirm Password: ";
		cin >> confirm_password;
	}

	cout << "Email: ";
	string email;
	email = input_email();
	cout << "Phone Number: ";
	string phone;
	cin >> phone;
	while (!(is_numbers(phone)) || (phone.length() != 10))
	{
		cout << "Phone only have number and contain 10 numbers" << endl;
		cout << "Phone Number: ";
		cin >> phone;

	}
	int points = 0;
	cout << endl;
	cout << "~~~~~~~~~~~~~~WELCOME~~~~~~~~~~~~~~~" << endl;
	Customer customer = { id, first_name, last_name, password, email, phone, points };// insert new user information

	int size = size_customer_DB();




	//Save in a temporary array

	Customer* temp = new Customer[size];

	for (int i = 0; i < size; i++)
	{
		temp[i].m_id = arr[i].m_id;
		temp[i].m_first_name = arr[i].m_first_name;
		temp[i].m_last_name = arr[i].m_last_name;
		temp[i].m_password = arr[i].m_password;
		temp[i].m_email = arr[i].m_email;
		temp[i].m_phone = arr[i].m_phone;
		temp[i].m_points = arr[i].m_points;
	}

	size++;

	// create a new array with the new size;

	arr = new Customer[size];

	for (int i = 0; i < size - 1; i++)
	{
		arr[i].m_id = temp[i].m_id;
		arr[i].m_first_name = temp[i].m_first_name;
		arr[i].m_last_name = temp[i].m_last_name;
		arr[i].m_password = temp[i].m_password;
		arr[i].m_email = temp[i].m_email;
		arr[i].m_phone = temp[i].m_phone;
		arr[i].m_phone = temp[i].m_phone;
		arr[i].m_points = temp[i].m_points;
	}

	arr[size - 1] = customer;

	// Write in DB

	write_to_customers_DB(arr, size);

	log_in_id = arr[size - 1].m_id;

	if (flag == 1)
		return;
	else
		customer_menu(arr, size - 1);

}
void delete_account(Customer* arr, int index)
{
	int choice = 0;

	while (choice > 0 || choice < 3)
	{
		cout << "==============DELETE ACCOUNT==============" << endl;
		cout << "Are you sure you want to delete your Account" << endl;
		cout << "1- Yes" << endl;
		cout << "2- No and Back to Personal Details" << endl;
		cout << "Choose Option: ";
		cin >> choice;

		switch (choice)
		{

		case 1:
		{

			Customer* temp = arr;

			int size = size_customer_DB() - 1;

			arr = new Customer[size];

			for (int i = 0; i < index; i++)
			{
				arr[i].m_id = temp[i].m_id;
				arr[i].m_first_name = temp[i].m_first_name;
				arr[i].m_last_name = temp[i].m_last_name;
				arr[i].m_password = temp[i].m_password;
				arr[i].m_email = temp[i].m_email;
				arr[i].m_phone = temp[i].m_phone;
				arr[i].m_points = temp[i].m_points;

			}
			for (int i = index; i < size; i++)
			{
				arr[i].m_id = temp[i].m_id;
				arr[i].m_first_name = temp[i].m_first_name;
				arr[i].m_last_name = temp[i].m_last_name;
				arr[i].m_password = temp[i].m_password;
				arr[i].m_email = temp[i].m_email;
				arr[i].m_phone = temp[i].m_phone;
				arr[i].m_points = temp[i].m_points;

			}


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
					obj1 << arr[i].m_id << " " << arr[i].m_first_name << " " << arr[i].m_last_name << " " << arr[i].m_password << " " << arr[i].m_email << " " << arr[i].m_phone << " " << arr[i].m_points << endl;
				}


				obj1.close();
				cout << "Account Deleted... See You Soon." << endl;
				log_in_id = 0;

				exit(1);
			}

			break;
		}
		case 2:
		{
			return;
			break;
		}
		default:
			cout << endl;
			cout << "Wrong Input" << endl;
			cout << endl;
			break;
		};

	}

}

void home_page()
{
	int choice = 0;
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                         VACATION 4 U                           " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;


	while (choice != 6)
	{
		cout << endl;
		cout << "=============HOME PAGE==============" << endl;
		cout << endl;
		cout << "1- About us\n2- Search package\n3- Recommended package\n4- Log-in\n5- Sign up\n6- Exit" << endl;
		cout << "====================================" << endl;
		cout << "Choice: ";
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
			recommended();
			break;
		case 4:
			log_in();
			break;
		case 5:
			sign_up(read_from_customer_DB());
			break;
		case 6:
			break;
		default:
			cout << "ERROR input ,please enter a number between 1-6 " << endl;
			break;
		}
	}

}
void customer_menu(Customer* arr, int index)
{
	int choice = 0;
	while (choice > 0 || choice < 5)
	{
		cout << endl;
		cout << "===========CUSTOMER MENU============" << endl;
		cout << endl;
		cout << "Hello " << arr[index].m_first_name << endl;
		cout << endl;
		cout << "1- Recommanded Packages" << endl;
		cout << "2- Search Packages" << endl;
		cout << "3- Contact Us" << endl;
		cout << "4- My Account" << endl;
		cout << "5- Log Out back to Home Page" << endl;

		cout << "Choose Option: ";
		cin >> choice;




		switch (choice)
		{
		case 1:
		{
			recommended();
			break;
		}
		case 2:
		{
			search_package();
			break;
		}
		case 3:
		{
			contact_us(read_from_messages_DB(), arr, index);

			break;
		}
		case 4:
		{
			my_account(arr, index);
			break;
		}
		case 5:
		{
			log_in_id = 0;
			return;
			break;
		}
		default:
			cout << "Wrong Input" << endl;
			cout << endl;
			break;
		}
	}
}
void my_account(Customer* arr, int index)
{
	int choice = 0;
	while (choice > 0 || choice < 3)
	{

		cout << endl;
		cout << "==============MY ACCOUNT==============" << endl;
		cout << endl;
		cout << "1- Personal Details" << endl;
		cout << "2- Order History" << endl;
		cout << "3- Back to Customer Menu" << endl;
		cout << "Choose Option: ";
		cin >> choice;




		switch (choice)
		{
		case 1:
		{
			personal_details(arr, index);
			break;
		}
		case 2:
		{
			order_history(read_from_orders_DB(), arr, index);
			break;
		}
		case 3:
		{
			return;
			break;
		}
		default:
			cout << "Wrong Input" << endl;
			cout << endl;
			break;
		}
	}
}
void personal_details(Customer* arr, int index)
{
	int choice = 0;
	while (choice > 0 || choice < 3)
	{

		cout << endl;
		cout << "==============PERSONAL DETAILS==============" << endl;
		cout << endl;
		cout << arr[index] << endl;
		cout << "1- Change Details" << endl;
		cout << "2- Delete account" << endl;
		cout << "3- Back to My Account Menu" << endl;
		cout << "Choose Option: ";
		cin >> choice;




		switch (choice)
		{
		case 1:
		{
			change_details(arr, index);
			break;
		}
		case 2:
		{
			delete_account(arr, index);
			break;
		}
		case 3:
		{
			return;
			break;
		}
		default:
			cout << "Wrong Input" << endl;
			cout << endl;
			break;
		}
	}
}
void change_details(Customer* arr, int index)
{
	int choice = 0;
	while (choice > 0 || choice < 6)
	{

		cout << endl;
		cout << "==============CHANGES DETAILS==============" << endl;
		cout << endl;
		cout << arr[index] << endl;
		cout << "1- Change First Name" << endl;
		cout << "2- Change Last Name" << endl;
		cout << "3- Change Password" << endl;
		cout << "4- Change Email" << endl;
		cout << "5- Change Phone Number" << endl;
		cout << "6- Back To Personal Details" << endl;
		cout << "Choose Option: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			change_first_name(arr, index, arr[index].m_first_name);
			break;
		}
		case 2:
		{
			change_last_name(arr, index, arr[index].m_last_name);
			break;
		}
		case 3:
		{
			change_password(arr, index, arr[index].m_password);
			break;
		}
		case 4:
		{
			change_email(arr, index, arr[index].m_email);
			break;
		}
		case 5:
		{
			change_phone_number(arr, index, arr[index].m_phone);
			break;
		}
		case 6:
		{
			return;
			break;
		}
		default:
			cout << "Wrong Input" << endl;
			cout << endl;
			break;
		}
	}
}


void Change_ID(Customer* arr, long id)
{

	int size = size_customer_DB();

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
void about_us()
{
	cout << "When we started in 2003, we set out to do things differently. We wanted to show all flight options in one place, creating a simple alternative to the confusing sites that make travel feel like hard work.Fast forward to todayand we’ve gone from a flight search engine to a global leader in travel.We're proud that more than 100 million people across the world (that's quite a few!) rely on our appand website each month to help them with their travel plans.Dedicated to making travel as simple as possible, we help eachand every one of them find the best options across flights, hotels, and car rentals to book the perfect trip." << endl;
	cout << endl;

}

void log_in_customer(Customer* arr)
{
	int size = size_customer_DB();
	cout << endl;
	cout << "==========CUSTOMER LOG IN===========" << endl;
	cout << endl;
	cout << "ID: ";
	long id;

	id = input_id();

	while (!(find_ID(arr, id)))
	{

		int choice = 0;
		cout << "No ID in our Customer DB" << endl;
		while (choice != 2)
		{
			cout << "1- Try Again." << endl;
			cout << "2- Back To Menu for Sign_Up" << endl;
			choice = input_num();

			switch (choice)
			{
			case 1:
			{
				id = input_id();
				choice = 2;
				break;
			}
			case 2:
				sign_up(read_from_customer_DB());
				return;
			default:
			{
				cout << "Wrong input" << endl;
				break;
			}
			}
		}
	}

	cout << "Password: ";
	string password;
	cin >> password;
	while (!(find_password(arr, password)))
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

			for (int i = 0; i < size; i++)
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
			index = i;
			break;
		}
	}

	log_in_id = arr[index].m_id;

	if (flag == 1)
		return;
	else
		customer_menu(arr, index);
}
void log_in()
{


	int user_type;
	cout << endl;
	cout << "==============LOG IN================" << endl;
	cout << endl;
	cout << "1- Agent\n2- Manager\n3- Customer\n4- Home Page" << endl;
	cout << "Choice: ";
	cin >> user_type;
	switch (user_type)
	{
	case 1:
		agent_login(read_from_agent_DB());//If the login is successful transfer to the appropriate menu

		break;
	case 2:
		manager_login();

		break;
	case 3:
		log_in_customer(read_from_customer_DB());

		break;
	case 4:
		return;
	default:

		cout << "Worng choice please try again" << endl;
		break;
	}


}
bool find_ID(Customer* arr, long id)
{
	int size = size_customer_DB();

	for (int i = 0; i < size; i++)
	{
		if (id == arr[i].m_id)
			return true;
	}
	return false;
}
bool find_password(Customer* arr, string password)
{
	int size = size_customer_DB();

	for (int i = 0; i < size; i++)
	{
		if (password == arr[i].m_password)
			return true;
	}
	return false;
}
void order_history(Orders* arr_order, Customer* arr, int index)
{
	int size_customer = size_customer_DB();
	int size_order = size_orders_DB();

	cout << endl;
	cout << "==============ORDER HISTORY==============" << endl;
	cout << endl;

	int flag = 0;

	for (int j = 0; j < size_order; j++)
	{

		if (arr[index].m_id == arr_order[j].m_customer_id)
		{
			cout << "*************************************" << endl;
			cout << endl;
			cout << arr_order[j];
			cout << endl;
			cout << "*************************************" << endl;
			flag++;
		}
	}

	if (flag == 0)
	{
		cout << "No order history" << endl;
		cout << endl;
	}





	cout << endl;
	cout << "Your accumulated Points: " << arr[index].m_points << endl;

}
void contact_us(Messages* arr_message, Customer* arr, int index)
{
	int choice = 0;
	while (choice > 0 || choice < 3)
	{

		cout << endl;
		cout << "===========CONTACT US============" << endl;
		cout << endl;
		cout << "Are you sure you want to Leave a Message?" << endl;
		cout << "1- Yes" << endl;
		cout << "2- No and Back to Customer Menu" << endl;
		cout << "Choice: ";
		cin >> choice;




		switch (choice)
		{
		case 1:
		{
			string message;
			string destination = "ND";
			cout << "Leave your message: ";
			cin.ignore();
			getline(cin, message);

			int choice1 = 0;
			while (choice1 > 0 || choice1 < 3)
			{

				// choice for destination 
				cout << endl;
				cout << "==============DESTINATION==============" << endl;
				cout << endl;
				cout << "Do you have a question about a specific destinitation ?" << endl;
				cout << "1- Yes" << endl;
				cout << "2- No and Back to Contact Us" << endl;
				cin >> choice1;




				switch (choice1)
				{
				case 1:
				{
					int size = size_messages_DB();
					long message_id = arr_message[size - 1].m_message_id + 1;
					cout << "What destination you have a question about ? ";
					cout << "EU (Europe) \nUS- (United Satetes)\nAU- (Australia)\nAN- (Antarctica)\nAS- (Asia)\nAF- (Africa)\n";
					cin >> destination;
					long customer_id = arr[index].m_id;
					Messages messages = { message_id, customer_id, destination, message };// insert new user information

					ofstream obj1("Messages.txt");

					if (!obj1)
					{
						cerr << "ERROR OPENING CUSTOMER DB" << endl;
						exit(1);
					}
					else
					{

						Messages* temp = new Messages[size];

						for (int i = 0; i < size; i++)
						{


							temp[i].m_message_id = arr_message[i].m_message_id;
							temp[i].m_customer_id = arr_message[i].m_customer_id;
							temp[i].m_area = arr_message[i].m_area;
							temp[i].m_massege = arr_message[i].m_massege;

						}

						size++;

						arr_message = new Messages[size];

						for (int i = 0; i < size - 1; i++)
						{
							arr_message[i].m_message_id = temp[i].m_message_id;
							arr_message[i].m_customer_id = temp[i].m_customer_id;
							arr_message[i].m_area = temp[i].m_area;
							arr_message[i].m_massege = temp[i].m_massege;
						}

						arr_message[size - 1].m_message_id = messages.m_message_id;
						arr_message[size - 1].m_customer_id = messages.m_customer_id;
						arr_message[size - 1].m_area = messages.m_area;
						arr_message[size - 1].m_massege = messages.m_massege;


						obj1 << size << endl;
						for (int i = 0; i < size; i++)
						{
							obj1 << arr_message[i].m_message_id << " " << arr_message[i].m_customer_id << " " << arr_message[i].m_area << " " << arr_message[i].m_massege << endl;
						}


						obj1.close();
					}
					return;
					break;

				}
				case 2:
				{
					int size = size_messages_DB();
					long message_id = arr_message[size - 1].m_message_id + 1;
					long customer_id = arr[index].m_id;
					Messages messages = { message_id, customer_id, destination, message };// insert new user information

					ofstream obj1("Messages.txt");

					if (!obj1)
					{
						cerr << "ERROR OPENING CUSTOMER DB" << endl;
						exit(1);
					}
					else
					{

						Messages* temp = new Messages[size];

						for (int i = 0; i < size; i++)
						{


							temp[i].m_message_id = arr_message[i].m_message_id;
							temp[i].m_customer_id = arr_message[i].m_customer_id;
							temp[i].m_area = arr_message[i].m_area;
							temp[i].m_massege = arr_message[i].m_massege;
						}

						size++;

						arr_message = new Messages[size];

						for (int i = 0; i < size - 1; i++)
						{
							arr_message[i].m_message_id = temp[i].m_message_id;
							arr_message[i].m_customer_id = temp[i].m_customer_id;
							arr_message[i].m_area = temp[i].m_area;
							arr_message[i].m_massege = temp[i].m_massege;
						}

						arr_message[size - 1].m_message_id = messages.m_message_id;
						arr_message[size - 1].m_customer_id = messages.m_customer_id;
						arr_message[size - 1].m_area = messages.m_area;
						arr_message[size - 1].m_massege = messages.m_massege;


						obj1 << size << endl;
						for (int i = 0; i < size; i++)
						{
							obj1 << arr_message[i].m_message_id << " " << arr_message[i].m_customer_id << " " << arr_message[i].m_area << " " << arr_message[i].m_massege << endl;
						}


						obj1.close();
					}
					return;
					break;
					return;
					break;
				}
				default:
					cout << "Wrong Input" << endl;
					cout << endl;
					break;
				}
			};



		}
		case 2:
		{
			return;
			break;
		}
		default:
			cout << "Wrong Input" << endl;
			cout << endl;
			break;
		}
	};


}

// Update Details Information

void change_first_name(Customer* arr, int index, string first_name)
{

	int choice = 0;
	while (choice > 0 || choice < 3)
	{

		cout << endl;
		cout << "==============Change First Name==============" << endl;
		cout << "Are you sure you want to change your first name ?" << endl;
		cout << "1- Yes" << endl;
		cout << "2- No and Back to Change Details" << endl;
		cout << "Choice: ";
		cin >> choice;




		switch (choice)
		{
		case 1:
		{
			int size = size_customer_DB();

			ofstream obj1("Customer.txt");


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
					if (arr[i].m_first_name == first_name)
					{
						obj1 << arr[i].m_id << " ";
						cout << "Old First Name: " << arr[i].m_first_name << endl;
						cout << "New First Name: ";
						cin >> arr[i].m_first_name;
						cout << "Change Succeed" << endl;
						cout << endl;
						obj1 << arr[i].m_first_name << " " << arr[i].m_last_name << " " << arr[i].m_password << " " << arr[i].m_email << " " << arr[i].m_phone << " " << arr[i].m_points << endl;


					}
					else
						obj1 << arr[i].m_id << " " << arr[i].m_first_name << " " << arr[i].m_last_name << " " << arr[i].m_password << " " << arr[i].m_email << " " << arr[i].m_phone << " " << arr[i].m_points << endl;
				}
				obj1.close();
			}
			return;
			break;

		}
		case 2:
		{
			return;
			break;
		}
		default:
			cout << "Wrong Input" << endl;
			cout << endl;
			break;
		}
	};



}
void change_last_name(Customer* arr, int index, string last_name)
{
	int choice = 0;
	while (choice > 0 || choice < 3)
	{

		cout << endl;
		cout << "==============Change Last Name==============" << endl;
		cout << "Are you sure you want to change you last name ?" << endl;
		cout << "1- Yes" << endl;
		cout << "2- No and Back to Change Details" << endl;
		cout << "Choice: ";
		cin >> choice;




		switch (choice)
		{
		case 1:
		{
			int size = size_customer_DB();

			ofstream obj1("Customer.txt");


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
					if (arr[i].m_last_name == last_name)
					{
						obj1 << arr[i].m_id << " " << arr[i].m_first_name << " ";
						cout << "Old Last Name: " << arr[i].m_last_name << endl;
						cout << "New Last Name: ";
						cin >> arr[i].m_last_name;
						cout << "Change Succeed" << endl;
						cout << endl;
						obj1 << arr[i].m_last_name << " " << arr[i].m_password << " " << arr[i].m_email << " " << arr[i].m_phone << " " << arr[i].m_points << endl;


					}
					else
						obj1 << arr[i].m_id << " " << arr[i].m_first_name << " " << arr[i].m_last_name << " " << arr[i].m_password << " " << arr[i].m_email << " " << arr[i].m_phone << " " << arr[i].m_points << endl;
				}
				obj1.close();
			}
			return;
			break;

		}
		case 2:
		{
			return;
			break;
		}
		default:
			cout << "Wrong Input" << endl;
			cout << endl;
			break;
		}
	};

}
void change_password(Customer* arr, int index, string password)
{
	int choice = 0;
	while (choice > 0 || choice < 3)
	{

		cout << endl;
		cout << "==============Change Password==============" << endl;
		cout << "Are you sure you want to change your password ?" << endl;
		cout << "1- Yes" << endl;
		cout << "2- No and Back to Change Details" << endl;
		cout << "Choice: ";
		cin >> choice;




		switch (choice)
		{
		case 1:
		{
			int size = size_customer_DB();

			ofstream obj1("Customer.txt");


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
					if (arr[i].m_password == password)
					{
						obj1 << arr[i].m_id << " " << arr[i].m_first_name << " " << arr[i].m_last_name << " ";
						cout << "Old Password: " << arr[i].m_password << endl;
						cout << "New Password: ";
						cin >> arr[i].m_password;
						cout << "Change Succeed" << endl;
						cout << endl;
						obj1 << arr[i].m_password << " " << arr[i].m_email << " " << arr[i].m_phone << " " << arr[i].m_points << endl;


					}
					else
						obj1 << arr[i].m_id << " " << arr[i].m_first_name << " " << arr[i].m_last_name << " " << arr[i].m_password << " " << arr[i].m_email << " " << arr[i].m_phone << " " << arr[i].m_points << endl;
				}
				obj1.close();
			}
			return;
			break;

		}
		case 2:
		{
			return;
			break;
		}
		default:
			cout << "Wrong Input" << endl;
			cout << endl;
			break;
		}
	};

}
void change_email(Customer* arr, int index, string email)
{
	int choice = 0;
	while (choice > 0 || choice < 3)
	{

		cout << endl;
		cout << "==============Change Email==============" << endl;
		cout << "Are you sure you want to change your email ?" << endl;
		cout << "1- Yes" << endl;
		cout << "2- No and Back to Change Details" << endl;
		cout << "Choice: ";
		cin >> choice;




		switch (choice)
		{
		case 1:
		{
			int size = size_customer_DB();

			ofstream obj1("Customer.txt");


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
					if (arr[i].m_email == email)
					{
						obj1 << arr[i].m_id << " " << arr[i].m_first_name << " " << arr[i].m_last_name << " " << arr[i].m_password << " ";
						cout << "Old Email: " << arr[i].m_email << endl;
						cout << "New Email: ";
						cin >> arr[i].m_email;
						cout << "Change Succeed" << endl;
						cout << endl;
						obj1 << arr[i].m_email << " " << arr[i].m_phone << " " << arr[i].m_points << endl;


					}
					else
						obj1 << arr[i].m_id << " " << arr[i].m_first_name << " " << arr[i].m_last_name << " " << arr[i].m_password << " " << arr[i].m_email << " " << arr[i].m_phone << " " << arr[i].m_points << endl;
				}
				obj1.close();
			}
			return;
			break;

		}
		case 2:
		{
			return;
			break;
		}
		default:
			cout << "Wrong Input" << endl;
			cout << endl;
			break;
		}
	};

}
void change_phone_number(Customer* arr, int index, string phone)
{
	int choice = 0;
	while (choice > 0 || choice < 3)
	{

		cout << endl;
		cout << "==============Change Phone Number==============" << endl;
		cout << "Are you sure you want to change your phone number ?" << endl;
		cout << "1- Yes" << endl;
		cout << "2- No and Back to Change Details" << endl;
		cout << "Choice: ";
		cin >> choice;




		switch (choice)
		{
		case 1:
		{
			int size = size_customer_DB();

			ofstream obj1("Customer.txt");


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
					if (arr[i].m_phone == phone)
					{
						obj1 << arr[i].m_id << " " << arr[i].m_first_name << " " << arr[i].m_last_name << " " << arr[i].m_password << " " << arr[i].m_email << " ";
						cout << "Old Phone Number: " << arr[i].m_phone << endl;
						cout << "New Phone Number: ";
						cin >> arr[i].m_phone;
						cout << "Change Succeed" << endl;
						cout << endl;
						obj1 << arr[i].m_phone << " " << arr[i].m_points << endl;


					}
					else
						obj1 << arr[i].m_id << " " << arr[i].m_first_name << " " << arr[i].m_last_name << " " << arr[i].m_password << " " << arr[i].m_email << " " << arr[i].m_phone << " " << arr[i].m_points << endl;
				}
				obj1.close();
			}
			return;
			break;

		}
		case 2:
		{
			return;
			break;
		}
		default:
			cout << "Wrong Input" << endl;
			cout << endl;
			break;
		}
	};

}


///////////////////////////////////////////////////////////RECOMMENDED////////////////////////////////////////////////////////////////////


void recommended()
{
	Packages* new_packages = only_packages_quantity();
	if (size_package_quantity() < 4)//prints the packages if there are less then 4
	{
		if (size_package_quantity() == 3)
		{
			Packages* recommended_packages = new Packages[sizeof(Packages) * 3];
			recommended_packages[0] = new_packages[0];
			recommended_packages[1] = new_packages[1];
			recommended_packages[2] = new_packages[2];
			// print recommended package
			cout << endl;
			cout << "THE BEST PACKAGE SELERS" << endl;
			cout << "-----------------------" << endl;
			cout << endl;
			cout << "Package number 1: " << endl;
			print_package(recommended_packages[0]);
			cout << "-----------------------" << endl;
			cout << endl;
			cout << "Package number 2: " << endl;
			print_package(recommended_packages[1]);
			cout << "-----------------------" << endl;
			cout << endl;
			cout << "Package number 3: " << endl;
			print_package(recommended_packages[2]);
			cout << "-----------------------" << endl;

			int choice = 0;
			//recommended package menu
			while (choice != 4)
			{
				cout << "====================================" << endl;
				cout << "1- Package number 1\n2- Package number 2\n3- Package number 3\n4- Exit" << endl;
				cout << "====================================" << endl;
				cout << "Please enter your choice" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					make_reservation(recommended_packages[0].m_package_id, "Packages");
					choice = 4;
					break;
				case 2:
					make_reservation(recommended_packages[1].m_package_id, "Packages");
					choice = 4;
					break;
				case 3:
					make_reservation(recommended_packages[2].m_package_id, "Packages");
					choice = 4;
					break;
				case 4:
					break;
				default:
					cout << "ERROR input ,please enter a number between 1-6 " << endl;
					break;
				}
			}

		}
		else if (size_package_quantity() == 2)
		{
			Packages* recommended_packages = new Packages[sizeof(Packages) * 2];
			recommended_packages[0] = new_packages[0];
			recommended_packages[1] = new_packages[1];
			// print recommended package
			cout << "THE BEST PACKAGE SELERS" << endl;
			cout << "-----------------------" << endl;
			cout << endl;
			cout << "Package number 1: " << endl;
			print_package(recommended_packages[0]);
			cout << "-----------------------" << endl;
			cout << endl;
			cout << "Package number 2: " << endl;
			print_package(recommended_packages[1]);
			cout << "-----------------------" << endl;
			int choice = 0;
			//recommended package menu
			while (choice != 3)
			{
				cout << "====================================" << endl;
				cout << "1.Package number 1\n2.Package number 2\n3.Exit" << endl;
				cout << "====================================" << endl;
				cout << "Please enter your choice" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					make_reservation(recommended_packages[0].m_package_id, "Packages");
					choice = 3;
					break;
				case 2:
					make_reservation(recommended_packages[1].m_package_id, "Packages");
					choice = 3;
					break;
				case 3:
					break;
				default:
					cout << "ERROR input ,please enter a number between 1-6 " << endl;
					break;
				}
			}
		}
		else if (size_package_quantity() == 1)
		{
			Packages* recommended_packages = new Packages[sizeof(Packages) * 1];
			recommended_packages[0] = new_packages[0];
			cout << "THE BEST PACKAGE SELERS" << endl;
			cout << "-----------------------" << endl;
			cout << endl;
			cout << "Package number 1" << endl;
			print_package(recommended_packages[0]);
			//recommended package menu
			int choice = 0;
			while (choice != 2)
			{
				cout << "====================================" << endl;
				cout << "1.Package number 1\n2Exit" << endl;
				cout << "====================================" << endl;
				cout << "Please enter your choice" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					make_reservation(recommended_packages[0].m_package_id, "Packages");
					choice = 2;
					break;
				case 2:
					break;
				default:
					cout << "ERROR input ,please enter a number between 1-6 " << endl;
					break;
				}
			}
		}
		/*else
			cout << "Empty Recommende Packages" << endl;*/
	}
	else
	{
		Packages* recommended_packages = new Packages[sizeof(Packages) * 3];
		for (int i = 0; i < size_packages_DB(); i++)
		{
			// first recommende package
			if (new_packages[i].m_sales_counter > recommended_packages[0].m_sales_counter)
				recommended_packages[0] = new_packages[i];
		}
		for (int i = 0; i < size_packages_DB(); i++)
		{
			// seconde recommende package
			if (new_packages[i].m_sales_counter > recommended_packages[1].m_sales_counter && new_packages[i].m_package_id != recommended_packages[0].m_package_id)
				recommended_packages[1] = new_packages[i];
		}
		for (int i = 0; i < size_packages_DB(); i++)
		{
			// third package
			if (new_packages[i].m_sales_counter > recommended_packages[2].m_sales_counter && new_packages[i].m_package_id != recommended_packages[0].m_package_id && new_packages[i].m_package_id != recommended_packages[1].m_package_id)
				recommended_packages[2] = new_packages[i];
		}
		// print recommended package
		cout << "THE BEST PACKAGE SELERS" << endl;
		cout << "-----------------------" << endl;
		cout << endl;
		cout << "Package number 1" << endl;
		print_package(recommended_packages[0]);
		cout << "-----------------------" << endl;
		cout << endl;
		cout << "Package number 2" << endl;
		print_package(recommended_packages[1]);
		cout << "-----------------------" << endl;
		cout << endl;
		cout << "Package number 3" << endl;
		print_package(recommended_packages[2]);
		//choise variable
		int choice = 0;
		//recommended packages menu
		while (choice != 4)
		{
			cout << "====================================" << endl;
			cout << "1.Package number 1\n2.Package number 2\n3.Package number 3\n4.Exit" << endl;
			cout << "====================================" << endl;
			cout << "Please enter your choice" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				make_reservation(recommended_packages[0].m_package_id, "Packages");
				choice = 4;
				break;
			case 2:
				make_reservation(recommended_packages[1].m_package_id, "Packages");
				choice = 4;
				break;
			case 3:
				make_reservation(recommended_packages[2].m_package_id, "Packages");
				choice = 4;
				break;
			case 4:
				break;
			default:
				cout << "ERROR input ,please enter a number between 1-6 " << endl;
				break;
			}
		}
	}

}

bool make_reservation(string num_orders, string type)//type-type of package
{
	if (log_in_id == 0)
	{
		flag = 1;
		int choice = 0;
		while (choice != 3)
		{

			cout << "Please Register Yourself" << endl;
			cout << "1- Sign up\n2- Log_in\n3- Back to Home Page" << endl;
			cout << "Choice: ";
			choice = input_num();

			switch (choice)
			{

			case 1:

				sign_up(read_from_customer_DB());
				choice = 3;
				break;
			case 2:
				log_in_customer(read_from_customer_DB());
				choice = 3;
				break;
			case 3:
				return false;


			default:
				cout << "Wrong Input Try Again" << endl;
				break;
			}
		}
	}
	flag = 0;
	// find the type of order

	if (type == "Packages")
	{
		cout << "Packages-reservision" << endl;
		Packages* new_packages = read_from_packages_DB();
		int size = size_packages_DB();
		for (int i = 0; i < size; i++)
		{
			if (new_packages[i].m_package_id == num_orders)
			{
				// update package seles and quantity.
				new_packages[i].m_quantity--;
				new_packages[i].m_sales_counter++;

				int choice;
				// ask if the customer want friend to the package
				cout << "Do you want friends for travel?\n1-YES\n2-NO" << endl;
				cin >> choice;
				while (choice != 1 && choice != 2)
				{
					cout << "Error try again\n 1-YES\n2-NO " << endl;
					cin >> choice;
				}
				// upadate order.
				update_orders(num_orders, choice);
			}
		}
		write_to_packages_DB(new_packages, size);
	}
	else if (type == "Hotels")
	{
		cout << "Hotels-reservision" << endl;
		Hotels* new_hotels = read_from_hotels_DB();
		int size = size_hotels_DB();
		for (int i = 0; i < size; i++)
		{
			if (new_hotels[i].m_hotel_id == num_orders)
			{
				// update package seles and quantity.
				new_hotels[i].m_quantity--;
				new_hotels[i].m_sales_counter++;
				// upadate order.
				update_orders(num_orders, 2);
			}
		}
		write_to_hotels_DB(new_hotels, size);
	}
	else if (type == "Flight")
	{
		cout << "Flight-reservision" << endl;
		Flights* new_flights = read_from_flights_DB();
		int size = size_flights_DB();
		for (int i = 0; i < size; i++)
		{
			if (new_flights[i].m_flight_id == num_orders)
			{
				// update package seles and quantity.
				new_flights[i].m_quantity--;
				new_flights[i].m_sales_counter++;
				// upadate order.
				update_orders(num_orders, 2);
			}
		}
		write_to_flights_DB(new_flights, size);
	}

	cout << "==========================" << endl;
	cout << "Thank you for your orders" << endl;
	cout << "==========================" << endl;
	return true;
}
Packages* only_packages_quantity()
{
	Packages* packages_quantity = new Packages[sizeof(Packages) * size_package_quantity()];//array of available packages
	Packages* new_packages = read_from_packages_DB();
	int j = 0;
	//checks for available packages and creats a new array of available packages
	for (int i = 0; i < size_packages_DB(); i++)
	{
		if (new_packages[i].m_quantity != 0)
		{
			packages_quantity[j] = new_packages[i];
			j++;
		}
	}
	return packages_quantity;
}

// Size Quantity

int size_package_quantity()//checks how much packages are available
{
	int count = 0;
	Packages* new_packages = read_from_packages_DB();
	//count++ when there is an available package
	for (int i = 0; i < size_packages_DB(); i++)
		if (new_packages[i].m_quantity != 0)
			count++;
	return count;
}

//Print Function
void print_people_from_the_same_package(string num_orders)
{
	cout << "===========================" << endl;
	cout << "This pepoles have the same package:" << endl;
	cout << endl;
	Customer* c = read_from_customer_DB();
	Orders* o = read_from_orders_DB();
	int count = 0;
	// find the people with same order.
	for (int i = 0; i < size_customer_DB(); i++)
	{
		for (int j = 0; j < size_orders_DB(); j++)
		{
			// print only the people with the same order that want friend .
			if (c[i].m_id == o[j].m_customer_id && o[j].m_package_id == num_orders && log_in_id != c[i].m_id && o[j].m_friends)
			{
				cout << "Name: " << c[i].m_first_name << " " << c[i].m_last_name << endl;
				cout << "Phone number: " << c[i].m_phone << endl;
				cout << "Email: " << c[i].m_email << endl;
				cout << endl;
				count++;
				if (count != 0)
					cout << "----------------" << endl;
			}
		}
	}
	if (count == 0)
		cout << "No people with the same package." << endl;
}


void change_agent_order(string num_orders)
{
	Agent* a = read_from_agent_DB();
	int fine = 0;
	long agent_id = 0;

	// chacking type num order

	Packages* p = read_from_packages_DB();
	// find the package with the same id.
	for (int i = 0; i < size_packages_DB(); i++)
		if (p[i].m_package_id == num_orders)
		{
			// take the id agent that add this order.
			agent_id = p[i].m_agent_id;
			// update customer points.
			upadate_customer_points(p[i].m_points, num_orders);
		}

	Hotels* h = read_from_hotels_DB();
	// find the hotel with the same id.
	for (int i = 0; i < size_hotels_DB(); i++)
		if (h[i].m_hotel_id == num_orders)
			// take the id agent that add this order.
		{
			agent_id = h[i].m_agent_id;
			upadate_customer_points(0, num_orders);

		}


	Flights* f = read_from_flights_DB();
	// find the flight with the same id.
	for (int i = 0; i < size_flights_DB(); i++)
		if (f[i].m_flight_id == num_orders)
			// take the id agent that add this order.
		{
			agent_id = f[i].m_agent_id;
			upadate_customer_points(0, num_orders);

		}


	// find the agent that make this order.
	for (int i = 0; i < size_agent_DB(); i++)
	{
		if (a[i].m_id == agent_id)
		{
			// add to the agent selse.
			a[i].m_sales++;
		}
	}
	write_to_agent_DB(a, size_agent_DB());
}

// Update option

void upadate_customer_points(int point, string num_orders)
{
	Customer* c = read_from_customer_DB();
	for (int i = 0; i < size_customer_DB(); i++)
		// find the customer with the same log in id.
	{
		if (c[i].m_id == log_in_id)
		{
			// adds  to the customer points.
			cout << "Your points are: " << c[i].m_points << endl;
			int choice;
			// ask how the customer want too pay.
			cout << "How do you want to pay?\n1-Paypal\n2-Points" << endl;
			cin >> choice;
			while (choice != 1 && choice != 2)
			{
				cout << "Error try again\n1-Paypal\n2-Points" << endl;
				cin >> choice;
			}
			if (choice == 1)
				//paypal
				pay_with_paypal(0);
			else
				//points
				pay_with_points(num_orders);

		}
	}
	// customer DB
	// write_to_customers_DB(c, size_customer_DB());
}
void update_orders(string num_orders, int friends)
{
	Orders* o = read_from_orders_DB();
	int order_size = size_orders_DB() + 1;
	Orders* new_orders = new Orders[sizeof(Orders) * order_size];

	for (int i = 0; i < order_size - 1; i++)
		new_orders[i] = o[i];

	Customer c;
	Customer* customers = read_from_customer_DB();

	int c_size = size_customer_DB();

	for (int i = 0; i < c_size; i++)
		if (customers[i].m_id == log_in_id)
			c = customers[i];


	new_orders[order_size - 1].m_package_id = num_orders;
	new_orders[order_size - 1].m_customer_id = log_in_id;
	new_orders[order_size - 1].m_status = "In process";

	if (friends == 1)
	{
		new_orders[order_size].m_friends = true;
		write_to_orders_DB(new_orders, order_size);

		// print all people detiels in this package
		print_people_from_the_same_package(num_orders);
	}
	else
	{
		new_orders[order_size].m_friends = false;
		write_to_orders_DB(new_orders, order_size);
	}


	write_to_orders_DB(new_orders, order_size);

	// change agent order
	change_agent_order(num_orders);

}

// Payment Option
void pay_with_paypal(int price)
{
	cout << "Payment succesful" << endl;
}
void pay_with_points(string num_orders)
{
	Packages* p = read_from_packages_DB();
	int price = 0;
	int p_package = 0;
	// find the package with the same id.
	for (int i = 0; i < size_packages_DB(); i++)
		if (p[i].m_package_id == num_orders)
		{
			price = p[i].m_price;
			p_package = p[i].m_points;
		}




	Hotels* h = read_from_hotels_DB();
	// find the hotel with the same id.
	for (int i = 0; i < size_hotels_DB(); i++)
		if (h[i].m_hotel_id == num_orders)
		{
			price = p[i].m_price;
			p_package = 0;
		};


	Flights* f = read_from_flights_DB();
	// find the flight with the same id.
	for (int i = 0; i < size_flights_DB(); i++)
		if (f[i].m_flight_id == num_orders)
		{
			price = p[i].m_price;
			p_package = 0;
		}


	Customer* c = read_from_customer_DB();
	for (int i = 0; i < size_customer_DB(); i++)
		// find the customer with the same log in id.
	{
		if (c[i].m_id == log_in_id)
		{
			if (c[i].m_points > 0)
			{
				if (price <= c[i].m_points)
				{
					c[i].m_points -= price;
					price = 0;
					c[i].m_points += p_package;
				}

				else
				{
					price -= c[i].m_points;
					c[i].m_points = 0;
					c[i].m_points += p_package;
				}
			}
		}
	}
	write_to_customers_DB(c, size_customer_DB());
	if (price == 0)
		cout << "Payment succesful" << endl;
	else
	{
		cout << "Left to pay: " << price << endl;
		cout << "you are transferred to Paypal" << endl;
		pay_with_paypal(price);
	}

}


//////////////////////////////////////////////////////////////AGENT///////////////////////////////////////////////////////////////////////


//Adding Functions

void add_package_menu(Agent* arr, int agent_index)
{
	int choice = 0;
	while (choice > 0 || choice < 4)
	{
		cout << " ===========ADD PACKAGE MENU============" << endl;
		cout << "1- Add Package" << endl;
		cout << "2- Add Flight" << endl;
		cout << "3- Add Hotel" << endl;
		cout << "4- Back to Agent menu" << endl;

		cout << "Choose Option: ";
		cin >> choice;




		switch (choice)
		{
		case 1:
		{
			add_new_package(read_from_packages_DB(), agent_index);
			break;
		}
		case 2:
		{
			add_new_flight(read_from_flights_DB(), agent_index);
			break;
		}
		case 3:
		{

			add_new_hotel(read_from_hotels_DB(), agent_index);
			break;
		}
		case 4:
		{
			return;
			break;
		}
		default:
			cout << "Wrong Input" << endl;
			cout << endl;
			break;
		}
	}
}
void add_new_package(Packages* arr, int agent_index)
{
	Packages p = make_package(read_from_agent_DB(), agent_index);

	int new_size = size_packages_DB() + 1;
	arr = new Packages[new_size];
	for (int i = 0; i < new_size - 1; i++)
		arr[i] = read_from_packages_DB()[i];
	arr[new_size - 1] = p;

	write_to_packages_DB(arr, new_size);
	agent_menu(read_from_agent_DB(), agent_index);
}
void add_new_flight(Flights* arr, int agent_index)
{
	Flights f = make_flight(read_from_agent_DB(), agent_index);
	int new_size = size_flights_DB() + 1;
	arr = new Flights[new_size];
	for (int i = 0; i < new_size - 1; i++)
		arr[i] = read_from_flights_DB()[i];
	arr[new_size - 1] = f;

	write_to_flights_DB(arr, new_size);
	agent_menu(read_from_agent_DB(), agent_index);



}
void add_new_hotel(Hotels* arr, int agent_index)
{
	Hotels h = make_hotel(read_from_agent_DB(), agent_index);
	int new_size = size_hotels_DB() + 1;
	arr = new Hotels[new_size];
	for (int i = 0; i < new_size - 1; i++)
		arr[i] = read_from_hotels_DB()[i];
	arr[new_size - 1] = h;
	write_to_hotels_DB(arr, new_size);
	agent_menu(read_from_agent_DB(), agent_index);

}

//New struct to add

Packages make_package(Agent* arr, int agent_index)
{
	Packages p;
	Date d;
	char c;
	cout << "Enter new package details:" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Enter package id: " << endl;
	//cin.ignore();
	getline(cin, p.m_package_id);
	while (is_exist_package(read_from_packages_DB(), p.m_package_id))
	{
		cout << "This ID is already in Data Base" << endl;
		cout << "Enter Package ID: " << endl;
		//cin.ignore();
		getline(cin, p.m_package_id);
	}

	cout << "Enter start date in format dd/mm/yy" << endl;
	cin >> d;
	p.m_start = d;
	cout << "Enter end date in format dd/mm/yy" << endl;
	cin >> d;
	p.m_end = d;
	cout << "Enter Country of Origin" << endl;
	cin >> p.m_origin;
	cout << "Enter Destination country" << endl;
	cin >> p.m_destinion;
	cout << "Enter number of travelers" << endl;
	cin >> p.m_num_of_travelers;
	cout << "Enter package price: " << endl;
	cin >> p.m_price;
	cout << "Enter package area: " << endl;
	cin.ignore();
	getline(cin, p.m_area);
	cout << "Enter package quantity: " << endl;
	cin >> p.m_quantity;
	cout << "Is the package an organized trip ? { y/Y-yes n/N-no}" << endl;
	cin >> c;
	while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
	{
		cout << "Is the package an organized trip ? { y/Y-yes n/N-no}" << endl;
		cin >> c;
	}
	if (c == 'y' || c == 'Y')
		p.m_organized_trip = true;
	else
		p.m_organized_trip = false;
	cout << "Enter package description: " << endl;
	cin.ignore();
	getline(cin, p.m_description);
	p.m_points = 0.01 * p.m_price;
	p.m_sales_counter = 0;
	p.m_agent_id = arr[agent_index].m_id;

	return p;

}
Flights make_flight(Agent* arr, int agent_index)
{
	Flights f;
	Date d;
	char c;
	int choice;
	cout << "Enter new flight details" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Enter flight id: " << endl;
	//cin.ignore();
	getline(cin, f.m_flight_id);
	while (is_exist_flight(read_from_flights_DB(), f.m_flight_id))
	{
		cout << "This ID is already in Data Base" << endl;
		cout << "Enter Flight ID: " << endl;
		cin.ignore();
		getline(cin, f.m_flight_id);
	}

	cout << "Enter Departure location" << endl;
	//cin.ignore();
	getline(cin, f.m_departure_location);
	cout << "Enter Arrival location" << endl;
	//cin.ignore();
	getline(cin, f.m_arrival_location);
	cout << "Enter Departure date in format dd/mm/yy" << endl;
	cin >> d;
	f.m_departure_date = d;
	cout << "Enter Return date in format dd/mm/yy" << endl;
	cin >> d;
	f.m_return_date = d;
	cout << "Enter flight's price: " << endl;
	cin >> f.m_price;
	cout << "Enter flight's area: " << endl;
	cin.ignore();
	getline(cin, f.m_area);
	cout << "Is the flight in business class or economy  class ? " << " Press E-Economy B-Business " << endl;
	cin >> c;
	while (c != 'E' && c != 'B')
	{
		cout << "Is the flight in business class or economy  class ? " << " Press E-Economy B-Business " << endl;
		cin >> c;
	}
	if (c == 'E')
		f.m_class_f = 'E';
	else
		f.m_class_f = 'B';
	cout << "Enter Amount of airline tickets " << endl;
	cin >> f.m_quantity;
	cout << "Is the flight direct or with a connection ? { 1 - Direct 2 - With a connection}" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "Is the flight direct or with a connection ? { 1 - Direct 2 - With a connection}" << endl;
		cin >> choice;
	}
	if (choice == 1)
		f.m_direct = true;
	else
	{
		f.m_direct = false;
		cout << " You must enter details of the connecting flights in the description" << endl;
	}
	cout << "Is the round trip flight or one way ? { 1 - Round trip flight 2 - One way}" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "Is the round trip flight or one way ? { 1 - Round trip flight 2 - One way}" << endl;
		cin >> choice;
	}
	if (choice == 1)
		f.m_one_way = true;
	else
	{
		f.m_one_way = false;
	}
	cout << "Enter flight description: " << endl;
	cin.ignore();
	getline(cin, f.m_description);
	f.m_sales_counter = 0;
	f.m_agent_id = arr[agent_index].m_id;

	return f;

}
Hotels make_hotel(Agent* arr, int agent_index)
{
	Hotels h;
	Date d;
	char c;
	int choice;
	cout << "Enter new Hotel details" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Enter Hotel ID: " << endl;
	//cin.ignore();
	getline(cin, h.m_hotel_id);
	while (is_exist_hotel(read_from_hotels_DB(), h.m_hotel_id))
	{
		cout << "This ID is already in Data Base" << endl;
		cout << "Enter Hotel ID:  " << endl;
		//cin.ignore();
		getline(cin, h.m_hotel_id);
	}

	cout << "Enter Hotel Name: " << endl;
	//cin.ignore();
	getline(cin, h.m_hotel_name);
	cout << "Enter Hotel location: " << endl;
	//cin.ignore();
	getline(cin, h.m_hotel_location);
	cout << "Enter Check in date in format dd/mm/yy" << endl;
	cin >> d;
	h.m_check_in = d;
	cout << "Enter Check out date in format dd/mm/yy" << endl;
	cin >> d;
	h.m_check_out = d;
	cout << "Enter the amount of guests in the room " << endl;
	cin >> h.m_guest;
	cout << "Is it a standard room or a suite ? { 1 - Suite 2 - Standard}" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "Is it a standard room or a suite ? { 1 - Suite 2 - Standard}" << endl;
		cin >> choice;
	}
	if (choice == 1)
		h.m_room_type = true;
	else
		h.m_room_type = false;
	cout << " Enter a hotel rating {1-5}" << endl;
	cin >> choice;
	while (choice < 1 || choice>5)
	{
		cout << " Enter a hotel rating {1-5}" << endl;
		cin >> choice;
	}
	h.m_rating = choice;
	cout << "Enter Hotel's price: " << endl;
	cin >> h.m_price;
	cout << "Enter quantity" << endl;
	cin >> h.m_quantity;
	cout << "Enter Hotel's area: " << endl;
	cin.ignore();
	getline(cin, h.m_area);
	cout << "Enter Hotel description: " << endl;
	//cin.ignore();
	getline(cin, h.m_description);
	h.m_sales_counter = 0;
	h.m_agent_id = arr[agent_index].m_id;

	return h;

}

//Update Functions

void update_package(Packages* arr, int agent_index)
{
	string id;
	int choice, counter = 0;
	cout << "Enter id of Package you want to change" << endl;
	cin >> id;
	while (!is_exist_package(arr, id))
	{
		cout << "Package does not exist in Data Base" << endl;
		cout << "1- Try Again " << endl;
		cout << "2- Back To Menu " << endl;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			cout << "ERROR input ,please enter a number 1/2 " << endl;
			cin >> choice;
		}
		if (choice == 1)
		{
			cout << "Enter id of Package you want to change" << endl;
			cin >> id;
		}
		else
		{
			agent_menu(read_from_agent_DB(), agent_index);
			break;
		}

	}
	for (int i = 0; i < size_packages_DB(); i++)
		if (arr[i].m_package_id == id)
		{
			arr[i] = update_p(arr[i]);


			cout << "Do you want to update something else?" << endl << "1.yes  2.no" << endl;
			cin >> choice;
			while (choice != 2)
			{
				if (counter > 0) {
					cout << "Do you want to update something else?" << endl << "1.yes  2.no" << endl;
					cin >> choice;
				}


				while (choice != 1 && choice != 2)
				{
					cout << "ERROR input" << endl;
					cout << "Do you want to update something else?" << endl << "1.yes  2.no" << endl;
					cin >> choice;
				}
				if (choice == 1)
					arr[i] = update_p(arr[i]);
				else if (choice == 2)
					break;
				counter++;
			}
		}

	read_from_packages_DB();
	int size = size_packages_DB();

	ofstream obj("Packages.txt");
	obj << size << endl;
	for (int i = 0; i < size; i++)
	{
		obj << arr[i].m_package_id << " ";
		obj << arr[i].m_start.m_day << " " << arr[i].m_start.m_month << " " << arr[i].m_start.m_year << " ";
		obj << arr[i].m_end.m_day << " " << arr[i].m_end.m_month << " " << arr[i].m_end.m_year << " ";
		obj << arr[i].m_price << " " << arr[i].m_area << " ";
		obj << arr[i].m_origin << " " << arr[i].m_destinion << " " << arr[i].m_num_of_travelers << " ";
		obj << arr[i].m_quantity << " " << arr[i].m_sales_counter << " " << arr[i].m_agent_id << " ";
		obj << arr[i].m_points << " " << arr[i].m_organized_trip;
		obj << arr[i].m_description << endl;

	}

	obj.close();

}
void update_flight(Flights* arr, int agent_index)
{
	string id;
	int choice, counter = 0;
	cout << "Enter id of Flight you want to change" << endl;
	cin >> id;
	while (!is_exist_flight(arr, id))
	{
		cout << "Flight does not exist in Data Base" << endl;
		cout << "1- Try Again " << endl;
		cout << "2- Back To Menu " << endl;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			cout << "ERROR input ,please enter a number 1/2 " << endl;
			cin >> choice;
		}
		if (choice == 1)
		{
			cout << "Enter id of Flight you want to change" << endl;
			cin >> id;
		}
		else
		{
			agent_menu(read_from_agent_DB(), agent_index);
			break;
		}

	}


	for (int i = 0; i < size_flights_DB(); i++)
		if (arr[i].m_flight_id == id)
		{
			arr[i] = update_f(arr[i]);


			cout << "Do you want to update something else?" << endl << "1.yes  2.no" << endl;
			cin >> choice;
			while (choice != 2)
			{
				if (counter > 0) {
					cout << "Do you want to update something else?" << endl << "1.yes  2.no" << endl;
					cin >> choice;
				}


				while (choice != 1 && choice != 2)
				{
					cout << "ERROR input" << endl;
					cout << "Do you want to update something else?" << endl << "1.yes  2.no" << endl;
					cin >> choice;
				}
				if (choice == 1)
					arr[i] = update_f(arr[i]);
				else if (choice == 2)
					break;
				counter++;
			}
		}
	write_to_flights_DB(arr, size_flights_DB());

}
void update_hotel(Hotels* arr, int agent_index)
{
	string id;
	int choice, counter = 0;
	cout << "Enter id of Hotel you want to change" << endl;
	cin >> id;
	while (!is_exist_hotel(arr, id))
	{
		cout << "Flight does not exist in Data Base" << endl;
		cout << "1- Try Again " << endl;
		cout << "2- Back To Menu " << endl;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			cout << "ERROR input ,please enter a number 1/2 " << endl;
			cin >> choice;
		}
		if (choice == 1)
		{
			cout << "Enter id of Flight you want to change" << endl;
			cin >> id;
		}
		else
		{
			agent_menu(read_from_agent_DB(), agent_index);
			break;
		}

	}


	for (int i = 0; i < size_hotels_DB(); i++)
		if (arr[i].m_hotel_id == id)
		{
			arr[i] = update_h(arr[i]);


			cout << "Do you want to update something else?" << endl << "1.yes  2.no" << endl;
			cin >> choice;
			while (choice != 2)
			{
				if (counter > 0) {
					cout << "Do you want to update something else?" << endl << "1.yes  2.no" << endl;
					cin >> choice;
				}


				while (choice != 1 && choice != 2)
				{
					cout << "ERROR input" << endl;
					cout << "Do you want to update something else?" << endl << "1.yes  2.no" << endl;
					cin >> choice;
				}
				if (choice == 1)
					arr[i] = update_h(arr[i]);
				else if (choice == 2)
					break;
				counter++;
			}
		}
	write_to_hotels_DB(arr, size_hotels_DB());

}

//Update struct

Packages update_p(Packages p)
{

	Date d;
	char c;
	int choice, exit = 0, counter = 0;
	cout << "#################################################################" << endl;
	cout << "ID: " << p.m_package_id << endl << "Start: " << p.m_start << endl;
	cout << "End: " << p.m_end << endl << "Price: " << p.m_price << "$" << endl;
	cout << "Quantity right now: " << p.m_quantity << endl;
	cout << "#################################################################" << endl;
	cout << "What do you want to update ?" << endl;
	cout << "1.Package ID" << endl << "2.Start Date" << endl << "3.End Date" << endl << "4.Price" << endl;
	cout << "5.Country of Origin" << endl << "6.Destination country" << endl << "7.number of travelers" << endl;
	cout << "8.Package Area" << endl << "9.Package Quantity" << endl << "10.organized trip" << endl << "11.Description";
	cout << endl;
	cin >> choice;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	switch (choice)
	{
	case 1:
	{
		cout << "Current Package ID: " << p.m_package_id << endl;
		cout << "Enter Package ID: " << endl;
		cin.ignore();
		getline(cin, p.m_package_id);
		break;

	}
	case 2:
	{
		cout << "Current Start Date: " << p.m_start << endl;
		cout << "Enter start date in format dd/mm/yy" << endl;
		cin >> d;
		p.m_start = d;
		break;

	}
	case 3:
	{
		cout << "Current End Date: " << p.m_end << endl;
		cout << "Enter end date in format dd/mm/yy" << endl;
		cin >> d;
		p.m_end = d;
		break;
	}
	case 4:
	{
		cout << "Current Package Price: " << p.m_price << endl;
		cout << "Enter Package Price " << endl;
		cin >> p.m_price;
		break;



	}
	case 5:
	{

		cout << "Current Destination country: " << p.m_destinion << endl;
		cout << "Enter Destination country" << endl;
		cin >> p.m_destinion;
		break;

	}
	case 6:
	{
		cout << "Current Destination country: " << p.m_destinion << endl;
		cout << "Enter Destination country" << endl;
		cin >> p.m_destinion;
		break;


	}
	case 7:
	{
		cout << "Current number of travelers" << p.m_num_of_travelers << endl;
		cout << "Enter number of travelers" << endl;
		cin >> p.m_num_of_travelers;
		break;

	}
	case 8:
	{
		cout << "Current Package Area: " << p.m_area << endl;
		cout << "Enter Package Area " << endl;
		cin.ignore();
		getline(cin, p.m_area);
		break;
	}
	case 9:
	{
		cout << "Quantity right now:" << p.m_quantity << endl;
		cout << "Enter package quantity: " << endl;
		cin >> p.m_quantity;
		break;
	}
	case 10:
	{
		if (p.m_organized_trip == true)
			cout << "The package is currently an organized trip" << endl;
		else
			cout << "The package is currently  NOT an organized trip" << endl;
		cout << "Is the package an organized trip ? { y/Y-yes n/N-no}" << endl;
		cin >> c;
		while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
		{
			cout << "Is the package an organized trip ? { y/Y-yes n/N-no}" << endl;
			cin >> c;
		}
		if (c == 'y' || c == 'Y')
			p.m_organized_trip = true;
		else
			p.m_organized_trip = false;
		break;

	}
	case 11:
	{
		cout << "current Description: " << p.m_description << endl;
		cout << "Enter package Description " << endl;
		cin.ignore();
		getline(cin, p.m_description);
		break;

	}
	default:
	{
		cout << "ERROR input" << endl;
		break;
	}
	}
	p.m_points = 0.01 * p.m_price;
	p.m_agent_id = 12470;

	return p;





}
Flights update_f(Flights f)
{
	Date d;
	char c;
	int choice, exit = 0, counter = 0;
	cout << "#################################################################" << endl;
	cout << "ID: " << f.m_flight_id << endl << "Departure Locaton: " << f.m_departure_location << endl << "Arrival Llocation: " << f.m_arrival_location << endl;
	cout << "Departure date: " << f.m_departure_date << endl << "Return date: " << f.m_return_date << endl;
	cout << "Price: " << f.m_price << "$" << endl;
	cout << "Quantity right now: " << f.m_quantity << endl;
	cout << "#################################################################" << endl;
	cout << "What do you want to update ?" << endl;
	cout << "1.Flight ID" << endl << "2.Departure Location" << endl << "3.Arrival Location" << endl << "4.Departure Date" << endl;
	cout << "5.Return Date" << endl << "6.Price" << endl << "7.Flight Area" << endl;
	cout << "8.Flight Passenger class" << endl << "9. Quantity" << endl << "10.Direct or connection" << endl;
	cout << "11.Round trip or one direction " << endl << "12.Description";
	cout << endl;
	cin >> choice;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	switch (choice)
	{
	case 1:
	{
		cout << "Current Flight ID: " << f.m_flight_id << endl;
		cout << "Enter Flight ID: " << endl;
		cin.ignore();
		getline(cin, f.m_flight_id);
		break;

	}
	case 2:
	{
		cout << "Current Departure Locaton: " << f.m_departure_location << endl;
		cout << "Enter Departure location" << endl;
		cin.ignore();
		getline(cin, f.m_departure_location);
		break;

	}
	case 3:
	{
		cout << "Current Arrival Location: " << f.m_departure_location << endl;
		cout << "Enter Arrival location" << endl;
		cin.ignore();
		getline(cin, f.m_arrival_location);
		break;
	}
	case 4:
	{
		cout << "Current Departure Date: " << f.m_departure_date << endl;
		cout << "Enter Departure Date in format dd/mm/yy" << endl;
		cin >> d;
		f.m_departure_date = d;
		break;

	}
	case 5:
	{

		cout << "Current Return Date: " << f.m_departure_date << endl;
		cout << "Enter Return Date in format dd/mm/yy" << endl;
		cin >> d;
		f.m_return_date = d;
		break;

	}
	case 6:
	{
		cout << "Current Flight Price: " << f.m_price << endl;
		cout << "Enter Flight Price " << endl;
		cin >> f.m_price;
		break;


	}
	case 7:
	{
		cout << "Current Flight Area: " << f.m_area << endl;
		cout << "Enter Flight Area " << endl;
		cin.ignore();
		getline(cin, f.m_area);
		break;

	}
	case 8:
	{
		if (f.m_class_f == 'E')
			cout << "Current Flight Passenger class is Economy Class " << endl;
		else
			cout << "Current Flight Passenger class is Business Class " << endl;

		cout << "Flight Passenger class " << endl;
		cin >> c;
		while (c != 'E' && c != 'B')
		{
			cout << "Is the flight in business class or economy  class ? " << " Press E-Economy B-Business " << endl;
			cin >> c;
		}
		if (c == 'E')
			f.m_class_f = 'E';
		else
			f.m_class_f = 'B';
		break;
	}
	case 9:
	{
		cout << "Quantity right now:" << f.m_quantity << endl;
		cout << "Enter Flight quantity: " << endl;
		cin >> f.m_quantity;
		break;
	}
	case 10:
	{
		if (f.m_direct == true)
			cout << "The current flight is direct" << endl;
		else
			cout << "The current flight isn't direct" << endl;

		cout << "Is the flight direct or with a connection ? { 1 - Direct 2 - With a connection}" << endl;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			cout << "Is the flight direct or with a connection ? { 1 - Direct 2 - With a connection}" << endl;
			cin >> choice;
		}
		if (choice == 1)
			f.m_direct = true;
		else
		{
			f.m_direct = false;
			cout << " You must enter details of the connecting flights in the description" << endl;
		}
		break;

	}
	case 11:
	{
		if (f.m_one_way == true)
			cout << "The flight is round trip" << endl;
		else
			cout << "The flight is one direction" << endl;

		cout << "Is the round trip flight or one way ? { 1 - Round trip flight 2 - One way}" << endl;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			cout << "Is the round trip flight or one way ? { 1 - Round trip flight 2 - One way}" << endl;
			cin >> choice;
		}
		if (choice == 1)
			f.m_one_way = true;
		else
			f.m_one_way = false;
		break;
	}
	case 12:
	{
		cout << "current Description: " << f.m_description << endl;
		cout << "Enter Flight Description " << endl;
		cin.ignore();
		getline(cin, f.m_description);
		break;

	}
	default:
	{
		cout << "ERROR input" << endl;
		break;
	}
	}
	f.m_agent_id = 12470;

	return f;

}
Hotels update_h(Hotels h)
{
	Date d;
	char c;
	int choice, exit = 0, counter = 0;
	cout << "#################################################################" << endl;
	cout << "ID: " << h.m_hotel_id << endl << "Hotel name: " << h.m_hotel_name << endl << "Hotel Llocation: " << h.m_hotel_location << endl;
	cout << "Check in date: " << h.m_check_in << endl << "Check out date: " << h.m_check_out << endl;
	cout << "Price: " << h.m_price << "$" << endl;
	cout << "Quantity right now: " << h.m_quantity << endl;
	cout << "#################################################################" << endl;
	cout << "What do you want to update ?" << endl;
	cout << "1.Hotel ID" << endl << "2.Hotel name" << endl << "3.Hotel Location" << endl << "4.Check in Date" << endl;
	cout << "5.Check out Date" << endl << "6.Number of guests" << endl << "7.Suite or standard room type" << endl;
	cout << "8.Hotel Rating" << endl << "9. Quantity" << endl << "10.Price" << endl;
	cout << "11.Hotel Area " << endl << "12.Description";
	cout << endl;
	cin >> choice;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	switch (choice)
	{
	case 1:
	{
		cout << "Current Hotel ID: " << h.m_hotel_id << endl;
		cout << "Enter Hotel ID: " << endl;
		cin.ignore();
		getline(cin, h.m_hotel_id);
		break;

	}
	case 2:
	{
		cout << "Current Hotel name: " << h.m_hotel_name << endl;
		cout << "Enter Hotel name" << endl;
		cin.ignore();
		getline(cin, h.m_hotel_name);
		break;

	}
	case 3:
	{
		cout << "Current Hotel Location: " << h.m_hotel_location << endl;
		cout << "Enter Hotel location" << endl;
		cin.ignore();
		getline(cin, h.m_hotel_location);
		break;
	}
	case 4:
	{
		cout << "Current Check in Date: " << h.m_check_in << endl;
		cout << "Enter Check in Date in format dd/mm/yy" << endl;
		cin >> d;
		h.m_check_in = d;
		break;

	}
	case 5:
	{

		cout << "Current Check out Date: " << h.m_check_out << endl;
		cout << "Enter Check out date in format dd/mm/yy" << endl;
		cin >> d;
		h.m_check_out = d;
		break;

	}
	case 6:
	{
		cout << "Current Number of guests: " << h.m_guest << endl;
		cout << "Enter Number of guests " << endl;
		cin >> h.m_guest;
		break;


	}
	case 7:
	{
		if (h.m_room_type == true)
			cout << "The current room is a suite" << endl;
		else
			cout << "The current room is a standard room" << endl;

		cout << "Is it a standard room or a suite ? { 1 - Suite 2 - Standard}" << endl;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			cout << "Is it a standard room or a suite ? { 1 - Suite 2 - Standard}" << endl;
			cin >> choice;
		}
		if (choice == 1)
			h.m_room_type = true;
		else
			h.m_room_type = false;
		break;

	}
	case 8:
	{
		cout << "Current Hotel Rating: " << h.m_rating << endl;
		cout << "Enter Hotel Rating " << endl;
		cin >> h.m_rating;
		break;

	}
	case 9:
	{
		cout << "Quantity right now:" << h.m_quantity << endl;
		cout << "Enter Hotel quantity: " << endl;
		cin >> h.m_quantity;
		break;

	}
	case 10:
	{
		cout << "Current Hotel Price: " << h.m_price << endl;
		cout << "Enter Hotel Price " << endl;
		cin >> h.m_price;
		break;

	}
	case 11:
	{
		cout << "Current Hotel Area: " << h.m_area << endl;
		cout << "Enter Hotel Area " << endl;
		cin.ignore();
		getline(cin, h.m_area);
		break;
	}
	case 12:
	{
		cout << "current Description: " << h.m_description << endl;
		cout << "Enter Flight Description " << endl;
		cin.ignore();
		getline(cin, h.m_description);
		break;

	}
	default:
	{
		cout << "ERROR input" << endl;
		break;
	}
	}
	h.m_agent_id = 12470;

	return h;

}

//Remove Functions

void remove_package(Packages* arr, int agent_index)
{
	Packages p_r;
	string id;
	int choice, size = 0;
	cout << "Enter id of Package you want to remove" << endl;
	cin >> id;
	while (!is_exist_package(arr, id))
	{
		cout << "Package does not exist in Data Base" << endl;
		cout << "1- Try Again " << endl;
		cout << "2- Back To Menu" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter id of Package you want to remove" << endl;
			cin >> id;
			break;
		}
		case 2:
		{
			agent_menu(read_from_agent_DB(), agent_index);
			break;

		}

		default:
		{
			cout << "ERROR input ,please enter a number 1/2 " << endl;
			cin >> choice;
		}


		}
	}
	size = size_packages_DB();
	for (int i = 0; i < size; i++)
	{
		if (arr[i].m_package_id == id)
			p_r = arr[i];
	}
	cout << "The Package you choose to remove is:" << endl << endl;
	print_package(p_r);
	cout << endl << "Are you sure you want to remove the package? {1-yes  2-no}" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << endl << "Are you sure you want to remove the package? {1-yes  2-no}" << endl;
		cin >> choice;
	}
	if (choice == 1)
	{
		Packages* new_arr = new Packages[size - 1];
		int i = 0, j = 0;
		while (j < size - 1)
		{
			if (arr[i].m_package_id == id)
				i++;
			else
				new_arr[j++] = arr[i++];

		}

		read_from_packages_DB();
		size = size_packages_DB() - 1;

		write_to_packages_DB(new_arr, size);
		cout << "The package was successfully removed" << endl;
	}
	else
		agent_menu(read_from_agent_DB(), agent_index);
}
void remove_flight(Flights* arr, int agent_index)
{
	Flights f_r;
	string id;
	int choice, size = 0;
	cout << "Enter id of Flight you want to remove" << endl;
	cin >> id;
	while (!is_exist_flight(arr, id))
	{
		cout << "Flight does not exist in Data Base" << endl;
		cout << "1- Try Again " << endl;
		cout << "2- Back To Menu" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter id of Flight you want to remove" << endl;
			cin >> id;
			break;
		}
		case 2:
		{
			agent_menu(read_from_agent_DB(), agent_index);
			break;

		}

		default:
		{
			cout << "ERROR input ,please enter a number 1/2 " << endl;
			cin >> choice;
		}


		}
	}
	size = size_flights_DB();
	for (int i = 0; i < size; i++)
	{
		if (arr[i].m_flight_id == id)
			f_r = arr[i];
	}
	cout << "The Flight you choose to remove is:" << endl << endl;
	print_flight(f_r);
	cout << endl << "Are you sure you want to remove the Flight? {1-yes  2-no}" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << endl << "Are you sure you want to remove the Flight? {1-yes  2-no}" << endl;
		cin >> choice;
	}
	if (choice == 1)
	{
		Flights* new_arr = new Flights[size - 1];
		int i = 0, j = 0;
		while (j < size - 1)
		{
			if (arr[i].m_flight_id == id)
				i++;
			else
				new_arr[j++] = arr[i++];

		}

		read_from_flights_DB();
		size = size_flights_DB() - 1;

		write_to_flights_DB(new_arr, size);
		cout << "The Flight was successfully removed" << endl;
	}
	else
		agent_menu(read_from_agent_DB(), agent_index);
}
void remove_hotel(Hotels* arr, int agent_index)
{
	Hotels h_r;
	string id;
	int choice, size = 0;
	cout << "Enter id of Hotel you want to remove" << endl;
	cin >> id;
	while (!is_exist_hotel(arr, id))
	{
		cout << " Hotel does not exist in Data Base" << endl;
		cout << "1- Try Again " << endl;
		cout << "2- Back To Menu" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter id of  Hotel you want to remove" << endl;
			cin >> id;
			break;
		}
		case 2:
		{
			agent_menu(read_from_agent_DB(), agent_index);
			break;

		}

		default:
		{
			cout << "ERROR input ,please enter a number 1/2 " << endl;
			cin >> choice;
		}


		}
	}
	size = size_hotels_DB();
	for (int i = 0; i < size; i++)
	{
		if (arr[i].m_hotel_id == id)
			h_r = arr[i];
	}
	cout << "The Hotel you choose to remove is:" << endl << endl;
	print_hotel(h_r);
	cout << endl << "Are you sure you want to remove the Hotel? {1-yes  2-no}" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << endl << "Are you sure you want to remove the Hotel? {1-yes  2-no}" << endl;
		cin >> choice;
	}
	if (choice == 1)
	{
		Hotels* new_arr = new Hotels[size - 1];
		int i = 0, j = 0;
		while (j < size - 1)
		{
			if (arr[i].m_hotel_id == id)
				i++;
			else
				new_arr[j++] = arr[i++];

		}

		read_from_hotels_DB();
		size = size_hotels_DB() - 1;

		write_to_hotels_DB(new_arr, size);
		cout << "The Hotel was successfully removed" << endl;
	}
	else
		agent_menu(read_from_agent_DB(), agent_index);

}
void remove_message(long id)
{
	Messages* m = read_from_messages_DB();
	Messages m_r;
	int choice, size = size_messages_DB();
	for (int i = 0; i < size; i++)
	{
		if (m[i].m_message_id == id)
			m_r = m[i];
	}

	Messages* new_arr = new Messages[size - 1];
	int i = 0, j = 0;
	while (j < size - 1)
	{
		if (m[i].m_message_id == id)
			i++;
		else
			new_arr[j++] = m[i++];

	}
	write_to_messages_DB(new_arr, size - 1);

}

//Print Functions

void print_package(Packages p)
{
	cout << " Package ID: " << p.m_package_id << endl;
	cout << " The Package Area : " << p.m_area << endl;
	cout << " The Package Origin : " << p.m_origin << endl;
	cout << " The Package Destinion : " << p.m_destinion << endl;
	cout << " The Package start date : " << p.m_start;
	cout << " The Package end data : " << p.m_end;
	cout << " The Pckage is for : " << p.m_num_of_travelers << endl;
	cout << " The Package price : " << p.m_price << " $" << endl;
	cout << " The Package give you " << p.m_points << " points" << endl;
	if (p.m_organized_trip)
		cout << "This package ia for organized trip" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                  Description                     " << endl;
	cout << p.m_description << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;


}
void print_flight(Flights f)
{
	cout << "  Flight ID: " << f.m_flight_id << endl;
	cout << "  The Flight Area : " << f.m_area << endl;
	cout << "  The Flight Departure location : " << f.m_departure_location << endl;
	cout << "  The Flight Arrival_location : " << f.m_arrival_location << endl;
	cout << "  The Flight Departure date : " << f.m_departure_date;
	cout << "  The Flight Return data : " << f.m_return_date;
	cout << "  The Flight price : " << f.m_price << " $" << endl;
	if (f.m_class_f == 'E')
		cout << "  The Economy class flight" << endl;
	else
		cout << " - Business class flight" << endl;
	if (f.m_direct)//1 - Direct 2 - With a connection
		cout << "  This is Direct flight" << endl;
	else
		cout << "  This is Connecting through flight" << endl;
	if (f.m_one_way)//1 - Round trip flight 2 - One way
		cout << "  This is Round trip flight" << endl;
	else
		cout << "  This is One way flight" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                  Description                     " << endl;
	cout << f.m_description << endl << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

}
void print_hotel(Hotels h)
{
	cout << "  Hotel ID: " << h.m_hotel_id << endl;
	cout << "  The Hotel Area : " << h.m_area << endl;
	cout << "  The Hotel location : " << h.m_hotel_location << endl;
	cout << "  The Check in date : " << h.m_check_in;
	cout << "  The Check out data : " << h.m_check_out;
	cout << "  The Hotel Rating : " << h.m_rating << " stars" << endl;
	cout << "  The Hotel price : " << h.m_price << " $" << endl;
	cout << "  The Room is for :" << h.m_guest << " Guests" << endl;
	if (h.m_room_type)//1 - Suite 2 - Standard
		cout << "  This is Suite room " << endl;
	else
		cout << "  This is Standard room " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                  Description                     " << endl;
	cout << h.m_description << endl << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
//Is Exist Functions

bool is_exist_agent(long id)
{
	Agent* arr = new Agent[size_agent_DB()];
	for (int i = 0; i < size_agent_DB(); i++)
		arr[i] = read_from_agent_DB()[i];
	for (int i = 0; i < size_agent_DB(); i++)
	{
		if (arr[i].m_id == id)
			return true;
	}
	return false;
}
bool is_exist_package(Packages* arr, string id)
{
	for (int i = 0; i < size_packages_DB(); i++)
	{
		if (arr[i].m_package_id == id)
			return true;
	}
	return false;
}
bool is_exist_flight(Flights* arr, string id)
{
	for (int i = 0; i < size_flights_DB(); i++)
	{
		if (arr[i].m_flight_id == id)
			return true;
	}
	return false;

}
bool is_exist_hotel(Hotels* arr, string id)
{
	for (int i = 0; i < size_hotels_DB(); i++)
	{
		if (arr[i].m_hotel_id == id)
			return true;
	}
	return false;

}
bool is_exist_order(Orders* arr, string id)
{

	for (int i = 0; i < size_orders_DB(); i++)
	{
		if (arr[i].m_package_id == id)
			return true;
	}
	return false;

}
bool is_exist_str(string* s, int size, string id)
{
	for (int i = 0; i < size; i++)
	{
		if (s[i] == id)
			return true;
	}
	return false;
}

//Functions for checking packages belonging to the agent

Packages* agent_packages(Packages* arr, int* p, long agent_id)
{
	int p_size = size_packages_DB();
	*p = 0;
	for (int i = 0; i < p_size; i++)
	{
		if (arr[i].m_agent_id == agent_id)
			(*p)++;
	}

	Packages* p_arr = new Packages[*p];
	int i = 0, j = 0;
	while (j < *p)
	{
		if (arr[i].m_agent_id == agent_id)
		{
			p_arr[j] = arr[i];
			i++;
			j++;
			continue;
		}
		else
			i++;
	}
	/*for (i = 0; i < *p; i++)
		print_package(p_arr[i]);*/
	return p_arr;
}
Flights* agent_flights(Flights* arr, int* f, long agent_id)
{
	int f_size = size_flights_DB();
	*f = 0;
	for (int i = 0; i < f_size; i++)
	{
		if (arr[i].m_agent_id == agent_id)
			(*f)++;
	}
	Flights* f_arr = new Flights[*f];
	int i = 0, j = 0;
	while (j < *f)
	{
		if (arr[i].m_agent_id == agent_id)
		{
			f_arr[j] = arr[i];
			i++;
			j++;
			continue;
		}
		else
			i++;
	}
	/*for (i = 0; i < *f; i++)
		print_flight(f_arr[i]);*/

	return f_arr;
}
Hotels* agent_hotels(Hotels* arr, int* h, long agent_id)
{
	int h_size = size_hotels_DB();
	*h = 0;
	for (int i = 0; i < h_size; i++)
	{
		if (arr[i].m_agent_id == agent_id)
			(*h)++;
	}
	Hotels* h_arr = new Hotels[*h];
	int i = 0, j = 0;
	while (j < *h)
	{
		if (arr[i].m_agent_id == agent_id)
		{
			h_arr[j] = arr[i];
			i++;
			j++;
			continue;
		}
		else
			i++;
	}
	/*for (i = 0; i < *h; i++)
		print_hotel(h_arr[i]);*/
	return h_arr;
}
void add_order_arr(Orders** arr, int* size, Orders order)
{
	if (*size == 0)
	{
		*size = 1;
		*arr = new Orders[*size];
		*arr[0] = order;
	}
	else
	{
		Orders* temp = new Orders[*size];
		for (int i = 0; i < *size; i++)
			temp[i] = *arr[i];
		(*size)++;
		*arr = new Orders[*size];
		for (int i = 0; i < *size - 1; i++)
			*arr[i] = temp[i];
		(*arr)[*size - 1] = order;
	}

}

//Agent Functions
void agent_login(Agent* arr)
{
	long id;
	string c;
	bool success;
	int exit;
	cout << " ~~~~~~~~~~~~ AGENT LOG IN ~~~~~~~~~~~~" << endl;
	cout << "ID number:" << endl;
	cin >> id;
	while (!is_exist_agent(id))
	{

		int choice = 0;
		cout << "No ID in our Agent DB" << endl;
		cout << "1- Try Again." << endl;
		cout << "2- Back To Menu" << endl;
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
	cout << endl << "Enter company code:" << endl;
	cin.ignore();
	getline(cin, c);
	while (c != CompanyCode)
	{
		int choice = 0;
		cout << "Password Incorrect" << endl;
		cout << "1- Try Again." << endl;
		cout << "2- Back To Menu" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter Password: ";
			cin.ignore();
			getline(cin, c);
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
	for (int i = 0; i < size_agent_DB(); i++)
	{
		if (arr[i].m_id == id)
		{
			cout << "WELLCOME " << arr[i].m_first_name << " !" << endl;
			index = i;
		}
	}
	agent_menu(arr, index);

}
void customer_orders(Packages* p, Flights* f, Hotels* h, Orders* arr, long agent_id)
{
	int p_c = 0, f_c = 0, h_c = 0;
	int counter = 0;
	int size_of_order = 0;
	Packages* p_of_a = agent_packages(read_from_packages_DB(), &p_c, agent_id);
	Flights* f_of_a = agent_flights(read_from_flights_DB(), &f_c, agent_id);
	Hotels* h_of_a = agent_hotels(read_from_hotels_DB(), &h_c, agent_id);
	counter = p_c + f_c + h_c;
	int so = size_orders_DB();
	Orders* o = new Orders[counter];
	string* s = new string[counter];
	int index = 0;
	/*for (int i = 0; i < p_c; i++)
	{
		if (is_exist_package(p_of_a, arr[i].m_package_id))
			add_order_arr(&o, &size_of_order, arr[i]);
	}
	for (int i = 0; i < f_c; i++)
	{
		if (is_exist_flight(f_of_a, arr[i].m_package_id))
			add_order_arr(&o, &size_of_order, arr[i]);
	}
	for (int i = 0; i < h_c; i++)
	{
		if (is_exist_hotel(h_of_a, arr[i].m_package_id))
			add_order_arr(&o, &size_of_order, arr[i]);
	}*/


	while (index < counter)
	{
		for (int i = 0; i < p_c; i++)
		{
			if (is_exist_order(arr, p[i].m_package_id))
			{
				s[index] = p[i].m_package_id;
				index++;
			}
		}
		break;
	}
	while (index < counter)
	{
		for (int i = 0; i < f_c; i++)
		{
			if (is_exist_order(arr, f[i].m_flight_id))
			{
				s[index] = f[i].m_flight_id;
				index++;
			}
		}
		break;
	}
	while (index < counter)
	{
		for (int i = 0; i < h_c; i++)
		{
			if (is_exist_order(arr, h[i].m_hotel_id))
			{
				s[index] = h[i].m_hotel_id;
				index++;
			}
		}
		break;
	}
	for (int i = 0; i < size_orders_DB(); i++)
	{
		if (is_exist_str(s, index, arr[i].m_package_id))
			add_order_arr(&o, &size_of_order, arr[i]);
	}
	Customer* c = read_from_customer_DB();
	cout << endl << "--------------------------------------------------------------------------------------------------------" << endl;
	cout << "|  Customer Name  |    Phone Number    |           Email            |  Package ID |       Status       |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < size_customer_DB(); j++)
		{
			if (o[i].m_customer_id == c[j].m_id)
			{
				cout << "|  " << c[j].m_first_name << "     |    " << c[j].m_phone << "    |          " << c[j].m_email << "            |  " << o[i].m_package_id << "     |       " << o[i].m_status << "      |" << endl;
				cout << "-----------------------------------------------------------------------------------------------------------" << endl;

			}


		}

	}
	string choice;
	int select;
	cout << "Press 0 if you want to back to Menu" << endl;
	cin >> select;
	if (select == 0)
		return;
	cout << "Select an order that you want to change status {Package/Flight/Hotel ID}" << endl;
	cin.ignore();
	getline(cin, choice);
	while (!is_exist_str(s, index, choice))
	{
		cout << "The selection does not exist. Try again" << endl;
		getline(cin, choice);
	}
	for (int i = 0; i < index; i++)
	{
		if (o[i].m_package_id == choice)
		{
			cout << "Current Status: " << o[i].m_status << endl;
			cout << "Select a new status" << endl;
			cout << "-----------------" << endl;
			cout << "|  1.Approved    |" << endl;
			cout << "-----------------" << endl;
			cout << "-----------------" << endl;
			cout << "| 2.Cancelled    |" << endl;
			cout << "-----------------" << endl;
			cout << "-----------------" << endl;
			cout << "| 3.Back to Menu |" << endl;
			cout << "-----------------" << endl;
			cin >> select;
			while (select != 1 && select != 2 && select != 3)
			{
				cout << "Invalid Input, try again" << endl;
				cout << "Select a new status" << endl;
				cout << "-----------------" << endl;
				cout << "|  1.Approved    |" << endl;
				cout << "-----------------" << endl;
				cout << "-----------------" << endl;
				cout << "| 2.Cancelled    |" << endl;
				cout << "-----------------" << endl;
				cout << "-----------------" << endl;
				cout << "| 3.Back to Menu |" << endl;
				cout << "-----------------" << endl;
				cin >> select;

			}
			if (select == 1)
			{
				o[i].m_status = "Approved";
				break;
			}
			else if (select == 2)
			{
				o[i].m_status = "Cancelled";
				break;
			}
			else
				agent_menu(read_from_agent_DB(), agent_id);

		}
	}
	cout << "The status has changed successfully" << endl;
	for (int i = 0; i < size_orders_DB(); i++)
	{
		for (int j = 0; j < index; j++)
		{
			if (arr[i].m_package_id == o[j].m_package_id)
				arr[i] = o[j];
		}

	}
	write_to_orders_DB(arr, size_orders_DB());

}
void answer_message(Agent* a_db, long agent_id)
{
	int count = 0;
	string area;
	for (int i = 0; i < size_agent_DB(); i++)
	{
		if (a_db[i].m_id == agent_id)
			area = a_db[i].m_area;
	}
	Messages* m_db = read_from_messages_DB();
	Messages* arr = new Messages[size_messages_DB()];
	Customer* c_db = read_from_customer_DB();
	for (int i = 0; i < size_messages_DB(); i++)
	{
		if (area == m_db[i].m_area || m_db[i].m_area == "ND")
		{
			for (int j = 0; j < size_customer_DB(); j++)
			{
				if (m_db[i].m_customer_id == c_db[j].m_id)
				{
					arr[count] = m_db[i];
					count++;
					cout << "===============" << count << "==============" << endl;
					cout << "From:" << c_db[j].m_first_name << " " << c_db[j].m_last_name << endl;
					cout << "Email:" << c_db[j].m_email << endl;
					cout << "Phone:" << c_db[j].m_phone << endl;
					cout << "------------------------------------------" << endl;
					cout << m_db[i].m_massege << endl;
					cout << endl;

				}
			}
		}
	}
	int choise;
	cout << "enter which message you want to answer: ";
	cin >> choise;
	remove_message(arr[choise - 1].m_message_id);
	cout << "answered via Email...message removed from database." << endl;



}
void view_package_DB(Agent* arr, int agent_index)
{
	int size_p = size_packages_DB();
	int size_f = size_flights_DB();
	int size_h = size_hotels_DB();
	Packages* p = read_from_packages_DB();
	Flights* f = read_from_flights_DB();
	Hotels* h = read_from_hotels_DB();
	int p_c, f_c, h_c;
	Packages* a_p = agent_packages(p, &p_c, arr[agent_index].m_id);
	Flights* a_f = agent_flights(f, &f_c, arr[agent_index].m_id);
	Hotels* a_h = agent_hotels(h, &h_c, arr[agent_index].m_id);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                WELLCOME TO DATA BASE                           " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	int choice, sel;
	cout << endl << "       Hello " << arr[agent_index].m_first_name << "         " << endl << endl;
	cout << " Select the desired option " << endl;
	cout << "------------------------------------" << endl;
	cout << "|  1. View all existing Data Base  |" << endl;
	cout << "------------------------------------" << endl << endl;
	cout << "------------------------------------" << endl;
	cout << "|  2.View the personal database     |" << endl;
	cout << "| { Packages / Flights / Hotels }   |" << endl;
	cout << "------------------------------------" << endl << endl;
	cout << "------------------------------------" << endl;
	cout << "|        3. Back to Menu            |" << endl;
	cout << "------------------------------------" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3)
	{
		cout << " Select the desired option " << endl;
		cout << "------------------------------------" << endl;
		cout << "|  1. View all existing Data Base  |" << endl;
		cout << "------------------------------------" << endl << endl;
		cout << "------------------------------------" << endl;
		cout << "|  2.View the personal database     |" << endl;
		cout << "| { Packages / Flights / Hotels }   |" << endl;
		cout << "------------------------------------" << endl << endl;
		cout << "------------------------------------" << endl;
		cout << "|        3. Back to Menu            |" << endl;
		cout << "------------------------------------" << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		for (int i = 0; i < size_p; i++)
		{
			cout << "-------------------------------------------------" << endl;
			print_package(p[i]);
		}
		cout << "-------------------------------------------------" << endl;
		for (int i = 0; i < size_f; i++)
		{
			cout << "-------------------------------------------------" << endl;
			print_flight(f[i]);
		}
		cout << "-------------------------------------------------" << endl;
		for (int i = 0; i < size_h; i++)
		{
			cout << "-------------------------------------------------" << endl;
			print_hotel(h[i]);
		}
		cout << "-------------------------------------------------" << endl;
		break;
	}
	case 2:
	{
		for (int i = 0; i < p_c; i++)
		{
			cout << "-------------------------------------------------" << endl;
			print_package(a_p[i]);
		}
		cout << "-------------------------------------------------" << endl;
		for (int i = 0; i < f_c; i++)
		{
			cout << "-------------------------------------------------" << endl;
			print_flight(a_f[i]);
		}
		cout << "-------------------------------------------------" << endl;
		for (int i = 0; i < h_c; i++)
		{
			cout << "-------------------------------------------------" << endl;
			print_hotel(h[i]);
		}
		cout << "-------------------------------------------------" << endl;
		break;
	}
	case 3:
	{
		agent_menu(arr, arr[agent_index].m_id);
		break;
	}
	}

	cout << endl << " What do you want to do ? " << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "|  1. Remove { Packages / Flights / Hotels }  |" << endl;
	cout << "-----------------------------------------------" << endl << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "|  2. Update { Packages / Flights / Hotels }  |" << endl;
	cout << "-----------------------------------------------" << endl << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "|              3. Back to Menu                |" << endl;
	cout << "-----------------------------------------------" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3)
	{
		cout << endl << " What do you want to do ? " << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "|  1. Remove { Packages / Flights / Hotels }  |" << endl;
		cout << "-----------------------------------------------" << endl << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "|  2. Update { Packages / Flights / Hotels }  |" << endl;
		cout << "-----------------------------------------------" << endl << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "|              3. Back to Menu                |" << endl;
		cout << "-----------------------------------------------" << endl;
		cin >> choice;
	}

	switch (choice)
	{
	case 1:
	{
		cout << " What do you want to remove ? " << endl;
		cout << "1 - Package" << endl << "2 - Flight" << endl << "3 - Hotel" << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		cout << "| You have the option to remove only items you have uploaded |" << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		cin >> sel;
		while (sel < 1 || sel>3)
		{
			cout << " What do you want to remove ? " << endl;
			cout << "1 - Package" << endl << "2 - Flight" << endl << "3 - Hotel" << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cout << "| You have the option to remove only items you have uploaded |" << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cin >> sel;
		}
		if (sel == 1)
			remove_package(a_p, agent_index);
		else if (sel == 2)
			remove_flight(a_f, agent_index);
		else
			remove_hotel(a_h, agent_index);
		break;
	}
	case 2:
	{
		cout << " What do you want to update ? " << endl;
		cout << "1 - Package" << endl << "2 - Flight" << endl << "3 - Hotel" << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		cout << "| You have the option to update only items you have uploaded |" << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		cin >> sel;
		while (sel < 1 || sel>3)
		{
			cout << " What do you want to update ? " << endl;
			cout << "1 - Package" << endl << "2 - Flight" << endl << "3 - Hotel" << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cout << "| You have the option to update only items you have uploaded |" << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cin >> sel;
		}
		if (sel == 1)
			update_package(a_p, agent_index);
		else if (sel == 2)
			update_flight(a_f, agent_index);
		else
			update_hotel(a_h, agent_index);
		break;

	}
	case 3:
	{
		agent_menu(arr, arr[agent_index].m_id);
		break;
	}

	}

}

void agent_menu(Agent* arr, int agent_index)
{
	cout << endl << "Hello, wellcome " << arr[agent_index].m_first_name << " Glad to see you again" << endl;

	int choice = 0;
	int p, f, h;
	while (choice != 5)
	{
		cout << "===============AGENT MENU=====================" << endl;
		cout << "Menu:\n1- Add package\n2- Customer's order\n3- Answer customer\n4- Package DB\n5- Log out and return to home page" << endl;
		cout << "====================================" << endl;
		cout << "Please enter your choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			add_package_menu(arr, agent_index);
			break;
		}
		case 2:
			customer_orders(agent_packages(read_from_packages_DB(), &p, arr[agent_index].m_id), agent_flights(read_from_flights_DB(), &f, arr[agent_index].m_id), agent_hotels(read_from_hotels_DB(), &h, arr[agent_index].m_id), read_from_orders_DB(), arr[agent_index].m_id);
			break;
		case 3:
			answer_message(arr, agent_index);
			break;
		case 4:
			view_package_DB(arr, agent_index);
			break;
		case 5:
			return;
			break;

		default:
		{
			cout << "ERROR input ,please enter a number between 1-5 " << endl;
			cin >> choice;
			break;
		}
		}
	}

}

////////////////////////////////////////////////////////////////SEARCH////////////////////////////////////////////////////////////////////

void search_package()
{
	int choice;
	cout << "==================SEARCH PACKAGE MENU===================" << endl;
	cout << "1- Flight\n2- Hotels\n3- Vacation\n4- return to Home page" << endl;
	choice = input_num();
	switch (choice)
	{
	case 1:
		flight();
		break;
	case 2:
		hotels();
		break;
	case 3:
		packages(read_from_packages_DB());
		break;
	case 4:
		return;

	default:
		cout << "ERROR input please insert a number between 1-5" << endl;
		break;
	}
}

//All type choice function

void flight()
{
	//search flight
	string departure_location, arrival_location;
	Date departure_date, return_date;
	float price;
	char class_f;//'E'-Economy Class ,'B'- Business class. 
	bool only_direct = false; // False - Connecting flights and direct flights , True - Only direct flights
	bool one_way; // one_way - True , round trip - False.
	bool filter = false; //True -  If the customer wants to filter the results , false - if the customer wants to see all the results.
	int user_selection;//The number of the flight from the list of flights selected by the customer.
	bool price_filter = false; //True - If the customer chooses to filter results by price.
	bool class_filter = false; //True - If the customer chooses to filter results by class.
	bool direct_filter = false; //True - If the customer chooses to filter results by flight type.
	cout << endl;
	cout << " ===========SEARCH FLIGHT============" << endl;

	cout << "Departure location: ";
	departure_location = input_location();
	cout << "Destination: ";
	arrival_location = input_location();
	cout << "Departure Date: " << endl;
	cin >> departure_date;
	while (today_date() > departure_date && !(today_date() == departure_date))
	{
		cout << "The date must be equal or later than the date " << today_date() << endl;
		cin >> departure_date;
	}
	cout << "one way flight or a round trip ? " << endl;
	cout << "0 - Round Trip" << endl;
	cout << "1 - one way" << endl;
	cout << "Choose Option: ";
	one_way = input_num();
	if (!one_way) //If the customer wants a return flight.
	{
		cout << "Return Date: " << endl;
		cin >> return_date;
		while (!check_dates(departure_date, return_date))
		{
			cout << "invalid date. enter again(DD/MM/YYYY):" << endl;
			cin >> return_date;
		}

	}
	cout << "Do you want to filter the results ? " << endl;
	cout << "1 - YES" << endl;
	cout << "0 - NO" << endl;
	cout << "Choose Option: ";
	filter = input_num();
	if (filter)//If the customer wants to filter results.
	{
		int filter_choice;
		do
		{
			cout << endl;
			cout << "1.Filter results by price\n2.Filter results by class\n3.Filter results flight type\n4.Back to search flight\n " << endl;
			cout << "Choose Option: ";
			filter_choice = input_num();
			switch (filter_choice)
			{
			case 1:
				cout << "Maximum price: ";
				price = input_price();
				price_filter = true;
				break;
			case 2:
				cout << "Economy Class - press 'E' , Business class - press 'B': ";
				class_f = class_input();
				class_filter = true;
				break;
			case 3:

				cout << "1 - To show only direct flights" << endl;
				cout << "0 - to show connection flight and direct flight " << endl;
				cout << "Choose Option: ";
				only_direct = input_num();
				direct_filter = true;

				break;
			case 4:
				break;
			default:
				cout << "ERROR input! please insert again a number between 1-4" << endl;
				break;
			}
		} while (filter_choice != 4);

	}

	Flights* flight_arr = read_from_flights_DB(); //Copies all flights from the database to the flight array
	int size = 0; //The size for new flights array
	Flights* matching_flight = NULL; //new array for the relevant flights of the customer's choice
	for (int i = 0; i < size_flights_DB(); i++)
	{
		if (flight_arr[i].m_quantity > 0 && flight_arr[i].m_departure_location == departure_location && flight_arr[i].m_arrival_location == arrival_location && flight_arr[i].m_departure_date == departure_date && flight_arr[i].m_one_way == one_way)
		{
			if (!one_way)
			{
				if (flight_arr[i].m_return_date == return_date)
				{
					if (filter)
					{
						//If the customer inserted three filters
						if (price_filter && class_filter && direct_filter)
						{
							if (flight_arr[i].m_price <= price && flight_arr[i].m_class_f == class_f && flight_arr[i].m_direct == true)
							{
								size++;
								matching_flight = Increasing_farr_by_one(matching_flight, flight_arr[i], size);

							}
						}
						//If the customer inserted two filters
						else if (price_filter && class_filter)
						{
							if (flight_arr[i].m_price <= price && flight_arr[i].m_class_f == class_f)
							{
								{
									size++;
									matching_flight = Increasing_farr_by_one(matching_flight, flight_arr[i], size);

								}
							}
						}
						else if (price_filter && direct_filter)
						{
							if (flight_arr[i].m_price <= price && flight_arr[i].m_direct == true)
							{
								size++;
								matching_flight = Increasing_farr_by_one(matching_flight, flight_arr[i], size);

							}
						}
						else if (class_filter && direct_filter)
						{
							if (flight_arr[i].m_class_f == class_f && flight_arr[i].m_direct == true)
							{
								{
									size++;
									matching_flight = Increasing_farr_by_one(matching_flight, flight_arr[i], size);

								}
							}
						}
						//If the customer inserted one filter
						else if (price_filter)
						{
							if (flight_arr[i].m_price <= price)//If the flight is at a price lower  or equal than the maximum price the customer entered
							{
								size++;
								matching_flight = Increasing_farr_by_one(matching_flight, flight_arr[i], size);

							}
						}
						else if (class_filter)
						{
							if (flight_arr[i].m_class_f == class_f)
							{
								size++;
								matching_flight = Increasing_farr_by_one(matching_flight, flight_arr[i], size);

							}
						}
						else if (direct_filter)
						{
							if (flight_arr[i].m_direct == true)
							{
								size++;
								matching_flight = Increasing_farr_by_one(matching_flight, flight_arr[i], size);

							}
						}


					}

					//The customer chooses round-trip flights without filters
					else
					{
						size++;
						matching_flight = Increasing_farr_by_one(matching_flight, flight_arr[i], size);

					}
				}

			}//The customer chooses one-way flights without filters
			else
			{
				size++;
				matching_flight = Increasing_farr_by_one(matching_flight, flight_arr[i], size);

			}
		}
	}
	if (size == 0)
	{
		cout << "There are no matching flights" << endl;
	}
	else if (size != 0)
	{
		for (int i = 0; i < size; i++)//Prints the relevant flights to the customer
		{
			cout << i + 1 << ". ";
			print_match_flights(matching_flight[i]);
			cout << endl;
		}
		int choice;
		do
		{
			cout << "1 - Select a flight" << endl;
			cout << "2 - return to search Hotel" << endl;
			cout << "Choose Option: ";
			choice = input_num();

			switch (choice)
			{
			case 1:
			{
				cout << "Which flight do you want to choose ? " << endl;
				cin >> user_selection;
				make_reservation(matching_flight[user_selection - 1].m_flight_id, "Flight");//Sends the selected flight to booking
				break;
			}
			case 2:
			{
			}
			break;

			break;
			default:
				cout << "ERROR input! please insert again 1 or 2" << endl;
				break;
			}
		} while (choice != 2);

	}

}
void hotels()
{
	string hotel_location, hotel_name;
	Date check_in, check_out;
	int raiting, number_of_guest, user_selection;
	float price;
	bool filter;
	bool room_type; // true if suit ,false standart room.
	bool price_filter = false; //True - If the customer chooses to filter results by price.
	bool raiting_filter = false; //True - If the customer chooses to filter results by class.
	bool roomType_filter = false; //True - If the customer chooses to filter results by flight type.
	int answer;
	Hotels* hotels_arr = read_from_hotels_DB(); //Copies all the hotels from the database to the hotel array 
	int size = 0; //The size for new hotel array
	Hotels* matching_hotels = NULL; //new array for the relevant flights of the customer's choice
	do
	{

		cout << endl;
		cout << " ===========SEARCH HOTEL============" << endl << endl;
		cout << "How would you like to search a hotel? By hotel name or by date and location" << endl;
		cout << "1 - To search by name " << endl;
		cout << "2 - To Search by location and date " << endl;
		cout << "3 - To return to Home page  " << endl;
		cout << " ==================================" << endl << endl;
		cout << "Choose Option: ";
		answer = input_num();

		switch (answer)
		{
		case 1:
		{   //search hotels by name
			cout << "Enter the name of the Hotel: ";
			hotel_name = input_name();
			cout << endl;
			for (int i = 0; i < size_hotels_DB(); i++)
			{
				if (hotels_arr[i].m_quantity > 0 && hotels_arr[i].m_hotel_name == hotel_name)
				{

					size++;
					matching_hotels = Increasing_harr_by_one(matching_hotels, hotels_arr[i], size);
				}
			}

		}
		break;
		case 2:
		{    //search hotel by details
			cout << endl;
			cout << "Date: " << endl;
			cout << "Check in: " << endl;
			cin >> check_in;
			while (today_date() > check_in && !(today_date() == check_in))
			{
				cout << "The date must be equal or later than the date " << today_date() << endl;
				cin >> check_in;
			}
			cout << "Check out: " << endl;
			cin >> check_out;
			while (!check_dates(check_in, check_out))
			{
				cout << "invalid date. enter again(DD/MM/YYYY):" << endl;
				cin >> check_out;
			}

			cout << "Location: ";
			hotel_location = input_location();
			cout << "Number of Guest: ";
			number_of_guest = input_num();
			cout << "Do you want to filter the results?" << endl;
			cout << "1 - YES" << endl;
			cout << "0 - NO " << endl;
			cout << "Choose Option: ";
			filter = input_num();
			if (filter)
			{
				int filter_choice;

				do
				{
					cout << "1.Filter results by price\n2.Filter results by Raiting\n3.Filter results by Room Type\n4.Back to search Hotel\n " << endl;
					filter_choice = input_num();
					switch (filter_choice)
					{
					case 1:
						cout << "Maximum price: ";
						price = input_price();
						price_filter = true;
						break;
					case 2:
						cout << "Minimum rating: ";
						raiting = input_num();
						raiting_filter = true;
						break;
					case 3:

						cout << "1 - for Suite " << endl;
						cout << "0 - for a Standard Room" << endl;
						cout << "Choose Option: ";
						room_type = input_num();
						roomType_filter = true;

						break;
					case 4:
						break;
					default:
						cout << "ERROR input! please insert again a number between 1-4" << endl;
						break;
					}
				} while (filter_choice != 4);
			}
			//Search for the right hotel according to the customer's choices
			for (int i = 0; i < size_hotels_DB(); i++)
			{
				if (hotels_arr[i].m_hotel_location == hotel_location && hotels_arr[i].m_check_in == check_in && hotels_arr[i].m_check_out == check_out && hotels_arr[i].m_guest >= number_of_guest)
				{
					if (filter)
					{
						//If the customer inserted three filters
						if (price_filter && raiting_filter && roomType_filter)
						{
							if (hotels_arr[i].m_price <= price && hotels_arr[i].m_rating == raiting && hotels_arr[i].m_room_type == room_type)
							{
								size++;
								matching_hotels = Increasing_harr_by_one(matching_hotels, hotels_arr[i], size);
							}
						}
						//If the customer inserted two filters
						else if (price_filter && roomType_filter)
						{
							if (hotels_arr[i].m_price <= price && hotels_arr[i].m_room_type == room_type)
							{
								{
									size++;
									matching_hotels = Increasing_harr_by_one(matching_hotels, hotels_arr[i], size);
								}
							}
						}
						else if (price_filter && raiting_filter)
						{
							if (hotels_arr[i].m_price <= price && hotels_arr[i].m_rating >= raiting)
							{
								size++;
								matching_hotels = Increasing_harr_by_one(matching_hotels, hotels_arr[i], size);
							}
						}
						else if (raiting_filter && roomType_filter)
						{
							if (hotels_arr[i].m_rating >= raiting && hotels_arr[i].m_room_type == room_type)
							{
								{
									size++;
									matching_hotels = Increasing_harr_by_one(matching_hotels, hotels_arr[i], size);
								}
							}
						}
						//If the customer inserted one filter
						else if (price_filter)
						{
							if (hotels_arr[i].m_price <= price)//If the hotels with a price lower  or equal than the maximum price the customer entered
							{
								size++;
								matching_hotels = Increasing_harr_by_one(matching_hotels, hotels_arr[i], size);
							}
						}
						else if (raiting_filter)
						{
							if (hotels_arr[i].m_rating >= raiting)
							{
								size++;
								matching_hotels = Increasing_harr_by_one(matching_hotels, hotels_arr[i], size);
							}
						}
						else if (roomType_filter)
						{
							if (hotels_arr[i].m_room_type == room_type)
							{
								size++;
								matching_hotels = Increasing_harr_by_one(matching_hotels, hotels_arr[i], size);
							}
						}


					}


					else
					{
						size++;
						matching_hotels = Increasing_harr_by_one(matching_hotels, hotels_arr[i], size);
					}


				}
			}
		}

		break;
		case 3:
			break;
		default:
			break;
		}

		if (answer != 3)
		{
			if (size == 0)
			{
				cout << "There are no matching hotels" << endl;
			}
			else
			{
				for (int i = 0; i < size; i++)//Prints the relevant hotels to the customer
				{
					cout << endl;
					cout << i + 1 << ". ";
					print_match_hotels(matching_hotels[i]);
					cout << endl;

					int choice;
					do
					{
						cout << "1 - Select a hotel" << endl;
						cout << "2 - return to search Hotel" << endl;
						cout << "Choose Option: ";
						choice = input_num();
						switch (choice)
						{
						case 1:
						{
							cout << "Which hotel do you want to choose ?  ";
							user_selection = input_num();
							make_reservation(matching_hotels[user_selection - 1].m_hotel_id, "Hotel");//Sends the selected hotel to booking
							break;
						}
						case 2:

							break;

							break;
						default:
							cout << "ERROR input! please insert again 1 or 2" << endl;
							break;
						}

					} while (choice != 2);
				}
			}
		}
	} while (answer != 3);
}
void packages(Packages* p)
{
	//v filters v
	int price_top = 0, price_bot = 0;
	Date arrive, bye, blank;
	string loc = "0", dep_loc;
	int ppl;
	bool org, flag = false;
	//^ filters ^
	string* arr = new string[size_packages_DB()];//displayed packages id save
	string* dests = new string[size_packages_DB()];
	int dest_count = 0, count = 0;//displayed packages counter
	string choise;//user's choise veraible
	int num;//string to int covertion veriable
	//	Packages *p = read_from_packages_DB();
	for (int i = 0; i < size_packages_DB(); i++)//check which destinations are available and prints them
	{
		for (int j = 0; j < size_packages_DB(); j++)
		{
			if (iequals(p[i].m_destinion, dests[j]))
			{
				flag = true;
			}
		}
		if (flag == false)
		{
			dest_count++;
			cout << dest_count << "->" << p[i].m_destinion << endl;
			dests[dest_count] = p[i].m_destinion;
		}
	}
	cout << "choose a destination from the list:";
	cin >> choise;
	std::istringstream(choise) >> num;
	loc = dests[num];
	for (int i = 0; i < size_packages_DB(); i++)//prints the packages based on user's choise
	{
		if (iequals(dests[num], p[i].m_destinion))
		{
			arr[count] = p[i].m_package_id;
			count++;
			cout << "\n";
			cout << "==========(" << count << ")=========" << endl;
			cout << "\n";
			print_package(p[i]);
		}
	}
	cout << "\n";
	flag = false;
	while (!flag)
	{
		cout << "======================================" << endl << endl;
		cout << " #- Proceed to reservation of chosen package" << endl;
		cout << " F- Filter the package list." << endl;
		cout << " M- Back to search menu" << endl;
		cout << "Your Choise:"; cin >> choise;
		std::istringstream(choise) >> num;
		if (iequals(choise, "F"))//filter manegment
		{
			count = 0;
			cout << "\n----------------------------------------------------\n";
			cout << "TO IGNORE A FILTER PRESS 0 (0 0 0 for dates)" << endl << endl;
			cout << "Enter a date of departure:";
			arrive = input_date(); cout << endl;
			cout << "Enter a date of arrival:";
			bye = input_date(); cout << endl;
			while (!(bye > arrive))
			{
				//cout << "Enter a date of arrival(or 0 0 0):"<<endl;
				if (!(bye > arrive))cout << "invalid date range.enter again:";
				bye = input_date(); cout << endl;
			}
			cout << "Enter a departure location:";
			dep_loc = input_location(); cout << endl;
			cout << "Enter a price range:\nFrom:";
			price_bot = input_price();
			cout << "To:";
			price_top = input_price();
			while (price_bot > price_top)
			{
				if (price_top < price_bot)cout << "invalid price range.enter again:" << endl;
				price_top = input_price();
			}
			cout << endl;
			cout << "Enter number of people:";
			ppl = input_num();
			cout << "Enter 2 For orgenized tours or 1 for not orgenized tours:";
			org = input_num(); cout << endl;
			for (int i = 0; i < size_packages_DB(); i++)
			{
				if (iequals(loc, p[i].m_destinion))
				{
					if (arrive == p[i].m_start || arrive == blank)
					{
						if (bye == p[i].m_end || bye == blank)
						{
							if (dep_loc == p[i].m_origin || dep_loc == "0")
							{
								if (price_bot <= p[i].m_price || price_bot == 0)
								{
									if (price_top >= p[i].m_price || price_top == 0)
									{
										if (ppl = p[i].m_num_of_travelers || ppl == 0)
										{
											if (org - 1 == p[i].m_organized_trip || org == 0)
											{
												arr[count] = p[i].m_package_id;
												count++;
												cout << "\n";
												cout << "==========(" << count << ")=========" << endl;
												cout << "\n";
												print_package(p[i]);
											}
										}
									}
								}
							}
						}
					}
				}
			}
			if (count == 0)
			{
				cout << "\n";
				cout << "=============================" << endl;
				cout << "|       NO MATCH PACKAGE     |" << endl;
			}
			/*else
			{
				cout << "Choose a package.if u wish to change the filter F. to go back to menu press M" << endl;
				cin >> choise;
			}*/
		}
		cout << "=============================" << endl;
		std::istringstream(choise) >> num;
		if (num > 0 && num <= count)
		{
			flag = true;
		}
		else
		{
			while (!iequals(choise, "m") && num > 0 && num <= count + 1 || !iequals(choise, "f") && num > 0 && num <= count + 1)
			{
				cout << "could not find package in the list." << endl;
				cout << "choose a destination from the list or if u wish to filter the results press F." << endl;
				cout << "to go back to menu press M" << endl;
				cin >> choise;
				std::istringstream(choise) >> num;
			}

			if (iequals(choise, "m"))
			{
				flag = true;
			}
		}

	}
	std::istringstream(choise) >> num;
	if (num > 0 && num <= count + 1 || !iequals(choise, "m"))
	{
		make_reservation(arr[count - 1], "Packages");
	}

}

//Filter

bool iequals(const string& a, const string& b)
{
	unsigned int sz = a.size();
	if (b.size() != sz)
		return false;
	for (unsigned int i = 0; i < sz; ++i)
		if (tolower(a[i]) != tolower(b[i]))
			return false;
	return true;
}
Date input_date()
{
	Date date;
	int d, m, y;
	bool flag = false;
	/*cin >> d;
	cin >> m;
	cin >> y;*/
	cin >> date;
	while (!flag)
	{
		if (cin.fail())
		{
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(INT_MAX, '\n'); // ignore last input
			cout << endl;
			cout << "Invalid Date: " << endl;
			cout << "Try Again: ";
			cin >> date;
			/*cout << "day:"; cin >> d;
			cout << "month:"; cin >> m;
			cout << "year:"; cin >> y;*/
		}
		else
		{
			flag = true;
		}
	}
	return date;
}
Date today_date()//Returns the date of the day
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	Date today_date;
	today_date.m_day = ltm->tm_mday;
	today_date.m_month = 1 + ltm->tm_mon;
	today_date.m_year = 1900 + ltm->tm_year;
	return today_date;
}
int input_price()
{
	int p;
	bool flag = false;
	cin >> p;
	while (!flag)
	{
		if (p < 0 || p>100000 || cin.fail())
		{
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(INT_MAX, '\n'); // ignore last input
			cout << endl;
			cout << "Invalid Price: " << endl;
			cout << "Try Again : ";
			cin >> p;
		}
		else
		{
			flag = true;
		}
	}
	return p;
}
string input_location()
{
	string p;
	bool flag = false;
	cin >> p;
	while (!flag)
	{
		if (p.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0") != std::string::npos)// || cin.fail())
		{
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(INT_MAX, '\n'); // ignore last input
			cout << endl;
			cout << "Invalid Location:  " << endl;
			cout << "Try Again: ";
			cin >> p;
		}
		else
		{
			flag = true;
		}
	}
	return p;
}
string input_name()
{
	string p;
	bool flag = false;
	cin >> p;
	while (!flag)
	{
		if (p.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos)// || cin.fail())
		{
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(INT_MAX, '\n'); // ignore last input
			cout << endl;
			cout << "Name: " << endl;
			cout << "Try Again : ";
			cin >> p;
		}
		else
		{
			flag = true;
		}
	}
	return p;
}
int input_num()
{
	int p;
	bool flag = false;
	cin >> p;
	while (!flag)
	{
		if (cin.fail())
		{
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(INT_MAX, '\n'); // ignore last input
			cout << endl;
			cout << "Enter a Number please " << endl;
			cout << "Try Again : ";
			cin >> p;
		}
		else
		{
			flag = true;
		}
	}
	return p;
}
char class_input()
{
	char ch;
	do
	{
		cin >> ch;
		if (ch == 'e')
			ch = 'E';
		else if (ch == 'b')
			ch = 'B';
		else
			cout << "ERROR input ! please insert again The char 'B' for Business class or 'E' for Economy class " << endl;
	} while (ch != 'E' && ch != 'B');

	return ch;
}
bool check_dates(Date first, Date second)
// functiom that check if the second date id layter from the first date.
{
	if (first.m_year > second.m_year)
		return false;
	else if (first.m_year == second.m_year)
	{
		if (first.m_month > second.m_month)
			return false;
		else if (first.m_month == second.m_month)
		{
			if (first.m_day > second.m_day)
				return false;

		}
	}
	return true;
}

//Print Function

void print_match_flights(Flights match_flight)
{
	cout << "Flight Details: " << endl;
	cout << "Departure: " << match_flight.m_departure_location << endl;
	cout << "Destination: " << match_flight.m_arrival_location << endl;
	cout << "Departure Date:  " << match_flight.m_departure_date;
	if (!match_flight.m_one_way)
		cout << "Return Date: " << match_flight.m_return_date;
	if (match_flight.m_class_f == 'E')
		cout << "Class Type: Economy" << endl;
	else if (match_flight.m_class_f == 'B')
		cout << "Class Type: Business " << endl;
	if (match_flight.m_direct)
		cout << "Direct Flight" << endl;
	else if (!match_flight.m_direct)
		cout << "Conection Flight" << endl;
	cout << "Price: " << match_flight.m_price << "$" << endl;
	cout << "****************************************************************" << endl;
	cout << "Description: " << match_flight.m_description << endl << endl;
	cout << "****************************************************************" << endl;
}
void print_match_hotels(Hotels match_hotel)
{
	cout << "Hotel Details: " << endl;
	cout << "Hotel Name: " << match_hotel.m_hotel_name << endl;
	cout << "Location: " << match_hotel.m_hotel_location << endl;
	cout << "Check in Date:  " << match_hotel.m_check_in;
	cout << "Check out Date: " << match_hotel.m_check_out;
	cout << "Raiting: " << match_hotel.m_rating << endl;
	cout << "Maximum number of guests :" << match_hotel.m_guest << endl;
	if (match_hotel.m_room_type)
		cout << "Room Type: suite" << endl;
	else
		cout << "Room Type: Standard room " << endl;
	cout << "Price: " << match_hotel.m_price << "$" << endl;
	cout << "****************************************************************************************************" << endl;
	cout << "Description: " << match_hotel.m_description << endl << endl;
	cout << "****************************************************************************************************" << endl;
}


Flights* Increasing_farr_by_one(Flights* matching_flight, Flights flight, int size)
{

	if (matching_flight != NULL)
	{
		Flights* tmp = new Flights[size];
		for (int i = 0; i < size - 1; i++)
			tmp[i] = matching_flight[i];
		tmp[size - 1] = flight;
		delete[] matching_flight;
		matching_flight = tmp;

	}
	else
	{
		matching_flight = new Flights[1];
		matching_flight[0] = flight;
	}

	return matching_flight;
}
Hotels* Increasing_harr_by_one(Hotels* matching_hotels, Hotels hotel, int size)
{
	if (matching_hotels != NULL)
	{
		Hotels* tmp = new Hotels[size];
		for (int i = 0; i < size - 1; i++)
			tmp[i] = matching_hotels[i];
		tmp[size - 1] = hotel;
		delete[] matching_hotels;
		matching_hotels = tmp;

	}
	else
	{
		matching_hotels = new Hotels[1];
		matching_hotels[0] = hotel;
	}

	return matching_hotels;
}

////////////////////////////////////////////////////////////MANAGER///////////////////////////////////////////////////////////////////////

// Log in For manager

void manager_login()
{
	long id;
	string password;
	cout << endl;
	cout << "==========MANAGER LOG IN===============" << endl;
	cout << "ID: ";
	cin >> id;
	cout << "Your company code:";
	cin >> password;
	int choice = 0;
	while (id != ManagerID || password != ManagerCompanyCode)
	{
		cout << "ID or Password Incorrect" << endl;
		cout << "1- Try Again" << endl;
		cout << "2 - Return to Home Page";
		cout << "Choose option: ";
		cin >> choice;
		switch (choice)
		{
		case 1:

			cout << "ID: ";
			cin >> id;
			cout << "Your company code: " << endl;
			cin >> password;
			break;

		case 2:
			return;

		default:

			cout << "Wrong Input" << endl;
			break;
		}

	}

	manager_menu();
}

// Menu
void manager_menu() {
	int choice = 0;
	while (choice != 4) {
		cout << endl;
		cout << "===============MANAGER MENU=================" << endl;
		cout << "1- Add new agent to the agency" << endl;
		cout << "2- Statistics menu" << endl;
		cout << "3- View agent DB" << endl;
		cout << "4- Return to home page" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			add_new_agent(read_from_agent_DB(), size_agent_DB());
			break;
		case 2:
			statistics_menu();
			break;
		case 3:
			view_agent_DB();
			break;
		case 4:
			return;
			break;
		default:
			cout << "Worng choice please choice again" << endl;
			break;
		}
	}
}

// Print Function

void view_agent_DB() {
	Agent* arr = read_from_agent_DB();
	int size = size_agent_DB();
	for (int i = 0; i < size; i++)
	{
		cout << "Agent Id: " << arr[i].m_id << " " << "Agent Name: " << arr[i].m_first_name << " " << arr[i].m_last_name << " " << "Agent Erea: " << arr[i].m_area << " " << "Agent sales: " << arr[i].m_sales << endl;
	}
}

//Check

bool agent_is_exist(long id, int size)
{
	Agent* arr = new Agent[size];
	for (int i = 0; i < size; i++)
		arr[i] = read_from_agent_DB()[i];
	for (int i = 0; i < size; i++)
	{
		if (arr[i].m_id == id)
			return true;
	}
	return false;
}

// Statistic option

void statistics_menu() {
	//statistics related to the agency
	int choice = 0;
	while (choice != 4) {
		cout << endl;
		cout << "=============STATISTICS MENU===============" << endl;
		cout << "1- Financial reports" << endl;
		cout << "2- Packages sales" << endl;
		cout << "3- Tracking sales agent" << endl;
		cout << "4- Return to manager menu" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			report();//revenu report of agency
			break;
		case 2:
			most_packages_sales();//manager can choose view the most saeles package by type
			break;
		case 3:
			tracking_sales_agent();//
			break;
		case 4:
			return;
			break;
		default:
			cout << "Worng choice please choice again" << endl;
			break;
		}
	}
}
void report() {
	//financial report of agency
	int choice = 0;
	while (choice != 2)
	{
		cout << endl;
		cout << "=========REPORT MENU===========" << endl;
		cout << "1.View Year Revenue" << endl;
		cout << "2.Return to Statistics Menu" << endl;
		cout << "==============================" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Year Revenue of Vacation4U: " << revenu_of_agency() << "$" << endl;
			break;
		case 2:
			return;
			break;
		default:
			cout << "Wrong choice please choice again" << endl;
			break;
		}

	}

}
void most_packages_sales() {
	int choice = 0;
	Packages best_package = best_sale_package();
	Hotels best_hotel = best_sale_hotel();
	Flights best_flight = best_sale_flight();
	while (choice != 4)
	{
		cout << endl;
		cout << "========BEST SELLERS==========" << endl;
		cout << "Most packages sales by:" << endl;
		cout << "1- Package" << endl;
		cout << "2- Hotel" << endl;
		cout << "3- Flight" << endl;
		cout << "4.Return to statistics menu" << endl;
		cout << "==============================" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << endl;
			cout << "=========PACKAGE==========" << endl;
			cout << "Id:" << best_package.m_package_id << endl;
			cout << "Origin:" << best_package.m_origin << endl;
			cout << "Destinion:" << best_package.m_destinion << endl;
			cout << "Price:" << best_package.m_price << endl;
			cout << "Sales:" << best_package.m_sales_counter << endl;

			break;
		case 2:
			cout << endl;
			cout << "==========HOTEL===========" << endl;
			cout << "Id:" << best_hotel.m_hotel_id << endl;
			cout << "Location:" << best_hotel.m_hotel_location << endl;
			cout << "Rating:" << best_hotel.m_rating << endl;
			cout << "Price:" << best_hotel.m_price << endl;
			cout << "Sales:" << best_hotel.m_sales_counter << endl;
			break;
		case 3:
			cout << endl;
			cout << "=========FLIGHT===========" << endl;
			cout << "Id:" << best_flight.m_flight_id << endl;
			cout << "Departure Location:" << best_flight.m_departure_location << endl;
			cout << "Arrival Location:" << best_flight.m_arrival_location << endl;
			cout << "Price:" << best_flight.m_price << endl;
			cout << "Sales:" << best_flight.m_sales_counter << endl;
			break;
		case 4:
			return;
			break;


		default:
			cout << "Wrong choice please try again" << endl;
			break;
		}

	}

}
void tracking_sales_agent()//print the agent with most sales in agency 
{
	Agent* arr = read_from_agent_DB();
	Agent most_lucrative_agent = arr[0];
	for (int i = 0; i < size_agent_DB(); i++)//run on DB and checking which agent has the most sales
	{
		if (arr[i].m_sales > most_lucrative_agent.m_sales)
			most_lucrative_agent = arr[i];
	}
	//print the info of agent
	cout << "Best Agent: " << most_lucrative_agent.m_first_name << " " << most_lucrative_agent.m_last_name << " " << "his sales quantity is: " << most_lucrative_agent.m_sales << endl;

}
Packages best_sale_package()
{
	//find the best-selling package
	int size = size_packages_DB();
	Packages* new_parr = read_from_packages_DB();
	Packages best_sale_package = new_parr[0]; //my assumption is that the first one is best selling
	for (int i = 0; i < size; i++)//run on package DB and checking who's the best-selling package
	{
		if (new_parr[i].m_sales_counter > best_sale_package.m_sales_counter) {
			best_sale_package = new_parr[i];

		}
	}
	return best_sale_package;
}
Hotels best_sale_hotel()
{
	//find the best-selling hotel
	int size = size_packages_DB();
	Hotels* new_parr = read_from_hotels_DB();
	Hotels best_sale_hotel = new_parr[0];//my assumption is that the first one is best selling
	for (int i = 0; i < size; i++)//run on package DB and checking who's the best-selling hotel
	{
		if (new_parr[i].m_sales_counter > best_sale_hotel.m_sales_counter) {
			best_sale_hotel = new_parr[i];

		}
	}
	return best_sale_hotel;

}
Flights best_sale_flight()
{
	//find the best-selling flight
	int size = size_flights_DB();
	Flights* new_parr = read_from_flights_DB();
	Flights best_sale_flight = new_parr[0];//my assumption is that the first one is best selling
	for (int i = 0; i < size; i++)//run on package DB and checking who's the best-selling flight
	{
		if (new_parr[i].m_sales_counter > best_sale_flight.m_sales_counter) {
			best_sale_flight = new_parr[i];

		}
	}
	return best_sale_flight;
}
long long revenu_of_agency() {
	//calculating the revenue of the agency over the past year
	long long total_agent_salery = size_agent_DB() * AgentSalary, total_sales_agency = 0, total_packages_sales = 0, total_hotel_sales = 0, total_flight_sales = 0, revenue_of_agency;
	Packages* p_arr = read_from_packages_DB();
	Hotels* h_arr = read_from_hotels_DB();
	Flights* f_arr = read_from_flights_DB();
	int p_arr_size = size_packages_DB(), h_arr_size = size_hotels_DB(), f_arr_size = size_flights_DB();
	for (int i = 0; i < p_arr_size; i++)//calculating total revenu ftom packages sales
	{
		total_packages_sales += (p_arr[i].m_price * p_arr[i].m_sales_counter);
	}
	for (int i = 0; i < h_arr_size; i++)//calculating total revenu ftom hotels sales
	{
		total_hotel_sales += (h_arr[i].m_price * h_arr[i].m_sales_counter);
	}
	for (int i = 0; i < f_arr_size; i++)//calculating total revenu ftom flights sales
	{
		total_flight_sales += (f_arr[i].m_price * f_arr[i].m_sales_counter);
	}
	total_sales_agency = total_packages_sales + total_hotel_sales + total_flight_sales;
	revenue_of_agency = total_sales_agency - total_agent_salery;
	return revenue_of_agency;


}

// Add


void add_new_agent(Agent* arr, int size)
{

	Agent new_agent = make_agent();
	int new_size = size + 1;
	arr = new Agent[new_size];
	if (size == 0)
	{
		arr[0] = new_agent;
		write_to_agent_DB(arr, new_size);
	}
	else
	{

		for (int i = 0; i < new_size; i++)
			arr[i] = read_from_agent_DB()[i];
		arr[new_size - 1] = new_agent;
		write_to_agent_DB(arr, new_size);
	}
	cout << "Agent successfully added" << endl;
	manager_menu();

}
Agent make_agent()
{
	Agent a;
	int  size = size_agent_DB();
	cout << "Enter Agent Details" << endl;
	cout << "ID: ";
	a.m_id = input_id();
	while (agent_is_exist(a.m_id, size))//cheak if agent id exist in DB
	{
		cout << "ID already in Agent DB " << endl;
		a.m_id = input_id();
	}
	cout << "First Name: ";
	a.m_first_name = input_name();
	cout << "Last Name: ";
	a.m_last_name = input_name();
	cout << "Enter Area: ";
	a.m_area = input_area();
	a.m_sales = 0;
	return a;
}
string input_area()
{
	string p;

	cin >> p;
	while (p != "EU" && p != "US" && p != "AU" && p != "AN" && p != "AS" && p != "AF")
	{
		cout << endl << "Enter Area: " << endl;;
		cout << "EU (Europe) \nUS- (United Satetes)\nAU- (Australia)\nAN- (Antarctica)\nAS- (Asia)\nAF- (Africa)\n";
		cout << "invalid Area, enter again:" << endl;
		cout << "Area:"; cin >> p;
	}
	return p;
}

// Requirement for details 


long input_id()
{
	long p;
	bool flag = false;
	cin >> p;
	while (!flag)
	{
		if (p < 100000000 || p>999999999 || cin.fail())
		{
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(INT_MAX, '\n'); // ignore last input
			cout << endl;
			cout << "invalid ID must constain 9 numbers:" << endl;
			cout << "ID: "; cin >> p;
		}
		else
		{
			flag = true;
		}
	}
	return p;
}

//////////////////////////////////////////////////////////////DATABASE////////////////////////////////////////////////////////////////////

//Functions Database Size

int size_packages_DB()
{
	int size = 0;

	ifstream obj("Packages.txt");
	if (!obj)
		cerr << "Error opening file ";
	else
	{
		obj >> size;

		obj.close();
	}

	return size;

}
int size_agent_DB()
{
	int size = 0;

	ifstream obj("Agent.txt");
	if (!obj)
		cerr << "Error opening file ";
	else
	{
		obj >> size;

		obj.close();
	}

	return size;

}
int size_flights_DB()
{
	int size = 0;
	ifstream obj("Flights.txt");
	if (!obj)
		cerr << "Error opening file ";
	else
	{
		obj >> size;
		obj.close();
	}
	return size;
}
int size_hotels_DB()
{
	int size = 0;
	ifstream obj("Hotels.txt");
	if (!obj)
		cerr << "Error opening file ";
	else
	{
		obj >> size;
		obj.close();
	}
	return size;
}
int size_customer_DB()
{
	int size = 0;
	ifstream obj("Customer.txt");
	if (!obj)
		cerr << "Error opening file ";
	else
	{
		obj >> size;
		obj.close();
	}
	return size;
}
int size_orders_DB()
{
	int size = 0;
	ifstream obj("Orders.txt");
	if (!obj)
		cerr << "Error opening file ";
	else
	{
		obj >> size;
		obj.close();
	}
	return size;
}
int size_messages_DB()
{
	int size = 0;
	ifstream obj("Messages.txt");
	if (!obj)
		cerr << "Error opening file ";
	else
	{
		obj >> size;
		obj.close();
	}
	return size;
}

//Functions reading  from database

Flights* read_from_flights_DB()
{
	int size;
	ifstream obj("Flights.txt");
	if (!obj)
	{
		cout << "Error opening file";
	}
	obj >> size;
	Flights* arr = new Flights[size];//יצירת מערך בגודל המאגר
	if (size != 0)
	{
		for (int i = 0; i < size; i++)//העתקה מהמאגר למערך
		{
			obj >> arr[i].m_flight_id;
			obj >> arr[i].m_departure_location;
			obj >> arr[i].m_arrival_location;
			obj >> arr[i].m_departure_date.m_day >> arr[i].m_departure_date.m_month >> arr[i].m_departure_date.m_year;
			obj >> arr[i].m_return_date.m_day >> arr[i].m_return_date.m_month >> arr[i].m_return_date.m_year;
			obj >> arr[i].m_price;
			obj >> arr[i].m_area;
			obj >> arr[i].m_class_f;
			obj >> arr[i].m_quantity;
			obj >> arr[i].m_direct;
			obj >> arr[i].m_one_way;
			obj >> arr[i].m_sales_counter;
			obj >> arr[i].m_agent_id;
			obj.ignore();
			getline(obj, arr[i].m_description);
		}
	}

	obj.close();
	return arr;
}
Hotels* read_from_hotels_DB()
{
	int size;
	ifstream obj("Hotels.txt");
	if (!obj)
	{
		cout << "Error opening file";
	}
	obj >> size;
	Hotels* arr = new Hotels[size];//יצירת מערך בגודל המאגר
	if (size != 0)
	{
		for (int i = 0; i < size; i++)//העתקה מהמאגר למערך
		{
			obj >> arr[i].m_hotel_id;
			obj >> arr[i].m_hotel_name;
			obj >> arr[i].m_hotel_location;
			obj >> arr[i].m_check_in.m_day >> arr[i].m_check_in.m_month >> arr[i].m_check_in.m_year;
			obj >> arr[i].m_check_out.m_day >> arr[i].m_check_out.m_month >> arr[i].m_check_out.m_year;
			obj >> arr[i].m_guest;
			obj >> arr[i].m_room_type;
			obj >> arr[i].m_rating;
			obj >> arr[i].m_price;
			obj >> arr[i].m_quantity;
			obj >> arr[i].m_sales_counter;
			obj >> arr[i].m_agent_id;
			obj >> arr[i].m_area;
			obj.ignore();
			getline(obj, arr[i].m_description);
		}
	}

	obj.close();
	return arr;
}
Packages* read_from_packages_DB()
{
	int size;
	ifstream obj("Packages.txt");
	if (!obj)
	{
		cout << "Error opening file";
	}
	obj >> size;
	Packages* arr = new Packages[size];//יצירת מערך בגודל המאגר
	if (size != 0)
	{
		for (int i = 0; i < size; i++)//העתקה מהמאגר למערך
		{
			obj >> arr[i].m_package_id;
			obj >> arr[i].m_start.m_day >> arr[i].m_start.m_month >> arr[i].m_start.m_year;
			obj >> arr[i].m_end.m_day >> arr[i].m_end.m_month >> arr[i].m_end.m_year;
			obj >> arr[i].m_price >> arr[i].m_area;
			obj >> arr[i].m_origin >> arr[i].m_destinion >> arr[i].m_num_of_travelers;
			obj >> arr[i].m_quantity >> arr[i].m_sales_counter >> arr[i].m_agent_id;
			obj >> arr[i].m_points >> arr[i].m_organized_trip;
			getline(obj, arr[i].m_description);
		}



	}
	obj.close();

	return arr;
}
Agent* read_from_agent_DB()
{
	int size;
	ifstream obj("Agent.txt");
	// check that the file opening was successful.
	if (!obj)
	{
		cout << "Error opening file";
	}
	obj >> size;
	// create an array the size of the DB.
	Agent* arr = new Agent[size];
	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			obj >> arr[i].m_id;
			obj >> arr[i].m_first_name;
			obj >> arr[i].m_last_name;
			obj >> arr[i].m_area;
			obj >> arr[i].m_sales;
		}
	}
	obj.close();
	return arr;

}
Orders* read_from_orders_DB()
{
	int size;
	ifstream obj("Orders.txt");
	if (!obj)
	{
		cout << "Error opening file";
	}
	obj >> size;
	Orders* arr = new Orders[size];//יצירת מערך בגודל המאגר
	if (size != 0)
	{
		for (int i = 0; i < size; i++)//העתקה מהמאגר למערך
		{
			obj >> arr[i].m_package_id;
			obj >> arr[i].m_customer_id;
			obj >> arr[i].m_friends;
			obj.ignore();
			getline(obj, arr[i].m_status);
		}
	}

	obj.close();
	return arr;
}
Customer* read_from_customer_DB()
{
	int size;
	ifstream obj("Customer.txt");
	if (!obj)
	{
		cout << "Error opening file";
	}
	obj >> size;
	Customer* arr = new Customer[size];//יצירת מערך בגודל המאגר
	if (size != 0)
	{
		for (int i = 0; i < size; i++)//העתקה מהמאגר למערך
		{
			obj >> arr[i].m_id;
			obj >> arr[i].m_first_name;
			obj >> arr[i].m_last_name;
			obj >> arr[i].m_password;
			obj >> arr[i].m_email;
			obj >> arr[i].m_phone;
			obj >> arr[i].m_points;
			// obj >> arr[i].orders;
		}
	}

	obj.close();
	return arr;
}
Messages* read_from_messages_DB()
{
	int size;
	ifstream obj("Messages.txt");
	if (!obj)
	{
		cout << "Error opening file";
	}
	obj >> size;
	Messages* arr = new Messages[size];//יצירת מערך בגודל המאגר
	if (size != 0)
	{
		for (int i = 0; i < size; i++)//העתקה מהמאגר למערך
		{
			obj >> arr[i].m_message_id;
			obj >> arr[i].m_customer_id;
			obj >> arr[i].m_area;
			obj.ignore();
			getline(obj, arr[i].m_massege);
		}
	}
	obj.close();
	return arr;
}

//Functions writing functions for a database

void write_to_flights_DB(Flights* f, int size)
{
	ofstream obj("Flights.txt");
	obj << size << endl;
	for (int i = 0; i < size; i++)
	{

		obj << f[i].m_flight_id << " ";
		obj << f[i].m_departure_location << " ";
		obj << f[i].m_arrival_location << " ";
		obj << f[i].m_departure_date.m_day << " " << f[i].m_departure_date.m_month << " " << f[i].m_departure_date.m_year << " ";
		obj << f[i].m_return_date.m_day << " " << f[i].m_return_date.m_month << " " << f[i].m_return_date.m_year << " ";
		obj << f[i].m_price << " ";
		obj << f[i].m_area << " ";
		obj << f[i].m_class_f << " ";
		obj << f[i].m_quantity << " ";
		obj << f[i].m_direct << " ";
		obj << f[i].m_one_way << " ";
		obj << f[i].m_sales_counter << " ";
		obj << f[i].m_agent_id << " ";
		obj << f[i].m_description << endl;
	}
	obj.close();
}
void write_to_hotels_DB(Hotels* h, int size)
{
	ofstream obj("Hotels.txt");
	obj << size << endl;
	for (int i = 0; i < size; i++)
	{
		obj << h[i].m_hotel_id << " ";
		obj << h[i].m_hotel_name << " ";
		obj << h[i].m_hotel_location << " ";
		obj << h[i].m_check_in.m_day << " " << h[i].m_check_in.m_month << " " << h[i].m_check_in.m_year << " ";
		obj << h[i].m_check_out.m_day << " " << h[i].m_check_out.m_month << " " << h[i].m_check_out.m_year << " ";
		obj << h[i].m_guest << " ";
		obj << h[i].m_room_type << " ";
		obj << h[i].m_rating << " ";
		obj << h[i].m_price << " ";
		obj << h[i].m_quantity << " ";
		obj << h[i].m_sales_counter << " ";
		obj << h[i].m_agent_id << " ";
		obj << h[i].m_area << " ";
		obj << h[i].m_description << endl;
	}
	obj.close();
}
void write_to_packages_DB(Packages* p, int size)
{
	ofstream obj("Packages.txt");
	obj << size << endl;
	for (int i = 0; i < size; i++)
	{
		obj << p[i].m_package_id << " ";
		obj << p[i].m_start.m_day << " " << p[i].m_start.m_month << " " << p[i].m_start.m_year << " ";
		obj << p[i].m_end.m_day << " " << p[i].m_end.m_month << " " << p[i].m_end.m_year << " ";
		obj << p[i].m_price << " ";
		obj << p[i].m_area << " ";
		obj << p[i].m_origin << " ";
		obj << p[i].m_destinion << " ";
		obj << p[i].m_num_of_travelers << " ";
		obj << p[i].m_quantity << " ";
		obj << p[i].m_sales_counter << " ";
		obj << p[i].m_agent_id << " ";
		obj << p[i].m_points << " ";
		obj << p[i].m_organized_trip << " ";
		obj << p[i].m_description << endl;
	}
	obj.close();
}
void write_to_orders_DB(Orders* o, int size)
{
	ofstream obj("Orders.txt");
	obj << size << endl;
	for (int i = 0; i < size; i++)
	{
		obj << o[i].m_package_id << " ";
		obj << o[i].m_customer_id << " ";
		obj << o[i].m_friends << " ";
		obj << o[i].m_status << endl;
	}
	obj.close();
}
void write_to_messages_DB(Messages* m, int size)
{
	ofstream obj("Messages.txt");
	obj << size << endl;
	for (int i = 0; i < size; i++)
	{
		obj << m[i].m_message_id << " ";
		obj << m[i].m_customer_id << " ";
		obj << m[i].m_area << " ";
		obj << m[i].m_massege << endl;
	}
	obj.close();
}
void write_to_customers_DB(Customer* c, int size)
{
	ofstream obj("Customer.txt");
	if (obj)
	{
		obj << size << endl;
		for (int i = 0; i < size; i++)
		{
			obj << c[i].m_id << " ";
			obj << c[i].m_first_name << " ";
			obj << c[i].m_last_name << " ";
			obj << c[i].m_password << " ";
			obj << c[i].m_email << " ";
			obj << c[i].m_phone << " ";
			obj << c[i].m_points << endl;
		}
	}
	else
	{
		cout << "Error Opening File" << endl;
		exit(1);
	}

	obj.close();
}
void write_to_agent_DB(Agent* a, int size)
{
	ofstream obj("Agent.txt");
	obj << size << endl;
	for (int i = 0; i < size; i++)
	{
		obj << a[i].m_id << " ";
		obj << a[i].m_first_name << " ";
		obj << a[i].m_last_name << " ";
		obj << a[i].m_area << " ";
		obj << a[i].m_sales << endl;
	}
	obj.close();
}
void write_new_agent_to_agent_DB(Agent* a, int size) {
	ofstream obj("Agent.txt");
	obj << size << endl;
	for (int i = 0; i < size; i++)
	{
		obj << a[i].m_id << " " << a[i].m_first_name << " " << a[i].m_last_name << " " << a[i].m_area << " " << a[i].m_sales << endl;

	}
	cout << "Agent successfully added" << endl;
	obj.close();
}