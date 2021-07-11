#include <QtTest>
#include <canvas.h>
#include <simplecppmainwindow.h>

class TestSimpleCpp : public QObject
{
    Q_OBJECT

public:
    TestSimpleCpp();
    ~TestSimpleCpp();

private slots:

    void test_initCanvas();
    void test_closeCanvas();
    void test_drawLine();
    void test_drawLineStress();
};

TestSimpleCpp::TestSimpleCpp()
{

}

TestSimpleCpp::~TestSimpleCpp()
{

}

void init(std::string testTitle)
{
    auto windowName {testTitle};
    auto windowWidth {800};
    auto windowHeight {600};

    simplecpp::initCanvas(windowName.c_str(), windowWidth, windowHeight);
}

void cleanup()
{
    simplecpp::appObj->processEvents(); // Process all pending events
    Sleep(4000);                        // Wait for visual inspection
    simplecpp::closeCanvas();
}


void TestSimpleCpp::test_initCanvas()
{
    auto windowName {"Test for simplecpp::initCanvas()"};
    auto windowWidth {800};
    auto windowHeight {600};

    simplecpp::initCanvas(windowName, windowWidth, windowHeight);

    // Check window size
    QCOMPARE(simplecpp::winObj->width(),  windowWidth);
    QCOMPARE(simplecpp::winObj->height(), windowHeight);

    // Check window title
    auto currentTitle  = simplecpp::winObj->title();
    QCOMPARE(windowName, currentTitle);

    // Check window visibility
    QCOMPARE(simplecpp::winObj->isVisible(), true);

    // Cleanup
    cleanup();

}

void TestSimpleCpp::test_closeCanvas()
{
    // Initialization
    auto windowName {"Test for simplecpp::closeCanvas()"};
    auto windowWidth {300};
    auto windowHeight {200};
    simplecpp::initCanvas(windowName, windowWidth, windowHeight);

    QCOMPARE(simplecpp::winObj->isVisible(), true);

    simplecpp::closeCanvas();

    // Check whether global state has been cleaned up
    QCOMPARE(simplecpp::winObj, nullptr);
    QCOMPARE(simplecpp::appObj, nullptr);

}

void TestSimpleCpp::test_drawLine()
{
    // Initialization

    init(__func__);

    simplecpp::XPoint start {10, 20};
    simplecpp::XPoint end {300, 400};

    simplecpp::drawLine(start, end, simplecpp::Color("darkCyan"), 10);

    // Termination
    cleanup();
}

void TestSimpleCpp::test_drawLineStress()
{
    // Initialization

    init(__func__);
    auto limit = 100000;    // One lac

    for(auto idx = 0; idx < limit; idx ++)
    {
        simplecpp::XPoint start, end;

        start.setX(rand() %  800);
        start.setY(rand() %  600);

        end.setX(rand() %  800);
        end.setY(rand() %  600);

        simplecpp::drawLine(start, end, simplecpp::Color("darkCyan"), 10);
    }


    // Termination
    cleanup();
}

QTEST_APPLESS_MAIN(TestSimpleCpp)

#include "tst_testsimplecpp.moc"
