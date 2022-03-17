//
// Created by user on 22/03/2021.
//

#ifndef A45_916_SILASCHI_IASMINA_DOG_H
#define A45_916_SILASCHI_IASMINA_DOG_H


#include <string>
using namespace std;

///breed, a name, an age and a photograph
class Dog
{
protected:
    std::string breed;
    std::string name;
    int age = -1;
    std::string photo;

public:
    Dog();
    Dog(const string &breed, const string &name, int age, const string &photo);
    Dog(const Dog &anotherDog);
    Dog& operator=(const Dog &anotherDog);
    bool operator==(const Dog& dogToBeComparedWith) const;
    ~Dog();

    string getBreed() const;
    string getName() const;
    int getAge() const;
    string getPhoto() const;

    string toString() const;

    void setBreed(string newBreed);
    void setName(string newName);
    void setAge(int newAge);
    void setPhoto(string newPhoto);

    friend std::istream &operator>>(std::istream &is, Dog& dog);
    friend std::ostream &operator<<(std::ostream &os, const Dog& dog);
};


#endif //A45_916_SILASCHI_IASMINA_DOG_H
