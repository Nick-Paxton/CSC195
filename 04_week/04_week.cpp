
#include <iostream>
#include "MyInput.h"
#include "Animal.h"
#include "Database.h"
using namespace std;

int main()
{
    MyInput input; //Stack
    std::unique_ptr<Animal> animal;
    Database db;

    cout << "\n 04_week Hello World!\n";

    int iMenu = 0;
    int iTemp = 0;
    string inputName = "";

    while (iMenu != 6) {
        cout << "\n\n Enter Menu option: ";
        cout << "\n 1) Create Animal";
        cout << "\n 2) Display All";
        cout << "\n 3) Display by Name";
        cout << "\n 4) Display by Type";
        cout << "\n 5) ";
        cout << "\n 6) Quit\n";
        iMenu = input.GetUserInt(1, 6);

        switch (iMenu) {
        case 1: // Create a Bird/Fish
            cout << "\n Enter Animal Type: ";
            cout << "\n 1) Bird";
            cout << "\n 2) Fish";

            iTemp = input.GetUserInt(1,2);
            switch (iTemp) {
            case 1: // Create a Bird
                animal = db.Create(Animal::eType::Bird);
                break;
            case 2: // Create a Fish
                animal = db.Create(Animal::eType::Fish);
                break;
            } // Inner Switch
            animal->Read(cout, cin);
            animal->Write(cout);
            db.Add(animal);
            break; // Break create Bird/Fish

        case 2: // Display all records <- Animals
            db.DisplayAll(cout);
            break;
        
        case 3: // call method with cout (stream) and string (name)
            cout << "\n Enter Animal Name To Search: ";
            cin >> inputName;
            db.Display(cout, inputName);
            break;

        case 4: // call method with cout (stream) and type
            cout << "\n Enter Animal Type: ";
            cout << "\n 1) Bird";
            cout << "\n 2) Fish";

            iTemp = input.GetUserInt(1, 2);
            switch (iTemp) {
            case 1: // Display Birds
                db.Display(cout, Animal::eType::Bird);
                break;
            case 2: // Display Fish
                db.Display(cout, Animal::eType::Fish);
                break;
            }
            break;
        } // Outer Switch

    } // While
}