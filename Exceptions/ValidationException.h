//
// Created by user on 29/03/2021.
//

#ifndef A45_916_SILASCHI_IASMINA_VALIDATIONEXCEPTION_H
#define A45_916_SILASCHI_IASMINA_VALIDATIONEXCEPTION_H

using namespace std;
#include <exception>
#include <string>

class ValidationException : public std::exception{
private:
    string errorMessage;
public:
    explicit ValidationException(const string &errorMessage);
    const string &getErrorMessage() const;
};


#endif //A45_916_SILASCHI_IASMINA_VALIDATIONEXCEPTION_H
