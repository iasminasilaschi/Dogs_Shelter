//
// Created by user on 09/05/2021.
//

#include <QtWidgets/QApplication>
#include <FileRepository.h>
#include <ServiceAdmin.h>
#include <HtmlRepository.h>
#include <CsvRepository.h>
#include "QtGui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    string adminFile, userCsvFile, userHtmlFile;
    adminFile = "dogs.txt";
    userCsvFile = "dogs.csv";
    userHtmlFile = R"(C:\Users\user\CLionProjects\a10-916-Silaschi-Iasmina-1\dogs.html)";
    FileRepository repoAdmin(adminFile);
    ServiceAdmin serviceAdmin{repoAdmin};
    CsvRepository repoUserCsv{userCsvFile};
    HtmlRepository repoUserHtml{userHtmlFile};
    ServiceUser serviceUserCsv{repoUserCsv};
    ServiceUser serviceUserHtml{repoUserHtml};
    QtGui gui {serviceAdmin, serviceUserCsv, serviceUserHtml};
    gui.show();
    return a.exec();
}