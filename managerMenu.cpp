#define _CRT_SECURE_NO_WARNINGS
#define ManagerID 123456789
#define ManagerCompanyCode "v4u"
#define CompanyCode "VACATION4U0101"
#define AgentSalry 5000
#include <fstream> 
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
// m_points= price*0.1
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
};
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
	string m_package_id;
	long m_customer_id;
	int m_status;
	bool m_friends;

}Orders;
typedef struct
{
	long m_id;
	string m_first_name;
	string m_last_name;
	string m_password;
	string m_email;
	string m_phone;
	int m_points;
	Orders* orders;

}Customer;
typedef struct
{
	long m_customer_id;
	string m_area;
	string m_massege;

}Messages;
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
void manager_menu();
void add_agent();
void statistics_menu();
void reports();
void packages_sales();
void tracking_sales_agent();
Agent* read_from_agent_DB();
void view_agent_DB();
void write_to_agent_DB(Agent *a,int size);
int size_agent_DB();
bool agent_is_exist(long id, int size);
ostream& operator<<(ostream& output, const Date& date)
{

	output << date.m_day << "/" << date.m_month << "/" << date.m_year << endl;
	return output;
}
istream& operator>>(istream& is, Date& d)
{

	is >> d.m_day >> d.m_month >> d.m_year;

	return is;
}
int main() {
	manager_menu();
}
void manager_menu() {
	int choice = 0;
	while (choice != 4) {
		cout << "============================================" << endl;
		cout << "Hello to you dear manger what you want to do ?" << endl;
		cout << "1. Add new agent to the agency" << endl;
		cout << "2. Statistics menu" << endl;
		cout << "3. View agent DB" << endl;
		cout << "4.Return to home page" << endl;
		cout << "============================================" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			add_agent();
			break;
		case 2:
			statistics_menu();
			break;
		case 3:
			view_agent_DB();
			break;
		case 4:
			cout << "Home Page" << endl;//add func after finish
			break;


		default:
			cout << "Worng choice please choice again" << endl;
			break;
		}
	}
}
void view_agent_DB(){
	Agent* arr = read_from_agent_DB();
	int size = size_agent_DB();
	for (int i = 0; i < size; i++)
	{
		cout << "Agent Id:" << arr[i].m_id <<" "<< "Agent Name:" << arr[i].m_first_name << " " << arr[i].m_last_name << " " << "Agent Erea:" << arr[i].m_area << " " << "Agent sales:" << arr[i].m_sales << endl;
	}
}
bool agent_is_exist(long id,int size)
{
	Agent* arr = new Agent[size];
	for (int i = 0; i < size ;i++)
		arr[i] = read_from_agent_DB()[i];
	for (int i = 0; i < size; i++)
	{
		if (arr[i].m_id == id)
			return true;
	}
	return false;
}
void statistics_menu() {
	int choice = 0;
	while (choice != 4) {
		cout << "==========================" << endl;
		cout << "Statistics Menu" << endl;
		cout << "1. Financial reports" << endl;
		cout << "2. Packages sales" << endl;
		cout << "3. Tracking sales agent" << endl;
		cout << "4.Return to manager menu" << endl;
		cout << "==========================" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			reports();
			break;
		case 2:
			packages_sales();
			break;
		case 3:
			tracking_sales_agent();
			break;
		case 4:
			manager_menu();
			break;


		default:
			cout << "Worng choice please choice again" << endl;
			break;
		}
	}
}
void reports() {
	int choice = 0;
	while (choice != 4)
	{
		cout << "==============================" << endl;
		cout << "Reports Menu" << endl;
		cout << "1.view agency revenue by month" << endl;
		cout << "2.view agency revenue by year" << endl;
		cout << "3.Return to statistics menu" << endl;
		cout << "==============================" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			//todo
			break;
		case 2:
			//todo
			break;
		case 3:
			statistics_menu();
			break;
		default:
			cout << "Worng choice please choice again" << endl;
			break;
		}

	}

}
void packages_sales() {
	int choice = 0;
	while (choice != 4)
	{
		cout << "==============================" << endl;
		cout << "Packages sales" << endl;
		cout << "1.See the best-selling package" << endl;
		cout << "2.See the best-selling hotel" << endl;
		cout << "3.See the best-selling flight" << endl;
		cout << "4.Return to statistics menu" << endl;
		cout << "==============================" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "the best-selling package work" << endl;//delete this!!
			//read from order DB by p id&counter
			break;
		case 2:
			cout << "the best-selling hotel work" << endl;//delete this!!
			////read from order DB by h id&counter&filter
			break;
		case 3:
			cout << "the best-selling flight work" << endl;//delete this!!
			//read from order DB by f id&counter&filter
			break;
		case 4:
			statistics_menu();
			break;


		default:
			cout << "Worng choice please choice again" << endl;
			break;
		}
	}

}
void tracking_sales_agent()
{
	Agent* arr = read_from_agent_DB();
	Agent most_lucrative_agent =arr[0];
	for (int i = 0; i < size_agent_DB(); i++)
	{
		if(arr[i].m_sales>most_lucrative_agent.m_sales)
			most_lucrative_agent=arr[i];
	}
	cout << "The most lucrative agent in the agency is: "<< most_lucrative_agent.m_first_name << " " << most_lucrative_agent.m_last_name << " " << "his sales quantity is: " << most_lucrative_agent.m_sales << endl;
	statistics_menu();
	
}
Agent* read_from_agent_DB()
{
	int size;
	ifstream obj("Agent.txt");
	if (!obj)
	{
		cout << "Error opening file";
	}
	obj >> size;
	Agent* arr = new Agent[size];//יצירת מערך בגודל המאגר
	if (size != 0)
	{
		for (int i = 0; i < size; i++)//העתקה מהמאגר למערך
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
void write_to_agent_DB(Agent *a,int size) {
	ofstream obj("Agent.txt");
	obj << size << endl;
	for (int i = 0; i < size; i++)
	{
		obj << a[i].m_id << " " << a[i].m_first_name << " " << a[i].m_last_name << " " << a[i].m_area << " " << a[i].m_sales << endl;

	}
	cout << "Agent successfully added" << endl;
	obj.close();
}
void add_agent() {
	Agent new_agent = {};
	long id;
	int sales, size = size_agent_DB(), flag;
	
	string first_name, last_name, area;
	Agent* arr = read_from_agent_DB();
	Agent* new_arr = new Agent[size + 1];
	cout << "enter Id of agent ";
	cin >> new_agent.m_id;
	while (agent_is_exist(new_agent.m_id, size))
	{
		cout << "Id is exist please enter again " << endl;
		cin >> new_agent.m_id;
	}
	cout << "enter first name of agent ";
	cin >> new_agent.m_first_name;
	cout << "enter last name of agent ";
	cin >> new_agent.m_last_name;
	cout << "enter area of agent ";
	cin >> new_agent.m_area;

	fstream obj1;	obj1.open("Agent.txt");

	if (size == 0)
	{
		obj1 << 1 << endl;
		obj1 << new_agent.m_id << " " << new_agent.m_first_name << " " << new_agent.m_last_name << " " << new_agent.m_area << " " << new_agent.m_sales << endl;
		cout << "You want to add another agent?" << endl;
		cout<<"1 yes\n2 no"<<endl;
		cin >> flag;
		if (flag == 1)
			add_agent();
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			new_arr[i].m_id = arr[i].m_id;
			new_arr[i].m_first_name = arr[i].m_first_name;
			new_arr[i].m_last_name = arr[i].m_last_name;
			new_arr[i].m_area = arr[i].m_area;
			new_arr[i].m_sales = arr[i].m_sales;

		}
		
		new_arr[size].m_id = new_agent.m_id;
		new_arr[size].m_first_name = new_agent.m_first_name;
		new_arr[size].m_last_name = new_agent.m_last_name;
		new_arr[size].m_area = new_agent.m_area;
		new_arr[size].m_sales = 0;
		size++;
		cout << "You want to add another agent?" << endl;
		cout << "1 yes\n2 no" << endl;
		cin >> flag;
		if (flag == 1)
			add_agent();
		else
		write_to_agent_DB(new_arr, size);

	}
	obj1.close();

}