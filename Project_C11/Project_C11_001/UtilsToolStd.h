/****说明****/
/****模板: 定义和实现一定要在头文件中, 特例化和普通函数可以在外部******/

namespace UtilsFrame
{
    /**********************************************************************/
    /************************** 数据类型转换 ******************************/
    /**********************************************************************/
    template<typename T, typename K> 
    bool SetValue(const T& tSrc, K& tDst);
    
    template<typename T>
    bool SetValue(const T& tSrc, T& tDst);

    template<>
    bool SetValue(const std::string &sSrc, std::string &sDst);
    bool SetValue(const std::string &sSrc, std::string &sDst);
    
    /*********************************************************************/
    /*************************** 字符串处理 ******************************/
    /*********************************************************************/
    /*转换大写*/
    bool ToUpper(std::string &sStr);
    bool ToUpper(const std::string &sSrc, std::string  &sDst);
    bool ToUpper(char *pcStr, int iLen);
    bool ToUpper(const char *pcSrc, int iSrcLen, char *pcDst, int iDstLen);
    
    /*转换小写*/
    bool ToLower(std::string &sStr);
    bool ToLower(const std::string &sSrc, std::string  &sDst);
    bool ToLower(char *pcStr, int iLen);
    bool ToLower(const char *pcSrc, int iSrcLen, char *pcDst, int iDstLen);
    
    /*********************************************************************/
    /*************************** 类型处理 *******************************/
    /*********************************************************************/
    /*判断2个类型是否一致*/
    template <typename T, typename K>
    bool IsOwnSelf(const T& tVct1, const K& tVct2); 

    /*将源强制转换为目标类型赋值*/
    template <typename T, typename K>
    bool StaticCast(const T& tSrc, K& tDst);

    /*相同类型，直接赋值*/
    template <typename T>
    bool StaticCast(const T& tSrc, T& tDst);
};

template<typename T, typename K>
bool UtilsFrame::SetValue(const T& tSrc, K& tDst)
{
    if (IsOwnSelf(tSrc, tDst))
        return false;

    StaticCast(tSrc, tDst);
    return true;
}

template<typename T>
bool UtilsFrame::SetValue(const T& tSrc, T& tDst)
{
    if (IsOwnSelf(tSrc, tDst))
        return false;

    tDst = tSrc;
    return true;
}

template <typename T, typename K>
bool UtilsFrame::StaticCast(const T& tSrc, K& tDst)
{
    tDst = static_cast<K>(tSrc);
    return true;
}

template <typename T>
bool UtilsFrame::StaticCast(const T& tSrc, T& tDst)
{
    tDst = tSrc;
    return true;
}

template <typename T, typename K>
bool UtilsFrame::IsOwnSelf(const T& tVct1, const K& tVct2)
{
    const void* p1 = &tVct1;
    const void* p2 = &tVct2;
    return p1 == p2;
}