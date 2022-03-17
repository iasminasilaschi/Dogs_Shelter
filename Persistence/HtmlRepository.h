//
// Created by user on 16/04/2021.
//

#ifndef A67_916_SILASCHI_IASMINA_HTMLREPOSITORY_H
#define A67_916_SILASCHI_IASMINA_HTMLREPOSITORY_H


#include "Repository.h"

class HtmlRepository : public Repository  {
private:
    string &fileName;
    void writeToHtmlFile();
public:
    explicit HtmlRepository(string &fileName);
    void addElement(const TElement& dog) override;
    string getDisplayCommand() override;
    ~HtmlRepository();
};


#endif //A67_916_SILASCHI_IASMINA_HTMLREPOSITORY_H
