#ifndef FILENAMEHELPER_H
#define FILENAMEHELPER_H

#include "common/macrofactory/macro.h"
#include <QDir>

class FileNameHelper{
public:
    static auto GetTestFolderPath()-> QString
    {
        return QDir(STRING(SOURCE_PATH)).filePath("testdata");
    }
};

#endif // FILENAMEHELPER_H
