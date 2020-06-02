#include "System/Config.h"
#include "Application.h"

int main()
{
    Application app({Config()});
    app.apploop();
    
    return 0;
}
