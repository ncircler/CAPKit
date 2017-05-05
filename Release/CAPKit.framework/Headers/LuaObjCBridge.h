extern int lua_objc_open(lua_State* L);
extern id lua_objc_getid(lua_State* L,int stack_index);
extern void lua_objc_pushid(lua_State* L,id object);
extern int lua_objc_isid(lua_State* L,int stack_index);

int lua_objc_gc(lua_State* L);

extern void lua_objc_pushpropertylist(lua_State* L,id propertylist);
extern id lua_objc_topropertylist(lua_State* L,int stack_index);

extern int lua_objc_methodcall(lua_State* L);
extern int lua_objc_tostringcall(lua_State* L);
extern int lua_objc_methodlookup(lua_State* L);
extern int lua_objc_tostring(lua_State* L);
extern int lua_objc_fieldset(lua_State* L);

int lua_objc_block_function(lua_State *L);

void LuaError(lua_State *L);
