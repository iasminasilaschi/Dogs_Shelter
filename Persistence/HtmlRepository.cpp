//
// Created by user on 16/04/2021.
//

#include <fstream>
#include "HtmlRepository.h"

HtmlRepository::HtmlRepository(string &fileName) : fileName{fileName} {
    this->fileName = fileName;
}

void HtmlRepository::writeToHtmlFile() {
    ofstream file(this->fileName);
    if (!file.is_open())
        return;

    file << "<!DOCTYPE html>" << '\n';
    file << "<html>" << '\n';
    file << "<head>" << '\n';
    file << "\t<title>Dogs</title>" << '\n';
    file << "</head>" << '\n';
    file << "<body>" << '\n';
    file << "<table border=\"1\">" << '\n';
    file << "\t<tr>" << '\n';
    file << "\t\t<td>Breed</td>" << '\n';
    file << "\t\t<td>Name</td>" << '\n';
    file << "\t\t<td>Age</td>" << '\n';
    file << "\t\t<td>Photo link</td>" << '\n';
    file << "\t</tr>" << '\n';
    for (const auto& dog : this->dynamicVector)
    {
        file << "\t<tr>" << '\n';
        file << "\t\t<td>" << dog.getBreed() << "</td>" << '\n';
        file << "\t\t<td>" << dog.getName() << "</td>" << '\n';
        file << "\t\t<td>" << dog.getAge() << "</td>" << '\n';
        file << "\t\t<td><a href=\"" << dog.getPhoto() << "\">Link</a></td>" << '\n';
        file << "\t</tr>" << '\n';
    }
    file << "</table>" << '\n';
    file << "</body>" << '\n';
    file << "</html>" << '\n';
    file.close();
}

void HtmlRepository::addElement(const TElement &dog) {
    Repository::addElement(dog);
    this->writeToHtmlFile();
}

string HtmlRepository::getDisplayCommand() {
    string command = "start chrome \"" + this->fileName + "\"";
    return command;
}

HtmlRepository::~HtmlRepository() = default;
