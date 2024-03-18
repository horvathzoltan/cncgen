#ifndef TOGCODEMODEL_H
#define TOGCODEMODEL_H

#include <QMap>
#include <lastgeom.h>

#include <gcode/feed.h>
#include <gcode/tool.h>

#include <geometry/gmode.h>


struct ToGCodeModel
{
    LastGeom _lastGeom;
    Feed _last_feed3;
    GMode::Mode _last_gmode;
    qreal _last_hole_diameter;

    Feed _selected_feed3;

    bool _verbose = true;
    qreal _fmax=500;
    qreal _fmin=200;
    bool _isPlot = false;

    qreal _emax=0.1/100;
    qreal _fratio =0.7;
    qreal _movZ=2;
    qreal _safez=0;
    int _last_tool_ix = -1;
    qreal _maxZ=4;
    Point _safe_place = {0,0,0};

    XYMode _XYMode;

    qreal _ratio = 1;
    int _preMillSteps = 3;

    static double dPeck;
    static double dPeck2;

    qreal _safeb=0;
    qreal _overcut =0;

    MMode _MMode;
    Point _offset_xyz;

    qreal _pdwell;
    qreal _peckz_divider = 3;
private:
    QMap<int, Tool> _tools;
    int _selected_tool_ix;
public:

    bool ValidateTool();
    Tool selectedTool(){return _tools[_selected_tool_ix];}
    void selectTool(int v){_selected_tool_ix = v;};
    void clearTools(){_tools.clear();};
    bool toolsContains(int i){return _tools.contains(i);}
    void SetIsPlot(bool v){_isPlot = v;}
    void insertTool(int i, Tool t){_tools.insert(i,t);}
    int seletcedToolIx(){return _selected_tool_ix;}

    void setSelectedToolD(qreal v){_tools[_selected_tool_ix].d = v;};
    void Reset()
    {
        _MMode = {};
        _XYMode=XYMode::XY;

        _last_hole_diameter =-1;
        _lastGeom.Reset();

        _fmax=500;
        _fmin=200;
        clearTools();
        selectTool(-1);
        _emax=0.005;
        _fratio=0.7;
        _movZ=2;
        _maxZ=4;
        _last_tool_ix=-1;
        _selected_feed3 ={};
        _safez = 0;
        _last_gmode=GMode::Undefined;
        _ratio=1;
        _preMillSteps = 3;
        _safeb = 0;
        _overcut = 0;
        _offset_xyz = {};
        _last_feed3 ={};
    }
};


#endif // TOGCODEMODEL_H
