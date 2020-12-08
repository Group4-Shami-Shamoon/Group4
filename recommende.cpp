#define _CRT_SECURE_NO_WARNINGS
#include <fstream> // טיפול בקבצים
#include <iostream>
#include <string.h>
#include <string>

using namespace std;
#define ManagerID 123456789
#define ManagerCompanyCode "v4u"
#define CompanyCode "VACATION4U0101"
#define points 0.01
long log_in_id = 0;


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
};
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
	string m_message_id;
	string m_customer_id;
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

void print_package(Packages p)
{
	cout << "The package area : " << p.m_area << endl;
	cout << "The package origin; : " << p.m_origin << endl;
	cout << "The package destinion : " << p.m_destinion << endl;
	cout << "The package start date : " << p.m_start;
	cout << "The package end data : " << p.m_end;
	cout << "The package is for : " << p.m_num_of_travelers << endl;
	cout << "The package price : " << p.m_price << endl;
	cout << "The package give you " << p.m_points * 0.1 << " points" << endl;
	if (p.m_organized_trip)
		cout << "This package ia for organized trip" << endl;
	cout << p.m_description << endl;
}
int size_package_quantity()
{
	int count = 0;
	Packages* new_packages = read_from_packages_DB();
	for (int i = 0; i < size_packages_DB(); i++)
		if (new_packages[i].m_quantity != 0)
			count++;
	return count;
}
Packages* only_packages_quantity()
{
	Packages* packages_quantity = new Packages[sizeof(Packages) * size_package_quantity()];
	Packages* new_packages = read_from_packages_DB();
	int j = 0;
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
void recommended()
{
	Packages* new_packages = only_packages_quantity();
	if (size_package_quantity() < 4)
	{
		if (size_package_quantity() == 3)
		{
			Packages* recommended_packages = new Packages[sizeof(Packages) * 3];
			recommended_packages[0] = new_packages[0];
			recommended_packages[1] = new_packages[1];
			recommended_packages[2] = new_packages[2];
			// print recommended package
			cout << "THE BEST PACKAGE SELERS" << endl;
			cout << "Package number 1" << endl;
			print_package(recommended_packages[0]);
			cout << "Package number 2" << endl;
			print_package(recommended_packages[1]);
			cout << "Package number 3" << endl;
			print_package(recommended_packages[2]);

			int choice = 0;
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
		else if (size_package_quantity() == 2)
		{
			Packages* recommended_packages = new Packages[sizeof(Packages) * 2];
			recommended_packages[0] = new_packages[0];
			recommended_packages[1] = new_packages[1];
			// print recommended package
			cout << "THE BEST PACKAGE SELERS" << endl;
			cout << "Package number 1" << endl;
			print_package(recommended_packages[0]);
			cout << "Package number 2" << endl;
			print_package(recommended_packages[1]);
			int choice = 0;
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
			cout << "Package number 1" << endl;
			print_package(recommended_packages[0]);
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
		else
			cout << "Empty Recommende Packages" << endl;
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
		cout << "Package number 1" << endl;
		print_package(recommended_packages[0]);
		cout << "Package number 2" << endl;
		print_package(recommended_packages[1]);
		cout << "Package number 3" << endl;
		print_package(recommended_packages[2]);
		int choice = 0;
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
void update_orders(string num_orders, int friends)
{
	Orders* o = read_from_orders_DB();
	int order_size = size_orders_DB() + 1;
	Orders* new_orders = new Orders[sizeof(Orders) * order_size];
	new_orders = o;
	Customer c;
	Customer* customers = new Customer[sizeof(Customer) * 1];
	for (int i = 0; i < size_customer_DB(); i++)
		if (customers[i].m_id == log_in_id)
			c = customers[i];
	new_orders[order_size].m_customer_id = log_in_id;
	new_orders[order_size].m_package_id = num_orders;
	new_orders[order_size].m_status = "In process";
	if (friends == 1)
	{
		new_orders[order_size].m_friends = true;
		// print all people detiels in this package
		print_people_from_the_same_package(num_orders);
	}
	else
		new_orders[order_size].m_friends = false;
	write_to_orders_DB(new_orders, order_size);

	// change agent order
	change_agent_order(num_orders);

}
void print_people_from_the_same_package(string num_orders)
{
	cout << "===========================" << endl;
	cout << "This pepoles have the same package" << endl;
	Customer* c = read_from_customer_DB();
	Orders* o = read_from_orders_DB();
	for (int i = 0; i < size_customer_DB(); i++)
	{
		for (int j = 0; j < size_orders_DB(); j++)
		{
			if (c[i].m_id == o[j].m_customer_id && o[j].m_package_id == num_orders && log_in_id != c[i].m_id)
			{
				cout << "Name: " << c[i].m_first_name << " " << c[i].m_last_name << endl;
				cout << "Phone number: " << c[i].m_phone << endl;
				cout << "Email: " << c[i].m_email << endl;
			}
		}
	}
}
bool make_reservation(string num_orders, string type)//type-type of package
{
	if (log_in_id == 0)
	{
		// log in / log out
	}

	if (type == "Packages")
	{
		cout << "Packages-reservision" << endl;
		Packages* new_packages = read_from_packages_DB();
		int size = size_packages_DB();
		for (int i = 0; i < size; i++)
		{
			if (new_packages[i].m_package_id == num_orders)
			{
				new_packages[i].m_quantity--;
				new_packages[i].m_sales_counter++;
				// upated customer points
				int choice;
				cout << "Do you want friends for travel?\n 1-YES\n2-NO" << endl;
				cin >> choice;
				while (choice != 1 || choice != 2)
				{
					cout << "Error try again\n 1-YES\n2-NO " << endl;
				}
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
				new_hotels[i].m_quantity--;
				new_hotels[i].m_sales_counter++;
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
				new_flights[i].m_quantity--;
				new_flights[i].m_sales_counter++;
				update_orders(num_orders, 2);
			}
		}
		write_to_flights_DB(new_flights, size);
	}
	return true;

	// 
	cout << "==========================" << endl;
	cout << "Thank you for your orders" << endl;
	cout << "==========================" << endl;
}
void change_agent_order(string num_orders)
{
	Agent* a = read_from_agent_DB();
	int fine = 0;
	long agent_id = 0;

	// chacking type num order
	Packages* p = read_from_packages_DB();
	for (int i = 0; i < size_packages_DB(); i++)
		if (p[i].m_package_id == num_orders)
		{
			agent_id = p[i].m_agent_id;
			upadate_customer_points(p[i].m_points);
		}

	Hotels* h = read_from_hotels_DB();
	for (int i = 0; i < size_hotels_DB(); i++)
		if (h[i].m_hotel_id == num_orders)
			agent_id = h[i].m_agent_id;

	Flights* f = read_from_flights_DB();
	for (int i = 0; i < size_flights_DB(); i++)
		if (f[i].m_flight_id == num_orders)
			agent_id = h[i].m_agent_id;

	for (int i = 0; i < size_agent_DB(); i++)
	{
		if (a[i].m_id == agent_id)
		{
			a[i].m_sales++;
		}
	}
	write_to_agent_DB(a, size_agent_DB());
}
void upadate_customer_points(int point)
{
	Customer* c = read_from_customer_DB();
	for (int i = 0; i < size_customer_DB(); i++)
	{
		if (c[i].m_id == log_in_id)
			c[i].m_points += point * points;
	}
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
			obj >> arr[i].m_price;
			obj >> arr[i].m_area;
			obj >> arr[i].m_origin;
			obj >> arr[i].m_destinion;
			obj >> arr[i].m_num_of_travelers;
			obj >> arr[i].m_quantity;
			obj >> arr[i].m_sales_counter;
			obj >> arr[i].m_agent_id;
			obj >> arr[i].m_points;
			obj >> arr[i].m_organized_trip;
			obj.ignore();
			getline(obj, arr[i].m_description);
		}
	}
	obj.close();
	return arr;
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

// Customer DB func
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
		}
	}

	obj.close();
	return arr;
}
void write_to_customer_DB(Customer* c, int size)
{
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


// Orders DB func
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
			obj >> arr[i].m_status;
			obj >> arr[i].m_friends;
			obj.ignore();
			getline(obj, arr[i].m_status);
		}
	}

	obj.close();
	return arr;
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


// Messages DB func
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
void write_to_messages_DB(Messages* m, int size)
{
	ofstream obj("Orders.txt");
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


// Flights DB func
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


// Hotels DB func
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


// Agent DB func
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
void write_to_agent_DB(Agent* a,int size)
{
	ofstream obj("Agent.txt");
	int new_size = size_agent_DB() + 1;
	obj << new_size << endl;
	for (int i = 0; i < new_size; i++)
	{
		obj << a[i].m_id;
		obj << a[i].m_first_name;
		obj << a[i].m_last_name;
		obj << a[i].m_area;
		obj << a[i].m_sales << endl;
	}
	obj.close();
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