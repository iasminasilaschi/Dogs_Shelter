//
// Created by user on 16/04/2021.
//

#ifndef A67_916_SILASCHI_IASMINA_CSVREPOSITORY_H
#define A67_916_SILASCHI_IASMINA_CSVREPOSITORY_H


#include "Repository.h"

class CsvRepository : public Repository {
private:
    string fileName;
    void readFromCsvFile();
    void writeToCsvFile();
public:
    explicit CsvRepository(string &fileName);
    void addElement(const TElement& dog) override;
    string getDisplayCommand() override;
    ~CsvRepository();
};


#endif //A67_916_SILASCHI_IASMINA_CSVREPOSITORY_H
