//
// Created by user on 29/03/2021.
//

#ifndef A45_916_SILASCHI_IASMINA_DOGVALIDATOR_H
#define A45_916_SILASCHI_IASMINA_DOGVALIDATOR_H


#include <Dog.h>

class DogValidator {
public:
    static void validateAddOrUpdate(const Dog &doggo);
    static void validateDeleteOrToBeUpdated(const Dog &doggo);
};


#endif //A45_916_SILASCHI_IASMINA_DOGVALIDATOR_H
