#include <lua.h>

int table_new(lua_State *L)
{
  int top = lua_gettop(L);
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
  lua_pushcfunction(L, &table_new);
  return 1;
}
