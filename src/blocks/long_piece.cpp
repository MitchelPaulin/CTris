#include "long_piece.h"

LongPiece::LongPiece()
{
    centerOfRotation = new Square(LongPiece::color, BOARD_HEIGHT - 3, BOARD_WIDTH - 5);

    blocks.push_back(centerOfRotation);
    blocks.push_back(new Square(LongPiece::color, BOARD_HEIGHT - 1, BOARD_WIDTH - 5));
    blocks.push_back(new Square(LongPiece::color, BOARD_HEIGHT - 2, BOARD_WIDTH - 5));
    blocks.push_back(new Square(LongPiece::color, BOARD_HEIGHT - 4, BOARD_WIDTH - 5));
}

LongPiece::LongPiece(std::vector<Square *> s, Square *center) : Block(s, center) {}

/*
    Long piece is a bit akaward, requires custom code to handle rotation 
*/
Block *LongPiece::rotate()
{
    std::vector<Square *> newSquares;
    Square *center = nullptr;
    for (Square *s : blocks)
    {
        if (s == centerOfRotation)
        {
            center = new Square(s->getColor(), centerOfRotation->getRow(), centerOfRotation->getCol());
            newSquares.push_back(center);
            continue;
        }

        newSquares.push_back(Square::rotateSquareAboutCenter(centerOfRotation, s));
    }

    LongPiece *ret = new LongPiece(newSquares, center);

    switch (dir)
    {
    case Direction::RIGHT:
        ret->moveLeft();
        ret->dir = Direction::DOWN;
        return ret; 
    case Direction::DOWN:
        ret->moveUp();
        ret->dir = Direction::LEFT;
        return ret; 
    case Direction::LEFT:
        ret->moveRight();
        ret->dir = Direction::UP;
        return ret; 
    case Direction::UP:
        ret->moveDown();
        ret->dir = Direction::RIGHT;
        return ret; 
    default:
        return ret;
    }
}