/* this is a fruit juice machine project. This program does the following things:
    1. show the customer different items sold by the Machine
    2. let the customer make the selection
    3. show the cost of the selected item to the customer
    4. Accept money from the customer
    5. release the product
*/

/*---------------Two main components----------------
  1. Cash Register
  2. Dispenser
*/
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

/* This is cashRegister Class
   -> it has some cash in hand
   -> takes cash from customer
   -> show amount of money in hand at any instant to owner
*/
class cashRegister{
    int cashOnHand;//for storing the cash in reguster
    public:
    int getCurrentBalance() const;
    void acceptAmount(int);
    cashRegister();
    cashRegister(int);
};
int cashRegister::getCurrentBalance() const{
    return cashOnHand;
}

void cashRegister::acceptAmount(int amountIn){
    cashOnHand = cashOnHand+amountIn;
} 
cashRegister::cashRegister() {
    cashOnHand = 500;
}

cashRegister::cashRegister(int cashIn) {
    if(cashIn>=0)
      cashOnHand = cashIn;
    else
      cashOnHand = 500;
}
 
/* This is the Dispenser Class
  ->The dispenser releases the selected item if it is not empty.
  ->The dispenser should show the number of items in the dispenser and the cost of the item
*/
 class dispenserType{
     int numberOfItems;
     int cost;

     public:
     int getNoOfItems() const;
     int getCost() const;
     void makeSale();
     dispenserType();
     dispenserType(int setNoOfItems, int setCost);
 };
    
int dispenserType::getNoOfItems() const{
    return numberOfItems;
}

int dispenserType::getCost() const{
    return cost;
}

void dispenserType::makeSale(){
    numberOfItems--;
}
dispenserType::dispenserType(){
    numberOfItems = 50;
    cost = 50;
}

dispenserType::dispenserType(int setNoOfItems, int setCost){
    if(setNoOfItems>=0)
       numberOfItems = setNoOfItems;
    else
       numberOfItems = 50;
    if(setCost>=0)
       cost = setCost;
    else
       cost = 50;
}

void showSelection(){
    cout<<endl;
    cout<<"============================================================"<<endl;
    cout<<"+++++++++++++++ WELCOME TO RIYA'S JUICE SHOP +++++++++++++++"<<endl;
    cout<<"============================================================"<<endl<<endl;
    cout<<"Select your Juice"<<endl;
    cout<<"1. Apple Juice"<<endl<<
          "2. Orange Juice"<<endl<<
          "3. Mango Juice"<<endl<<
          "4. Mixed Juice"<<endl<<
          "5. Cash In Hand"<<endl<<
          "6. Items Check"<<endl<<
          "9. Exit"<<endl;

}

void sellProduct(dispenserType &product, cashRegister &pCounter ){
    int amount, amount2;
    if(product.getNoOfItems()>0){
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Please Deposit Amount: "<<product.getCost()<<" Rupees"<<endl;
        cin>>amount;
        if(product.getCost()>amount){
            cout<<"Kindly deposit more "<<product.getCost()-amount<<" Rupees"<<endl;
            cin>>amount2;
            amount = amount+amount2;
        }
        if(product.getCost() == amount){
            cout<<"=========================================================="<<endl;
            pCounter.acceptAmount(amount);
            product.makeSale();
            cout<<"Collect Yout JUICE & Enjoy"<<endl;
            cout<<"==========================================================="<<endl;
        }
        else if(product.getCost() < amount){
            pCounter.acceptAmount(amount);
            product.makeSale();
            cout<<"Collect Yout JUICE & Enjoy"<<endl;
            cout<<"----------------------------------------------------------"<<endl;
            cout<<"Collect your "<<amount-product.getCost()<<" extra Rupees"<<endl;
            cout<<"=============================================================="<<endl;
        }
        else
            cout<<"----------------------------------------------------"<<endl<<
                  "Amount not enough to enjoy the Juice Drink"<<endl<<
                  "Collect your deposited cash"<<endl<<
                  "----------------------------------------------------"<<endl;
    }
        
    else{
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Sorry !!!! Item Not Available!!!!!!!!!!"<<endl;
        cout<<"----------------------------------------------------"<<endl;
    }
}

int main(){
    cashRegister counter;
    dispenserType appleJuice(100, 50);
    dispenserType orangeJuice(100, 65);
    dispenserType mangoLassi(75, 45);
    dispenserType mixed(100, 85);
    int choice; 
    char item;
    showSelection();
    cin >> choice;
    while (choice != 9)
    {
    switch (choice)
    {
        case 1:
        sellProduct(appleJuice, counter);
        break;
        case 2:
        sellProduct(orangeJuice, counter);
        break;
        case 3:
        sellProduct(mangoLassi, counter);
        break;
        case 4:
        sellProduct(mixed, counter);
        break;
        case 5:
        cout<<"Current Balance is "<<counter.getCurrentBalance()<<endl;
        break;
        case 6:
        cout<<"Enter item number: "<<endl<<" a. apple juice \n b. orange juice \n c. Mango Juice\n d. Mixed"<<endl;
        cin>>item;
        switch (item)
        {
        case 'a':
            cout<<"Items Remaining "<<appleJuice.getNoOfItems()<<endl; 
            break;
        case 'b':
            cout<<"Items Remaining "<<orangeJuice.getNoOfItems()<<endl;
            break;
        case 'c':
            cout<<"Items Remaining "<<mangoLassi.getNoOfItems()<<endl;
            break;
        case 'd':
            cout<<"Items Remaining "<<mixed.getNoOfItems()<<endl;
            break;
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }
        break;

        default:
        cout << "Invalid selection." << endl;
    }
    cout<<"Press any key to continue----!!!!"<<endl;
    getch();
    system("CLS");
    showSelection();
cin >> choice;
}
    
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n"<<endl;
    cout<<"\t\t\t\t\t=+=+=+=+=+ HAVE A GOOD DAY =+=+=+=+=+"<<endl;
    cout<<"\n\n\n\t\t\t\t\t----------THANK YOU FOR YOUR VISIT----------"<<endl;
    return 0;
}