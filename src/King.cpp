#include "King.hpp"

King::King(bool player, int pos) : Piece()
{
    m_position = pos;
    m_player = player;
    m_type = 'K';
}

void King::calcMoves(std::vector<Piece*> whitePieces, std::vector<Piece*> blackPieces, bool playerTurn,
    boost::contract::virtual_ *v)
{
    boost::contract::check c = boost::contract::public_function<
        override_calcMoves>(v, &King::calcMoves, this, whitePieces, blackPieces, playerTurn);

    int piecePos{this->getPosition()};
    this->getPossibleMoves().clear();

    if((piecePos / 8) != 0){
        this->getPossibleMoves().push_back(piecePos - 8);
        if((piecePos % 8) != 0)
            this->getPossibleMoves().push_back(piecePos - 9);
        if((piecePos % 8) != 7)
            this->getPossibleMoves().push_back(piecePos - 7);
    }
    if((piecePos / 8) != 7){
        this->getPossibleMoves().push_back(piecePos + 8);
        if((piecePos % 8) != 0)
            this->getPossibleMoves().push_back(piecePos + 7);
        if((piecePos % 8) != 7)
            this->getPossibleMoves().push_back(piecePos + 9);
    }
    if((piecePos % 8) != 0)
        this->getPossibleMoves().push_back(piecePos - 1);
    if((piecePos % 8) != 7)
        this->getPossibleMoves().push_back(piecePos + 1);


    //calcCastling(tmpPiece);
}

