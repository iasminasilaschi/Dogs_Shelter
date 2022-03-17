//
// Created by user on 29/03/2021.
//

#include <ServiceAdmin.h>
#include <cassert>
#include <iostream>
#include <ValidationException.h>
#include <ServiceException.h>
#include <ServiceUser.h>
#include "TestsService.h"

void TestsService::runServiceTests() {
    cout<<"Starting serviceAdmin tests...\n";
    this->testAddDog();
    this->testAddDogUser();
    this->testDeleteDog();
    this->testUpdateDog();
    this->testGetAllDogs();
    this->testGetAllDogsUser();
    this->testGetLengthAllDogs();
    this->testAdd10Entries();
    this->testGetFilteredDogs();
    cout<<"Finished serviceAdmin tests!\n";
}

void TestsService::testAddDog() {
    Repository repo = Repository();
    ServiceAdmin service = ServiceAdmin{repo};
    try{
        service.addDog("", "", -1, "");
    }
    catch(const ValidationException &ve){
        assert(ve.getErrorMessage() == "Invalid breed!\nInvalid name!\nInvalid age!\nInvalid photo!\n");
    }
    assert(service.getLengthAllDogs() == 0);
    service.addDog("Dachshund", "Pixie", 4, "https://idk");
    assert(service.getLengthAllDogs() == 1);
    try{
        service.addDog("Dachshund", "Pixie", 3, "https://idk2");
    }
    catch(const ServiceException &se){
        assert(se.getErrorMessage() == "The dog with this breed and name already exists!\n");
    }
}

void TestsService::testAddDogUser() {
    Repository repo = Repository();
    ServiceUser service = ServiceUser{repo};
    try{
        service.addDog("", "", -1, "");
    }
    catch(const ValidationException &ve){
        assert(ve.getErrorMessage() == "Invalid breed!\nInvalid name!\nInvalid age!\nInvalid photo!\n");
    }
    assert(service.getLengthAllDogs() == 0);
    service.addDog("Dachshund", "Pixie", 4, "https://idk");
    assert(service.getLengthAllDogs() == 1);
    try{
        service.addDog("Dachshund", "Pixie", 3, "https://idk2");
    }
    catch(const ServiceException &se){
        assert(se.getErrorMessage() == "The dog with this breed and name already exists!\n");
    }
}

void TestsService::testDeleteDog() {
    Repository repo = Repository();
    ServiceAdmin service = ServiceAdmin{repo};
    assert(service.getLengthAllDogs() == 0);
    service.addDog("Dachshund", "Pixie", 4, "https://idk");
    service.addDog("Bichon", "Toto", 5, "https://idk2");
    service.addDog("Pug", "Alfie", 2, "https://idk3");
    service.addDog("Beagle", "Charlie", 3, "https://idk4");
    assert(service.getLengthAllDogs() == 4);
    service.deleteDog("Dachshund", "Pixie");
    assert(service.getLengthAllDogs() == 3);
    assert(service.getAllDogs()[0] == Dog("Bichon", "Toto",  4, "https://idk"));
    service.deleteDog("Beagle", "Charlie");
    assert(service.getLengthAllDogs() == 2);
    service.deleteDog("Bichon", "Toto");
    service.deleteDog("Pug", "Alfie");
    assert(service.getLengthAllDogs() == 0);
    try{
        service.deleteDog("Dachshund", "Pixie");
    }
    catch(const ServiceException &se){
        assert(se.getErrorMessage() == "This dog does not exist!\n");
    }
    try{
        service.deleteDog("", "");
    }
    catch(const ValidationException &ve){
        assert(ve.getErrorMessage() == "Invalid breed!\nInvalid name!\n");
    }
}

void TestsService::testUpdateDog() {
    Repository repo = Repository();
    ServiceAdmin service = ServiceAdmin{repo};
    service.addDog("Dachshund", "Pixie", 4, "https://idk");
    service.addDog("Bichon", "Toto", 5, "https://idk2");
    service.addDog("Pug", "Alfie", 2, "https://idk3");
    service.addDog("Beagle", "Charlie", 3, "https://idk4");
    service.updateDog("Dachshund", "Pixie", "", "Cynthia", -1, "");
    assert(service.getAllDogs()[0].getName() == "Cynthia");
    service.updateDog("Bichon", "Toto", "Terrier", "", -1, "");
    assert(service.getAllDogs()[1].getBreed() == "Terrier");
    service.updateDog("Pug", "Alfie", "", "", 6, "");
    assert(service.getAllDogs()[2].getAge() == 6);
    service.updateDog("Beagle", "Charlie", "", "", -1, "https://idk4");
    assert(service.getAllDogs()[3].getPhoto() == "https://idk4");

    try{
        service.updateDog("", "", "", "Terrier", -1, "");
    }
    catch(const ValidationException &ve){
        assert(ve.getErrorMessage() == "Invalid breed!\nInvalid name!\n");
    }

    try{
        service.updateDog("Pug", "Alfie", "", "", -5, "");
    }
    catch(const ValidationException &ve){
        assert(ve.getErrorMessage() == "Invalid age!\n");
    }

    try{
        service.updateDog("Kitty", "Cat", "", "", -1, "");
    }
    catch(const ServiceException &se){
        assert(se.getErrorMessage() == "This dog does not exist!\n");
    }
}

void TestsService::testGetAllDogs() {
    Repository repo;
    ServiceAdmin service = ServiceAdmin{repo};
    assert(repo.getElements() == service.getAllDogs());
    service.addDog("Dachshund", "Pixie", 4, "https://idk");
    service.addDog("Bichon", "Toto", 5, "https://idk2");
    service.addDog("Pug", "Alfie", 2, "https://idk3");
    assert(repo.getElements() == service.getAllDogs());
    assert(repo.getElements()[0] == service.getAllDogs()[0]);
    assert(repo.getElements()[1] == service.getAllDogs()[1]);
    assert(repo.getElements()[2] == service.getAllDogs()[2]);
}

void TestsService::testGetAllDogsUser() {
    Repository repo;
    ServiceUser service = ServiceUser{repo};
    assert(repo.getElements() == service.getAllDogs());
    service.addDog("Dachshund", "Pixie", 4, "https://idk");
    service.addDog("Bichon", "Toto", 5, "https://idk2");
    service.addDog("Pug", "Alfie", 2, "https://idk3");
    assert(repo.getElements() == service.getAllDogs());
    assert(repo.getElements()[0] == service.getAllDogs()[0]);
    assert(repo.getElements()[1] == service.getAllDogs()[1]);
    assert(repo.getElements()[2] == service.getAllDogs()[2]);
}

void TestsService::testGetLengthAllDogs() {
    Repository repo = Repository();
    ServiceAdmin service = ServiceAdmin{repo};
    assert(repo.getSize() == service.getLengthAllDogs());
    service.addDog("Dachshund", "Pixie", 4, "https://idk");
    service.addDog("Bichon", "Toto", 5, "https://idk2");
    service.addDog("Pug", "Alfie", 2, "https://idk3");
    assert(repo.getSize() == service.getLengthAllDogs());
}

void TestsService::testAdd10Entries() {
    Repository repo = Repository();
    ServiceAdmin service = ServiceAdmin{repo};
    assert(service.getLengthAllDogs() == 0);
    service.add10Entries();
    assert(service.getLengthAllDogs() == 10);
}

void TestsService::testGetFilteredDogs() {
    Repository repo = Repository();
    ServiceAdmin service = ServiceAdmin{repo};
    service.addDog("Dachshund", "Pixie", 4, "https://idk");
    service.addDog("Bichon", "Toto", 5, "https://idk2");
    service.addDog("Pug", "Alfie", 2, "https://idk3");
    Dog doggo1 = Dog{"Pug", "Alfie", 2, "https://idk3"};
    assert(service.getFilteredDogs("Pug", 10)[0] == doggo1);
}