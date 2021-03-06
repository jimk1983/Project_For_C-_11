/* 文件说明*/
/* Tool关于XML的工具类的封装测试*/
#include "UtilsToolStd.h"
#include "UtilsToolXml.h"

long VOS_DirGetCurrentPath(char *pcDirPath, int iMaxLen)
{
    int iRet = 0;
    int index = 0;

#if VOS_PLAT_LINUX
    iRet = readlink("/proc/self/exe", pcDirPath, iMaxLen);
    if (iRet < 0 || iRet >= iMaxLen)
    {
        return VOS_ERR;
    }

    //获取当前目录绝对路径，即去掉程序名
    for (index = iRet; index >= 0; --index)
    {
        if (pcDirPath[index] == '/')
        {
            pcDirPath[index + 1] = '\0';

            break;
        }
    }
#elif 1
    char *pcStr = NULL;

    GetModuleFileNameA(NULL, pcDirPath, MAX_PATH);

    pcStr = strrchr(pcDirPath, ('\\'));
    if (NULL != pcStr)
    {
        pcStr[1] = 0;
    }

#endif

    return 0;
}

class CPrimerJob
{
public:
    CPrimerJob() {};
    ~CPrimerJob() {};
public:
    int nums;
private:
    int count;
};

int main()
{
    TiXmlDocument xDocXml;
    std::string sFullPath = "D:\\Work\\OpenProject\\Primer_C_11\\Project_C11\\Debug\\config\\Config.xml";
    const char *pcFilePath = "D:\\Work\\OpenProject\\Primer_C_11\\Project_C11\\Debug\\config\\Config.xml";

    char acCfgPath[MAX_PATH] = {0};
    CPrimerJob *newjob = new CPrimerJob;
    CPrimerJob &prmjob = *newjob;

    newjob->nums = 10;

    std::cout << "11 newjob.nums=" << newjob->nums << std::endl;

    prmjob.nums = 12;
    
    std::cout << "22 prmjob.nums=" << newjob->nums << std::endl;

    free(newjob);
    newjob = (CPrimerJob *)0x000000001;

    std::cout << "33 prmjob.nums=" << prmjob.nums << std::endl;


    std::cout << "44 prmjob.nums=" << newjob->nums << std::endl;

    VOS_DirGetCurrentPath(acCfgPath, MAX_PATH);
    strcat_s(acCfgPath, MAX_PATH-1, "config\\Config.xml");

    if (!UtilsFrame::LoadFile(acCfgPath, xDocXml))
    {
        std::cout << "loadFile error: File=" << acCfgPath << std::endl;
        return -1;
    }
    else
    {
        std::cout << "LoadFile successful! File=" << acCfgPath << std::endl;
    }
    
    UtilsFrame::XDocToString(xDocXml, sFullPath);

    UtilsFrame::ClearFile(xDocXml);
    
    return 0;
}



#if 0
void testTemplate()
{
    std::string test = "hell@HUONasdfHHYHUI";

    UtilsFrame::ToUpper(test);

    std::cout << test << std::endl;

    UtilsFrame::ToLower(test);

    std::cout << test << std::endl;

    std::string tDest;

    // UtilsFrame::ToValue(test, tDest);
    int a = 0;
    int b = 1;
    long la = 0;

    //UtilsFrame::SetValue(a, tDest);

    UtilsFrame::SetValue(b, a);

    UtilsFrame::SetValue<std::string, std::string>(test, tDest);

    std::cout << "test=" << test << std::endl;
    std::cout << "tDest=" << tDest << std::endl;

    //UtilsFrame::StaticCast(a, la);
}

#endif