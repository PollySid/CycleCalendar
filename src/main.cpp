#include <AUI/Platform/Entry.h>
#include "MyWindow.h"

AUI_ENTRY
{
    _new<MyWindow>()->show();
    return 0;
}
