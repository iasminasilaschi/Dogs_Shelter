//
// Created by user on 16/04/2021.
//

#include <fstream>
#include <sstream>
#include "CsvRepository.h"

CsvRepository::CsvRepository(string &fileName) : fileName{fileName}{
    this->fileName = fileName;
}

void CsvRepository::readFromCsvFile() {
    ifstream file;
    file.open(this->fileName, ios::in);
    if (!file.is_open())
    {
        return;
    }

    vector<string> result;
    string line, word, something;

    while (file >> something) {
        getline(file, line);
        stringstream ss(line);
        while (getline(ss, word, ',')) {
            result.push_back(word);
        }
        if (result.size() != 4)
            return;
        int age = stoi(result[2]);
        Dog dog = {result[0], result[1], age, result[3]};
        this->dynamicVector.push_back(dog);
    }
    file.close();
}

void CsvRepository::writeToCsvFile() {
    ofstream file;
    file.open(this->fileName, ios::out);
    if (!file.is_open())
        return;

    for (const auto& dog : this->dynamicVector)
    {
        file<<dog.getBreed()<<','<<dog.getName()<<','<<dog.getAge()<<','<<dog.getPhoto()<<'\n';
    }

    file.close();
}

void CsvRepository::addElement(const TElement &dog) {
    Repository::addElement(dog);
    this->writeToCsvFile();
}

string CsvRepository::getDisplayCommand() {
    string command = "notepad \"" + this->fileName + "\"";
    return command;
}

CsvRepository::~CsvRepository() = default;


