#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Product
{
	string name;
	unsigned int quantity;
	double price;

public:

	Product() {}

	Product(string name, unsigned int quantity, double price)
	{
		this->name = name;
		this->quantity = quantity;
		if (price > 0)
			this->price = price;
	}

	Product(const Product& product)
	{
		this->name = product.get_name();
		this->quantity = product.get_quantity();
		this->price = product.get_price();
	}

	Product& operator=(const Product& product) {
		if (this != &product) {
			this->name = product.name;
			this->quantity = product.quantity;
			this->price = product.price;
		}
		return *this;
	}


	double get_price()const
	{
		return this->price;
	}
	void set_price(double new_price)
	{
		this->price = new_price;
	}

	unsigned int get_quantity()const
	{
		return this->quantity;
	}
	void set_quantity(unsigned int new_quantity)
	{
		this->quantity = new_quantity;
	}

	string get_name() const
	{
		return this->name;
	}
	void set_name(string name)
	{
		this->name = name;
	}


};


class Property
{
protected:
	string address;
	double rent;
	string type_after_rent;

public:
	Property() {}

	Property(string address, double rent, string type_after_rent)
	{
		this->address = address;
		if (rent > 0)
			this->rent = rent;
		if (type_after_rent == "supermarket" || type_after_rent == "pharmacy" || type_after_rent == "non-stop " || type_after_rent == "other")
		{
			this->type_after_rent = type_after_rent;
		}
	}

	Property(const Property& property)
	{
		this->address = property.get_address();
		this->rent = property.get_rent();
		this->type_after_rent = property.get_type_after_rent();
	}

	Property& operator=(const Property& property) {
		if (this != &property) {
			this->address = property.address;
			this->rent = property.rent;
			this->type_after_rent = property.type_after_rent;
		}
		return *this;
	}


	string get_address()const
	{
		return this->address;
	}

	string get_type_after_rent() const
	{
		return this->type_after_rent;
	}

	double get_rent() const
	{
		return this->rent;
	}

	double calculate_rent(double rent, string type_after_rent)
	{
		if (type_after_rent == "supermarket")
			return rent + 0.4 * rent;
		else if (type_after_rent == "pharmacy")
			return rent + 0.3 * rent;
		else if (type_after_rent == "non-stop")
			return rent + 0.2 * rent;
		else
			return rent;
	}

};


class Store : public Property
{
	string store_name;
	int size;
	Product* products;

public:

	Store(string store_name, int store_capacity, string address, double rent, string type_after_rent)
	{
		this->address = address;
		this->type_after_rent = type_after_rent;
		this->rent = calculate_rent(rent, type_after_rent);
		if (store_name.length() != 0)
			this->store_name = store_name;
		this->size = 0;
		this->products = new Product[store_capacity];
		return;
	}

	Store(const Store& store)
	{
		this->store_name = store.get_store_name();
		this->size = store.get_size();
		this->products = new Product[this->size];
		for (int i = 0; i < this->size; i++)
		{
			this->products[i] = store.products[i];
		}
	}

	Store& operator=(const Store& store)
	{
		if (this != &store)
		{
			this->store_name = store.store_name;
			this->size = store.size;
			this->products = new Product[this->size];
			for (int i = 0; i < this->size; i++)
			{
				this->products[i] = store.products[i];
			}
		}
		return *this;
	}

	string get_store_name()const
	{
		return this->store_name;
	}

	int get_size()const
	{
		return this->size;
	}

	vector<string> Revision()
	{
		vector<string> v;
		for (int i = 0; i < this->size; i++)
		{
			if (this->products[i].get_quantity() < 5)
				v.push_back(this->products[i].get_name());
		}
		return v;
	}

	void add_product(string product_name, unsigned int quantity, double price)
	{
		Product product = Product(product_name, quantity, price);
		this->size += 1;
		for (int i = 0; i < this->size; i++)
		{
			if (this->products[i].get_name() == product_name)
			{
				this->size -= 1;
				break;
			}

			if (this->products[i].get_quantity() == 0)
				this->products[i] = product;
		}
	}

	void new_quantity(string product_name, unsigned int new_quantity)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->products[i].get_name() == product_name)
			{
				this->products[i].set_quantity(this->products[i].get_quantity() + new_quantity);
				return;
			}
		}
		throw "The product isn't in the products of the store";
	}


	int buy_product(string product_name, int cnt)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->products[i].get_name() == product_name)
			{
				int k = this->products[i].get_quantity() - cnt;
				if (k > 0)
				{
					this->products[i].set_quantity(k);
					return cnt;
				}
				else
				{
					int res = this->products[i].get_quantity();
					this->products[i].set_quantity(0);
					return res;
				}
			}
		}
		throw "The product isn't in the products of the store";
	}

	int check_quantity(string product_name)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->products[i].get_name() == product_name)
			{
				return this->products[i].get_quantity();
			}
		}
		throw "The product isn't in the products of the store";
		return 0;
	}

	double check_price(string product_name)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->products[i].get_name() == product_name)
			{
				return this->products[i].get_price();
			}
		}
		throw "The product isn't in the products of the store";
		return 0;
	}

	void change_price(string product_name, double new_price)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->products[i].get_name() == product_name)
			{
				this->products[i].set_price(new_price);
				return;
			}
		}
		throw "The product isn't in the products of the store";
	}

	void print_store_info()
	{
		cout << "Store name: " << this->store_name << endl;
		cout << "Address: " << this->get_address() << endl;
		cout << "Type: " << this->get_type_after_rent() << endl;
		cout << "Rent: " << this->get_rent() << endl;

		cout << "Products: " << this->size << endl;

		for (int i = 0; i < this->size; i++)
		{
			cout << "Name: " << this->products[i].get_name() << endl;
			cout << "Quantity: " << this->products[i].get_quantity() << endl;
			cout << "Price: " << this->products[i].get_price() << endl;
			puts(" ");
		}
	}

};


int main()
{
	string store_name, store_address, store_type;
	double store_rent;
	do
	{
		cout << "Enter store's name: " << endl;
		cin >> store_name;
	} while (store_name.length() == 0);

	do
	{
		cout << "Enter store's address: " << endl;
		cin >> store_address;
	} while (store_address.length() == 0);

	int flag = 1;

	do
	{
		cout << "Enter store's type: " << endl;
		cin >> store_type;
		if (store_type == "supermarket" || store_type == "pharmacy" || store_type == "non-stop " || store_type == "other")
		{
			flag = 0;
		}
	} while (flag);

	do
	{
		cout << "Enter store's baseRent: " << endl;
		cin >> store_rent;
	} while (store_rent < 0);


	Store* store = new Store(store_name, 100, store_address, store_rent, store_type);

	system("clear");
	int num;

	do
	{
		cout << "1. Add product " << endl;
		cout << "2. Check product quantity " << endl;
		cout << "3. Check product price " << endl;
		cout << "4. Restock product " << endl;
		cout << "5. Change product price" << endl;
		cout << "6. Buy product   " << endl;
		cout << "7. Show shop's information " << endl;
		cout << "8. Revision " << endl;
		cout << "9. Exit  " << endl;

		cout << "Choose option:  " << endl;
		cin >> num;
		string product_name;
		unsigned int product_quantity;
		double product_price;
		vector<string> v;

		switch (num)
		{
		case 1:
			system("clear");
			do
			{
				cout << "Enter new product's name: " << endl;
				cin >> product_name;
				if (product_name.length() == 0)
				{
					cout << "Please enter valid name" << endl;
				}

			} while (product_name.length() == 0);

			cout << "Enter new product's quantity: " << endl;
			cin >> product_quantity;

			do
			{
				cout << "Enter new product's price: " << endl;
				cin >> product_price;

				if (product_price < 0)
				{
					cout << "Please enter valid price" << endl;
				}
			} while (product_price < 0);

			store->add_product(product_name, product_quantity, product_price);

			break;

		case 2:
			system("clear");
			cout << "Enter product's name: " << endl;
			cin >> product_name;
			try
			{
				int res = store->check_quantity(product_name);
				cout << "Quantity: " << res << endl;
			}
			catch (const char* msg)
			{
				cerr << msg << endl;
			};
			break;

		case 3:
			system("clear");
			cout << "Enter product's name: " << endl;
			cin >> product_name;
			try
			{
				double res = store->check_price(product_name);
				cout << "Price: " << res << endl;
			}
			catch (const char* msg)
			{
				cerr << msg << endl;
			};

			break;

		case 4:
			system("clear");
			cout << "Enter product's name: " << endl;
			cin >> product_name;
			do
			{
				cout << "Enter quantity : " << endl;
				cin >> product_quantity;
				if (product_quantity <= 0)
				{
					cout << "Enter positive number for quantity!" << endl;
				}
			} while (product_quantity <= 0);

			try
			{
				store->new_quantity(product_name, product_quantity);
				cout << "Successfully restoked " << product_name << endl;
			}
			catch (const char* msg)
			{
				cerr << msg << endl;
			};

			break;
		case 5:
			system("clear");
			cout << "Enter product's name: " << endl;
			cin >> product_name;
			do
			{
				cout << "Enter new price : " << endl;
				cin >> product_price;
				if (product_price <= 0)
				{
					cout << "Enter positive number for price!" << endl;
				}
			} while (product_price <= 0);

			try
			{
				store->change_price(product_name, product_price);
				cout << "Successfully changed the price of " << product_name << endl;
			}
			catch (const char* msg)
			{
				cerr << msg << endl;
			};

			break;
		case 6:
			system("clear");
			cout << "Enter product's name: " << endl;
			cin >> product_name;
			do
			{
				cout << "Enter quantity : " << endl;
				cin >> product_quantity;
				if (product_quantity <= 0)
				{
					cout << "Enter positive number for quantity!" << endl;
				}
			} while (product_quantity <= 0);

			try
			{
				int cnt = store->buy_product(product_name, product_quantity);
				if (cnt == product_quantity)
				{
					cout << "Successfully bought " << cnt << " " << product_name << " products" << endl;
				}
				else
				{
					cout << "There aren’t  " << product_quantity << " " << product_name << " products in the store!" << endl;
					cout << "Successfully bought " << cnt << " " << product_name << " products" << endl;
				}
			}
			catch (const char* msg)
			{
				cerr << msg << endl;
			};

			break;
		case 7:
			system("clear");
			store->print_store_info();

			break;
		case 8:
			system("clear");
			v = store->Revision();
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << endl;
			}
			break;

		case 9:
			system("clear");
			num = -1;
			break;

		default:
			cout << "Please enter number from 1 to 9" << endl;

		}

	} while (num != -1);

	return 0;
}