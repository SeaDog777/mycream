#ifndef __LUA_H
#define __LUA_H

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <glib.h>

/*!
 * \defgroup lua Lua context
 * Functions to manipulate the Lua context.
 *
 * @{
 */

static inline void luaL_checktable (lua_State *L, int idx)
{
     if(!lua_istable (L, idx))
          luaL_typerror (L, idx, "table");
}

static inline gboolean luaL_checkboolean (lua_State *L, int idx)
{
     if (!lua_isboolean (L, idx))
          luaL_typerror (L, idx, "boolean");

     return lua_toboolean (L, idx);
}

/*!
 * \def LUA_TMODULE
 * Userdata type associated to #CreamModule.
 */
#define LUA_TMODULE    "CreamModule"

/*!
 * \def LUA_TCLIPBOARD
 * Userdata type associated to \class{GtkClipboard}.
 */
#define LUA_TCLIPBOARD "Clipboard"

/*!
 * \def LUA_TREGEX
 * Userdata type associated to \class{GRegex}.
 */
#define LUA_TREGEX     "Regex"

/*!
 * \def LUA_TWEBVIEW
 * Userdata type associated to #WebView.
 */
#define LUA_TWEBVIEW   "WebView"

gboolean lua_ctx_init (GError **err);
gboolean lua_ctx_parse (const char *file, GError **err);
void lua_ctx_close (void);

extern void lua_pushwebview (lua_State *L, WebView *w);

/*! @} */

#endif /* __LUA_H */
