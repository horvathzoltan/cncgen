#include "helpers/logger.h"
#include "togcodemodel.h"

// ToGCodeModel::ToGCodeModel() {}

double ToGCodeModel::dPeck = 15;
double ToGCodeModel::dPeck2 = 6;

auto ToGCodeModel::ValidateTool()->bool
{
    if(_selected_tool_ix==-1){
        zInfo(QStringLiteral("no tool selected"));
        return false;
    }
    if(!_tools.contains(_selected_tool_ix)) {
        zInfo("tool not found: "+QString::number(_selected_tool_ix));
        return false;
    }
    return true;
}
