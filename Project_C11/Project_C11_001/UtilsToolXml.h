/*ͨ�õĶ�ȡ�����ļ��Ĺ���*/
/*��Ҫʵ�ֵĽӿڹ�������:
1. ��ȡ���ڵ�
2. ���ݱ�ǩ����ȡ��ǰ�ڵ����һ�ڵ���Ϣ�������ж��
3. ���ݻ�ȡ��ǩ��������Ϣ
4. ��ȡ�����ض������Զԣ��ҵ���ǩ��������
5. ��ȡ��ǩ���м�ֵ
6. ��ȡ���·���µ������ļ�·��*/

#include "tinyxml/tinyxml.h"

namespace UtilsFrame
{
    /*����XML�ļ�*/
    bool LoadFile(const std::string& sFilePath, TiXmlDocument& XmlDoc);
    bool LoadFile(const char* pcFilePath, TiXmlDocument& XmlDoc);
    /*����XML�ļ�*/
    bool ClearFile(TiXmlDocument& XmlDoc);
}


