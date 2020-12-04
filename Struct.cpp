
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

/*

struct Agent {

	long m_id;
	string m_first_name;
	string m_last_name;
	string m_area;
	int m_sales;

	Agent(long id, string first_name, string last_name, string area, int sales)
	{
		m_id = id;
		m_first_name = first_name;
		m_last_name = last_name;
		m_area = area;
		m_sales = sales;

	}


	friend ostream& operator<<(ostream& flux, Agent const& student);
	friend istream& operator>>(istream& flux, Agent const& student);
}; 

struct ManagerMenu {

	Agent** m_array;
	int m_size_array;

	
	~ManagerMenu() 
	{
		for (int i = 0; i < m_size_array; i++)
		{
			delete m_array[i];
		}
		delete[] m_array;
	}
	

	void operator +=(Agent& student) {
		Agent** temp = m_array; // create a temporary 

		m_array = new Agent * [m_size_array]; // dynamic allocation
		if (!m_array) {
			cout << "Failed" << endl; // check
			exit(1);
		}


		for (int i = 0; i < m_size_array - 1; i++)
		{
			m_array[i] = temp[i]; // copy the old student
		}

		m_array[m_size_array - 1] = &student; // insert last student 

	}

	void Add_Agent() 
	{
		int sizestudent1;
		cout << "How many Agent you want to save ?" << endl;
		cin >> sizestudent1; // number of student we want to save

		for (m_size_array = 1; m_size_array <= sizestudent1; ++m_size_array) // add client one by one
		{
			cout << "Agent Details:" << endl;
			cout << "id: " << endl;
			long id;
			cin >> id;
			cout << "First Name: " << endl;
			string first_name;
			cin >> first_name;
			cout << "Last Name: " << endl;
			string last_name;
			cin >> last_name;
			cout << "Area: " << endl;
			string area;
			cin >> area;
			cout << "Sales: " << endl;
			int sales;
			cin >> sales;



			Agent* newagent = new Agent(id, first_name, last_name, area, sales); // insert user information
			*this += *newagent; // operator +=
		}

	}

	void WriteFile() {

		ofstream monflux("sectiondata.txt"); // write in the file

		if (monflux)
		{
			int size = m_size_array;
			m_size_array = size - 1;
			monflux << m_size_array << endl;
			for (int i = 0; i < size - 1; i++)        // write the object in the file 
			{
				monflux << endl;
				monflux << *m_array[i] << endl;
				monflux << endl;
			}

		}
	}

	void ReadFile()
	{
		ifstream monflux("sectiondata.txt");

		if (monflux)
		{
			//opening succeed

			string ligne;

			while (getline(monflux, ligne))
			{
				cout << ligne << endl;
			}
		}
		else
		{
			cout << "Error for read file" << endl;
		}
	}


};




int main()
{
	//Agent Neriya(1566, "Neriya", "Zudi", "Israel", 1);
	//cout << Neriya;
	
	ManagerMenu a;

	//a.Add_Agent();
	//a.WriteFile();

	a.ReadFile();
	



}



ostream& operator<<(ostream& flux, Agent const& student)
{

	flux << student.m_id << " " << student.m_first_name << " " << student.m_last_name << " " << student.m_area << " " << student.m_sales << endl;


	return flux;
}

istream& operator>>(istream& flux, Agent const& student)
{

	return flux;
}
*/

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

	Date(int day, int month, int year)
	{
		m_day = day;
		m_month = month;
		m_year = year;
	}

	friend ostream& operator<<(ostream& flux, Date const& date);
	friend istream& operator>>(istream& is, Date& d);


};

ostream& operator<<(ostream& flux, Date const& date)
{

	flux << date.m_day << "/" << date.m_month << "/" << date.m_year << endl;


	return flux;
}

istream& operator>>(istream& is, Date& d)
{
	
	is >> d.m_day >> d.m_month >> d.m_year;

	return is;
}

/*
struct Room
{
	int m_type;
	int m_quantity;

};
*/

struct Orders
{
	string m_package_id;
	long m_customer_id;
	int m_status;

	Orders(string package_id, long customer_id, int status) 
	{
		m_package_id = package_id;
		m_customer_id = customer_id;
		m_status = status;
	}

};

struct Customer
{

	long m_id;
	string m_first_name;
	string m_last_name;
	string m_password;
	string m_email;
	string m_phone;
	int m_points;
	bool m_friends;
	Orders* m_orders;

	Customer(long id, string first_name, string last_name, string password, string email, string phone, int points, bool friends, Orders* orders)
	{
		m_id = id;
		m_first_name = first_name;
		m_last_name = last_name;
		m_password = password;
		m_email = email;
		m_phone = phone;
		m_friends = friends;
		m_orders = orders;

	}

	friend ostream& operator<<(ostream& flux, Customer const& customer);
	friend istream& operator>>(istream& flux, Customer const& customer);
};

ostream& operator<<(ostream& flux, Customer const& customer)
{

	flux << customer.m_id << " " << customer.m_first_name << " " << customer.m_last_name << " " << customer.m_password << " " << customer.m_email << " " << customer.m_phone << " " << customer.m_friends << " " << customer.m_orders << endl;


	return flux;
}

istream& operator>>(istream& flux, Customer const& customer)
{

	return flux;
}


struct Messages
{
	long m_customer_id;
	string m_area;
	string m_message;

	Messages(long customer_id, string area, string message)
	{
		m_customer_id = customer_id;
		m_area = area;
		m_message = message;
	}

};

struct Flights
{
	string m_flight_id;
	Date m_departure;
	Date m_arrival;
	float m_price;
	string m_area;
	string m_class_f;
	int m_quantity;
	bool m_direct;
	bool m_one_d;
	string m_description;
	long m_agent_id;

	Flights()
	{
		m_flight_id = nullptr;
		m_class_f = nullptr;
		m_direct = false;
		m_one_d = false;
		m_price = 0;
		m_area = nullptr;
		m_description = nullptr;
		m_quantity = 0;
		m_agent_id = 0;
	}

	Flights(string id, Date departure, Date arrival, string class_f, bool direct, bool one_d, float price, string area, string description, int quantity, long agent_id)
	{
		m_flight_id = id;
		m_departure = departure;
		m_arrival = arrival;
		m_class_f = class_f;
		m_direct = direct;
		m_one_d = one_d;
		m_price = price;
		m_area = area;
		m_description = description;
		m_quantity = quantity;
		m_agent_id = agent_id;

	}

	//friend istream& operator>>(istream& is, Flights& d);
};

/*
istream& operator>>(istream& is, Flights& d)
{
	
	is >> d.m_flight_id;
	is >> d.m_departure;
	is >> d.m_arrival;
	is >> d.m_class_f;
	is >> d.m_direct;
	is >> d.m_one_d;
	is >> d.m_price;
	is >> d.m_area;
	is >> d.m_description;
	is >> d.m_quantity;
	is >> d.m_agent_id;

	return is;
}

*/

struct Hotels
{
	string m_hotel_id;
	Date m_check_in;
	Date m_check_out;
	int m_guest;
	bool m_room_type;
	int m_rating;
	float m_price;
	string m_area;
	string m_description;
	int m_quantity;
	long m_agent_id;

	Hotels()
	{

		m_hotel_id = nullptr;
		m_check_in = Date();
		m_check_out = Date();
		m_guest = 0;
		m_room_type = false;
		m_rating = 0;
		m_price = 0;
		m_area = nullptr;
		m_description = nullptr;
		m_quantity = 0;
		m_agent_id = 0;

	}

	Hotels(string id, Date check_in, Date check_out, int guest, bool room_type, int rating, float price, string area, string description, int quantity, long agent_id)
	{
		m_hotel_id = id;
		m_check_in = check_in;
		m_check_out = check_out;
		m_guest = guest;
		m_room_type = room_type;
		m_rating = rating;
		m_price = price;
		m_area = area;
		m_description = description;
		m_quantity = quantity;
		m_agent_id = agent_id;

	}


};

struct Packages
{
	string m_package_id;
	Date m_start;
	Date m_end;
	float m_price;
	string m_area;
	string m_description;
	long m_agent_id;
	int m_quantity;
	Flights m_flight;
	Hotels m_hotel;
	

	Packages(string package_id, Date start, Date end, float price, string area, string description, long agent_id, int quantity, Flights flight, Hotels hotel)
	{
		m_package_id = package_id;
		m_start = start;
		m_end = end;
		m_price = price;
		m_area = area;
		m_description = description;
		m_agent_id = agent_id;
		m_quantity = quantity;
		m_flight = flight;
		m_hotel = hotel;
	}

	friend ostream& operator<<(ostream& flux, Packages const& packages);
	friend istream& operator>>(istream& flux, Packages const& packages);

};

ostream& operator<<(ostream& flux, Packages const& Packages)
{

	//flux << "Package: "<< Packages.m_package_id << Packages.m_first_name << " " << customer.m_last_name << " " << customer.m_password << " " << customer.m_email << " " << customer.m_phone << " " << customer.m_friends << " " << customer.m_orders << endl;


	return flux;
}

istream& operator>>(istream& flux, Packages const& customer)
{

	return flux;
}

int main()
{
	
}