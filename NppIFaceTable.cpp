// This file is part of LuaScript.
// 
// Copyright (C)2016 Justin Dailey <dail8859@yahoo.com>
// 
// LuaScript is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include "IFaceTable.h"
#include "Notepad_plus_msgs.h"
#include "menuCmdID.h"

static IFaceConstant ifaceConstants[] = {
	{ "ALL_OPEN_FILES", ALL_OPEN_FILES },
	{ "IDM_CLEAN_RECENT_FILE_LIST", IDM_CLEAN_RECENT_FILE_LIST },
	{ "IDM_CMDLINEARGUMENTS", IDM_CMDLINEARGUMENTS },
	{ "IDM_CONFUPDATERPROXY", IDM_CONFUPDATERPROXY },
	{ "IDM_EDIT_AUTOCOMPLETE", IDM_EDIT_AUTOCOMPLETE },
	{ "IDM_EDIT_AUTOCOMPLETE_CURRENTFILE", IDM_EDIT_AUTOCOMPLETE_CURRENTFILE },
	{ "IDM_EDIT_AUTOCOMPLETE_PATH", IDM_EDIT_AUTOCOMPLETE_PATH },
	{ "IDM_EDIT_BEGINENDSELECT", IDM_EDIT_BEGINENDSELECT },
	{ "IDM_EDIT_BLANKLINEABOVECURRENT", IDM_EDIT_BLANKLINEABOVECURRENT },
	{ "IDM_EDIT_BLANKLINEBELOWCURRENT", IDM_EDIT_BLANKLINEBELOWCURRENT },
	{ "IDM_EDIT_BLOCK_COMMENT", IDM_EDIT_BLOCK_COMMENT },
	{ "IDM_EDIT_BLOCK_COMMENT_SET", IDM_EDIT_BLOCK_COMMENT_SET },
	{ "IDM_EDIT_BLOCK_UNCOMMENT", IDM_EDIT_BLOCK_UNCOMMENT },
	{ "IDM_EDIT_CHAR_PANEL", IDM_EDIT_CHAR_PANEL },
	{ "IDM_EDIT_CLEARREADONLY", IDM_EDIT_CLEARREADONLY },
	{ "IDM_EDIT_CLIPBOARDHISTORY_PANEL", IDM_EDIT_CLIPBOARDHISTORY_PANEL },
	{ "IDM_EDIT_COLUMNMODE", IDM_EDIT_COLUMNMODE },
	{ "IDM_EDIT_COLUMNMODETIP", IDM_EDIT_COLUMNMODETIP },
	{ "IDM_EDIT_COPY", IDM_EDIT_COPY },
	{ "IDM_EDIT_COPY_BINARY", IDM_EDIT_COPY_BINARY },
	{ "IDM_EDIT_CURRENTDIRTOCLIP", IDM_EDIT_CURRENTDIRTOCLIP },
	{ "IDM_EDIT_CUT", IDM_EDIT_CUT },
	{ "IDM_EDIT_CUT_BINARY", IDM_EDIT_CUT_BINARY },
	{ "IDM_EDIT_DELETE", IDM_EDIT_DELETE },
	{ "IDM_EDIT_DUP_LINE", IDM_EDIT_DUP_LINE },
	{ "IDM_EDIT_EOL2WS", IDM_EDIT_EOL2WS },
	{ "IDM_EDIT_FILENAMETOCLIP", IDM_EDIT_FILENAMETOCLIP },
	{ "IDM_EDIT_FULLPATHTOCLIP", IDM_EDIT_FULLPATHTOCLIP },
	{ "IDM_EDIT_FUNCCALLTIP", IDM_EDIT_FUNCCALLTIP },
	{ "IDM_EDIT_INS_TAB", IDM_EDIT_INS_TAB },
	{ "IDM_EDIT_JOIN_LINES", IDM_EDIT_JOIN_LINES },
	{ "IDM_EDIT_LINE_DOWN", IDM_EDIT_LINE_DOWN },
	{ "IDM_EDIT_LINE_UP", IDM_EDIT_LINE_UP },
	{ "IDM_EDIT_LOWERCASE", IDM_EDIT_LOWERCASE },
	{ "IDM_EDIT_LTR", IDM_EDIT_LTR },
	{ "IDM_EDIT_PASTE", IDM_EDIT_PASTE },
	{ "IDM_EDIT_PASTE_AS_HTML", IDM_EDIT_PASTE_AS_HTML },
	{ "IDM_EDIT_PASTE_AS_RTF", IDM_EDIT_PASTE_AS_RTF },
	{ "IDM_EDIT_PASTE_BINARY", IDM_EDIT_PASTE_BINARY },
	{ "IDM_EDIT_REDO", IDM_EDIT_REDO },
	{ "IDM_EDIT_REMOVEEMPTYLINES", IDM_EDIT_REMOVEEMPTYLINES },
	{ "IDM_EDIT_REMOVEEMPTYLINESWITHBLANK", IDM_EDIT_REMOVEEMPTYLINESWITHBLANK },
	{ "IDM_EDIT_RMV_TAB", IDM_EDIT_RMV_TAB },
	{ "IDM_EDIT_RTL", IDM_EDIT_RTL },
	{ "IDM_EDIT_SELECTALL", IDM_EDIT_SELECTALL },
	{ "IDM_EDIT_SETREADONLY", IDM_EDIT_SETREADONLY },
	{ "IDM_EDIT_SORTLINES_DECIMALCOMMA_ASCENDING", IDM_EDIT_SORTLINES_DECIMALCOMMA_ASCENDING },
	{ "IDM_EDIT_SORTLINES_DECIMALCOMMA_DESCENDING", IDM_EDIT_SORTLINES_DECIMALCOMMA_DESCENDING },
	{ "IDM_EDIT_SORTLINES_DECIMALDOT_ASCENDING", IDM_EDIT_SORTLINES_DECIMALDOT_ASCENDING },
	{ "IDM_EDIT_SORTLINES_DECIMALDOT_DESCENDING", IDM_EDIT_SORTLINES_DECIMALDOT_DESCENDING },
	{ "IDM_EDIT_SORTLINES_INTEGER_ASCENDING", IDM_EDIT_SORTLINES_INTEGER_ASCENDING },
	{ "IDM_EDIT_SORTLINES_INTEGER_DESCENDING", IDM_EDIT_SORTLINES_INTEGER_DESCENDING },
	{ "IDM_EDIT_SORTLINES_LEXICOGRAPHIC_ASCENDING", IDM_EDIT_SORTLINES_LEXICOGRAPHIC_ASCENDING },
	{ "IDM_EDIT_SORTLINES_LEXICOGRAPHIC_DESCENDING", IDM_EDIT_SORTLINES_LEXICOGRAPHIC_DESCENDING },
	{ "IDM_EDIT_SPLIT_LINES", IDM_EDIT_SPLIT_LINES },
	{ "IDM_EDIT_STREAM_COMMENT", IDM_EDIT_STREAM_COMMENT },
	{ "IDM_EDIT_STREAM_UNCOMMENT", IDM_EDIT_STREAM_UNCOMMENT },
	{ "IDM_EDIT_SW2TAB_ALL", IDM_EDIT_SW2TAB_ALL },
	{ "IDM_EDIT_SW2TAB_LEADING", IDM_EDIT_SW2TAB_LEADING },
	{ "IDM_EDIT_TAB2SW", IDM_EDIT_TAB2SW },
	{ "IDM_EDIT_TRANSPOSE_LINE", IDM_EDIT_TRANSPOSE_LINE },
	{ "IDM_EDIT_TRIMALL", IDM_EDIT_TRIMALL },
	{ "IDM_EDIT_TRIMLINEHEAD", IDM_EDIT_TRIMLINEHEAD },
	{ "IDM_EDIT_TRIMTRAILING", IDM_EDIT_TRIMTRAILING },
	{ "IDM_EDIT_TRIM_BOTH", IDM_EDIT_TRIM_BOTH },
	{ "IDM_EDIT_UNDO", IDM_EDIT_UNDO },
	{ "IDM_EDIT_UPPERCASE", IDM_EDIT_UPPERCASE },
	{ "IDM_FILESWITCHER_FILESCLOSE", IDM_FILESWITCHER_FILESCLOSE },
	{ "IDM_FILESWITCHER_FILESCLOSEOTHERS", IDM_FILESWITCHER_FILESCLOSEOTHERS },
	{ "IDM_FILE_CLOSE", IDM_FILE_CLOSE },
	{ "IDM_FILE_CLOSEALL", IDM_FILE_CLOSEALL },
	{ "IDM_FILE_CLOSEALL_BUT_CURRENT", IDM_FILE_CLOSEALL_BUT_CURRENT },
	{ "IDM_FILE_CLOSEALL_TOLEFT", IDM_FILE_CLOSEALL_TOLEFT },
	{ "IDM_FILE_CLOSEALL_TORIGHT", IDM_FILE_CLOSEALL_TORIGHT },
	{ "IDM_FILE_DELETE", IDM_FILE_DELETE },
	{ "IDM_FILE_EXIT", IDM_FILE_EXIT },
	{ "IDM_FILE_LOADSESSION", IDM_FILE_LOADSESSION },
	{ "IDM_FILE_NEW", IDM_FILE_NEW },
	{ "IDM_FILE_OPEN", IDM_FILE_OPEN },
	{ "IDM_FILE_OPEN_CMD", IDM_FILE_OPEN_CMD },
	{ "IDM_FILE_OPEN_FOLDER", IDM_FILE_OPEN_FOLDER },
	{ "IDM_FILE_PRINT", IDM_FILE_PRINT },
	{ "IDM_FILE_PRINTNOW", IDM_FILE_PRINTNOW },
	{ "IDM_FILE_RELOAD", IDM_FILE_RELOAD },
	{ "IDM_FILE_RENAME", IDM_FILE_RENAME },
	{ "IDM_FILE_RESTORELASTCLOSEDFILE", IDM_FILE_RESTORELASTCLOSEDFILE },
	{ "IDM_FILE_SAVE", IDM_FILE_SAVE },
	{ "IDM_FILE_SAVEALL", IDM_FILE_SAVEALL },
	{ "IDM_FILE_SAVEAS", IDM_FILE_SAVEAS },
	{ "IDM_FILE_SAVECOPYAS", IDM_FILE_SAVECOPYAS },
	{ "IDM_FILE_SAVESESSION", IDM_FILE_SAVESESSION },
	{ "IDM_FOCUS_ON_FOUND_RESULTS", IDM_FOCUS_ON_FOUND_RESULTS },
	{ "IDM_FORMAT_ANSI", IDM_FORMAT_ANSI },
	{ "IDM_FORMAT_AS_UTF_8", IDM_FORMAT_AS_UTF_8 },
	{ "IDM_FORMAT_BIG5", IDM_FORMAT_BIG5 },
	{ "IDM_FORMAT_CONV2_ANSI", IDM_FORMAT_CONV2_ANSI },
	{ "IDM_FORMAT_CONV2_AS_UTF_8", IDM_FORMAT_CONV2_AS_UTF_8 },
	{ "IDM_FORMAT_CONV2_UCS_2BE", IDM_FORMAT_CONV2_UCS_2BE },
	{ "IDM_FORMAT_CONV2_UCS_2LE", IDM_FORMAT_CONV2_UCS_2LE },
	{ "IDM_FORMAT_CONV2_UTF_8", IDM_FORMAT_CONV2_UTF_8 },
	{ "IDM_FORMAT_DOS_437", IDM_FORMAT_DOS_437 },
	{ "IDM_FORMAT_DOS_720", IDM_FORMAT_DOS_720 },
	{ "IDM_FORMAT_DOS_737", IDM_FORMAT_DOS_737 },
	{ "IDM_FORMAT_DOS_775", IDM_FORMAT_DOS_775 },
	{ "IDM_FORMAT_DOS_850", IDM_FORMAT_DOS_850 },
	{ "IDM_FORMAT_DOS_852", IDM_FORMAT_DOS_852 },
	{ "IDM_FORMAT_DOS_855", IDM_FORMAT_DOS_855 },
	{ "IDM_FORMAT_DOS_857", IDM_FORMAT_DOS_857 },
	{ "IDM_FORMAT_DOS_858", IDM_FORMAT_DOS_858 },
	{ "IDM_FORMAT_DOS_860", IDM_FORMAT_DOS_860 },
	{ "IDM_FORMAT_DOS_861", IDM_FORMAT_DOS_861 },
	{ "IDM_FORMAT_DOS_862", IDM_FORMAT_DOS_862 },
	{ "IDM_FORMAT_DOS_863", IDM_FORMAT_DOS_863 },
	{ "IDM_FORMAT_DOS_865", IDM_FORMAT_DOS_865 },
	{ "IDM_FORMAT_DOS_866", IDM_FORMAT_DOS_866 },
	{ "IDM_FORMAT_DOS_869", IDM_FORMAT_DOS_869 },
	{ "IDM_FORMAT_ENCODE", IDM_FORMAT_ENCODE },
	{ "IDM_FORMAT_ENCODE_END", IDM_FORMAT_ENCODE_END },
	{ "IDM_FORMAT_EUC_KR", IDM_FORMAT_EUC_KR },
	{ "IDM_FORMAT_GB2312", IDM_FORMAT_GB2312 },
	{ "IDM_FORMAT_ISO_8859_1", IDM_FORMAT_ISO_8859_1 },
	{ "IDM_FORMAT_ISO_8859_10", IDM_FORMAT_ISO_8859_10 },
	{ "IDM_FORMAT_ISO_8859_11", IDM_FORMAT_ISO_8859_11 },
	{ "IDM_FORMAT_ISO_8859_13", IDM_FORMAT_ISO_8859_13 },
	{ "IDM_FORMAT_ISO_8859_14", IDM_FORMAT_ISO_8859_14 },
	{ "IDM_FORMAT_ISO_8859_15", IDM_FORMAT_ISO_8859_15 },
	{ "IDM_FORMAT_ISO_8859_16", IDM_FORMAT_ISO_8859_16 },
	{ "IDM_FORMAT_ISO_8859_2", IDM_FORMAT_ISO_8859_2 },
	{ "IDM_FORMAT_ISO_8859_3", IDM_FORMAT_ISO_8859_3 },
	{ "IDM_FORMAT_ISO_8859_4", IDM_FORMAT_ISO_8859_4 },
	{ "IDM_FORMAT_ISO_8859_5", IDM_FORMAT_ISO_8859_5 },
	{ "IDM_FORMAT_ISO_8859_6", IDM_FORMAT_ISO_8859_6 },
	{ "IDM_FORMAT_ISO_8859_7", IDM_FORMAT_ISO_8859_7 },
	{ "IDM_FORMAT_ISO_8859_8", IDM_FORMAT_ISO_8859_8 },
	{ "IDM_FORMAT_ISO_8859_9", IDM_FORMAT_ISO_8859_9 },
	{ "IDM_FORMAT_KOI8R_CYRILLIC", IDM_FORMAT_KOI8R_CYRILLIC },
	{ "IDM_FORMAT_KOI8U_CYRILLIC", IDM_FORMAT_KOI8U_CYRILLIC },
	{ "IDM_FORMAT_KOREAN_WIN", IDM_FORMAT_KOREAN_WIN },
	{ "IDM_FORMAT_MAC_CYRILLIC", IDM_FORMAT_MAC_CYRILLIC },
	{ "IDM_FORMAT_SHIFT_JIS", IDM_FORMAT_SHIFT_JIS },
	{ "IDM_FORMAT_TIS_620", IDM_FORMAT_TIS_620 },
	{ "IDM_FORMAT_TODOS", IDM_FORMAT_TODOS },
	{ "IDM_FORMAT_TOMAC", IDM_FORMAT_TOMAC },
	{ "IDM_FORMAT_TOUNIX", IDM_FORMAT_TOUNIX },
	{ "IDM_FORMAT_UCS_2BE", IDM_FORMAT_UCS_2BE },
	{ "IDM_FORMAT_UCS_2LE", IDM_FORMAT_UCS_2LE },
	{ "IDM_FORMAT_UTF_8", IDM_FORMAT_UTF_8 },
	{ "IDM_FORMAT_WIN_1250", IDM_FORMAT_WIN_1250 },
	{ "IDM_FORMAT_WIN_1251", IDM_FORMAT_WIN_1251 },
	{ "IDM_FORMAT_WIN_1252", IDM_FORMAT_WIN_1252 },
	{ "IDM_FORMAT_WIN_1253", IDM_FORMAT_WIN_1253 },
	{ "IDM_FORMAT_WIN_1254", IDM_FORMAT_WIN_1254 },
	{ "IDM_FORMAT_WIN_1255", IDM_FORMAT_WIN_1255 },
	{ "IDM_FORMAT_WIN_1256", IDM_FORMAT_WIN_1256 },
	{ "IDM_FORMAT_WIN_1257", IDM_FORMAT_WIN_1257 },
	{ "IDM_FORMAT_WIN_1258", IDM_FORMAT_WIN_1258 },
	{ "IDM_FORUM", IDM_FORUM },
	{ "IDM_HELP", IDM_HELP },
	{ "IDM_HOMESWEETHOME", IDM_HOMESWEETHOME },
	{ "IDM_LANGSTYLE_CONFIG_DLG", IDM_LANGSTYLE_CONFIG_DLG },
	{ "IDM_LANG_ADA", IDM_LANG_ADA },
	{ "IDM_LANG_ASCII", IDM_LANG_ASCII },
	{ "IDM_LANG_ASM", IDM_LANG_ASM },
	{ "IDM_LANG_ASP", IDM_LANG_ASP },
	{ "IDM_LANG_AU3", IDM_LANG_AU3 },
	{ "IDM_LANG_BASH", IDM_LANG_BASH },
	{ "IDM_LANG_BATCH", IDM_LANG_BATCH },
	{ "IDM_LANG_C", IDM_LANG_C },
	{ "IDM_LANG_CAML", IDM_LANG_CAML },
	{ "IDM_LANG_CMAKE", IDM_LANG_CMAKE },
	{ "IDM_LANG_COBOL", IDM_LANG_COBOL },
	{ "IDM_LANG_COFFEESCRIPT", IDM_LANG_COFFEESCRIPT },
	{ "IDM_LANG_CPP", IDM_LANG_CPP },
	{ "IDM_LANG_CS", IDM_LANG_CS },
	{ "IDM_LANG_CSS", IDM_LANG_CSS },
	{ "IDM_LANG_D", IDM_LANG_D },
	{ "IDM_LANG_DIFF", IDM_LANG_DIFF },
	{ "IDM_LANG_EXTERNAL", IDM_LANG_EXTERNAL },
	{ "IDM_LANG_EXTERNAL_LIMIT", IDM_LANG_EXTERNAL_LIMIT },
	{ "IDM_LANG_FLASH", IDM_LANG_FLASH },
	{ "IDM_LANG_FORTRAN", IDM_LANG_FORTRAN },
	{ "IDM_LANG_GUI4CLI", IDM_LANG_GUI4CLI },
	{ "IDM_LANG_HASKELL", IDM_LANG_HASKELL },
	{ "IDM_LANG_HTML", IDM_LANG_HTML },
	{ "IDM_LANG_INI", IDM_LANG_INI },
	{ "IDM_LANG_INNO", IDM_LANG_INNO },
	{ "IDM_LANG_JAVA", IDM_LANG_JAVA },
	{ "IDM_LANG_JS", IDM_LANG_JS },
	{ "IDM_LANG_JSP", IDM_LANG_JSP },
	{ "IDM_LANG_KIX", IDM_LANG_KIX },
	{ "IDM_LANG_LISP", IDM_LANG_LISP },
	{ "IDM_LANG_LUA", IDM_LANG_LUA },
	{ "IDM_LANG_MAKEFILE", IDM_LANG_MAKEFILE },
	{ "IDM_LANG_MATLAB", IDM_LANG_MATLAB },
	{ "IDM_LANG_NSIS", IDM_LANG_NSIS },
	{ "IDM_LANG_OBJC", IDM_LANG_OBJC },
	{ "IDM_LANG_PASCAL", IDM_LANG_PASCAL },
	{ "IDM_LANG_PERL", IDM_LANG_PERL },
	{ "IDM_LANG_PHP", IDM_LANG_PHP },
	{ "IDM_LANG_POWERSHELL", IDM_LANG_POWERSHELL },
	{ "IDM_LANG_PROPS", IDM_LANG_PROPS },
	{ "IDM_LANG_PS", IDM_LANG_PS },
	{ "IDM_LANG_PYTHON", IDM_LANG_PYTHON },
	{ "IDM_LANG_R", IDM_LANG_R },
	{ "IDM_LANG_RC", IDM_LANG_RC },
	{ "IDM_LANG_RUBY", IDM_LANG_RUBY },
	{ "IDM_LANG_SCHEME", IDM_LANG_SCHEME },
	{ "IDM_LANG_SMALLTALK", IDM_LANG_SMALLTALK },
	{ "IDM_LANG_SQL", IDM_LANG_SQL },
	{ "IDM_LANG_TCL", IDM_LANG_TCL },
	{ "IDM_LANG_TEX", IDM_LANG_TEX },
	{ "IDM_LANG_TEXT", IDM_LANG_TEXT },
	{ "IDM_LANG_USER", IDM_LANG_USER },
	{ "IDM_LANG_USER_DLG", IDM_LANG_USER_DLG },
	{ "IDM_LANG_USER_LIMIT", IDM_LANG_USER_LIMIT },
	{ "IDM_LANG_VB", IDM_LANG_VB },
	{ "IDM_LANG_VERILOG", IDM_LANG_VERILOG },
	{ "IDM_LANG_VHDL", IDM_LANG_VHDL },
	{ "IDM_LANG_XML", IDM_LANG_XML },
	{ "IDM_LANG_YAML", IDM_LANG_YAML },
	{ "IDM_MACRO_PLAYBACKRECORDEDMACRO", IDM_MACRO_PLAYBACKRECORDEDMACRO },
	{ "IDM_MACRO_RUNMULTIMACRODLG", IDM_MACRO_RUNMULTIMACRODLG },
	{ "IDM_MACRO_SAVECURRENTMACRO", IDM_MACRO_SAVECURRENTMACRO },
	{ "IDM_MACRO_STARTRECORDINGMACRO", IDM_MACRO_STARTRECORDINGMACRO },
	{ "IDM_MACRO_STOPRECORDINGMACRO", IDM_MACRO_STOPRECORDINGMACRO },
	{ "IDM_ONLINEHELP", IDM_ONLINEHELP },
	{ "IDM_ONLINESUPPORT", IDM_ONLINESUPPORT },
	{ "IDM_OPEN_ALL_RECENT_FILE", IDM_OPEN_ALL_RECENT_FILE },
	{ "IDM_PLUGINSHOME", IDM_PLUGINSHOME },
	{ "IDM_PROJECTPAGE", IDM_PROJECTPAGE },
	{ "IDM_SEARCH_CLEARALLMARKS", IDM_SEARCH_CLEARALLMARKS },
	{ "IDM_SEARCH_CLEAR_BOOKMARKS", IDM_SEARCH_CLEAR_BOOKMARKS },
	{ "IDM_SEARCH_COPYMARKEDLINES", IDM_SEARCH_COPYMARKEDLINES },
	{ "IDM_SEARCH_CUTMARKEDLINES", IDM_SEARCH_CUTMARKEDLINES },
	{ "IDM_SEARCH_DELETEMARKEDLINES", IDM_SEARCH_DELETEMARKEDLINES },
	{ "IDM_SEARCH_DELETEUNMARKEDLINES", IDM_SEARCH_DELETEUNMARKEDLINES },
	{ "IDM_SEARCH_FIND", IDM_SEARCH_FIND },
	{ "IDM_SEARCH_FINDCHARINRANGE", IDM_SEARCH_FINDCHARINRANGE },
	{ "IDM_SEARCH_FINDINCREMENT", IDM_SEARCH_FINDINCREMENT },
	{ "IDM_SEARCH_FINDINFILES", IDM_SEARCH_FINDINFILES },
	{ "IDM_SEARCH_FINDNEXT", IDM_SEARCH_FINDNEXT },
	{ "IDM_SEARCH_FINDPREV", IDM_SEARCH_FINDPREV },
	{ "IDM_SEARCH_GONEXTMARKER1", IDM_SEARCH_GONEXTMARKER1 },
	{ "IDM_SEARCH_GONEXTMARKER2", IDM_SEARCH_GONEXTMARKER2 },
	{ "IDM_SEARCH_GONEXTMARKER3", IDM_SEARCH_GONEXTMARKER3 },
	{ "IDM_SEARCH_GONEXTMARKER4", IDM_SEARCH_GONEXTMARKER4 },
	{ "IDM_SEARCH_GONEXTMARKER5", IDM_SEARCH_GONEXTMARKER5 },
	{ "IDM_SEARCH_GONEXTMARKER_DEF", IDM_SEARCH_GONEXTMARKER_DEF },
	{ "IDM_SEARCH_GOPREVMARKER1", IDM_SEARCH_GOPREVMARKER1 },
	{ "IDM_SEARCH_GOPREVMARKER2", IDM_SEARCH_GOPREVMARKER2 },
	{ "IDM_SEARCH_GOPREVMARKER3", IDM_SEARCH_GOPREVMARKER3 },
	{ "IDM_SEARCH_GOPREVMARKER4", IDM_SEARCH_GOPREVMARKER4 },
	{ "IDM_SEARCH_GOPREVMARKER5", IDM_SEARCH_GOPREVMARKER5 },
	{ "IDM_SEARCH_GOPREVMARKER_DEF", IDM_SEARCH_GOPREVMARKER_DEF },
	{ "IDM_SEARCH_GOTOLINE", IDM_SEARCH_GOTOLINE },
	{ "IDM_SEARCH_GOTOMATCHINGBRACE", IDM_SEARCH_GOTOMATCHINGBRACE },
	{ "IDM_SEARCH_GOTONEXTFOUND", IDM_SEARCH_GOTONEXTFOUND },
	{ "IDM_SEARCH_GOTOPREVFOUND", IDM_SEARCH_GOTOPREVFOUND },
	{ "IDM_SEARCH_INVERSEMARKS", IDM_SEARCH_INVERSEMARKS },
	{ "IDM_SEARCH_MARK", IDM_SEARCH_MARK },
	{ "IDM_SEARCH_MARKALLEXT1", IDM_SEARCH_MARKALLEXT1 },
	{ "IDM_SEARCH_MARKALLEXT2", IDM_SEARCH_MARKALLEXT2 },
	{ "IDM_SEARCH_MARKALLEXT3", IDM_SEARCH_MARKALLEXT3 },
	{ "IDM_SEARCH_MARKALLEXT4", IDM_SEARCH_MARKALLEXT4 },
	{ "IDM_SEARCH_MARKALLEXT5", IDM_SEARCH_MARKALLEXT5 },
	{ "IDM_SEARCH_NEXT_BOOKMARK", IDM_SEARCH_NEXT_BOOKMARK },
	{ "IDM_SEARCH_PASTEMARKEDLINES", IDM_SEARCH_PASTEMARKEDLINES },
	{ "IDM_SEARCH_PREV_BOOKMARK", IDM_SEARCH_PREV_BOOKMARK },
	{ "IDM_SEARCH_REPLACE", IDM_SEARCH_REPLACE },
	{ "IDM_SEARCH_SELECTMATCHINGBRACES", IDM_SEARCH_SELECTMATCHINGBRACES },
	{ "IDM_SEARCH_SETANDFINDNEXT", IDM_SEARCH_SETANDFINDNEXT },
	{ "IDM_SEARCH_SETANDFINDPREV", IDM_SEARCH_SETANDFINDPREV },
	{ "IDM_SEARCH_TOGGLE_BOOKMARK", IDM_SEARCH_TOGGLE_BOOKMARK },
	{ "IDM_SEARCH_UNMARKALLEXT1", IDM_SEARCH_UNMARKALLEXT1 },
	{ "IDM_SEARCH_UNMARKALLEXT2", IDM_SEARCH_UNMARKALLEXT2 },
	{ "IDM_SEARCH_UNMARKALLEXT3", IDM_SEARCH_UNMARKALLEXT3 },
	{ "IDM_SEARCH_UNMARKALLEXT4", IDM_SEARCH_UNMARKALLEXT4 },
	{ "IDM_SEARCH_UNMARKALLEXT5", IDM_SEARCH_UNMARKALLEXT5 },
	{ "IDM_SEARCH_VOLATILE_FINDNEXT", IDM_SEARCH_VOLATILE_FINDNEXT },
	{ "IDM_SEARCH_VOLATILE_FINDPREV", IDM_SEARCH_VOLATILE_FINDPREV },
	{ "IDM_SETTING_EDITCONTEXTMENU", IDM_SETTING_EDITCONTEXTMENU },
	{ "IDM_SETTING_IMPORTPLUGIN", IDM_SETTING_IMPORTPLUGIN },
	{ "IDM_SETTING_IMPORTSTYLETHEMS", IDM_SETTING_IMPORTSTYLETHEMS },
	{ "IDM_SETTING_PREFERECE", IDM_SETTING_PREFERECE },
	{ "IDM_SETTING_REMEMBER_LAST_SESSION", IDM_SETTING_REMEMBER_LAST_SESSION },
	{ "IDM_SETTING_SHORTCUT_MAPPER", IDM_SETTING_SHORTCUT_MAPPER },
	{ "IDM_SETTING_SHORTCUT_MAPPER_MACRO", IDM_SETTING_SHORTCUT_MAPPER_MACRO },
	{ "IDM_SETTING_SHORTCUT_MAPPER_RUN", IDM_SETTING_SHORTCUT_MAPPER_RUN },
	{ "IDM_SETTING_TRAYICON", IDM_SETTING_TRAYICON },
	{ "IDM_SYSTRAYPOPUP", IDM_SYSTRAYPOPUP },
	{ "IDM_SYSTRAYPOPUP_ACTIVATE", IDM_SYSTRAYPOPUP_ACTIVATE },
	{ "IDM_SYSTRAYPOPUP_CLOSE", IDM_SYSTRAYPOPUP_CLOSE },
	{ "IDM_SYSTRAYPOPUP_NEWDOC", IDM_SYSTRAYPOPUP_NEWDOC },
	{ "IDM_SYSTRAYPOPUP_NEW_AND_PASTE", IDM_SYSTRAYPOPUP_NEW_AND_PASTE },
	{ "IDM_SYSTRAYPOPUP_OPENFILE", IDM_SYSTRAYPOPUP_OPENFILE },
	{ "IDM_UPDATE_NPP", IDM_UPDATE_NPP },
	{ "IDM_VIEW_ALL_CHARACTERS", IDM_VIEW_ALL_CHARACTERS },
	{ "IDM_VIEW_ALWAYSONTOP", IDM_VIEW_ALWAYSONTOP },
	{ "IDM_VIEW_CLONE_TO_ANOTHER_VIEW", IDM_VIEW_CLONE_TO_ANOTHER_VIEW },
	{ "IDM_VIEW_CURLINE_HILITING", IDM_VIEW_CURLINE_HILITING },
	{ "IDM_VIEW_DOCCHANGEMARGIN", IDM_VIEW_DOCCHANGEMARGIN },
	{ "IDM_VIEW_DOC_MAP", IDM_VIEW_DOC_MAP },
	{ "IDM_VIEW_DRAWTABBAR_CLOSEBOTTUN", IDM_VIEW_DRAWTABBAR_CLOSEBOTTUN },
	{ "IDM_VIEW_DRAWTABBAR_DBCLK2CLOSE", IDM_VIEW_DRAWTABBAR_DBCLK2CLOSE },
	{ "IDM_VIEW_DRAWTABBAR_INACIVETAB", IDM_VIEW_DRAWTABBAR_INACIVETAB },
	{ "IDM_VIEW_DRAWTABBAR_MULTILINE", IDM_VIEW_DRAWTABBAR_MULTILINE },
	{ "IDM_VIEW_DRAWTABBAR_TOPBAR", IDM_VIEW_DRAWTABBAR_TOPBAR },
	{ "IDM_VIEW_DRAWTABBAR_VERTICAL", IDM_VIEW_DRAWTABBAR_VERTICAL },
	{ "IDM_VIEW_EDGEBACKGROUND", IDM_VIEW_EDGEBACKGROUND },
	{ "IDM_VIEW_EDGELINE", IDM_VIEW_EDGELINE },
	{ "IDM_VIEW_EDGENONE", IDM_VIEW_EDGENONE },
	{ "IDM_VIEW_EOL", IDM_VIEW_EOL },
	{ "IDM_VIEW_FILESWITCHER_PANEL", IDM_VIEW_FILESWITCHER_PANEL },
	{ "IDM_VIEW_FOLDERMAGIN", IDM_VIEW_FOLDERMAGIN },
	{ "IDM_VIEW_FOLDERMAGIN_ARROW", IDM_VIEW_FOLDERMAGIN_ARROW },
	{ "IDM_VIEW_FOLDERMAGIN_BOX", IDM_VIEW_FOLDERMAGIN_BOX },
	{ "IDM_VIEW_FOLDERMAGIN_CIRCLE", IDM_VIEW_FOLDERMAGIN_CIRCLE },
	{ "IDM_VIEW_FOLDERMAGIN_SIMPLE", IDM_VIEW_FOLDERMAGIN_SIMPLE },
	{ "IDM_VIEW_FOLD_1", IDM_VIEW_FOLD_1 },
	{ "IDM_VIEW_FOLD_2", IDM_VIEW_FOLD_2 },
	{ "IDM_VIEW_FOLD_3", IDM_VIEW_FOLD_3 },
	{ "IDM_VIEW_FOLD_4", IDM_VIEW_FOLD_4 },
	{ "IDM_VIEW_FOLD_5", IDM_VIEW_FOLD_5 },
	{ "IDM_VIEW_FOLD_6", IDM_VIEW_FOLD_6 },
	{ "IDM_VIEW_FOLD_7", IDM_VIEW_FOLD_7 },
	{ "IDM_VIEW_FOLD_8", IDM_VIEW_FOLD_8 },
	{ "IDM_VIEW_FOLD_CURRENT", IDM_VIEW_FOLD_CURRENT },
	{ "IDM_VIEW_FULLSCREENTOGGLE", IDM_VIEW_FULLSCREENTOGGLE },
	{ "IDM_VIEW_FUNC_LIST", IDM_VIEW_FUNC_LIST },
	{ "IDM_VIEW_GOTO_ANOTHER_VIEW", IDM_VIEW_GOTO_ANOTHER_VIEW },
	{ "IDM_VIEW_GOTO_NEW_INSTANCE", IDM_VIEW_GOTO_NEW_INSTANCE },
	{ "IDM_VIEW_HIDELINES", IDM_VIEW_HIDELINES },
	{ "IDM_VIEW_INDENT_GUIDE", IDM_VIEW_INDENT_GUIDE },
	{ "IDM_VIEW_LINENUMBER", IDM_VIEW_LINENUMBER },
	{ "IDM_VIEW_LOAD_IN_NEW_INSTANCE", IDM_VIEW_LOAD_IN_NEW_INSTANCE },
	{ "IDM_VIEW_LOCKTABBAR", IDM_VIEW_LOCKTABBAR },
	{ "IDM_VIEW_LWALIGN", IDM_VIEW_LWALIGN },
	{ "IDM_VIEW_LWDEF", IDM_VIEW_LWDEF },
	{ "IDM_VIEW_LWINDENT", IDM_VIEW_LWINDENT },
	{ "IDM_VIEW_POSTIT", IDM_VIEW_POSTIT },
	{ "IDM_VIEW_PROJECT_PANEL_1", IDM_VIEW_PROJECT_PANEL_1 },
	{ "IDM_VIEW_PROJECT_PANEL_2", IDM_VIEW_PROJECT_PANEL_2 },
	{ "IDM_VIEW_PROJECT_PANEL_3", IDM_VIEW_PROJECT_PANEL_3 },
	{ "IDM_VIEW_REDUCETABBAR", IDM_VIEW_REDUCETABBAR },
	{ "IDM_VIEW_REFRESHTABAR", IDM_VIEW_REFRESHTABAR },
	{ "IDM_VIEW_SUMMARY", IDM_VIEW_SUMMARY },
	{ "IDM_VIEW_SWITCHTO_OTHER_VIEW", IDM_VIEW_SWITCHTO_OTHER_VIEW },
	{ "IDM_VIEW_SYMBOLMARGIN", IDM_VIEW_SYMBOLMARGIN },
	{ "IDM_VIEW_SYNSCROLLH", IDM_VIEW_SYNSCROLLH },
	{ "IDM_VIEW_SYNSCROLLV", IDM_VIEW_SYNSCROLLV },
	{ "IDM_VIEW_TAB1", IDM_VIEW_TAB1 },
	{ "IDM_VIEW_TAB2", IDM_VIEW_TAB2 },
	{ "IDM_VIEW_TAB3", IDM_VIEW_TAB3 },
	{ "IDM_VIEW_TAB4", IDM_VIEW_TAB4 },
	{ "IDM_VIEW_TAB5", IDM_VIEW_TAB5 },
	{ "IDM_VIEW_TAB6", IDM_VIEW_TAB6 },
	{ "IDM_VIEW_TAB7", IDM_VIEW_TAB7 },
	{ "IDM_VIEW_TAB8", IDM_VIEW_TAB8 },
	{ "IDM_VIEW_TAB9", IDM_VIEW_TAB9 },
	{ "IDM_VIEW_TAB_NEXT", IDM_VIEW_TAB_NEXT },
	{ "IDM_VIEW_TAB_PREV", IDM_VIEW_TAB_PREV },
	{ "IDM_VIEW_TAB_SPACE", IDM_VIEW_TAB_SPACE },
	{ "IDM_VIEW_TOGGLE_FOLDALL", IDM_VIEW_TOGGLE_FOLDALL },
	{ "IDM_VIEW_TOGGLE_UNFOLDALL", IDM_VIEW_TOGGLE_UNFOLDALL },
	{ "IDM_VIEW_TOOLBAR_ENLARGE", IDM_VIEW_TOOLBAR_ENLARGE },
	{ "IDM_VIEW_TOOLBAR_REDUCE", IDM_VIEW_TOOLBAR_REDUCE },
	{ "IDM_VIEW_TOOLBAR_STANDARD", IDM_VIEW_TOOLBAR_STANDARD },
	{ "IDM_VIEW_UNFOLD", IDM_VIEW_UNFOLD },
	{ "IDM_VIEW_UNFOLD_1", IDM_VIEW_UNFOLD_1 },
	{ "IDM_VIEW_UNFOLD_2", IDM_VIEW_UNFOLD_2 },
	{ "IDM_VIEW_UNFOLD_3", IDM_VIEW_UNFOLD_3 },
	{ "IDM_VIEW_UNFOLD_4", IDM_VIEW_UNFOLD_4 },
	{ "IDM_VIEW_UNFOLD_5", IDM_VIEW_UNFOLD_5 },
	{ "IDM_VIEW_UNFOLD_6", IDM_VIEW_UNFOLD_6 },
	{ "IDM_VIEW_UNFOLD_7", IDM_VIEW_UNFOLD_7 },
	{ "IDM_VIEW_UNFOLD_8", IDM_VIEW_UNFOLD_8 },
	{ "IDM_VIEW_UNFOLD_CURRENT", IDM_VIEW_UNFOLD_CURRENT },
	{ "IDM_VIEW_WRAP", IDM_VIEW_WRAP },
	{ "IDM_VIEW_WRAP_SYMBOL", IDM_VIEW_WRAP_SYMBOL },
	{ "IDM_VIEW_ZOOMIN", IDM_VIEW_ZOOMIN },
	{ "IDM_VIEW_ZOOMOUT", IDM_VIEW_ZOOMOUT },
	{ "IDM_VIEW_ZOOMRESTORE", IDM_VIEW_ZOOMRESTORE },
	{ "IDM_WIKIFAQ", IDM_WIKIFAQ },
	{ "L_ADA", L_ADA },
	{ "L_ASCII", L_ASCII },
	{ "L_ASM", L_ASM },
	{ "L_ASP", L_ASP },
	{ "L_AU3", L_AU3 },
	{ "L_BASH", L_BASH },
	{ "L_BATCH", L_BATCH },
	{ "L_C", L_C },
	{ "L_CAML", L_CAML },
	{ "L_CMAKE", L_CMAKE },
	{ "L_COBOL", L_COBOL },
	{ "L_COFFEESCRIPT", L_COFFEESCRIPT },
	{ "L_CPP", L_CPP },
	{ "L_CS", L_CS },
	{ "L_CSS", L_CSS },
	{ "L_D", L_D },
	{ "L_DIFF", L_DIFF },
	{ "L_EXTERNAL", L_EXTERNAL },
	{ "L_FLASH", L_FLASH },
	{ "L_FORTRAN", L_FORTRAN },
	{ "L_GUI4CLI", L_GUI4CLI },
	{ "L_HASKELL", L_HASKELL },
	{ "L_HTML", L_HTML },
	{ "L_INI", L_INI },
	{ "L_INNO", L_INNO },
	{ "L_JAVA", L_JAVA },
	{ "L_JAVASCRIPT", L_JAVASCRIPT },
	{ "L_JS", L_JS },
	{ "L_JSON", L_JSON },
	{ "L_JSP", L_JSP },
	{ "L_KIX", L_KIX },
	{ "L_LISP", L_LISP },
	{ "L_LUA", L_LUA },
	{ "L_MAKEFILE", L_MAKEFILE },
	{ "L_MATLAB", L_MATLAB },
	{ "L_NSIS", L_NSIS },
	{ "L_OBJC", L_OBJC },
	{ "L_PASCAL", L_PASCAL },
	{ "L_PERL", L_PERL },
	{ "L_PHP", L_PHP },
	{ "L_POWERSHELL", L_POWERSHELL },
	{ "L_PROPS", L_PROPS },
	{ "L_PS", L_PS },
	{ "L_PYTHON", L_PYTHON },
	{ "L_R", L_R },
	{ "L_RC", L_RC },
	{ "L_RUBY", L_RUBY },
	{ "L_SCHEME", L_SCHEME },
	{ "L_SEARCHRESULT", L_SEARCHRESULT },
	{ "L_SMALLTALK", L_SMALLTALK },
	{ "L_SQL", L_SQL },
	{ "L_TCL", L_TCL },
	{ "L_TEX", L_TEX },
	{ "L_TEXT", L_TEXT },
	{ "L_USER", L_USER },
	{ "L_VB", L_VB },
	{ "L_VERILOG", L_VERILOG },
	{ "L_VHDL", L_VHDL },
	{ "L_XML", L_XML },
	{ "L_YAML", L_YAML },
	{ "MAIN_VIEW", MAIN_VIEW },
	{ "NPPM_GETAPPDATAPLUGINSALLOWED", NPPM_GETAPPDATAPLUGINSALLOWED },
	{ "NPPM_GETBUFFERLANGTYPE", NPPM_GETBUFFERLANGTYPE },
	{ "NPPM_GETCURRENTBUFFERID", NPPM_GETCURRENTBUFFERID },
	{ "NPPM_GETCURRENTCOLUMN", NPPM_GETCURRENTCOLUMN },
	{ "NPPM_GETCURRENTLANGTYPE", NPPM_GETCURRENTLANGTYPE },
	{ "NPPM_GETCURRENTLINE", NPPM_GETCURRENTLINE },
	{ "NPPM_GETCURRENTVIEW", NPPM_GETCURRENTVIEW },
	{ "NPPM_GETEDITORDEFAULTBACKGROUNDCOLOR", NPPM_GETEDITORDEFAULTBACKGROUNDCOLOR },
	{ "NPPM_GETEDITORDEFAULTFOREGROUNDCOLOR", NPPM_GETEDITORDEFAULTFOREGROUNDCOLOR },
	{ "NPPM_GETNPPVERSION", NPPM_GETNPPVERSION },
	{ "NPPM_GETWINDOWSVERSION", NPPM_GETWINDOWSVERSION },
	{ "NPPM_SETBUFFERLANGTYPE", NPPM_SETBUFFERLANGTYPE },
	{ "NPPM_SETCURRENTLANGTYPE", NPPM_SETCURRENTLANGTYPE },
	{ "PRIMARY_VIEW", PRIMARY_VIEW },
	{ "SECOND_VIEW", SECOND_VIEW },
	{ "SUB_VIEW", SUB_VIEW },
	{ "WV_95", WV_95 },
	{ "WV_98", WV_98 },
	{ "WV_ME", WV_ME },
	{ "WV_NT", WV_NT },
	{ "WV_S2003", WV_S2003 },
	{ "WV_UNKNOWN", WV_UNKNOWN },
	{ "WV_VISTA", WV_VISTA },
	{ "WV_W2K", WV_W2K },
	{ "WV_WIN32S", WV_WIN32S },
	{ "WV_WIN7", WV_WIN7 },
	{ "WV_WIN8", WV_WIN8 },
	{ "WV_WIN81", WV_WIN81 },
	{ "WV_XP", WV_XP },
	{ "WV_XPX64", WV_XPX64 },
};

static IFaceFunction ifaceFunctions[] = {
	{ "ActivateDoc", NPPM_ACTIVATEDOC, iface_void, { iface_int, iface_int } },
	{ "DoOpen", NPPM_DOOPEN, iface_bool, { iface_void, iface_tstring } },
	{ "GetBufferIDFromPos", NPPM_GETBUFFERIDFROMPOS, iface_int, { iface_int, iface_int } },
	{ "GetCurrentDirectory", NPPM_GETCURRENTDIRECTORY, iface_void, { iface_void, iface_tstringresult } },
	{ "GetCurrentDocIndex", NPPM_GETCURRENTDOCINDEX, iface_int, { iface_void, iface_int } },
	{ "GetCurrentWord", NPPM_GETCURRENTWORD, iface_void, { iface_void, iface_tstringresult } },
	{ "GetExtPart", NPPM_GETEXTPART, iface_void, { iface_void, iface_tstringresult } },
	{ "GetFileName", NPPM_GETFILENAME, iface_void, { iface_void, iface_tstringresult } },
	{ "GetFullCurrentPath", NPPM_GETFULLCURRENTPATH, iface_void, { iface_void, iface_tstringresult } },
	{ "GetNamePart", NPPM_GETNAMEPART, iface_void, { iface_void, iface_tstringresult } },
	{ "GetNbOpenFiles", NPPM_GETNBOPENFILES, iface_int, { iface_void, iface_int } },
	{ "GetNppDirectory", NPPM_GETNPPDIRECTORY, iface_void, { iface_void, iface_tstringresult } },
	//{ "GetPosFromBufferID", NPPM_GETPOSFROMBUFFERID, iface_int, { iface_int, iface_int } },
	//{ "HideTabBar", NPPM_HIDETABBAR, iface_bool, { iface_void, iface_bool } },
	//{ "IsTabBarHidden", NPPM_ISTABBARHIDDEN, iface_bool, { iface_void, iface_void } },
	//{ "LaunchFindInFilesDlg", NPPM_LAUNCHFINDINFILESDLG, iface_void, { iface_tstring, iface_tstring } },
	//{ "LoadSession", NPPM_LOADSESSION, iface_void, { iface_void, iface_tstring } },
	{ "ReloadFile", NPPM_RELOADFILE, iface_bool, { iface_bool, iface_tstring } },
	{ "SaveAllFiles", NPPM_SAVEALLFILES, iface_bool, { iface_void, iface_void } },
	{ "SaveCurrentFile", NPPM_SAVECURRENTFILE, iface_bool, { iface_void, iface_void } },
	{ "SaveCurrentSession", NPPM_SAVECURRENTSESSION, iface_void, { iface_void, iface_tstring } },
	{ "SwitchToFile", NPPM_SWITCHTOFILE, iface_bool, { iface_void, iface_tstring } },
}; 

static IFaceProperty ifaceProperties[] = {
	{ "AppDataPluginsAllowed", NPPM_GETAPPDATAPLUGINSALLOWED, 0, iface_bool, iface_void },
	{ "BufferLangType", NPPM_GETBUFFERLANGTYPE, NPPM_SETBUFFERLANGTYPE, iface_int, iface_int },
	{ "CurrentBufferID", NPPM_GETCURRENTBUFFERID, 0, iface_int, iface_void },
	{ "CurrentColumn", NPPM_GETCURRENTCOLUMN, 0, iface_int, iface_void },
	//{ "CurrentLangType", NPPM_GETCURRENTLANGTYPE, NPPM_SETCURRENTLANGTYPE, iface_int, iface_void },
	{ "CurrentLine", NPPM_GETCURRENTLINE, 0, iface_int, iface_void },
	{ "CurrentView", NPPM_GETCURRENTVIEW, 0, iface_int, iface_void },
	{ "DefaultBackgroundColor", NPPM_GETEDITORDEFAULTBACKGROUNDCOLOR, 0, iface_colour, iface_void },
	{ "DefaultForegroundColor", NPPM_GETEDITORDEFAULTFOREGROUNDCOLOR, 0, iface_colour, iface_void },
	{ "Version", NPPM_GETNPPVERSION, 0, iface_int, iface_void },
	{ "WindowsVersion", NPPM_GETWINDOWSVERSION, 0, iface_int, iface_void },
};

IFaceTable NppIFaceTable("NPPM_", ifaceFunctions, ELEMENTS(ifaceFunctions), ifaceConstants, ELEMENTS(ifaceConstants), ifaceProperties, ELEMENTS(ifaceProperties));
