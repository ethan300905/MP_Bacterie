/*
 * POOSV 2026
 */

#include <Application.hpp>
#include <Lab/PilusMediatedBacterium.hpp>
#include <Lab/Nutrient.hpp>

class MockTwitching : public PilusMediatedBacterium
{
public:
	using PilusMediatedBacterium::PilusMediatedBacterium;
	using PilusMediatedBacterium::moveGrip;
	using PilusMediatedBacterium::getRadius;
};

	
class GripTest : public Application
{
public:
    GripTest(int argc, char const** argv)
    : Application(argc, argv)
    {
    }

    virtual ~GripTest() = default;

    virtual void onRun() override final;
	std::string getHelpTextFile() const override final;
    virtual void onEvent(sf::Event event, sf::RenderWindow& window) override final;
    std::string getWindowTitle() const override final;
};

IMPLEMENT_MAIN(GripTest);

void GripTest::onRun()
{
    // Basic setup
    Application::onRun();
	setStats(false);
}

void GripTest::onEvent(sf::Event event, sf::RenderWindow&)
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
            MockTwitching* twitching(new MockTwitching(getCursorPositionInView()));
            twitching->moveGrip(Vec2d(5,5)*twitching->getRadius());
            getEnv().addBacterium(twitching);
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
            MockTwitching* twitching(new MockTwitching(getCursorPositionInView()));
            twitching->moveGrip(Vec2d(5,5)*twitching->getRadius());
            getEnv().addBacterium(twitching);
            break;
        }
    }
#endif
    // Pilus mediated bacteria
    //(controls to be added here if needed)
}

std::string GripTest::getHelpTextFile() const
{
	return RES_LOCATION + "grip_help_step4.txt";
}

std::string GripTest::getWindowTitle() const
{
    return Application::getWindowTitle()  + ":   GripTest";
}
