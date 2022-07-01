#include "RapidPlay.hpp"

RapidPlay::RapidPlay(std::shared_ptr<sf::RenderWindow> &x_window) : GameType(x_window)
{
    Variables();
}

void RapidPlay::Variables()
{
    // setting the title
    Set_Text(name, data.Round_Bold, "Rapid Play", 0.08 * window->getSize().y, window->getSize().x / 2, 0);
    name.setPosition(window->getSize().x / 2, name.getLocalBounds().height / 2);
    name.setFillColor(sf::Color::Red);

    setTotalTime = 35 * 60;
    firstTime = false;
}

void RapidPlay::Input(sf::Event &event, std::shared_ptr<State> &xState,
    std::vector<std::shared_ptr<State>> &x_list, boost::contract::virtual_ *v)
{
    boost::contract::old_ptr<std::vector<std::shared_ptr<State>>> old_list = BOOST_CONTRACT_OLDOF(x_list);
    boost::contract::check c = boost::contract::public_function<
        override_Input>(v, &RapidPlay::Input, this, event, xState, x_list);

    GameType::Input(event, xState, x_list);
}

void RapidPlay::Logic(boost::contract::virtual_ *v)
{
    boost::contract::check c = boost::contract::public_function<
        override_Logic>(v, &RapidPlay::Logic, this);

    GameType::Logic();
}

void RapidPlay::Draw(boost::contract::virtual_ *v)
{
    boost::contract::check c = boost::contract::public_function<
        override_Draw>(v, &RapidPlay::Draw, this);

    GameType::Draw();
}