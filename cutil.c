#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

int _set(lua_State* L)
{
	const char* k = luaL_checkstring(L, 1);
	const char* v = luaL_checkstring(L, 2);

	lua_pushstring(L, k);
	lua_pushstring(L, v);
	lua_settable(L, LUA_REGISTRYINDEX);
	return 0;
}

int _get(lua_State* L)
{
	const char* k = luaL_checkstring(L, 1);

	lua_pushstring(L, k);
	lua_gettable(L, LUA_REGISTRYINDEX);
	return 1;
}

int _split(lua_State* L)
{
    const char* s = luaL_checkstring(L, 1);
    const char* sep = luaL_checkstring(L, 2);
    const char* e;
    int i = 1;
  
    lua_newtable(L);

    while ((e = strchr(s, *sep)) != NULL) {
        lua_pushlstring(L, s, e-s);
        lua_rawseti(L, -2, i++);
        s = e + 1;
    }

    lua_pushstring(L, s);
    lua_rawseti(L, -2, i);
    return 1;
}

int _time(lua_State* L)
{
    struct timeval tv;
    struct timezone tz;
    struct tm *p;
    gettimeofday(&tv, &tz);
    long long ms = tv.tv_sec * 1000 + tv.tv_usec/1000;
    lua_pushinteger(L, ms);
    return 1; 
}

static luaL_Reg libs[] = {
    {"split", _split},
    {"get", _get},
    {"set", _set},
    {"time", _time},
    {NULL, NULL}
};

int luaopen_cutil(lua_State* L)
{
    luaL_newlib(L, libs);
    return 1;
}

