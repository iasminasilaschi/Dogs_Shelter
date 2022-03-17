//
// Created by user on 31/05/2021.
//

#ifndef A10_916_SILASCHI_IASMINA_1_UNDOREDO_H
#define A10_916_SILASCHI_IASMINA_1_UNDOREDO_H

#include <iostream>
#include <Repository.h>

class UndoRedo{
public:
    virtual void do_undo() = 0;
    virtual void do_redo()= 0;
    virtual ~UndoRedo(){};
};

class UndoRedoAdd: public UndoRedo{
    Dog dog;
    Repository& repository;
public:

    UndoRedoAdd(Repository& repo, const Dog& dog) : repository{repo}, dog{dog} {}

    void do_undo() override {
        repository.deleteElement(dog);
    }
    void do_redo() override {
        repository.addElement(dog);
    }
};

class UndoRedoUpdate: public UndoRedo{
    Dog old_dog;
    Dog new_dog;
    Repository& repository;
public:

    UndoRedoUpdate(Repository& repo, const Dog& old_dog, const Dog& new_dog) : repository{repo}, old_dog{old_dog}, new_dog{new_dog}  {}

    void do_undo() override {
        repository.updateElement(new_dog, old_dog);
    }
    void do_redo() override {
        repository.updateElement(old_dog, new_dog);
    }
};

class UndoRedoDelete: public UndoRedo{
    Dog dog;
    Repository& repository;
public:

    UndoRedoDelete(Repository& repo, const Dog& dog) : repository{repo}, dog{dog}{}

    void do_undo() override {
        repository.addElement(dog);
    }
    void do_redo() override {
        repository.deleteElement(dog);
    }
};

#endif //A10_916_SILASCHI_IASMINA_1_UNDOREDO_H
