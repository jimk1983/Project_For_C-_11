#include "UtilsMacro.h"
#include "UtilsToolStd.h"
#include "UtilsToolXml.h"




bool UtilsFrame::LoadFile(const std::string & sFullPath, TiXmlDocument& XmlDoc)
{
    if ( true != XmlDoc.LoadFile(sFullPath.c_str()) )
    {
        return false;
    }

    return true;
}

bool UtilsFrame::LoadFile(const char* pcFullPath, TiXmlDocument& XmlDoc)
{
    if ( nullptr == pcFullPath)
    {
        return false;
    }

    if (true != XmlDoc.LoadFile(pcFullPath))
    {
        return false;
    }

    return true;
}

bool UtilsFrame::ClearFile(TiXmlDocument& XmlDoc)
{
    XmlDoc.Clear();
    return true;
}





