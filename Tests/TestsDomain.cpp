//
// Created by user on 29/03/2021.
//

#include <Dog.h>
#include "TestsDomain.h"
#include <cassert>
#include <iostream>

void TestsDomain::runDomainTests() {
    cout<<"Starting domain tests...\n";
    this->testImplicitConstructor();
    this->testExplicitConstructor();
    this->testGettersAndSetters();
    this->testCopy();
    this->testCopyConstructor();
    this->testEqualOperator();
    this->testToStringMethod();
    this->testEqualEqualOperator();
    cout<<"Finished domain tests!\n";
}

void TestsDomain::testImplicitConstructor() {
    Dog doggo{};
    assert(doggo.getBreed().empty());
    assert(doggo.getName().empty());
    assert(doggo.getAge() == -1);
    assert(doggo.getPhoto().empty());
}

void TestsDomain::testExplicitConstructor() {
    Dog doggo1{"Dachshund", "Pixie", 4, "https://idk"};
    assert(doggo1.getBreed() == "Dachshund");
    assert(doggo1.getName() == "Pixie");
    assert(doggo1.getAge() == 4);
    assert(doggo1.getPhoto() == "https://idk");
}

void TestsDomain::testGettersAndSetters() {
    Dog doggo{};
    doggo.setBreed("Bichon");
    doggo.setName("Toto");
    doggo.setAge(5);
    doggo.setPhoto("https://idk2");
    assert(doggo.getBreed() == "Bichon");
    assert(doggo.getName() == "Toto");
    assert(doggo.getAge() == 5);
    assert(doggo.getPhoto() == "https://idk2");
}

void TestsDomain::testCopy() {
    Dog doggo1{"Dachshund", "Pixie", 4, "https://idk"};
    Dog doggo2{doggo1}; //One way to make a copy of doggo1 in doggo2
    doggo1.setName("Cynthia");
    assert(doggo1.getBreed() == "Dachshund");
    assert(doggo1.getName() == "Cynthia");
    assert(doggo1.getAge() == 4);
    assert(doggo1.getPhoto() == "https://idk");
    assert(doggo2.getBreed() == "Dachshund");
    assert(doggo2.getName() == "Pixie");
    assert(doggo2.getAge() == 4);
    assert(doggo2.getPhoto() == "https://idk");
}

void TestsDomain::testCopyConstructor() {
    Dog doggo1{"Dachshund", "Pixie", 4, "https://idk"};
    Dog doggo2{doggo1}; //One way to make a copy of doggo1 in doggo2
    Dog doggo3 = doggo2; //Another way to make a copy of doggo1 in doggo2 (calling the copy-constructor "=")
    doggo2.setName("Cynthia");
    assert(doggo2.getBreed() == "Dachshund");
    assert(doggo2.getName() == "Cynthia");
    assert(doggo2.getAge() == 4);
    assert(doggo2.getPhoto() == "https://idk");
    assert(doggo3.getBreed() == "Dachshund");
    assert(doggo3.getName() == "Pixie");
    assert(doggo3.getAge() == 4);
    assert(doggo3.getPhoto() == "https://idk");
}

void TestsDomain::testEqualOperator() {
    Dog doggo1{"Dachshund", "Pixie", 4, "https://idk"};
    Dog doggo2{doggo1}; //One way to make a copy of doggo1 in doggo2
    Dog doggo3 = doggo2; //Another way to make a copy of doggo1 in doggo2 (calling the copy-constructor "=")
    Dog doggo4;
    doggo4 = doggo3; //We can also do it like this, but it does not call the copy-constructor ("=" operator)
    doggo3.setName("Cynthia");
    assert(doggo3.getBreed() == "Dachshund");
    assert(doggo3.getName() == "Cynthia");
    assert(doggo3.getAge() == 4);
    assert(doggo3.getPhoto() == "https://idk");
    assert(doggo4.getBreed() == "Dachshund");
    assert(doggo4.getName() == "Pixie");
    assert(doggo4.getAge() == 4);
    assert(doggo4.getPhoto() == "https://idk");
}

void TestsDomain::testToStringMethod() {
    Dog doggo{};
    doggo.setBreed("Bichon");
    doggo.setName("Toto");
    doggo.setAge(5);
    doggo.setPhoto("https://idk2");
    assert(doggo.toString() == "Dog \n\t breed: Bichon\n\t name: Toto\n\t age: 5\n\t photo: https://idk2\n");
}

void TestsDomain::testEqualEqualOperator() {
    Dog doggo1{"Dachshund", "Pixie", 4, "https://idk"};
    Dog doggo2{"Dachshund", "Pixie", 5, "https://idk2"};
    assert(doggo1 == doggo2);
}
