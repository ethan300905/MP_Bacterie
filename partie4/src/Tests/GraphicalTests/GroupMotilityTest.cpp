/*
 * POOSV 2026
 */

#include <Application.hpp>
#include <Lab/BacteriaGroup.hpp>
#include <Lab/GroupMotilityBacterium.hpp>
#include <Lab/Nutrient.hpp>
#include <array>
#include <cassert>

class GroupMotilityTest : public Application
{
public:
    GroupMotilityTest(int argc, char const** argv)
    : Application(argc, argv)
    {
    }

    virtual ~GroupMotilityTest() = default;

    virtual void onRun() override final;

    virtual void onSimulationStart() override final;
	
	std::string getHelpTextFile() const override final;
    std::string getWindowTitle() const override final;
	
    virtual void onEvent(sf::Event event, sf::RenderWindow& window) override final;
};

IMPLEMENT_MAIN(GroupMotilityTest);

void GroupMotilityTest::onRun()
{
    // Basic setup
    Application::onRun();
	setStats(false);
}

void GroupMotilityTest::onSimulationStart()
{
	Application::onSimulationStart();
    for (auto i = 1; i < 4; ++i) {
        auto id = std::to_string(i);
        getEnv().addSwarm(id);
    }
}

void GroupMotilityTest::onEvent(sf::Event event, sf::RenderWindow&)
{
    constexpr int NUT_QTY(50);
#if SFML_VERSION_MAJOR >= 3
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
        if (sf::Keyboard::Key::Num0 <= keyPressed->code && keyPressed->code <= sf::Keyboard::Key::Num3) {
            auto id = std::to_string(static_cast<int>(keyPressed->code) - static_cast<int>(sf::Keyboard::Key::Num0));
            getEnv().addBacteriumToSwarm(id, getCursorPositionInView());
        }
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
         }
        // Add other controls for group motility bacteria if needed
    }
#else
    if (event.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::Num0 <= event.key.code && event.key.code <= sf::Keyboard::Num3) {
            auto id = std::to_string(event.key.code - sf::Keyboard::Num0);
            getEnv().addBacteriumToSwarm(id, getCursorPositionInView());
        }
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
            }
        // Add other controls for group motility bacteria if needed
    }
#endif
}
std::string GroupMotilityTest::getHelpTextFile() const
{
	return RES_LOCATION + "swarm_help_step4.txt";
}

std::string GroupMotilityTest::getWindowTitle() const
{
    return Application::getWindowTitle() + ":   GroupMotilityTest";
}
