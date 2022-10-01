#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                 PERSON CLASS                                                                    //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Person
{
protected:
     int id;
     string name;
     string password;
 public:
//Constructor Default
     Person()
     {
        id=0;
        name = "";
        password="";
     }
     //Constructor w Parameters
     Person(int i, string n, string pass)
     {
        id=i;
        name=n;
        password=pass;

     }
    //Setter & Getters
    void set_id(int i)
    {
        id=i;
    }
    void set_name(string n)
    {
        name=n;
    }
    void set_password(string pass)
    {
        password=pass;
    }
    int get_id()
    {
        return id;
    }
    string get_name()
    {
    if(name.length()>5 && name.length()<20)
         {
             for(int i = 0; i<name.size();i++)
             {
                 if(isalpha(name[i]))
                 {
                return name;
                 }
                 else{
                        break;
                    cout << "Please make sure Letters are Alpha";
                 }
             }
         }
        else
        {
         return "Name Too Short";
        }
    }
    string get_password()
    {
    if(password.length()>8 && password.length()<20)
        {
         return password;
        }
        else
        {
          return "Password too Short";
        }
    }

};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                 CLIENT CLASS                                                                    //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Client:public Person
{
 //Attributes
 private:
     double balance;
 public:
    //Constructor Default
     Client()
     {
        balance=0;
     }
     //Constructor w Parameters
     Client(int i, string n, string pass, double bal):Person(i,n,pass)
     {
        balance=bal;
     }
    //Setter & Getters
/**************************************/
    void set_balance(double bal)
   {
      try {
        if(bal < 1500) {
            throw 000;
        }
        balance = bal;
    }
    catch(int e) {
        cout << "\nError: " << e;
        cout << "\nMinimum Balance: " << "1500";
    }
}
/**************************************/
    void deposit(double amount)
    {
        balance+=amount;
    }
/**************************************/
    void withdraw(double amount)
    {
        if(balance < amount)
        {
        cout << "Balance is too Low";
        }
        else{
          balance-=amount;
        }
    }
/**************************************/
    void transfer_to(Client &a, double amount)
    {
      if(balance > amount)
      {
        balance-=amount;
        a.deposit(amount);
      }
      else{
        cout << "Balance is too low";
      }
    }
/**************************************/
    double get_balance()
    {
        if(balance<1500)
        {
        return balance;
        cout << "Balance Is Too Low" << endl;
        }
        else
        {
        return balance;
        }
    }
/**************************************/
   virtual void display()
    {
    cout << "CLIENT NAME: " << name << endl;
    cout << "CLIENT ID: " << id << endl;
    cout << "CLIENT BALANCE: " << balance << endl;
    cout <<endl;
    }
/**************************************/

    void checkBalance(){
    cout << "Current Balance is: " << balance;
    cout <<endl;
    }


};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                 EMPLOYEE CLASS                                                                  //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Employee:public Person
{
 //Attributes
 private:
     double balance;
 public:
     //Constructor Default
     Employee()
     {
        balance=0;
     }
     //Constructor w Parameters
     Employee (int i, string n, string pass, double bal):Person(i,n,pass)
     {
        balance=bal;
     }
    //Setter & Getters
/**************************************/
    void set_balance(double bal)
    {
      try {
        if(bal < 1500) {
            throw 000;
        }
        balance = bal;
    }
    catch(int e) {
        cout << "\nError: " << e;
        cout << "\nMinimum Balance: " << "1500";
    }
}
/**************************************/
    double get_balance()
    {
    return balance;
    }
/**************************************/
 void display()
{
  cout << "EMPLOYEE NAME: " << name << endl;
  cout << "EMPLOYEE ID: " << id << endl;
  cout << "EMPLOYEE BALANCE: " << balance << endl;
  cout <<endl;
}
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                 ADMIN CLASS                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Admin:public Person
{
 //Attributes
 private:
     double balance;
 public:
     //Constructor Default
     Admin()
     {
        balance=0;
     }
     //Constructor w Parameters
     Admin (int i, string n, string pass, double bal):Person(i,n,pass)
     {
        balance=bal;
     }
    //Setter & Getters
/**************************************/
    void set_balance(double bal)
    {
     balance=bal;
    }
/**************************************/
    double get_balance()
    {
    if(balance<5000)
     {
    cout << "Balance is too low";
     }
    else
     {
    return balance;
     }
    }
/**************************************/
void display()
{
  cout << "ADMIN NAME: " << name << endl;
  cout << "ADMIN ID: " << id << endl;
  cout << "ADMIN BALANCE: " << balance << endl;
  cout <<endl;
}
};
class DataSourceInterface{
public:
    virtual void addClient(Client);
    virtual void addEmployee(Employee);
    virtual void addAdmin(Admin);
    virtual vector <Client> getAllClients();
    virtual vector <Employee> getAllEmployees();
    virtual vector <Admin> getAllAdmins();
    virtual void removeAllClients();
    virtual void removeAllEmployees();
    virtual void removeAllAdmins();
};
class FileManager:public Person{
public:
    //Add Admin method//
     void addAdmin(int i, string n, string pass, double bal, Admin a)
     {
    fstream fiA;
    fiA.open("admin.txt", fstream::app);
    cout << "***Bank System***";
    fiA << endl;
    cout << "\nEnter Name: ";
    cin >> n;
    a.set_name(n);
    fiA << "Name: " << n << endl;
    cout << "\nEnter Password: ";
    cin >> pass ;
    cout << "\nEnter ID: ";
    cin >> i;
    a.set_id(i);
    fiA << "ID: " <<i<< endl;
    cout << "\nEnter Balance: ";
    cin >> bal;
    fiA << "Balance: " <<bal << endl;
    a.set_balance(bal);

     }
    //Add Client Method//
    void addClient(int i, string n, string pass, double bal, Client c){
        fstream fiC;
        fiC.open("clients.txt",fstream::app);
      cout << "\nEnter Client's Name: ";
                cin >> n;
                c.set_name(n);
                cout << "\nEnter Client's ID: ";
                cin >> i;
                c.set_id(i);
                cout << "\nEnter Client's Password: ";
                cin >> pass;
                c.set_password(pass);
                cout << "Set Client's Balance: ";
                cin >> bal;
                c.set_balance(bal);
                fiC << "Client's Name: " << n << endl;
                fiC << "Client's ID: " << i << endl;
                fiC << "Client's Password: " << pass << endl;
                fiC << "Client's Balance: " << bal << endl;
    }


    //Add Employee Method//
     void addEmployee(int i, string n, string pass, double bal, Employee e){
         fstream fiE;
        fiE.open("employee.txt",fstream::app);
       cout << "\nEnter Employee's Name: ";
                cin >> n;
                e.set_name(n);
                cout << "\nEnter Employee's ID: ";
                cin >> i;
                e.set_id(i);
                cout << "\nEnter Employee's Password: ";
                cin >> pass;
                e.set_password(pass);
                cout << "Set Employee's Balance: ";
                cin >> bal;
                e.set_balance(bal);
                fiE << "Admin's Name: " << n << endl;
                fiE << "Admin's ID: " << i << endl;
                fiE << "Admin's Password: " << pass << endl;
                fiE << "Admin's Balance: " << bal << endl;
    }
};

int main() {

    int choice;
    //Client
    Client c1;
    Client c2;
    //Add Client
    FileManager fc;
    string nC1,nC2,pC;
    int balC,amC,wC,iC;
    //Employee
    Employee e;
    //Add Employee
    FileManager fe;
    string nE,pE;
    int balE,amE,wE,iE;
    //Admin
    Admin a;
    //Add Admin
    FileManager fa;
    string nA,pA;
    int balA,amA,iA;

    while(choice != 5){
    cout << "\n1)Admin";
    cout << "\n2)Employee";
    cout << "\n3)Client";
    cout << "\n4)Exit"<<endl;
    cout << "\nSelect any given option to proceed: ";
    cin >>choice;

    switch(choice){
case 1:
    {
     fa.addAdmin(iA,  nA,  pA,  balA, a);

 while(choice != 10) {
        cout << "\n1)Add Client";
        cout << "\n2)Add Employee";
        cout << "\n3)Remove Client";
        cout << "\n4)Remove Employee";
        cout << "\n5)Search for Client";
        cout << "\n6)Search for Employee";
        cout << "\n7)Exit";
        cout << "\nSelect any given option to proceed: ";
        cin >> choice;
        switch(choice) {
            case 1:
                fc.addClient(iC,  nC1,  pC,  balC, c1);
                break;

            case 2:
                fe.addEmployee(iE,  nE,  pE,  balE, e);
                break;

            case 3:
                cout << "\nYour Current Balance: " << c1.get_balance();
                break;
            case 4:
                cout <<"nEnter Amount: ";
                cin >> amC;
                cout <<"nEnter the Name of The Account: ";
                cin >> nC2;
                c1.transfer_to(c2, amC);
                cout << "Your Balance now is : "<< c1.get_balance() <<endl;;
                cout << "Other Account Balance is: "<< c2.get_balance();;
            case 5:
                {
                string search;
                string line;
                fstream fiC;
                fiC.open("clients.txt");
                cout <<"Enter ID: ";
                cin >> search;
                cout << endl;
                if(fiC.is_open())
                {
                    while(!fiC.eof())
                    {
                       getline(fiC, line);
                       if((line.find(search, 0)) !=string::npos)
                       {
                       cout <<"yes";
                       }
                    }
                    fiC.close();
                }
                }
            case 7:
                break;
            default:
                cout << "\nEnter Valid Option";
                break;
        }
    }

    }

case 3:
    {

    //////////////
    ////CLIENT////
    //////////////
    fstream fiC;
    fiC.open("clients.txt", fstream::app);
    cout << "***Bank System***";
/////////////////////////////////////
    fiC << endl;
    cout << "\nEnter Name: ";
    cin >> nC1;
    c1.set_name(nC1);
    fiC << "Name: " << nC1 << endl;
/////////////////////////////////////
    cout << "\nEnter Password: ";
    cin >> pC ;
/////////////////////////////////////
    cout << "\nEnter ID: ";
    cin >> iC;
    c1.set_id(iC);
    fiC << "ID: " <<iC<< endl;
/////////////////////////////////////
    cout << "\nEnter Balance: ";
    cin >> balC;
    c1.set_balance(balC);
    fiC << "Balance: " <<balC << endl;

/////////////////////////////////////
    while(choice != 5) {
        cout << "\n1)Deposit";
        cout << "\n2)Withdraw";
        cout << "\n3)Check Balance";
        cout << "\n4)Transfer";
        cout << "\n5)Exit";
        cout << "\nSelect any given option to proceed: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "\nEnter Amount: ";
                cin >> amC;
                c1.deposit(amC);
                cout << "Your Balance now is : "<<c1.get_balance();
                break;

            case 2:
                cout << "\nEnter Amount: ";
                cin >> amC;
                c1.withdraw(amC);
                cout << "Your Balance now is : " <<c1.get_balance();

                break;

            case 3:
                cout << "\nYour Current Balance: " << c1.get_balance();
                break;
            case 4:
                cout <<"nEnter Amount: ";
                cin >> amC;
                cout <<"nEnter the Name of The Account: ";
                cin >> nC2;
                c1.transfer_to(c2, amC);
                cout << "Your Balance now is : "<< c1.get_balance() <<endl;;
                cout << "Other Account Balance is: "<< c2.get_balance();;

            case 5:
                break;
            default:
                cout << "\nEnter Valid Option";
                break;
        }
    }
    fiC.close();
    }
     case 4:
         {
            break;
         }
   }

   }

    return 0;
}

