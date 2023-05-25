#include <lua.h>
#include <stdio.h>

#define top lua_gettop(L)

int table_new(lua_State *L)
{
	if (top > 2) lua_pop(L, top-2);
	int narr = 0;
	if (top > 0) narr=lua_tointeger(L, 1);
	int nrec = 0;
	if (top > 1) nrec=lua_tointeger(L, 2);
	lua_createtable(L, narr, nrec);
	return 1;
}

int luaopen_table_new(lua_State *L)
{
	int bottom = top;
	lua_pushcfunction(L, &table_new);
	lua_getglobal(L, "table");
	lua_pushliteral(L, "new");
	lua_gettable(L, bottom+2);
	if (lua_isnil(L, top)) {
		lua_pop(L, 1);
		lua_pushliteral(L, "new");
		lua_pushvalue(L, bottom+1);
		lua_settable(L, bottom+2);
	}
	lua_pop(L, 1);
	return 1;
}
