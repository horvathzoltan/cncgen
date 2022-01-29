#include "filenamehelper.h"
#include "common/macrofactory/macro.h"

#include <QDir>

FileNameHelper::FileNameHelper()
{

}

QString FileNameHelper::GetTestFolderPath()
{
    return QDir(STRING(SOURCE_PATH)).filePath("testdata");
}
