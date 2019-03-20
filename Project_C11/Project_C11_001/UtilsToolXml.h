/*通用的读取配置文件的功能*/
/*需要实现的接口功能如下:
1. 获取根节点
2. 根据标签名获取当前节点的下一节点信息，可能有多个
3. 根据获取标签的属性信息
4. 获取根据特定的属性对，找到标签所有属性
5. 获取标签的中间值
6. 获取相对路径下的配置文件路径*/

#include "tinyxml/tinyxml.h"

namespace UtilsFrame
{
    /*加载XML文件*/
    bool LoadFile(const std::string& sFilePath, TiXmlDocument& XmlDoc);
    bool LoadFile(const char* pcFilePath, TiXmlDocument& XmlDoc);
    /*清理XML文件*/
    bool ClearFile(TiXmlDocument& XmlDoc);
}


