#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

#define CHESSBOARD_DIMENSION 8
#define KING_IN_CHECK true

enum pieceTypes
{
    eKing,
    eQueen,
    eKnight,
    eBishop,
    eRook,
    ePawn
};

std::map<int,std::string> pieceTypeToName
{
    {eKing      ,"King"},
    {eQueen     ,"Queen"},
    {eBishop    ,"Bishop"},
    {eKnight    ,"Horse"},
    {eRook      ,"Castle"},
    {ePawn      ,"Pawn"}
};

std::map<char,int> chessPieces{
    { 'K' , eKing},            //King
    { 'Q' , eQueen},           //Queen
    { 'B' , eBishop},          //Bishop
    { 'N' , eKnight},          //Castle
    { 'R' , eRook},            //Pawn
    { 'P' , ePawn},            //Knight
};

struct position
{
    int16_t x;
    int16_t y;
};

struct chessPiece
{
    uint16_t type;
    position position;
};

struct chessPieceOffset
{
    uint16_t type;
    position origin;
    position offset;
};

void printPiece(chessPiece piece)
{
    std::string pieceName = pieceTypeToName.find(piece.type)->second;
    std::cout << "Chess Piece : " << pieceName << "\nFound at - " 
    << " X : " << piece.position.x << " Y : " << piece.position.y << std::endl;
}

void printPosition(position position)
{
    std::cout << " X : " << position.x << " Y : " << position.y << std::endl;
}

/**
 * @brief Translates a Chess piece to a piece type.
 * 
 * @param piece Chess piece in char.
 * @return int chess piece in number
 */
int pieceToPieceType(char piece)
{
    return chessPieces.find(piece)->second;
}

int absoluteValue(int input)
{
    return (input > 0) ? input : -input;
}

/**
 * @brief Get the Piece Locations object
 * 
 * @return std::vector<chessPiece> Vector of chess pieces.
 */
std::vector<chessPiece> getPieceLocations(std::vector<std::vector<char>>chessBoard)
{
    std::vector<chessPiece> chessPiecesInPlay{};
    struct chessPiece current;

    for(int xPos = 0; xPos < CHESSBOARD_DIMENSION; xPos++)
    {
        for(int yPos = 0; yPos < CHESSBOARD_DIMENSION; yPos++)
        {
            if(chessBoard[yPos][xPos] != '\0' && chessBoard[yPos][xPos] != ' ') 
            {
                current.type = pieceToPieceType(chessBoard[yPos][xPos]);
                current.position.x = xPos;
                current.position.y = yPos;
                chessPiecesInPlay.push_back(current);
            }
        }
    }

    return chessPiecesInPlay;
}

//Checks if piece has any obstructions in the pathway.
bool isObstructed(std::vector<position>obstructionMap, chessPieceOffset currentPiece)
{
    position path = currentPiece.origin;

    int16_t travelx = currentPiece.offset.x;
    int16_t travely = currentPiece.offset.y;

    uint16_t obstructionMapSize = obstructionMap.size();

    /**
     * @brief In this function I "Travel" accross the line of sight towards the king. If I "see" any obstructions then I will exit this function because
     * the pathway is obstructed.
     * 
     */
    

    while(travelx != 0 || travely != 0)
    {
        printPosition(path);

        //Piece will initially look forward one step forward so that it does not see itself as 
        //an obstruction.

        if(travelx != 0)
        {
            if(travelx > 0)
            {
                path.x--;
                travelx--;
            } else {
                path.x++;
                travelx++;
            }
        }

        if(travely!=0)
        {
            if(travely > 0)
            {
                path.y--;
                travely--;
            } else {
                path.y++;
                travely++;
            }   
        }


        for(uint16_t i = 0; i < obstructionMapSize; i++)
        {
            if(path.x == obstructionMap[i].x && path.y ==  obstructionMap[i].y)
            {
                return true;
            }
        }
        
    }
    return false;
}

/**
 * @brief 
 * 
 * @param obstructionMap - Current "Obstructions"
 * @param chessPieceOffsets - Map of the differences between the current piece and the king and maintain the original position of piece.
 * @return true if king check condition occurs.
 * @return false if king is not in check position.
 */
bool isKingInCheckCondition(std::vector<chessPieceOffset> chessPieceOffsets, std::vector<position> obstructionMap)
{
    
    for(int i = 0; i < chessPieceOffsets.size(); i++)
    {
        chessPieceOffset currentPiece = chessPieceOffsets[i];
        int xOffset = currentPiece.offset.x;
        int yOffset = currentPiece.offset.y;
        int xOrigin = currentPiece.origin.y;
        int yOrigin = currentPiece.origin.y;

        switch(currentPiece.type)
        {
            /**
             * @brief CASES WHERE OBSTRUCTION IS NOT POSSIBLE.
             * 
             */
            //Knight has unobstructed pathing and can move in any direction.
            case eKnight:
                if ((absoluteValue(xOffset) == 2 && absoluteValue(yOffset) == 1) ||
                    (absoluteValue(xOffset) == 1 && absoluteValue(yOffset) == 2))
                    {
                        return KING_IN_CHECK;
                    }
                break;
            //Pawn has psuedo "unobstructed pathing since a check is only 1 square away."
            case ePawn:
                if (yOffset == 1 && absoluteValue(xOffset) == 1)
                {
                    return KING_IN_CHECK;
                }
                break;
            //King can not check itself. 
            case eKing:
                break;
            /**
             * @brief CASES WHERE LINE OF SIGHT OBSTRUCTION IS POSSIBLE.
             * 
             */
            case eRook:
            //If rook is in Check condition, it must be on the same X or Y vector as king and be unobstructed.
                if(yOffset == 0 || xOffset == 0)
                {
                    if (!isObstructed(obstructionMap,currentPiece))
                    {
                        return KING_IN_CHECK;
                    }
                }
                break;
            case eBishop:
            printPosition(currentPiece.offset);
            //If the absolute values of Y and X are exactly matching for the Bishop. The Piece is in line of sight of the king.
                if(absoluteValue(yOffset) == absoluteValue(xOffset))
                {
                    if (!isObstructed(obstructionMap,currentPiece))
                    {
                        return KING_IN_CHECK;
                    }
                }
                break;
            case eQueen:
            //Queen has both bishop and rook Condition.
                if(absoluteValue(yOffset) == absoluteValue(xOffset) || yOffset == 0 || xOffset == 0)
                {
                    if (!isObstructed(obstructionMap,currentPiece))
                    {
                        return KING_IN_CHECK;
                    }
                }
                break;
        }
        
    }

    return false;
}

bool isKingInCheck(std::vector<std::vector<char>>chessBoard)
{
    std::vector<chessPiece> chessPiecesInPlay = getPieceLocations(chessBoard);
    chessPiece blackKing;

    //Find black King!
    for(std::vector<chessPiece>::iterator it = chessPiecesInPlay.begin(); it!= chessPiecesInPlay.end(); ++it)
    {
        if(it->type == eKing)
        {
            blackKing = *(it); //BKB!!!!
        }
    }

    std::vector<chessPieceOffset> chessPieceOffsets; 
    chessPieceOffset currentPieceOffset;

    std::vector<position> obstructionMap;
    position currentPosition;

    //Find differences
    for(std::vector<chessPiece>::iterator it = chessPiecesInPlay.begin(); it!= chessPiecesInPlay.end(); ++it)
    {
        currentPieceOffset.type = it->type;
    
        //I don't care about the BLACK KING BAR
        if (currentPieceOffset.type != eKing)
        {
            //Maintain origin location for obstruction detection.
            currentPieceOffset.origin.x = it->position.x;
            currentPieceOffset.origin.y = it->position.y;

            //Find piece offset location.
            currentPieceOffset.offset.x = it->position.x - blackKing.position.x;
            currentPieceOffset.offset.y = it->position.y - blackKing.position.y;
            chessPieceOffsets.push_back(currentPieceOffset);

            //Create "Obstruction Map"
            currentPosition.x = it->position.x;
            currentPosition.y = it->position.y;
            obstructionMap.push_back(currentPosition);
        }
    }

    return isKingInCheckCondition(chessPieceOffsets,obstructionMap);   
}

int main()
{
    //THIS IS A DEMO CHESSBOARD, WE CAN INSERT EITHER '\0' OR ' ' for EMPTY GRIDS!
    std::vector<std::vector<char>> chessBoard{
        {'\0' , '\0' , '\0' , '\0' , '\0' , '\0', '\0' , '\0'},
        {'\0' , '\0' , '\0' , '\0' , '\0' , '\0', '\0' , '\0'},
        {'\0' , '\0' , '\0' , '\0' , '\0' , '\0', '\0' , '\0'},
        {'R' , 'Q' , 'P' , 'K' , '\0' , '\0', '\0' , '\0' },
        {'\0' , '\0' , '\0' , 'P' , '\0' , '\0', '\0' , '\0'},
        {'\0' , '\0' , '\0' , '\0' , '\0' , '\0', '\0' , '\0'},
        {'\0' , '\0' , '\0' , '\0' , '\0' , '\0', '\0' , '\0'},
        {'\0' , '\0' , '\0' , '\0' , '\0' , '\0', '\0' , '\0'},
    };

    std::cout<<isKingInCheck(chessBoard);


}