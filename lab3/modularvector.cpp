#include <modularvector.h>

int main()
{
	vector<string> *v = new vector<string>;
	char choise;


	while (true)
	{
		cin.clear();
		fflush(stdin);

		cout << "MENU:" << endl;
		cout << "1. initialise database" << endl;
		cout << "2. insert" << endl;
		cout << "3. search" << endl;
		cout << "4. delete" << endl;
		cout << "5. print" << endl;
		cout << "6. save" << endl;
		cout << "7. load" << endl;
		cout << "8. quit" << endl;

		cin >> choise;

		if (choise == '8')
			break;

		switch (choise)
		{
		case '1':
			initialise_database(v);
			break;
		case '2':
			insert_vector(v);
			break;
		case '3':
			search_vector(v);
			break;
		case '4':
			delete_vector(v);
			break;
		case '5':
			print_vector(v);
			break;
		case '6':
			save(v);
			break;
		case '7':
			if (v->size() == 0)
			{
				load(v);
			}
			else
				cout << "Database is not empty. Run initialise database first." << endl;
			break;
		default:
			break;
		}
	}
	delete v;
	return 0;
}

bool initialise_database(vector<string>* v)
{
	char areyousure;

	cout << "Remove all names. Are you sure? [y/n] ";
	cin >> areyousure;
	if (areyousure == 'y')
	{
		v->clear();
		return 0;
	}
	return 1;
}

bool print_vector(const vector<string>* v)
{
	int i = 0;
	for (i ; i < v->size(); i++)
	{
		cout << v->at(i).data() << endl;	
	}
	if (i > 0)
	{
		return 1;
	}
	else return 0;
}

int insert_vector(vector<string>* v)
{
	string name;
	int elementsCreated = 0;
	cout << "Press q or Q to quit" << endl;
	while (true)
	{
		cout << "Enter name: ";
		cin >> name;
		if (name == "q" || name == "Q")
		{
			return elementsCreated;
		}
		else
		{
			elementsCreated++;
			v->push_back(name);
		}
	}
}

bool delete_vector(vector<string>* v)
{
	string name;
	bool deleted = false;
	cout << "Enter name to delete : ";
	cin >> name;

	for (auto iterator = v->begin(); iterator != v->end(); iterator++)
	{
		if (*iterator == name) // && v->size() != 1)
		{
			iterator = v->erase(iterator);
			deleted = true;
			break;
		}
	/*	else if (*iterator == name && v->size() == 1)
		{
			v->pop_back();
			deleted = true;
			break;
		}*/
	}

	return deleted;
}

bool search_vector(const vector<string>* v)
{
	string name;
	bool found = false;
	cout << "Enter name to find: ";
	cin >> name;

	for (auto iterator = v->begin(); iterator != v->end(); iterator++)
	{
		if ((*iterator).find(name) != string::npos)
		{
			found = true;
			cout << *iterator << endl;
		}
	}
	return found;
}

bool save(const vector<string>* v)
{
	ofstream filehandle; 
	filehandle.open("database.txt");
	if (filehandle.is_open())
	{
		for (int i = 0; i < v->size(); i++)
		{
			filehandle << v->at(i).data() << '\n';
		}
		filehandle.close();
		return 0;
	}
	else return 1;
}

bool load(vector<string>* v)
{
	ifstream filehandle; 
	filehandle.open("database.txt"); 
	string data;  

	if (filehandle.is_open())
	{
		while (getline(filehandle, data))
			v->push_back(data);

		filehandle.close();
		return 0;
	}
	else return 1;
}