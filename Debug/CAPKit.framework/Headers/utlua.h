#include <lua53/lua.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <math.h>
#include <memory.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/stat.h>

#include <sys/queue.h>
#ifndef utlua_h
#define utlua_h


#if !defined(__cplusplus)
#include <stdbool.h>
#endif

#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>

#include <event.h>
#include <event2/bufferevent.h>
#include <event2/dns.h>
#include <event2/event.h>
#include <event2/listener.h>
#include <evhttp.h>

#if FAN_HAS_OPENSSL
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/pkcs12.h>
#include <openssl/rand.h>
#include <openssl/ssl.h>

#include "openssl_hostname_validation.h"
#include <event2/bufferevent_ssl.h>
#endif

#include "bytearray.h"

#define READ_BUFF_LEN 1024 * 1024

#ifdef __ANDROID__
#include <android/log.h>
#define LOG_TAG "luafan.log"
#undef LOG
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#else

#define LOGD(...)                                                              \
fprintf(stdout, __VA_ARGS__);                                                \
fflush(stdout);
#define LOGE(...)                                                              \
fprintf(stderr, __VA_ARGS__);                                                \
fflush(stderr);

#endif

#define PUSH_REF(L)                                                         \
lua_lock(L);                                                                \
incrRef(L);                                                                 \
int _ref_ = luaL_ref(L, LUA_REGISTRYINDEX);                                 \
lua_unlock(L);

#define POP_REF(L)                                                          \
lua_lock(L);                                                                \
luaL_unref(L, LUA_REGISTRYINDEX, _ref_);                                    \
lua_unlock(L);                                                              \
decrRef(L);

#define SET_FUNC_REF_FROM_TABLE(L, REF, IDX, KEY)     \
lua_getfield(L, IDX, KEY);                    \
if (lua_isfunction(L, -1))                    \
{                                             \
REF = luaL_ref(L, LUA_REGISTRYINDEX); \
}                                             \
else                                          \
{                                             \
REF = LUA_NOREF;                      \
lua_pop(L, 1);                        \
}

#define CLEAR_REF(L, REF)                              \
if (REF != LUA_NOREF)                          \
{                                              \
luaL_unref(L, LUA_REGISTRYINDEX, REF); \
REF = LUA_NOREF;                       \
}

#define DUP_STR_FROM_TABLE(L, REF, IDX, KEY)           \
{                                              \
lua_getfield(L, IDX, KEY);             \
const char *str = lua_tostring(L, -1); \
if (str)                               \
{                                      \
REF = strdup(str);             \
}                                      \
else                                   \
{                                      \
REF = NULL;                    \
}                                      \
lua_pop(L, 1);                         \
}

#define FREE_STR(REF)       \
if (REF)            \
{                   \
free(REF);  \
REF = NULL; \
}

#define SET_INT_FROM_TABLE(L, REF, IDX, KEY)             \
{                                                \
lua_getfield(L, IDX, KEY);               \
if (!lua_isnil(L, -1))                   \
{                                        \
REF = (int)lua_tointeger(L, -1); \
}                                        \
else                                     \
{                                        \
REF = 0;                         \
}                                        \
lua_pop(L, 1);                           \
}


lua_State* utlua_open_state();
int utlua_resume(lua_State *co, lua_State *from, int count);

lua_State* utlua_mainthread(lua_State *L);

void d2tv(double x, struct timeval *tv);

LUALIB_API int secure_loadfile (lua_State *L, const char *filename,
                                const char *mode);

int regress_get_socket_port(evutil_socket_t fd);
void regress_get_socket_host(evutil_socket_t fd, char *host);

#if FAN_HAS_OPENSSL
void die_most_horribly_from_openssl_error(const char *func);

void server_setup_certs(SSL_CTX *ctx, const char *certificate_chain,
                        const char *private_key);
#endif

#endif
