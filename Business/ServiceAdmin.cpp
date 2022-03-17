//
// Created by user on 28/03/2021.
//

#include "ServiceAdmin.h"
#include <vector>
#include <ServiceException.h>
#include <Repository.h>
#include <Dog.h>
#include <DogValidator.h>
#include <algorithm>
#include <iostream>

ServiceAdmin::ServiceAdmin(Repository &repo): repo{repo} {

}

void ServiceAdmin::addDog(const string &breed, const string &name, int age, const string &photo) {
    Dog doggoToBeAdded{breed, name, age, photo};
    DogValidator::validateAddOrUpdate(doggoToBeAdded);
    if(this->repo.searchByNameAndBreed(doggoToBeAdded) == -1)
    {
        this->repo.addElement(doggoToBeAdded);
    }
    else{
        throw ServiceException("The dog with this breed and name already exists!\n");
    }
    undo_actions.push_back(std::make_unique<UndoRedoAdd>(this->repo, doggoToBeAdded));
    redo_actions.clear();
}

void ServiceAdmin::deleteDog(const string &breed, const string &name) {
    Dog doggoToBeDeleted{breed, name, -1, ""};
    DogValidator::validateDeleteOrToBeUpdated(doggoToBeDeleted);
    int index = this->repo.searchByNameAndBreed(doggoToBeDeleted);
    if(index != -1)
    {
        Dog actualDoggo = this->getDogsVector()[index];
        this->repo.deleteElement(doggoToBeDeleted);
        undo_actions.push_back(std::make_unique<UndoRedoDelete>(this->repo, actualDoggo));
        redo_actions.clear();
    }
    else{
        throw ServiceException("This dog does not exist!\n");
    }
}

void ServiceAdmin::updateDog(const string &breed, const string &name, const string &newBreed, const string &newName, int newAge,
                             const string &newPhoto) {
    Dog doggoToBeUpdated{breed, name, -1, ""};
    DogValidator::validateDeleteOrToBeUpdated(doggoToBeUpdated);
    int oldDoggoPosition = this->repo.searchByNameAndBreed(doggoToBeUpdated);
    if(oldDoggoPosition != -1)
    {
        Dog oldDoggo = this->getAllDogs()[oldDoggoPosition];
        Dog newDoggo{newBreed, newName, newAge, newPhoto};
        if(newDoggo.getBreed() == ""){
            newDoggo.setBreed(oldDoggo.getBreed());
        }
        if(newDoggo.getName() == ""){
            newDoggo.setName(oldDoggo.getName());
        }
        if(newDoggo.getAge() == -1){
            newDoggo.setAge(oldDoggo.getAge());
        }
        if(newDoggo.getPhoto() == ""){
            newDoggo.setPhoto(oldDoggo.getPhoto());
        }
        DogValidator::validateAddOrUpdate(newDoggo);
        undo_actions.push_back(std::make_unique<UndoRedoUpdate>(this->repo, oldDoggo, newDoggo));
        redo_actions.clear();
        this->repo.updateElement(doggoToBeUpdated, newDoggo);
    }
    else{
        throw ServiceException("This dog does not exist!\n");
    }
}

Dog *ServiceAdmin::getAllDogs() {
    return this->repo.getElements();
}

int ServiceAdmin::getLengthAllDogs() {
    return this->repo.getSize();
}

vector<Dog> ServiceAdmin::getFilteredDogs(const string &breed, int age) {
    vector<Dog> filteredDogs;
    std::copy_if(this->repo.getDynamicVectorBegin(), this->repo.getDynamicVectorEnd(), std::back_inserter(filteredDogs),
                 [&breed, &age](Dog& dog){return (breed.empty() || dog.getBreed() == breed) && dog.getAge() < age;});
    return filteredDogs;
}

vector<Dog> ServiceAdmin::getDogsVector() {
    return this->repo.getDynamicVector();
}

void ServiceAdmin::add10Entries() {
    this->addDog("Dachshund", "Pixie", 4, "https://dogtime.com/assets/uploads/2011/01/file_23020_dachshund-dog-breed.jpg");
    this->addDog("Bichon", "Toto", 5, "https://rasedecaini.ro/wp-content/uploads/2019/05/rasa-bichon-maltez.jpg");
    this->addDog("Pug", "Toby", 2, "https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/12225358/Pug-On-White-01.jpg");
    this->addDog("Bulldog", "Rex", 3, "https://www.wowwow.ro/cache/c/a/2/7/e/ca27edc89ae69faedc76cfa291d00b49d516a18e-bulldog-francez.jpeg");
    this->addDog("Corgi", "Donna", 6, "https://dogtime.com/assets/uploads/gallery/pembroke-welsh-corgi-dog-breed-pictures/prance-8.jpg");
    this->addDog("Corgi", "Cynthia", 1, "https://i.pinimg.com/originals/51/03/d8/5103d8dcf3285e7e73b142049d252558.jpg");
    this->addDog("Labrador", "Charlie", 3, "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRqtevyTOTKqvE9uNtGEMxfEUMJglnnBT0iVg&usqp=CAU");
    this->addDog("Husky", "Alfie", 7, "https://highlandcanine.com/wp-content/uploads/2021/01/siberian-husky-in-the-snow.jpg");
    this->addDog("Pug", "Ben", 1, "https://i.pinimg.com/originals/21/cc/0e/21cc0ef668b35d78ff3e7160fd556186.jpg");
    this->addDog("Pomeranian", "Puffy", 1, "https://www.animalepierdute.ro/wp-content/uploads/2019/09/pomeranian-rase-de-caini.jpg");
}

void ServiceAdmin::undo() {
    if(undo_actions.empty()) {
        throw ServiceException("\nNo more undos!\n");
    }
    undo_actions[undo_actions.size()-1]->do_undo();
    redo_actions.push_back(move(undo_actions[undo_actions.size()-1]));
    undo_actions.pop_back();
}

void ServiceAdmin::redo() {
    if(redo_actions.empty()) {
        throw ServiceException("\nNo more redos!\n");
    }
    redo_actions.back()->do_redo();
    undo_actions.push_back(move(redo_actions[redo_actions.size()-1]));
    redo_actions.pop_back();
}

ServiceAdmin::~ServiceAdmin() = default;



