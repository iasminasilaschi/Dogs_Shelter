#include <iostream>
#include <Tests.h>
#include <ServiceAdmin.h>
#include <Console.h>
#include <ServiceUser.h>
#include <FileRepository.h>
#include <CsvRepository.h>
#include <HtmlRepository.h>

using namespace std;

//int main() {
//
//    string runWithTests;
//    cout<<"Run with tests?(yes/no):";
//    cin>>runWithTests;
//    if(runWithTests == "yes") {
//        Tests tests;
//        tests.runAllTests();
//        cout << endl;
//    }
//
//    string userFile, adminFile;
//    adminFile = R"(C:\Users\user\CLionProjects\a67-916-Silaschi-Iasmina\dogs.txt)";
//    FileRepository repoAdmin(adminFile);
//    ServiceAdmin serviceAdmin{repoAdmin};
//
//    string repoType;
//    bool chose = false;
//    while (!chose){
//        cout<<"Which type of file do you wish to use?(csv/html):";
//        cin>>repoType;
//        if(repoType == "csv"){
//            userFile = R"(C:\Users\user\CLionProjects\a67-916-Silaschi-Iasmina\dogs.csv)";
//            CsvRepository repoUser(userFile);
//            ServiceUser serviceUser{repoUser};
//            Console ui{serviceAdmin, serviceUser};
//            ui.run();
//            chose = true;
//        }
//        else if(repoType == "html"){
//            userFile = R"(C:\Users\user\CLionProjects\a67-916-Silaschi-Iasmina\dogs.html)";
//            HtmlRepository repoUser(userFile);
//            ServiceUser serviceUser{repoUser};
//            Console ui{serviceAdmin, serviceUser};
//            ui.run();
//            chose = true;
//        }
//    }
//    return 0;
//}

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    string adminFile, userCsvFile, user;
//    adminFile = R"(C:\Users\user\CLionProjects\a89-916-Silaschi-Iasmina\dogs.txt)";
//    userCsvFile = R"(C:\Users\user\CLionProjects\a89-916-Silaschi-Iasmina\dogs.csv)";
//    FileRepository repoAdmin(adminFile);
//    ServiceAdmin serviceAdmin{repoAdmin};
//    CsvRepository repoUserCsv{userCsvFile};
//    ServiceUser serviceUser{repoUserCsv};
//    QtGui gui {serviceAdmin, serviceUser};
//    gui.show();
//    return a.exec();
//}

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    QFont f{"Times New Roman", 12};
//    QWidget* chooseRepo = new QWidget{};
//    QHBoxLayout* layoutRepo = new QHBoxLayout{};
//    QPushButton* buttonCsv = new QPushButton{"CSV Repo"};
//    QPushButton* buttonHtml = new QPushButton{"HTML Repo"};
//    buttonCsv->setFont(f);
//    buttonHtml->setFont(f);
//    layoutRepo->addWidget(buttonCsv);
//    layoutRepo->addWidget(buttonHtml);
//    chooseRepo->setLayout(layoutRepo);
//    chooseRepo->show();
//    QObject::connect(buttonCsv, &QPushButton::clicked,chooseRepo,[=](){
//        string adminFile, userCsvFile;
//        adminFile = R"(C:\Users\user\CLionProjects\a89-916-Silaschi-Iasmina\dogs.txt)";
//        userCsvFile = R"(C:\Users\user\CLionProjects\a89-916-Silaschi-Iasmina\dogs.csv)";
//        FileRepository repoAdmin(adminFile);
//        ServiceAdmin serviceAdmin{repoAdmin};
//        CsvRepository repoUserCsv{userCsvFile};
//        ServiceUser serviceUser{repoUserCsv};
//        chooseRepo->hide();
//        QtGui gui {serviceAdmin, serviceUser};
//        gui.show();
//        return a.exec();
//    });
//    QObject::connect(buttonHtml, &QPushButton::clicked,chooseRepo,[=](){
//        string adminFile, userCsvFile, userHtmlFile;
//        adminFile = R"(C:\Users\user\CLionProjects\a89-916-Silaschi-Iasmina\dogs.txt)";
//        userHtmlFile = R"(C:\Users\user\CLionProjects\a89-916-Silaschi-Iasmina\dogs.html)";
//        FileRepository repoAdmin(adminFile);
//        ServiceAdmin serviceAdmin{repoAdmin};
//        HtmlRepository repoUserHtml{userHtmlFile};
//        ServiceUser serviceUser{repoUserHtml};
//        chooseRepo->hide();
//        QtGui gui {serviceAdmin, serviceUser};
//        gui.show();
//        return a.exec();
//    });
//}
