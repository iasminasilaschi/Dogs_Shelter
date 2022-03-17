//
// Created by user on 29/03/2021.
//

using namespace std;
#include "TestsValidation.h"
#include <iostream>
#include <cassert>
#include <Dog.h>
#include <DogValidator.h>
#include <ValidationException.h>

void TestsValidation::runValidationTests() {
    cout<<"Starting validation tests...\n";

    Dog doggo1{"Beagle", "Mary", 2, "https://idk3"};
    DogValidator::validateAddOrUpdate(doggo1);
    Dog doggo2{"", "", -2, ""};
    try{
        DogValidator::validateAddOrUpdate(doggo2);
    }
    catch(const ValidationException &ve){
        assert(ve.getErrorMessage() == "Invalid breed!\nInvalid name!\nInvalid age!\nInvalid photo!\n");
    }

    cout<<"Finished validation tests!\n";
}
