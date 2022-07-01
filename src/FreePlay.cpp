#include "FreePlay.hpp"

FreePlay::FreePlay(std::shared_ptr<sf::RenderWindow> &x_window) : GameType(x_window)
{
    Variables();
}

void FreePlay::Variables()
{
    // setting the title
    Set_Text(name, data.Round_Bold, "Free Play", 0.08 * window->getSize().y, window->getSize().x / 2, 0);
    name.setPosition(window->getSize().x / 2, name.getLocalBounds().height / 2);
    name.setFillColor(sf::Color::Red);

    timeLimit = false;
    firstTime = false;
}

void FreePlay::Input(sf::Event &event, std::shared_ptr<State> &xState,
    std::vector<std::shared_ptr<State>> &x_list, boost::contract::virtual_ *v)
{
    boost::contract::check c = boost::contract::public_function<
        override_Input>(v, &FreePlay::Input, this, event, xState, x_list);

    GameType::Input(event, xState, x_list);
}

void FreePlay::Logic(boost::contract::virtual_ *v)
{
    boost::contract::check c = boost::contract::public_function<
        override_Logic>(v, &FreePlay::Logic, this);

    GameType::Logic();
}

void FreePlay::Draw(boost::contract::virtual_ *v)
{
    boost::contract::check c = boost::contract::public_function<
        override_Draw>(v, &FreePlay::Draw, this);

    GameType::Draw();
}