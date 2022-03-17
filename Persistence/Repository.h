//
// Created by user on 22/03/2021.
//

#ifndef A45_916_SILASCHI_IASMINA_REPOSITORY_H
#define A45_916_SILASCHI_IASMINA_REPOSITORY_H

#include "Repository.h"
#include "Dog.h"
#include <vector>

typedef Dog TElement;

class Repository {

protected:
    std::vector<TElement> dynamicVector;
public:
    // default constructor
    Repository();

    int searchByNameAndBreed(const TElement& dog);

    virtual void addElement(const TElement& dog);

    virtual TElement deleteElement(const TElement& dog);

    virtual TElement updateElement(const TElement& old_dog, const TElement& new_dog);

    int getSize();

    Dog * getElements();

    vector<TElement>::iterator getDynamicVectorBegin();

    vector<TElement>::iterator getDynamicVectorEnd();

    virtual string getDisplayCommand();

    ~Repository();

    vector<TElement> getDynamicVector();
};


#endif //A45_916_SILASCHI_IASMINA_REPOSITORY_H
