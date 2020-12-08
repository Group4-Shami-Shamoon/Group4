#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include<fstream>
#include <string.h>
#include <string>
#define ManagerID 123456789
#define ManagerCompanyCode "v4u"
#define CompanyCode "VACATION4U0101"

using namespace std;

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
	friend ostream& operator <<(ostream& os, const Date& d);
	friend istream& operator >>(istream& is, Date& d);

};
typedef struct
{

	long m_id;
	string m_first_name;
	string m_last_name ;
	string m_area;
	int m_sales;


}Agent;
typedef struct
{
	string m_package_id;
	long m_customer_id;
	bool m_friends;
	string m_status;
	

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

}Customer;
typedef struct 
{

	string m_message_id = " ";
	long m_customer_id = 0;
	string m_area = " ";
	string m_massege = " ";
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
Packages* read_from_Packages_DB();
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
//Statements of functions to add
void add_new_package(Packages* arr, int agent_index);
void add_new_flight(Flights* arr, int agent_index);
void add_new_hotel(Hotels* arr, int agent_index);
Packages make_package();
Flights make_flight();
Hotels make_hotel();
//Update Function Statements
void update_package(Packages* arr,int index);
void update_flight(Flights* arr, int agent_index);
void update_hotel(Hotels* arr, int agent_index);
Packages update_p(Packages p);
Flights update_f(Flights f);
Hotels update_h(Hotels h);
//Remove Functions
void remove_package(Packages* arr, int index);
void remove_flight(Flights* arr, int agent_index);
void remove_hotel(Hotels* arr, int agent_index);
void remove_message(string id);
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
Flights* agent_flights(Flights* arr, int* f,long agent_id);
Hotels* agent_hotels(Hotels* arr, int *h, long agent_id);
void add_order_arr(Orders** arr, int *size, Orders order);
//Agent Functions
void view_DB();
void agent_login(Agent* arr);
void agent_menu(Agent* arr, int index);
void customer_orders(Packages* p, Flights* f, Hotels* h, Orders* arr, long agent_id);
void answer_message(Agent* a_db, long agent_id);
void home_page();


	//void add_package();
	void change_id();

	ostream& operator <<(ostream& os, const Date& d)
	{
		os << d.m_day << "/" << d.m_month << "/" << d.m_year << endl;
		return os;
	}
	istream& operator >>(istream& is, Date& d)
	{
		is >> d.m_day >> d.m_month >> d.m_year;
		return is;
	}
	

	int main()
	{
		home_page();
		
		//add_new_agent();
		//change_id();
		//change_message();
		//add_new_package(read_from_Packages_DB(),5);
		//view_DB();
	     //agent_login(read_from_agent_DB());
		//update_package(read_from_Packages_DB());
		//remove_package(read_from_Packages_DB(),5);
		//remove_flight(read_from_flights_DB(), 5);
		//remove_hotel(read_from_hotels_DB(), 5);
		//add_new_flight(5);
		//add_new_hotel(5);
		//update_flight(read_from_flights_DB(), 5);
		//update_hotel(read_from_hotels_DB(), 5);
		long id = 123;
		int p, f, h;
		//customer_orders(agent_packages(read_from_Packages_DB(),&p,id), agent_flights(read_from_flights_DB(), &f, id), agent_hotels(read_from_hotels_DB(), &h, id),read_from_orders_DB(), id);
		//agent_packages(read_from_Packages_DB(),&p,id);
		//agent_flights(read_from_flights_DB(),&f, id);
		//agent_hotels(read_from_hotels_DB(),&h, id);
		//answer_message(read_from_agent_DB(),126);
				
		
		return 0;
	}




	void change_id()
	{
		//קריאה מקובץ למערך
		int size, id;

		ifstream obj("agent.txt");
		if (!obj)
		{
			cout << "error";
		}
		obj >> size;
		Agent* arr = new Agent[size];//יצירת מערך בגודל המאגר
		if (size == 0)
			obj.close();
		for (int i = 0; i < size; i++)//העתקה מהמאגר למערך
			obj >> arr[i].m_id >> arr[i].m_first_name >> arr[i].m_last_name >> arr[i].m_area >> arr[i].m_sales;
		for (int i = 0; i < size; i++)//הדפסת המאגר ששמור במערך
			cout << arr[i].m_id << " " << arr[i].m_first_name << " " << arr[i].m_last_name << " " << arr[i].m_area << " " << arr[i].m_sales << endl;


		obj.close();

		//כתיבה/שינוי מערך וכתיבה לקובץ
		ofstream obj1("agent.txt");
		cout << "enter id you want to change" << endl;
		cin >> id;
		obj1 << size << endl;//כתיבה למאגר את גודל המאגר החדש
		for (int i = 0; i < size; i++)//ריצה כל כל המערך הקיים
		{
			if (arr[i].m_id == id)
			{
				cout << "enter new id" << endl;
				cin >> arr[i].m_id;
				obj1 << arr[i].m_id << " " << arr[i].m_first_name << " " << arr[i].m_last_name << " " << arr[i].m_area << " " << arr[i].m_sales << endl;
			}
			else
				obj1 << arr[i].m_id << " " << arr[i].m_first_name << " " << arr[i].m_last_name << " " << arr[i].m_area << " " << arr[i].m_sales << endl;

		}
		obj1.close();

	}


	void add_package()
	{


		Packages p;
		Hotels h;
		Flights f;

		string id;
		Date start;
		Date end;
		float price;
		string area, classs;
		string description;
		long agent_id;
		int quantity, choise = 0, day, month, year, ch;

		cout << "enter your choise:" << endl << "1.package" << endl << "2.flight" << endl << "3.hotel" << endl;
		cin >> choise;
		

		switch (choise)
		{

		case 1:
		{
			//call add package;
		}
		case 2:
		{
		
		}
		case 3:
		{
		
		}
		}
		cout << "print all" << endl;

	}

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
Packages* read_from_Packages_DB()
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
//Adding Functions
void add_new_package(Packages* arr,int agent_index)
{
	Packages p = make_package();

	int new_size = size_packages_DB() + 1;
	arr = new Packages[new_size];
	for (int i = 0; i < new_size-1; i++)
		arr[i] = read_from_Packages_DB()[i];
	arr[new_size - 1] = p;

	write_to_packages_DB(arr, new_size);
	 agent_menu(read_from_agent_DB(), agent_index);
}
void add_new_flight(Flights* arr,int agent_index)
{
	Flights f = make_flight();
	int new_size = size_flights_DB() + 1;
	 arr = new Flights[new_size];
	for (int i = 0; i < new_size - 1; i++)
		arr[i] = read_from_flights_DB()[i];
	arr[new_size - 1] = f;

	write_to_flights_DB(arr, new_size);
	agent_menu(read_from_agent_DB(), agent_index);

	

}
void add_new_hotel(Hotels* arr,int agent_index)
{
	Hotels h = make_hotel();
	int new_size = size_hotels_DB() + 1;
	 arr = new Hotels[new_size];
	for (int i = 0; i < new_size - 1; i++)
		arr[i] = read_from_hotels_DB()[i];
	arr[new_size - 1] = h;
	write_to_hotels_DB(arr, new_size);
	agent_menu(read_from_agent_DB(), agent_index);

}
//New struct to add
Packages make_package()
{
	Packages p;
	Date d;
	char c;
	cout << "Enter new package details:" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Enter package id: " << endl;
	//cin.ignore();
	getline(cin, p.m_package_id);
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
	p.m_agent_id = 12470;

	return p;

}
Flights make_flight()
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
		f.m_one_way = false;

	cout << "Enter flight description: " << endl;
	cin.ignore();
	getline(cin, f.m_description);
	f.m_sales_counter = 0;
	f.m_agent_id = 12470;

	return f;

}
Hotels make_hotel()
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
	h.m_agent_id = 12470;

	return h;

}
//Update Functions
void update_package(Packages* arr,int agent_index)
{
	string id;
	int choice,counter=0;
	cout << "Enter id of Package you want to change" << endl;
	cin >> id;
	while (!is_exist_package(arr,id))
	{
		cout << "Package does not exist in Data Base" << endl;
		cout << "1- Try Again." << endl;
		cout << "2- Back To Menu" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter id of Package you want to change" << endl;
			cin >> id;
			break;
		}
		case 2:
		{
			agent_menu(read_from_agent_DB(),agent_index);
			break;

		}

		default:
		{
			cout << "ERROR input ,please enter a number 1/2 " << endl;
			cin >> choice;
		}


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
		
	read_from_Packages_DB();
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
	while (!is_exist_flight(arr,id))
	{
		cout << "Flight does not exist in Data Base" << endl;
		cout << "1- Try Again." << endl;
		cout << "2- Back To Menu" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter id of Flight you want to change" << endl;
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
		cout << "Hotel does not exist in Data Base" << endl;
		cout << "1- Try Again." << endl;
		cout << "2- Back To Menu" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter id of Hotel you want to change" << endl;
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
	int choice,exit=0,counter=0;
	cout << "#################################################################" << endl;
	cout << "ID: " << p.m_package_id << endl << "Start: " << p.m_start << endl;
	cout << "End: " << p.m_end << endl << "Price: " << p.m_price << "$" << endl;
	cout << "Quantity right now: " << p.m_quantity << endl;
	cout << "#################################################################" << endl;
	cout << "What do you want to update ?" << endl;
	cout << "1.Package ID" << endl << "2.Start Date" << endl << "3.End Date" <<endl<< "4.Price" << endl;
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
		cout << "Quantity right now:" << p.m_quantity<<endl;
		cout << "Enter package quantity: " << endl;
		cin >> p.m_quantity;
		break;
	}
	case 10:
	{
		if (p.m_organized_trip == true)
			cout << "The package is currently an organized trip"<<endl;
		else
			cout << "The package is currently  NOT an organized trip"<<endl;
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
		cout << "ERROR input"<<endl; 
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
	cout<<	"Price: " << f.m_price << "$" << endl;
	cout << "Quantity right now: " << f.m_quantity << endl;
	cout << "#################################################################" << endl;
	cout << "What do you want to update ?" << endl;
	cout << "1.Flight ID" << endl << "2.Departure Location" << endl << "3.Arrival Location" << endl << "4.Departure Date" << endl;
	cout << "5.Return Date" << endl << "6.Price" << endl << "7.Flight Area" << endl;
	cout << "8.Flight Passenger class" << endl << "9. Quantity" << endl << "10.Direct or connection" << endl;
	cout<< "11.Round trip or one direction "<<endl<<"12.Description";
	cout << endl;
	cin >> choice;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	switch (choice)
	{
	case 1:
	{
		cout << "Current Flight ID: " << f.m_flight_id<< endl;
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
		if(f.m_class_f=='E')
		cout << "Current Flight Passenger class is Economy Class "<< endl;
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
		cout << "Quantity right now:" << f.m_quantity<< endl;
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
	cout << "ID: " << h.m_hotel_id<< endl << "Hotel name: " << h.m_hotel_name << endl << "Hotel Llocation: " << h.m_hotel_location << endl;
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
		cout << "Current Hotel ID: " << h.m_hotel_id<< endl;
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
		cout << "Current Check in Date: " << h.m_check_in<< endl;
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

		read_from_Packages_DB();
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
void remove_message(string id)
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
	cout << " The Package price : " << p.m_price <<" $"<< endl;
	cout << " The Package give you " << p.m_points<< " points" << endl;
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
	cout << "  The Flight Departure location : " << f.m_departure_location<< endl;
	cout << "  The Flight Arrival_location : " << f.m_arrival_location << endl;
	cout << "  The Flight Departure date : " << f.m_departure_date;
	cout << "  The Flight Return data : " << f.m_return_date;
	cout << "  The Flight price : " << f.m_price <<" $"<< endl;
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
	cout << f.m_description << endl<<endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

}
void print_hotel(Hotels h)
{
	cout << "  Hotel ID: " << h.m_hotel_id << endl;
	cout << "  The Hotel Area : " << h.m_area << endl;
	cout << "  The Hotel location : " << h.m_hotel_location << endl;
	cout << "  The Check in date : " << h.m_check_in;
	cout << "  The Check out data : " << h.m_check_out;
	cout << "  The Hotel Rating : " << h.m_rating <<" stars"<< endl;
	cout << "  The Hotel price : " << h.m_price << " $" << endl;
	cout << "  The Room is for :" << h.m_guest << " Guests" << endl;
	if (h.m_room_type)//1 - Suite 2 - Standard
		cout << "  This is Suite room " << endl;
	else
		cout<< "  This is Standard room " << endl;
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
Packages* agent_packages(Packages* arr,int *p, long agent_id)
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
Flights* agent_flights(Flights* arr,int *f, long agent_id)
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
Hotels* agent_hotels(Hotels* arr,int* h, long agent_id)
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
void add_order_arr(Orders** arr,int* size,Orders order)
{
	if (*size==0)
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
void view_DB()
{
	Packages *arr = new Packages [size_packages_DB()];
	for (int i = 0; i < size_packages_DB(); i++)
		arr[i] =read_from_Packages_DB()[i];
	for (int i = 0; i < size_packages_DB(); i++)
	{
		
		cout << "*********************************" << endl;
		cout << "Package id : " << arr[i].m_package_id<<endl;
		cout << "*********************************"<<endl;
		cout << "------------- Details ------------- " << endl;
		cout << "Start date: " << arr[i].m_start << endl;;
		cout << "End Date: " << arr[i].m_end << endl;
		cout << "Price: " << arr[i].m_price << " $" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << arr[i].m_description;
		cout <<endl<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;

	}


}
void agent_login(Agent* arr)
{
	long id;
	string c;
	bool success;
	int exit;
	cout << " ~~~~~~~~~~~~ AGENT LOG IN ~~~~~~~~~~~~"<<endl;
	cout << "ID number:" << endl;
	cin >> id;
	while (!is_exist_agent(id))
	{
		
		cout << "The id doesn't exsit in the system" << endl;
		cout << "To back home page press 0" << endl;
		cin >> exit;
		if (exit == 0)
		{
			home_page();
		}
		else
		{
			cout << "Try again:";
			cin >> id;
		}
	}
	cout <<endl<< "Enter company code:" << endl;
	cin.ignore();
	getline(cin, c);
	while (c!=CompanyCode)
	{
			cout << "inncorect company code" << endl;
			cout << "To back home page press 0" << endl;
			cin >> exit;
			if (exit == 0)
			{
				home_page();
			}
			else
			{
				cout << "Try again:";
				cin.ignore();
				getline(cin, c);
			}
	}
	success = true;
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
void agent_menu(Agent* arr,int agent_index)
{
	cout << endl << "Hello, wellcome " << arr[agent_index].m_first_name << " Glad to see you again" << endl;

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
		{
			
			break;
		}
		case 2:

			break;
		case 3:

			break;
		case 4:
			//read from package DB all package 
			break;
		case 5:
			home_page();
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
void customer_orders(Packages* p, Flights* f, Hotels* h, Orders* arr, long agent_id)
{
	int p_c = 0, f_c = 0, h_c = 0;
	int counter= 0;
	int size_of_order = 0;
	agent_packages(read_from_Packages_DB(), &p_c, agent_id);
	agent_flights(read_from_flights_DB(), &f_c, agent_id);
	agent_hotels(read_from_hotels_DB(), &h_c, agent_id);
	counter = p_c + f_c + h_c;
	Orders* o = new Orders[counter];
	string* s = new string[counter];
	int index = 0;
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
	/*customer_order* c_orders = new customer_order[index];
	
	for (int i = 0; i < size_customer_DB(); i++)
	{
		if(is_exist_customer_order(arr,read_from_customer_DB[i].))
	}
	for (int i = 0; i < index; i++)
	{
		if()
	}*/
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
				cout << "|  " << c[j].m_first_name << "     |    " << c[j].m_phone << "    |          "<< c[j].m_email<<"            |  " << o[i].m_package_id << "     |       " << o[i].m_status << "      |" << endl;
		        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
				
			}
			
			
		}

	}
	string choice;
	int select;
	cout << "Select an order that you want to change status {Package/Flight/Hotel ID}" << endl;
	getline(cin, choice);
	while (!is_exist_str(s,index,choice))
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
			while (select != 1 && select != 2 && select!=3)
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
void answer_message(Agent* a_db,long agent_id)
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
		if (area == m_db[i].m_area)
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
void home_page()
{
	int choice = 0;
	cout << "HELLO Welcome to the travel agency Vacation 4 U" << endl;
	while (choice != 6)
	{
		cout << "====================================" << endl;
		cout << "Home Page menu:\n1.About us\n2.Recommended package\n3.Search package\n4.Log-in\n5.sign up\n6.Exit" << endl;
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

			break;
		case 6:
			break;
		default:
		{
			cout << "ERROR input ,please enter a number between 1-6 " << endl;
			cin >> choice;
		}
		}
	}
}
void login()
{

	bool user_type;
	cout << "Agent or client?\nTo log in as an agent press 1,To log in as an customer press something else " << endl;
	cin >> user_type;
	if (user_type)
	{
		if (agent_login())//If the login is successful transfer to the appropriate menu
			agent_menu();


	}
	//else if (customer_login())
		//customer_menu();


}











