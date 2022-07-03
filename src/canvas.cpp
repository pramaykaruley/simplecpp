#include <canvas.h>
#include <sprite.h>
#include <turtle.h>

namespace simplecpp{

// C++ standard guarantess the order of initialization of static variables in the same file.
// They are initialized in the order they are declared.
// Refer to "Ordered Dynamic Initialization" in https://en.cppreference.com/w/cpp/language/initialization
// Following order is signicant as Qt application must be created before initializing any GUI classes
static int argc = 1;
static char *appName = "Simplecpp";
static QGuiApplication theApp(argc, &appName);
static Canvas theCanvas;
static Turtle theSystemTurtleObj;

static QRect calculateCanvasSize() {
    auto rect = theApp.primaryScreen()->availableGeometry();
    auto topLeft = rect.topLeft();
    auto sz = rect.size() * (2.0 / 3.0);
    return QRect(topLeft, sz);
}
    void initCanvas(const unsigned width, const unsigned height) {                
    }

    void closeCanvas() {        
    }

    Turtle& theSystemTurtle() {
        return theSystemTurtleObj;
    }

    int canvas_width() {
        return theCanvas.width();
    }

    int canvas_height() {
        return theCanvas.height();
    }

    void addSprite(Sprite *){
        // if(t){
        //     spriteSet.insert(t);
        // }
    }

    void repaint() {}
    void removeSprite(Sprite *) {}
    void c_imprint(Sprite* s) {s->paint(nullptr);}
    void beginFrame() {}
    void endFrame() {}
    void drawPolygon(XPoint *points, int npoints, Color fill_color, bool fill, unsigned int line_width, int line_style, int cap_style, int join_style, int fill_rule, int function){}
    void drawLine(XPoint start, XPoint end, Color line_color, unsigned int line_width){
        theCanvas.drawLine(start, end, line_color, line_width);        
    }
}   // End of simplecpp namespace

Canvas::Canvas():offScreenBuffer(this) {    
    auto rectSz = simplecpp::calculateCanvasSize();
    
    // Set window size including top left corner position, height, and width    
    setGeometry(rectSz);

    // Set screen buffer size to window's size
    // auto screenSize = rectSz.size();
    auto screenSize = QSize(width(), height());
    
    offScreenBuffer.resize(screenSize);

    // Fill the screen buffer with a background colour
    auto brush = QGuiApplication::palette().brush(QPalette::Window);
    auto fillRegion = QRegion(0, 0, screenSize.width(), screenSize.height());
    
    offScreenBuffer.beginPaint(fillRegion);
    QPaintDevice *device = offScreenBuffer.paintDevice();
    Q_ASSERT(device != nullptr);
    QPainter painter(device);
    painter.fillRect(fillRegion.boundingRect(), brush);
    painter.end();
    offScreenBuffer.endPaint();

    // Show the window
    show();

    // Wait till window is exposed
    while(!isExposed())
    {
        QGuiApplication::processEvents();
        QThread::msleep(100);
    }    
}

Canvas::~Canvas() {
    
}

void Canvas::exposeEvent(QExposeEvent *e)
{
    if (isExposed())
        render(e->region());
}

void Canvas::render(const QRegion &dirtyRegion) {
    if (!isExposed())
        return;

    // Flush screen buffer to window to update dirty region    
    offScreenBuffer.flush(dirtyRegion.boundingRect());
}


void Canvas::drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth) {
    auto fillRegion = QRegion(0, 0, width(), height());
    
    // Get resources
    QPen pen(lineColor);    
    pen.setWidth(lineWidth);

    offScreenBuffer.beginPaint(fillRegion);
    QPaintDevice *device = offScreenBuffer.paintDevice();
    Q_ASSERT(device != nullptr);
    QPainter painter(device);
    
    // Do the drawing
    painter.setPen(pen);
    painter.drawLine(start, end);    
    
    painter.end();
    offScreenBuffer.endPaint();

    // Update the window
    offScreenBuffer.flush(fillRegion.boundingRect());

    simplecpp::theApp.processEvents();  
}
