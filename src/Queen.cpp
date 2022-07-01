#include "Queen.hpp"

Queen::Queen(bool player, int pos ,bool moved) : Piece()
{
    m_position = pos;
    m_player = player;
    m_type = 'Q';
}

void Queen::calcMoves(std::vector<Piece*> whitePieces, std::vector<Piece*> blackPieces, bool playerTurn,
    boost::contract::virtual_ *v)
{
    boost::contract::check c = boost::contract::public_function<
        override_calcMoves>(v, &Queen::calcMoves, this, whitePieces, blackPieces, playerTurn);

    int piecePos{this->getPosition()};
    int posCounter{1};

    bool dangerMove{false};
    bool finishLoop{false};

    this->getPossibleMoves().clear();
    this->getDangerMoves().clear();

    // Queen moves left on X axis
    while( ((piecePos-posCounter) >= 0) && ((piecePos/8) == ((piecePos-posCounter)/8)) ){
        
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if(  ( whitePieces[i]->getPosition() == (piecePos-posCounter) ) || ( blackPieces[i]->getPosition() == (piecePos-posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }
            this->getPossibleMoves().push_back(piecePos-posCounter);
        }
        
        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            this->getDangerMoves().push_back(piecePos-posCounter);
            if(!playerTurn){
                if( (piecePos-posCounter) == blackPieces[3]->getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos-posCounter) == whitePieces[4]->getPosition() )
                    dangerMove = true;
            }

        }
        
        posCounter += 1;
    }


    // Queen moves right on X axis
    if(!dangerMove) this->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 1;
    while( (piecePos/8) == ((piecePos+posCounter)/8) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (whitePieces[i]->getPosition() == (piecePos+posCounter)) || ( blackPieces[i]->getPosition() == (piecePos+posCounter) ) ){
                    finishLoop = true;
                    break;
                }
            }
            this->getPossibleMoves().push_back(piecePos+posCounter);
        }

        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            this->getDangerMoves().push_back(piecePos+posCounter);
            if(!playerTurn){
                if( (piecePos+posCounter) == blackPieces[3]->getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos+posCounter) == whitePieces[4]->getPosition() )
                    dangerMove = true;
            }

        }
        
        posCounter += 1;
    }
    //Queen moves up on Y axis
    if(!dangerMove) this->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 8;
    while(((piecePos-posCounter) >= 0) && (posCounter < 64) && ((piecePos%8) == ((piecePos-posCounter)%8)) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (whitePieces[i]->getPosition() == (piecePos-posCounter)) || (blackPieces[i]->getPosition() == (piecePos-posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }        
            this->getPossibleMoves().push_back(piecePos-posCounter);
        }

        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            this->getDangerMoves().push_back(piecePos-posCounter);
            if(!playerTurn){
                if( (piecePos-posCounter) == blackPieces[3]->getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos-posCounter) == whitePieces[4]->getPosition() )
                    dangerMove = true;
            }

        }

        posCounter += 8;
    }
    //Queen moves down on Y axis
    if(!dangerMove) this->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 8;
    while(((piecePos+posCounter) <= 63) && (posCounter < 64) && ((piecePos%8) == ((piecePos+posCounter)%8)) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (whitePieces[i]->getPosition() == (piecePos+posCounter)) || (blackPieces[i]->getPosition() == (piecePos+posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }
            this->getPossibleMoves().push_back(piecePos+posCounter);
        }
        
        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            this->getDangerMoves().push_back(piecePos+posCounter);
            if(!playerTurn){
                if( (piecePos+posCounter) == blackPieces[3]->getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos+posCounter) == whitePieces[4]->getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 8;
    }
    // Queen moves towards top left
    if(!dangerMove) this->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 9;
    while( ((piecePos-posCounter) >= 0) && (((piecePos-posCounter) % 8) < (piecePos % 8)) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (whitePieces[i]->getPosition() == (piecePos-posCounter)) || (blackPieces[i]->getPosition() == (piecePos-posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }
            this->getPossibleMoves().push_back(piecePos-posCounter);
        }

        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            this->getDangerMoves().push_back(piecePos-posCounter);
            if(!playerTurn){
                if( (piecePos-posCounter) == blackPieces[3]->getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos-posCounter) == whitePieces[4]->getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 9;
    }
    // Queen moves towards bottom right
    if(!dangerMove) this->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 9;
    while( ((piecePos+posCounter) <= 63) && (((piecePos+posCounter) % 8) > (piecePos % 8)) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (whitePieces[i]->getPosition() == (piecePos+posCounter)) || (blackPieces[i]->getPosition() == (piecePos+posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }        
            this->getPossibleMoves().push_back(piecePos+posCounter);
        }

        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            this->getDangerMoves().push_back(piecePos+posCounter);
            if(!playerTurn){
                if( (piecePos+posCounter) == blackPieces[3]->getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos+posCounter) == whitePieces[4]->getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 9;
    }
    // Queen moves towards top right
    if(!dangerMove) this->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 7;
    while( ((piecePos-posCounter) >= 0) && (((piecePos-posCounter) % 8) > (piecePos % 8)) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (whitePieces[i]->getPosition() == (piecePos-posCounter)) || (blackPieces[i]->getPosition() == (piecePos-posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }        
            this->getPossibleMoves().push_back(piecePos-posCounter);
        }

        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            this->getDangerMoves().push_back(piecePos-posCounter);
            if(!playerTurn){
                if( (piecePos-posCounter) == blackPieces[3]->getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos-posCounter) == whitePieces[4]->getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 7;
    }
    // Queen moves towards bottom left
    if(!dangerMove) this->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 7;
    while( ((piecePos+posCounter) <= 63) && (((piecePos+posCounter) % 8) < (piecePos % 8)) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (whitePieces[i]->getPosition() == (piecePos+posCounter)) || (blackPieces[i]->getPosition() == (piecePos+posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }        
            this->getPossibleMoves().push_back(piecePos+posCounter);
        }

        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            this->getDangerMoves().push_back(piecePos+posCounter);
            if(!playerTurn){
                if( (piecePos+posCounter) == blackPieces[3]->getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos+posCounter) == whitePieces[4]->getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 7;
    }

    if(!dangerMove) this->getDangerMoves().clear();

    
    if(!this->getDangerMoves().empty()){
        int collisions{0};
        for(size_t j=0; j<this->getDangerMoves().size(); j++){
            for(int i=0; i<16; i++){
                if(this->getDangerMoves().at(j) == blackPieces[i]->getPosition()){
                    collisions++;
                    if(!this->getPlayer())
                        collisions++;
                }
                if(this->getDangerMoves().at(j) == whitePieces[i]->getPosition()){
                    collisions++;
                    if(this->getPlayer())
                        collisions++;
                }
            }
        }

        if(collisions > 2)
            this->getDangerMoves().clear();
    }

    this->getDangerMoves().push_back( this->getPosition() );
}
