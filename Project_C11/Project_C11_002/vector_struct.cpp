#include "pch.h"
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>



struct ipinfo
{
	uint32_t src_addr;
	uint16_t src_port;
	uint32_t  dst_addr;
	uint16_t  dst_port;
	uint32_t result;
};

void vector_struct()
{
	struct ipinfo a0 = { 0xc0a81012, 56302, 0xc0a81121, 3306, 1 };
	struct ipinfo a1 = { 0xc0a81012, 56302, 0xc0a81121, 3306, 0 };
	struct ipinfo a2 = { 0xc0a81011, 56302, 0xc0a81121, 3306, 0 };
	struct ipinfo a3 = { 0xc0a81015, 56302, 0xc0a81121, 3306, 0 };
	struct ipinfo a4 = { 0xc0a81067, 56302, 0xc0a81131, 3306, 0 };
	struct ipinfo a5 = { 0xc0a81032, 56302, 0xc0a81151, 3306, 0 };
	struct ipinfo a6 = { 0xc0a81035, 56302, 0xc0a81221, 3306, 0 };
	struct ipinfo a7 = { 0xc0a81021, 56302, 0xc0a81621, 3306, 0 };
	struct ipinfo a8 = { 0xc0a81012, 56302, 0xc0a81121, 3306, 1 };
	struct ipinfo a9 = { 0xc0a81021, 56302, 0xc0a81621, 3306, 1 };
	int i = 0;
	std::vector<ipinfo> list_;
	printf("-------->11\n");
	//插入
	list_.push_back(a1);
	list_.push_back(a2);
	list_.push_back(a3);
	list_.push_back(a4);
	list_.push_back(a5);
	//查找
	i = 0;
	for (std::vector<ipinfo>::iterator it = list_.begin(); it != list_.end();)
	{
		printf("list[%d] the info:[%08x:%d] --> [%08x:%d] ,result=%d, i=%d\n",
			list_.size(), it->src_addr, it->src_port, it->dst_addr, it->dst_port, it->result,i);

		//std::cout << it->src_addr << " " << std::endl;
		i++;
		++it;
	}
	printf("-------->22\n");
	//插入
	list_.push_back(a6);
	list_.push_back(a7);
	list_.push_back(a8);

	//遍历
	i = 0;
	for (std::vector<ipinfo>::iterator it = list_.begin(); it != list_.end();)
	{
		printf("list[%d] the info:[%08x:%d] --> [%08x:%d] ,result=%d, i=%d\n",
			list_.size(), it->src_addr, it->src_port, it->dst_addr, it->dst_port, it->result, i);

		//std::cout << it->src_addr << " " << std::endl;
		i++;
		++it;
	}

	printf("-------->33\n");
	//删除
	i = 0;
	for (std::vector<ipinfo>::iterator it = list_.begin(); it != list_.end();)
	{
		printf("list[%d] the info:[%08x:%d] --> [%08x:%d] ,result=%d, i=%d\n",
			list_.size(), it->src_addr, it->src_port, it->dst_addr, it->dst_port, it->result, i);
		if ( 0xc0a81015 == it->src_addr || 0xc0a81121 == it->dst_addr)
		{
			it = list_.erase(it);
		}
		else
		{
			++it;
		}
		//std::cout << it->src_addr << " " << std::endl;
		i++;
	}


	printf("-------->44\n");

	list_.push_back(a8);

	//遍历
	i = 0;
	for (std::vector<ipinfo>::iterator it = list_.begin(); it != list_.end();)
	{
		printf("list[%d] the info:[%08x:%d] --> [%08x:%d] ,result=%d, i=%d\n",
			list_.size(), it->src_addr, it->src_port, it->dst_addr, it->dst_port, it->result, i);

		//std::cout << it->src_addr << " " << std::endl;
		i++;
		++it;
	}


	//
	printf("-->endl\n");


}























