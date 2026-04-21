/*
 * POOSV 2026
 */

#include <Application.hpp>
#include <Lab/Bacterium.hpp>
#include <Lab/MonotrichousBacterium.hpp>
#include <Utility/Types.hpp>
#include<Lab/Nutrient.hpp>

#define STEP 4
constexpr Quantity DEFAULT_ENERGY(60);
constexpr Quantity DEFAULT_RADIUS(10);



typedef MonotrichousBacterium TestBacterium;

		  
class BacteriaTest : public Application
{
public:
    BacteriaTest(int argc, char const** argv)
    : Application(argc, argv)
    {
    }

    virtual ~BacteriaTest() = default;

    virtual void onRun() override final;

    virtual void onEvent(sf::Event event, sf::RenderWindow& window) override final;

    std::string getHelpTextFile() const override final;
    std::string getWindowTitle() const override final;
};

IMPLEMENT_MAIN(BacteriaTest);

void BacteriaTest::onRun()
{
    // Basic setup
    Application::onRun();
	setStats(false);
}

void BacteriaTest::onEvent(sf::Event event, sf::RenderWindow&)
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
            getEnv().addBacterium(new TestBacterium(getCursorPositionInView()));
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
            getEnv().addBacterium(new TestBacterium(getCursorPositionInView()));
            break;
        }
    }
#endif
}

std::string BacteriaTest::getHelpTextFile() const
{
    return RES_LOCATION + "bact_help_step3.txt";
}

std::string BacteriaTest::getWindowTitle() const
{
    return Application::getWindowTitle()  + ":   BacteriaTest";
}
