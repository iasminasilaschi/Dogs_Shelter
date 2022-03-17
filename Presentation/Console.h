//
// Created by user on 28/03/2021.
//

#ifndef A45_916_SILASCHI_IASMINA_CONSOLE_H
#define A45_916_SILASCHI_IASMINA_CONSOLE_H

#include <iostream>
#include <ServiceAdmin.h>
#include <ServiceUser.h>

using namespace std;

class Console {
private:
    ServiceAdmin &serviceAdmin;
    ServiceUser &serviceUser;

    static string readMode();
    void adminMode();
    void userMode();
    static void printMenuAdmin();
    static void printMenuUser();
    static string readCommand();
    void addUI();
    void deleteUI();
    void updateUI();
    void listUI();
    static void printMenuUserAdoption();
    void seeAllDogsOneByOne();
    void seeFilteredDogsOneByOne();
    void seeAdoptionList();
    void printDog(int index);
    void printFilteredDog(int index, const string &breed, int age);
    void addDogToAdoptList(Dog &dogToBeAdopted);
    void deleteDogFromList(Dog &dogToBeDeleted);
    void displayAdoptionList();

public:
    Console(ServiceAdmin &serviceAdmin, ServiceUser &serviceUser);
    void run();
    ~Console();
};


#endif //A45_916_SILASCHI_IASMINA_CONSOLE_H
