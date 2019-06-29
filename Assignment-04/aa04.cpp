#include<iostream>
#include<string>
using namespace std;

class User{
	protected:
	int id;
	string password;
	static int next_id;
	virtual int set_id();
	virtual static int set_next_id();
	virtual string set_password();
	virtual void sign_up(int id, string password);
	
	User();
};

int User::next_id = 0;

User::User(){
	//increment user id
}


class Buyer : public User{
	Property property[10];
	RateProperty rate_property[10];
	
	public:
	
	void add_credit();
	bool get_the_state_of_property();
	void buy_property();
	void new_property_status();
	
};

class RateProperty{
	public:
	static int property_id;
	void set_property_id();
	void rate_property();
	
};

int RateProperty::property_id = 0;


class Seller : public User{
	Property property[10];
	
	void set_state_of_property();
	
	//string path;
	//int size;
	
	public:
		
	void total_properties();
	int total_earnings();
	bool verification_of_earning();
	
	protected:
	
	int image_size();
	string relative_path();
		
	string post_image();
	string post_text_description();
	
	virtual void store_image();
	
};

class Server : public Seller{
	public:
	void store_image();
	
};



class WebAdmin : public User{
	public:
		
};




class Property{
	public:
	virtual int area_of_property();
	virtual bool status_of_property();
	virtual int cost_of_property();
	virtual int images();
	virtual string description();
	
};

class Condo : public Property{
	public:
	int num_of_rooms();
	bool amenities();
};

class Apartment : public Property{
	public:	 
	int num_of_rooms();
};

class House : public Property{
	public:
	int num_of_rooms();
};

class SingleRoom : public Property{
	public:
	bool room_shared();
	int people_in_room();
};





class DatabaseManager{
	protected:
	string database_username();
	string database_password();
	string server_location();
	
	public:
	virtual void connecting();
	virtual void disconnecting();
};

class MariaDB : public DatabaseManager{
	public:
	void connecting();
	void disconnecting();
};

class Postgres : public DatabaseManager{
	public:
	void connecting();
	void disconnecting();
};




int main(){
	
	return 0;
}
