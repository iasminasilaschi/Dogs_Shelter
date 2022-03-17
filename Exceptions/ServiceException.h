//
// Created by user on 29/03/2021.
//

#ifndef A45_916_SILASCHI_IASMINA_SERVICEEXCEPTION_H
#define A45_916_SILASCHI_IASMINA_SERVICEEXCEPTION_H


using namespace std;
#include <exception>
#include <string>

class ServiceException : public std::exception{
private:
    string errorMessage;
public:
    explicit ServiceException(const string &errorMessage);
    const string &getErrorMessage() const;
};


#endif //A45_916_SILASCHI_IASMINA_SERVICEEXCEPTION_H
