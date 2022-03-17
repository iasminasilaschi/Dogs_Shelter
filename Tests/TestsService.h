//
// Created by user on 29/03/2021.
//

#ifndef A45_916_SILASCHI_IASMINA_TESTSSERVICE_H
#define A45_916_SILASCHI_IASMINA_TESTSSERVICE_H


class TestsService{
private:

    void testGetAllDogs();

    void testGetLengthAllDogs();

    void testAddDog();

    void testDeleteDog();

    void testUpdateDog();

    void testAdd10Entries();

    void testAddDogUser();

    void testGetAllDogsUser();

    void testGetFilteredDogs();

public:
    void runServiceTests();

};


#endif //A45_916_SILASCHI_IASMINA_TESTSSERVICE_H
