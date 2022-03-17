//
// Created by user on 28/03/2021.
//

#include "Console.h"

#include <iostream>
#include <ServiceException.h>
#include <ValidationException.h>
#include <RepositoryException.h>

using namespace std;

Console::Console(ServiceAdmin &serviceAdmin, ServiceUser &serviceUser):
serviceAdmin{serviceAdmin}, serviceUser{serviceUser} {

}

string Console::readMode() {
    string mode;
    cout<<"Mode(admin/user):";
    cin>>mode;
    return mode;
}

void Console::run() {
    bool chosen = false;
    while(!chosen)
    {
        string mode = readMode();
        if(mode == "user")
        {
            userMode();
            chosen = true;
        }
        else if(mode == "admin")
        {
            adminMode();
            chosen = true;
        }
        else
        {
            cout << "Wrong mode!\n";
            chosen = false;
        }
    }
}

void Console::adminMode() {
    cout<<"You are in admin mode!\n";
    bool done = false;
    while(!done){
        try{
            printMenuAdmin();
            string command = readCommand();
            if(command == "add")
            {
                addUI();
            }
            else if(command == "delete")
            {
                deleteUI();
            }
            else if(command == "update")
            {
                updateUI();
            }
            else if(command == "list")
            {
                listUI();
            }
            else if(command == "change")
            {
                userMode();
                done = true;
            }
            else if(command == "exit")
            {
                cout << "Goodbye!";
                done = true;
            }
            else
            {
                cout<<"Wrong command!\n";
            }
        }
        catch (RepositoryException &re) {
            cout << endl << re.getErrorMessage() << endl;
        }
        catch (ValidationException &ve) {
            cout << endl << ve.getErrorMessage() << endl;
        }
        catch (ServiceException &se) {
            cout << endl << se.getErrorMessage() << endl;
        }
    }
}

void Console::userMode() {
    cout<<"You are in user mode!\n";
    bool done = false;
    while(!done){
        printMenuUser();
        string command = readCommand();
        if(command == "dogs")
        {
            if(this->serviceAdmin.getLengthAllDogs() == 0){
                cout << "\nThere are no dogs left to be adopted!\n";
            }
            else{
                seeAllDogsOneByOne();
            }
        }
        else if(command == "filter")
        {
            if(this->serviceAdmin.getLengthAllDogs() == 0){
                cout << "\nThere are no dogs left to be adopted!\n";
            }
            else{
                seeFilteredDogsOneByOne();
            }
        }
        else if(command == "list")
        {
            seeAdoptionList();
        }
        else if(command == "display")
        {
            displayAdoptionList();
        }
        else if(command == "change")
        {
            adminMode();
            done = true;
        }
        else if(command == "exit")
        {
            cout << "Goodbye!";
            done = true;
        }
        else
        {
            cout<<"Wrong command!\n";
        }
    }

}

void Console::printMenuAdmin() {
    cout<<"What you can do:\n";
    cout<<"\t-> add  \t(add a new dog)\n";
    cout<<"\t-> delete \t(delete a dog)\n";
    cout<<"\t-> update \t(update the information of a dog)\n";
    cout<<"\t-> list \t(see all the added dogs)\n";
    cout<<"\t-> change \t(change the mode to user)\n";
    cout<<"\t-> exit \t(exit the application)\n";
}

void Console::printMenuUser() {
    cout<<"What you can do:\n";
    cout<<"\t-> dogs \t(see all the dogs)\n";
    cout<<"\t-> filter \t(see all the dogs of a given breed, having an age less than a given number)\n";
    cout<<"\t-> list \t(see the adoption list)\n";
    cout<<"\t-> display \t(see the adoption list in notepad - for csv, or in browser - for html)\n";
    cout<<"\t-> change \t(change the mode to admin)\n";
    cout<<"\t-> exit \t(exit the application)\n";
}

void Console::printMenuUserAdoption() {
    cout<<"\nWhat you can do:\n";
    cout<<"\t-> adopt \t(adopt the current dog)\n";
    cout<<"\t-> next \t(see the next available dog)\n";
    cout<<"\t-> exit \t(go back to main user menu)\n";
}

string Console::readCommand() {
    string command;
    cout<<"Command:";
    cin>>command;
    return command;
}

void Console::addUI() {
    string name;
    string breed;
    int age;
    string photo;
    cout<<"\nName:";
    cin>>name;
    cout<<"\nBreed:";
    cin>>breed;
    cout<<"\nAge:";
    if(!(cin>>age))
    {
        cout<<"Invalid numerical value!\n";
        cin.clear();
        cin.ignore(123, '\n');
        return;
    }
    cout<<"\nPhoto:";
    cin>>photo;
    this->serviceAdmin.addDog(breed, name, age, photo);
}

void Console::deleteUI() {
    string name;
    string breed;
    cout<<"\nName:";
    cin>>name;
    cout<<"\nBreed:";
    cin>>breed;
    this->serviceAdmin.deleteDog(breed, name);
}

void Console::updateUI() {
    string old_name;
    string old_breed;
    string name;
    string breed;
    int age = -1;
    string photo;
    string whatToChange;
    cout<<"\nOld name:";
    cin>>old_name;
    cout<<"\nOld breed:";
    cin>>old_breed;

    bool done = false;
    while (!done)
    {
        cout<<"\nWhat do you want to change? (breed/name/age/photo):";
        cin>>whatToChange;
        if(whatToChange == "name")
        {
            cout<<"\nNew name:";
            cin>>name;
        }
        if(whatToChange == "breed")
        {
            cout<<"\nNew breed:";
            cin>>breed;
        }
        if(whatToChange == "age")
        {
            cout<<"\nNew age:";
            if(!(cin>>age))
            {
                cout<<"Invalid numerical value!\n";
                cin.clear();
                cin.ignore(123, '\n');
                return;
            }
        }
        if(whatToChange == "photo")
        {
            cout<<"\nNew photo:";
            cin>>photo;
        }
        cout<<"\nDo you want to change anything else? (yes/no):";
        cin>>whatToChange;
        if(whatToChange == "yes")
            done = false;
        else if(whatToChange == "no")
            done = true;
    }

    this->serviceAdmin.updateDog(old_breed, old_name, breed, name, age, photo);
}

void Console::listUI() {
    for(int index=0; index < this->serviceAdmin.getLengthAllDogs(); index++)
        cout<<this->serviceAdmin.getAllDogs()[index]<<endl;
}

void Console::printDog(int index) {
    cout<<endl<<this->serviceAdmin.getAllDogs()[index];
    system(("start chrome " + this->serviceAdmin.getAllDogs()[index].getPhoto()).c_str());
}

void Console::printFilteredDog(int index, const string &breed, int age) {
    cout<<endl<<this->serviceAdmin.getFilteredDogs(breed, age)[index];
    system(("start chrome " + this->serviceAdmin.getFilteredDogs(breed, age)[index].getPhoto()).c_str());
}

void Console::seeAllDogsOneByOne() {
    bool done = false;
    int index = 0;
    while(!done){
        printDog(index);
        printMenuUserAdoption();
        string command = readCommand();
        if(command == "adopt")
        {
            addDogToAdoptList(this->serviceAdmin.getAllDogs()[index]);
            deleteDogFromList(this->serviceAdmin.getAllDogs()[index]);
            if(this->serviceAdmin.getLengthAllDogs() == 0)
            {
                done = true;
                cout << "There are no more dogs to be adopted!\nYou have been redirected to the user "
                        "main menu! Thank you for adopting!\n\n";
            }
        }
        else if(command == "next")
        {
            index++;
            if(index == this->serviceAdmin.getLengthAllDogs())
                index = 0;
        }
        else if(command == "exit")
        {
            done = true;
        }
        else
        {
            cout<<"Wrong command!\n";
        }
    }
}

void Console::seeFilteredDogsOneByOne() {
    bool done = false;
    int index = 0;
    string breed;
    int age;
    cout<<"\nBreed to filter by:";
    cin.ignore();
    getline(cin, breed);
    breed.c_str();
    cout<<"\nMaximum age:";
    if(!(cin>>age))
    {
        cout<<"Invalid numerical value!\n";
        cin.clear();
        cin.ignore(123, '\n');
        done = true;
    }
    while(!done){
        if(this->serviceAdmin.getFilteredDogs(breed, age).empty()){
            done = true;
            cout << "There are no dogs with the given criteria!\nYou have been redirected to the user "
                    "main menu!\n\n";
        }
        else{
            printFilteredDog(index, breed, age);
            printMenuUserAdoption();
            string command = readCommand();
            if(command == "adopt")
            {
                addDogToAdoptList(this->serviceAdmin.getFilteredDogs(breed, age)[index]);
                deleteDogFromList(this->serviceAdmin.getFilteredDogs(breed, age)[index]);
                if(this->serviceAdmin.getFilteredDogs(breed, age).empty())
                {
                    done = true;
                    cout << "Those were all the dogs with the given criteria!\nYou have been redirected to the user "
                            "main menu! Thank you for adopting!\n\n";
                }
            }
            else if(command == "next")
            {
                index++;
                if(index == this->serviceAdmin.getFilteredDogs(breed, age).size())
                    index = 0;
            }
            else if(command == "exit")
            {
                done = true;
            }
            else
            {
                cout<<"Wrong command!\n";
            }
        }
    }
}

void Console::seeAdoptionList() {
    for(int index=0; index < this->serviceUser.getLengthAllDogs(); index++)
        cout<<this->serviceUser.getAllDogs()[index];
}

void Console::addDogToAdoptList(Dog &dogToBeAdopted) {
    this->serviceUser.addDog(dogToBeAdopted.getBreed(), dogToBeAdopted.getName(), dogToBeAdopted.getAge(), dogToBeAdopted.getPhoto());
}

void Console::deleteDogFromList(Dog &dogToBeDeleted) {
    this->serviceAdmin.deleteDog(dogToBeDeleted.getBreed(), dogToBeDeleted.getName());
}

void Console::displayAdoptionList() {
    system(this->serviceUser.getDisplayCommand().c_str());
}

Console::~Console() = default;






