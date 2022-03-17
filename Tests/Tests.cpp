//
// Created by user on 28/03/2021.
//

#include "Tests.h"
#include <iostream>
#include <cassert>
#include <Dog.h>
#include <DogValidator.h>
#include <ValidationException.h>
#include "TestsDomain.h"
#include "TestsRepository.h"
#include "TestsService.h"
#include "TestsValidation.h"

using namespace std;

void Tests::runAllTests() {
    cout<<"Starting all tests...\n";
    this->runDomainTests();
    this->runValidationTests();
    this->runRepositoryTests();
    this->runServiceTests();
    cout<<"Finished all tests!\n";
}

void Tests::runDomainTests(){
    TestsDomain domainTests = TestsDomain();
    domainTests.runDomainTests();
}

void Tests::runValidationTests() {
    TestsValidation validationTests = TestsValidation();
    validationTests.runValidationTests();
}

void Tests::runRepositoryTests() {
    TestsRepository repositoryTests = TestsRepository();
    repositoryTests.runRepositoryTests();
}

void Tests::runServiceTests() {
    TestsService serviceTests = TestsService();
    serviceTests.runServiceTests();
}


