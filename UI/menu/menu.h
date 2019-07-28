#ifndef __MENU_H
#define __MENU_H

typedef struct MenuItem{
	struct MenuItem* child;
	struct MenuItem* next;
	char* text;
}MenuItem;

extern MenuItem Null_Menu;
extern MenuItem rootItem;

#endif
