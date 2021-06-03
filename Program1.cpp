#include<bits/stdc++.h>

using namespace std;

int main(){

    float inch, yard, foot;
    cout<<"------------CHOICES--------------------"<<endl;
    cout<<"1. Inch to Foot"<<endl;
    cout<<"2. Inch to Yard"<<endl;
    cout<<"3. Foot to Inch"<<endl;
    cout<<"4. Foot to yard"<<endl;
    cout<<"5. Yard to Inch"<<endl;
    cout<<"6. Yard to Foot"<<endl;
    cout<<"7. Exit"<<endl;
    int choice;
    cout<<"Conversion Type: ";
    cin>>choice;

    while (choice != 7){
        switch (choice)
        {
        case 1:
            cout<<"Enter Inch: ";
            cin>>inch;
            foot = inch/12;
            cout<<"Foot: "<<foot<<endl;
            break;
        
        case 2:
            cout<<"Enter Inch: ";
            cin>>inch;
            yard = inch/36;
            cout<<"Yard: "<<yard<<endl;
            break;
        case 3:
            cout<<"Enter foot: ";
            cin>>foot;
            inch = foot * 12;
            cout<<"Inch: "<<inch<<endl;
            break;
        case 4:
            cout<<"Enter foot: ";
            cin>>foot;
            yard = foot/3;
            cout<<"Yard: "<<yard<<endl;
            break;
        case 5:
            cout<<"Enter yard: ";
            cin>>yard;
            inch = yard * 36;
            cout<<"Inch: "<<inch<<endl;
            break;
        case 6:
            cout<<"Enter yard: ";
            cin>>yard;
            foot  = 3 * yard;
            cout<<"Foot: "<<foot<<endl;
            break;
        case 7:
            exit(0);
            break;
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }

        cout<<"Conversion Type ";
        cin>>choice;   
    }
    return 0;
}