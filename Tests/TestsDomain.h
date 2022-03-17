//
// Created by user on 29/03/2021.
//

#ifndef A45_916_SILASCHI_IASMINA_TESTSDOMAIN_H
#define A45_916_SILASCHI_IASMINA_TESTSDOMAIN_H


class TestsDomain{
private:

    //Test for the implicit constructor of Dog
    void testImplicitConstructor();

    //Test for the explicit constructor of Dog
    void testExplicitConstructor();

    //Test all the getters & setters
    void testGettersAndSetters();

    //Test to see that if we modify a dog, its copy won't also get modified
    void testCopy();

    //Test the copy constructor
    void testCopyConstructor();

    //Test the "=" operator
    void testEqualOperator();

    //Test the toString method
    void testToStringMethod();

    //Test the "==" operator (breed && name - the same)
    void testEqualEqualOperator();


public:
    void runDomainTests();
};


#endif //A45_916_SILASCHI_IASMINA_TESTSDOMAIN_H
