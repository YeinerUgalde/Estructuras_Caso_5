#include <iostream>
#include <ctime>


using namespace std;

#ifndef USUARIO
#define USUARIO 1

class Usuario {
    private:

        struct tm *time_path;
        time_t register_date;
        
        string demanda;
        string oferta;

        string nickName;

        string registerDate;

        string passWord;        
        int id;

    public:
        
        void setNickName(string pNick){
            this->nickName = pNick;
            
        }
        
        void setPassWord(string pPassWord){
            this->passWord = pPassWord;
        }

        void setRegisterDate(string pRegister){
            this->registerDate = pRegister;
        }

        void setDemanda(string pDemanda){
            this->demanda = pDemanda;
        }

        void setOferta(string pOferta){
            this->oferta = pOferta;
        }

        void setTime(){
            time_t time_mod = time(NULL);
            time_path = localtime(&time_mod);
            register_date = mktime(time_path);            
            
        }

        //COSAS PRIVADAS POR CAMBIAR


        string getNick(){
            return this->nickName;
        }
        
        string getPassWord(){
            return this->passWord;
        }

        string getDemanda(){
            return this->demanda;
        }

        string getOferta(){
            return this->oferta;
        }

        string getRegister_Date(){
            return ctime(&register_date);
        }

};


#endif 