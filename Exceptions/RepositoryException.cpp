//
// Created by user on 29/03/2021.
//

#include "RepositoryException.h"

RepositoryException::RepositoryException(const string &errorMessage):std::exception(), errorMessage{errorMessage}{

}

const string &RepositoryException::getErrorMessage() const {
    return this->errorMessage;
}