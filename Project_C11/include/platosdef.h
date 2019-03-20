/******************************************************************************

                  版权所有 (C), 2018-2028, 杭州友机技术有限公司

 ******************************************************************************
  文 件 名   : pubdefs.h
  版 本 号   : 初稿
  作    者   : 蒋康
  生成日期   : 2019年2月14日
  最近修改   :
  功能描述   : 系统定义
  函数列表   :
  修改历史   :
  1.日    期   : 2019年2月14日
    作    者   : 蒋康
    修改内容   : 创建文件

******************************************************************************/
#ifndef _PLATOS_DEF_H_
#define _PLATOS_DEF_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************/
/***************** 系统配置 ***********************/
/**************************************************/
/*定义的平台是MAC系统*/
#define     VOS_PLAT_MAC             0
/*定义的平台是Win系统*/
#define     VOS_PLAT_WIN             1
/*定义的平台是Linux系统*/
#define     VOS_PLAT_LINUX           0
/*定义的是32位系统*/
#define     VOS_PLATCPU_32             1
/*定义的是64位系统*/
#define     VOS_PLATCPU_64             0
/*定义的大小端*/
#define     VOS_PLAT_BIG_ENDIAN        0


/**************************************************/
/***************** 系统定义 ***********************/
/**************************************************/

#if VOS_PLAT_LINUX
#ifndef CHAR
typedef char                CHAR, *PCHAR;
#endif

#ifndef BYTE
typedef signed char         BYTE, *PBYTE;
#endif


#ifndef LONG
typedef signed int          LONG, *PLONG;
#endif


#ifndef UCHAR
typedef unsigned char       UCHAR, *PUCHAR;
#endif



#ifndef ULONG
typedef unsigned int        ULONG, *PULONG;
#endif


#ifndef VOID
#define VOID void
#endif

#ifndef PVOID
typedef VOID *PVOID;
#endif

#ifndef BOOL
typedef unsigned char BOOL;
#endif

#ifndef SIZE_T
typedef unsigned int SIZE_T;
#endif

#ifndef NULL
#define NULL ((VOID*)0)
#endif

#endif

#ifndef BYTE
typedef signed char         INT8, *PINT8;
#endif
#ifndef BYTE
typedef unsigned char       UINT8, *PUINT8;
#endif
#ifndef SHORT
typedef signed short        SHORT, *PSHORT;
#endif
#ifndef USHORT
typedef unsigned short      USHORT, *PUSHORT;
#endif
#ifndef INT32
typedef signed int          INT32, *PINT32;
#endif
#ifndef UINT32
typedef unsigned int        UINT32, *PUINT32;
#endif


#if VOS_PLATCPU_32
typedef struct tagDUlong
{
    struct tagulong_ul
    {
        unsigned int ulHi_l;
        unsigned int ulLo_l;
    }x;
    
    struct taglong_us
    {
        #if VOS_PLAT_BIG_ENDIAN
            USHORT usHiHi_s;
            USHORT usHiLo_s;
            USHORT usLoHi_s;
            USHORT usLoLo_s;
        #else
            unsigned short usHiLo_s;
            unsigned short usHiHi_s;
            unsigned short usLoLo_s;
            unsigned short usLoHi_s;
        #endif
    }y;
    #define     ulHi    x.ulHi_l
    #define     ulLo    x.ulLo_l
}DULONG, *PDULONG;


#elif VOS_PLATCPU_64

#ifndef LONG64
typedef signed long long        LONG64, *PLONG64;

#endif

#ifndef ULONG64
typedef unsigned long long      ULONG64, *PULONG64;
#endif

#ifndef SIZE_T
typedef unsigned long long      SIZE_T;
#endif

#endif


/**************************************************/
/***************** 系统常用宏       ********************/
/**************************************************/


/*将DULONG 转为ULONG64*/
#define VOS_DULONG_TO_ULONG64(dulSrc, ullDst64) \
        (ullDst64) = ((ULONG64)((dulSrc).ulHi) << 32 \
        | ((ULONG64)((dulSrc).ulLo)) );

/*将ULONG转化为DULONG*/
#define VOS_ULONG64_TO_DULONG(ullSrc64, dulDst) \
    (dulDst).ulHi  =  (unsigned int)((ullSrc64)>>32;\
    (dulDst).ulLo =  (unsigned int)((ullSrc64);

    
#define IN 
#define OUT
#define INOUT
    
    
#define VOS_COREDUMP        {char *ptr=0x00;*(ptr)=0x00;}
#define VOS_ASSERT(expr)     if(!(expr))VOS_COREDUMP
    
#ifndef VOS_OK
#define VOS_OK               0
#endif
        
#ifndef VOS_ERR
#define VOS_ERR             (~(0))
#endif


#ifndef SYS_OK
#define SYS_OK              VOS_OK
#endif

#ifndef SYS_ERR
#define SYS_ERR             VOS_ERR
#endif


#ifndef VOS_TRUE
#define VOS_TRUE            1
#endif
    
#ifndef VOS_FALSE
#define VOS_FALSE           0
#endif


#define VOS_INVALID_VAL32   0xFFFFFFFF
#define VOS_INVALID_VAL64   0xFFFFFFFFFFFFFFFF



/**************************************************/
/***************** 系统错误码       ********************/
/**************************************************/

/*系统错误*/
#define VOS_SYS_ERR                         -1
/*参数错误*/
#define VOS_SYS_PARAM_INVALID               -2
/*超时错误*/
#define VOS_SYS_TIMEOUT                     -3
/*阻塞*/
#define VOS_SYS_EWOULDBLOCK                 -4
/*已经存在*/
#define VOS_SYS_EXIST                       -5



/**************************************************/
/***************** 系统重定义       ********************/
/**************************************************/


#ifndef SYS_TRUE
#define SYS_TRUE                            VOS_TRUE
#endif
    
#ifndef SYS_FALSE
#define SYS_FALSE                           VOS_FALSE
#endif

#ifndef SYS_ERR_PARAM
#define SYS_ERR_PARAM                       VOS_SYS_PARAM_INVALID
#endif

#ifndef SYS_ERR_TIMEOUT
#define SYS_ERR_TIMEOUT                     VOS_SYS_TIMEOUT
#endif

#ifndef SYS_ERR_EWOULDBLOCK                
#define SYS_ERR_EWOULDBLOCK                 VOS_SYS_EWOULDBLOCK
#endif

#ifndef MAX_PATH
#define MAX_PATH                            260
#endif

#ifndef SYS_IPV4LEN
#define SYS_IPV4LEN                         32
#endif

/**************************************************/
/***************** 系统头文件 *********************/
/**************************************************/

/* Linux系统 */
#if VOS_PLAT_LINUX
#include <sys/signal.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <pthread.h>
#include <math.h>
#include <sys/timerfd.h>

#include <netdb.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <net/route.h>

#include <linux/rtnetlink.h>    

#include <dirent.h>

/*BPF规格*/
#include <linux/if_ether.h>
#include <net/if.h>
#include <linux/filter.h>

/*支持pcap扩展*/
//#include <pcap/pcap.h>   //suse有该头文件
//#include <pcap.h>

#define atomic_inc(x) __sync_add_and_fetch((x),1)   
#define atomic_dec(x) __sync_sub_and_fetch((x),1)   
#define atomic_add(x,y) __sync_add_and_fetch((x),(y))   
#define atomic_sub(x,y) __sync_sub_and_fetch((x),(y)) 

#elif  VOS_PLAT_WIN
/*该处定义的是纯C的头文件，C++的请包含在UtilsMacro.h中*/
#include <Winsock2.h>
#include <Windows.h>
#include <WS2tcpip.h>
#include <TimeAPI.h>
#include <mswsock.h>
#include <stdio.h>
#include <process.h>
#include <winsvc.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ShlObj.h>
#include <signal.h>
#include <time.h>
#include <stdarg.h>
#include <assert.h>
#include <ctype.h> 
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Winmm.lib")

#elif  VOS_PLAT_MAC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <pthread.h> 
#include <math.h>


#endif



#ifdef __cplusplus
}
#endif

#endif

