//
// Created by user on 16/04/2021.
//

#include <fstream>
#include <iostream>
#include "FileRepository.h"

FileRepository::FileRepository(string &fileName) : fileName{fileName} {
    this->fileName = fileName;
    this->readFromFile();
}

void FileRepository::readFromFile()
{
    ifstream file(this->fileName);
    if (!file.is_open())
    {
        return;
    }
    Dog dog{};
    while (file >> dog)
    {
        this->dynamicVector.push_back(dog);
    }
    file.close();
}

void FileRepository::writeToFile()
{
    ofstream file(this->fileName);
    if (!file.is_open())
        return;

    for (const auto& dog : this->dynamicVector)
    {
        file << dog;
    }

    file.close();
}

void FileRepository::addElement(const TElement &dog) {
    Repository::addElement(dog);
    this->writeToFile();
}

TElement FileRepository::deleteElement(const TElement &dog) {
    Dog deleted_dog = Repository::deleteElement(dog);
    this->writeToFile();
    return deleted_dog;
}

TElement FileRepository::updateElement(const TElement &old_dog, const TElement &new_dog) {
    Dog updated_dog = Repository::updateElement(old_dog, new_dog);
    this->writeToFile();
    return updated_dog;
}

FileRepository::~FileRepository() = default;



