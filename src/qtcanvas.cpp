# include <canvas.h>

using namespace std::string_literals;

std::string QtCanvas::toString() {
    app->processEvents();
    return "This is QtCanvas"s;
}

QtCanvas::QtCanvas() {
    auto argc {0};
    app = std::make_unique<QGuiApplication>(argc, nullptr);
    win = std::make_unique<SimpleCppMainWindow>();
    win->show();    
}