//
// Created by user on 09/05/2021.
//

#include "QtGui.h"
#include <QMessageBox>
#include <QFormLayout>
#include <QLabel>
#include <iostream>
#include <ServiceException.h>
#include <ValidationException.h>
#include <RepositoryException.h>


void QtGui::initGui() {
    mainMode();
    adminMode();
    userMode();
    chooseRepoType();
}

void QtGui::setInitialGuiState() {
    this->populateDogList();
}

void QtGui::mainMode() {
    QFont f{"Times New Roman", 12};
    ///MAIN layout
    QVBoxLayout* mainLayout = new QVBoxLayout;
    setLayout(mainLayout);
    ///Choose MODE buttons
    chooseMode(mainLayout, f);
}

void QtGui::chooseMode(QVBoxLayout *mainLayout, QFont f) {
    QWidget* chooseMode = new QWidget{};
    QHBoxLayout* layoutMode = new QHBoxLayout{};
    buttonAdmin = new QPushButton{"Admin Mode"};
    buttonUser = new QPushButton{"User Mode"};
    buttonAdmin->setFont(f);
    buttonUser->setFont(f);
    layoutMode->addWidget(buttonAdmin);
    layoutMode->addWidget(buttonUser);
    chooseMode->setLayout(layoutMode);
    mainLayout->addWidget(chooseMode);
}

void QtGui::adminMode() {
    /// big layout
    this->adminWidget = new QWidget{};
    QHBoxLayout* layoutAdmin = new QHBoxLayout{};

    /// left side - just the list
    listDogs = new QListWidget{};
    // set the selection model
    listDogs->setSelectionMode(QAbstractItemView::SingleSelection);

    /// right side - dog information + buttons
    QWidget* rightSide = new QWidget{};
    QVBoxLayout* vLayout = new QVBoxLayout{rightSide};
    QFont f{"Times New Roman", 12};
    // dog information
    dogDataAdmin(vLayout, f);
    // buttons
    buttonsAdmin(vLayout, f);

    /// add everything to the big layout
    layoutAdmin->addWidget(listDogs);
    layoutAdmin->addWidget(rightSide);
    this->adminWidget->setLayout(layoutAdmin);

    shortcutUndo = new QShortcut(QKeySequence("Ctrl+Z"), adminWidget);
    QObject::connect(shortcutUndo, SIGNAL(activated()), this, SLOT(undo()));
    shortcutRedo = new QShortcut(QKeySequence("Ctrl+Y"), adminWidget);
    QObject::connect(shortcutRedo, SIGNAL(activated()), this, SLOT(redo()));

    updateWindow();
}

void QtGui::dogDataAdmin(QVBoxLayout *vLayout, QFont &f) {
    QWidget *dogData = new QWidget{};
    QFormLayout* formLayout = new QFormLayout{dogData};
    breedEditAdmin = new QLineEdit{};
    nameEditAdmin = new QLineEdit{};
    ageEditAdmin = new QLineEdit{};
    photoEditAdmin = new QTextEdit{};
    QLabel* breedLabel = new QLabel{"&Breed:" };
    breedLabel->setBuddy(breedEditAdmin);
    QLabel* nameLabel = new QLabel{"&Name:" };
    nameLabel->setBuddy(nameEditAdmin);
    QLabel* ageLabel = new QLabel{ "&Age: " };
    ageLabel->setBuddy(ageEditAdmin);
    QLabel* photoLabel = new QLabel{ "&Photo:" };
    photoLabel->setBuddy(photoEditAdmin);
    breedLabel->setFont(f);
    nameLabel->setFont(f);
    ageLabel->setFont(f);
    photoLabel->setFont(f);
    breedEditAdmin->setFont(f);
    nameEditAdmin->setFont(f);
    ageEditAdmin->setFont(f);
    photoEditAdmin->setFont(f);
    formLayout->addRow(breedLabel, breedEditAdmin);
    formLayout->addRow(nameLabel, nameEditAdmin);
    formLayout->addRow(ageLabel, ageEditAdmin);
    formLayout->addRow(photoLabel, photoEditAdmin);
    vLayout->addWidget(dogData);
}

void QtGui::buttonsAdmin(QVBoxLayout *vLayout, const QFont &f) {
    QWidget* addDelButtons = new QWidget{};
    QHBoxLayout* hLayout = new QHBoxLayout{addDelButtons};
    addButton = new QPushButton("Add");
    addButton->setFont(f);
    deleteButton = new QPushButton("Delete");
    deleteButton->setFont(f);
    hLayout->addWidget(addButton);
    hLayout->addWidget(deleteButton);
    vLayout->addWidget(addDelButtons);

    QWidget* updUndButtons = new QWidget{};
    QHBoxLayout* hLayout1 = new QHBoxLayout{updUndButtons};
    updateButton = new QPushButton("Update");
    updateButton->setFont(f);
    undoButton = new QPushButton("Undo");
    undoButton->setFont(f);
    redoButton = new QPushButton("Redo");
    redoButton->setFont(f);
    hLayout1->addWidget(updateButton);
    hLayout1->addWidget(undoButton);
    hLayout1->addWidget(redoButton);
    vLayout->addWidget(updUndButtons);
}

void QtGui::updateWindow() {
    /// big layout
    this->updateWidget = new QWidget{};
    QHBoxLayout* layoutUpdate = new QHBoxLayout{};

    QWidget* rightSideUpdate = new QWidget{};
    QVBoxLayout* vLayout = new QVBoxLayout{rightSideUpdate};
    QFont f{"Times New Roman", 12};
    // dog information
    dogDataUpdate(vLayout, f);
    // buttons
    buttonsUpdate(vLayout, f);

    /// add everything to the big layout
    layoutUpdate->addWidget(rightSideUpdate);
    this->updateWidget->setLayout(layoutUpdate);
}

void QtGui::dogDataUpdate(QVBoxLayout *vLayout, QFont &f) {
    QWidget *dogData = new QWidget{};
    QFormLayout* formLayout = new QFormLayout{dogData};
    breedEditUpdate = new QLineEdit{};
    nameEditUpdate = new QLineEdit{};
    ageEditUpdate = new QLineEdit{};
    photoEditUpdate = new QTextEdit{};
    QLabel* breedLabel = new QLabel{"&Breed:" };
    breedLabel->setBuddy(breedEditUpdate);
    QLabel* nameLabel = new QLabel{"&Name:" };
    nameLabel->setBuddy(nameEditUpdate);
    QLabel* ageLabel = new QLabel{ "&Age: " };
    ageLabel->setBuddy(ageEditUpdate);
    QLabel* photoLabel = new QLabel{ "&Photo:" };
    photoLabel->setBuddy(photoEditUpdate);
    breedLabel->setFont(f);
    nameLabel->setFont(f);
    ageLabel->setFont(f);
    photoLabel->setFont(f);
    breedEditUpdate->setFont(f);
    nameEditUpdate->setFont(f);
    ageEditUpdate->setFont(f);
    photoEditUpdate->setFont(f);
    formLayout->addRow(breedLabel, breedEditUpdate);
    formLayout->addRow(nameLabel, nameEditUpdate);
    formLayout->addRow(ageLabel, ageEditUpdate);
    formLayout->addRow(photoLabel, photoEditUpdate);
    vLayout->addWidget(dogData);
}

void QtGui::buttonsUpdate(QVBoxLayout *vLayout, const QFont &f) {
    QWidget* updateButtons = new QWidget{};
    QHBoxLayout* hLayout = new QHBoxLayout{updateButtons};
    updateButtonUpdate = new QPushButton("Update");
    updateButtonUpdate->setFont(f);
    hLayout->addWidget(updateButtonUpdate);
    vLayout->addWidget(updateButtons);
}

void QtGui::userMode() {
    /// big layout
    this->userWidget = new QWidget{};
    QHBoxLayout* layoutUser = new QHBoxLayout{};
    QFont f{"Times New Roman", 12};

    /// left side - the list and a filter option
    QWidget* leftSide = new QWidget{};
    QVBoxLayout* vLayoutLeft = new QVBoxLayout{leftSide};
    listDogsUser = new QListWidget{};
    // set the selection model
    listDogsUser->setSelectionMode(QAbstractItemView::SingleSelection);
    vLayoutLeft->addWidget(listDogsUser);
    // filter option
    filterUser(vLayoutLeft, f);

    /// middle side - dog information + buttons
    QWidget* middleSide = new QWidget{};
    QVBoxLayout* vLayout = new QVBoxLayout{middleSide};
    // dog information
    dogDataUser(vLayout, f);
    // buttons
    buttonsUser(vLayout, f);

    /// right side - just the adoption list
    adoptionTable->setModel(model);
    setWindowTitle("Adoption List");
    // set the selection model
//    listAdoption->setSelectionMode(QAbstractItemView::SingleSelection);

    /// add everything to the big layout
    layoutUser->addWidget(leftSide);
    layoutUser->addWidget(middleSide);
    layoutUser->addWidget(adoptionTable);
    this->userWidget->setLayout(layoutUser);

    shortcutUndoUser = new QShortcut(QKeySequence("Ctrl+Z"), userWidget);
    QObject::connect(shortcutUndoUser, SIGNAL(activated()), this, SLOT(undoUser()));
    shortcutRedoUser = new QShortcut(QKeySequence("Ctrl+Y"), userWidget);
    QObject::connect(shortcutRedoUser, SIGNAL(activated()), this, SLOT(redoUser()));
}

void QtGui::dogDataUser(QVBoxLayout *vLayout, QFont f) {
    QWidget *dogData = new QWidget{};
    QFormLayout* formLayout = new QFormLayout{dogData};
    breedEditUser = new QLineEdit{};
    nameEditUser = new QLineEdit{};
    ageEditUser = new QLineEdit{};
    photoEditUser = new QTextEdit{};
    QLabel* breedLabel = new QLabel{"&Breed:" };
    breedLabel->setBuddy(breedEditUser);
    QLabel* nameLabel = new QLabel{"&Name:" };
    nameLabel->setBuddy(nameEditUser);
    QLabel* ageLabel = new QLabel{ "&Age: " };
    ageLabel->setBuddy(ageEditUser);
    QLabel* photoLabel = new QLabel{ "&Photo:" };
    photoLabel->setBuddy(photoEditUser);
    breedLabel->setFont(f);
    nameLabel->setFont(f);
    ageLabel->setFont(f);
    photoLabel->setFont(f);
    breedEditUser->setFont(f);
    nameEditUser->setFont(f);
    ageEditUser->setFont(f);
    photoEditUser->setFont(f);
    formLayout->addRow(breedLabel, breedEditUser);
    formLayout->addRow(nameLabel, nameEditUser);
    formLayout->addRow(ageLabel, ageEditUser);
    formLayout->addRow(photoLabel, photoEditUser);
    vLayout->addWidget(dogData);
}

void QtGui::buttonsUser(QVBoxLayout *vLayout, QFont f) {
    QWidget* adoNexButtons = new QWidget{};
    QHBoxLayout* hLayout = new QHBoxLayout{adoNexButtons};
    adoptButton = new QPushButton("Adopt");
    adoptButton->setFont(f);
    nextButton = new QPushButton("Next");
    nextButton->setFont(f);
    hLayout->addWidget(adoptButton);
    hLayout->addWidget(nextButton);
    vLayout->addWidget(adoNexButtons);
    QWidget* disExiButtons = new QWidget{};
    QHBoxLayout* hLayout2 = new QHBoxLayout{disExiButtons};
    displayButton = new QPushButton("Display");
    undoButtonUser = new QPushButton("Undo");
    redoButtonUser = new QPushButton("Redo");
    undoButtonUser->setFont(f);
    redoButtonUser->setFont(f);
    displayButton->setFont(f);
    hLayout2->addWidget(displayButton);
    hLayout2->addWidget(undoButtonUser);
    hLayout2->addWidget(redoButtonUser);
    vLayout->addWidget(disExiButtons);
}

void QtGui::filterUser(QVBoxLayout *vLayout, QFont f) {
    filterButton = new QPushButton{"Filter"};
    filterButton->setFont(f);
    vLayout->addWidget(filterButton);
    QWidget *filterData = new QWidget{};
    QFormLayout* formLayout = new QFormLayout{filterData};
    filterBreedEdit = new QLineEdit{};
    filterAgeEdit = new QLineEdit{};
    QLabel* breedLabel = new QLabel{"&Breed:" };
    breedLabel->setBuddy(filterBreedEdit);
    QLabel* ageLabel = new QLabel{ "&Age: " };
    ageLabel->setBuddy(filterAgeEdit);
    breedLabel->setFont(f);
    ageLabel->setFont(f);
    filterBreedEdit->setFont(f);
    filterAgeEdit->setFont(f);
    formLayout->addRow(breedLabel, filterBreedEdit);
    formLayout->addRow(ageLabel, filterAgeEdit);
    vLayout->addWidget(filterData);
    revertButton = new QPushButton{"Revert"};
    revertButton->setFont(f);
    vLayout->addWidget(revertButton);
}

void QtGui::populateDogList()
{
    // clear the list, if there are elements in it
    if (this->listDogs->count() > 0)
        this->listDogs->clear();

    if (this->listDogsUser->count() > 0)
        this->listDogsUser->clear();

    for (auto &dog : this->adminService.getDogsVector())
    {
        string age = to_string(dog.getAge());
        QString itemInList = QString::fromStdString(dog.getBreed() + " - " +
                                                    dog.getName() + " - " + age + " - " +
                                                    dog.getPhoto());
        QFont f{"Times New Roman", 12};
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->listDogs->addItem(item);
    }

    for (auto &dog : this->adminService.getDogsVector())
    {
        std::string age = std::to_string(dog.getAge());
        QString itemInList = QString::fromStdString(dog.getBreed() + " - " +
                                                    dog.getName() + " - " + age + " - " +
                                                    dog.getPhoto());
        QFont f{"Times New Roman", 12};
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->listDogsUser->addItem(item);
    }

    // set the selection on the first item in the list
    if (!this->adminService.getDogsVector().empty()) {
        this->listDogs->setCurrentRow(0);
        this->listDogsUser->setCurrentRow(0);
    }
}

void QtGui::populateAdoptionList()
{
    if(filtered) {
        QString breed = this->filterBreedEdit->text();
        QString age_str = this->filterAgeEdit->text();

        int age;
        if(age_str.toStdString().empty() || age_str.toInt() == 0) {
            age = -1;
        }
        else {
            age = age_str.toInt();
        }
        // clear the list, if there are elements in it
        if (this->listDogsUser->count() > 0)
            this->listDogsUser->clear();

        for (auto &dog : adminService.getFilteredDogs(breed.toStdString(), age))
        {
            string age = to_string(dog.getAge());
            QString itemInList = QString::fromStdString(dog.getBreed() + " - " +
                                                        dog.getName() + " - " + age + " - " +
                                                        dog.getPhoto());
            QFont f{"Times New Roman", 12};
            QListWidgetItem* item = new QListWidgetItem{ itemInList };
            item->setFont(f);
            this->listDogsUser->addItem(item);
        }
        if(csv) {
            model->set_dogs(this->userServiceCsv.getVectorAdoption());
        }
        if(html) {
            model->set_dogs(this->userServiceHtml.getVectorAdoption());
        }

        // set the selection on the first item in the list
        if (!this->adminService.getDogsVector().empty()) {
            this->listDogsUser->setCurrentRow(0);
//            system(("start chrome " + this->adminService.getDogsVector()[0].getPhoto()).c_str());
        }
        else {
            filtered = false;
        }
    }
    else if (!filtered) {
        if(csv) {
            model->set_dogs(this->userServiceCsv.getVectorAdoption());
        }
        if(html) {
            model->set_dogs(this->userServiceHtml.getVectorAdoption());
        }
    }

}

void QtGui::connectSignalsAndSlots() {
    QObject::connect(buttonAdmin, &QPushButton::clicked,this,[=](){
        this->adminWidget->show();
        this->hide();
    });
    QObject::connect(buttonUser, &QPushButton::clicked,this,[=](){
        this->chooseRepo->show();
        this->hide();
    });
    QObject::connect(updateButton, &QPushButton::clicked,this,[=](){
        this->updateWidget->show();
    });
    QObject::connect(buttonCsv, &QPushButton::clicked,this,[=](){
        csv = true;
        this->userWidget->show();
        this->chooseRepo->hide();
    });
    QObject::connect(buttonHtml, &QPushButton::clicked,this,[=](){
        html = true;
        this->userWidget->show();
        this->chooseRepo->hide();
    });


    // when the vector is updated - re-populate the list
    QObject::connect(this, &QtGui::listUpdatedSignal, this, &QtGui::populateDogList);
    QObject::connect(this, &QtGui::listUpdatedAdoptionSignal, this, &QtGui::populateAdoptionList);

    // add a connection: function listItemChangedAdmin() will be called when an item in the list is selected
    QObject::connect(this->listDogs, &QListWidget::itemSelectionChanged, this, [this]() {
        this->listItemChangedAdmin();
    });

    QObject::connect(this->listDogsUser, &QListWidget::itemSelectionChanged, this, [this]() {
        if(!filtered)
            this->listItemChangedUser();
        else if(filtered)
            this->listItemChangedUserFilter();
    });

    // add button connections
    QObject::connect(addButton, &QPushButton::clicked, this, &QtGui::addButtonHandler);
    QObject::connect(deleteButton, &QPushButton::clicked, this, &QtGui::deleteButtonHandler);
    QObject::connect(updateButtonUpdate, &QPushButton::clicked, this, &QtGui::updateButtonHandler);
    QObject::connect(undoButton, &QPushButton::clicked, this, &QtGui::undoButtonHandler);
    QObject::connect(redoButton, &QPushButton::clicked, this, &QtGui::redoButtonHandler);
    QObject::connect(undoButtonUser, &QPushButton::clicked, this, &QtGui::undoButtonHandlerUser);
    QObject::connect(redoButtonUser, &QPushButton::clicked, this, &QtGui::redoButtonHandlerUser);
    QObject::connect(nextButton, &QPushButton::clicked, this, &QtGui::nextButtonHandler);
    QObject::connect(adoptButton, &QPushButton::clicked, this, &QtGui::adoptButtonHandler);
    QObject::connect(displayButton, &QPushButton::clicked,this, &QtGui::displayButtonHandler);
    QObject::connect(filterButton, &QPushButton::clicked,this, &QtGui::filterButtonHandler);
    QObject::connect(revertButton, &QPushButton::clicked,this, &QtGui::revertButtonHandler);

    // connect the signals to the slots
    QObject::connect(this, SIGNAL(addSignal(const string&, const string&, int, const string&)),
                     this, SLOT(add(const string&, const string&, int, const string&)));
    QObject::connect(this, SIGNAL(deleteSignal(const string&, const string&)),
                     this, SLOT(del(const string&, const string&)));
    QObject::connect(this, SIGNAL(updateSignal(const string&, const string&, const string&, const string&, int, const string&)),
                     this, SLOT(update(const string&, const string&, const string&, const string&, int, const string&)));
    QObject::connect(this, SIGNAL(adoptSignal(const string&, const string&, int, const string&)),
                     this, SLOT(adopt(const string&, const string&, int, const string&)));
}

void QtGui::revertButtonHandler()
{
    filtered = false;
    populateDogList();
}

void QtGui::filterButtonHandler()
{
    // read data from the text boxes
    filtered = true;
    QString breed = this->filterBreedEdit->text();
    QString age_str = this->filterAgeEdit->text();

    int age;
    if(age_str.toStdString().empty() || age_str.toInt() == 0) {
        age = -1;
    }
    else {
        age = age_str.toInt();
    }
    // clear the list, if there are elements in it
    if (this->listDogsUser->count() > 0)
        this->listDogsUser->clear();

    for (auto &dog : adminService.getFilteredDogs(breed.toStdString(), age))
    {
        string age = to_string(dog.getAge());
        QString itemInList = QString::fromStdString(dog.getBreed() + " - " +
                                                    dog.getName() + " - " + age + " - " +
                                                    dog.getPhoto());
        QFont f{"Times New Roman", 12};
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->listDogsUser->addItem(item);
    }

    // set the selection on the first item in the list
    if (!this->adminService.getDogsVector().empty()) {
        this->listDogsUser->setCurrentRow(0);
    }

}

void QtGui::displayButtonHandler()
{
    if(html) {
        system(userServiceHtml.getDisplayCommand().c_str());
    }
    if(csv) {
        system(userServiceCsv.getDisplayCommand().c_str());
    }
}

void QtGui::add(const string& breed, const string& name, int age, const std::string& photo)
{
    try {
        this->adminService.addDog(breed, name, age, photo);
    }
    catch (RepositoryException &re) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(re.getErrorMessage()));
    }
    catch (ValidationException &ve) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(ve.getErrorMessage()));
    }
    catch (ServiceException &se) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(se.getErrorMessage()));
    }
    emit listUpdatedSignal();
}

void QtGui::adopt(const string &breed, const string &name, int age, const string &photo) {
    if(html) {
        userServiceHtml.addDog(breed, name, age, photo);
    }
    if(csv) {
        userServiceCsv.addDog(breed, name, age, photo);
    }
    emit deleteSignal(breed, name);
    emit listUpdatedAdoptionSignal();
}

void QtGui::addButtonHandler()
{
    // read data from the textboxes
    QString breed = this->breedEditAdmin->text();
    QString name = this->nameEditAdmin->text();
    QString age = this->ageEditAdmin->text();
    QString photo = this->photoEditAdmin->toPlainText();

    // emit the add signal
    emit addSignal(breed.toStdString(), name.toStdString(), age.toInt(), photo.toStdString());
}

void QtGui::del(const string& breed, const string& name)
{
    try {
        this->adminService.deleteDog(breed, name);
    }
    catch (RepositoryException &re) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(re.getErrorMessage()));
    }
    catch (ValidationException &ve) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(ve.getErrorMessage()));
    }
    catch (ServiceException &se) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(se.getErrorMessage()));
    }
    emit listUpdatedSignal();
}

void QtGui::deleteButtonHandler()
{
    // read data from the text boxes
    QString breed = this->breedEditAdmin->text();
    QString name = this->nameEditAdmin->text();


    // emit the signal: the dogs were updated
    emit deleteSignal(breed.toStdString(), name.toStdString());
}

void QtGui::updateButtonHandler()
{
    // read data from the text boxes
    QString old_breed = this->breedEditAdmin->text();
    QString old_name = this->nameEditAdmin->text();
    QString breed = this->breedEditUpdate->text();
    QString name = this->nameEditUpdate->text();
    QString age_str = this->ageEditUpdate->text();
    QString photo = this->photoEditUpdate->toPlainText();

    int age;
    if(age_str.toStdString().empty() || age_str.toInt() == 0) {
        age = -1;
    }
    else {
        age = age_str.toInt();
    }

    // emit the signal: the dogs were updated
    emit updateSignal(old_breed.toStdString(), old_name.toStdString(), breed.toStdString(), name.toStdString(), age, photo.toStdString());
}

int QtGui::getSelectedIndexAdmin()
{
    if (this->listDogs->count() == 0)
        return -1;

    if (this->listDogsUser->count() == 0)
        return -1;

    // get selected indexList
    QModelIndexList indexList = this->listDogs->selectionModel()->selectedIndexes();
    if (indexList.empty())
    {
        this->breedEditAdmin->clear();
        this->nameEditAdmin->clear();
        this->ageEditAdmin->clear();
        this->photoEditAdmin->clear();
        return -1;
    }

    int index = indexList.at(0).row();
    return index;
}

int QtGui::getSelectedIndexUser()
{
    if (this->listDogs->count() == 0)
        return -1;

    if (this->listDogsUser->count() == 0)
        return -1;

    // get selected indexList
    QModelIndexList indexList = this->listDogsUser->selectionModel()->selectedIndexes();
    if (indexList.empty())
    {
        this->breedEditUser->clear();
        this->nameEditUser->clear();
        this->ageEditUser->clear();
        this->photoEditUser->clear();
        return -1;
    }

    int index = indexList.at(0).row();
    return index;
}

void QtGui::listItemChangedAdmin()
{
    int index = this->getSelectedIndexAdmin();
    if (index == -1)
        return;

    if (index >= this->adminService.getDogsVector().size())
        return;

    Dog dog = this->adminService.getDogsVector()[index];

    this->breedEditAdmin->setText(QString::fromStdString(dog.getBreed()));
    this->nameEditAdmin->setText(QString::fromStdString(dog.getName()));
    this->ageEditAdmin->setText(QString::fromStdString(to_string(dog.getAge())));
    this->photoEditAdmin->setText(QString::fromStdString(dog.getPhoto()));
}

void QtGui::listItemChangedUser()
{
    int index = this->getSelectedIndexUser();
    if (index == -1)
        return;

    if (index == this->adminService.getDogsVector().size())
        index = 0;

    if (index > this->adminService.getDogsVector().size() || this->adminService.getDogsVector().empty())
        return;

    Dog dog = this->adminService.getDogsVector()[index];
    if(!first) {
        system(("start chrome " + dog.getPhoto()).c_str());
    }
    first = false;

    this->breedEditUser->setText(QString::fromStdString(dog.getBreed()));
    this->nameEditUser->setText(QString::fromStdString(dog.getName()));
    this->ageEditUser->setText(QString::fromStdString(to_string(dog.getAge())));
    this->photoEditUser->setText(QString::fromStdString(dog.getPhoto()));
}

void QtGui::listItemChangedUserFilter()
{
    QString breed = this->filterBreedEdit->text();
    QString age_str = this->filterAgeEdit->text();
    int age;
    if(age_str.toStdString().empty() || age_str.toInt() == 0) {
        age = -1;
    }
    else {
        age = age_str.toInt();
    }

    int index = this->getSelectedIndexUser();
    if (index == -1)
        return;

    if (index == this->adminService.getFilteredDogs(breed.toStdString(), age).size())
        index = 0;

    if (index > this->adminService.getFilteredDogs(breed.toStdString(), age).size() || this->adminService.getFilteredDogs(breed.toStdString(), age).empty())
        return;

    Dog dog;
    dog = this->adminService.getFilteredDogs(breed.toStdString(), age)[index];
    system(("start chrome " + dog.getPhoto()).c_str());


    this->breedEditUser->setText(QString::fromStdString(dog.getBreed()));
    this->nameEditUser->setText(QString::fromStdString(dog.getName()));
    this->ageEditUser->setText(QString::fromStdString(to_string(dog.getAge())));
    this->photoEditUser->setText(QString::fromStdString(dog.getPhoto()));
}

void QtGui::adoptButtonHandler()
{
    int index = getSelectedIndexUser();
    Dog dog;
    if(!filtered)
        dog = this->adminService.getDogsVector()[index];
    else
    {
        QString breed = this->filterBreedEdit->text();
        QString age_str = this->filterAgeEdit->text();
        int age;
        if(age_str.toStdString().empty() || age_str.toInt() == 0) {
            age = -1;
        }
        else {
            age = age_str.toInt();
        }
        dog = this->adminService.getFilteredDogs(breed.toStdString(), age)[index];
    }
    emit adoptSignal(dog.getBreed(), dog.getName(), dog.getAge(), dog.getPhoto());
}

void QtGui::nextButtonHandler()
{
    next_index = this->getSelectedIndexUser();
    next_index++;
    if (next_index == this->adminService.getDogsVector().size())
        next_index = 0;

    if (next_index > this->adminService.getDogsVector().size() || this->adminService.getDogsVector().empty())
        return;

    Dog dog = this->adminService.getDogsVector()[next_index];

    this->breedEditUser->setText(QString::fromStdString(dog.getBreed()));
    this->nameEditUser->setText(QString::fromStdString(dog.getName()));
    this->ageEditUser->setText(QString::fromStdString(to_string(dog.getAge())));
    this->photoEditUser->setText(QString::fromStdString(dog.getPhoto()));

    this->listDogsUser->setCurrentRow(next_index);
}

void QtGui::update(const string &old_breed, const string &old_name, const string &breed, const string &name, int age, const string &photo) {
    try {
        this->adminService.updateDog(old_breed, old_name, breed, name, age, photo);
    }
    catch (RepositoryException &re) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(re.getErrorMessage()));
    }
    catch (ValidationException &ve) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(ve.getErrorMessage()));
    }
    catch (ServiceException &se) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(se.getErrorMessage()));
    }
    emit listUpdatedSignal();
}

void QtGui::chooseRepoType() {
    QFont f{"Times New Roman", 12};
    chooseRepo = new QWidget{};
    QHBoxLayout* layoutRepo = new QHBoxLayout{};
    buttonCsv = new QPushButton{"CSV Repo"};
    buttonHtml = new QPushButton{"HTML Repo"};
    buttonCsv->setFont(f);
    buttonHtml->setFont(f);
    layoutRepo->addWidget(buttonCsv);
    layoutRepo->addWidget(buttonHtml);
    chooseRepo->setLayout(layoutRepo);
}

void QtGui::undo() {
    try{
        adminService.undo();
        emit listUpdatedSignal();
        QMessageBox::information(nullptr, "Info", "Undo performed!");
    }
    catch (ServiceException& error){
        QMessageBox::information(nullptr, "Info", QString::fromStdString(error.getErrorMessage()));
    }
}

void QtGui::redo() {
    try{
        adminService.redo();
        emit listUpdatedSignal();
        QMessageBox::information(nullptr, "Info", "Redo performed!");
    }
    catch (ServiceException& error){
        QMessageBox::information(nullptr, "Info", QString::fromStdString(error.getErrorMessage()));
    }
}

void QtGui::undoButtonHandler() {
    undo();
}

void QtGui::redoButtonHandler() {
    redo();
}

void QtGui::undoUser() {
    try{
        adminService.undo();
        if(html) {
            userServiceHtml.undo();
        }
        if(csv) {
            userServiceCsv.undo();
        }
        emit listUpdatedSignal();
        emit listUpdatedAdoptionSignal();
        QMessageBox::information(nullptr, "Info", "Undo performed!");
    }
    catch (ServiceException& error){
        QMessageBox::information(nullptr, "Info", QString::fromStdString(error.getErrorMessage()));
    }
}

void QtGui::redoUser() {
    try{
        if(html) {
            userServiceHtml.redo();
        }
        if(csv) {
            userServiceCsv.redo();
        }
        adminService.redo();
        emit listUpdatedSignal();
        emit listUpdatedAdoptionSignal();
        QMessageBox::information(nullptr, "Info", "Redo performed!");
    }
    catch (ServiceException& error){
        QMessageBox::information(nullptr, "Info", QString::fromStdString(error.getErrorMessage()));
    }
}

void QtGui::undoButtonHandlerUser() {
    undoUser();
}

void QtGui::redoButtonHandlerUser() {
    redoUser();
}