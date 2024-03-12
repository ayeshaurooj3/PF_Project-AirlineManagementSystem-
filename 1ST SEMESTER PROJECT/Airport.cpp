#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void add()
{
    ofstream fout;
    fout.open("Airport 2.txt",ios::app);
    cout<<"\nEnter the details:\n";
    string name, place;
    int flights, employees;
    cout<<"Enter the name of Airport: ";
    cin>>name;
    cout<<"Enter the place: ";
    cin.ignore();
    cin>>place;
    cout<<"Enter the number of flights: ";
    cin>>flights;
    cout<<"Enter the number of employees: ";
    cin>>employees;
    fout<<name<<"\t\t"<<place<<"\t\t"<<flights<<"\t\t"<<employees<<endl;
    cout<<"\nSuccessfully added\n";
    fout.close();
}

void delete_data()
{
    string name;
    ifstream fin;
    ofstream fout;
    fin.open("Airport.txt");
    fout.open("temp.txt",ios::app);
    cout<<"Enter the name of Airport to delete: ";
    cin>>name;
    string n, p;
    int f, e;
    while(fin>>n>>p>>f>>e)
    {
        if(n!=name)
        {
            fout<<n<<"\t\t"<<p<<"\t\t"<<f<<"\t\t"<<e<<endl;
        }
    }
    fin.close();
    fout.close();
    remove("Airport.txt");
    rename("temp.txt", "Airport.txt");
    cout<<"\nSuccessfully deleted\n";
}

void show()
{
    ifstream fin;
    fin.open("airport 2.txt");
    cout<<"Name\t\tPlace\t\tFlights\t\tEmployees\n";
    string n, p;
    int f, e;
    while(fin>>n>>p>>f>>e)
    {
        cout<<n<<"\t\t"<<p<<"\t\t"<<f<<"\t\t"<<e<<endl;
    }
    fin.close();
}

int total_profit_loss()
{
    ifstream fin;
    fin.open("airport 2.txt");
    string n, p;
    int f, e;
    int profit = 0;
    while(fin>>n>>p>>f>>e)
    {
        profit += f*10000 - e*5000;
    }
    fin.close();
    return profit;
}

int main()
{
    int ch;
    while(1)
    {
        cout<<"\nAirport Management System\n";
        cout<<"1. Add\n2. Delete\n3. Show\n4. Total Profit/Loss\n5. Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: add();
                    break;
            case 2: delete_data();
                    break;
            case 3: show();
                    break;
            case 4: cout<<"\nTotal Profit/Loss is: "<<total_profit_loss()<<endl;
                    break;
            case 5: exit(0);
                    break;
            default:
		    cout<<"\nInvalid choice\n";
        }
    }
    return 0;
}
