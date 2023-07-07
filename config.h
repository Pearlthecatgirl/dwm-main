/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 10;        /* gaps between windows */
static const unsigned int snap      = 0;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=13" };
static const char dmenufont[]       = "monospace:size=13";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#bfa793";
static const char col_cyan[]        = "#96392A";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

static const char *const autostart[] = {
	"st", NULL,
	"picom", "-f", NULL,
	"nm-applet", NULL,
	"slstatus", NULL,
	"hsetroot", "-center", "/home/pearl/wallpapers/background.png", NULL,
	"libinput-gestures", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "󰄛", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "steam",    NULL,	  NULL,	      8,	    0,		 -1 },
	{ "DaggerfallUnity.x86_64",    NULL,	  NULL,	      8,	    1,		 -1 },
	{ "openmw",    NULL,	  NULL,	      8,	    1,		 -1 },
	{ "openmw-launcher",    NULL,	  NULL,	      8,	    1,		 -1 },
	{ "MuPDF",    NULL,	  NULL,	      2,	    0,		 -1 },
	{ "Heroic",   NULL,	  NULL,       8,	    1,		 -1}
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

static const char *filecmd[]  = { "pcmanfm", NULL};
static const char *screenshotcmd[] = { "/home/pearl/Scripts/screenshot.sh", NULL};
static const char *slock[] = { "slock", NULL};
static const char *upvol[] = { "pactl", "set-sink-volume", "0", "+5%", NULL};
static const char *mute[] = { "pactl", "set-sink-mute", "0", "toggle", NULL};
static const char *downvol[] = { "pactl", "set-sink-volume", "0", "-5%", NULL};
//static const char *downvolnotify[] = { "pactl", "set-sink-volume", "0", "-5%", NULL};
//static const char *upvolnotify[] = { "pactl", "set-sink-volume", "0", "-5%", NULL};
static const char *upbrillo[] = { "brillo", "-q", "-A", "5", NULL};
static const char *downbrillo[] = { "brillo", "-q", "-U", "5", NULL};
//static const char *upbrillonotify[] = { "brillo", "-q", "-A", "5", NULL};
//static const char *downbrillonotify[] = { "brillo", "-q", "-U", "5", NULL};
static const char *pausecmd[] = {"playerctl", "play-pause", NULL};
static const char *nextcmd[] = {"playerctl", "next", NULL};
static const char *prevcmd[] = {"playerctl", "previous", NULL};
static const char *aBlur[] = {"picom-trans", "-c", "20", NULL};
static const char *bBlur[] = {"picom-trans", "-c", "40", NULL};
static const char *cBlur[] = {"picom-trans", "-c", "60", NULL};
static const char *dBlur[] = {"picom-trans", "-c", "80", NULL};
static const char *eBlur[] = {"picom-trans", "-c", "100", NULL};
static const char *libwolf[] = {"librewolf", NULL};
static const char *firefox[] = {"firefox", NULL};

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,	               	XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,	        XK_x, 	   spawn,          {.v = filecmd } },
	{ MODKEY|ShiftMask,	        XK_p,	   spawn,          {.v = screenshotcmd } },
	{ MODKEY,	              	XK_x, 	   spawn,          {.v = libwolf } },
	{ MODKEY|ShiftMask,             XK_f,	   spawn,          {.v = firefox } },
	{ MODKEY|ShiftMask,             XK_w,	   spawn,          {.v = slock } },

	{ 0,		             	0x1008FF12,spawn,          {.v = mute } },
	{ 0,		             	0x1008FF13,spawn,          {.v = upvol } },
	{ 0,		              	0x1008FF11,spawn,          {.v = downvol } },
	//{ 0,		             	0x1008FF13,spawn,          {.v = upvolnotify } },
	//{ 0,		              	0x1008FF11,spawn,          {.v = downvolnotify } },
	{ 0,		             	0x1008FF02,spawn,          {.v = upbrillo } },
	{ 0,		            	0x1008FF03,spawn,          {.v = downbrillo } },
	//{ 0,		             	0x1008FF02,spawn,          {.v = upbrillonotify } },
	//{ 0,		            	0x1008FF03,spawn,          {.v = downbrillonotify } },
	{ 0,		         	0x1008FF16,spawn,          {.v = prevcmd } },
	{ 0,		      	        0x1008FF17,spawn,          {.v = nextcmd } },
	{ 0,		          	0x1008FF14,spawn,          {.v = pausecmd } },


	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_o,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.005} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.005} },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_e,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_w,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,	                XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,			XK_equal,  setgaps,        {.i = 0 } },
	{ MODKEY,			XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY|ShiftMask,		XK_equal,  setgaps,        {.i = +1 } },
//	{ MODKEY,                       XK_Right,  viewnext,       {0} },
//	{ MODKEY,                       XK_Left,   viewprev,       {0} },
	{ MODKEY|ShiftMask,             XK_Right,  tagtonext,      {0} },
	{ MODKEY|ShiftMask,             XK_Left,   tagtoprev,      {0} },
	{ MODKEY,                       XK_Right,  viewnextskipvacant,       {0} },
	{ MODKEY,                       XK_Left,   viewprevskipvacant,       {0} },
//	{ MODKEY|ShiftMask,             XK_Right,  tagtonextskipvacant,      {0} },
//	{ MODKEY|ShiftMask,             XK_Left,   tagtoprevskipvacant,      {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8) 
	{ MODKEY|ShiftMask,             XK_e,      quitprompt,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

