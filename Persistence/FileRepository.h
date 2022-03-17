//
// Created by user on 16/04/2021.
//

#ifndef A67_916_SILASCHI_IASMINA_FILEREPOSITORY_H
#define A67_916_SILASCHI_IASMINA_FILEREPOSITORY_H


#include "Repository.h"

class FileRepository : public Repository {
private:
    string &fileName;
    void readFromFile();
    void writeToFile();
public:
    explicit FileRepository(string &fileName);
    void addElement(const TElement& dog) override;
    TElement deleteElement(const TElement& dog) override;
    TElement updateElement(const TElement& old_dog, const TElement& new_dog) override;
    ~FileRepository();
};


#endif //A67_916_SILASCHI_IASMINA_FILEREPOSITORY_H
