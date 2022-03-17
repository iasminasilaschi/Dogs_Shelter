//
// Created by user on 29/03/2021.
//

#include <iostream>
#include <ValidationException.h>
#include "DogValidator.h"
using namespace std;

void DogValidator::validateAddOrUpdate(const Dog &doggo) {
    string error;
    if(doggo.getBreed().empty())
        error+="Invalid breed!\n";
    if(doggo.getName().empty())
        error+="Invalid name!\n";
    if(doggo.getAge() < 0 || doggo.getAge() > 29)
        error+="Invalid age!\n";
    if(doggo.getPhoto().empty() || doggo.getPhoto().length() < 9 || doggo.getPhoto().substr (0,8) != "https://")
        error+="Invalid photo!\n";
    if(!error.empty())
        throw ValidationException(error);
}

void DogValidator::validateDeleteOrToBeUpdated(const Dog &doggo) {
    string error;
    if(doggo.getBreed().empty())
        error+="Invalid breed!\n";
    if(doggo.getName().empty())
        error+="Invalid name!\n";
    if(!error.empty()){
        throw ValidationException(error);
    }
}