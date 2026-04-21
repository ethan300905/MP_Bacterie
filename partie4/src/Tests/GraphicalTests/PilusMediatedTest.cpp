/*
 * POOSV 2026
 */

#include <Application.hpp>
#include <Lab/PilusMediatedBacterium.hpp>
#include <Lab/Nutrient.hpp>
class PilusMediatedTest : public Application
{
public:
    PilusMediatedTest(int argc, char const** argv)
    : Application(argc, argv)
    {
    }

    virtual ~PilusMediatedTest() = default;

    virtual void onRun() override final;

    virtual void onEvent(sf::Event event, sf::RenderWindow& window) override final;
	std::string getHelpTextFile() const override final;
    std::string getWindowTitle() const override final;
};

IMPLEMENT_MAIN(PilusMediatedTest);

void PilusMediatedTest::onRun()
{
    // Basic setup
    Application::onRun();
	setStats(false);
}

void PilusMediatedTest::onEvent(sf::Event event, sf::RenderWindow&)
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
        case sf::Keyboard::Key::P:
            getEnv().addBacterium(new PilusMediatedBacterium(getCursorPositionInView()));
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
        case sf::Keyboard::P:
            getEnv().addBacterium(new PilusMediatedBacterium(getCursorPositionInView()));
            break;
        }
    }
#endif
}


std::string PilusMediatedTest::getHelpTextFile() const
{
	return RES_LOCATION + "twitching_help_step4.txt";
}

std::string PilusMediatedTest::getWindowTitle() const
{
    return Application::getWindowTitle()  + ":   PilusMediatedTest";
}
