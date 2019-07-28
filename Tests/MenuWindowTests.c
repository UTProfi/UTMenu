
#include "unity.h"
#include "unity_fixture.h"

#include "menu_window.h"

TEST_GROUP(MenuWindowTests);

MenuItem root, measure, setup, help;
void InitMenu();

TEST_SETUP(MenuWindowTests)
{
  InitMenu();
}

TEST_TEAR_DOWN(MenuWindowTests)
{
}

// private menu_window.c
int calculateChildsCount(MenuItem *menuItem);

TEST(MenuWindowTests, RootChildsCount_Test)
{
  int childCount = calculateChildsCount(&root);
  TEST_ASSERT_EQUAL(3, childCount);
}

TEST(MenuWindowTests, ZeroChildsCount_Test)
{
  int childCount = calculateChildsCount(&help);
  TEST_ASSERT_EQUAL(0, childCount);
}

void InitMenuItem(MenuItem *item)
{
  item->child = &Null_Menu;
  item->next = &Null_Menu;
  item->text = '\0';
}

void InitMenu()
{
  InitMenuItem(&root);
  InitMenuItem(&measure);
  InitMenuItem(&setup);
  InitMenuItem(&help);

  root.child = &measure;
  measure.next = &setup;
  setup.next = &help;

  root.text = "Корень";
  measure.text = "Измерение";
  setup.text = "Настройки";
  help.text = "Справка";
}

TEST_GROUP_RUNNER(MenuWindowTests)
{
  RUN_TEST_CASE(MenuWindowTests, RootChildsCount_Test);
  RUN_TEST_CASE(MenuWindowTests, ZeroChildsCount_Test);
}
