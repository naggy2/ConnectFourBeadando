#include "Gamemaster.h"




std::vector<std::vector<int> > initPlayers(){
    std::vector<std::vector<int> > players;
    for (int i = 0;i< 7;i++ ){
        std::vector<int> vec;
        for (int j = 0;j< 6;j++ ){
            vec.push_back(0);
        }
        players.push_back(vec);
    }

    return players;
}

std::vector<std::pair<int, int>> initWinnerFields(){
    std::vector<std::pair<int, int>> p;
    for (int i = 0;i< 4;i++ ){
        p.push_back(std::make_pair(-1,-1));
    }

    return p;
}

Gamemaster::Gamemaster() : _status(inGame), _turn(0),_players(initPlayers()), _winnerFields(initWinnerFields())
{

}

Gamemaster::~Gamemaster()
{

}
bool Gamemaster::isRowFull(int x){
    if(_players[x][5] == 0){ return false;}
    return true;

}

bool Gamemaster::isFieldFull(){
    for (unsigned int i = 0;i< _players.size();i++ ){
        for (unsigned int j = 0;j< _players[i].size();j++ ){
            if(_players[i][j] == 0) return false;
        }
    }
    return true;

}

void Gamemaster::setFieldsDefault(){

    for (int i = 0;i< 7;i++ ){ for (int j = 0;j< 6;j++ ){
            _players[i][j]=0;
    } }
//    for (int i = 0;i< 4;i++ ){
//        _winnerFields[i].first=-1;
//        _winnerFields[i].second=-1;
//    }

    _status=inGame;

}

void Gamemaster::checkNewElement( int x){

    int y=-1;
    /// Ha nincs tele a board �s nem is nyert senki
    if(_status!=fullBoard && _status!=winner){

        /// Ha nincsen tele a v�lasztott oszlop
        if(!isRowFull(x)){


            _turn++;
            /// A sor legals� m�g �res elem�be dobunk
            for (unsigned int i = 0;i< _players[x].size();i++ ){
                if(_players[x][i] == 0) { _players[x][i] = _turn % 2==0 ? 1 : 2;y=i; break; }
            }

            /// Ha �gy tele lesz a board, a st�tuszt megv�ltoztatjuk
            if(isFieldFull()){   _status = fullBoard;}
            ///Ha nem, akkor v�gig futtatjuk a keres�st minden ir�nyb�l, h�tha nyert valaki
            else{
                /// A 7. l�p�s el�tt senki se nyerhet, felesleges nem futtatunk keres�st
                if(_turn>6){

                    int num = _players[x][y];
                    int bx=x-3;
                    int by=y-3;
                    if(bx<0) bx=0;
                    if(by<0) by=0;

                    // a 4 �s a 3 �talak�tva _players.size()-3 illetve _player[0]s.size()-3-ra a j�t�k kib�v�thet� ak�rmekkora p�ly�ra

                    /// Ha siker�l a n�gy szomsz�d, akkor a st�tuszt winner-re �ll�tjuk, �s a nyer� n�gyes koordin�t�i elmentj�k

                    /// V�ZSZINTES
                    for (int i = bx;i< 4;i++ ){
                        if(_players[i][y] == num && _players[i+1][y] == num && _players[i+2][y] == num && _players[i+3][y] == num ){
                            _status=winner;
                            for (int k = 0;k< 4;k++ ){
                                _winnerFields[k].first = k+i;
                                _winnerFields[k].second = y;
                            }
                            break;
                        }
                    }

                    /// F�GG�LEGES
                    for (int i = by;i< 3;i++ ){
                        if(_players[x][i] == num && _players[x][i+1] == num && _players[x][i+2] == num && _players[x][i+3] == num ){
                            _status=winner;
                            for (int k = 0;k< 4;k++ ){
                                _winnerFields[k].first = x;
                                _winnerFields[k].second = k+i;
                            }
                            break;
                        }
                    }

                    /// JOBB �TL�S S�V
                    for (int i = bx;i< 4;i++ ){
                        for (int j = by;j< 3;j++ ){
                            if(_players[i][j] == num && _players[i+1][j+1] == num && _players[i+2][j+2] == num && _players[i+3][j+3] == num ){
                                _status=winner;
                                for (int k = 0;k< 4;k++ ){
                                    _winnerFields[k].first = k+i;
                                    _winnerFields[k].second = k+j;
                                }
                                break;
                            }
                        }
                    }
                    ///BAL �TL�S S�V
                    for (int i = bx;i< 4;i++ ){
                        for (int j = by;j< 3;j++ ){
                            if(_players[6-i][j] == num && _players[6-(i+1)][j+1] == num && _players[6-(i+2)][j+2] == num && _players[6-(i+3)][j+3] == num ){
                                _status=winner;
                                for (int k = 0;k< 4;k++ ){
                                    _winnerFields[k].first = 6-(k+i);
                                    _winnerFields[k].second = j+k;
                                }
                                break;
                            }
                        }
                    }



                }
            }

        }

    }




}


