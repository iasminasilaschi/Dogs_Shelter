//
// Created by user on 22/03/2021.
//

#include "Repository.h"
#include <RepositoryException.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

Repository::Repository() {
    this->dynamicVector = vector<TElement>();
}

int Repository::searchByNameAndBreed(const TElement& dog)
{
    auto it = std::find(this->dynamicVector.begin(),this->dynamicVector.end(), dog);
    if (it == this->dynamicVector.end())
        return -1;
    return distance(this->dynamicVector.begin(), it);
}

void Repository::addElement(const TElement& dog)
{
    int positionOfDog = this->searchByNameAndBreed(dog);
    if (positionOfDog != -1)
    {
        throw RepositoryException("Element already in repo!\n");
    }
    this->dynamicVector.push_back(dog);
}

TElement Repository::deleteElement(const TElement& dog)
{
    int positionOfDog = this->searchByNameAndBreed(dog);
    if (positionOfDog == -1)
    {
        throw RepositoryException("Element not in repo!\n");
    }
    TElement deletedElement = this->dynamicVector[positionOfDog];
    this->dynamicVector.erase(this->dynamicVector.begin() + positionOfDog);
    return deletedElement;
}

TElement Repository::updateElement(const TElement& old_dog, const TElement& new_dog)
{
    int positionOfDog = this->searchByNameAndBreed(old_dog);
    if (positionOfDog == -1)
    {
        throw RepositoryException("Element not in repo!\n");
    }
    TElement oldElement = this->dynamicVector[positionOfDog];
    this->dynamicVector[positionOfDog].setName(new_dog.getName());
    this->dynamicVector[positionOfDog].setBreed(new_dog.getBreed());
    this->dynamicVector[positionOfDog].setAge(new_dog.getAge());
    this->dynamicVector[positionOfDog].setPhoto(new_dog.getPhoto());
    return oldElement;
}

int Repository::getSize() {
    return this->dynamicVector.size();
}

Dog* Repository::getElements() {
    return this->dynamicVector.data();
}

vector<TElement>::iterator Repository::getDynamicVectorBegin() {
    return this->dynamicVector.begin();
}

vector<TElement>::iterator Repository::getDynamicVectorEnd() {
    return this->dynamicVector.end();
}

vector<TElement> Repository::getDynamicVector() {
    return this->dynamicVector;
}

string Repository::getDisplayCommand() {
    return "";
}

Repository::~Repository() = default;
