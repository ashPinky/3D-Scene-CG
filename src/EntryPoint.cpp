#include <RenderEngine.hpp>
#include "Sandbox.hpp"

int main()
{
    ApplicationProps props;

    Sandbox app = Sandbox(props);
    app.Run();
}

