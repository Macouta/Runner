#include "Model.h"
#include <iostream>
#include <fstream>
using namespace std;

//=======================================
// Constructeurs
//=======================================
Model::Model(int w, int h)
  :  _w(w), _h(h){
    m_char=new Balle{10,450,300,300,0,0};
}

//=======================================
// Destructeurs
//=======================================
Model::~Model(){

    delete m_char;
}

//=======================================
// Calcul la prochaine étape
//=======================================
void Model::nextStep(){
    m_char->move();
}

sf::Vector2f Model::getBallPosition()
{
    sf::Vector2f a{m_char->getX(),m_char->getY()};
    return a;
}

void Model::getBallDim(int&h, int &w)
{
    h=m_char->getH();
    w=m_char->getW();
}


void Model::moveBall(bool left, bool right)
{
    int a = -5;
    int b = 5;
    int c = 0;
    if (left)
        m_char->setDX(a);
    else if (right)
        m_char->setDX(b);
    else
        m_char->setDX(c);
}
