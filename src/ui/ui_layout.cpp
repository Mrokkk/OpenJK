#include <stack>
#include <algorithm>

#include "server/exe_headers.h"

#include "ui_shared.h"
#include "ui_layout.h"

enum layoutType_t {
	LAYOUT_HORIZONTAL,
	LAYOUT_VERTICAL,
};

struct layoutDef_t {
	layoutDef_t(layoutType_t t, float x, float y, layoutDef_t* p);
	void Add(itemDef_t *item);

private:
	const layoutType_t	type;
	UIRectangle			rect;
	const float			localX;
	const float			localY;
	layoutDef_t			*parent;

	void Recalculate(const layoutDef_t& child);
};

static std::stack<layoutDef_t> layoutStack;

static layoutDef_t *Layout_Current()
{
	return layoutStack.empty() ? NULL : &layoutStack.top();
}

void Layout_Current_Add(itemDef_t *item)
{
	if (auto layout = Layout_Current())
	{
		layout->Add(item);
	}
}

layoutDef_t::layoutDef_t(layoutType_t t, float x, float y, layoutDef_t* p)
	: type(t)
	, rect(
		UIRectangle{
			p ? p->type == LAYOUT_HORIZONTAL ? p->rect.x + p->rect.w + x : p->rect.x + x : x,
			p ? p->type == LAYOUT_VERTICAL ? p->rect.y + p->rect.h + y : p->rect.y + y : y,
			0.f,
			0.f
		})
	, localX(x)
	, localY(y)
	, parent(p)
{
}

void layoutDef_t::Add(itemDef_t *newItem)
{
	switch (type)
	{
		case LAYOUT_HORIZONTAL:
			newItem->window.rectClient.x += rect.x + rect.w;
			newItem->window.rectClient.y += rect.y;
			rect.w += newItem->window.rectClient.w;
			rect.h = std::max(rect.h, newItem->window.rectClient.h);
			break;
		case LAYOUT_VERTICAL:
			newItem->window.rectClient.x += rect.x;
			newItem->window.rectClient.y += rect.y + rect.h;
			rect.w = std::max(rect.w, newItem->window.rectClient.w);
			rect.h += newItem->window.rectClient.h;
			break;
	}
	if (parent)
	{
		parent->Recalculate(*this);
	}
}

void layoutDef_t::Recalculate(const layoutDef_t& child)
{
	switch (type)
	{
		case LAYOUT_HORIZONTAL:
			rect.w = std::max(rect.w, child.localX + child.rect.w);
			break;
		case LAYOUT_VERTICAL:
			rect.h = std::max(rect.h, child.localY + child.rect.h);
			break;
	}
	if (parent)
	{
		parent->Recalculate(*this);
	}
}

static qboolean Layout_Parse(float *x, float *y, layoutType_t *type)
{
	const char *token;
	while (1)
	{
		if (PC_ParseString(&token))
		{
			PC_ParseWarning("end of file inside layoutDef");
			return qfalse;
		}
		if (*token == '}')
		{
			PC_ParseWarning("empty layoutDef");
			return qfalse;
		}
		else if (!Q_stricmp(token, "type"))
		{
			const char *typeStr;
			if (PC_ParseString(&typeStr))
			{
				PC_ParseWarning("failed to parse layoutDef.type");
				return qfalse;
			}
			if (!Q_stricmp(typeStr, "horiz"))
			{
				*type = LAYOUT_HORIZONTAL;
			}
			else if (!Q_stricmp(typeStr, "vert"))
			{
				*type = LAYOUT_VERTICAL;
			}
		}
		else if (!Q_stricmp(token, "pos"))
		{
			if (PC_ParseFloat(x) || PC_ParseFloat(y))
			{
				PC_ParseWarning("failed to parse layoutDef.pos");
				return qfalse;
			}
		}
		else
		{
			PC_Parse_RewindBack(strlen(token));
			break;
		}
	}
	return qtrue;
}

qboolean MenuParse_layoutDef( itemDef_t *item )
{
	const char *token = NULL;
	menuDef_t *menu = (menuDef_t*)item;

	if (PC_ParseString(&token))
	{
		return qfalse;
	}

	if (*token != '{')
	{
		return qfalse;
	}

	float x = 0.f, y = 0.f;
	layoutType_t type = LAYOUT_VERTICAL;

	if (!Layout_Parse(&x, &y, &type))
	{
		return qfalse;
	}

	layoutStack.emplace(type, x, y, Layout_Current());
	MenuParse_continue(menu);
	layoutStack.pop();

	return qtrue;
}

// vim: set noexpandtab tabstop=4 shiftwidth=4 :
