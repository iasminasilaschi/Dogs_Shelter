//
// Created by user on 30/03/2021.
//

#include <DogValidator.h>
#include <Dog.h>
#include <ServiceException.h>
#include <Repository.h>
#include "ServiceUser.h"

ServiceUser::ServiceUser(Repository &repo): repo{repo} {

}

void ServiceUser::addDog(const string &breed, const string &name, int age, const string &photo) {
    Dog doggoToBeAdded{breed, name, age, photo};
    DogValidator::validateAddOrUpdate(doggoToBeAdded);
    if(this->repo.searchByNameAndBreed(doggoToBeAdded) == -1)
    {
        this->repo.addElement(doggoToBeAdded);
        undo_actions.push_back(std::make_unique<UndoRedoAdd>(this->repo, doggoToBeAdded));
        redo_actions.clear();
    }
    else{
        throw ServiceException("The dog with this breed and name already exists!\n");
    }
}

Dog *ServiceUser::getAllDogs() {
    return this->repo.getElements();
}

int ServiceUser::getLengthAllDogs() {
    return this->repo.getSize();
}

string ServiceUser::getDisplayCommand() {
    return this->repo.getDisplayCommand();
}

vector<Dog> ServiceUser::getVectorAdoption() {
    return this->repo.getDynamicVector();
}

void ServiceUser::undo() {
    if(undo_actions.empty()) {
        throw ServiceException("\nNo more undos!\n");
    }
    undo_actions[undo_actions.size()-1]->do_undo();
    redo_actions.push_back(move(undo_actions[undo_actions.size()-1]));
    undo_actions.pop_back();
}

void ServiceUser::redo() {
    if(redo_actions.empty()) {
        throw ServiceException("\nNo more redos!\n");
    }
    redo_actions.back()->do_redo();
    undo_actions.push_back(move(redo_actions[redo_actions.size()-1]));
    redo_actions.pop_back();
}

ServiceUser::~ServiceUser() = default;
