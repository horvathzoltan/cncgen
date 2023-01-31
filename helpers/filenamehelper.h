#ifndef FILENAMEHELPER_H
#define FILENAMEHELPER_H

#include "helpers/macro.h"
#include <QDir>

class FileNameHelper{
public:
    static auto GetTestFolderPath()-> QString
    {
#if defined (STRING) && defined (TARGI)
        return QDir(STRING(SOURCE_PATH)).filePath("testdata");
#else
        return ("/home/zoli/cncgen/testdata");
#endif
    }
};

#endif // FILENAMEHELPER_H
