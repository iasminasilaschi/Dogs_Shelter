//
// Created by user on 29/03/2021.
//

#include "ServiceException.h"

ServiceException::ServiceException(const string &errorMessage):std::exception(), errorMessage{errorMessage}{

}

const string &ServiceException::getErrorMessage() const {
    return this->errorMessage;
}