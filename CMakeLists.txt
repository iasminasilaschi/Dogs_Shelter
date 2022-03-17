cmake_minimum_required(VERSION 3.17)
project(a10_916_Silaschi_Iasmina-1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:\\qt6\\6.0.4\\mingw81_64\\lib\\cmake\\")
set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)

include_directories(Business)
include_directories(Domain)
include_directories(Exceptions)
include_directories(Persistence)
include_directories(Presentation)
include_directories(Tests)
include_directories(Validation)

add_executable(a10_916_Silaschi_Iasmina-1
        Business/ServiceAdmin.cpp
        Business/ServiceAdmin.h
        Business/ServiceUser.cpp
        Business/ServiceUser.h
        Domain/Dog.cpp
        Domain/Dog.h
        Exceptions/RepositoryException.cpp
        Exceptions/RepositoryException.h
        Exceptions/ServiceException.cpp
        Exceptions/ServiceException.h
        Exceptions/ValidationException.cpp
        Exceptions/ValidationException.h
        Persistence/CsvRepository.cpp
        Persistence/CsvRepository.h
        Persistence/FileRepository.cpp
        Persistence/FileRepository.h
        Persistence/HtmlRepository.cpp
        Persistence/HtmlRepository.h
        Persistence/Repository.cpp
        Persistence/Repository.h
        Presentation/Console.cpp
        Presentation/Console.h
        Tests/Tests.cpp
        Tests/Tests.h
        Tests/TestsDomain.cpp
        Tests/TestsDomain.h
        Tests/TestsRepository.cpp
        Tests/TestsRepository.h
        Tests/TestsService.cpp
        Tests/TestsService.h
        Tests/TestsValidation.cpp
        Tests/TestsValidation.h
        Validation/DogValidator.cpp
        Validation/DogValidator.h
        main.cpp
        Presentation/QtGui.cpp
        Presentation/QtGui.h
        mainQt.cpp Presentation/ModelView.cpp Presentation/ModelView.h Business/UndoRedo.cpp Business/UndoRedo.h)

find_package(Qt6Widgets REQUIRED)
target_link_libraries(a10_916_Silaschi_Iasmina-1 Qt6::Widgets)