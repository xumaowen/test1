
#ifndef QTBASIC_H
#define QTBASIC_H

/* 编译版本 */
#define QT_COMPILE_VERSION_ARM  0
#define QT_COMPILE_VERSION_X86  1

/* QT编译器版本 */
#define QT_C_VERSION   5

#if (QT_C_VERSION < 5)
#define QT_NO_QFTP     0 //QT5起 QFTP 模块需要单独编译，不再作为编译器的基本组件
#else
#define QT_NO_QFTP     1
#endif

#if QT_COMPILE_VERSION_X86

// OpenMP 并行加速
#define USE_OPENMP    0
#endif



// 是否启用PYTHON 程序
#define USE_PYTHON  0


#include <math.h>
#include <time.h>
#include <zlib.h>
#include <dlfcn.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <netdb.h>
#include <assert.h>
#include <signal.h>
#include <dirent.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <pthread.h>
#include <termios.h>
#include <arpa/inet.h>

#include <linux/types.h>
#include <linux/ioctl.h>
#include <linux/sockios.h>
#include "linux/soundcard.h"

#include <net/if.h>
#include <net/if_arp.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#include <sys/un.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/sysinfo.h>

#include <iostream>



#ifdef  __cplusplus
extern "C"{
#endif

typedef void                 VOID;
typedef int                  INT;
typedef unsigned int         UINT;
typedef long                 LONG;
typedef unsigned long        ULONG;
typedef char                 CHAR;
typedef unsigned char        UCHAR;
typedef short                SHORT;
typedef unsigned short       USHORT;
typedef long long            DLONG;
typedef unsigned long long   DULONG;
//typedef unsigned long        SIZE_T;
typedef int                  BOOL_T;
typedef float                FLOAT;
typedef double               DOUBLE;
typedef long                 TIME_T;
typedef VOID*                HANDLE;
typedef unsigned char        UINT8;
typedef unsigned short       UINT16;
typedef unsigned int         UINT32;
typedef loff_t               LOFF_T;
typedef size_t               SIZE_T;

#define  IN
#define  OUT
#define  INOUT

#ifndef NULL
#define NULL         ((void *)(0))
#endif

#define BOOL_TRUE   (1)
#define BOOL_FALSE  (0)
#define ERR_COMMON_SUCCEED                      0x000000      /* 执行成功 */
#define ERR_COMMON_FAIL                         0x000001      /* 执行失败 */
#define ERR_COMMON_INVALID_PARAM                0x000002      /* 输入参数非法 */
#define ERR_COMMON_NO_MEMORY                    0x000003      /* 系统内存不足 */
#define ERR_COMMON_NO_MSG                       0x000004      /* 没有要发送的消息 */
#define ERR_COMMON_TIMEOUT                      0x000005      /* 等待消息超时失败 */
#define ERR_COMMON_DATELENERR                   0x000006      /* 数据长度非法 */
#define ERR_COMMON_MUXLOCKERR                   0x000007      /* 锁出问题 */
#define ERR_COMMON_IP_CONFLICT                  0x000008      /* IP地址冲突 */
#define ERR_COMMON_NOT_COMPLETE                 0x000009      /* 消息没收全 */
#define ERR_COMMON_FILE_NOT_CHANGE              0x00000a      /* 文件没有发生变更 */


/* 图形程序全局分辨率 */
#define  QTYRESM  ((int)(480 * 1))
#define  QTXRESM  ((int)(800 * 1))

#define  QTXREF   (0)
#define  QTYREF   (0)

#define  QT_DESKBACK_MOUSELEN              ((int)(QTYRESM * 0.4))     /* 鼠标纵向移动多少像素触发切换桌面背景操作 */
#define  QT_DESKBACK_MAXNUM                (13)                       /* 桌面背景最大数量 */
#define  QT_DESKBACK_MOVE_MAXLINE          ((int)(QTXRESM * 0.56))    /* 桌面移动起始坐标最大值,超过最大值不移动 */
#define  QT_DESKBACK_ATACHSETUP_XPOS       (QTXRESM / 8 * 7)          /* 鼠标向左滑动触发设置界面的最小起始X坐标 */
#define  QT_DESKBACK_ATACHSETUP_MOUSELEN   (QTXRESM / 16)             /* 鼠标向左滑动触发设置界面的最小鼠标移动距离 */

#define QT_MAX_DIRLEN    (256)    /* 目录名称最大长度 */
#define QT_MAX_CMDLEN    (256)    /* 命令名称最大长度 */
#define QT_MAX_FILELEN    (64)    /* 文件名最大长度 */

/* 字符串长度 */
#define QT_STRLEN_4        (4)
#define QT_STRLEN_16       (16)
#define QT_STRLEN_32       (32)
#define QT_STRLEN_64       (64)
#define QT_STRLEN_128      (128)
#define QT_STRLEN_256      (256)
#define QT_STRLEN_512      (512)
#define QT_STRLEN_1024     (1024)

#define QT_THRFLAG_DETACHED       (0x00000040)  /* 标志:线程可分离属性 */
#define QT_THRFLAG_JOINABLE       (0x00010000)  /* 标志:线程可加入属性 */
#define QT_THRFLAG_SCHED_FIFO     (0x00020000)  /* 使用资源先到先得调度方式 */
#define QT_THRFLAG_SCHED_RR       (0x00040000)  /* 使用按优先级调度方式（优先级高的先调度） */
#define QT_THRFLAG_SCHED_DEFAULT  (0x00080000)  /* 使用默认调度方式 */

#define QT_THR_JOINABLE     (0)     /* 线程可加入属性 */
#define QT_THR_DETACHED     (1)     /* 线程可分离属性 */
#define QT_THR_SCHED_OTHER  (0)     /* 分时调度策略 */
#define QT_THR_SCHED_FIFO   (1)     /* 实时调度策略，先到先服务 创建时优先级大于0(1-99) */
#define QT_THR_SCHED_RR     (2)     /* 实时调度策略，时间片轮转 创建时优先级大于0(1-99) */
#define QT_DEFAULT_THREAD_PRIORITY    (127)  /* 默认优先级 */

#define QT_PR_SET_NAME      PR_SET_NAME

/* 没有用到的参数处理 */
#define UNUSED_ARG(x)              ((void) x)

/* 内存管理链表最大节点数 */
#define QT_MEMMGR_LIST_NUM         (1000)

/* 断言assert(lExpression); */
#define QT_ASSERT(lExpression) \
{ \
    if (!(lExpression)) \
    { \
        printf("Assert [%d][%s]\n", __LINE__, __FILE__); \
        return; \
    } \
}
#define QT_ASSERT_RETURN(lExpression, err) \
{ \
    if (!(lExpression)) \
    { \
        printf("Assert [%d][%s]\n", __LINE__, __FILE__); \
        return err; \
    } \
}

/* 日志文件名 */
#define QT_LOG_FILENAME   "/tmp/qtsys_log.txt"

/* 文本行结束标志 */
#define LINEEND ((USHORT)0X0A0D)

#define INVALID_FD  (-1)

#define QT_PI   (3.1415926)

/* ARP相关宏 */
#define QT_MAC_BCAST_ADDR      "\xff\xff\xff\xff\xff\xff"        /* 清空MAC地址时所用的字符串 */
#define QT_ETH_P_ARP           (0x0806)                          /* Arp包类型 */
#define QT_ETH_P_RARP          (0x8035)                          /* Rarp包类型 */
#define QT_SOCK_PACKET         (10)                              /* socket类型 */
#define QT_ETH_P_IP            (0x0800)                          /* Arp包的协议类型 */
#define QT_IP_BYTE_LEN         (4)                               /* 使用字节表示的IP地址的长度 */
#define QT_MAC_TYTE_LEN        (6)                               /* 使用字节表示的MAC地址长度 */
#define QT_PAD_LEN             (18)                              /* ARP报文中pad字段所占的长度 */

/* 下面定义了ICMP协议的消息类型 */
#define QT_ICMP_TYPE_ECHOREPLY       (0)   /* Echo(请求回显报文)接收应答  */
#define QT_ICMP_TYPE_ECHOSEND        (8)   /* Echo(请求回显报文)发送请求 */
#define QT_ICMP_TYPE_ECHONOTARRIVE   (3)   /* 目的地址不存在 */
#define QT_ICMP_TYPE_TIMEOUT         (11)  /* 当前数据传送超过了允许的最大路由器通过数 */

/* 默认连接互联网的网络接口 */
#if QT_COMPILE_VERSION_ARM
#define QT_DEFAULT_NETINTERFAVE   "eth0"
#define QT_DEFAULT_VPNINTERFAVE   "eth0"
#else
#define QT_DEFAULT_NETINTERFAVE   "eth2"
#define QT_DEFAULT_VPNINTERFAVE   "eth3"
#endif

/* DNS配置文件路径 */
#define DDNS_CONF_FILE         "/etc/resolv.conf"

/* DNS配置模板 */
#define DDNS_CONF_FILE_DATE    "nameserver %s \nnameserver %s\n"

/* 计算结构成员相对于结构头的偏移 */
#ifndef offsetof
#define offsetof(stru, member)      ((LONG) &((stru *)0)->member)
#else
#undef offsetof
#define offsetof(stru, member)      ((LONG) &((stru *)0)->member)
#endif

/* 计算结构成员的所占字节数 */
#ifndef sizeofmember
#define sizeofmember(stru, member)    (sizeof(((stru *)0)->member))
#else
#undef sizeofmember
#define sizeofmember(stru, member)    (sizeof(((stru *)0)->member))
#endif

/* 计算结构体成员所在结构体的首地址 */
#ifndef container_of
#define container_of(point, stru, member) \
{ \
    const typeof(((stru *)0)->member) *__mptr = (point); \
    (stru *)((char *)__mptr - offsetof(stru, member)); \
}
#else
#undef container_of
#define container_of(point, stru, member) \
{ \
    const typeof(((stru *)0)->member) *__mptr = (point); \
    (stru *)((char *)__mptr - offsetof(stru, member)); \
}
#endif

typedef void *(*QT_THR_FUNC)(void*);  /* 线程函数 */

typedef pthread_mutex_t                 QT_MUTEX_S;
typedef struct epoll_event              QT_EPOLL_EVENT_S;
typedef struct stat                     QT_STAT_S;
typedef fd_set                          QT_FD_SET_S;
#define QT_FD_ZERO(c)                   FD_ZERO(c)
#define QT_FD_SET(c, d)                 FD_SET(c, d)
#define QT_FD_ISSET(c, d)               FD_ISSET(c, d)
typedef time_t                          QT_TIME_S;

typedef struct sockaddr                 QT_SOCKADDR_S;

// 将系统错误码转换为字符串(linux下)
#define strerror                        strerror

void CPtest_Write(IN ULONG ulLine, IN const char *pszStr, ...);

#define Cprintf(format, arg...) \
    CPtest_Write(__LINE__, format, ##arg);


void CTest(void);


#ifdef  __cplusplus
}
#endif

#endif


