
#ifndef QTBASIC_H
#define QTBASIC_H

/* ����汾 */
#define QT_COMPILE_VERSION_ARM  0
#define QT_COMPILE_VERSION_X86  1

/* QT�������汾 */
#define QT_C_VERSION   5

#if (QT_C_VERSION < 5)
#define QT_NO_QFTP     0 //QT5�� QFTP ģ����Ҫ�������룬������Ϊ�������Ļ������
#else
#define QT_NO_QFTP     1
#endif

#if QT_COMPILE_VERSION_X86

// OpenMP ���м���
#define USE_OPENMP    0
#endif



// �Ƿ�����PYTHON ����
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
#define ERR_COMMON_SUCCEED                      0x000000      /* ִ�гɹ� */
#define ERR_COMMON_FAIL                         0x000001      /* ִ��ʧ�� */
#define ERR_COMMON_INVALID_PARAM                0x000002      /* ��������Ƿ� */
#define ERR_COMMON_NO_MEMORY                    0x000003      /* ϵͳ�ڴ治�� */
#define ERR_COMMON_NO_MSG                       0x000004      /* û��Ҫ���͵���Ϣ */
#define ERR_COMMON_TIMEOUT                      0x000005      /* �ȴ���Ϣ��ʱʧ�� */
#define ERR_COMMON_DATELENERR                   0x000006      /* ���ݳ��ȷǷ� */
#define ERR_COMMON_MUXLOCKERR                   0x000007      /* �������� */
#define ERR_COMMON_IP_CONFLICT                  0x000008      /* IP��ַ��ͻ */
#define ERR_COMMON_NOT_COMPLETE                 0x000009      /* ��Ϣû��ȫ */
#define ERR_COMMON_FILE_NOT_CHANGE              0x00000a      /* �ļ�û�з������ */


/* ͼ�γ���ȫ�ֱַ��� */
#define  QTYRESM  ((int)(480 * 1))
#define  QTXRESM  ((int)(800 * 1))

#define  QTXREF   (0)
#define  QTYREF   (0)

#define  QT_DESKBACK_MOUSELEN              ((int)(QTYRESM * 0.4))     /* ��������ƶ��������ش����л����汳������ */
#define  QT_DESKBACK_MAXNUM                (13)                       /* ���汳��������� */
#define  QT_DESKBACK_MOVE_MAXLINE          ((int)(QTXRESM * 0.56))    /* �����ƶ���ʼ�������ֵ,�������ֵ���ƶ� */
#define  QT_DESKBACK_ATACHSETUP_XPOS       (QTXRESM / 8 * 7)          /* ������󻬶��������ý������С��ʼX���� */
#define  QT_DESKBACK_ATACHSETUP_MOUSELEN   (QTXRESM / 16)             /* ������󻬶��������ý������С����ƶ����� */

#define QT_MAX_DIRLEN    (256)    /* Ŀ¼������󳤶� */
#define QT_MAX_CMDLEN    (256)    /* ����������󳤶� */
#define QT_MAX_FILELEN    (64)    /* �ļ�����󳤶� */

/* �ַ������� */
#define QT_STRLEN_4        (4)
#define QT_STRLEN_16       (16)
#define QT_STRLEN_32       (32)
#define QT_STRLEN_64       (64)
#define QT_STRLEN_128      (128)
#define QT_STRLEN_256      (256)
#define QT_STRLEN_512      (512)
#define QT_STRLEN_1024     (1024)

#define QT_THRFLAG_DETACHED       (0x00000040)  /* ��־:�߳̿ɷ������� */
#define QT_THRFLAG_JOINABLE       (0x00010000)  /* ��־:�߳̿ɼ������� */
#define QT_THRFLAG_SCHED_FIFO     (0x00020000)  /* ʹ����Դ�ȵ��ȵõ��ȷ�ʽ */
#define QT_THRFLAG_SCHED_RR       (0x00040000)  /* ʹ�ð����ȼ����ȷ�ʽ�����ȼ��ߵ��ȵ��ȣ� */
#define QT_THRFLAG_SCHED_DEFAULT  (0x00080000)  /* ʹ��Ĭ�ϵ��ȷ�ʽ */

#define QT_THR_JOINABLE     (0)     /* �߳̿ɼ������� */
#define QT_THR_DETACHED     (1)     /* �߳̿ɷ������� */
#define QT_THR_SCHED_OTHER  (0)     /* ��ʱ���Ȳ��� */
#define QT_THR_SCHED_FIFO   (1)     /* ʵʱ���Ȳ��ԣ��ȵ��ȷ��� ����ʱ���ȼ�����0(1-99) */
#define QT_THR_SCHED_RR     (2)     /* ʵʱ���Ȳ��ԣ�ʱ��Ƭ��ת ����ʱ���ȼ�����0(1-99) */
#define QT_DEFAULT_THREAD_PRIORITY    (127)  /* Ĭ�����ȼ� */

#define QT_PR_SET_NAME      PR_SET_NAME

/* û���õ��Ĳ������� */
#define UNUSED_ARG(x)              ((void) x)

/* �ڴ�����������ڵ��� */
#define QT_MEMMGR_LIST_NUM         (1000)

/* ����assert(lExpression); */
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

/* ��־�ļ��� */
#define QT_LOG_FILENAME   "/tmp/qtsys_log.txt"

/* �ı��н�����־ */
#define LINEEND ((USHORT)0X0A0D)

#define INVALID_FD  (-1)

#define QT_PI   (3.1415926)

/* ARP��غ� */
#define QT_MAC_BCAST_ADDR      "\xff\xff\xff\xff\xff\xff"        /* ���MAC��ַʱ���õ��ַ��� */
#define QT_ETH_P_ARP           (0x0806)                          /* Arp������ */
#define QT_ETH_P_RARP          (0x8035)                          /* Rarp������ */
#define QT_SOCK_PACKET         (10)                              /* socket���� */
#define QT_ETH_P_IP            (0x0800)                          /* Arp����Э������ */
#define QT_IP_BYTE_LEN         (4)                               /* ʹ���ֽڱ�ʾ��IP��ַ�ĳ��� */
#define QT_MAC_TYTE_LEN        (6)                               /* ʹ���ֽڱ�ʾ��MAC��ַ���� */
#define QT_PAD_LEN             (18)                              /* ARP������pad�ֶ���ռ�ĳ��� */

/* ���涨����ICMPЭ�����Ϣ���� */
#define QT_ICMP_TYPE_ECHOREPLY       (0)   /* Echo(������Ա���)����Ӧ��  */
#define QT_ICMP_TYPE_ECHOSEND        (8)   /* Echo(������Ա���)�������� */
#define QT_ICMP_TYPE_ECHONOTARRIVE   (3)   /* Ŀ�ĵ�ַ������ */
#define QT_ICMP_TYPE_TIMEOUT         (11)  /* ��ǰ���ݴ��ͳ�������������·����ͨ���� */

/* Ĭ�����ӻ�����������ӿ� */
#if QT_COMPILE_VERSION_ARM
#define QT_DEFAULT_NETINTERFAVE   "eth0"
#define QT_DEFAULT_VPNINTERFAVE   "eth0"
#else
#define QT_DEFAULT_NETINTERFAVE   "eth2"
#define QT_DEFAULT_VPNINTERFAVE   "eth3"
#endif

/* DNS�����ļ�·�� */
#define DDNS_CONF_FILE         "/etc/resolv.conf"

/* DNS����ģ�� */
#define DDNS_CONF_FILE_DATE    "nameserver %s \nnameserver %s\n"

/* ����ṹ��Ա����ڽṹͷ��ƫ�� */
#ifndef offsetof
#define offsetof(stru, member)      ((LONG) &((stru *)0)->member)
#else
#undef offsetof
#define offsetof(stru, member)      ((LONG) &((stru *)0)->member)
#endif

/* ����ṹ��Ա����ռ�ֽ��� */
#ifndef sizeofmember
#define sizeofmember(stru, member)    (sizeof(((stru *)0)->member))
#else
#undef sizeofmember
#define sizeofmember(stru, member)    (sizeof(((stru *)0)->member))
#endif

/* ����ṹ���Ա���ڽṹ����׵�ַ */
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

typedef void *(*QT_THR_FUNC)(void*);  /* �̺߳��� */

typedef pthread_mutex_t                 QT_MUTEX_S;
typedef struct epoll_event              QT_EPOLL_EVENT_S;
typedef struct stat                     QT_STAT_S;
typedef fd_set                          QT_FD_SET_S;
#define QT_FD_ZERO(c)                   FD_ZERO(c)
#define QT_FD_SET(c, d)                 FD_SET(c, d)
#define QT_FD_ISSET(c, d)               FD_ISSET(c, d)
typedef time_t                          QT_TIME_S;

typedef struct sockaddr                 QT_SOCKADDR_S;

// ��ϵͳ������ת��Ϊ�ַ���(linux��)
#define strerror                        strerror

void CPtest_Write(IN ULONG ulLine, IN const char *pszStr, ...);

#define Cprintf(format, arg...) \
    CPtest_Write(__LINE__, format, ##arg);


void CTest(void);


#ifdef  __cplusplus
}
#endif

#endif


