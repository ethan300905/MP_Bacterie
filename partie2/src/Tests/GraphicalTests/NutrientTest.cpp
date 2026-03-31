 /*
 * POOSV 2026
 * ATTENTION: LE CODE SE DÉCLINE EN DEUX VARIANTES (SFML >=3 ou SFML < 3)
 * LORSQUE VOUS AUREZ À DÉCOMMENTER DU CODE FAITES-LE POUR LES DEUX VARIANTES
 * POUR PARER À TOUTE ÉVENTUALITÉ.
 *ATTENTION: THE CODE COMES IN TWO VERSIONS (SFML >=3 or SFML < 3)
 * WHEN YOU NEED TO COMMENT OUT CODE, DO SO FOR BOTH VERSIONS TO BE ON THE
 * SAFE SIDE.
 */

#include <Application.hpp>
#include <Lab/Nutrient.hpp>

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
            lastCreated = new Nutrient(NUT_QTY, getCursorPositionInView());
	    // UNCOMMENT WHEN READY TO TEST
            //getEnv().addNutrient(lastCreated);
            break;

        // to test takeQuantity
        case sf::Keyboard::Key::T:
	  // UNCOMMENT WHEN READY TO TEST
	  /*
            if (lastCreated != nullptr) {
                lastCreated->takeQuantity(15);
                if (lastCreated->getQuantity() <=0)  { lastCreated= nullptr; }
            }
	  */
            break;
        }
    }
#else
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        default:
            break;
        case sf::Keyboard::N:
            lastCreated = new Nutrient(NUT_QTY, getCursorPositionInView());
	    //UNCOMMENT WHEN READY TO TEST
            getEnv().addNutrient(lastCreated);
            break;


        // to test takeQuantity
        case sf::Keyboard::T:
      // UNCOMMENT WHEN READY TO TEST

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
    return RES_LOCATION + "nutriment_help_step2.txt";
}

std::string NutrientTest::getWindowTitle() const
{
    return Application::getWindowTitle()  + ":   NutrientTest";
}
