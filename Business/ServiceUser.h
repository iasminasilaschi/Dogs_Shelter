//
// Created by user on 30/03/2021.
//

#ifndef A45_916_SILASCHI_IASMINA_SERVICEUSER_H
#define A45_916_SILASCHI_IASMINA_SERVICEUSER_H


#include <Repository.h>
#include <DogValidator.h>
#include <memory>
#include "UndoRedo.h"

using std::unique_ptr;

class ServiceUser {
private:
    Repository &repo;
    vector<unique_ptr<UndoRedo>> undo_actions;
    vector<unique_ptr<UndoRedo>> redo_actions;
public:
    explicit ServiceUser(Repository &repo);
    void addDog(const string&, const string&, int, const string&);
    int getLengthAllDogs();
    Dog* getAllDogs();
    string getDisplayCommand();
    ~ServiceUser();
    vector<Dog> getVectorAdoption();
    void undo();
    void redo();
};

#endif //A45_916_SILASCHI_IASMINA_SERVICEUSER_H
