/*
 * POOSV 2026
 */

#include <Application.hpp>
#include <Lab/MonotrichousBacterium.hpp>
#include <Lab/NutrientA.hpp>
#include <Lab/NutrientB.hpp>

class MonotrichousTest : public Application
{
public:
    MonotrichousTest(int argc, char const** argv)
    : Application(argc, argv)
    {
    }

    virtual ~MonotrichousTest() = default;

    virtual void onRun() override final;

    virtual void onEvent(sf::Event event, sf::RenderWindow& window) override final;

	std::string getHelpTextFile() const override final;

    std::string getWindowTitle() const override final;
};

IMPLEMENT_MAIN(MonotrichousTest);

void MonotrichousTest::onRun()
{
    // Basic setup
    Application::onRun();
	setStats(false);
}

void MonotrichousTest::onEvent(sf::Event event, sf::RenderWindow&)
{
    constexpr int NUT_QTY(50);
#if SFML_VERSION_MAJOR >= 3
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
        switch (keyPressed->code) {
        default:
            break;
        case sf::Keyboard::Key::N:
            if (keyPressed->shift) {
                getEnv().addNutrient(new NutrientA(NUT_QTY, getCursorPositionInView()));
            } else {
                getEnv().addNutrient(new NutrientB(NUT_QTY, getCursorPositionInView()));
            }
            break;
        case sf::Keyboard::Key::M:
            getEnv().addBacterium(new MonotrichousBacterium(getCursorPositionInView()));
            break;
        }
    }
#else
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        default:
            break;
        case sf::Keyboard::N:
            if (event.key.shift) {
                getEnv().addNutrient(new NutrientA(NUT_QTY, getCursorPositionInView()));
            } else {
                getEnv().addNutrient(new NutrientB(NUT_QTY, getCursorPositionInView()));
            }
            break;
        case sf::Keyboard::M:
            getEnv().addBacterium(new MonotrichousBacterium(getCursorPositionInView()));
            break;
        }
    }
#endif
}

std::string MonotrichousTest::getHelpTextFile() const
{
	return RES_LOCATION + "simple_bact_help.txt";
}

std::string MonotrichousTest::getWindowTitle() const
{
    return Application::getWindowTitle()  + ":   MonotrichousTest";
}
