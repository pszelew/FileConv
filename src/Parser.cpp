#include "Parser.hh"


bool Parser::ParseCmd(std::istringstream & IStrm4Cmds)
{
    std::string Cmd4Preproc = "cpp -P ";
    char Line[LINESIZE];
    std::ostringstream OTmpStrm;
    Cmd4Preproc += cmdFile.c_str();

    FILE * pProc = popen(Cmd4Preproc.c_str(),"r");
    if(!pProc)
        return false;
    while(fgets(Line,LINESIZE,pProc))
    {
        OTmpStrm<<Line;
    }
    IStrm4Cmds.str(OTmpStrm.str());

    return pclose(pProc) == 0;
}
bool Parser::ParseXML(std::istringstream & IStrm4Cmds)
{
    /*TODO*/
    return true;
}