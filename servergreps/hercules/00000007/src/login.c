# 1 "../../../server-code/src/login/login.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../../../server-code/src/login/login.c"
# 23 "../../../server-code/src/login/login.c"
# 1 "../../../server-code/src/login/login.h" 1
# 24 "../../../server-code/src/login/login.h"
# 1 "../../../server-code/src/common/hercules.h" 1
# 23 "../../../server-code/src/common/hercules.h"
# 1 "../../../server-code/src/config/core.h" 1
# 90 "../../../server-code/src/config/core.h"
# 1 "../../../server-code/src/config/./renewal.h" 1
# 91 "../../../server-code/src/config/core.h" 2
# 1 "../../../server-code/src/config/./secure.h" 1
# 92 "../../../server-code/src/config/core.h" 2
# 1 "../../../server-code/src/config/./classes/general.h" 1
# 93 "../../../server-code/src/config/core.h" 2




# 1 "../../../server-code/src/config/./const.h" 1
# 62 "../../../server-code/src/config/./const.h"
 typedef short defType;
# 98 "../../../server-code/src/config/core.h" 2
# 24 "../../../server-code/src/common/hercules.h" 2
# 1 "../../../server-code/src/common/cbasetypes.h" 1
# 116 "../../../server-code/src/common/cbasetypes.h"
# 1 "/usr/include/inttypes.h" 1 3 4
# 25 "/usr/include/inttypes.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 361 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 410 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 411 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 362 "/usr/include/features.h" 2 3 4
# 385 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 386 "/usr/include/features.h" 2 3 4
# 26 "/usr/include/inttypes.h" 2 3 4

# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdint.h" 1 3 4
# 9 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdint.h" 3 4
# 1 "/usr/include/stdint.h" 1 3 4
# 26 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wchar.h" 1 3 4
# 27 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 28 "/usr/include/stdint.h" 2 3 4
# 36 "/usr/include/stdint.h" 3 4

# 36 "/usr/include/stdint.h" 3 4
typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;

typedef long int int64_t;







typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef unsigned int uint32_t;



typedef unsigned long int uint64_t;
# 65 "/usr/include/stdint.h" 3 4
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;

typedef long int int_least64_t;






typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;

typedef unsigned long int uint_least64_t;
# 90 "/usr/include/stdint.h" 3 4
typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
# 103 "/usr/include/stdint.h" 3 4
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
# 119 "/usr/include/stdint.h" 3 4
typedef long int intptr_t;


typedef unsigned long int uintptr_t;
# 134 "/usr/include/stdint.h" 3 4
typedef long int intmax_t;
typedef unsigned long int uintmax_t;
# 10 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdint.h" 2 3 4
# 28 "/usr/include/inttypes.h" 2 3 4






typedef int __gwchar_t;
# 266 "/usr/include/inttypes.h" 3 4





typedef struct
  {
    long int quot;
    long int rem;
  } imaxdiv_t;
# 290 "/usr/include/inttypes.h" 3 4
extern intmax_t imaxabs (intmax_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern intmax_t strtoimax (const char *__restrict __nptr,
      char **__restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));


extern uintmax_t strtoumax (const char *__restrict __nptr,
       char ** __restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));


extern intmax_t wcstoimax (const __gwchar_t *__restrict __nptr,
      __gwchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));


extern uintmax_t wcstoumax (const __gwchar_t *__restrict __nptr,
       __gwchar_t ** __restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));
# 432 "/usr/include/inttypes.h" 3 4

# 117 "../../../server-code/src/common/cbasetypes.h" 2

# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/limits.h" 1 3 4
# 34 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/limits.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/syslimits.h" 1 3 4






# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/limits.h" 1 3 4
# 168 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/limits.h" 3 4
# 1 "/usr/include/limits.h" 1 3 4
# 143 "/usr/include/limits.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 1 3 4
# 160 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/local_lim.h" 1 3 4
# 38 "/usr/include/x86_64-linux-gnu/bits/local_lim.h" 3 4
# 1 "/usr/include/linux/limits.h" 1 3 4
# 39 "/usr/include/x86_64-linux-gnu/bits/local_lim.h" 2 3 4
# 161 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 2 3 4
# 144 "/usr/include/limits.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/posix2_lim.h" 1 3 4
# 148 "/usr/include/limits.h" 2 3 4
# 169 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/limits.h" 2 3 4
# 8 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/syslimits.h" 2 3 4
# 35 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/limits.h" 2 3 4
# 119 "../../../server-code/src/common/cbasetypes.h" 2
# 1 "/usr/include/time.h" 1 3 4
# 29 "/usr/include/time.h" 3 4








# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 38 "/usr/include/time.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/time.h" 1 3 4
# 42 "/usr/include/time.h" 2 3 4
# 55 "/usr/include/time.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;







typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
# 121 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
# 122 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;
# 56 "/usr/include/time.h" 2 3 4



typedef __clock_t clock_t;



# 73 "/usr/include/time.h" 3 4


typedef __time_t time_t;



# 91 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 103 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
# 120 "/usr/include/time.h" 3 4
struct timespec
  {
    __time_t tv_sec;
    __syscall_slong_t tv_nsec;
  };








struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;


  long int tm_gmtoff;
  const char *tm_zone;




};








struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };


struct sigevent;





typedef __pid_t pid_t;
# 186 "/usr/include/time.h" 3 4



extern clock_t clock (void) __attribute__ ((__nothrow__ , __leaf__));


extern time_t time (time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));


extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));





extern size_t strftime (char *__restrict __s, size_t __maxsize,
   const char *__restrict __format,
   const struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));

# 221 "/usr/include/time.h" 3 4
# 1 "/usr/include/xlocale.h" 1 3 4
# 27 "/usr/include/xlocale.h" 3 4
typedef struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
} *__locale_t;


typedef __locale_t locale_t;
# 222 "/usr/include/time.h" 2 3 4

extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     const char *__restrict __format,
     const struct tm *__restrict __tp,
     __locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
# 236 "/usr/include/time.h" 3 4



extern struct tm *gmtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));



extern struct tm *localtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));





extern struct tm *gmtime_r (const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));



extern struct tm *localtime_r (const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));





extern char *asctime (const struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));


extern char *ctime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));







extern char *asctime_r (const struct tm *__restrict __tp,
   char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));


extern char *ctime_r (const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));




extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;




extern char *tzname[2];



extern void tzset (void) __attribute__ ((__nothrow__ , __leaf__));



extern int daylight;
extern long int timezone;





extern int stime (const time_t *__when) __attribute__ ((__nothrow__ , __leaf__));
# 319 "/usr/include/time.h" 3 4
extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));


extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));


extern int dysize (int __year) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 334 "/usr/include/time.h" 3 4
extern int nanosleep (const struct timespec *__requested_time,
        struct timespec *__remaining);



extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__ , __leaf__));


extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __attribute__ ((__nothrow__ , __leaf__));


extern int clock_settime (clockid_t __clock_id, const struct timespec *__tp)
     __attribute__ ((__nothrow__ , __leaf__));






extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       const struct timespec *__req,
       struct timespec *__rem);


extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__ , __leaf__));




extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) __attribute__ ((__nothrow__ , __leaf__));


extern int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));


extern int timer_settime (timer_t __timerid, int __flags,
     const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__ , __leaf__));


extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __attribute__ ((__nothrow__ , __leaf__));


extern int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));





extern int timespec_get (struct timespec *__ts, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 430 "/usr/include/time.h" 3 4

# 120 "../../../server-code/src/common/cbasetypes.h" 2
# 140 "../../../server-code/src/common/cbasetypes.h"

# 140 "../../../server-code/src/common/cbasetypes.h"
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef int8_t sint8;
typedef int16_t sint16;
typedef int32_t sint32;
typedef int64_t sint64;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
# 196 "../../../server-code/src/common/cbasetypes.h"
typedef long int ppint;
typedef long int ppint8;
typedef long int ppint16;
typedef long int ppint32;

typedef unsigned long int ppuint;
typedef unsigned long int ppuint8;
typedef unsigned long int ppuint16;
typedef unsigned long int ppuint32;





# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 149 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4

# 149 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4
typedef long int ptrdiff_t;
# 328 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4
typedef int wchar_t;
# 426 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
# 211 "../../../server-code/src/common/cbasetypes.h" 2
# 227 "../../../server-code/src/common/cbasetypes.h"

# 227 "../../../server-code/src/common/cbasetypes.h"
typedef intptr_t intptr;
typedef uintptr_t uintptr;







  typedef int64 sysint;
  typedef uint64 usysint;
# 305 "../../../server-code/src/common/cbasetypes.h"
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdbool.h" 1 3 4
# 306 "../../../server-code/src/common/cbasetypes.h" 2
# 395 "../../../server-code/src/common/cbasetypes.h"
# 1 "/usr/include/ctype.h" 1 3 4
# 28 "/usr/include/ctype.h" 3 4

# 39 "/usr/include/ctype.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 36 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 2 3 4
# 60 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 29 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 2 3 4






# 1 "/usr/include/x86_64-linux-gnu/bits/byteswap-16.h" 1 3 4
# 36 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 2 3 4
# 44 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4

# 44 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
static __inline unsigned int
__bswap_32 (unsigned int __bsx)
{
  return __builtin_bswap32 (__bsx);
}
# 108 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __builtin_bswap64 (__bsx);
}
# 61 "/usr/include/endian.h" 2 3 4
# 40 "/usr/include/ctype.h" 2 3 4






enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
# 79 "/usr/include/ctype.h" 3 4
extern const unsigned short int **__ctype_b_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_tolower_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_toupper_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 104 "/usr/include/ctype.h" 3 4






extern int isalnum (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha (int) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit (int) __attribute__ ((__nothrow__ , __leaf__));
extern int islower (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint (int) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit (int) __attribute__ ((__nothrow__ , __leaf__));



extern int tolower (int __c) __attribute__ ((__nothrow__ , __leaf__));


extern int toupper (int __c) __attribute__ ((__nothrow__ , __leaf__));








extern int isblank (int) __attribute__ ((__nothrow__ , __leaf__));


# 150 "/usr/include/ctype.h" 3 4
extern int isascii (int __c) __attribute__ ((__nothrow__ , __leaf__));



extern int toascii (int __c) __attribute__ ((__nothrow__ , __leaf__));



extern int _toupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int _tolower (int) __attribute__ ((__nothrow__ , __leaf__));
# 271 "/usr/include/ctype.h" 3 4
extern int isalnum_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int islower_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));

extern int isblank_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));



extern int __tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));


extern int __toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
# 347 "/usr/include/ctype.h" 3 4

# 396 "../../../server-code/src/common/cbasetypes.h" 2
# 417 "../../../server-code/src/common/cbasetypes.h"
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 98 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;
# 418 "../../../server-code/src/common/cbasetypes.h" 2
# 25 "../../../server-code/src/common/hercules.h" 2
# 25 "../../../server-code/src/login/login.h" 2
# 1 "../../../server-code/src/common/core.h" 1
# 25 "../../../server-code/src/common/core.h"
# 1 "../../../server-code/src/common/db.h" 1
# 90 "../../../server-code/src/common/db.h"

# 90 "../../../server-code/src/common/db.h"
enum DBReleaseOption {
 DB_RELEASE_NOTHING = 0x0,
 DB_RELEASE_KEY = 0x1,
 DB_RELEASE_DATA = 0x2,
 DB_RELEASE_BOTH = DB_RELEASE_KEY|DB_RELEASE_DATA,
};
# 117 "../../../server-code/src/common/db.h"
enum DBType {
 DB_INT,
 DB_UINT,
 DB_STRING,
 DB_ISTRING,
 DB_INT64,
 DB_UINT64,
};
# 148 "../../../server-code/src/common/db.h"
enum DBOptions {
 DB_OPT_BASE = 0x00,
 DB_OPT_DUP_KEY = 0x01,
 DB_OPT_RELEASE_KEY = 0x02,
 DB_OPT_RELEASE_DATA = 0x04,
 DB_OPT_RELEASE_BOTH = DB_OPT_RELEASE_KEY|DB_OPT_RELEASE_DATA,
 DB_OPT_ALLOW_NULL_KEY = 0x08,
 DB_OPT_ALLOW_NULL_DATA = 0x10,
};
# 169 "../../../server-code/src/common/db.h"
union DBKey {
 int i;
 unsigned int ui;
 const char *str;
 char *mutstr;
 int64 i64;
 uint64 ui64;
};
# 186 "../../../server-code/src/common/db.h"
enum DBDataType {
 DB_DATA_INT,
 DB_DATA_UINT,
 DB_DATA_PTR,
};
# 201 "../../../server-code/src/common/db.h"
struct DBData {
 enum DBDataType type;
 union {
  int i;
  unsigned int ui;
  void *ptr;
 } u;
};
# 220 "../../../server-code/src/common/db.h"
typedef struct DBData (*DBCreateData)(union DBKey key, va_list args);
# 237 "../../../server-code/src/common/db.h"
typedef int (*DBApply)(union DBKey key, struct DBData *data, va_list args);
# 250 "../../../server-code/src/common/db.h"
typedef int (*DBMatcher)(union DBKey key, struct DBData data, va_list args);
# 264 "../../../server-code/src/common/db.h"
typedef int (*DBComparator)(union DBKey key1, union DBKey key2, unsigned short maxlen);
# 276 "../../../server-code/src/common/db.h"
typedef uint64 (*DBHasher)(union DBKey key, unsigned short maxlen);
# 290 "../../../server-code/src/common/db.h"
typedef void (*DBReleaser)(union DBKey key, struct DBData data, enum DBReleaseOption which);
# 304 "../../../server-code/src/common/db.h"
struct DBIterator {
# 314 "../../../server-code/src/common/db.h"
 struct DBData *(*first)(struct DBIterator *self, union DBKey *out_key);
# 325 "../../../server-code/src/common/db.h"
 struct DBData *(*last)(struct DBIterator *self, union DBKey *out_key);
# 336 "../../../server-code/src/common/db.h"
 struct DBData *(*next)(struct DBIterator *self, union DBKey *out_key);
# 347 "../../../server-code/src/common/db.h"
 struct DBData *(*prev)(struct DBIterator *self, union DBKey *out_key);
# 357 "../../../server-code/src/common/db.h"
 
# 357 "../../../server-code/src/common/db.h" 3 4
_Bool 
# 357 "../../../server-code/src/common/db.h"
     (*exists)(struct DBIterator *self);
# 372 "../../../server-code/src/common/db.h"
 int (*remove)(struct DBIterator *self, struct DBData *out_data);






 void (*destroy)(struct DBIterator *self);

};







struct DBMap {
# 400 "../../../server-code/src/common/db.h"
 struct DBIterator *(*iterator)(struct DBMap *self);
# 409 "../../../server-code/src/common/db.h"
 
# 409 "../../../server-code/src/common/db.h" 3 4
_Bool 
# 409 "../../../server-code/src/common/db.h"
     (*exists)(struct DBMap *self, union DBKey key);
# 418 "../../../server-code/src/common/db.h"
 struct DBData *(*get)(struct DBMap *self, union DBKey key);
# 438 "../../../server-code/src/common/db.h"
 unsigned int (*getall)(struct DBMap *self, struct DBData **buf, unsigned int max, DBMatcher match, ...);
# 456 "../../../server-code/src/common/db.h"
 unsigned int (*vgetall)(struct DBMap *self, struct DBData **buf, unsigned int max, DBMatcher match, va_list args);
# 472 "../../../server-code/src/common/db.h"
 struct DBData *(*ensure)(struct DBMap *self, union DBKey key, DBCreateData create, ...);
# 486 "../../../server-code/src/common/db.h"
 struct DBData *(*vensure)(struct DBMap *self, union DBKey key, DBCreateData create, va_list args);
# 499 "../../../server-code/src/common/db.h"
 int (*put)(struct DBMap *self, union DBKey key, struct DBData data, struct DBData *out_data);
# 511 "../../../server-code/src/common/db.h"
 int (*remove)(struct DBMap *self, union DBKey key, struct DBData *out_data);
# 525 "../../../server-code/src/common/db.h"
 int (*foreach)(struct DBMap *self, DBApply func, ...);
# 537 "../../../server-code/src/common/db.h"
 int (*vforeach)(struct DBMap *self, DBApply func, va_list args);
# 553 "../../../server-code/src/common/db.h"
 int (*clear)(struct DBMap *self, DBApply func, ...);
# 567 "../../../server-code/src/common/db.h"
 int (*vclear)(struct DBMap *self, DBApply func, va_list args);
# 584 "../../../server-code/src/common/db.h"
 int (*destroy)(struct DBMap *self, DBApply func, ...);
# 599 "../../../server-code/src/common/db.h"
 int (*vdestroy)(struct DBMap *self, DBApply func, va_list args);







 unsigned int (*size)(struct DBMap *self);







 enum DBType (*type)(struct DBMap *self);







 enum DBOptions (*options)(struct DBMap *self);

};
# 745 "../../../server-code/src/common/db.h"
struct db_interface {
# 758 "../../../server-code/src/common/db.h"
enum DBOptions (*fix_options) (enum DBType type, enum DBOptions options);
# 768 "../../../server-code/src/common/db.h"
DBComparator (*default_cmp) (enum DBType type);
# 778 "../../../server-code/src/common/db.h"
DBHasher (*default_hash) (enum DBType type);
# 797 "../../../server-code/src/common/db.h"
DBReleaser (*default_release) (enum DBType type, enum DBOptions options);
# 808 "../../../server-code/src/common/db.h"
DBReleaser (*custom_release) (enum DBReleaseOption which);
# 834 "../../../server-code/src/common/db.h"
struct DBMap *(*alloc) (const char *file, const char *func, int line, enum DBType type, enum DBOptions options, unsigned short maxlen);







union DBKey (*i2key) (int key);







union DBKey (*ui2key) (unsigned int key);







union DBKey (*str2key) (const char *key);







union DBKey (*i642key) (int64 key);







union DBKey (*ui642key) (uint64 key);







struct DBData (*i2data) (int data);







struct DBData (*ui2data) (unsigned int data);







struct DBData (*ptr2data) (void *data);
# 907 "../../../server-code/src/common/db.h"
int (*data2i) (struct DBData *data);
# 916 "../../../server-code/src/common/db.h"
unsigned int (*data2ui) (struct DBData *data);
# 925 "../../../server-code/src/common/db.h"
void* (*data2ptr) (struct DBData *data);






void (*init) (void);







void (*final) (void);
};


struct linkdb_node {
 struct linkdb_node *next;
 struct linkdb_node *prev;
 void *key;
 void *data;
};

typedef void (*LinkDBFunc)(void* key, void* data, va_list args);


void linkdb_insert (struct linkdb_node** head, void *key, void* data);
void linkdb_replace (struct linkdb_node** head, void *key, void* data);
void* linkdb_search (struct linkdb_node** head, void *key);
void* linkdb_erase (struct linkdb_node** head, void *key);
void linkdb_final (struct linkdb_node** head);
void linkdb_vforeach(struct linkdb_node** head, LinkDBFunc func, va_list ap);
void linkdb_foreach (struct linkdb_node** head, LinkDBFunc func, ...);

void db_defaults(void);


extern struct db_interface *DB;
# 26 "../../../server-code/src/common/core.h" 2
# 34 "../../../server-code/src/common/core.h"
enum server_types {
 SERVER_TYPE_UNKNOWN = 0x0,
 SERVER_TYPE_LOGIN = 0x1,
 SERVER_TYPE_CHAR = 0x2,
 SERVER_TYPE_MAP = 0x4,
};


enum E_CORE_ST {
 CORE_ST_STOP = 0,
 CORE_ST_RUN,
 CORE_ST_LAST
};


enum cmdline_options {
 CMDLINE_OPT_NORMAL = 0x0,
 CMDLINE_OPT_PARAM = 0x1,
 CMDLINE_OPT_SILENT = 0x2,
 CMDLINE_OPT_PREINIT = 0x4,
};
typedef 
# 55 "../../../server-code/src/common/core.h" 3 4
       _Bool 
# 55 "../../../server-code/src/common/core.h"
            (*CmdlineExecFunc)(const char *name, const char *params);
struct CmdlineArgData {
 unsigned int pluginID;
 unsigned int options;
 char *name;
 char shortname;
 CmdlineExecFunc func;
 char *help;
};

struct cmdline_interface {
 struct { int _max_; int _len_; struct CmdlineArgData *_data_; } args_data;

 void (*init) (void);
 void (*final) (void);
 
# 70 "../../../server-code/src/common/core.h" 3 4
_Bool 
# 70 "../../../server-code/src/common/core.h"
     (*arg_add) (unsigned int pluginID, const char *name, char shortname, CmdlineExecFunc func, const char *help, unsigned int options);
 int (*exec) (int argc, char **argv, unsigned int options);
 
# 72 "../../../server-code/src/common/core.h" 3 4
_Bool 
# 72 "../../../server-code/src/common/core.h"
     (*arg_next_value) (const char *name, int current_arg, int argc);
 const char *(*arg_source) (struct CmdlineArgData *arg);
};

struct core_interface {
 int arg_c;
 char **arg_v;

 int runflag;
 char *server_name;
 enum server_types server_type;



 void (*shutdown_callback)(void);
};






extern void cmdline_args_init_local(void);
extern int do_init(int,char**);
extern void set_server_type(void);
extern void do_abort(void);
extern int do_final(void);







void cmdline_defaults(void);


extern struct core_interface *core;
extern struct cmdline_interface *cmdline;
# 26 "../../../server-code/src/login/login.h" 2

# 1 "../../../server-code/src/common/mmo.h" 1
# 225 "../../../server-code/src/common/mmo.h"
struct hplugin_data_store;

enum item_types {
 IT_HEALING = 0,
 IT_UNKNOWN,
 IT_USABLE,
 IT_ETC,
 IT_WEAPON,
 IT_ARMOR,
 IT_CARD,
 IT_PETEGG,
 IT_PETARMOR,
 IT_UNKNOWN2,
 IT_AMMO,
 IT_DELAYCONSUME,
 IT_CASH = 18,
 IT_MAX
};




enum quest_state {
 Q_INACTIVE,
 Q_ACTIVE,
 Q_COMPLETE,
};


struct quest {
 int quest_id;
 unsigned int time;
 int count[3];
 enum quest_state state;
};

struct item {
 int id;
 short nameid;
 short amount;
 unsigned int equip;
 char identify;
 char refine;
 char attribute;
 short card[4];
 unsigned int expire_time;
 char favorite;
 unsigned char bound;
 uint64 unique_id;
};


enum equip_pos {
 EQP_NONE = 0x000000,
 EQP_HEAD_LOW = 0x000001,
 EQP_HEAD_MID = 0x000200,
 EQP_HEAD_TOP = 0x000100,
 EQP_HAND_R = 0x000002,
 EQP_HAND_L = 0x000020,
 EQP_ARMOR = 0x000010,
 EQP_SHOES = 0x000040,
 EQP_GARMENT = 0x000004,
 EQP_ACC_L = 0x000008,
 EQP_ACC_R = 0x000080,
 EQP_COSTUME_HEAD_TOP = 0x000400,
 EQP_COSTUME_HEAD_MID = 0x000800,
 EQP_COSTUME_HEAD_LOW = 0x001000,
 EQP_COSTUME_GARMENT = 0x002000,

 EQP_AMMO = 0x008000,
 EQP_SHADOW_ARMOR = 0x010000,
 EQP_SHADOW_WEAPON = 0x020000,
 EQP_SHADOW_SHIELD = 0x040000,
 EQP_SHADOW_SHOES = 0x080000,
 EQP_SHADOW_ACC_R = 0x100000,
 EQP_SHADOW_ACC_L = 0x200000,
};

struct point {
 unsigned short map;
 short x,y;
};

enum e_skill_flag
{
 SKILL_FLAG_PERMANENT,
 SKILL_FLAG_TEMPORARY,
 SKILL_FLAG_PLAGIARIZED,
 SKILL_FLAG_UNUSED,
 SKILL_FLAG_PERM_GRANTED,


 SKILL_FLAG_REPLACED_LV_0,
};

enum e_mmo_charstatus_opt {
 OPT_NONE = 0x0,
 OPT_SHOW_EQUIP = 0x1,
 OPT_ALLOW_PARTY = 0x2,
};

enum e_item_bound_type {
 IBT_NONE = 0x0,
 IBT_MIN = 0x1,
 IBT_ACCOUNT = 0x1,
 IBT_GUILD = 0x2,
 IBT_PARTY = 0x3,
 IBT_CHARACTER = 0x4,
 IBT_MAX = 0x4,
};

enum {
 OPTION_NOTHING = 0x00000000,
 OPTION_SIGHT = 0x00000001,
 OPTION_HIDE = 0x00000002,
 OPTION_CLOAK = 0x00000004,
 OPTION_FALCON = 0x00000010,
 OPTION_RIDING = 0x00000020,
 OPTION_INVISIBLE = 0x00000040,
 OPTION_ORCISH = 0x00000800,
 OPTION_WEDDING = 0x00001000,
 OPTION_RUWACH = 0x00002000,
 OPTION_CHASEWALK = 0x00004000,
 OPTION_FLYING = 0x00008000,
 OPTION_XMAS = 0x00010000,
 OPTION_TRANSFORM = 0x00020000,
 OPTION_SUMMER = 0x00040000,
 OPTION_DRAGON1 = 0x00080000,
 OPTION_WUG = 0x00100000,
 OPTION_WUGRIDER = 0x00200000,
 OPTION_MADOGEAR = 0x00400000,
 OPTION_DRAGON2 = 0x00800000,
 OPTION_DRAGON3 = 0x01000000,
 OPTION_DRAGON4 = 0x02000000,
 OPTION_DRAGON5 = 0x04000000,
 OPTION_HANBOK = 0x08000000,
 OPTION_OKTOBERFEST = 0x10000000,

 OPTION_CART1 = 0x00000008,
 OPTION_CART2 = 0x00000080,
 OPTION_CART3 = 0x00000100,
 OPTION_CART4 = 0x00000200,
 OPTION_CART5 = 0x00000400,

 OPTION_CART = OPTION_CART1|OPTION_CART2|OPTION_CART3|OPTION_CART4|OPTION_CART5,


 OPTION_DRAGON = OPTION_DRAGON1|OPTION_DRAGON2|OPTION_DRAGON3|OPTION_DRAGON4|OPTION_DRAGON5,
 OPTION_COSTUME = OPTION_WEDDING|OPTION_XMAS|OPTION_SUMMER|OPTION_HANBOK|OPTION_OKTOBERFEST,
};

struct s_skill {
 unsigned short id;
 unsigned char lv;
 unsigned char flag;
};

struct script_reg_state {
 unsigned int type : 1;
 unsigned int update : 1;
};

struct script_reg_num {
 struct script_reg_state flag;
 int value;
};

struct script_reg_str {
 struct script_reg_state flag;
 char *value;
};


struct status_change_data {
 unsigned short type;
 int val1, val2, val3, val4;
 int tick;
};

struct storage_data {
 int storage_amount;
 struct item items[600];
};

struct guild_storage {
 int dirty;
 int guild_id;
 short storage_status;
 short storage_amount;
 struct item items[600];
 unsigned short lock;
};

struct s_pet {
 int account_id;
 int char_id;
 int pet_id;
 short class_;
 short level;
 short egg_id;
 short equip;
 short intimate;
 short hungry;
 char name[(23 + 1)];
 char rename_flag;
 char incubate;
};

struct s_homunculus {
 char name[(23 + 1)];
 int hom_id;
 int char_id;
 short class_;
 short prev_class;
 int hp,max_hp,sp,max_sp;
 unsigned int intimacy;
 short hunger;
 struct s_skill hskill[43];
 short skillpts;
 short level;
 unsigned int exp;
 short rename_flag;
 short vaporize;
 int str;
 int agi;
 int vit;
 int int_;
 int dex;
 int luk;

 int str_value;
 int agi_value;
 int vit_value;
 int int_value;
 int dex_value;
 int luk_value;

 int8 spiritball;
};

struct s_mercenary {
 int mercenary_id;
 int char_id;
 short class_;
 int hp, sp;
 unsigned int kill_count;
 unsigned int life_time;
};

struct s_elemental {
 int elemental_id;
 int char_id;
 short class_;
 uint32 mode;
 int hp, sp, max_hp, max_sp, matk, atk, atk2;
 short hit, flee, amotion, def, mdef;
 int life_time;
};

struct s_friend {
 int account_id;
 int char_id;
 char name[(23 + 1)];
};

struct hotkey {





 int8 HERC__unavailable_struct;

};

struct mmo_charstatus {
 int char_id;
 int account_id;
 int partner_id;
 int father;
 int mother;
 int child;

 unsigned int base_exp,job_exp;
 int zeny;
 int bank_vault;

 short class_;
 unsigned int status_point,skill_point;
 int hp,max_hp,sp,max_sp;
 unsigned int option;
 short manner;
 unsigned char karma;
 short hair,hair_color,clothes_color,body;
 int party_id,guild_id,pet_id,hom_id,mer_id,ele_id;
 int fame;


 int arch_faith, arch_calls;
 int spear_faith, spear_calls;
 int sword_faith, sword_calls;

 short weapon;
 short shield;
 short head_top,head_mid,head_bottom;
 short robe;

 char name[(23 + 1)];
 unsigned int base_level,job_level;
 short str,agi,vit,int_,dex,luk;
 unsigned char slot,sex;

 uint32 mapip;
 uint16 mapport;

 struct point last_point,save_point,memo_point[3];
 struct item inventory[100],cart[100];
 struct storage_data storage;
 struct s_skill skill[1478];

 struct s_friend friends[40];



 
# 549 "../../../server-code/src/common/mmo.h" 3 4
_Bool 
# 549 "../../../server-code/src/common/mmo.h"
     show_equip, allow_party;
 unsigned short rename;
 unsigned short slotchange;

 time_t delete_date;


 unsigned short mod_exp,mod_drop,mod_death;

 unsigned char font;

 uint32 uniqueitem_counter;

 unsigned char hotkey_rowshift;
};

typedef enum mail_status {
 MAIL_NEW,
 MAIL_UNREAD,
 MAIL_READ,
} mail_status;

struct mail_message {
 int id;
 int send_id;
 char send_name[(23 + 1)];
 int dest_id;
 char dest_name[(23 + 1)];
 char title[40];
 char body[200];

 mail_status status;
 time_t timestamp;

 int zeny;
 struct item item;
};

struct mail_data {
 short amount;
 
# 589 "../../../server-code/src/common/mmo.h" 3 4
_Bool 
# 589 "../../../server-code/src/common/mmo.h"
     full;
 short unchecked, unread;
 struct mail_message msg[30];
};

struct auction_data {
 unsigned int auction_id;
 int seller_id;
 char seller_name[(23 + 1)];
 int buyer_id;
 char buyer_name[(23 + 1)];

 struct item item;

 char item_name[50];
 short type;

 unsigned short hours;
 int price, buynow;
 time_t timestamp;
 int auction_end_timer;
};

struct party_member {
 int account_id;
 int char_id;
 char name[(23 + 1)];
 unsigned short class_;
 unsigned short map;
 unsigned short lv;
 unsigned leader : 1,
          online : 1;
};

struct party {
 int party_id;
 char name[(23 + 1)];
 unsigned char count;
 unsigned exp : 1,
    item : 2;
 struct party_member member[12];
};

struct map_session_data;
struct guild_member {
 int account_id, char_id;
 short hair,hair_color,gender,class_,lv;
 uint64 exp;
 int exp_payper;
 short online,position;
 char name[(23 + 1)];
 struct map_session_data *sd;
 unsigned char modified;
};

struct guild_position {
 char name[(23 + 1)];
 int mode;
 int exp_mode;
 unsigned char modified;
};

struct guild_alliance {
 int opposition;
 int guild_id;
 char name[(23 + 1)];
};

struct guild_expulsion {
 char name[(23 + 1)];
 char mes[40];
 int account_id;
};

struct guild_skill {
 int id,lv;
};

struct channel_data;
struct guild {
 int guild_id;
 short guild_lv, connect_member, max_member, average_lv;
 uint64 exp;
 unsigned int next_exp;
 int skill_point;
 char name[(23 + 1)],master[(23 + 1)];
 struct guild_member member[(16 +10*6)];
 struct guild_position position[20];
 char mes1[60],mes2[120];
 int emblem_len,emblem_id;
 char emblem_data[2048];
 struct guild_alliance alliance[16];
 struct guild_expulsion expulsion[32];
 struct guild_skill skill[15];


 unsigned short save_flag;

 short *instance;
 unsigned short instances;

 struct channel_data *channel;
 struct hplugin_data_store *hdata;
};

struct guild_castle {
 int castle_id;
 int mapindex;
 char castle_name[(23 + 1)];
 char castle_event[(23 + 1)];
 int guild_id;
 int economy;
 int defense;
 int triggerE;
 int triggerD;
 int nextTime;
 int payTime;
 int createTime;
 int visibleC;
 struct {
  unsigned visible : 1;
  int id;
 } guardian[8];
 int* temp_guardians;
 int temp_guardians_max;
};

struct fame_list {
 int id;
 int fame;
 char name[(23 + 1)];
};

enum fame_list_type {
 RANKTYPE_BLACKSMITH = 0,
 RANKTYPE_ALCHEMIST = 1,
 RANKTYPE_TAEKWON = 2,
 RANKTYPE_PK = 3,
};






enum guild_basic_info {
 GBI_EXP = 1,
 GBI_GUILDLV,
 GBI_SKILLPOINT,





 GBI_SKILLLV,
};

enum {
 GMI_POSITION = 0,
 GMI_EXP,
 GMI_HAIR,
 GMI_HAIR_COLOR,
 GMI_GENDER,
 GMI_CLASS,
 GMI_LEVEL,
};

enum guild_permission {
 GPERM_INVITE = 0x01,
 GPERM_EXPEL = 0x10,
 GPERM_ALL = GPERM_INVITE|GPERM_EXPEL,
 GPERM_MASK = GPERM_ALL,
};

enum {
 GD_SKILLBASE=10000,
 GD_APPROVAL=10000,
 GD_KAFRACONTRACT=10001,
 GD_GUARDRESEARCH=10002,
 GD_GUARDUP=10003,
 GD_EXTENSION=10004,
 GD_GLORYGUILD=10005,
 GD_LEADERSHIP=10006,
 GD_GLORYWOUNDS=10007,
 GD_SOULCOLD=10008,
 GD_HAWKEYES=10009,
 GD_BATTLEORDER=10010,
 GD_REGENERATION=10011,
 GD_RESTORE=10012,
 GD_EMERGENCYCALL=10013,
 GD_DEVELOPMENT=10014,
 GD_MAX,
};


enum {
 JOB_NOVICE,
 JOB_SWORDMAN,
 JOB_MAGE,
 JOB_ARCHER,
 JOB_ACOLYTE,
 JOB_MERCHANT,
 JOB_THIEF,
 JOB_KNIGHT,
 JOB_PRIEST,
 JOB_WIZARD,
 JOB_BLACKSMITH,
 JOB_HUNTER,
 JOB_ASSASSIN,
 JOB_KNIGHT2,
 JOB_CRUSADER,
 JOB_MONK,
 JOB_SAGE,
 JOB_ROGUE,
 JOB_ALCHEMIST,
 JOB_BARD,
 JOB_DANCER,
 JOB_CRUSADER2,
 JOB_WEDDING,
 JOB_SUPER_NOVICE,
 JOB_GUNSLINGER,
 JOB_NINJA,
 JOB_XMAS,
 JOB_SUMMER,
 JOB_MAX_BASIC,

 JOB_NOVICE_HIGH = 4001,
 JOB_SWORDMAN_HIGH,
 JOB_MAGE_HIGH,
 JOB_ARCHER_HIGH,
 JOB_ACOLYTE_HIGH,
 JOB_MERCHANT_HIGH,
 JOB_THIEF_HIGH,
 JOB_LORD_KNIGHT,
 JOB_HIGH_PRIEST,
 JOB_HIGH_WIZARD,
 JOB_WHITESMITH,
 JOB_SNIPER,
 JOB_ASSASSIN_CROSS,
 JOB_LORD_KNIGHT2,
 JOB_PALADIN,
 JOB_CHAMPION,
 JOB_PROFESSOR,
 JOB_STALKER,
 JOB_CREATOR,
 JOB_CLOWN,
 JOB_GYPSY,
 JOB_PALADIN2,

 JOB_BABY,
 JOB_BABY_SWORDMAN,
 JOB_BABY_MAGE,
 JOB_BABY_ARCHER,
 JOB_BABY_ACOLYTE,
 JOB_BABY_MERCHANT,
 JOB_BABY_THIEF,
 JOB_BABY_KNIGHT,
 JOB_BABY_PRIEST,
 JOB_BABY_WIZARD,
 JOB_BABY_BLACKSMITH,
 JOB_BABY_HUNTER,
 JOB_BABY_ASSASSIN,
 JOB_BABY_KNIGHT2,
 JOB_BABY_CRUSADER,
 JOB_BABY_MONK,
 JOB_BABY_SAGE,
 JOB_BABY_ROGUE,
 JOB_BABY_ALCHEMIST,
 JOB_BABY_BARD,
 JOB_BABY_DANCER,
 JOB_BABY_CRUSADER2,
 JOB_SUPER_BABY,

 JOB_TAEKWON,
 JOB_STAR_GLADIATOR,
 JOB_STAR_GLADIATOR2,
 JOB_SOUL_LINKER,

 JOB_GANGSI,
 JOB_DEATH_KNIGHT,
 JOB_DARK_COLLECTOR,

 JOB_RUNE_KNIGHT = 4054,
 JOB_WARLOCK,
 JOB_RANGER,
 JOB_ARCH_BISHOP,
 JOB_MECHANIC,
 JOB_GUILLOTINE_CROSS,

 JOB_RUNE_KNIGHT_T,
 JOB_WARLOCK_T,
 JOB_RANGER_T,
 JOB_ARCH_BISHOP_T,
 JOB_MECHANIC_T,
 JOB_GUILLOTINE_CROSS_T,

 JOB_ROYAL_GUARD,
 JOB_SORCERER,
 JOB_MINSTREL,
 JOB_WANDERER,
 JOB_SURA,
 JOB_GENETIC,
 JOB_SHADOW_CHASER,

 JOB_ROYAL_GUARD_T,
 JOB_SORCERER_T,
 JOB_MINSTREL_T,
 JOB_WANDERER_T,
 JOB_SURA_T,
 JOB_GENETIC_T,
 JOB_SHADOW_CHASER_T,

 JOB_RUNE_KNIGHT2,
 JOB_RUNE_KNIGHT_T2,
 JOB_ROYAL_GUARD2,
 JOB_ROYAL_GUARD_T2,
 JOB_RANGER2,
 JOB_RANGER_T2,
 JOB_MECHANIC2,
 JOB_MECHANIC_T2,

 JOB_BABY_RUNE = 4096,
 JOB_BABY_WARLOCK,
 JOB_BABY_RANGER,
 JOB_BABY_BISHOP,
 JOB_BABY_MECHANIC,
 JOB_BABY_CROSS,

 JOB_BABY_GUARD,
 JOB_BABY_SORCERER,
 JOB_BABY_MINSTREL,
 JOB_BABY_WANDERER,
 JOB_BABY_SURA,
 JOB_BABY_GENETIC,
 JOB_BABY_CHASER,

 JOB_BABY_RUNE2,
 JOB_BABY_GUARD2,
 JOB_BABY_RANGER2,
 JOB_BABY_MECHANIC2,

 JOB_SUPER_NOVICE_E = 4190,
 JOB_SUPER_BABY_E,

 JOB_KAGEROU = 4211,
 JOB_OBORO,
 JOB_REBELLION = 4215,

 JOB_MAX,
};




enum {
 SEX_FEMALE = 0,
 SEX_MALE,
 SEX_SERVER
};

enum weapon_type {
 W_FIST,
 W_DAGGER,
 W_1HSWORD,
 W_2HSWORD,
 W_1HSPEAR,
 W_2HSPEAR,
 W_1HAXE,
 W_2HAXE,
 W_MACE,
 W_2HMACE,
 W_STAFF,
 W_BOW,
 W_KNUCKLE,
 W_MUSICAL,
 W_WHIP,
 W_BOOK,
 W_KATAR,
 W_REVOLVER,
 W_RIFLE,
 W_GATLING,
 W_SHOTGUN,
 W_GRENADE,
 W_HUUMA,
 W_2HSTAFF,
 MAX_SINGLE_WEAPON_TYPE,

 W_DOUBLE_DD,
 W_DOUBLE_SS,
 W_DOUBLE_AA,
 W_DOUBLE_DS,
 W_DOUBLE_DA,
 W_DOUBLE_SA,
 MAX_WEAPON_TYPE,
};

enum ammo_type {
 A_ARROW = 1,
 A_DAGGER,
 A_BULLET,
 A_SHELL,
 A_GRENADE,
 A_SHURIKEN,
 A_KUNAI,
 A_CANNONBALL,
 A_THROWWEAPON,
};

enum e_char_server_type {
 CST_NORMAL = 0,
 CST_MAINTENANCE = 1,
 CST_OVER18 = 2,
 CST_PAYING = 3,
 CST_F2P = 4,
};

enum e_pc_reg_loading {
 PRL_NONE = 0x0,
 PRL_CHAR = 0x1,
 PRL_ACCL = 0x2,
 PRL_ACCG = 0x4,
 PRL_ALL = 0xFF,
};




enum zh_char_ask_name_type {
 CHAR_ASK_NAME_BLOCK = 1,
 CHAR_ASK_NAME_BAN = 2,
 CHAR_ASK_NAME_UNBLOCK = 3,
 CHAR_ASK_NAME_UNBAN = 4,
 CHAR_ASK_NAME_CHANGESEX = 5,
 CHAR_ASK_NAME_CHARBAN = 6,
 CHAR_ASK_NAME_CHARUNBAN = 7,
 CHAR_ASK_NAME_CHANGECHARSEX = 8,
};




enum hz_char_ask_name_answer {
 CHAR_ASK_NAME_ANS_DONE = 0,
 CHAR_ASK_NAME_ANS_NOTFOUND = 1,
 CHAR_ASK_NAME_ANS_GMLOW = 2,
 CHAR_ASK_NAME_ANS_OFFLINE = 3,
};
# 28 "../../../server-code/src/login/login.h" 2

struct mmo_account;
struct AccountDB;

enum E_LOGINSERVER_ST
{
 LOGINSERVER_ST_RUNNING = CORE_ST_LAST,
 LOGINSERVER_ST_SHUTDOWN,
 LOGINSERVER_ST_LAST
};

enum password_enc {
 PWENC_NONE = 0x0,
 PWENC_ENCRYPT = 0x1,
 PWENC_ENCRYPT2 = 0x2,
 PWENC_BOTH = PWENC_ENCRYPT|PWENC_ENCRYPT2,
};





struct login_session_data {
 int account_id;
 int login_id1;
 int login_id2;
 char sex;

 char userid[(23 + 1)];
 char passwd[(32+1)];
 int passwdenc;
 char md5key[20];
 uint16 md5keylen;

 char lastlogin[24];
 uint8 group_id;
 uint8 clienttype;
 uint32 version;

 uint8 client_hash[16];
 int has_client_hash;

 int fd;

 time_t expiration_time;
};

struct mmo_char_server {

 char name[20];
 int fd;
 uint32 ip;
 uint16 port;
 uint16 users;
 uint16 type;
 uint16 new_;
};

struct client_hash_node {
 int group_id;
 uint8 hash[16];
 struct client_hash_node *next;
};

struct Login_Config {

 uint32 login_ip;
 uint16 login_port;
 unsigned int ipban_cleanup_interval;
 unsigned int ip_sync_interval;
 
# 98 "../../../server-code/src/login/login.h" 3 4
_Bool 
# 98 "../../../server-code/src/login/login.h"
     log_login;
 char date_format[32];
 
# 100 "../../../server-code/src/login/login.h" 3 4
_Bool 
# 100 "../../../server-code/src/login/login.h"
     new_account_flag,new_acc_length_limit;
 int start_limited_time;
 
# 102 "../../../server-code/src/login/login.h" 3 4
_Bool 
# 102 "../../../server-code/src/login/login.h"
     use_md5_passwds;
 int group_id_to_connect;
 int min_group_id_to_connect;
 
# 105 "../../../server-code/src/login/login.h" 3 4
_Bool 
# 105 "../../../server-code/src/login/login.h"
     check_client_version;
 uint32 client_version_to_connect;
 int allowed_regs;
 int time_allowed;

 
# 110 "../../../server-code/src/login/login.h" 3 4
_Bool 
# 110 "../../../server-code/src/login/login.h"
     ipban;
 
# 111 "../../../server-code/src/login/login.h" 3 4
_Bool 
# 111 "../../../server-code/src/login/login.h"
     dynamic_pass_failure_ban;
 unsigned int dynamic_pass_failure_ban_interval;
 unsigned int dynamic_pass_failure_ban_limit;
 unsigned int dynamic_pass_failure_ban_duration;
 
# 115 "../../../server-code/src/login/login.h" 3 4
_Bool 
# 115 "../../../server-code/src/login/login.h"
     use_dnsbl;
 char dnsbl_servs[1024];

 int client_hash_check;
 struct client_hash_node *client_hash_nodes;
};

struct login_auth_node {
 int account_id;
 uint32 login_id1;
 uint32 login_id2;
 uint32 ip;
 char sex;
 uint32 version;
 uint8 clienttype;
 int group_id;
 time_t expiration_time;
};




struct online_login_data {
 int account_id;
 int waiting_disconnect;
 int char_server;
};
# 151 "../../../server-code/src/login/login.h"
struct login_interface {
 struct DBMap *auth_db;
 struct DBMap *online_db;
 int fd;
 struct Login_Config *config;
 struct AccountDB* accounts;

 int (*mmo_auth) (struct login_session_data* sd, 
# 158 "../../../server-code/src/login/login.h" 3 4
                                                _Bool 
# 158 "../../../server-code/src/login/login.h"
                                                     isServer);
 int (*mmo_auth_new) (const char* userid, const char* pass, const char sex, const char* last_ip);
 int (*waiting_disconnect_timer) (int tid, int64 tick, int id, intptr_t data);
 struct DBData (*create_online_user) (union DBKey key, va_list args);
 struct online_login_data* (*add_online_user) (int char_server, int account_id);
 void (*remove_online_user) (int account_id);
 int (*online_db_setoffline) (union DBKey key, struct DBData *data, va_list ap);
 int (*online_data_cleanup_sub) (union DBKey key, struct DBData *data, va_list ap);
 int (*online_data_cleanup) (int tid, int64 tick, int id, intptr_t data);
 int (*sync_ip_addresses) (int tid, int64 tick, int id, intptr_t data);
 
# 168 "../../../server-code/src/login/login.h" 3 4
_Bool 
# 168 "../../../server-code/src/login/login.h"
     (*check_encrypted) (const char* str1, const char* str2, const char* passwd);
 
# 169 "../../../server-code/src/login/login.h" 3 4
_Bool 
# 169 "../../../server-code/src/login/login.h"
     (*check_password) (const char* md5key, int passwdenc, const char* passwd, const char* refpass);
 uint32 (*lan_subnet_check) (uint32 ip);
 void (*fromchar_accinfo) (int fd, int account_id, int u_fd, int u_aid, int u_group, int map_fd, struct mmo_account *acc);
 void (*fromchar_account) (int fd, int account_id, struct mmo_account *acc);
 void (*fromchar_account_update_other) (int account_id, unsigned int state);
 void (*fromchar_auth_ack) (int fd, int account_id, uint32 login_id1, uint32 login_id2, uint8 sex, int request_id, struct login_auth_node* node);
 void (*fromchar_ban) (int account_id, time_t timestamp);
 void (*fromchar_change_sex_other) (int account_id, char sex);
 void (*fromchar_pong) (int fd);
 void (*fromchar_parse_auth) (int fd, int id, const char *ip);
 void (*fromchar_parse_update_users) (int fd, int id);
 void (*fromchar_parse_request_change_email) (int fd, int id, const char *ip);
 void (*fromchar_parse_account_data) (int fd, int id, const char *ip);
 void (*fromchar_parse_ping) (int fd);
 void (*fromchar_parse_change_email) (int fd, int id, const char *ip);
 void (*fromchar_parse_account_update) (int fd, int id, const char *ip);
 void (*fromchar_parse_ban) (int fd, int id, const char *ip);
 void (*fromchar_parse_change_sex) (int fd, int id, const char *ip);
 void (*fromchar_parse_account_reg2) (int fd, int id, const char *ip);
 void (*fromchar_parse_unban) (int fd, int id, const char *ip);
 void (*fromchar_parse_account_online) (int fd, int id);
 void (*fromchar_parse_account_offline) (int fd);
 void (*fromchar_parse_online_accounts) (int fd, int id);
 void (*fromchar_parse_request_account_reg2) (int fd);
 void (*fromchar_parse_update_wan_ip) (int fd, int id);
 void (*fromchar_parse_all_offline) (int fd, int id);
 void (*fromchar_parse_change_pincode) (int fd);
 
# 196 "../../../server-code/src/login/login.h" 3 4
_Bool 
# 196 "../../../server-code/src/login/login.h"
     (*fromchar_parse_wrong_pincode) (int fd);
 void (*fromchar_parse_accinfo) (int fd);
 int (*parse_fromchar) (int fd);
 void (*connection_problem) (int fd, uint8 status);
 void (*kick) (struct login_session_data* sd);
 void (*auth_ok) (struct login_session_data* sd);
 void (*auth_failed) (struct login_session_data* sd, int result);
 void (*login_error) (int fd, uint8 status);
 void (*parse_ping) (int fd, struct login_session_data* sd);
 void (*parse_client_md5) (int fd, struct login_session_data* sd);
 
# 206 "../../../server-code/src/login/login.h" 3 4
_Bool 
# 206 "../../../server-code/src/login/login.h"
     (*parse_client_login) (int fd, struct login_session_data* sd, const char *ip);
 void (*send_coding_key) (int fd, struct login_session_data* sd);
 void (*parse_request_coding_key) (int fd, struct login_session_data* sd);
 void (*char_server_connection_status) (int fd, struct login_session_data* sd, uint8 status);
 void (*parse_request_connection) (int fd, struct login_session_data* sd, const char *ip, uint32 ipl);
 int (*parse_login) (int fd);
 void (*config_set_defaults) (void);
 int (*config_read) (const char *cfgName);
 char *LOGIN_CONF_NAME;
 char *NET_CONF_NAME;
};


extern struct mmo_char_server server[30];

void login_defaults(void);


extern struct login_interface *login;
# 24 "../../../server-code/src/login/login.c" 2

# 1 "../../../server-code/src/login/HPMlogin.h" 1
# 28 "../../../server-code/src/login/HPMlogin.h"
# 1 "../../../server-code/src/common/HPM.h" 1
# 29 "../../../server-code/src/common/HPM.h"
# 1 "../../../server-code/src/common/HPMi.h" 1
# 24 "../../../server-code/src/common/HPMi.h"
# 1 "../../../server-code/src/common/console.h" 1
# 25 "../../../server-code/src/common/console.h"
# 1 "../../../server-code/src/common/mutex.h" 1
# 26 "../../../server-code/src/common/mutex.h"
typedef struct ramutex ramutex;
typedef struct racond racond;







ramutex *ramutex_create(void);






void ramutex_destroy(ramutex *m);






void ramutex_lock(ramutex *m);
# 58 "../../../server-code/src/common/mutex.h"

# 58 "../../../server-code/src/common/mutex.h" 3 4
_Bool 
# 58 "../../../server-code/src/common/mutex.h"
    ramutex_trylock(ramutex *m);






void ramutex_unlock(ramutex *m);







racond *racond_create(void);






void racond_destroy(racond *c);
# 89 "../../../server-code/src/common/mutex.h"
void racond_wait(racond *c, ramutex *m, sysint timeout_ticks);
# 99 "../../../server-code/src/common/mutex.h"
void racond_signal(racond *c);
# 108 "../../../server-code/src/common/mutex.h"
void racond_broadcast(racond *c);
# 26 "../../../server-code/src/common/console.h" 2
# 1 "../../../server-code/src/common/spinlock.h" 1
# 31 "../../../server-code/src/common/spinlock.h"
# 1 "../../../server-code/src/common/atomic.h" 1
# 110 "../../../server-code/src/common/atomic.h"
static __attribute__((always_inline)) inline int64 InterlockedExchangeAdd64(volatile int64 *addend, int64 increment){
 return __sync_fetch_and_add(addend, increment);
}

static __attribute__((always_inline)) inline int32 InterlockedExchangeAdd(volatile int32 *addend, int32 increment){
 return __sync_fetch_and_add(addend, increment);
}

static __attribute__((always_inline)) inline int64 InterlockedIncrement64(volatile int64 *addend){
 return __sync_add_and_fetch(addend, 1);
}

static __attribute__((always_inline)) inline int32 InterlockedIncrement(volatile int32 *addend){
 return __sync_add_and_fetch(addend, 1);
}

static __attribute__((always_inline)) inline int64 InterlockedDecrement64(volatile int64 *addend){
 return __sync_sub_and_fetch(addend, 1);
}

static __attribute__((always_inline)) inline int32 InterlockedDecrement(volatile int32 *addend){
 return __sync_sub_and_fetch(addend, 1);
}

static __attribute__((always_inline)) inline int64 InterlockedCompareExchange64(volatile int64 *dest, int64 exch, int64 cmp){
 return __sync_val_compare_and_swap(dest, cmp, exch);
}

static __attribute__((always_inline)) inline int32 InterlockedCompareExchange(volatile int32 *dest, int32 exch, int32 cmp){
 return __sync_val_compare_and_swap(dest, cmp, exch);
}

static __attribute__((always_inline)) inline int64 InterlockedExchange64(volatile int64 *target, int64 val){
 return __sync_lock_test_and_set(target, val);
}

static __attribute__((always_inline)) inline int32 InterlockedExchange(volatile int32 *target, int32 val){
 return __sync_lock_test_and_set(target, val);
}
# 32 "../../../server-code/src/common/spinlock.h" 2

# 1 "../../../server-code/src/common/thread.h" 1
# 26 "../../../server-code/src/common/thread.h"
typedef struct rAthread rAthread;
typedef void* (*rAthreadProc)(void*);

typedef enum RATHREAD_PRIO {
 RAT_PRIO_LOW = 0,
 RAT_PRIO_NORMAL,
 RAT_PRIO_HIGH
} RATHREAD_PRIO;
# 45 "../../../server-code/src/common/thread.h"
rAthread *rathread_create(rAthreadProc entryPoint, void *param);
# 58 "../../../server-code/src/common/thread.h"
rAthread *rathread_createEx(rAthreadProc entryPoint, void *param, size_t szStack, RATHREAD_PRIO prio);
# 68 "../../../server-code/src/common/thread.h"
void rathread_destroy(rAthread *handle);
# 79 "../../../server-code/src/common/thread.h"
rAthread *rathread_self(void);
# 90 "../../../server-code/src/common/thread.h"
int rathread_get_tid(void);
# 101 "../../../server-code/src/common/thread.h"

# 101 "../../../server-code/src/common/thread.h" 3 4
_Bool 
# 101 "../../../server-code/src/common/thread.h"
    rathread_wait(rAthread *handle, void **out_exitCode);
# 110 "../../../server-code/src/common/thread.h"
void rathread_prio_set(rAthread *handle, RATHREAD_PRIO prio);







RATHREAD_PRIO rathread_prio_get(rAthread *handle);
# 128 "../../../server-code/src/common/thread.h"
void rathread_yield(void);

void rathread_init(void);
void rathread_final(void);
# 34 "../../../server-code/src/common/spinlock.h" 2
# 47 "../../../server-code/src/common/spinlock.h"
typedef struct SPIN_LOCK{
  volatile int32 lock;
  volatile int32 nest;

  volatile int32 sync_lock;
} __attribute__((aligned(64))) SPIN_LOCK;




static __attribute__((always_inline)) inline void InitializeSpinLock(SPIN_LOCK *lck){
  lck->lock = 0;
  lck->nest = 0;
  lck->sync_lock = 0;
}

static __attribute__((always_inline)) inline void FinalizeSpinLock(SPIN_LOCK *lck){
  return;
}





static __attribute__((always_inline)) inline void EnterSpinLock(SPIN_LOCK *lck){
  int tid = rathread_get_tid();



  do { if(InterlockedCompareExchange((&lck->sync_lock), 1, 0) == 0) break; rathread_yield(); } while( 1);
  if(InterlockedCompareExchange(&lck->lock, tid, tid) == tid){
    InterlockedIncrement(&lck->nest);
    do { InterlockedExchange((&lck->sync_lock), 0); } while(0);
    return;
  }

  do { InterlockedExchange((&lck->sync_lock), 0); } while(0);


  while(1){
   if(InterlockedCompareExchange(&lck->lock, tid, 0) == 0){
    InterlockedIncrement(&lck->nest);
    return;
   }
   rathread_yield();
  }

}


static __attribute__((always_inline)) inline void LeaveSpinLock(SPIN_LOCK *lck){
  int tid = rathread_get_tid();

  do { if(InterlockedCompareExchange((&lck->sync_lock), 1, 0) == 0) break; rathread_yield(); } while( 1);

  if(InterlockedCompareExchange(&lck->lock, tid, tid) == tid){
   if(InterlockedDecrement(&lck->nest) == 0)
     InterlockedExchange(&lck->lock, 0);
  }

  do { InterlockedExchange((&lck->sync_lock), 0); } while(0);
}
# 27 "../../../server-code/src/common/console.h" 2



struct Sql;
# 41 "../../../server-code/src/common/console.h"
typedef void (*CParseFunc)(char *line);
# 56 "../../../server-code/src/common/console.h"
enum CONSOLE_PARSE_ENTRY_TYPE {
 CPET_UNKNOWN,
 CPET_FUNCTION,
 CPET_CATEGORY,
};

struct CParseEntry {
 char cmd[20];
 int type;
 union {
  CParseFunc func;
  struct { int _max_; int _len_; struct CParseEntry * *_data_; } children;
 } u;
};

struct console_input_interface {


 SPIN_LOCK ptlock;
 rAthread *pthread;
 volatile int32 ptstate;
 ramutex *ptmutex;
 racond *ptcond;

 struct { int _max_; int _len_; struct CParseEntry * *_data_; } command_list;
 struct { int _max_; int _len_; struct CParseEntry * *_data_; } commands;

 struct Sql *SQL;

 void (*parse_init) (void);
 void (*parse_final) (void);
 int (*parse_timer) (int tid, int64 tick, int id, intptr_t data);
 void *(*pthread_main) (void *x);
 void (*parse) (char* line);
 void (*parse_sub) (char* line);
 int (*key_pressed) (void);
 void (*load_defaults) (void);
 void (*parse_list_subs) (struct CParseEntry *cmd, unsigned char depth);
 void (*addCommand) (char *name, CParseFunc func);
 void (*setSQL) (struct Sql *SQL_handle);



};

struct console_interface {
 void (*init) (void);
 void (*final) (void);
 void (*display_title) (void);
 void (*display_gplnotice) (void);

 struct console_input_interface *input;
};


void console_defaults(void);


extern struct console_interface *console;
# 25 "../../../server-code/src/common/HPMi.h" 2

# 1 "../../../server-code/src/common/showmsg.h" 1
# 29 "../../../server-code/src/common/showmsg.h"
struct config_setting_t;
# 89 "../../../server-code/src/common/showmsg.h"
enum msg_type {
 MSG_NONE,
 MSG_STATUS,
 MSG_SQL,
 MSG_INFORMATION,
 MSG_NOTICE,
 MSG_WARNING,
 MSG_DEBUG,
 MSG_ERROR,
 MSG_FATALERROR
};

struct showmsg_interface {
 
# 102 "../../../server-code/src/common/showmsg.h" 3 4
_Bool 
# 102 "../../../server-code/src/common/showmsg.h"
     stdout_with_ansisequence;
 int silent;
 int console_log;
 char timestamp_format[20];

 void (*init) (void);
 void (*final) (void);

 void (*clearScreen) (void);
 int (*showMessageV) (const char *string, va_list ap);

 void (*showMessage) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showStatus) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showSQL) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showInfo) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showNotice) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showWarning) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showDebug) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showError) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showFatalError) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showConfigWarning) (struct config_setting_t *config, const char *string, ...) __attribute__((format(printf, 2, 3)));
};
# 140 "../../../server-code/src/common/showmsg.h"
void showmsg_defaults(void);


extern struct showmsg_interface *showmsg;
# 27 "../../../server-code/src/common/HPMi.h" 2

struct Sql;
struct script_state;
struct AtCommandInfo;
struct socket_data;
struct map_session_data;
struct hplugin_data_store;




struct hplugin_info {
 char* name;
 enum server_types type;
 char* version;
 char* req_version;
};

struct s_HPMDataCheck {
 char *name;
 unsigned int size;
 int type;
};



enum hp_event_types {
 HPET_INIT,
 HPET_FINAL,
 HPET_READY,
 HPET_POST_FINAL,
 HPET_PRE_INIT,
 HPET_MAX,
};

enum HPluginPacketHookingPoints {
 hpClif_Parse,
 hpChrif_Parse,
 hpParse_FromMap,
 hpParse_FromLogin,
 hpParse_Char,
 hpParse_FromChar,
 hpParse_Login,

 hpPHP_MAX,
};

enum HPluginHookType {
 HOOK_TYPE_PRE,
 HOOK_TYPE_POST,
};




enum HPluginDataTypes {
 HPDT_UNKNOWN,
 HPDT_SESSION,
 HPDT_MSD,
 HPDT_NPCD,
 HPDT_MAP,
 HPDT_INSTANCE,
 HPDT_GUILD,
 HPDT_PARTY,
 HPDT_MOBDB,
 HPDT_MOBDATA,
 HPDT_ITEMDATA,
 HPDT_BGDATA,
 HPDT_AUTOTRADE_VEND,
};


enum HPluginConfType {
 HPCT_BATTLE,
 HPCT_LOGIN,
 HPCT_CHAR,
 HPCT_CHAR_INTER,
 HPCT_MAP_INTER,
 HPCT_LOG,
 HPCT_SCRIPT,
 HPCT_MAX,
};
# 220 "../../../server-code/src/common/HPMi.h"
struct HPMi_interface {

 unsigned int pid;

 void (*event[HPET_MAX]) (void);
 
# 225 "../../../server-code/src/common/HPMi.h" 3 4
_Bool 
# 225 "../../../server-code/src/common/HPMi.h"
     (*addCommand) (char *name, 
# 225 "../../../server-code/src/common/HPMi.h" 3 4
                                _Bool 
# 225 "../../../server-code/src/common/HPMi.h"
                                     (*func)(const int fd, struct map_session_data* sd, const char* command, const char* message,struct AtCommandInfo *info));
 
# 226 "../../../server-code/src/common/HPMi.h" 3 4
_Bool 
# 226 "../../../server-code/src/common/HPMi.h"
     (*addScript) (char *name, char *args, 
# 226 "../../../server-code/src/common/HPMi.h" 3 4
                                           _Bool 
# 226 "../../../server-code/src/common/HPMi.h"
                                                (*func)(struct script_state *st), 
# 226 "../../../server-code/src/common/HPMi.h" 3 4
                                                                                  _Bool 
# 226 "../../../server-code/src/common/HPMi.h"
                                                                                       isDeprecated);
 void (*addCPCommand) (char *name, CParseFunc func);

 void (*addToHPData) (enum HPluginDataTypes type, uint32 pluginID, struct hplugin_data_store **storeptr, void *data, uint32 classid, 
# 229 "../../../server-code/src/common/HPMi.h" 3 4
                                                                                                                                    _Bool 
# 229 "../../../server-code/src/common/HPMi.h"
                                                                                                                                         autofree);
 void *(*getFromHPData) (enum HPluginDataTypes type, uint32 pluginID, struct hplugin_data_store *store, uint32 classid);
 void (*removeFromHPData) (enum HPluginDataTypes type, uint32 pluginID, struct hplugin_data_store *store, uint32 classid);

 
# 233 "../../../server-code/src/common/HPMi.h" 3 4
_Bool 
# 233 "../../../server-code/src/common/HPMi.h"
     (*addPacket) (unsigned short cmd, unsigned short length, void (*receive)(int fd), unsigned int point, unsigned int pluginID);

 
# 235 "../../../server-code/src/common/HPMi.h" 3 4
_Bool 
# 235 "../../../server-code/src/common/HPMi.h"
     (*AddHook) (enum HPluginHookType type, const char *target, void *hook, unsigned int pID);
 void (*HookStop) (const char *func, unsigned int pID);
 
# 237 "../../../server-code/src/common/HPMi.h" 3 4
_Bool 
# 237 "../../../server-code/src/common/HPMi.h"
     (*HookStopped) (void);

 
# 239 "../../../server-code/src/common/HPMi.h" 3 4
_Bool 
# 239 "../../../server-code/src/common/HPMi.h"
     (*addArg) (unsigned int pluginID, char *name, 
# 239 "../../../server-code/src/common/HPMi.h" 3 4
                                                   _Bool 
# 239 "../../../server-code/src/common/HPMi.h"
                                                        has_param, CmdlineExecFunc func, const char *help);

 
# 241 "../../../server-code/src/common/HPMi.h" 3 4
_Bool 
# 241 "../../../server-code/src/common/HPMi.h"
     (*addConf) (unsigned int pluginID, enum HPluginConfType type, char *name, void (*parse_func) (const char *key, const char *val), int (*return_func) (const char *key));

 void (*addPCGPermission) (unsigned int pluginID, char *name, unsigned int *mask);

 struct Sql *sql_handle;
};
# 30 "../../../server-code/src/common/HPM.h" 2
# 44 "../../../server-code/src/common/HPM.h"
# 1 "/usr/include/dlfcn.h" 1 3 4
# 24 "/usr/include/dlfcn.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 25 "/usr/include/dlfcn.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/dlfcn.h" 1 3 4
# 28 "/usr/include/dlfcn.h" 2 3 4
# 52 "/usr/include/dlfcn.h" 3 4





# 56 "/usr/include/dlfcn.h" 3 4
extern void *dlopen (const char *__file, int __mode) __attribute__ ((__nothrow__));



extern int dlclose (void *__handle) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern void *dlsym (void *__restrict __handle,
      const char *__restrict __name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
# 82 "/usr/include/dlfcn.h" 3 4
extern char *dlerror (void) __attribute__ ((__nothrow__ , __leaf__));
# 188 "/usr/include/dlfcn.h" 3 4

# 45 "../../../server-code/src/common/HPM.h" 2
# 64 "../../../server-code/src/common/HPM.h"
# 1 "/usr/include/string.h" 1 3 4
# 27 "/usr/include/string.h" 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 33 "/usr/include/string.h" 2 3 4









extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));






extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));





extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 92 "/usr/include/string.h" 3 4
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


# 123 "/usr/include/string.h" 3 4


extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

# 162 "/usr/include/string.h" 3 4
extern int strcoll_l (const char *__s1, const char *__s2, __locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));

extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    __locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));




extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 206 "/usr/include/string.h" 3 4

# 231 "/usr/include/string.h" 3 4
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 258 "/usr/include/string.h" 3 4
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


# 277 "/usr/include/string.h" 3 4



extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 310 "/usr/include/string.h" 3 4
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 337 "/usr/include/string.h" 3 4
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));




extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
# 392 "/usr/include/string.h" 3 4


extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));

# 422 "/usr/include/string.h" 3 4
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__))

                        __attribute__ ((__nonnull__ (2)));
# 440 "/usr/include/string.h" 3 4
extern char *strerror_l (int __errnum, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));





extern void __bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern void bcopy (const void *__src, void *__dest, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 484 "/usr/include/string.h" 3 4
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 512 "/usr/include/string.h" 3 4
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 529 "/usr/include/string.h" 3 4
extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 552 "/usr/include/string.h" 3 4
extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));


extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
# 639 "/usr/include/string.h" 3 4

# 65 "../../../server-code/src/common/HPM.h" 2




# 68 "../../../server-code/src/common/HPM.h"
struct hplugin {
 void * dll;
 unsigned int idx;
 char *filename;
 struct hplugin_info *info;
 struct HPMi_interface *hpi;
};




struct hpm_symbol {
 const char *name;
 void *ptr;
};




struct hplugin_data_entry {
 uint32 pluginID;
 uint32 classid;
 struct {
  unsigned int free : 1;
 } flag;
 void *data;
};




struct hplugin_data_store {
 enum HPluginDataTypes type;
 struct { int _max_; int _len_; struct hplugin_data_entry * *_data_; } entries;
};

struct HPluginPacket {
 unsigned int pluginID;
 unsigned short cmd;
 short len;
 void (*receive) (int fd);
};

struct HPMFileNameCache {
 const char *addr;
 char *name;
};


struct HPConfListenStorage {
 unsigned int pluginID;
 char key[40];
 void (*parse_func) (const char *key, const char *val);
 int (*return_func) (const char *key);
};


struct HPM_interface {

 unsigned int version[2];
 
# 128 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 128 "../../../server-code/src/common/HPM.h"
     off;
 
# 129 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 129 "../../../server-code/src/common/HPM.h"
     hooking;

 
# 131 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 131 "../../../server-code/src/common/HPM.h"
     force_return;

 struct { int _max_; int _len_; struct hplugin * *_data_; } plugins;
 struct { int _max_; int _len_; struct hpm_symbol * *_data_; } symbols;

 struct { int _max_; int _len_; struct HPluginPacket *_data_; } packets[hpPHP_MAX];

 struct {

  int count;
  struct HPMFileNameCache *data;
 } filenames;

 struct { int _max_; int _len_; struct HPConfListenStorage *_data_; } config_listeners[HPCT_MAX];

 struct { int _max_; int _len_; char * *_data_; } cmdline_load_plugins;

 void (*init) (void);
 void (*final) (void);
 struct hplugin * (*create) (void);
 struct hplugin * (*load) (const char* filename);
 void (*unload) (struct hplugin* plugin);
 
# 153 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 153 "../../../server-code/src/common/HPM.h"
     (*exists) (const char *filename);
 
# 154 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 154 "../../../server-code/src/common/HPM.h"
     (*iscompatible) (char* version);
 void (*event) (enum hp_event_types type);
 void *(*import_symbol) (char *name, unsigned int pID);
 void (*share) (void *value, const char *name);
 void (*config_read) (void);
 char *(*pid2name) (unsigned int pid);
 unsigned char (*parse_packets) (int fd, int packet_id, enum HPluginPacketHookingPoints point);
 void (*load_sub) (struct hplugin *plugin);
 
# 162 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 162 "../../../server-code/src/common/HPM.h"
     (*addhook_sub) (enum HPluginHookType type, const char *target, void *hook, unsigned int pID);

 
# 164 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 164 "../../../server-code/src/common/HPM.h"
     (*parseConf) (const char *w1, const char *w2, enum HPluginConfType point);
 
# 165 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 165 "../../../server-code/src/common/HPM.h"
     (*getBattleConf) (const char* w1, int *value);

 
# 167 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 167 "../../../server-code/src/common/HPM.h"
     (*DataCheck) (struct s_HPMDataCheck *src, unsigned int size, int version, char *name);
 void (*datacheck_init) (const struct s_HPMDataCheck *src, unsigned int length, int version);
 void (*datacheck_final) (void);

 void (*data_store_create) (struct hplugin_data_store **storeptr, enum HPluginDataTypes type);
 void (*data_store_destroy) (struct hplugin_data_store **storeptr);
 
# 173 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 173 "../../../server-code/src/common/HPM.h"
     (*data_store_validate) (enum HPluginDataTypes type, struct hplugin_data_store **storeptr, 
# 173 "../../../server-code/src/common/HPM.h" 3 4
                                                                                               _Bool 
# 173 "../../../server-code/src/common/HPM.h"
                                                                                                    initialize);

 
# 175 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 175 "../../../server-code/src/common/HPM.h"
     (*data_store_validate_sub) (enum HPluginDataTypes type, struct hplugin_data_store **storeptr, 
# 175 "../../../server-code/src/common/HPM.h" 3 4
                                                                                                   _Bool 
# 175 "../../../server-code/src/common/HPM.h"
                                                                                                        initialize);
};


# 178 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 178 "../../../server-code/src/common/HPM.h"
cmdline_arg_loadplugin (const char *name, const char *params);

extern struct HPM_interface *HPM;

void hpm_defaults(void);
# 29 "../../../server-code/src/login/HPMlogin.h" 2

struct hplugin;


# 32 "../../../server-code/src/login/HPMlogin.h" 3 4
_Bool 
# 32 "../../../server-code/src/login/HPMlogin.h"
    HPM_login_data_store_validate(enum HPluginDataTypes type, struct hplugin_data_store **storeptr, 
# 32 "../../../server-code/src/login/HPMlogin.h" 3 4
                                                                                                    _Bool 
# 32 "../../../server-code/src/login/HPMlogin.h"
                                                                                                         initialize);

void HPM_login_plugin_load_sub(struct hplugin *plugin);

void HPM_login_do_final(void);

void HPM_login_do_init(void);
# 26 "../../../server-code/src/login/login.c" 2
# 1 "../../../server-code/src/login/account.h" 1
# 28 "../../../server-code/src/login/account.h"
struct Sql;

typedef struct AccountDB AccountDB;
typedef struct AccountDBIterator AccountDBIterator;




AccountDB* account_db_sql(void);


struct mmo_account
{
 int account_id;
 char userid[(23 + 1)];
 char pass[32+1];
 char sex;
 char email[40];
 int group_id;
 uint8 char_slots;
 unsigned int state;
 time_t unban_time;
 time_t expiration_time;
 unsigned int logincount;
 unsigned int pincode_change;
 char pincode[4+1];
 char lastlogin[24];
 char last_ip[16];
 char birthdate[10+1];
};


struct AccountDBIterator
{



 void (*destroy)(AccountDBIterator* self);






 
# 72 "../../../server-code/src/login/account.h" 3 4
_Bool 
# 72 "../../../server-code/src/login/account.h"
     (*next)(AccountDBIterator* self, struct mmo_account* acc);
};

struct Account_engine {
 AccountDB* (*constructor)(void);
 AccountDB* db;
};

struct AccountDB
{





 
# 87 "../../../server-code/src/login/account.h" 3 4
_Bool 
# 87 "../../../server-code/src/login/account.h"
     (*init)(AccountDB* self);




 void (*destroy)(AccountDB* self);
# 105 "../../../server-code/src/login/account.h"
 
# 105 "../../../server-code/src/login/account.h" 3 4
_Bool 
# 105 "../../../server-code/src/login/account.h"
     (*get_property)(AccountDB* self, const char* key, char* buf, size_t buflen);







 
# 113 "../../../server-code/src/login/account.h" 3 4
_Bool 
# 113 "../../../server-code/src/login/account.h"
     (*set_property)(AccountDB* self, const char* key, const char* value);
# 122 "../../../server-code/src/login/account.h"
 
# 122 "../../../server-code/src/login/account.h" 3 4
_Bool 
# 122 "../../../server-code/src/login/account.h"
     (*create)(AccountDB* self, struct mmo_account* acc);






 
# 129 "../../../server-code/src/login/account.h" 3 4
_Bool 
# 129 "../../../server-code/src/login/account.h"
     (*remove)(AccountDB* self, const int account_id);







 
# 137 "../../../server-code/src/login/account.h" 3 4
_Bool 
# 137 "../../../server-code/src/login/account.h"
     (*save)(AccountDB* self, const struct mmo_account* acc);







 
# 145 "../../../server-code/src/login/account.h" 3 4
_Bool 
# 145 "../../../server-code/src/login/account.h"
     (*load_num)(AccountDB* self, struct mmo_account* acc, const int account_id);







 
# 153 "../../../server-code/src/login/account.h" 3 4
_Bool 
# 153 "../../../server-code/src/login/account.h"
     (*load_str)(AccountDB* self, struct mmo_account* acc, const char* userid);





 AccountDBIterator* (*iterator)(AccountDB* self);
};


struct Sql *account_db_sql_up(AccountDB* self);

void mmo_send_accreg2(AccountDB* self, int fd, int account_id, int char_id);
void mmo_save_accreg2(AccountDB* self, int fd, int account_id, int char_id);
# 27 "../../../server-code/src/login/login.c" 2
# 1 "../../../server-code/src/login/ipban.h" 1
# 29 "../../../server-code/src/login/ipban.h"
void ipban_init(void);


void ipban_final(void);



# 35 "../../../server-code/src/login/ipban.h" 3 4
_Bool 
# 35 "../../../server-code/src/login/ipban.h"
    ipban_check(uint32 ip);


void ipban_log(uint32 ip);



# 41 "../../../server-code/src/login/ipban.h" 3 4
_Bool 
# 41 "../../../server-code/src/login/ipban.h"
    ipban_config_read(const char *key, const char* value);
# 28 "../../../server-code/src/login/login.c" 2
# 1 "../../../server-code/src/login/loginlog.h" 1
# 28 "../../../server-code/src/login/loginlog.h"
unsigned long loginlog_failedattempts(uint32 ip, unsigned int minutes);
void login_log(uint32 ip, const char* username, int rcode, const char* message);

# 30 "../../../server-code/src/login/loginlog.h" 3 4
_Bool 
# 30 "../../../server-code/src/login/loginlog.h"
    loginlog_init(void);

# 31 "../../../server-code/src/login/loginlog.h" 3 4
_Bool 
# 31 "../../../server-code/src/login/loginlog.h"
    loginlog_final(void);

# 32 "../../../server-code/src/login/loginlog.h" 3 4
_Bool 
# 32 "../../../server-code/src/login/loginlog.h"
    loginlog_config_read(const char* w1, const char* w2);
# 29 "../../../server-code/src/login/login.c" 2




# 1 "../../../server-code/src/common/memmgr.h" 1
# 80 "../../../server-code/src/common/memmgr.h"
struct malloc_interface {
 void (*init) (void);
 void (*final) (void);

 void* (*malloc)(size_t size, const char *file, int line, const char *func);
 void* (*calloc)(size_t num, size_t size, const char *file, int line, const char *func);
 void* (*realloc)(void *p, size_t size, const char *file, int line, const char *func);
 void* (*reallocz)(void *p, size_t size, const char *file, int line, const char *func);
 char* (*astrdup)(const char *p, const char *file, int line, const char *func);
 char *(*astrndup)(const char *p, size_t size, const char *file, int line, const char *func);
 void (*free)(void *p, const char *file, int line, const char *func);

 void (*memory_check)(void);
 
# 93 "../../../server-code/src/common/memmgr.h" 3 4
_Bool 
# 93 "../../../server-code/src/common/memmgr.h"
     (*verify_ptr)(void* ptr);
 size_t (*usage) (void);

 void (*post_shutdown) (void);
 void (*init_messages) (void);
};


void malloc_defaults(void);

void memmgr_report(int extra);


extern struct malloc_interface *iMalloc;
# 34 "../../../server-code/src/login/login.c" 2
# 1 "../../../server-code/src/common/md5calc.h" 1
# 25 "../../../server-code/src/common/md5calc.h"
void MD5_String(const char * string, char * output);
void MD5_Binary(const char * string, unsigned char * output);
void MD5_Salt(unsigned int len, char * output);
# 35 "../../../server-code/src/login/login.c" 2
# 1 "../../../server-code/src/common/nullpo.h" 1
# 40 "../../../server-code/src/common/nullpo.h"
# 1 "/usr/include/assert.h" 1 3 4
# 66 "/usr/include/assert.h" 3 4




# 69 "/usr/include/assert.h" 3 4
extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



# 41 "../../../server-code/src/common/nullpo.h" 2
# 155 "../../../server-code/src/common/nullpo.h"

# 155 "../../../server-code/src/common/nullpo.h"
struct nullpo_interface {
 void (*assert_report) (const char *file, int line, const char *func, const char *targetname, const char *title);
};


void nullpo_defaults(void);


extern struct nullpo_interface *nullpo;
# 36 "../../../server-code/src/login/login.c" 2
# 1 "../../../server-code/src/common/random.h" 1
# 27 "../../../server-code/src/common/random.h"
void rnd_init(void);
void rnd_seed(uint32);

int32 rnd(void);
uint32 rnd_roll(uint32 dice_faces);
int32 rnd_value(int32 min, int32 max);
double rnd_uniform(void);
double rnd_uniform53(void);
# 37 "../../../server-code/src/login/login.c" 2

# 1 "../../../server-code/src/common/socket.h" 1
# 39 "../../../server-code/src/login/login.c" 2
# 1 "../../../server-code/src/common/strlib.h" 1
# 54 "../../../server-code/src/common/strlib.h"
typedef enum e_svopt {

 SV_NOESCAPE_NOTERMINATE = 0,

 SV_ESCAPE_C = 1,

 SV_TERMINATE_LF = 2,
 SV_TERMINATE_CRLF = 4,
 SV_TERMINATE_CR = 8,

 SV_KEEP_TERMINATOR = 16
} e_svopt;






struct s_svstate {
 const char* str;
 int len;
 int off;
 int start;
 int end;
 enum e_svopt opt;
 char delim;
 
# 80 "../../../server-code/src/common/strlib.h" 3 4
_Bool 
# 80 "../../../server-code/src/common/strlib.h"
     done;
};



struct StringBuf {
 char *buf_;
 char *ptr_;
 unsigned int max_;
};
typedef struct StringBuf StringBuf;

struct strlib_interface {
 char *(*jstrescape) (char* pt);
 char *(*jstrescapecpy) (char* pt, const char* spt);
 int (*jmemescapecpy) (char* pt, const char* spt, int size);
 int (*remove_control_chars_) (char* str);
 char *(*trim_) (char* str);
 char *(*normalize_name_) (char* str,const char* delims);
 const char *(*stristr_) (const char *haystack, const char *needle);


 size_t (*strnlen_) (const char* string, size_t maxlen);


 char * (*strtok_r_) (char *s1, const char *s2, char **lasts);

 int (*e_mail_check_) (char* email);
 int (*config_switch_) (const char* str);


 char *(*safestrncpy_) (char* dst, const char* src, size_t n);


 size_t (*safestrnlen_) (const char* string, size_t maxlen);




 int (*safesnprintf_) (char *buf, size_t sz, const char *fmt, ...) __attribute__((format(printf, 3, 4)));



 int (*strline_) (const char* str, size_t pos);




 
# 128 "../../../server-code/src/common/strlib.h" 3 4
_Bool 
# 128 "../../../server-code/src/common/strlib.h"
     (*bin2hex_) (char* output, unsigned char* input, size_t count);
};

struct stringbuf_interface {
 StringBuf* (*Malloc) (void);
 void (*Init) (StringBuf* self);
 int (*Printf) (StringBuf *self, const char *fmt, ...) __attribute__((format(printf, 2, 3)));
 int (*Vprintf) (StringBuf* self, const char* fmt, va_list args);
 int (*Append) (StringBuf* self, const StringBuf *sbuf);
 int (*AppendStr) (StringBuf* self, const char* str);
 int (*Length) (StringBuf* self);
 char* (*Value) (StringBuf* self);
 void (*Clear) (StringBuf* self);
 void (*Destroy) (StringBuf* self);
 void (*Free) (StringBuf* self);
};

struct sv_interface {





 int (*parse_next) (struct s_svstate* svstate);






 int (*parse) (const char* str, int len, int startoff, char delim, int* out_pos, int npos, enum e_svopt opt);







 int (*split) (char* str, int len, int startoff, char delim, char** out_fields, int nfields, enum e_svopt opt);




 size_t (*escape_c) (char* out_dest, const char* src, size_t len, const char* escapes);




 size_t (*unescape_c) (char* out_dest, const char* src, size_t len);


 const char* (*skip_escaped_c) (const char* p);




 
# 184 "../../../server-code/src/common/strlib.h" 3 4
_Bool 
# 184 "../../../server-code/src/common/strlib.h"
     (*readdb) (const char* directory, const char* filename, char delim, int mincols, int maxcols, int maxrows, 
# 184 "../../../server-code/src/common/strlib.h" 3 4
                                                                                                                _Bool 
# 184 "../../../server-code/src/common/strlib.h"
                                                                                                                     (*parseproc)(char* fields[], int columns, int current));
};


void strlib_defaults(void);


extern struct strlib_interface *strlib;
extern struct stringbuf_interface *StrBuf;
extern struct sv_interface *sv;
# 40 "../../../server-code/src/login/login.c" 2
# 1 "../../../server-code/src/common/timer.h" 1
# 32 "../../../server-code/src/common/timer.h"
enum {
 TIMER_ONCE_AUTODEL = 0x01,
 TIMER_INTERVAL = 0x02,
 TIMER_REMOVE_HEAP = 0x10,
};



typedef int (*TimerFunc)(int tid, int64 tick, int id, intptr_t data);

struct TimerData {
 int64 tick;
 TimerFunc func;
 unsigned char type;
 int interval;


 int id;
 intptr_t data;
};







struct timer_interface {


 int64 (*gettick) (void);
 int64 (*gettick_nocache) (void);

 int (*add) (int64 tick, TimerFunc func, int id, intptr_t data);
 int (*add_interval) (int64 tick, TimerFunc func, int id, intptr_t data, int interval);
 const struct TimerData *(*get) (int tid);
 int (*delete) (int tid, TimerFunc func);

 int64 (*addtick) (int tid, int64 tick);
 int64 (*settick) (int tid, int64 tick);

 int (*add_func_list) (TimerFunc func, char* name);

 unsigned long (*get_uptime) (void);

 int (*perform) (int64 tick);
 void (*init) (void);
 void (*final) (void);
};


void timer_defaults(void);


extern struct timer_interface *timer;
# 41 "../../../server-code/src/login/login.c" 2
# 1 "../../../server-code/src/common/utils.h" 1
# 26 "../../../server-code/src/common/utils.h"
# 1 "/usr/include/stdio.h" 1 3 4
# 29 "/usr/include/stdio.h" 3 4




# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 34 "/usr/include/stdio.h" 2 3 4
# 44 "/usr/include/stdio.h" 3 4

# 44 "/usr/include/stdio.h" 3 4
struct _IO_FILE;



typedef struct _IO_FILE FILE;





# 64 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 74 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 31 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 15 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 16 "/usr/include/_G_config.h" 2 3 4




# 1 "/usr/include/wchar.h" 1 3 4
# 82 "/usr/include/wchar.h" 3 4
typedef struct
{
  int __count;
  union
  {

    unsigned int __wch;



    char __wchb[4];
  } __value;
} __mbstate_t;
# 21 "/usr/include/_G_config.h" 2 3 4
typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 32 "/usr/include/libio.h" 2 3 4
# 144 "/usr/include/libio.h" 3 4
struct _IO_jump_t; struct _IO_FILE;





typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 173 "/usr/include/libio.h" 3 4
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 241 "/usr/include/libio.h" 3 4
struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 289 "/usr/include/libio.h" 3 4
  __off64_t _offset;
# 298 "/usr/include/libio.h" 3 4
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;

  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 334 "/usr/include/libio.h" 3 4
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, const char *__buf,
     size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);
# 386 "/usr/include/libio.h" 3 4
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
# 430 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));

extern int _IO_peekc_locked (_IO_FILE *__fp);





extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
# 460 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);

extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
# 75 "/usr/include/stdio.h" 2 3 4
# 90 "/usr/include/stdio.h" 3 4
typedef __off_t off_t;
# 102 "/usr/include/stdio.h" 3 4
typedef __ssize_t ssize_t;







typedef _G_fpos_t fpos_t;




# 164 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 1 3 4
# 165 "/usr/include/stdio.h" 2 3 4



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;







extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));

extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));




extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));








extern FILE *tmpfile (void) ;
# 209 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;





extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;
# 227 "/usr/include/stdio.h" 3 4
extern char *tempnam (const char *__dir, const char *__pfx)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);

# 252 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 266 "/usr/include/stdio.h" 3 4






extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes) ;




extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 295 "/usr/include/stdio.h" 3 4

# 306 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__)) ;
# 319 "/usr/include/stdio.h" 3 4
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__)) ;






extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));





extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));








extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);




extern int printf (const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));





extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));

# 412 "/usr/include/stdio.h" 3 4
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));








extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;




extern int scanf (const char *__restrict __format, ...) ;

extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
# 443 "/usr/include/stdio.h" 3 4
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

                               ;
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
                              ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__))

                      ;
# 463 "/usr/include/stdio.h" 3 4








extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 494 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))



     __attribute__ ((__format__ (__scanf__, 2, 0)));
# 522 "/usr/include/stdio.h" 3 4









extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);

# 550 "/usr/include/stdio.h" 3 4
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 561 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);











extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);

# 594 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);








extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;
# 640 "/usr/include/stdio.h" 3 4

# 665 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;







extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;








extern int fputs (const char *__restrict __s, FILE *__restrict __stream);





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;




extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);

# 737 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);








extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream) ;




extern void rewind (FILE *__stream);

# 773 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence);




extern __off_t ftello (FILE *__stream) ;
# 792 "/usr/include/stdio.h" 3 4






extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream, const fpos_t *__pos);
# 815 "/usr/include/stdio.h" 3 4

# 824 "/usr/include/stdio.h" 3 4


extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));

extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;

extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;




extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;








extern void perror (const char *__s);






# 1 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h" 1 3 4
# 26 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern const char *const sys_errlist[];
# 854 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
# 872 "/usr/include/stdio.h" 3 4
extern FILE *popen (const char *__command, const char *__modes) ;





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__));
# 912 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));



extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;


extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
# 942 "/usr/include/stdio.h" 3 4

# 27 "../../../server-code/src/common/utils.h" 2

# 1 "/usr/include/unistd.h" 1 3 4
# 27 "/usr/include/unistd.h" 3 4

# 205 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/posix_opt.h" 1 3 4
# 206 "/usr/include/unistd.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/environments.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/environments.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/environments.h" 2 3 4
# 210 "/usr/include/unistd.h" 2 3 4
# 229 "/usr/include/unistd.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 230 "/usr/include/unistd.h" 2 3 4





typedef __gid_t gid_t;




typedef __uid_t uid_t;
# 258 "/usr/include/unistd.h" 3 4
typedef __useconds_t useconds_t;
# 277 "/usr/include/unistd.h" 3 4
typedef __socklen_t socklen_t;
# 290 "/usr/include/unistd.h" 3 4
extern int access (const char *__name, int __type) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 307 "/usr/include/unistd.h" 3 4
extern int faccessat (int __fd, const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
# 337 "/usr/include/unistd.h" 3 4
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__ , __leaf__));
# 356 "/usr/include/unistd.h" 3 4
extern int close (int __fd);






extern ssize_t read (int __fd, void *__buf, size_t __nbytes) ;





extern ssize_t write (int __fd, const void *__buf, size_t __n) ;
# 379 "/usr/include/unistd.h" 3 4
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes,
        __off_t __offset) ;






extern ssize_t pwrite (int __fd, const void *__buf, size_t __n,
         __off_t __offset) ;
# 420 "/usr/include/unistd.h" 3 4
extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__ , __leaf__)) ;
# 435 "/usr/include/unistd.h" 3 4
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__ , __leaf__));
# 447 "/usr/include/unistd.h" 3 4
extern unsigned int sleep (unsigned int __seconds);







extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__ , __leaf__));






extern int usleep (__useconds_t __useconds);
# 472 "/usr/include/unistd.h" 3 4
extern int pause (void);



extern int chown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;



extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;






extern int fchownat (int __fd, const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;



extern int chdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;



extern int fchdir (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
# 514 "/usr/include/unistd.h" 3 4
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__ , __leaf__)) ;
# 528 "/usr/include/unistd.h" 3 4
extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__)) ;




extern int dup (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;


extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__ , __leaf__));
# 546 "/usr/include/unistd.h" 3 4
extern char **__environ;







extern int execve (const char *__path, char *const __argv[],
     char *const __envp[]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern int fexecve (int __fd, char *const __argv[], char *const __envp[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));




extern int execv (const char *__path, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern int execle (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern int execl (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern int execvp (const char *__file, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern int execlp (const char *__file, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
# 601 "/usr/include/unistd.h" 3 4
extern int nice (int __inc) __attribute__ ((__nothrow__ , __leaf__)) ;




extern void _exit (int __status) __attribute__ ((__noreturn__));





# 1 "/usr/include/x86_64-linux-gnu/bits/confname.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/confname.h" 3 4
enum
  {
    _PC_LINK_MAX,

    _PC_MAX_CANON,

    _PC_MAX_INPUT,

    _PC_NAME_MAX,

    _PC_PATH_MAX,

    _PC_PIPE_BUF,

    _PC_CHOWN_RESTRICTED,

    _PC_NO_TRUNC,

    _PC_VDISABLE,

    _PC_SYNC_IO,

    _PC_ASYNC_IO,

    _PC_PRIO_IO,

    _PC_SOCK_MAXBUF,

    _PC_FILESIZEBITS,

    _PC_REC_INCR_XFER_SIZE,

    _PC_REC_MAX_XFER_SIZE,

    _PC_REC_MIN_XFER_SIZE,

    _PC_REC_XFER_ALIGN,

    _PC_ALLOC_SIZE_MIN,

    _PC_SYMLINK_MAX,

    _PC_2_SYMLINKS

  };


enum
  {
    _SC_ARG_MAX,

    _SC_CHILD_MAX,

    _SC_CLK_TCK,

    _SC_NGROUPS_MAX,

    _SC_OPEN_MAX,

    _SC_STREAM_MAX,

    _SC_TZNAME_MAX,

    _SC_JOB_CONTROL,

    _SC_SAVED_IDS,

    _SC_REALTIME_SIGNALS,

    _SC_PRIORITY_SCHEDULING,

    _SC_TIMERS,

    _SC_ASYNCHRONOUS_IO,

    _SC_PRIORITIZED_IO,

    _SC_SYNCHRONIZED_IO,

    _SC_FSYNC,

    _SC_MAPPED_FILES,

    _SC_MEMLOCK,

    _SC_MEMLOCK_RANGE,

    _SC_MEMORY_PROTECTION,

    _SC_MESSAGE_PASSING,

    _SC_SEMAPHORES,

    _SC_SHARED_MEMORY_OBJECTS,

    _SC_AIO_LISTIO_MAX,

    _SC_AIO_MAX,

    _SC_AIO_PRIO_DELTA_MAX,

    _SC_DELAYTIMER_MAX,

    _SC_MQ_OPEN_MAX,

    _SC_MQ_PRIO_MAX,

    _SC_VERSION,

    _SC_PAGESIZE,


    _SC_RTSIG_MAX,

    _SC_SEM_NSEMS_MAX,

    _SC_SEM_VALUE_MAX,

    _SC_SIGQUEUE_MAX,

    _SC_TIMER_MAX,




    _SC_BC_BASE_MAX,

    _SC_BC_DIM_MAX,

    _SC_BC_SCALE_MAX,

    _SC_BC_STRING_MAX,

    _SC_COLL_WEIGHTS_MAX,

    _SC_EQUIV_CLASS_MAX,

    _SC_EXPR_NEST_MAX,

    _SC_LINE_MAX,

    _SC_RE_DUP_MAX,

    _SC_CHARCLASS_NAME_MAX,


    _SC_2_VERSION,

    _SC_2_C_BIND,

    _SC_2_C_DEV,

    _SC_2_FORT_DEV,

    _SC_2_FORT_RUN,

    _SC_2_SW_DEV,

    _SC_2_LOCALEDEF,


    _SC_PII,

    _SC_PII_XTI,

    _SC_PII_SOCKET,

    _SC_PII_INTERNET,

    _SC_PII_OSI,

    _SC_POLL,

    _SC_SELECT,

    _SC_UIO_MAXIOV,

    _SC_IOV_MAX = _SC_UIO_MAXIOV,

    _SC_PII_INTERNET_STREAM,

    _SC_PII_INTERNET_DGRAM,

    _SC_PII_OSI_COTS,

    _SC_PII_OSI_CLTS,

    _SC_PII_OSI_M,

    _SC_T_IOV_MAX,



    _SC_THREADS,

    _SC_THREAD_SAFE_FUNCTIONS,

    _SC_GETGR_R_SIZE_MAX,

    _SC_GETPW_R_SIZE_MAX,

    _SC_LOGIN_NAME_MAX,

    _SC_TTY_NAME_MAX,

    _SC_THREAD_DESTRUCTOR_ITERATIONS,

    _SC_THREAD_KEYS_MAX,

    _SC_THREAD_STACK_MIN,

    _SC_THREAD_THREADS_MAX,

    _SC_THREAD_ATTR_STACKADDR,

    _SC_THREAD_ATTR_STACKSIZE,

    _SC_THREAD_PRIORITY_SCHEDULING,

    _SC_THREAD_PRIO_INHERIT,

    _SC_THREAD_PRIO_PROTECT,

    _SC_THREAD_PROCESS_SHARED,


    _SC_NPROCESSORS_CONF,

    _SC_NPROCESSORS_ONLN,

    _SC_PHYS_PAGES,

    _SC_AVPHYS_PAGES,

    _SC_ATEXIT_MAX,

    _SC_PASS_MAX,


    _SC_XOPEN_VERSION,

    _SC_XOPEN_XCU_VERSION,

    _SC_XOPEN_UNIX,

    _SC_XOPEN_CRYPT,

    _SC_XOPEN_ENH_I18N,

    _SC_XOPEN_SHM,


    _SC_2_CHAR_TERM,

    _SC_2_C_VERSION,

    _SC_2_UPE,


    _SC_XOPEN_XPG2,

    _SC_XOPEN_XPG3,

    _SC_XOPEN_XPG4,


    _SC_CHAR_BIT,

    _SC_CHAR_MAX,

    _SC_CHAR_MIN,

    _SC_INT_MAX,

    _SC_INT_MIN,

    _SC_LONG_BIT,

    _SC_WORD_BIT,

    _SC_MB_LEN_MAX,

    _SC_NZERO,

    _SC_SSIZE_MAX,

    _SC_SCHAR_MAX,

    _SC_SCHAR_MIN,

    _SC_SHRT_MAX,

    _SC_SHRT_MIN,

    _SC_UCHAR_MAX,

    _SC_UINT_MAX,

    _SC_ULONG_MAX,

    _SC_USHRT_MAX,


    _SC_NL_ARGMAX,

    _SC_NL_LANGMAX,

    _SC_NL_MSGMAX,

    _SC_NL_NMAX,

    _SC_NL_SETMAX,

    _SC_NL_TEXTMAX,


    _SC_XBS5_ILP32_OFF32,

    _SC_XBS5_ILP32_OFFBIG,

    _SC_XBS5_LP64_OFF64,

    _SC_XBS5_LPBIG_OFFBIG,


    _SC_XOPEN_LEGACY,

    _SC_XOPEN_REALTIME,

    _SC_XOPEN_REALTIME_THREADS,


    _SC_ADVISORY_INFO,

    _SC_BARRIERS,

    _SC_BASE,

    _SC_C_LANG_SUPPORT,

    _SC_C_LANG_SUPPORT_R,

    _SC_CLOCK_SELECTION,

    _SC_CPUTIME,

    _SC_THREAD_CPUTIME,

    _SC_DEVICE_IO,

    _SC_DEVICE_SPECIFIC,

    _SC_DEVICE_SPECIFIC_R,

    _SC_FD_MGMT,

    _SC_FIFO,

    _SC_PIPE,

    _SC_FILE_ATTRIBUTES,

    _SC_FILE_LOCKING,

    _SC_FILE_SYSTEM,

    _SC_MONOTONIC_CLOCK,

    _SC_MULTI_PROCESS,

    _SC_SINGLE_PROCESS,

    _SC_NETWORKING,

    _SC_READER_WRITER_LOCKS,

    _SC_SPIN_LOCKS,

    _SC_REGEXP,

    _SC_REGEX_VERSION,

    _SC_SHELL,

    _SC_SIGNALS,

    _SC_SPAWN,

    _SC_SPORADIC_SERVER,

    _SC_THREAD_SPORADIC_SERVER,

    _SC_SYSTEM_DATABASE,

    _SC_SYSTEM_DATABASE_R,

    _SC_TIMEOUTS,

    _SC_TYPED_MEMORY_OBJECTS,

    _SC_USER_GROUPS,

    _SC_USER_GROUPS_R,

    _SC_2_PBS,

    _SC_2_PBS_ACCOUNTING,

    _SC_2_PBS_LOCATE,

    _SC_2_PBS_MESSAGE,

    _SC_2_PBS_TRACK,

    _SC_SYMLOOP_MAX,

    _SC_STREAMS,

    _SC_2_PBS_CHECKPOINT,


    _SC_V6_ILP32_OFF32,

    _SC_V6_ILP32_OFFBIG,

    _SC_V6_LP64_OFF64,

    _SC_V6_LPBIG_OFFBIG,


    _SC_HOST_NAME_MAX,

    _SC_TRACE,

    _SC_TRACE_EVENT_FILTER,

    _SC_TRACE_INHERIT,

    _SC_TRACE_LOG,


    _SC_LEVEL1_ICACHE_SIZE,

    _SC_LEVEL1_ICACHE_ASSOC,

    _SC_LEVEL1_ICACHE_LINESIZE,

    _SC_LEVEL1_DCACHE_SIZE,

    _SC_LEVEL1_DCACHE_ASSOC,

    _SC_LEVEL1_DCACHE_LINESIZE,

    _SC_LEVEL2_CACHE_SIZE,

    _SC_LEVEL2_CACHE_ASSOC,

    _SC_LEVEL2_CACHE_LINESIZE,

    _SC_LEVEL3_CACHE_SIZE,

    _SC_LEVEL3_CACHE_ASSOC,

    _SC_LEVEL3_CACHE_LINESIZE,

    _SC_LEVEL4_CACHE_SIZE,

    _SC_LEVEL4_CACHE_ASSOC,

    _SC_LEVEL4_CACHE_LINESIZE,



    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,

    _SC_RAW_SOCKETS,


    _SC_V7_ILP32_OFF32,

    _SC_V7_ILP32_OFFBIG,

    _SC_V7_LP64_OFF64,

    _SC_V7_LPBIG_OFFBIG,


    _SC_SS_REPL_MAX,


    _SC_TRACE_EVENT_NAME_MAX,

    _SC_TRACE_NAME_MAX,

    _SC_TRACE_SYS_MAX,

    _SC_TRACE_USER_EVENT_MAX,


    _SC_XOPEN_STREAMS,


    _SC_THREAD_ROBUST_PRIO_INHERIT,

    _SC_THREAD_ROBUST_PRIO_PROTECT

  };


enum
  {
    _CS_PATH,


    _CS_V6_WIDTH_RESTRICTED_ENVS,



    _CS_GNU_LIBC_VERSION,

    _CS_GNU_LIBPTHREAD_VERSION,


    _CS_V5_WIDTH_RESTRICTED_ENVS,



    _CS_V7_WIDTH_RESTRICTED_ENVS,



    _CS_LFS_CFLAGS = 1000,

    _CS_LFS_LDFLAGS,

    _CS_LFS_LIBS,

    _CS_LFS_LINTFLAGS,

    _CS_LFS64_CFLAGS,

    _CS_LFS64_LDFLAGS,

    _CS_LFS64_LIBS,

    _CS_LFS64_LINTFLAGS,


    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,

    _CS_XBS5_ILP32_OFF32_LDFLAGS,

    _CS_XBS5_ILP32_OFF32_LIBS,

    _CS_XBS5_ILP32_OFF32_LINTFLAGS,

    _CS_XBS5_ILP32_OFFBIG_CFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LIBS,

    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,

    _CS_XBS5_LP64_OFF64_CFLAGS,

    _CS_XBS5_LP64_OFF64_LDFLAGS,

    _CS_XBS5_LP64_OFF64_LIBS,

    _CS_XBS5_LP64_OFF64_LINTFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LIBS,

    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LIBS,

    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V6_LP64_OFF64_CFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LIBS,

    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LIBS,

    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V7_LP64_OFF64_CFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LIBS,

    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,


    _CS_V6_ENV,

    _CS_V7_ENV

  };
# 613 "/usr/include/unistd.h" 2 3 4


extern long int pathconf (const char *__path, int __name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__ , __leaf__));


extern long int sysconf (int __name) __attribute__ ((__nothrow__ , __leaf__));



extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__));




extern __pid_t getpid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __pid_t getppid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __pid_t getpgrp (void) __attribute__ ((__nothrow__ , __leaf__));


extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));

extern __pid_t getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));






extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__ , __leaf__));
# 663 "/usr/include/unistd.h" 3 4
extern int setpgrp (void) __attribute__ ((__nothrow__ , __leaf__));






extern __pid_t setsid (void) __attribute__ ((__nothrow__ , __leaf__));



extern __pid_t getsid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));



extern __uid_t getuid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __uid_t geteuid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __gid_t getgid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __gid_t getegid (void) __attribute__ ((__nothrow__ , __leaf__));




extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__ , __leaf__)) ;
# 703 "/usr/include/unistd.h" 3 4
extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;






extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;
# 759 "/usr/include/unistd.h" 3 4
extern __pid_t fork (void) __attribute__ ((__nothrow__));







extern __pid_t vfork (void) __attribute__ ((__nothrow__ , __leaf__));





extern char *ttyname (int __fd) __attribute__ ((__nothrow__ , __leaf__));



extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;



extern int isatty (int __fd) __attribute__ ((__nothrow__ , __leaf__));





extern int ttyslot (void) __attribute__ ((__nothrow__ , __leaf__));




extern int link (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern int linkat (int __fromfd, const char *__from, int __tofd,
     const char *__to, int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4))) ;




extern int symlink (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern ssize_t readlink (const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern int symlinkat (const char *__from, int __tofd,
        const char *__to) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3))) ;


extern ssize_t readlinkat (int __fd, const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3))) ;



extern int unlink (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern int unlinkat (int __fd, const char *__name, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern int rmdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__ , __leaf__));


extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__ , __leaf__));






extern char *getlogin (void);







extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)));




extern int setlogin (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 874 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/getopt.h" 1 3 4
# 57 "/usr/include/getopt.h" 3 4
extern char *optarg;
# 71 "/usr/include/getopt.h" 3 4
extern int optind;




extern int opterr;



extern int optopt;
# 150 "/usr/include/getopt.h" 3 4
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__ , __leaf__));
# 875 "/usr/include/unistd.h" 2 3 4







extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int sethostname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;



extern int sethostid (long int __id) __attribute__ ((__nothrow__ , __leaf__)) ;





extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int setdomainname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;





extern int vhangup (void) __attribute__ ((__nothrow__ , __leaf__));


extern int revoke (const char *__file) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;







extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int acct (const char *__name) __attribute__ ((__nothrow__ , __leaf__));



extern char *getusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void endusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void setusershell (void) __attribute__ ((__nothrow__ , __leaf__));





extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__ , __leaf__)) ;






extern int chroot (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;



extern char *getpass (const char *__prompt) __attribute__ ((__nonnull__ (1)));







extern int fsync (int __fd);
# 972 "/usr/include/unistd.h" 3 4
extern long int gethostid (void);


extern void sync (void) __attribute__ ((__nothrow__ , __leaf__));





extern int getpagesize (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern int getdtablesize (void) __attribute__ ((__nothrow__ , __leaf__));
# 996 "/usr/include/unistd.h" 3 4
extern int truncate (const char *__file, __off_t __length)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 1019 "/usr/include/unistd.h" 3 4
extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__ , __leaf__)) ;
# 1040 "/usr/include/unistd.h" 3 4
extern int brk (void *__addr) __attribute__ ((__nothrow__ , __leaf__)) ;





extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__ , __leaf__));
# 1061 "/usr/include/unistd.h" 3 4
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__ , __leaf__));
# 1084 "/usr/include/unistd.h" 3 4
extern int lockf (int __fd, int __cmd, __off_t __len) ;
# 1115 "/usr/include/unistd.h" 3 4
extern int fdatasync (int __fildes);
# 1154 "/usr/include/unistd.h" 3 4

# 29 "../../../server-code/src/common/utils.h" 2
# 39 "../../../server-code/src/common/utils.h"

# 39 "../../../server-code/src/common/utils.h"
void WriteDump(FILE* fp, const void* buffer, size_t length);
void ShowDump(const void* buffer, size_t length);

void findfile(const char *p, const char *pat, void (func)(const char*));

# 43 "../../../server-code/src/common/utils.h" 3 4
_Bool 
# 43 "../../../server-code/src/common/utils.h"
    exists(const char* filename);


unsigned int get_percentage(const unsigned int A, const unsigned int B);

int64 apply_percentrate64(int64 value, int rate, int maxrate);
int apply_percentrate(int value, int rate, int maxrate);

const char* timestamp2string(char* str, size_t size, time_t timestamp, const char* format);





extern uint8 GetByte(uint32 val, int idx);
extern uint16 GetWord(uint32 val, int idx);
extern uint16 MakeWord(uint8 byte0, uint8 byte1);
extern uint32 MakeDWord(uint16 word0, uint16 word1);




extern int16 MakeShortLE(int16 val);
extern int32 MakeLongLE(int32 val);
extern uint16 GetUShort(const unsigned char* buf);
extern uint32 GetULong(const unsigned char* buf);
extern int32 GetLong(const unsigned char* buf);
extern float GetFloat(const unsigned char* buf);

size_t hread(void * ptr, size_t size, size_t count, FILE * stream);
size_t hwrite(const void * ptr, size_t size, size_t count, FILE * stream);
# 83 "../../../server-code/src/common/utils.h"
struct HCache_interface {
 void (*init) (void);

 
# 86 "../../../server-code/src/common/utils.h" 3 4
_Bool 
# 86 "../../../server-code/src/common/utils.h"
     (*check) (const char *file);
 FILE *(*open) (const char *file, const char *opt);

 time_t recompile_time;
 
# 90 "../../../server-code/src/common/utils.h" 3 4
_Bool 
# 90 "../../../server-code/src/common/utils.h"
     enabled;
};


void HCache_defaults(void);


extern struct HCache_interface *HCache;
# 42 "../../../server-code/src/login/login.c" 2


# 1 "/usr/include/stdlib.h" 1 3 4
# 32 "/usr/include/stdlib.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 33 "/usr/include/stdlib.h" 2 3 4








# 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 1 3 4
# 50 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 3 4

# 50 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 3 4
typedef enum
{
  P_ALL,
  P_PID,
  P_PGID
} idtype_t;
# 42 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 1 3 4
# 66 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 3 4
union wait
  {
    int w_status;
    struct
      {

 unsigned int __w_termsig:7;
 unsigned int __w_coredump:1;
 unsigned int __w_retcode:8;
 unsigned int:16;







      } __wait_terminated;
    struct
      {

 unsigned int __w_stopval:8;
 unsigned int __w_stopsig:8;
 unsigned int:16;






      } __wait_stopped;
  };
# 43 "/usr/include/stdlib.h" 2 3 4
# 67 "/usr/include/stdlib.h" 3 4
typedef union
  {
    union wait *__uptr;
    int *__iptr;
  } __WAIT_STATUS __attribute__ ((__transparent_union__));
# 95 "/usr/include/stdlib.h" 3 4


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;







__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;


# 139 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;




extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

# 305 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;


extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;




# 1 "/usr/include/x86_64-linux-gnu/sys/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4






typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;
# 60 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __dev_t dev_t;
# 70 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __mode_t mode_t;




typedef __nlink_t nlink_t;
# 104 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __id_t id_t;
# 115 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 146 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 147 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 200 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));
# 219 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/select.h" 1 3 4
# 30 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/select.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/select.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/select.h" 2 3 4
# 31 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/sigset.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/sigset.h" 3 4
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 34 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4



typedef __sigset_t sigset_t;







# 1 "/usr/include/x86_64-linux-gnu/bits/time.h" 1 3 4
# 30 "/usr/include/x86_64-linux-gnu/bits/time.h" 3 4
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 46 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4


typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 64 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
# 96 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4

# 106 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 118 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
# 131 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4

# 220 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 3 4


__extension__
extern unsigned int gnu_dev_major (unsigned long long int __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__
extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__
extern unsigned long long int gnu_dev_makedev (unsigned int __major,
            unsigned int __minor)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 58 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 3 4

# 223 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4





typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 270 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 1 3 4
# 21 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 2 3 4
# 60 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
typedef unsigned long int pthread_t;


union pthread_attr_t
{
  char __size[56];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;





typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
# 90 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;

    unsigned int __nusers;



    int __kind;

    short __spins;
    short __elision;
    __pthread_list_t __list;
# 125 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
  } __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;




typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;





typedef union
{

  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    int __writer;
    int __shared;
    signed char __rwelision;




    unsigned char __pad1[7];


    unsigned long int __pad2;


    unsigned int __flags;

  } __data;
# 220 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 271 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



# 315 "/usr/include/stdlib.h" 2 3 4






extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));


extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));






extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));

extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));




extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));







extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;

  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));









extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;










extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));

extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));




extern void cfree (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));



# 1 "/usr/include/alloca.h" 1 3 4
# 24 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 25 "/usr/include/alloca.h" 2 3 4







extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));






# 493 "/usr/include/stdlib.h" 2 3 4





extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;




extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (2))) ;




extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));





extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));







extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));






extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;

# 578 "/usr/include/stdlib.h" 3 4
extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
# 606 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 619 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 641 "/usr/include/stdlib.h" 3 4
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
# 662 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 711 "/usr/include/stdlib.h" 3 4





extern int system (const char *__command) ;

# 733 "/usr/include/stdlib.h" 3 4
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;






typedef int (*__compar_fn_t) (const void *, const void *);
# 751 "/usr/include/stdlib.h" 3 4



extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;







extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
# 774 "/usr/include/stdlib.h" 3 4
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;



__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;







extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;




__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;

# 811 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));






extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));

extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__));








extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 898 "/usr/include/stdlib.h" 3 4
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
# 950 "/usr/include/stdlib.h" 3 4
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


# 1 "/usr/include/x86_64-linux-gnu/bits/stdlib-float.h" 1 3 4
# 955 "/usr/include/stdlib.h" 2 3 4
# 967 "/usr/include/stdlib.h" 3 4

# 45 "../../../server-code/src/login/login.c" 2


# 46 "../../../server-code/src/login/login.c"
struct login_interface login_s;
struct login_interface *login;
struct Login_Config login_config_;
struct mmo_char_server server[30];

struct Account_engine account_engine[] = {
 {account_db_sql, 
# 52 "../../../server-code/src/login/login.c" 3 4
                 ((void *)0)
# 52 "../../../server-code/src/login/login.c"
                     }
};


AccountDB* accounts = 
# 56 "../../../server-code/src/login/login.c" 3 4
                     ((void *)0)
# 56 "../../../server-code/src/login/login.c"
                         ;
# 66 "../../../server-code/src/login/login.c"
static struct DBData login_create_online_user(union DBKey key, va_list args)
{
 struct online_login_data* p;
 ((p) = (struct online_login_data *) (iMalloc->calloc(((1)),(sizeof(struct online_login_data)),"../../../server-code/src/login/login.c", 69, __func__)));
 p->account_id = key.i;
 p->char_server = -1;
 p->waiting_disconnect = (-1);
 return DB->ptr2data(p);
}

struct online_login_data* login_add_online_user(int char_server, int account_id)
{
 struct online_login_data* p;
 p = ( DB->data2ptr((login->online_db)->ensure((login->online_db),DB->i2key(account_id),(login->create_online_user))) );
 p->char_server = char_server;
 if( p->waiting_disconnect != (-1) )
 {
  timer->delete(p->waiting_disconnect, login->waiting_disconnect_timer);
  p->waiting_disconnect = (-1);
 }
 return p;
}

void login_remove_online_user(int account_id)
{
 struct online_login_data* p;
 p = (struct online_login_data*)( DB->data2ptr((login->online_db)->get((login->online_db),DB->i2key(account_id))) );
 if( p == 
# 93 "../../../server-code/src/login/login.c" 3 4
         ((void *)0) 
# 93 "../../../server-code/src/login/login.c"
              )
  return;
 if( p->waiting_disconnect != (-1) )
  timer->delete(p->waiting_disconnect, login->waiting_disconnect_timer);

 ( (login->online_db)->remove((login->online_db),DB->i2key(account_id),
# 98 "../../../server-code/src/login/login.c" 3 4
((void *)0)
# 98 "../../../server-code/src/login/login.c"
) );
}

static int login_waiting_disconnect_timer(int tid, int64 tick, int id, intptr_t data) {
 struct online_login_data* p = (struct online_login_data*)( DB->data2ptr((login->online_db)->get((login->online_db),DB->i2key(id))) );
 if( p != 
# 103 "../../../server-code/src/login/login.c" 3 4
         ((void *)0) 
# 103 "../../../server-code/src/login/login.c"
              && p->waiting_disconnect == tid && p->account_id == id )
 {
  p->waiting_disconnect = (-1);
  login->remove_online_user(id);
  ( (login->auth_db)->remove((login->auth_db),DB->i2key(id),
# 107 "../../../server-code/src/login/login.c" 3 4
 ((void *)0)
# 107 "../../../server-code/src/login/login.c"
 ) );
 }
 return 0;
}




static int login_online_db_setoffline(union DBKey key, struct DBData *data, va_list ap)
{
 struct online_login_data* p = DB->data2ptr(data);
 int server_id = 
# 118 "../../../server-code/src/login/login.c" 3 4
                __builtin_va_arg(
# 118 "../../../server-code/src/login/login.c"
                ap
# 118 "../../../server-code/src/login/login.c" 3 4
                ,
# 118 "../../../server-code/src/login/login.c"
                int
# 118 "../../../server-code/src/login/login.c" 3 4
                )
# 118 "../../../server-code/src/login/login.c"
                               ;
 do { if (((void)(p), 
# 119 "../../../server-code/src/login/login.c" 3 4
0
# 119 "../../../server-code/src/login/login.c"
)) return(0); } while(0);
 if( server_id == -1 )
 {
  p->char_server = -1;
  if( p->waiting_disconnect != (-1) )
  {
   timer->delete(p->waiting_disconnect, login->waiting_disconnect_timer);
   p->waiting_disconnect = (-1);
  }
 }
 else if( p->char_server == server_id )
  p->char_server = -2;
 return 0;
}




static int login_online_data_cleanup_sub(union DBKey key, struct DBData *data, va_list ap)
{
 struct online_login_data *character= DB->data2ptr(data);
 do { if (((void)(character), 
# 140 "../../../server-code/src/login/login.c" 3 4
0
# 140 "../../../server-code/src/login/login.c"
)) return(0); } while(0);
 if (character->char_server == -2)
  login->remove_online_user(character->account_id);
 return 0;
}

static int login_online_data_cleanup(int tid, int64 tick, int id, intptr_t data) {
 login->online_db->foreach(login->online_db, login->online_data_cleanup_sub);
 return 0;
}





int charif_sendallwos(int sfd, uint8* buf, size_t len)
{
 int i, c;

 do { if (((void)(buf), 
# 159 "../../../server-code/src/login/login.c" 3 4
0
# 159 "../../../server-code/src/login/login.c"
)) return(0); } while(0);
 for( i = 0, c = 0; i < ( (int)(sizeof(server)/sizeof((server)[0])) ); ++i )
 {
  int fd = server[i].fd;
  if (sockt->session_is_valid(fd) && fd != sfd) {
   WFIFOHEAD(fd,len);
   memcpy(WFIFOP(fd,0), buf, len);
   WFIFOSET(fd,len);
   ++c;
  }
 }

 return c;
}



void chrif_server_init(int id)
{
 do { if (( (id >= 0 && id < 30) ? 
# 178 "../../../server-code/src/login/login.c" 3 4
0 
# 178 "../../../server-code/src/login/login.c"
: (nullpo->assert_report("../../../server-code/src/login/login.c", 178, __func__, "id >= 0 && id < 30", "failed assertion"), 
# 178 "../../../server-code/src/login/login.c" 3 4
1
# 178 "../../../server-code/src/login/login.c"
) )) return; } while(0);
 memset(&server[id], 0, sizeof(server[id]));
 server[id].fd = -1;
}



void chrif_server_destroy(int id)
{
 do { if (( (id >= 0 && id < 30) ? 
# 187 "../../../server-code/src/login/login.c" 3 4
0 
# 187 "../../../server-code/src/login/login.c"
: (nullpo->assert_report("../../../server-code/src/login/login.c", 187, __func__, "id >= 0 && id < 30", "failed assertion"), 
# 187 "../../../server-code/src/login/login.c" 3 4
1
# 187 "../../../server-code/src/login/login.c"
) )) return; } while(0);
 if (server[id].fd != -1)
 {
  sockt->close(server[id].fd);
  server[id].fd = -1;
 }
}



void chrif_server_reset(int id)
{
 login->online_db->foreach(login->online_db, login->online_db_setoffline, id);
 chrif_server_destroy(id);
 chrif_server_init(id);
}



void chrif_on_disconnect(int id)
{
 do { if (( (id >= 0 && id < 30) ? 
# 208 "../../../server-code/src/login/login.c" 3 4
0 
# 208 "../../../server-code/src/login/login.c"
: (nullpo->assert_report("../../../server-code/src/login/login.c", 208, __func__, "id >= 0 && id < 30", "failed assertion"), 
# 208 "../../../server-code/src/login/login.c" 3 4
1
# 208 "../../../server-code/src/login/login.c"
) )) return; } while(0);
 (showmsg->showStatus(("Char-server '%s' has disconnected.\n"), server[id].name));
 chrif_server_reset(id);
}





static int login_sync_ip_addresses(int tid, int64 tick, int id, intptr_t data) {
 uint8 buf[2];
 (showmsg->showInfo(("IP Sync in progress...\n")));
 WBUFW(buf,0) = 0x2735;
 charif_sendallwos(-1, buf, 2);
 return 0;
}






# 229 "../../../server-code/src/login/login.c" 3 4
_Bool 
# 229 "../../../server-code/src/login/login.c"
    login_check_encrypted(const char* str1, const char* str2, const char* passwd)
{
 char tmpstr[64+1], md5str[32+1];

 do { if (((void)(str1), 
# 233 "../../../server-code/src/login/login.c" 3 4
0
# 233 "../../../server-code/src/login/login.c"
)) return(0); } while(0);
 do { if (((void)(str2), 
# 234 "../../../server-code/src/login/login.c" 3 4
0
# 234 "../../../server-code/src/login/login.c"
)) return(0); } while(0);
 do { if (((void)(passwd), 
# 235 "../../../server-code/src/login/login.c" 3 4
0
# 235 "../../../server-code/src/login/login.c"
)) return(0); } while(0);
 (strlib->safesnprintf_((tmpstr),(sizeof(tmpstr)),("%s%s"), str1, str2));
 MD5_String(tmpstr, md5str);

 return (0==strcmp(passwd, md5str));
}


# 242 "../../../server-code/src/login/login.c" 3 4
_Bool 
# 242 "../../../server-code/src/login/login.c"
    login_check_password(const char* md5key, int passwdenc, const char* passwd, const char* refpass)
{
 do { if (((void)(passwd), 
# 244 "../../../server-code/src/login/login.c" 3 4
0
# 244 "../../../server-code/src/login/login.c"
)) return(0); } while(0);
 do { if (((void)(refpass), 
# 245 "../../../server-code/src/login/login.c" 3 4
0
# 245 "../../../server-code/src/login/login.c"
)) return(0); } while(0);
 if(passwdenc == PWENC_NONE) {
  return (0==strcmp(passwd, refpass));
 } else {



  return ((passwdenc&PWENC_ENCRYPT) && login->check_encrypted(md5key, refpass, passwd)) ||
         ((passwdenc&PWENC_ENCRYPT2) && login->check_encrypted(refpass, md5key, passwd));
 }
}
# 265 "../../../server-code/src/login/login.c"
uint32 login_lan_subnet_check(uint32 ip)
{
 return sockt->lan_subnet_check(ip, 
# 267 "../../../server-code/src/login/login.c" 3 4
                                   ((void *)0)
# 267 "../../../server-code/src/login/login.c"
                                       );
}

void login_fromchar_auth_ack(int fd, int account_id, uint32 login_id1, uint32 login_id2, uint8 sex, int request_id, struct login_auth_node* node)
{
 WFIFOHEAD(fd,33);
 WFIFOW(fd,0) = 0x2713;
 WFIFOL(fd,2) = account_id;
 WFIFOL(fd,6) = login_id1;
 WFIFOL(fd,10) = login_id2;
 WFIFOB(fd,14) = sex;
 if (node)
 {
  WFIFOB(fd,15) = 0;
  WFIFOL(fd,16) = request_id;
  WFIFOL(fd,20) = node->version;
  WFIFOB(fd,24) = node->clienttype;
  WFIFOL(fd,25) = node->group_id;
  WFIFOL(fd,29) = (unsigned int)node->expiration_time;
 }
 else
 {
  WFIFOB(fd,15) = 1;
  WFIFOL(fd,16) = request_id;
  WFIFOL(fd,20) = 0;
  WFIFOB(fd,24) = 0;
  WFIFOL(fd,25) = 0;
  WFIFOL(fd,29) = 0;
 }
 WFIFOSET(fd,33);
}

void login_fromchar_parse_auth(int fd, int id, const char *const ip)
{
 struct login_auth_node* node;

 int account_id = RFIFOL(fd,2);
 uint32 login_id1 = RFIFOL(fd,6);
 uint32 login_id2 = RFIFOL(fd,10);
 uint8 sex = RFIFOB(fd,14);

 int request_id = RFIFOL(fd,19);
 RFIFOSKIP(fd,23);

 node = (struct login_auth_node*)( DB->data2ptr((login->auth_db)->get((login->auth_db),DB->i2key(account_id))) );
 if( core->runflag == LOGINSERVER_ST_RUNNING &&
  node != 
# 313 "../../../server-code/src/login/login.c" 3 4
         ((void *)0) 
# 313 "../../../server-code/src/login/login.c"
              &&
  node->account_id == account_id &&
  node->login_id1 == login_id1 &&
  node->login_id2 == login_id2 &&
  node->sex == ( ((sex) == SEX_FEMALE) ? 'F' : ((sex) == SEX_MALE) ? 'M' : 'S' )
                            )
 {



  login->fromchar_auth_ack(fd, account_id, login_id1, login_id2, sex, request_id, node);

  ( (login->auth_db)->remove((login->auth_db),DB->i2key(account_id),
# 325 "../../../server-code/src/login/login.c" 3 4
 ((void *)0)
# 325 "../../../server-code/src/login/login.c"
 ) );
 }
 else
 {
  do { if (((void)(ip), 
# 329 "../../../server-code/src/login/login.c" 3 4
 0
# 329 "../../../server-code/src/login/login.c"
 )) return; } while(0);
  (showmsg->showStatus(("Char-server '%s': authentication of the account %d REFUSED (ip: %s).\n"), server[id].name, account_id, ip));
  login->fromchar_auth_ack(fd, account_id, login_id1, login_id2, sex, request_id, 
# 331 "../../../server-code/src/login/login.c" 3 4
                                                                                 ((void *)0)
# 331 "../../../server-code/src/login/login.c"
                                                                                     );
 }
}

void login_fromchar_parse_update_users(int fd, int id)
{
 int users = RFIFOL(fd,2);
 RFIFOSKIP(fd,6);


 if( server[id].users != users )
 {
  (showmsg->showStatus(("set users %s : %d\n"), server[id].name, users));

  server[id].users = (uint16)users;
 }
}

void login_fromchar_parse_request_change_email(int fd, int id, const char *const ip)
{
 struct mmo_account acc;
 char email[40];

 int account_id = RFIFOL(fd,2);
 (strlib->safestrncpy_((email),(RFIFOP(fd,6)),(40))); (strlib->remove_control_chars_(email));
 RFIFOSKIP(fd,46);

 if( (strlib->e_mail_check_(email)) == 0 )
  (showmsg->showNotice(("Char-server '%s': Attempt to create an e-mail on an account with a default e-mail REFUSED - e-mail is invalid (account: %d, ip: %s)\n"), server[id].name, account_id, ip));
 else
 if( !accounts->load_num(accounts, &acc, account_id) || strcmp(acc.email, "a@a.com") == 0 || acc.email[0] == '\0' )
  (showmsg->showNotice(("Char-server '%s': Attempt to create an e-mail on an account with a default e-mail REFUSED - account doesn't exist or e-mail of account isn't default e-mail (account: %d, ip: %s).\n"), server[id].name, account_id, ip));
 else {
  memcpy(acc.email, email, sizeof(acc.email));
  (showmsg->showNotice(("Char-server '%s': Create an e-mail on an account with a default e-mail (account: %d, new e-mail: %s, ip: %s).\n"), server[id].name, account_id, email, ip));

  accounts->save(accounts, &acc);
 }
}

void login_fromchar_account(int fd, int account_id, struct mmo_account *acc)
{
 WFIFOHEAD(fd,72);
 WFIFOW(fd,0) = 0x2717;
 WFIFOL(fd,2) = account_id;
 if (acc)
 {
  time_t expiration_time = 0;
  char email[40] = "";
  int group_id = 0;
  uint8 char_slots = 0;
  char birthdate[10+1] = "";
  char pincode[4+1] = "\0\0\0\0";

  (strlib->safestrncpy_((email),(acc->email),(sizeof(email))));
  expiration_time = acc->expiration_time;
  group_id = acc->group_id;
  char_slots = acc->char_slots;
  (strlib->safestrncpy_((pincode),(acc->pincode),(sizeof(pincode))));
  (strlib->safestrncpy_((birthdate),(acc->birthdate),(sizeof(birthdate))));
  if (pincode[0] == '\0')
   memset(pincode,'\0',sizeof(pincode));

  (strlib->safestrncpy_((WFIFOP(fd,6)),(email),(40)));
  WFIFOL(fd,46) = (uint32)expiration_time;
  WFIFOB(fd,50) = (unsigned char)group_id;
  WFIFOB(fd,51) = char_slots;
  (strlib->safestrncpy_((WFIFOP(fd,52)),(birthdate),(10+1)));
  (strlib->safestrncpy_((WFIFOP(fd,63)),(pincode),(4+1)));
  WFIFOL(fd,68) = acc->pincode_change;
 }
 else
 {
  (strlib->safestrncpy_((WFIFOP(fd,6)),(""),(40)));
  WFIFOL(fd,46) = 0;
  WFIFOB(fd,50) = 0;
  WFIFOB(fd,51) = 0;
  (strlib->safestrncpy_((WFIFOP(fd,52)),(""),(10+1)));
  (strlib->safestrncpy_((WFIFOP(fd,63)),("\0\0\0\0"),(4+1)));
  WFIFOL(fd,68) = 0;
 }
 WFIFOSET(fd,72);
}

void login_fromchar_parse_account_data(int fd, int id, const char *const ip)
{
 struct mmo_account acc;

 int account_id = RFIFOL(fd,2);
 RFIFOSKIP(fd,6);

 if( !accounts->load_num(accounts, &acc, account_id) )
 {
  (showmsg->showNotice(("Char-server '%s': account %d NOT found (ip: %s).\n"), server[id].name, account_id, ip));
  login->fromchar_account(fd, account_id, 
# 425 "../../../server-code/src/login/login.c" 3 4
                                         ((void *)0)
# 425 "../../../server-code/src/login/login.c"
                                             );
 }
 else {
  login->fromchar_account(fd, account_id, &acc);
 }
}

void login_fromchar_pong(int fd)
{
 WFIFOHEAD(fd,2);
 WFIFOW(fd,0) = 0x2718;
 WFIFOSET(fd,2);
}

void login_fromchar_parse_ping(int fd)
{
 RFIFOSKIP(fd,2);
 login->fromchar_pong(fd);
}

void login_fromchar_parse_change_email(int fd, int id, const char *const ip)
{
 struct mmo_account acc;
 char actual_email[40];
 char new_email[40];

 int account_id = RFIFOL(fd,2);
 (strlib->safestrncpy_((actual_email),(RFIFOP(fd,6)),(40)));
 (strlib->safestrncpy_((new_email),(RFIFOP(fd,46)),(40)));
 RFIFOSKIP(fd, 86);

 if( (strlib->e_mail_check_(actual_email)) == 0 )
  (showmsg->showNotice(("Char-server '%s': Attempt to modify an e-mail on an account (@email GM command), but actual email is invalid (account: %d, ip: %s)\n"), server[id].name, account_id, ip));
 else
 if( (strlib->e_mail_check_(new_email)) == 0 )
  (showmsg->showNotice(("Char-server '%s': Attempt to modify an e-mail on an account (@email GM command) with a invalid new e-mail (account: %d, ip: %s)\n"), server[id].name, account_id, ip));
 else
 if( strcasecmp(new_email, "a@a.com") == 0 )
  (showmsg->showNotice(("Char-server '%s': Attempt to modify an e-mail on an account (@email GM command) with a default e-mail (account: %d, ip: %s)\n"), server[id].name, account_id, ip));
 else
 if( !accounts->load_num(accounts, &acc, account_id) )
  (showmsg->showNotice(("Char-server '%s': Attempt to modify an e-mail on an account (@email GM command), but account doesn't exist (account: %d, ip: %s).\n"), server[id].name, account_id, ip));
 else
 if( strcasecmp(acc.email, actual_email) != 0 )
  (showmsg->showNotice(("Char-server '%s': Attempt to modify an e-mail on an account (@email GM command), but actual e-mail is incorrect (account: %d (%s), actual e-mail: %s, proposed e-mail: %s, ip: %s).\n"), server[id].name, account_id, acc.userid, acc.email, actual_email, ip));
 else {
  (strlib->safestrncpy_((acc.email),(new_email),(sizeof(acc.email))));
  (showmsg->showNotice(("Char-server '%s': Modify an e-mail on an account (@email GM command) (account: %d (%s), new e-mail: %s, ip: %s).\n"), server[id].name, account_id, acc.userid, new_email, ip));

  accounts->save(accounts, &acc);
 }
}

void login_fromchar_account_update_other(int account_id, unsigned int state)
{
 uint8 buf[11];
 WBUFW(buf,0) = 0x2731;
 WBUFL(buf,2) = account_id;
 WBUFB(buf,6) = 0;
 WBUFL(buf,7) = state;
 charif_sendallwos(-1, buf, 11);
}

void login_fromchar_parse_account_update(int fd, int id, const char *const ip)
{
 struct mmo_account acc;

 int account_id = RFIFOL(fd,2);
 unsigned int state = RFIFOL(fd,6);
 RFIFOSKIP(fd,10);

 if( !accounts->load_num(accounts, &acc, account_id) )
  (showmsg->showNotice(("Char-server '%s': Error of Status change (account: %d not found, suggested status %u, ip: %s).\n"), server[id].name, account_id, state, ip));
 else
 if( acc.state == state )
  (showmsg->showNotice(("Char-server '%s':  Error of Status change - actual status is already the good status (account: %d, status %u, ip: %s).\n"), server[id].name, account_id, state, ip));
 else {
  (showmsg->showNotice(("Char-server '%s': Status change (account: %d, new status %u, ip: %s).\n"), server[id].name, account_id, state, ip));

  acc.state = state;

  accounts->save(accounts, &acc);


  if (state != 0) {
   login->fromchar_account_update_other(account_id, state);
  }
 }
}

void login_fromchar_ban(int account_id, time_t timestamp)
{
 uint8 buf[11];
 WBUFW(buf,0) = 0x2731;
 WBUFL(buf,2) = account_id;
 WBUFB(buf,6) = 1;
 WBUFL(buf,7) = (uint32)timestamp;
 charif_sendallwos(-1, buf, 11);
}

void login_fromchar_parse_ban(int fd, int id, const char *const ip)
{
 struct mmo_account acc;

 int account_id = RFIFOL(fd,2);
 int year = RFIFOW(fd,6);
 int month = RFIFOW(fd,8);
 int mday = RFIFOW(fd,10);
 int hour = RFIFOW(fd,12);
 int min = RFIFOW(fd,14);
 int sec = RFIFOW(fd,16);
 RFIFOSKIP(fd,18);

 if (!accounts->load_num(accounts, &acc, account_id)) {
  (showmsg->showNotice(("Char-server '%s': Error of ban request (account: %d not found, ip: %s).\n"), server[id].name, account_id, ip));
 } else {
  time_t timestamp;
  struct tm *tmtime;
  if (acc.unban_time == 0 || acc.unban_time < time(
# 543 "../../../server-code/src/login/login.c" 3 4
                                                  ((void *)0)
# 543 "../../../server-code/src/login/login.c"
                                                      ))
   timestamp = time(
# 544 "../../../server-code/src/login/login.c" 3 4
                   ((void *)0)
# 544 "../../../server-code/src/login/login.c"
                       );
  else
   timestamp = acc.unban_time;
  tmtime = localtime(&timestamp);
  tmtime->tm_year += year;
  tmtime->tm_mon += month;
  tmtime->tm_mday += mday;
  tmtime->tm_hour += hour;
  tmtime->tm_min += min;
  tmtime->tm_sec += sec;
  timestamp = mktime(tmtime);
  if (timestamp == -1) {
   (showmsg->showNotice(("Char-server '%s': Error of ban request (account: %d, invalid date, ip: %s).\n"), server[id].name, account_id, ip));
  } else if( timestamp <= time(
# 557 "../../../server-code/src/login/login.c" 3 4
                              ((void *)0)
# 557 "../../../server-code/src/login/login.c"
                                  ) || timestamp == 0 ) {
   (showmsg->showNotice(("Char-server '%s': Error of ban request (account: %d, new date unbans the account, ip: %s).\n"), server[id].name, account_id, ip));
  } else {
   char tmpstr[24];
   timestamp2string(tmpstr, sizeof(tmpstr), timestamp, login->config->date_format);
   (showmsg->showNotice(("Char-server '%s': Ban request (account: %d, new final date of banishment: %ld (%s), ip: %s).\n"), server[id].name, account_id, (long)timestamp, tmpstr, ip))
                                                                       ;

   acc.unban_time = timestamp;


   accounts->save(accounts, &acc);

   login->fromchar_ban(account_id, timestamp);
  }
 }
}

void login_fromchar_change_sex_other(int account_id, char sex)
{
 unsigned char buf[7];
 WBUFW(buf,0) = 0x2723;
 WBUFL(buf,2) = account_id;
 WBUFB(buf,6) = ( ((sex) == 'F') ? SEX_FEMALE : ((sex) == 'M') ? SEX_MALE : SEX_SERVER );
 charif_sendallwos(-1, buf, 7);
}

void login_fromchar_parse_change_sex(int fd, int id, const char *const ip)
{
 struct mmo_account acc;

 int account_id = RFIFOL(fd,2);
 RFIFOSKIP(fd,6);

 if( !accounts->load_num(accounts, &acc, account_id) )
  (showmsg->showNotice(("Char-server '%s': Error of sex change (account: %d not found, ip: %s).\n"), server[id].name, account_id, ip));
 else
 if( acc.sex == 'S' )
  (showmsg->showNotice(("Char-server '%s': Error of sex change - account to change is a Server account (account: %d, ip: %s).\n"), server[id].name, account_id, ip));
 else
 {
  char sex = ( acc.sex == 'M' ) ? 'F' : 'M';

  (showmsg->showNotice(("Char-server '%s': Sex change (account: %d, new sex %c, ip: %s).\n"), server[id].name, account_id, sex, ip));

  acc.sex = sex;

  accounts->save(accounts, &acc);


  login->fromchar_change_sex_other(account_id, sex);
 }
}

void login_fromchar_parse_account_reg2(int fd, int id, const char *const ip)
{
 struct mmo_account acc;

 int account_id = RFIFOL(fd,4);

 if( !accounts->load_num(accounts, &acc, account_id) )
  (showmsg->showStatus(("Char-server '%s': receiving (from the char-server) of account_reg2 (account: %d not found, ip: %s).\n"), server[id].name, account_id, ip));
 else {
  mmo_save_accreg2(accounts,fd,account_id,RFIFOL(fd, 8));
 }
 RFIFOSKIP(fd,RFIFOW(fd,2));
}

void login_fromchar_parse_unban(int fd, int id, const char *const ip)
{
 struct mmo_account acc;

 int account_id = RFIFOL(fd,2);
 RFIFOSKIP(fd,6);

 if( !accounts->load_num(accounts, &acc, account_id) )
  (showmsg->showNotice(("Char-server '%s': Error of Unban request (account: %d not found, ip: %s).\n"), server[id].name, account_id, ip));
 else
 if( acc.unban_time == 0 )
  (showmsg->showNotice(("Char-server '%s': Error of Unban request (account: %d, no change for unban date, ip: %s).\n"), server[id].name, account_id, ip));
 else
 {
  (showmsg->showNotice(("Char-server '%s': Unban request (account: %d, ip: %s).\n"), server[id].name, account_id, ip));
  acc.unban_time = 0;
  accounts->save(accounts, &acc);
 }
}

void login_fromchar_parse_account_online(int fd, int id)
{
 login->add_online_user(id, RFIFOL(fd,2));
 RFIFOSKIP(fd,6);
}

void login_fromchar_parse_account_offline(int fd)
{
 login->remove_online_user(RFIFOL(fd,2));
 RFIFOSKIP(fd,6);
}

void login_fromchar_parse_online_accounts(int fd, int id)
{
 uint32 i, users;
 login->online_db->foreach(login->online_db, login->online_db_setoffline, id);
 users = RFIFOW(fd,4);
 for (i = 0; i < users; i++) {
  int aid = RFIFOL(fd,6+i*4);
  struct online_login_data *p = ( DB->data2ptr((login->online_db)->ensure((login->online_db),DB->i2key(aid),(login->create_online_user))) );
  p->char_server = id;
  if (p->waiting_disconnect != (-1))
  {
   timer->delete(p->waiting_disconnect, login->waiting_disconnect_timer);
   p->waiting_disconnect = (-1);
  }
 }
}

void login_fromchar_parse_request_account_reg2(int fd)
{
 int account_id = RFIFOL(fd,2);
 int char_id = RFIFOL(fd,6);
 RFIFOSKIP(fd,10);

 mmo_send_accreg2(accounts,fd,account_id,char_id);
}

void login_fromchar_parse_update_wan_ip(int fd, int id)
{
 server[id].ip = ntohl(RFIFOL(fd,2));
 (showmsg->showInfo(("Updated IP of Server #%d to %u.%u.%u.%u.\n"),id, CONVIP(server[id].ip)));
 RFIFOSKIP(fd,6);
}

void login_fromchar_parse_all_offline(int fd, int id)
{
 (showmsg->showInfo(("Setting accounts from char-server %d offline.\n"), id));
 login->online_db->foreach(login->online_db, login->online_db_setoffline, id);
 RFIFOSKIP(fd,2);
}

void login_fromchar_parse_change_pincode(int fd)
{
 struct mmo_account acc;

 if (accounts->load_num(accounts, &acc, RFIFOL(fd,2))) {
  (strlib->safestrncpy_((acc.pincode),(RFIFOP(fd,6)),(sizeof(acc.pincode))));
  acc.pincode_change = ((unsigned int)time(
# 703 "../../../server-code/src/login/login.c" 3 4
                                          ((void *)0)
# 703 "../../../server-code/src/login/login.c"
                                              ));
  accounts->save(accounts, &acc);
 }
 RFIFOSKIP(fd,11);
}


# 709 "../../../server-code/src/login/login.c" 3 4
_Bool 
# 709 "../../../server-code/src/login/login.c"
    login_fromchar_parse_wrong_pincode(int fd)
{
 struct mmo_account acc;

 if( accounts->load_num(accounts, &acc, RFIFOL(fd,2) ) ) {
  struct online_login_data* ld = (struct online_login_data*)( DB->data2ptr((login->online_db)->get((login->online_db),DB->i2key(acc.account_id))) );

  if (ld == 
# 716 "../../../server-code/src/login/login.c" 3 4
           ((void *)0)
# 716 "../../../server-code/src/login/login.c"
               ) {
   RFIFOSKIP(fd,6);
   return 
# 718 "../../../server-code/src/login/login.c" 3 4
         1
# 718 "../../../server-code/src/login/login.c"
             ;
  }

  login_log(sockt->host2ip(acc.last_ip), acc.userid, 100, "PIN Code check failed");
 }

 login->remove_online_user(acc.account_id);
 RFIFOSKIP(fd,6);
 return 
# 726 "../../../server-code/src/login/login.c" 3 4
       0
# 726 "../../../server-code/src/login/login.c"
            ;
}

void login_fromchar_accinfo(int fd, int account_id, int u_fd, int u_aid, int u_group, int map_fd, struct mmo_account *acc)
{
 if (acc)
 {
  WFIFOHEAD(fd,183);
  WFIFOW(fd,0) = 0x2737;
  (strlib->safestrncpy_((WFIFOP(fd,2)),(acc->userid),((23 + 1))));
  if (u_group >= acc->group_id)
   (strlib->safestrncpy_((WFIFOP(fd,26)),(acc->pass),(33)));
  else
   memset(WFIFOP(fd,26), '\0', 33);
  (strlib->safestrncpy_((WFIFOP(fd,59)),(acc->email),(40)));
  (strlib->safestrncpy_((WFIFOP(fd,99)),(acc->last_ip),(16)));
  WFIFOL(fd,115) = acc->group_id;
  (strlib->safestrncpy_((WFIFOP(fd,119)),(acc->lastlogin),(24)));
  WFIFOL(fd,143) = acc->logincount;
  WFIFOL(fd,147) = acc->state;
  if (u_group >= acc->group_id)
   (strlib->safestrncpy_((WFIFOP(fd,151)),(acc->pincode),(5)));
  else
   memset(WFIFOP(fd,151), '\0', 5);
  (strlib->safestrncpy_((WFIFOP(fd,156)),(acc->birthdate),(11)));
  WFIFOL(fd,167) = map_fd;
  WFIFOL(fd,171) = u_fd;
  WFIFOL(fd,175) = u_aid;
  WFIFOL(fd,179) = account_id;
  WFIFOSET(fd,183);
 }
 else
 {
  WFIFOHEAD(fd,18);
  WFIFOW(fd,0) = 0x2736;
  WFIFOL(fd,2) = map_fd;
  WFIFOL(fd,6) = u_fd;
  WFIFOL(fd,10) = u_aid;
  WFIFOL(fd,14) = account_id;
  WFIFOSET(fd,18);
 }
}

void login_fromchar_parse_accinfo(int fd)
{
 struct mmo_account acc;
 int account_id = RFIFOL(fd, 2), u_fd = RFIFOL(fd, 6), u_aid = RFIFOL(fd, 10), u_group = RFIFOL(fd, 14), map_fd = RFIFOL(fd, 18);
 if (accounts->load_num(accounts, &acc, account_id)) {
  login->fromchar_accinfo(fd, account_id, u_fd, u_aid, u_group, map_fd, &acc);
 } else {
  login->fromchar_accinfo(fd, account_id, u_fd, u_aid, u_group, map_fd, 
# 776 "../../../server-code/src/login/login.c" 3 4
                                                                       ((void *)0)
# 776 "../../../server-code/src/login/login.c"
                                                                           );
 }
 RFIFOSKIP(fd,22);
}




int login_parse_fromchar(int fd)
{
 int id;
 uint32 ipl;
 char ip[16];

 do { for ((id) = (0); (id) < (( (int)(sizeof(server)/sizeof((server)[0])) )); ++(id)) if (server[id].fd == fd) break; } while(
# 790 "../../../server-code/src/login/login.c" 3 4
0
# 790 "../../../server-code/src/login/login.c"
);
 if( id == ( (int)(sizeof(server)/sizeof((server)[0])) ) )
 {
  (showmsg->showDebug(("login_parse_fromchar: Disconnecting invalid session #%d (is not a char-server)\n"), fd));
  sockt->eof(fd);
  sockt->close(fd);
  return 0;
 }

 if( sockt->session[fd]->flag.eof )
 {
  sockt->close(fd);
  server[id].fd = -1;
  chrif_on_disconnect(id);
  return 0;
 }

 ipl = server[id].ip;
 sockt->ip2str(ipl, ip);

 while (RFIFOREST(fd) >= 2) {
  uint16 command = RFIFOW(fd,0);

  if (( (HPM->packets[hpParse_FromChar])._len_ ) > 0) {
   int result = HPM->parse_packets(fd,command,hpParse_FromChar);
   if (result == 1)
    continue;
   if (result == 2)
    return 0;
  }

  switch (command) {

  case 0x2712:
   if( RFIFOREST(fd) < 23 )
    return 0;
  {
   login->fromchar_parse_auth(fd, id, ip);
  }
  break;

  case 0x2714:
   if( RFIFOREST(fd) < 6 )
    return 0;
  {
   login->fromchar_parse_update_users(fd, id);
  }
  break;

  case 0x2715:
   if (RFIFOREST(fd) < 46)
    return 0;
  {
   login->fromchar_parse_request_change_email(fd, id, ip);
  }
  break;

  case 0x2716:
   if( RFIFOREST(fd) < 6 )
    return 0;
  {
   login->fromchar_parse_account_data(fd, id, ip);
  }
  break;

  case 0x2719:
   login->fromchar_parse_ping(fd);
  break;


  case 0x2722:
   if (RFIFOREST(fd) < 86)
    return 0;
  {
   login->fromchar_parse_change_email(fd, id, ip);
  }
  break;

  case 0x2724:
   if (RFIFOREST(fd) < 10)
    return 0;
  {
   login->fromchar_parse_account_update(fd, id, ip);
  }
  break;

  case 0x2725:
   if (RFIFOREST(fd) < 18)
    return 0;
  {
   login->fromchar_parse_ban(fd, id, ip);
  }
  break;

  case 0x2727:
   if( RFIFOREST(fd) < 6 )
    return 0;
  {
   login->fromchar_parse_change_sex(fd, id, ip);
  }
  break;

  case 0x2728:
   if( RFIFOREST(fd) < 4 || RFIFOREST(fd) < RFIFOW(fd,2) )
    return 0;
  {
   login->fromchar_parse_account_reg2(fd, id, ip);
  }
  break;

  case 0x272a:
   if( RFIFOREST(fd) < 6 )
    return 0;
  {
   login->fromchar_parse_unban(fd, id, ip);
  }
  break;

  case 0x272b:
   if( RFIFOREST(fd) < 6 )
    return 0;
   login->fromchar_parse_account_online(fd, id);
  break;

  case 0x272c:
   if( RFIFOREST(fd) < 6 )
    return 0;
   login->fromchar_parse_account_offline(fd);
  break;

  case 0x272d:
   if (RFIFOREST(fd) < 4 || RFIFOREST(fd) < RFIFOW(fd,2))
    return 0;
   {
    login->fromchar_parse_online_accounts(fd, id);
   }
   RFIFOSKIP(fd,RFIFOW(fd,2));
  break;

  case 0x272e:
   if (RFIFOREST(fd) < 10)
    return 0;
  {
   login->fromchar_parse_request_account_reg2(fd);
  }
  break;

  case 0x2736:
   if( RFIFOREST(fd) < 6 )
    return 0;
   login->fromchar_parse_update_wan_ip(fd, id);
  break;

  case 0x2737:
   login->fromchar_parse_all_offline(fd, id);
  break;

  case 0x2738:
   if( RFIFOREST(fd) < 11 )
    return 0;
   else {
    login->fromchar_parse_change_pincode(fd);
   }
   break;

  case 0x2739:
   if( RFIFOREST(fd) < 6 )
    return 0;
   else {
    if (login->fromchar_parse_wrong_pincode(fd))
     return 0;
   }
  break;

  case 0x2740:
   if( RFIFOREST(fd) < 22 )
    return 0;
   else {
    login->fromchar_parse_accinfo(fd);
   }
  break;
  default:
   (showmsg->showError(("login_parse_fromchar: Unknown packet 0x%x from a char-server! Disconnecting!\n"), command));
   sockt->eof(fd);
   return 0;
  }
 }

 return 0;
}





int login_mmo_auth_new(const char* userid, const char* pass, const char sex, const char* last_ip) {
 static int num_regs = 0;
 static int64 new_reg_tick = 0;
 int64 tick = timer->gettick();
 struct mmo_account acc;

 do { if (((void)(userid), 
# 991 "../../../server-code/src/login/login.c" 3 4
0
# 991 "../../../server-code/src/login/login.c"
)) return(3); } while(0);
 do { if (((void)(pass), 
# 992 "../../../server-code/src/login/login.c" 3 4
0
# 992 "../../../server-code/src/login/login.c"
)) return(3); } while(0);
 do { if (((void)(last_ip), 
# 993 "../../../server-code/src/login/login.c" 3 4
0
# 993 "../../../server-code/src/login/login.c"
)) return(3); } while(0);

 if( new_reg_tick == 0 )
  new_reg_tick = timer->gettick();
 if (((tick)-(new_reg_tick)) < 0 && num_regs >= login->config->allowed_regs) {
  (showmsg->showNotice(("Account registration denied (registration limit exceeded)\n")));
  return 3;
 }

 if (login->config->new_acc_length_limit && (strlen(userid) < 4 || strlen(pass) < 4))
  return 1;


 if( sex != 'M' && sex != 'F' )
  return 0;


 if( accounts->load_str(accounts, &acc, userid) ) {
  (showmsg->showNotice(("Attempt of creation of an already existing account (account: %s_%c, pass: %s, received pass: %s)\n"), userid, sex, acc.pass, pass));
  return 1;
 }

 memset(&acc, '\0', sizeof(acc));
 acc.account_id = -1;
 (strlib->safestrncpy_((acc.userid),(userid),(sizeof(acc.userid))));
 (strlib->safestrncpy_((acc.pass),(pass),(sizeof(acc.pass))));
 acc.sex = sex;
 (strlib->safestrncpy_((acc.email),("a@a.com"),(sizeof(acc.email))));
 acc.expiration_time = (login->config->start_limited_time != -1) ? time(
# 1021 "../../../server-code/src/login/login.c" 3 4
                                                                       ((void *)0)
# 1021 "../../../server-code/src/login/login.c"
                                                                           ) + login->config->start_limited_time : 0;
 (strlib->safestrncpy_((acc.lastlogin),("0000-00-00 00:00:00"),(sizeof(acc.lastlogin))));
 (strlib->safestrncpy_((acc.last_ip),(last_ip),(sizeof(acc.last_ip))));
 (strlib->safestrncpy_((acc.birthdate),("0000-00-00"),(sizeof(acc.birthdate))));
 (strlib->safestrncpy_((acc.pincode),("\0"),(sizeof(acc.pincode))));
 acc.pincode_change = 0;
 acc.char_slots = 0;

 if( !accounts->create(accounts, &acc) )
  return 0;

 (showmsg->showNotice(("Account creation (account %s, id: %d, pass: %s, sex: %c)\n"), acc.userid, acc.account_id, acc.pass, acc.sex));

 if( ((tick)-(new_reg_tick)) > 0 ) {
  num_regs = 0;
  new_reg_tick = tick + login->config->time_allowed*1000;
 }
 ++num_regs;

 return -1;
}





int login_mmo_auth(struct login_session_data* sd, 
# 1047 "../../../server-code/src/login/login.c" 3 4
                                                 _Bool 
# 1047 "../../../server-code/src/login/login.c"
                                                      isServer) {
 struct mmo_account acc;
 size_t len;

 char ip[16];
 do { if (((void)(sd), 
# 1052 "../../../server-code/src/login/login.c" 3 4
0
# 1052 "../../../server-code/src/login/login.c"
)) return(0); } while(0);
 sockt->ip2str(sockt->session[sd->fd]->client_addr, ip);


 if (login->config->use_dnsbl) {
  char r_ip[16];
  char ip_dnsbl[256];
  char* dnsbl_serv;
  uint8* sin_addr = (uint8*)&sockt->session[sd->fd]->client_addr;

  sprintf(r_ip, "%u.%u.%u.%u", sin_addr[0], sin_addr[1], sin_addr[2], sin_addr[3]);

  for (dnsbl_serv = strtok(login->config->dnsbl_servs,","); dnsbl_serv != 
# 1064 "../../../server-code/src/login/login.c" 3 4
                                                                         ((void *)0)
# 1064 "../../../server-code/src/login/login.c"
                                                                             ; dnsbl_serv = strtok(
# 1064 "../../../server-code/src/login/login.c" 3 4
                                                                                                   ((void *)0)
# 1064 "../../../server-code/src/login/login.c"
                                                                                                       ,",")) {
   sprintf(ip_dnsbl, "%s.%s", r_ip, (strlib->trim_(dnsbl_serv)));
   if (sockt->host2ip(ip_dnsbl)) {
    (showmsg->showInfo(("DNSBL: (%s) Blacklisted. User Kicked.\n"), r_ip));
    return 3;
   }
  }

 }


 if (login->config->check_client_version && sd->version != login->config->client_version_to_connect)
  return 5;

 len = (strlib->strnlen_((sd->userid),((23 + 1))));


 if (login->config->new_account_flag) {
  if (len > 2 && sd->passwd[0] != '\0' &&
   sd->passwdenc == PWENC_NONE &&
   sd->userid[len-2] == '_' && memchr("FfMm", sd->userid[len-1], 4))
  {
   int result;


   len -= 2;
   sd->userid[len] = '\0';

   result = login->mmo_auth_new(sd->userid, sd->passwd, (toupper((unsigned char)(sd->userid[len+1]))), ip);
   if( result != -1 )
    return result;
  }
 }

 if( len <= 0 ) {
  (showmsg->showNotice(("Empty userid (received pass: '%s', ip: %s)\n"), sd->passwd, ip));
  return 0;
 }

 if( !accounts->load_str(accounts, &acc, sd->userid) ) {
  (showmsg->showNotice(("Unknown account (account: %s, received pass: %s, ip: %s)\n"), sd->userid, sd->passwd, ip));
  return 0;
 }

 if( !login->check_password(sd->md5key, sd->passwdenc, sd->passwd, acc.pass) ) {
  (showmsg->showNotice(("Invalid password (account: '%s', pass: '%s', received pass: '%s', ip: %s)\n"), sd->userid, acc.pass, sd->passwd, ip));
  return 1;
 }

 if( acc.unban_time != 0 && acc.unban_time > time(
# 1113 "../../../server-code/src/login/login.c" 3 4
                                                 ((void *)0)
# 1113 "../../../server-code/src/login/login.c"
                                                     ) ) {
  char tmpstr[24];
  timestamp2string(tmpstr, sizeof(tmpstr), acc.unban_time, login->config->date_format);
  (showmsg->showNotice(("Connection refused (account: %s, pass: %s, banned until %s, ip: %s)\n"), sd->userid, sd->passwd, tmpstr, ip));
  return 6;
 }

 if( acc.state != 0 ) {
  (showmsg->showNotice(("Connection refused (account: %s, pass: %s, state: %u, ip: %s)\n"), sd->userid, sd->passwd, acc.state, ip));
  return acc.state - 1;
 }

 if (login->config->client_hash_check && !isServer) {
  struct client_hash_node *node = 
# 1126 "../../../server-code/src/login/login.c" 3 4
                                 ((void *)0)
# 1126 "../../../server-code/src/login/login.c"
                                     ;
  
# 1127 "../../../server-code/src/login/login.c" 3 4
 _Bool 
# 1127 "../../../server-code/src/login/login.c"
      match = 
# 1127 "../../../server-code/src/login/login.c" 3 4
              0
# 1127 "../../../server-code/src/login/login.c"
                   ;

  for (node = login->config->client_hash_nodes; node; node = node->next) {
   if( acc.group_id < node->group_id )
    continue;
   if( *node->hash == '\0'
    || (sd->has_client_hash && memcmp(node->hash, sd->client_hash, 16) == 0 )
   ) {
    match = 
# 1135 "../../../server-code/src/login/login.c" 3 4
           1
# 1135 "../../../server-code/src/login/login.c"
               ;
    break;
   }
  }

  if( !match ) {
   char smd5[33];
   int i;

   if( !sd->has_client_hash ) {
    (showmsg->showNotice(("Client didn't send client hash (account: %s, pass: %s, ip: %s)\n"), sd->userid, sd->passwd, ip));
    return 5;
   }

   for( i = 0; i < 16; i++ )
    sprintf(&smd5[i * 2], "%02x", sd->client_hash[i]);
   smd5[32] = '\0';

   (showmsg->showNotice(("Invalid client hash (account: %s, pass: %s, sent md5: %s, ip: %s)\n"), sd->userid, sd->passwd, smd5, ip));
   return 5;
  }
 }

 (showmsg->showNotice(("Authentication accepted (account: %s, id: %d, ip: %s)\n"), sd->userid, acc.account_id, ip));


 sd->account_id = acc.account_id;
 sd->login_id1 = rnd() + 1;
 sd->login_id2 = rnd() + 1;
 (strlib->safestrncpy_((sd->lastlogin),(acc.lastlogin),(sizeof(sd->lastlogin))));
 sd->sex = acc.sex;
 sd->group_id = (uint8)acc.group_id;
 sd->expiration_time = acc.expiration_time;


 timestamp2string(acc.lastlogin, sizeof(acc.lastlogin), time(
# 1170 "../../../server-code/src/login/login.c" 3 4
                                                            ((void *)0)
# 1170 "../../../server-code/src/login/login.c"
                                                                ), "%Y-%m-%d %H:%M:%S");
 (strlib->safestrncpy_((acc.last_ip),(ip),(sizeof(acc.last_ip))));
 acc.unban_time = 0;
 acc.logincount++;

 accounts->save(accounts, &acc);

 if( sd->sex != 'S' && sd->account_id < 2000000 )
  (showmsg->showWarning(("Account %s has account id %d! Account IDs must be over %d to work properly!\n"), sd->userid, sd->account_id, 2000000));

 return -1;
}

void login_connection_problem(int fd, uint8 status)
{
 WFIFOHEAD(fd,3);
 WFIFOW(fd,0) = 0x81;
 WFIFOB(fd,2) = status;
 WFIFOSET(fd,3);
}

void login_kick(struct login_session_data* sd)
{
 uint8 buf[6];
 do { if (((void)(sd), 
# 1194 "../../../server-code/src/login/login.c" 3 4
0
# 1194 "../../../server-code/src/login/login.c"
)) return; } while(0);
 WBUFW(buf,0) = 0x2734;
 WBUFL(buf,2) = sd->account_id;
 charif_sendallwos(-1, buf, 6);
}

void login_auth_ok(struct login_session_data* sd)
{
 int fd = 0;
 uint32 ip;
 uint8 server_num, n;
 struct login_auth_node* node;
 int i;

 do { if (((void)(sd), 
# 1208 "../../../server-code/src/login/login.c" 3 4
0
# 1208 "../../../server-code/src/login/login.c"
)) return; } while(0);
 fd = sd->fd;
 ip = sockt->session[fd]->client_addr;
 if( core->runflag != LOGINSERVER_ST_RUNNING )
 {

  login->connection_problem(fd, 1);
  return;
 }

 if (login->config->group_id_to_connect >= 0 && sd->group_id != login->config->group_id_to_connect) {
  (showmsg->showStatus(("Connection refused: the required group id for connection is %d (account: %s, group: %d).\n"), login->config->group_id_to_connect, sd->userid, sd->group_id));
  login->connection_problem(fd, 1);
  return;
 } else if (login->config->min_group_id_to_connect >= 0 && login->config->group_id_to_connect == -1 && sd->group_id < login->config->min_group_id_to_connect) {
  (showmsg->showStatus(("Connection refused: the minimum group id required for connection is %d (account: %s, group: %d).\n"), login->config->min_group_id_to_connect, sd->userid, sd->group_id));
  login->connection_problem(fd, 1);
  return;
 }

 server_num = 0;
 for( i = 0; i < ( (int)(sizeof(server)/sizeof((server)[0])) ); ++i )
  if (sockt->session_is_active(server[i].fd))
   server_num++;

 if( server_num == 0 )
 {
  (showmsg->showStatus(("Connection refused: there is no char-server online (account: %s).\n"), sd->userid));
  login->connection_problem(fd, 1);
  return;
 }

 {
  struct online_login_data* data = (struct online_login_data*)( DB->data2ptr((login->online_db)->get((login->online_db),DB->i2key(sd->account_id))) );
  if( data )
  {
   if( data->char_server > -1 )
   {
    (showmsg->showNotice(("User '%s' is already online - Rejected.\n"), sd->userid));
    login->kick(sd);
    if( data->waiting_disconnect == (-1) )
     data->waiting_disconnect = timer->add(timer->gettick()+30000, login->waiting_disconnect_timer, sd->account_id, 0);

    login->connection_problem(fd, 8);
    return;
   }
   else
   if( data->char_server == -1 )
   {

    ( (login->auth_db)->remove((login->auth_db),DB->i2key(sd->account_id),
# 1258 "../../../server-code/src/login/login.c" 3 4
   ((void *)0)
# 1258 "../../../server-code/src/login/login.c"
   ) );
    login->remove_online_user(sd->account_id);
    data = 
# 1260 "../../../server-code/src/login/login.c" 3 4
          ((void *)0)
# 1260 "../../../server-code/src/login/login.c"
              ;
   }
  }
 }

 login_log(ip, sd->userid, 100, "login ok");
 (showmsg->showStatus(("Connection of the account '%s' accepted.\n"), sd->userid));

 WFIFOHEAD(fd,47+32*server_num);
 WFIFOW(fd,0) = 0x69;
 WFIFOW(fd,2) = 47+32*server_num;
 WFIFOL(fd,4) = sd->login_id1;
 WFIFOL(fd,8) = sd->account_id;
 WFIFOL(fd,12) = sd->login_id2;
 WFIFOL(fd,16) = 0;

 memset(WFIFOP(fd,20), 0, 24);
 WFIFOW(fd,44) = 0;
 WFIFOB(fd,46) = ( ((sd->sex) == 'F') ? SEX_FEMALE : ((sd->sex) == 'M') ? SEX_MALE : SEX_SERVER );
 for (i = 0, n = 0; i < ( (int)(sizeof(server)/sizeof((server)[0])) ); ++i) {
  uint32 subnet_char_ip;

  if (!sockt->session_is_valid(server[i].fd))
   continue;

  subnet_char_ip = login->lan_subnet_check(ip);
  WFIFOL(fd,47+n*32) = htonl((subnet_char_ip) ? subnet_char_ip : server[i].ip);
  WFIFOW(fd,47+n*32+4) = sockt->ntows(htons(server[i].port));
  memcpy(WFIFOP(fd,47+n*32+6), server[i].name, 20);
  WFIFOW(fd,47+n*32+26) = server[i].users;

  if( server[i].type == CST_PAYING && sd->expiration_time > time(
# 1291 "../../../server-code/src/login/login.c" 3 4
                                                                ((void *)0)
# 1291 "../../../server-code/src/login/login.c"
                                                                    ) )
   WFIFOW(fd,47+n*32+28) = CST_NORMAL;
  else
   WFIFOW(fd,47+n*32+28) = server[i].type;

  WFIFOW(fd,47+n*32+30) = server[i].new_;
  n++;
 }
 WFIFOSET(fd,47+32*server_num);


 ((node) = (struct login_auth_node *) (iMalloc->calloc(((1)),(sizeof(struct login_auth_node)),"../../../server-code/src/login/login.c", 1302, __func__)));
 node->account_id = sd->account_id;
 node->login_id1 = sd->login_id1;
 node->login_id2 = sd->login_id2;
 node->sex = sd->sex;
 node->ip = ip;
 node->version = sd->version;
 node->clienttype = sd->clienttype;
 node->group_id = sd->group_id;
 node->expiration_time = sd->expiration_time;
 ( (login->auth_db)->put((login->auth_db),DB->i2key(sd->account_id),DB->ptr2data(node),
# 1312 "../../../server-code/src/login/login.c" 3 4
((void *)0)
# 1312 "../../../server-code/src/login/login.c"
) );

 {
  struct online_login_data* data;


  data = login->add_online_user(-1, sd->account_id);


  data->waiting_disconnect = timer->add(timer->gettick()+30000, login->waiting_disconnect_timer, sd->account_id, 0);
 }
}

void login_auth_failed(struct login_session_data* sd, int result)
{
 int fd;
 uint32 ip;
 do { if (((void)(sd), 
# 1329 "../../../server-code/src/login/login.c" 3 4
0
# 1329 "../../../server-code/src/login/login.c"
)) return; } while(0);

 fd = sd->fd;
 ip = sockt->session[fd]->client_addr;
 if (login->config->log_login) {
  const char* error;
  switch( result ) {
  case 0: error = "Unregistered ID."; break;
  case 1: error = "Incorrect Password."; break;
  case 2: error = "Account Expired."; break;
  case 3: error = "Rejected from server."; break;
  case 4: error = "Blocked by GM."; break;
  case 5: error = "Not latest game EXE."; break;
  case 6: error = "Banned."; break;
  case 7: error = "Server Over-population."; break;
  case 8: error = "Account limit from company"; break;
  case 9: error = "Ban by DBA"; break;
  case 10: error = "Email not confirmed"; break;
  case 11: error = "Ban by GM"; break;
  case 12: error = "Working in DB"; break;
  case 13: error = "Self Lock"; break;
  case 14: error = "Not Permitted Group"; break;
  case 15: error = "Not Permitted Group"; break;
  case 99: error = "Account gone."; break;
  case 100: error = "Login info remains."; break;
  case 101: error = "Hacking investigation."; break;
  case 102: error = "Bug investigation."; break;
  case 103: error = "Deleting char."; break;
  case 104: error = "Deleting spouse char."; break;
  default : error = "Unknown Error."; break;
  }

  login_log(ip, sd->userid, result, error);
 }

 if (result == 1 && login->config->dynamic_pass_failure_ban && !sockt->trusted_ip_check(ip))
  ipban_log(ip);
# 1380 "../../../server-code/src/login/login.c"
 WFIFOHEAD(fd,23);
 WFIFOW(fd,0) = 0x6a;
 WFIFOB(fd,2) = (uint8)result;
 if( result != 6 )
  memset(WFIFOP(fd,3), '\0', 20);
 else {
  struct mmo_account acc;
  time_t unban_time = ( accounts->load_str(accounts, &acc, sd->userid) ) ? acc.unban_time : 0;
  timestamp2string(WFIFOP(fd,3), 20, unban_time, login->config->date_format);
 }
 WFIFOSET(fd,23);

}

void login_login_error(int fd, uint8 status)
{
 WFIFOHEAD(fd,23);
 WFIFOW(fd,0) = 0x6a;
 WFIFOB(fd,2) = status;
 WFIFOSET(fd,23);
}

void login_parse_ping(int fd, struct login_session_data* sd) __attribute__((nonnull (2)));
void login_parse_ping(int fd, struct login_session_data* sd)
{
 RFIFOSKIP(fd,26);
}

void login_parse_client_md5(int fd, struct login_session_data* sd) __attribute__((nonnull (2)));
void login_parse_client_md5(int fd, struct login_session_data* sd)
{
 sd->has_client_hash = 1;
 memcpy(sd->client_hash, RFIFOP(fd, 2), 16);

 RFIFOSKIP(fd,18);
}


# 1417 "../../../server-code/src/login/login.c" 3 4
_Bool 
# 1417 "../../../server-code/src/login/login.c"
    login_parse_client_login(int fd, struct login_session_data* sd, const char *const ip) __attribute__((nonnull (2)));

# 1418 "../../../server-code/src/login/login.c" 3 4
_Bool 
# 1418 "../../../server-code/src/login/login.c"
    login_parse_client_login(int fd, struct login_session_data* sd, const char *const ip)
{
 uint32 version;
 char username[(23 + 1)];
 char password[(32+1)];
 unsigned char passhash[16];
 uint8 clienttype;
 int result;
 uint16 command = RFIFOW(fd,0);
 
# 1427 "../../../server-code/src/login/login.c" 3 4
_Bool 
# 1427 "../../../server-code/src/login/login.c"
     israwpass = (command==0x0064 || command==0x0277 || command==0x02b0 || command == 0x0825);


 if(command == 0x0825)
 {
  const char *accname = RFIFOP(fd, 9);
  const char *token = RFIFOP(fd, 0x5C);
  size_t uAccLen = strlen(accname);
  size_t uTokenLen = RFIFOREST(fd) - 0x5C;

  version = RFIFOL(fd,4);

  if(uAccLen <= 0 || uTokenLen <= 0) {
   login->auth_failed(sd, 3);
   return 
# 1441 "../../../server-code/src/login/login.c" 3 4
         1
# 1441 "../../../server-code/src/login/login.c"
             ;
  }

  (strlib->safestrncpy_((username),(accname),((23 + 1))));
  (strlib->safestrncpy_((password),(token),((((uTokenLen+1) < ((32+1))) ? (uTokenLen+1) : ((32+1))))));
  clienttype = RFIFOB(fd, 8);
 }
 else
 {
  version = RFIFOL(fd,2);
  (strlib->safestrncpy_((username),(RFIFOP(fd,6)),((23 + 1))));
  if( israwpass )
  {
   (strlib->safestrncpy_((password),(RFIFOP(fd,30)),((23 + 1))));
   clienttype = RFIFOB(fd,54);
  }
  else
  {
   memcpy(passhash, RFIFOP(fd,30), 16);
   clienttype = RFIFOB(fd,46);
  }
 }
 RFIFOSKIP(fd,RFIFOREST(fd));

 sd->clienttype = clienttype;
 sd->version = version;
 (strlib->safestrncpy_((sd->userid),(username),((23 + 1))));
 if( israwpass )
 {
  (showmsg->showStatus(("Request for connection of %s (ip: %s).\n"), sd->userid, ip));
  (strlib->safestrncpy_((sd->passwd),(password),((32+1))));
  if (login->config->use_md5_passwds)
   MD5_String(sd->passwd, sd->passwd);
  sd->passwdenc = PWENC_NONE;
 }
 else
 {
  (showmsg->showStatus(("Request for connection (passwdenc mode) of %s (ip: %s).\n"), sd->userid, ip));
  (strlib->bin2hex_((sd->passwd),(passhash),(16)));
  sd->passwdenc = PWENC_BOTH;
 }

 if (sd->passwdenc != PWENC_NONE && login->config->use_md5_passwds) {
  login->auth_failed(sd, 3);
  return 
# 1485 "../../../server-code/src/login/login.c" 3 4
        1
# 1485 "../../../server-code/src/login/login.c"
            ;
 }

 result = login->mmo_auth(sd, 
# 1488 "../../../server-code/src/login/login.c" 3 4
                             0
# 1488 "../../../server-code/src/login/login.c"
                                  );

 if( result == -1 )
  login->auth_ok(sd);
 else
  login->auth_failed(sd, result);
 return 
# 1494 "../../../server-code/src/login/login.c" 3 4
       0
# 1494 "../../../server-code/src/login/login.c"
            ;
}

void login_send_coding_key(int fd, struct login_session_data* sd) __attribute__((nonnull (2)));
void login_send_coding_key(int fd, struct login_session_data* sd)
{
 WFIFOHEAD(fd,4 + sd->md5keylen);
 WFIFOW(fd,0) = 0x01dc;
 WFIFOW(fd,2) = 4 + sd->md5keylen;
 memcpy(WFIFOP(fd,4), sd->md5key, sd->md5keylen);
 WFIFOSET(fd,WFIFOW(fd,2));
}

void login_parse_request_coding_key(int fd, struct login_session_data* sd) __attribute__((nonnull (2)));
void login_parse_request_coding_key(int fd, struct login_session_data* sd)
{
 memset(sd->md5key, '\0', sizeof(sd->md5key));
 sd->md5keylen = (uint16)(12 + rnd() % 4);
 MD5_Salt(sd->md5keylen, sd->md5key);

 login->send_coding_key(fd, sd);
}

void login_char_server_connection_status(int fd, struct login_session_data* sd, uint8 status) __attribute__((nonnull (2)));
void login_char_server_connection_status(int fd, struct login_session_data* sd, uint8 status)
{
 WFIFOHEAD(fd,3);
 WFIFOW(fd,0) = 0x2711;
 WFIFOB(fd,2) = status;
 WFIFOSET(fd,3);
}

void login_parse_request_connection(int fd, struct login_session_data* sd, const char *const ip, uint32 ipl) __attribute__((nonnull (2, 3)));
void login_parse_request_connection(int fd, struct login_session_data* sd, const char *const ip, uint32 ipl)
{
 char server_name[20];
 char message[256];
 uint32 server_ip;
 uint16 server_port;
 uint16 type;
 uint16 new_;
 int result;

 (strlib->safestrncpy_((sd->userid),(RFIFOP(fd,2)),((23 + 1))));
 (strlib->safestrncpy_((sd->passwd),(RFIFOP(fd,26)),((23 + 1))));
 if (login->config->use_md5_passwds)
  MD5_String(sd->passwd, sd->passwd);
 sd->passwdenc = PWENC_NONE;
 sd->version = login->config->client_version_to_connect;
 server_ip = ntohl(RFIFOL(fd,54));
 server_port = ntohs(RFIFOW(fd,58));
 (strlib->safestrncpy_((server_name),(RFIFOP(fd,60)),(20)));
 type = RFIFOW(fd,82);
 new_ = RFIFOW(fd,84);
 RFIFOSKIP(fd,86);

 (showmsg->showInfo(("Connection request of the char-server '%s' @ %u.%u.%u.%u:%u (account: '%s', pass: '%s', ip: '%s')\n"), server_name, CONVIP(server_ip), server_port, sd->userid, sd->passwd, ip));
 sprintf(message, "charserver - %s@%u.%u.%u.%u:%u", server_name, CONVIP(server_ip), server_port);
 login_log(sockt->session[fd]->client_addr, sd->userid, 100, message);

 result = login->mmo_auth(sd, 
# 1554 "../../../server-code/src/login/login.c" 3 4
                             1
# 1554 "../../../server-code/src/login/login.c"
                                 );
 if (core->runflag == LOGINSERVER_ST_RUNNING &&
  result == -1 &&
  sd->sex == 'S' &&
  sd->account_id >= 0 &&
  sd->account_id < ( (int)(sizeof(server)/sizeof((server)[0])) ) &&
  !sockt->session_is_valid(server[sd->account_id].fd) &&
  sockt->allowed_ip_check(ipl))
 {
  (showmsg->showStatus(("Connection of the char-server '%s' accepted.\n"), server_name));
  (strlib->safestrncpy_((server[sd->account_id].name),(server_name),(sizeof(server[sd->account_id].name))));
  server[sd->account_id].fd = fd;
  server[sd->account_id].ip = server_ip;
  server[sd->account_id].port = server_port;
  server[sd->account_id].users = 0;
  server[sd->account_id].type = type;
  server[sd->account_id].new_ = new_;

  sockt->session[fd]->func_parse = login->parse_fromchar;
  sockt->session[fd]->flag.server = 1;
  sockt->realloc_fifo(fd, FIFOSIZE_SERVERLINK, FIFOSIZE_SERVERLINK);


  login->char_server_connection_status(fd, sd, 0);
 }
 else
 {
  (showmsg->showNotice(("Connection of the char-server '%s' REFUSED.\n"), server_name));
  login->char_server_connection_status(fd, sd, 3);
 }
}




int login_parse_login(int fd)
{
 struct login_session_data* sd = (struct login_session_data*)sockt->session[fd]->session_data;

 char ip[16];
 uint32 ipl = sockt->session[fd]->client_addr;
 sockt->ip2str(ipl, ip);

 if( sockt->session[fd]->flag.eof )
 {
  (showmsg->showInfo(("Closed connection from '""\033[1;37m""%s""\033[0m""'.\n"), ip));
  sockt->close(fd);
  return 0;
 }

 if( sd == 
# 1604 "../../../server-code/src/login/login.c" 3 4
          ((void *)0) 
# 1604 "../../../server-code/src/login/login.c"
               )
 {

  if (login->config->ipban && !sockt->trusted_ip_check(ipl) && ipban_check(ipl)) {
   (showmsg->showStatus(("Connection refused: IP isn't authorized (deny/allow, ip: %s).\n"), ip));
   login_log(ipl, "unknown", -3, "ip banned");
   login->login_error(fd, 3);
   sockt->eof(fd);
   return 0;
  }


  ((sockt->session[fd]->session_data) = (struct login_session_data *) (iMalloc->calloc(((1)),(sizeof(struct login_session_data)),"../../../server-code/src/login/login.c", 1616, __func__)));
  sd = (struct login_session_data*)sockt->session[fd]->session_data;
  sd->fd = fd;
 }

 while (RFIFOREST(fd) >= 2) {
  uint16 command = RFIFOW(fd,0);

  if (( (HPM->packets[hpParse_Login])._len_ ) > 0) {
   int result = HPM->parse_packets(fd,command,hpParse_Login);
   if (result == 1)
    continue;
   if (result == 2)
    return 0;
  }

  switch (command) {

  case 0x0200:
   if (RFIFOREST(fd) < 26)
    return 0;
   login->parse_ping(fd, sd);
  break;


  case 0x0204:
   if (RFIFOREST(fd) < 18)
    return 0;

   login->parse_client_md5(fd, sd);
  break;


  case 0x0064:
  case 0x0277:
  case 0x02b0:

  case 0x01dd:
  case 0x01fa:
  case 0x027c:
  case 0x0825:
  {
   size_t packet_len = RFIFOREST(fd);

   if( (command == 0x0064 && packet_len < 55)
   || (command == 0x0277 && packet_len < 84)
   || (command == 0x02b0 && packet_len < 85)
   || (command == 0x01dd && packet_len < 47)
   || (command == 0x01fa && packet_len < 48)
   || (command == 0x027c && packet_len < 60)
   || (command == 0x0825 && (packet_len < 4 || packet_len < RFIFOW(fd, 2))) )
    return 0;
  }
  {
   if (login->parse_client_login(fd, sd, ip))
    return 0;
  }
  break;

  case 0x01db:
   RFIFOSKIP(fd,2);
  {
   login->parse_request_coding_key(fd, sd);
  }
  break;

  case 0x2710:
   if (RFIFOREST(fd) < 86)
    return 0;
  {
   login->parse_request_connection(fd, sd, ip, ipl);
  }
  return 0;

  default:
   (showmsg->showNotice(("Abnormal end of connection (ip: %s): Unknown packet 0x%x\n"), ip, command));
   sockt->eof(fd);
   return 0;
  }
 }

 return 0;
}


void login_config_set_defaults(void)
{
 login->config->login_ip = INADDR_ANY;
 login->config->login_port = 6900;
 login->config->ipban_cleanup_interval = 60;
 login->config->ip_sync_interval = 0;
 login->config->log_login = 
# 1707 "../../../server-code/src/login/login.c" 3 4
                           1
# 1707 "../../../server-code/src/login/login.c"
                               ;
 (strlib->safestrncpy_((login->config->date_format),("%Y-%m-%d %H:%M:%S"),(sizeof(login->config->date_format))));
 login->config->new_account_flag = 
# 1709 "../../../server-code/src/login/login.c" 3 4
                                  1
# 1709 "../../../server-code/src/login/login.c"
                                      ;
 login->config->new_acc_length_limit = 
# 1710 "../../../server-code/src/login/login.c" 3 4
                                      1
# 1710 "../../../server-code/src/login/login.c"
                                          ;
 login->config->use_md5_passwds = 
# 1711 "../../../server-code/src/login/login.c" 3 4
                                 0
# 1711 "../../../server-code/src/login/login.c"
                                      ;
 login->config->group_id_to_connect = -1;
 login->config->min_group_id_to_connect = -1;
 login->config->check_client_version = 
# 1714 "../../../server-code/src/login/login.c" 3 4
                                      0
# 1714 "../../../server-code/src/login/login.c"
                                           ;
 login->config->client_version_to_connect = 20;
 login->config->allowed_regs = 1;
 login->config->time_allowed = 10;

 login->config->ipban = 
# 1719 "../../../server-code/src/login/login.c" 3 4
                       1
# 1719 "../../../server-code/src/login/login.c"
                           ;
 login->config->dynamic_pass_failure_ban = 
# 1720 "../../../server-code/src/login/login.c" 3 4
                                          1
# 1720 "../../../server-code/src/login/login.c"
                                              ;
 login->config->dynamic_pass_failure_ban_interval = 5;
 login->config->dynamic_pass_failure_ban_limit = 7;
 login->config->dynamic_pass_failure_ban_duration = 5;
 login->config->use_dnsbl = 
# 1724 "../../../server-code/src/login/login.c" 3 4
                           0
# 1724 "../../../server-code/src/login/login.c"
                                ;
 (strlib->safestrncpy_((login->config->dnsbl_servs),(""),(sizeof(login->config->dnsbl_servs))));

 login->config->client_hash_check = 0;
 login->config->client_hash_nodes = 
# 1728 "../../../server-code/src/login/login.c" 3 4
                                   ((void *)0)
# 1728 "../../../server-code/src/login/login.c"
                                       ;
}




int login_config_read(const char *cfgName)
{
 char line[1024], w1[1024], w2[1024];
 FILE* fp;
 do { if (((void)(cfgName), 
# 1738 "../../../server-code/src/login/login.c" 3 4
0
# 1738 "../../../server-code/src/login/login.c"
)) return(1); } while(0);
 fp = fopen(cfgName, "r");
 if (fp == 
# 1740 "../../../server-code/src/login/login.c" 3 4
          ((void *)0)
# 1740 "../../../server-code/src/login/login.c"
              ) {
  (showmsg->showError(("Configuration file (%s) not found.\n"), cfgName));
  return 1;
 }
 while(fgets(line, sizeof(line), fp)) {
  if (line[0] == '/' && line[1] == '/')
   continue;

  if (sscanf(line, "%1023[^:]: %1023[^\r\n]", w1, w2) < 2)
   continue;

  if(!strcasecmp(w1,"timestamp_format"))
   (strlib->safestrncpy_((showmsg->timestamp_format),(w2),(20)));
  else if(!strcasecmp(w1,"stdout_with_ansisequence"))
   showmsg->stdout_with_ansisequence = (strlib->config_switch_(w2)) ? 
# 1754 "../../../server-code/src/login/login.c" 3 4
                                                          1 
# 1754 "../../../server-code/src/login/login.c"
                                                               : 
# 1754 "../../../server-code/src/login/login.c" 3 4
                                                                 0
# 1754 "../../../server-code/src/login/login.c"
                                                                      ;
  else if(!strcasecmp(w1,"console_silent")) {
   showmsg->silent = atoi(w2);
   if (showmsg->silent)
    (showmsg->showInfo(("Console Silent Setting: %d\n"), atoi(w2)));
  }
  else if( !strcasecmp(w1, "bind_ip") ) {
   login->config->login_ip = sockt->host2ip(w2);
   if (login->config->login_ip) {
    char ip_str[16];
    (showmsg->showStatus(("Login server binding IP address : %s -> %s\n"), w2, sockt->ip2str(login->config->login_ip, ip_str)));
   }
  }
  else if( !strcasecmp(w1, "login_port") ) {
   login->config->login_port = (uint16)atoi(w2);
  }
  else if(!strcasecmp(w1, "log_login"))
   login->config->log_login = (
# 1771 "../../../server-code/src/login/login.c" 3 4
                              _Bool
# 1771 "../../../server-code/src/login/login.c"
                                  )(strlib->config_switch_(w2));

  else if(!strcasecmp(w1, "new_account"))
   login->config->new_account_flag = (
# 1774 "../../../server-code/src/login/login.c" 3 4
                                     _Bool
# 1774 "../../../server-code/src/login/login.c"
                                         )(strlib->config_switch_(w2));
  else if(!strcasecmp(w1, "new_acc_length_limit"))
   login->config->new_acc_length_limit = (
# 1776 "../../../server-code/src/login/login.c" 3 4
                                         _Bool
# 1776 "../../../server-code/src/login/login.c"
                                             )(strlib->config_switch_(w2));
  else if(!strcasecmp(w1, "start_limited_time"))
   login->config->start_limited_time = atoi(w2);
  else if(!strcasecmp(w1, "check_client_version"))
   login->config->check_client_version = (
# 1780 "../../../server-code/src/login/login.c" 3 4
                                         _Bool
# 1780 "../../../server-code/src/login/login.c"
                                             )(strlib->config_switch_(w2));
  else if(!strcasecmp(w1, "client_version_to_connect"))
   login->config->client_version_to_connect = (unsigned int)strtoul(w2, 
# 1782 "../../../server-code/src/login/login.c" 3 4
                                                                       ((void *)0)
# 1782 "../../../server-code/src/login/login.c"
                                                                           , 10);
  else if(!strcasecmp(w1, "use_MD5_passwords"))
   login->config->use_md5_passwds = (
# 1784 "../../../server-code/src/login/login.c" 3 4
                                    _Bool
# 1784 "../../../server-code/src/login/login.c"
                                        )(strlib->config_switch_(w2));
  else if(!strcasecmp(w1, "group_id_to_connect"))
   login->config->group_id_to_connect = atoi(w2);
  else if(!strcasecmp(w1, "min_group_id_to_connect"))
   login->config->min_group_id_to_connect = atoi(w2);
  else if(!strcasecmp(w1, "date_format"))
   (strlib->safestrncpy_((login->config->date_format),(w2),(sizeof(login->config->date_format))));
  else if(!strcasecmp(w1, "allowed_regs"))
   login->config->allowed_regs = atoi(w2);
  else if(!strcasecmp(w1, "time_allowed"))
   login->config->time_allowed = atoi(w2);
  else if(!strcasecmp(w1, "use_dnsbl"))
   login->config->use_dnsbl = (
# 1796 "../../../server-code/src/login/login.c" 3 4
                              _Bool
# 1796 "../../../server-code/src/login/login.c"
                                  )(strlib->config_switch_(w2));
  else if(!strcasecmp(w1, "dnsbl_servers"))
   (strlib->safestrncpy_((login->config->dnsbl_servs),(w2),(sizeof(login->config->dnsbl_servs))));
  else if(!strcasecmp(w1, "ipban_cleanup_interval"))
   login->config->ipban_cleanup_interval = (unsigned int)atoi(w2);
  else if(!strcasecmp(w1, "ip_sync_interval"))
   login->config->ip_sync_interval = (unsigned int)1000*60*atoi(w2);
  else if(!strcasecmp(w1, "client_hash_check"))
   login->config->client_hash_check = (strlib->config_switch_(w2));
  else if(!strcasecmp(w1, "client_hash")) {
   int group = 0;
   char md5[33];
   memset(md5, '\0', 33);

   if (sscanf(w2, "%d, %32s", &group, md5) == 2) {
    struct client_hash_node *nnode;
    ((nnode) = (struct client_hash_node *) (iMalloc->calloc(((1)),(sizeof(struct client_hash_node)),"../../../server-code/src/login/login.c", 1812, __func__)));

    if (strcasecmp(md5, "disabled") == 0) {
     nnode->hash[0] = '\0';
    } else {
     int i;
     for (i = 0; i < 32; i += 2) {
      char buf[3];
      unsigned int byte;

      memcpy(buf, &md5[i], 2);
      buf[2] = 0;

      sscanf(buf, "%x", &byte);
      nnode->hash[i / 2] = (uint8)(byte & 0xFF);
     }
    }

    nnode->group_id = group;
    nnode->next = login->config->client_hash_nodes;

    login->config->client_hash_nodes = nnode;
   }
  }
  else if(!strcasecmp(w1, "import"))
   login_config_read(w2);
  else
  {
   AccountDB* db = account_engine[0].db;
   if (db)
    db->set_property(db, w1, w2);
   ipban_config_read(w1, w2);
   loginlog_config_read(w1, w2);
   HPM->parseConf(w1, w2, HPCT_LOGIN);
  }
 }
 fclose(fp);
 (showmsg->showInfo(("Finished reading %s.\n"), cfgName));
 return 0;
}




int do_final(void) {
 int i;
 struct client_hash_node *hn = login->config->client_hash_nodes;

 (showmsg->showStatus(("Terminating...\n")));

 HPM->event(HPET_FINAL);

 while (hn) {
  struct client_hash_node *tmp = hn;
  hn = hn->next;
  (iMalloc->free((tmp),"../../../server-code/src/login/login.c", 1867, __func__));
 }

 login_log(0, "login server", 100, "login server shutdown");

 if (login->config->log_login)
  loginlog_final();

 ipban_final();

 if( account_engine[0].db )
 {
  account_engine[0].db->destroy(account_engine[0].db);
  account_engine[0].db = 
# 1880 "../../../server-code/src/login/login.c" 3 4
                        ((void *)0)
# 1880 "../../../server-code/src/login/login.c"
                            ;
 }
 accounts = 
# 1882 "../../../server-code/src/login/login.c" 3 4
           ((void *)0)
# 1882 "../../../server-code/src/login/login.c"
               ;
 login->online_db->destroy(login->online_db, 
# 1883 "../../../server-code/src/login/login.c" 3 4
                                            ((void *)0)
# 1883 "../../../server-code/src/login/login.c"
                                                );
 login->auth_db->destroy(login->auth_db, 
# 1884 "../../../server-code/src/login/login.c" 3 4
                                        ((void *)0)
# 1884 "../../../server-code/src/login/login.c"
                                            );

 for( i = 0; i < ( (int)(sizeof(server)/sizeof((server)[0])) ); ++i )
  chrif_server_destroy(i);

 if( login->fd != -1 )
 {
  sockt->close(login->fd);
  login->fd = -1;
 }

 HPM_login_do_final();

 (iMalloc->free((login->LOGIN_CONF_NAME),"../../../server-code/src/login/login.c", 1897, __func__));
 (iMalloc->free((login->NET_CONF_NAME),"../../../server-code/src/login/login.c", 1898, __func__));

 HPM->event(HPET_POST_FINAL);

 (showmsg->showStatus(("Finished.\n")));
 return 
# 1903 "../../../server-code/src/login/login.c" 3 4
       0
# 1903 "../../../server-code/src/login/login.c"
                   ;
}





void do_abort(void)
{
}

void set_server_type(void) {
 (core->server_type) = SERVER_TYPE_LOGIN;
}



void do_shutdown_login(void)
{
 if( core->runflag != LOGINSERVER_ST_SHUTDOWN )
 {
  int id;
  core->runflag = LOGINSERVER_ST_SHUTDOWN;
  (showmsg->showStatus(("Shutting down...\n")));

  for( id = 0; id < ( (int)(sizeof(server)/sizeof((server)[0])) ); ++id )
   chrif_server_reset(id);
  sockt->flush_fifos();
  core->runflag = CORE_ST_STOP;
 }
}







static 
# 1941 "../../../server-code/src/login/login.c" 3 4
      _Bool 
# 1941 "../../../server-code/src/login/login.c"
      cmdline_arg_loginconfig (const char *name, const char *params)
{
 (iMalloc->free((login->LOGIN_CONF_NAME),"../../../server-code/src/login/login.c", 1943, __func__));
 login->LOGIN_CONF_NAME = (iMalloc->astrdup((params),"../../../server-code/src/login/login.c", 1944, __func__));
 return 
# 1945 "../../../server-code/src/login/login.c" 3 4
       1
# 1945 "../../../server-code/src/login/login.c"
           ;
}






static 
# 1953 "../../../server-code/src/login/login.c" 3 4
      _Bool 
# 1953 "../../../server-code/src/login/login.c"
      cmdline_arg_netconfig (const char *name, const char *params)
{
 (iMalloc->free((login->NET_CONF_NAME),"../../../server-code/src/login/login.c", 1955, __func__));
 login->NET_CONF_NAME = (iMalloc->astrdup((params),"../../../server-code/src/login/login.c", 1956, __func__));
 return 
# 1957 "../../../server-code/src/login/login.c" 3 4
       1
# 1957 "../../../server-code/src/login/login.c"
           ;
}



void cmdline_args_init_local(void)
{
 cmdline->arg_add(((unsigned int)-1), "--" "login-config", '\0', cmdline_arg_loginconfig, "Alternative login-server configuration.", CMDLINE_OPT_PARAM);
 cmdline->arg_add(((unsigned int)-1), "--" "net-config", '\0', cmdline_arg_netconfig, "Alternative subnet configuration.", CMDLINE_OPT_PARAM);
}




int do_init(int argc, char** argv)
{
 int i;


 account_engine[0].db = account_engine[0].constructor();
 accounts = account_engine[0].db;
 if( accounts == 
# 1978 "../../../server-code/src/login/login.c" 3 4
                ((void *)0) 
# 1978 "../../../server-code/src/login/login.c"
                     ) {
  (showmsg->showFatalError(("do_init: account engine 'sql' not found.\n")));
  exit(
# 1980 "../../../server-code/src/login/login.c" 3 4
      1
# 1980 "../../../server-code/src/login/login.c"
                  );
 }

 login_defaults();


 login->config_set_defaults();

 login->LOGIN_CONF_NAME = (iMalloc->astrdup(("conf/login-server.conf"),"../../../server-code/src/login/login.c", 1988, __func__));
 login->NET_CONF_NAME = (iMalloc->astrdup(("conf/network.conf"),"../../../server-code/src/login/login.c", 1989, __func__));

 HPM_login_do_init();
 cmdline->exec(argc, argv, CMDLINE_OPT_PREINIT);
 HPM->config_read();
 HPM->event(HPET_PRE_INIT);

 cmdline->exec(argc, argv, CMDLINE_OPT_NORMAL);
 login_config_read(login->LOGIN_CONF_NAME);
 sockt->net_config_read(login->NET_CONF_NAME);

 for( i = 0; i < ( (int)(sizeof(server)/sizeof((server)[0])) ); ++i )
  chrif_server_init(i);


 if (login->config->log_login)
  loginlog_init();


 ipban_init();


 login->online_db = DB->alloc("../../../server-code/src/login/login.c",__func__,2011,DB_INT,(DB_OPT_RELEASE_DATA),sizeof(int));
 timer->add_func_list(login->waiting_disconnect_timer, "login->waiting_disconnect_timer");


 login->auth_db = DB->alloc("../../../server-code/src/login/login.c",__func__,2015,DB_INT,(DB_OPT_RELEASE_DATA),sizeof(int));


 sockt->set_defaultparse(login->parse_login);


 timer->add_func_list(login->online_data_cleanup, "login->online_data_cleanup");
 timer->add_interval(timer->gettick() + 600*1000, login->online_data_cleanup, 0, 0, 600*1000);


 if (login->config->ip_sync_interval) {
  timer->add_func_list(login->sync_ip_addresses, "login->sync_ip_addresses");
  timer->add_interval(timer->gettick() + login->config->ip_sync_interval, login->sync_ip_addresses, 0, 0, login->config->ip_sync_interval);
 }


 if(!accounts->init(accounts)) {
  (showmsg->showFatalError(("do_init: Failed to initialize account engine 'sql'.\n")));
  exit(
# 2033 "../../../server-code/src/login/login.c" 3 4
      1
# 2033 "../../../server-code/src/login/login.c"
                  );
 }

 HPM->event(HPET_INIT);


 if ((login->fd = sockt->make_listen_bind(login->config->login_ip,login->config->login_port)) == -1) {
  (showmsg->showFatalError(("Failed to bind to port '""\033[1;37m""%d""\033[0m""'\n"),login->config->login_port));
  exit(
# 2041 "../../../server-code/src/login/login.c" 3 4
      1
# 2041 "../../../server-code/src/login/login.c"
                  );
 }

 if( core->runflag != CORE_ST_STOP ) {
  core->shutdown_callback = do_shutdown_login;
  core->runflag = LOGINSERVER_ST_RUNNING;
 }


 console->display_gplnotice();


 (showmsg->showStatus(("The login-server is ""\033[1;32m""ready""\033[0m"" (Server is listening on the port %u).\n\n"), login->config->login_port));
 login_log(0, "login server", 100, "login server started");

 HPM->event(HPET_READY);

 return 0;
}

void login_defaults(void) {
 login = &login_s;

 login->config = &login_config_;
 login->accounts = accounts;

 login->mmo_auth = login_mmo_auth;
 login->mmo_auth_new = login_mmo_auth_new;
 login->waiting_disconnect_timer = login_waiting_disconnect_timer;
 login->create_online_user = login_create_online_user;
 login->add_online_user = login_add_online_user;
 login->remove_online_user = login_remove_online_user;
 login->online_db_setoffline = login_online_db_setoffline;
 login->online_data_cleanup_sub = login_online_data_cleanup_sub;
 login->online_data_cleanup = login_online_data_cleanup;
 login->sync_ip_addresses = login_sync_ip_addresses;
 login->check_encrypted = login_check_encrypted;
 login->check_password = login_check_password;
 login->lan_subnet_check = login_lan_subnet_check;

 login->fromchar_auth_ack = login_fromchar_auth_ack;
 login->fromchar_accinfo = login_fromchar_accinfo;
 login->fromchar_account = login_fromchar_account;
 login->fromchar_account_update_other = login_fromchar_account_update_other;
 login->fromchar_ban = login_fromchar_ban;
 login->fromchar_change_sex_other = login_fromchar_change_sex_other;
 login->fromchar_pong = login_fromchar_pong;
 login->fromchar_parse_auth = login_fromchar_parse_auth;
 login->fromchar_parse_update_users = login_fromchar_parse_update_users;
 login->fromchar_parse_request_change_email = login_fromchar_parse_request_change_email;
 login->fromchar_parse_account_data = login_fromchar_parse_account_data;
 login->fromchar_parse_ping = login_fromchar_parse_ping;
 login->fromchar_parse_change_email = login_fromchar_parse_change_email;
 login->fromchar_parse_account_update = login_fromchar_parse_account_update;
 login->fromchar_parse_ban = login_fromchar_parse_ban;
 login->fromchar_parse_change_sex = login_fromchar_parse_change_sex;
 login->fromchar_parse_account_reg2 = login_fromchar_parse_account_reg2;
 login->fromchar_parse_unban = login_fromchar_parse_unban;
 login->fromchar_parse_account_online = login_fromchar_parse_account_online;
 login->fromchar_parse_account_offline = login_fromchar_parse_account_offline;
 login->fromchar_parse_online_accounts = login_fromchar_parse_online_accounts;
 login->fromchar_parse_request_account_reg2 = login_fromchar_parse_request_account_reg2;
 login->fromchar_parse_update_wan_ip = login_fromchar_parse_update_wan_ip;
 login->fromchar_parse_all_offline = login_fromchar_parse_all_offline;
 login->fromchar_parse_change_pincode = login_fromchar_parse_change_pincode;
 login->fromchar_parse_wrong_pincode = login_fromchar_parse_wrong_pincode;
 login->fromchar_parse_accinfo = login_fromchar_parse_accinfo;

 login->parse_fromchar = login_parse_fromchar;
 login->parse_login = login_parse_login;
 login->parse_ping = login_parse_ping;
 login->parse_client_md5 = login_parse_client_md5;
 login->parse_client_login = login_parse_client_login;
 login->parse_request_coding_key = login_parse_request_coding_key;
 login->parse_request_connection = login_parse_request_connection;
 login->auth_ok = login_auth_ok;
 login->auth_failed = login_auth_failed;
 login->char_server_connection_status = login_char_server_connection_status;
 login->connection_problem = login_connection_problem;
 login->kick = login_kick;
 login->login_error = login_login_error;
 login->send_coding_key = login_send_coding_key;

 login->config_set_defaults = login_config_set_defaults;
 login->config_read = login_config_read;
 login->LOGIN_CONF_NAME = 
# 2126 "../../../server-code/src/login/login.c" 3 4
                         ((void *)0)
# 2126 "../../../server-code/src/login/login.c"
                             ;
 login->NET_CONF_NAME = 
# 2127 "../../../server-code/src/login/login.c" 3 4
                       ((void *)0)
# 2127 "../../../server-code/src/login/login.c"
                           ;
}
