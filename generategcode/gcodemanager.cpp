#include "helpers/logger.h"
#include "gcodemanager.h"

GCodeManager::GCodeManager()
{

}

GCodeManager::GCodeManager(const QString& s){
    _gcodes.append(s);
}

bool GCodeManager::Append(const QString &g, const QString& err, const QString& comment)
{
    if(!g.isEmpty()){
        if(comment.isEmpty()){_gcodes.append(g);}
        else{_gcodes.append(g+" ("+comment+')');}
    }
    if(!err.isEmpty()){
        zInfo(err);
        _gcodes.append("(error: "+err+")");
        return false;
    }
    return true;
}

bool GCodeManager::Append2(QStringList* gs, const QString &g, const QString& err, const QString& comment)
{
    if(!gs) return false;
    if(!g.isEmpty()){
        if(comment.isEmpty()){gs->append(g);}
        else{gs->append(g+" ("+comment+')');}
    }
    if(!err.isEmpty()){
        zInfo(err);
        gs->append("(error: "+err+")");
        return false;
    }
    return true;
}
