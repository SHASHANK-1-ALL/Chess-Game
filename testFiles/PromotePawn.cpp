#include <gtest/gtest.h>

#include "Algo.hpp"

TEST(PromotePawn, CheckQueenAfterPromotion)
{
    std::shared_ptr<sf::RenderWindow> window;
    window = std::make_shared<sf::RenderWindow>();
    sf::Color c1 = sf::Color::White;
    sf::Color c2 = sf::Color::Black;
    ChessGame c(window,c1,c2);

    std::vector<Piece *>& wp = c.getWhitePieces();
    std::vector<Piece *>& bp = c.getBlackPieces();
    wp[0]->setPosition(7);
    bp[15]->setPosition(56);
    c.PromotePawn();

    ASSERT_EQ(bp[15]->getType(),'Q');
}