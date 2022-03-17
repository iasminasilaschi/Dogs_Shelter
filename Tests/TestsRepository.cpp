//
// Created by user on 29/03/2021.
//

using namespace std;
#include "TestsRepository.h"
#include <iostream>
#include <cassert>
#include <Repository.h>
#include <RepositoryException.h>

void TestsRepository::runRepositoryTests() {
    cout<<"Starting repository tests...\n";
    this->testSearchByNameAndBreed();
    this->testAddElement();
    this->testDeleteElement();
    this->testUpdateElement();
    this->testGetSize();
    this->testGetElements();
    cout<<"Finished repository tests!\n";
}

void TestsRepository::testSearchByNameAndBreed()
{
    Repository repo;
    Dog doggo1{"Dachshund", "Pixie", 4, "https://idk"};
    assert(repo.getSize() == 0);
    repo.addElement(doggo1);
    assert(repo.getSize() == 1);
    Dog doggoToSearchFor{"Dachshund", "Pixie", -1, ""};
    int findDoggoPos = repo.searchByNameAndBreed(doggoToSearchFor);
    assert(repo.getElements()[findDoggoPos] == doggo1);
    assert(findDoggoPos == 0);
    Dog doggoToSearchForNonexistent{"Kitty", "Cat", -1, ""};
    int findNonexistentDoggoPos = repo.searchByNameAndBreed(doggoToSearchForNonexistent);
    assert(findNonexistentDoggoPos == -1);
}

void TestsRepository::testAddElement()
{
    Repository repo;
    Dog doggo1{"Dachshund", "Pixie", 4, "https://idk"};
    assert(repo.getSize() == 0);
    repo.addElement(doggo1);
    assert(repo.getSize() == 1);
    assert(repo.getElements()[0] == doggo1);
    try{
        repo.addElement(doggo1);
    }
    catch(const RepositoryException &re){
        assert(re.getErrorMessage() == "Element already in repo!\n");
    }
}

void TestsRepository::testDeleteElement()
{
    Repository repo;
    Dog doggo1{"Dachshund", "Pixie", 4, "https://idk"};
    Dog doggo2{"Bichon", "Toto", 5, "https://idk2"};
    Dog doggo3{"Pug", "Alfie", 2, "https://idk3"};
    assert(repo.getSize() == 0);
    repo.addElement(doggo1);
    repo.addElement(doggo2);
    repo.addElement(doggo3);
    assert(repo.getSize() == 3);
    repo.deleteElement(doggo1);
    assert(repo.getSize() == 2);
    assert(repo.getElements()[0] == doggo2);
    repo.deleteElement(doggo3);
    assert(repo.getSize() == 1);
    assert(repo.getElements()[0] == doggo2);
    repo.deleteElement(doggo2);
    assert(repo.getSize() == 0);
    try{
        repo.deleteElement(doggo1);
    }
    catch(const RepositoryException &re){
        assert(re.getErrorMessage() == "Element not in repo!\n");
    }
}

void TestsRepository::testUpdateElement()
{
    Repository repo;
    Dog doggo1{"Dachshund", "Pixie", 4, "https://idk"};
    Dog doggo2{"Bichon", "Toto", 5, "https://idk2"};
    Dog doggo3{"Pug", "Alfie", 2, "https://idk3"};
    assert(repo.getSize() == 0);
    repo.addElement(doggo1);
    assert(repo.getSize() == 1);
    assert(repo.getElements()[0] == doggo1);
    assert(repo.getElements()[0].getBreed() == "Dachshund");
    assert(repo.getElements()[0].getName() == "Pixie");
    assert(repo.getElements()[0].getAge() == 4);
    assert(repo.getElements()[0].getPhoto() == "https://idk");
    repo.updateElement(doggo1, doggo2);
    assert(repo.getElements()[0].getBreed() == "Bichon");
    assert(repo.getElements()[0].getName() == "Toto");
    assert(repo.getElements()[0].getAge() == 5);
    assert(repo.getElements()[0].getPhoto() == "https://idk2");
    try{
        repo.updateElement(doggo3, doggo1);
    }
    catch(const RepositoryException &re){
        assert(re.getErrorMessage() == "Element not in repo!\n");
    }
}

void TestsRepository::testGetSize() {
    Repository repo;
    assert(repo.getSize() == 0);
    Dog doggo1{"Dachshund", "Pixie", 4, "https://idk"};
    repo.addElement(doggo1);
    assert(repo.getSize() == 1);
    repo.deleteElement(doggo1);
    assert(repo.getSize() == 0);
}

void TestsRepository::testGetElements() {
    Repository repo;
    Dog doggo1{"Dachshund", "Pixie", 4, "https://idk"};
    Dog doggo2{"Bichon", "Toto", 5, "https://idk2"};
    Dog doggo3{"Pug", "Alfie", 2, "https://idk3"};
    assert(repo.getSize() == 0);
    repo.addElement(doggo1);
    repo.addElement(doggo2);
    repo.addElement(doggo3);
    assert(repo.getSize() == 3);
    int findDoggo1Pos = repo.searchByNameAndBreed(doggo1);
    int findDoggo2Pos = repo.searchByNameAndBreed(doggo2);
    int findDoggo3Pos = repo.searchByNameAndBreed(doggo3);
    assert(repo.getElements()[findDoggo1Pos] == doggo1);
    assert(repo.getElements()[findDoggo2Pos] == doggo2);
    assert(repo.getElements()[findDoggo3Pos] == doggo3);
}
