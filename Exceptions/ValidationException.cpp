//
// Created by user on 29/03/2021.
//

#include "ValidationException.h"

ValidationException::ValidationException(const string &errorMessage):std::exception(), errorMessage{errorMessage}{

}

const string &ValidationException::getErrorMessage() const {
    return this->errorMessage;
}
