/* Experience 2 2018.10.17
   main.cpp for a car management system
   叶子繁 201730684427 */
// Headers
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "..\exp1-1\Llist.h"
using namespace std;

// Global variables
struct car      // Some information a car should have
{
    string brand;
    string model;
    string color;
    string carNum;
    string date;
};

Llist<car>* cars = new Llist<car>();        // The list of the cars
int select = -1;           // A variable for function select
enum selectFunction {BACK,NEW,FIND_AND_DISPLAY,DISPLAY_ALL,DELETE,CLEAR,MODIFY,READ_FROM_FILE,SAVE_TO_FILE};

void inserthelp(car c)      // Find a proper place and insert
{
    // If it is empty, directly insert.
    if(cars->isEmpty())
        cars->insert(c);
    else
    {
        cars->moveToStart();
        while(cars->currPos()<cars->length())
        {
            if(cars->getValue().carNum>c.carNum)            // Find the first node whose key is larger than the key of the car to be inserted.
            {
                cars->insert(c);
                return;
            }
            else
                cars->next();           // If still smaller, compare next;
        }
        cars->append(c);            // If all are smaller, insert at end.
    }
}

void newCar()           // Insert a record
{
    car c;
    system("cls");          // Clear the screen
    cout << endl << endl << endl << "             Please input the information for the new car." << endl;
    cout << endl << "             Brand: ";
    cin >> c.brand;
    cout << "             Model: ";
    cin >> c.model;
    cout << "             Color: ";
    cin >> c.color;
    cout << "             Car number: ";
    cin >> c.carNum;
    cout << "             Date: ";
    cin >> c.date;                  // Input some information
    inserthelp(c);                    // Insert the information
    cout << endl << "             Add succeeded. Press any button to continue..." << endl;
    cin.get();
    cin.get();
    return;
}

void display()          // Display some specific record
{
    string s;               // Search by key
    system("cls");
    cout << endl << endl << "             Enter the car number of the car that you wanna search:";          // Prompt the user to enter key
    cin >> s;

    // Find the record that matches the key
    cars->moveToStart();
    if(!cars->isEmpty())
    while(cars->currPos()<cars->length())
    {
        if(cars->getValue().carNum==s)  // If found, display it
        {
            cout << endl << "             " << left << setw(10) << "Found:" << endl;
            cout << "             " << left << setw(10) << "Number" << setw(10) << "Brand" << setw(10) << "Model" << setw(10) << "Color" << setw(10) << "Date" << endl;
            cout << "             " << left << setw(10) << cars->getValue().carNum << setw(10) << cars->getValue().brand <<
                    setw(10) << cars->getValue().model << setw(10) << cars->getValue().color << setw(10) << cars->getValue().date << endl;
            cout << endl << "             Press any button to continue..." << endl;
            cin.get();cin.get();
            return;
        }
        else    // else compare next
        {
            cars->next();
        }
    }
    // If not found......
    cout << "             Not found... Press any button to continue..." << endl;
    cin.get();cin.get();
}

void displayAll()   // Display all records in the list
{
    system("cls");
    if(cars->isEmpty())     // If list is empty
    {
        cout << endl << endl << "             No car is in the list" << endl;
        cin.get();cin.get();
    }
    else    // Display the records one by one
    {
        cars->moveToStart();

        // Display head
        cout << endl << endl << "             " << left << setw(10) << "All cars in the list is listed:" << endl << endl;
            cout << "             " << left << setw(10) << "Number" << setw(10) << "Brand" << setw(10) << "Model" << setw(10) << "Color" << setw(10) << "Date" << endl;
        while(cars->currPos()<cars->length())
        {
            cout << "             " << left << setw(10) << cars->getValue().carNum << setw(10) << cars->getValue().brand <<
                    setw(10) << cars->getValue().model << setw(10) << cars->getValue().color << setw(10) << cars->getValue().date << endl;
            cars->next();
        }
        cout << endl << "             Press any button to continue..." << endl;
        cin.get();cin.get();
    }
}

void deleteCar()        // A function to delete some specific record
{
    system("cls");
    if(!cars->isEmpty())
    {
        cars->moveToStart();
        //Display all the cars in the list
        cout << endl << endl << "             " << left << setw(10) << "All cars in the list is listed:" << endl << endl;
        cout << "             " << left << setw(10) << "Number" << setw(10) << "Brand" << setw(10) << "Model" << setw(10) << "Color" << setw(10) << "Date" << endl;
        while(cars->currPos()<cars->length())
            {
                cout << "             " << left << setw(10) << cars->getValue().carNum << setw(10) << cars->getValue().brand <<
                        setw(10) << cars->getValue().model << setw(10) << cars->getValue().color << setw(10) << cars->getValue().date << endl;
                cars->next();
            }

        //Deleting
        cout << endl << "             Enter the car number of the car you want to delete:";
        string s;
        cin >> s;
        cars->moveToStart();
        while(cars->currPos()<cars->length())       // Find the record that matches the key
        {
                if(cars->getValue().carNum==s)
                {
                    cars->remove();
                    cout << endl << "             Car " << s << " removed." << endl;
                    cout << endl << "             Press any button to continue..." << endl;
                    cin.get();cin.get();
                    return;
                }
                else
                {
                    cars->next();
                }
        }
        cout << endl << "             Not found... Press any button to continue..." << endl;
        cin.get();cin.get();
    }
    else        // If the list is empty
    {
        cout << endl << endl << "             No car is in the list... Press any button to continue..." << endl;
        cin.get();cin.get();
    }
}

void deleteAll()        // Delete all the records in the list
{
    system("cls");
    cout << endl << endl << "             This operation will clear all the record, continue? (y/n) ";  // Ask for confirmation
    char choice;
    cin >> choice;
    if(choice == 'y' || choice == 'Y')      // Confirmed
    {
        cars->clear();      // Reinitialize the list
        cout << endl << "             All records are deleted... Press any key to continue..." << endl;
        cin.get();cin.get();
        return;
    }               // Not confirmed
    cout << endl << "             Operation cancelled... Press any key to continue..." << endl;
    cin.get();cin.get();
    return;
}

void modify()       // Modify some specific record
{
    system("cls");
    string s;
    cout << endl << endl << "             Enter the car number of the car that you wanna modify:";      // Prompt the user to input the key value
    cin >> s;
    cars->moveToStart();
    if(!cars->isEmpty())        // If the list is not empty, traverse to look for the record
    while(cars->currPos()<cars->length())
    {
        if(cars->getValue().carNum==s)
        {
            cout << endl << "             " << left << setw(10) << "Here are the information of the car:" << endl;
            cout << "             " << left << setw(10) << "Number" << setw(10) << "Brand" << setw(10) << "Model" << setw(10) << "Color" << setw(10) << "Date" << endl;
            cout << "             " << left << setw(10) << cars->getValue().carNum << setw(10) << cars->getValue().brand <<
                    setw(10) << cars->getValue().model << setw(10) << cars->getValue().color << setw(10) << cars->getValue().date << endl << endl;
            cout << "             Please enter the modified information of this car: " << endl;
            car c;
            // Re-input the information
            cout << endl << "             Brand: ";
            cin >> c.brand;
            cout << "             Model: ";
            cin >> c.model;
            cout << "             Color: ";
            cin >> c.color;
            cout << "             Car number: ";
            cin >> c.carNum;
            cout << "             Date: ";
            cin >> c.date;
            cars->remove();         // Remove the former record
            cars->insert(c);           // Insert a modified record
            cout << endl << "             Successfully modified... Press any button to continue..." << endl;
            cin.get();cin.get();
            return;
        }
        else
        {
            cars->next();
        }
    }
    cout << endl << "             Not found... Press any button to continue..." << endl;        // If not found......
    cin.get();cin.get();
}

void read()             // Read the list from the file CarList.txt
{
    system("cls");
    ifstream in;            // An ifstream object
    in.open("CarList.txt",ios::in);     // Open the file
    if(in)      // If the file is opened successfully
    {
        cars->clear();          // Clear the data in the buffer
        string tmp;
        getline(in,tmp);
        while(!in.eof())            // While not end of file, read data to a temporary car struct and insert it.
        {
            car c;
            getline(in,c.carNum,' ');
            getline(in,c.brand,' ');
            getline(in,c.model,' ');
            getline(in,c.color,' ');
            getline(in,c.date);
            inserthelp(c);
        }
        cars->moveToStart();    //对已知bug“读取后出现一个空节点”进行删除
        cars->remove();
        cout << endl << endl << "             Successfully read from CarList.txt" << endl << endl;      // Some text output
        cout << "             Press any key to continue..." << endl;
        cin.get();cin.get();
    }
    else        // If the file can't be opened
    {
        cerr << endl << endl <<  "             Opening file failed..." << endl << endl;
        cout << "             Press any key to continue..." << endl;
        cin.get();cin.get();
    }
}

void save()         // Save the list in the memory to a file called CarList.txt
{
    system("cls");
    ofstream out;       // An ofstream object
    out.open("CarList.txt",ios::out);       // Open the file
    if(out)         // If the file is opened successfully
    {
        cars->moveToStart();
        out << "Number " <<"Brand " << "Model " << "Color " << "Date" << endl;      // Output head
        while(cars->currPos()<cars->length())       // Traverse the list to output it
        {
            car c;          // Read to a temporary struct
            c = cars->getValue();
            out << c.carNum << " " << c.brand << " " << c.model << " " << c.color << " " << c.date << endl;         // output to the file
            cars->next();       // Point curr to the next node
        }
        cout << endl << endl << endl << "             Successfully export the list to file CarList.txt" << endl << endl;
        cout << "             Press any key to continue..." << endl;
        cin.get();cin.get();
        return;
    }
    else        // If file cannot be opened
    {
        cerr << endl << endl << "             File could not be opened" << endl;
        return;
    }
}

void welcome()      // The welcome and function select screen
{
    while(select != 0)      // select initialize to be -1
    {
        system("cls");      // clear the screen
        cout << endl << endl << "             ----------Welcome to Cinkye's car management system----------       " << endl << endl;
        cout << "             Press number to select function:" << endl;
        cout << "             1 - Add a new car" << endl << "             2 - Display information for a certain car" << endl;
        cout << "             3 - Display all car information" << endl << "             4 - Delete a car" << endl << "             5 - Delete all the cars" << endl;
        cout << "             6 - Modify a car" << endl <<  "             7 - Read car data from file" << endl;
        cout << "             8 - Save car data to file" << endl <<  "             0 - Exit" << endl << endl;
        cout << right << setw(50) << "Select a function: ";
        cin >> select;      // Select a function
        switch(select)      // Choose a function according to the input
        {
            case BACK:
                break;
            case NEW:
            {
                newCar();
                break;
            }
            case FIND_AND_DISPLAY:
            {
                display();
                break;
            }
            case DISPLAY_ALL:
            {
                displayAll();
                break;
            }
            case DELETE:
            {
                deleteCar();
                break;
            }

            case CLEAR:
            {
                deleteAll();
                break;
            }
            case MODIFY:
            {
                modify();
                break;
            }
            case READ_FROM_FILE:
            {
                read();
                break;
            }
            case SAVE_TO_FILE:
            {
                save();
                break;
            }
            default:        // If the input is invalid...
            {
                    cout << endl << "             Invalid input... Press any key to re-enter..." << endl;
                    cin.get();cin.get();
                    select = 1;
            }
        }
    }
}

int main()
{
    system("mode con cols=87 lines=20");  //改变窗口宽高
    system("color 17"); //改变背景色和前景色
    welcome();
}
