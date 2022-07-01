#include "Pawn.hpp"

Pawn::Pawn(bool player, int pos) : Piece()
{
    m_position = pos;
    m_player = player;
    m_type = 'P';
}

void Pawn::calcMoves(std::vector<Piece*> whitePieces, std::vector<Piece*> blackPieces, bool playerTurn,
    boost::contract::virtual_ *v)
{
    boost::contract::check c = boost::contract::public_function<
        override_calcMoves>(v, &Pawn::calcMoves, this, whitePieces, blackPieces, playerTurn);
     
    this->getPossibleMoves().clear();

    int piecePos{this->getPosition()};
    
    if (this->getPlayer()){ // If pawn is white
        if((piecePos / 8) != 0){
            int i{0};
            for(i = 0; i<16;i++){
                if((whitePieces[i]->getPosition() == (piecePos - 8) ) || (blackPieces[i]->getPosition() == (piecePos - 8) ))
                    break;
            }
            if((i == 16) && playerTurn){
                this->getPossibleMoves().push_back(piecePos - 8);

                if(!this->getMoved()){
                    for(i = 0; i<16;i++){
                        if((whitePieces[i]->getPosition() == (piecePos - 16) ) || (blackPieces[i]->getPosition() == (piecePos - 16) ))
                            break;
                    }
                    if(i == 16)
                        this->getPossibleMoves().push_back(piecePos - 16);
                }
            }

            if((piecePos % 8) != 0){
                for(i = 0; i<16; i++){
                    if( !playerTurn || (blackPieces[i]->getPosition() == (piecePos - 9)) || (whitePieces[i]->getPosition() == (piecePos - 9)) ){
                        this->getPossibleMoves().push_back(piecePos - 9);
                        break;
                    }
                    else if((blackPieces[i]->getEnPassant() == (piecePos - 9)) && (blackPieces[i]->getEnPassant() != -1)){
                        this->getPossibleMoves().push_back(piecePos - 9);
                        break;
                    }
                }
            }

            if((piecePos % 8) != 7){
                for(i = 0; i<16; i++){
                    if( !playerTurn || (blackPieces[i]->getPosition() == (piecePos - 7)) || (whitePieces[i]->getPosition() == (piecePos - 7)) ){
                        this->getPossibleMoves().push_back(piecePos - 7);
                        break;
                    }
                    else if((blackPieces[i]->getEnPassant() == (piecePos - 7)) && (blackPieces[i]->getEnPassant() != -1)){
                        this->getPossibleMoves().push_back(piecePos - 7);
                        break;
                    }
                }                    
            }

        }
                

    }
    else{ //if pawn is black

        if((piecePos / 8) != 7){
            int i{0};
            for(i = 0; i<16;i++){
                if((whitePieces[i]->getPosition() == (piecePos + 8) ) || (blackPieces[i]->getPosition() == (piecePos + 8) ))
                    break;
            }
            if((i == 16) && !playerTurn){
                this->getPossibleMoves().push_back(piecePos + 8);

                if(!this->getMoved()){
                    for(i = 0; i<16;i++){
                        if((whitePieces[i]->getPosition() == (piecePos + 16) ) || (blackPieces[i]->getPosition() == (piecePos + 16) ))
                            break;
                    }
                    if(i == 16)
                        this->getPossibleMoves().push_back(piecePos + 16);
                }
            }

            if((piecePos % 8) != 0){
                for(i = 0; i<16; i++){
                    if( playerTurn || (whitePieces[i]->getPosition() == (piecePos + 7)) || (blackPieces[i]->getPosition() == (piecePos + 7)) ){
                        this->getPossibleMoves().push_back(piecePos + 7);
                        break;
                    }
                    else if((whitePieces[i]->getEnPassant() == (piecePos + 7)) && (whitePieces[i]->getEnPassant() != -1)){
                        this->getPossibleMoves().push_back(piecePos + 7);
                        break;
                    }
                }                    
            }

            if((piecePos % 8) != 7){
                for(i = 0; i<16; i++){
                    if( playerTurn || (whitePieces[i]->getPosition() == (piecePos + 9)) || (blackPieces[i]->getPosition() == (piecePos + 9)) ){
                        this->getPossibleMoves().push_back(piecePos + 9);
                        break;
                    }
                    else if((whitePieces[i]->getEnPassant() == (piecePos + 9)) && (whitePieces[i]->getEnPassant() != -1)){
                        this->getPossibleMoves().push_back(piecePos + 9);
                        break;
                    }
                }                    
            }

        }
        /*else{ // MUST PROMOTE PAWN
            this->setPiece('Q', this->getPlayer(), this->getPosition(), true);
            calcMoves(this);
            return;
        }*/
    }

    this->getDangerMoves().clear();

    for(size_t i = 0; i < this->getPossibleMoves().size(); i++){

        if(!playerTurn){
            if( (this->getPossibleMoves().at(i)) == blackPieces[3]->getPosition() )
                this->getDangerMoves().push_back( this->getPossibleMoves().at(i) );
        }
        else{
            if( (this->getPossibleMoves().at(i)) == whitePieces[4]->getPosition() )
                this->getDangerMoves().push_back( this->getPossibleMoves().at(i) );
        }

    }

    this->getDangerMoves().push_back( this->getPosition() );

}
