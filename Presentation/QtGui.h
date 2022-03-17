//
// Created by user on 09/05/2021.
//

#ifndef A89_916_SILASCHI_IASMINA_QTGUI_H
#define A89_916_SILASCHI_IASMINA_QTGUI_H

#include <Dog.h>
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <ServiceAdmin.h>
#include <ServiceUser.h>
#include <QTableView>
#include <QShortcut>
#include "ModelView.h"

class QtGui : public QWidget {
Q_OBJECT

private:
    ServiceAdmin &adminService;
    ServiceUser &userServiceCsv;
    ServiceUser &userServiceHtml;
    int next_index = 0;
    bool filtered = false;
    bool csv = false;
    bool html = false;
    bool first = true;
    QWidget* adminWidget;
    QWidget* userWidget;
    QWidget* updateWidget;
    QListWidget* listDogs;
    QListWidget* listDogsUser;
    QLineEdit* breedEditAdmin;
    QLineEdit* nameEditAdmin;
    QLineEdit* ageEditAdmin;
    QTextEdit* photoEditAdmin;
    QLineEdit* breedEditUpdate;
    QLineEdit* nameEditUpdate;
    QLineEdit* ageEditUpdate;
    QTextEdit* photoEditUpdate;
    QLineEdit* breedEditUser;
    QLineEdit* nameEditUser;
    QLineEdit* ageEditUser;
    QTextEdit* photoEditUser;
    QLineEdit* filterBreedEdit;
    QLineEdit* filterAgeEdit;
    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* updateButton;
    QPushButton* undoButton;
    QPushButton* redoButton;
    QPushButton* adoptButton;
    QPushButton* nextButton;
    QPushButton* displayButton;
    QPushButton* filterButton;
    QPushButton* revertButton;
    QPushButton* buttonAdmin;
    QPushButton* buttonUser;
    QPushButton* updateButtonUpdate;
    QPushButton* buttonCsv;
    QPushButton* buttonHtml;
    QWidget* chooseRepo;
    QTableView* adoptionTable = new QTableView;
    TableModel* model = new TableModel(userServiceCsv.getVectorAdoption());
    QShortcut *shortcutUndo;
    QShortcut *shortcutRedo;
    QShortcut *shortcutUndoUser;
    QShortcut *shortcutRedoUser;
    QPushButton* undoButtonUser;
    QPushButton* redoButtonUser;

    void initGui();
    void connectSignalsAndSlots();
    void setInitialGuiState();
    void mainMode();
    void chooseMode(QVBoxLayout *mainLayout, QFont f);
    void chooseRepoType();
    void adminMode();
    void userMode();
    void updateWindow();
    void buttonsAdmin(QVBoxLayout *vLayout, const QFont &f);
    void dogDataAdmin(QVBoxLayout *vLayout, QFont &f);
    void dogDataUser(QVBoxLayout *pLayout, QFont font);
    void buttonsUser(QVBoxLayout *pLayout, QFont font);
    void filterUser(QVBoxLayout *pLayout, QFont font);
    void populateDogList();
    void listItemChangedAdmin();
    void listItemChangedUserFilter();
    void addButtonHandler();
    void deleteButtonHandler();
    int getSelectedIndexAdmin();
    void dogDataUpdate(QVBoxLayout *vLayout, QFont &f);
    void buttonsUpdate(QVBoxLayout *vLayout, const QFont &f);
    void updateButtonHandler();
    void undoButtonHandler();
    void redoButtonHandler();
    void undoButtonHandlerUser();
    void redoButtonHandlerUser();
    void listItemChangedUser();
    int getSelectedIndexUser();
    void nextButtonHandler();
    void adoptButtonHandler();
    void populateAdoptionList();
    void displayButtonHandler();
    void revertButtonHandler();
    void filterButtonHandler();

signals:

    void listUpdatedSignal();
    void listUpdatedAdoptionSignal();
    void addSignal(const string& breed, const string& name, int age, const string& photo);
    void deleteSignal(const string& breed, const string& name);
    void updateSignal(const string& old_breed, const string& old_name, const string& breed, const string& name, int age, const string& photo);
    void adoptSignal(const string&, const string&, int, const string&);

public:

    QtGui(ServiceAdmin &serviceAdmin, ServiceUser &serviceUserCsv, ServiceUser &serviceUserHtml) :
            adminService {serviceAdmin}, userServiceCsv {serviceUserCsv}, userServiceHtml {serviceUserHtml}{
        this->initGui();
        this->connectSignalsAndSlots();
        this->setInitialGuiState();
    }

public slots:
    void add(const string &breed, const string &name, int age, const string &photo);
    void del(const string &breed, const string &name);
    void update(const string &old_breed, const string &old_name, const string &breed, const string &name, int age, const string &photo);
    void adopt(const string& breed, const string& name, int age, const string& photo);
    void undo();
    void redo();
    void undoUser();
    void redoUser();
};


#endif //A89_916_SILASCHI_IASMINA_QTGUI_H
