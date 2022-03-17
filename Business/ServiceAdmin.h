//
// Created by user on 28/03/2021.
//

#ifndef A45_916_SILASCHI_IASMINA_SERVICEADMIN_H
#define A45_916_SILASCHI_IASMINA_SERVICEADMIN_H


#include <Repository.h>
#include <DogValidator.h>
#include <vector>
#include "UndoRedo.h"
#include <memory>
using std::unique_ptr;

class ServiceAdmin {
private:
    Repository &repo;
    vector<unique_ptr<UndoRedo>> undo_actions;
    vector<unique_ptr<UndoRedo>> redo_actions;
public:
    ServiceAdmin(Repository &repo);
    void addDog(const string&, const string&, int, const string&);
    void deleteDog(const string&, const string&);
    void updateDog(const string&, const string&, const string&, const string&, int, const string&);
    int getLengthAllDogs();
    Dog* getAllDogs();
    vector<Dog> getFilteredDogs(const string &breed, int age);
    void add10Entries();
    ~ServiceAdmin();
    void undo();
    void redo();
    vector<Dog> getDogsVector();
};


#endif //A45_916_SILASCHI_IASMINA_SERVICEADMIN_H
