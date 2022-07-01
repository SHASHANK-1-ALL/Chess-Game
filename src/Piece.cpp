#include "Piece.hpp"

Piece::Piece(char type, bool player, int pos, bool moved)
    : m_type{type}, m_player{player}, m_position{-1}
{
    m_moved = false;
    enPassant = -1;
}

void Piece::setWindow(std::shared_ptr<sf::RenderWindow> &x_window)
{
    window = x_window;
    size = (2 * window->getSize().y / 3) / 8;
    setTexture();
    move();
    setMoved(false);
}

void Piece::setPiece(char type, bool player, int pos, bool moved)
{
    setType(type);
    setPlayer(player);
    setPosition(pos); //m_moved true
    setMoved(moved); // m_moved false
}

void Piece::setType(char ch)
{
    m_type = ch;
    setTexture();
}

char Piece::getType()
{
    return m_type;
}

void Piece::setPlayer(bool bl)
{
    m_player = bl;
    setTexture();
}

bool Piece::getPlayer()
{
    return m_player;
}

void Piece::setPosition(int pos)
{
    m_position = pos;
    move();
}

int Piece::getPosition()
{
    return m_position;
}

void Piece::setMoved(bool moved)
{
    m_moved = moved;
}
bool Piece::getMoved()
{
    return m_moved;
}

void Piece::setEnPassant(int x)
{
    enPassant = x;
}
int Piece::getEnPassant()
{
    return enPassant;
}

std::vector<int>& Piece::getPossibleMoves()
{
    return possibleMoves;
}
std::vector<int>& Piece::getDangerMoves()
{
    return dangerMoves;
}

std::string Piece::toString()
{
    std::string str;
    
    str += m_player ? "White ":"Black ";

    switch (m_type)
    {
        case 'K':
            str += "King ";
            break;
        case 'Q':
            str += "Queen ";
            break;
        case 'R':
            str += "Rook ";
            break;
        case 'B':
            str += "Bishop ";
            break;
        case 'N':
            str += "Knight ";
            break;
        case 'P':
            str += "Pawn ";
            break;
        default:
            str += "??? ";
            break;
    }

    str += "\nto position\nX: ";
    str += std::to_string((m_position % 8) + 1);
    str += "  Y: ";
    str += std::to_string((m_position / 8) + 1);
    str += '\n';


    return str;

}

void Piece::move()
{
    if(m_position <= -1 || 64 <= m_position)
    {
        m_position = -1;
        m_sprite.setFillColor(sf::Color(0x00000000));
        m_sprite.setPosition(sf::Vector2f((m_position % 8 -3.5) * size + window->getSize().x / 2,
            (m_position / 8 - 3.5) * size + window->getSize().y / 2));
        possibleMoves.clear();
        m_moved = true;
    }
    else
    {
        m_sprite.setPosition(sf::Vector2f((m_position % 8 -3.5) * size + window->getSize().x / 2,
            (m_position / 8 - 3.5) * size + window->getSize().y / 2));
        m_moved = true;
    }
    return;
}

void Piece::setTexture()
{
    m_sprite = sf::RectangleShape();
    switch (m_type)
    {
        case 'K':
            m_sprite.setTexture(&(m_player ? Engine::Data::whiteKing : Engine::Data::blackKing));
            break;
        case 'Q':
            m_sprite.setTexture(&(m_player ? Engine::Data::whiteQueen : Engine::Data::blackQueen));
            break;
        case 'R':
            m_sprite.setTexture(&(m_player ? Engine::Data::whiteRook : Engine::Data::blackRook));
            break;
        case 'B':
            m_sprite.setTexture(&(m_player ? Engine::Data::whiteBishop : Engine::Data::blackBishop));
            break;
        case 'N':
            m_sprite.setTexture(&(m_player ? Engine::Data::whiteKnight : Engine::Data::blackKnight));
            break;
        case 'P':
            m_sprite.setTexture(&(m_player ? Engine::Data::whitePawn : Engine::Data::blackPawn));
            break;
        default:
            std::cerr << "Error piece type does not exist.\n";
            break;
    }
    m_sprite.setSize(sf::Vector2f(2 * size / 3, 2 *size / 3));
    m_sprite.setOrigin(sf::Vector2f(m_sprite.getLocalBounds().height / 2 , m_sprite.getLocalBounds().width / 2));
}

void Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(getTransform());
    target.draw(m_sprite);  
}

void Piece::calcMoves(std::vector<Piece*> whitePieces, std::vector<Piece*> blackPieces,
    bool playerTurn, boost::contract::virtual_ *v)
{
    boost::contract::check c = boost::contract::public_function(v, this);
    assert(false);
}
