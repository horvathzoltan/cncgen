#include "gcodecommon.h"

const QString GCodeCommon::G1 = QStringLiteral("G:");
const QString GCodeCommon::G2 = QStringLiteral("    ->");
const QString GCodeCommon::T1 = QStringLiteral("T:");
const QString GCodeCommon::T_ERR = QStringLiteral("E:");
const QString GCodeCommon::T_W = QStringLiteral("W:");

const qreal GCodeCommon::SIMI = 5;

const int GCodeCommon::PECKSTEPS_2 = 2; // minden második után hűt
const int GCodeCommon::PECKSTEPS = 5; // ritkábban hűt

const qreal GCodeCommon::PECKSTEP_MILLISEC = 500;
