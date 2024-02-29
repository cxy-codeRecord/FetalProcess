#include "CServiceGenerate.h"
CServiceGenerator::CServiceGenerator()
{
    netService = new CNetService();
}

void CServiceGenerator::initModule()
{
    CController::getInstance()->initServiceGenerator();
}
