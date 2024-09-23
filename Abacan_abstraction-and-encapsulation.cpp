#include <iostream>  
#include <string>  
#include <iomanip>  
using namespace std;  

//This code is made by Abacan, Lorenz Althea
//Goal Bank Account

class CurrentAccount{
private:
	double balance = 0;

public:
    
    void menu();

    void deposit();
    void withdraw();
    void getBalance();
};

class SavingsAccount{
private:
	double balance = 1000;

public:
    
    void menu();

    void deposit();
    void withdraw();
    void getBalance();
};

class MainMenu : public SavingsAccount, CurrentAccount{
private:
	int selection;
	bool loop;
	SavingsAccount saving;
	CurrentAccount current;

public:
	void setChoice();
	void startMain();
	void setRepeat();

	int getChoice();
	bool getRepeat();
};

void MainMenu::setRepeat(){
    int temp = 0;
    
    do{
    cout<<"\nAre you sure you want to leave the program?"<<endl
        <<"1 - Yes"<<endl
        <<"2 - No"<<endl
        <<"Select an option: ";
        
        cin>>temp;
    
    }while(temp >= 3 && temp <= 0);
    
    if(temp == 1)
        this->loop = false;
    else
        this->loop = true;
    cout<<endl;
}
        
int MainMenu::getChoice(){
    return selection;
}

bool MainMenu::getRepeat(){
    return loop;
}

void MainMenu::setChoice(){
    int temp;
    
    do{
        cout<<"Main Menu"<<endl
            <<"1 - Savings Account"<<endl 
            <<"2 - Current Account"<<endl
            <<"3 - Exit" <<endl
            <<"Select an option: ";  
        cin>>temp;
        
        if(temp >= 4 || temp <= 0){
            cout<<"Invalid input... try selecting from the options provided"<<endl<<endl;
        }
    }while(temp >= 4 || temp <= 0);
    
    this->selection = temp;
}

void MainMenu::startMain(){
        do{
            setChoice();
            
            switch(selection){
                case 1:
                    saving.menu();
                    loop = true;
                    break;
                case 2:
                    current.menu();
                    loop = true;
                    break;
                case 3:
                    setRepeat();
                    break;
            }
            
        }while(loop == true);
}

void CurrentAccount::menu(){
    int choice;
    bool repeat = true;
    do{
        do{
            cout<<"\nSub Menu - Current Account"<<endl
                <<"1 - Deposit"<<endl
                <<"2 - Withdraw"<<endl
                <<"3 - Check Balance"<<endl
                <<"4 - Back"<<endl 
                <<"Select an option: ";
            
            cin>>choice;
                
            if(choice >= 5 || choice <= 0)
                cout<<"Invalid input... try selecting from the options provided"<<endl<<endl;
                
        }while(choice >= 5 || choice <= 0);
        
        switch(choice){
            case 1:
                deposit();
                break;
            
            case 2:
                withdraw();
                break;
            
            case 3:
                getBalance();
                break;
            
            case 4:
                repeat = false;
                break;
        }
    }while(repeat == true);
    cout<<endl;
}

void CurrentAccount::deposit(){
    double temp;
    do{
        cout<<"Enter the amount to deposit: ";
        cin>>temp;
        
        if(temp < 0)
            cout<<"You cannot deposit a negative value... try inputting a positive number instead"<<endl;
    
    }while(temp < 0);
    
    this->balance = this->balance + temp;
    
    cout<<"Deposit has been made"<<endl<<endl;
}

void CurrentAccount::withdraw(){
    double temp;
    do{
        cout<<"Enter the amount to withdraw: ";
        cin>> temp;
        
        if(temp < 0)
            cout<<"You cannot withdraw a negative value... try inputting a positive number instead"<<endl;
        else if(this->balance - temp < 0)
            cout<<"You cannot withdraw more than your balance... try inputting less"<<endl;
            
    }while(temp < 0 || this->balance - temp < 0);
    
    this->balance = balance - temp;
    cout<<"Withdraw complete"<<endl<<endl;
}

void CurrentAccount::getBalance(){
    cout<<"Your current account has a balance of "<<fixed<<setprecision(2)<<balance<<endl<<endl;
}

void SavingsAccount::menu(){
    int choice;
    bool repeat = true;
    do{
        do{
            cout<<"\nSub Menu - Savings Account"<<endl
                <<"1 - Deposit"<<endl
                <<"2 - Withdraw"<<endl
                <<"3 - Check Balance"<<endl
                <<"4 - Back"<<endl 
                <<"Select an option: ";
            
            cin>>choice;
                
            if(choice >= 5 || choice <= 0)
                cout<<"Invalid input... try selecting from the options provided"<<endl<<endl;
                
        }while(choice >= 5 || choice <= 0);
        
        switch(choice){
            case 1:
                deposit();
                break;
            
            case 2:
                withdraw();
                break;
            
            case 3:
                getBalance();
                break;
            
            case 4:
                repeat = false;
                break;
        }
    }while(repeat == true);
    cout<<endl;
}

void SavingsAccount::deposit(){
    double temp;
    do{
        cout<<"Enter the amount to deposit: ";
        cin>>temp;
        
        if(temp < 0)
            cout<<"You cannot deposit a negative value... try inputting a positive number instead"<<endl;
    
    }while(temp < 0);
    
    this->balance = this->balance + temp;
    
    cout<<"Deposit has been made"<<endl<<endl;
}

void SavingsAccount::withdraw(){
    double temp;
    do{
        cout<<"Enter the amount to withdraw: ";
        cin>> temp;
        
        if(temp < 0)
            cout<<"You cannot withdraw a negative value... try inputting a positive number instead"<<endl;
        else if(this->balance - temp < 1000)
            cout<<"You must maintain a balance of 1000 in your savings account... try inputting less"<<endl;
            
    }while(temp < 0 || this->balance - temp < 1000);
    
    this->balance = balance - temp;
    cout<<"Withdraw complete"<<endl<<endl;
}

void SavingsAccount::getBalance(){
    cout<<"Your savings account has a balance of "<<fixed<<setprecision(2)<<balance<<endl<<endl;
}

int main(){
    MainMenu case1;
    
    case1.startMain();
    
    return 0;  
}