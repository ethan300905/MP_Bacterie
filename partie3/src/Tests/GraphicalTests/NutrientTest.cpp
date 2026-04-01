/*
 * POOSV 2026
 * new version for STEP3
 */

#include <Application.hpp>
#include <Lab/NutrientA.hpp>
#include <Lab/NutrientB.hpp>

class NutrientTest : public Application
{
public:
    NutrientTest(int argc, char const** argv)
    : Application(argc, argv)
    {
    }

    virtual ~NutrientTest() = default;

    virtual void onRun() override final;

    virtual void onEvent(sf::Event event, sf::RenderWindow& window) override final;
	std::string getHelpTextFile() const override final;
    std::string getWindowTitle() const override final;
private:
    Nutrient* lastCreated = nullptr;
};

IMPLEMENT_MAIN(NutrientTest);

void NutrientTest::onRun()
{
    // Basic setup
    Application::onRun();
	setStats(false);
}

void NutrientTest::onEvent(sf::Event event, sf::RenderWindow&)
{
    constexpr int NUT_QTY(50);

#if SFML_VERSION_MAJOR >= 3
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
        switch (keyPressed->code) {
        default:
            break;

        case sf::Keyboard::Key::N:
            if (keyPressed->shift) {
                lastCreated = new NutrientA(NUT_QTY, getCursorPositionInView());
            } else {
                lastCreated = new NutrientB(NUT_QTY, getCursorPositionInView());
            }
            getEnv().addNutrient(lastCreated);
            break;

        // to test takeQuantity
        case sf::Keyboard::Key::T:
            if (lastCreated != nullptr) {
                lastCreated->takeQuantity(15);
                if (lastCreated->getQuantity() <=0)  { lastCreated= nullptr; }
            }
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
                lastCreated = new NutrientA(NUT_QTY, getCursorPositionInView());
            } else {
                lastCreated = new NutrientB(NUT_QTY, getCursorPositionInView());
            }
            getEnv().addNutrient(lastCreated);
            break;

        // to test takeQuantity
        case sf::Keyboard::T:
            if (lastCreated != nullptr) {
                lastCreated->takeQuantity(15);
                if (lastCreated->getQuantity() <=0)  { lastCreated= nullptr; }
            }
            break;
        }
    }
#endif
}

std::string NutrientTest::getHelpTextFile() const
{
	return RES_LOCATION + "nutriment_help_step3.txt";
}

std::string NutrientTest::getWindowTitle() const
{
    return Application::getWindowTitle()  + ":   NutrientTest";
}
