//Autor >> YoruHinda Ruan Phablo
//Data >> 14/09/2021
//C++ Relogio basico cmd

//Bibliotecas
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <thread>
#include <chrono>

//Declaração das funções
void initRelogio();
void relogio();
void cronometro();
void temporizador();
void alarme();

//Função main
int main()
{
    initRelogio();
    return 0;
}

//Função de inicializar relogio com menu organizado
void initRelogio()
{
    int numesc = 0;
    bool loopRe = false;
    do
    {
        system("color 6");
        std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
        std::cout << "Digite um numero para acessar uma funcao do relogio 1.Relogio 2.Conometro 3.Alarme 4.Temporizador" << std::endl;
        std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
        std::cout << ": ";
        std::cin >> numesc;
        switch (numesc)
        {
        case 1:
            system("cls");
            std::cout << "Iniciando o Relogio \n";
            loopRe = false;
            relogio();
            break;

        case 2:
            system("cls");
            std::cout << "Iniciando o Conometro \n";
            loopRe = false;
            cronometro();
            break;

        case 3:
            system("cls");
            std::cout << "Iniciando o Alarme\n";
            loopRe = false;
            alarme();
            break;

        case 4:
            system("cls");
            std::cout << "Iniciando o Temporizador\n";
            loopRe = false;
            temporizador();
            break;

        default:
            system("cls");
            std::cout << "ESCOLHA INVALIDA PORFAVOR INSIRA UM VALOR VALIDO \n";
            loopRe = true;
            break;
        }
    } while (loopRe == true);
}

//Função obter a hora atual do computar e atualizar em loop dentro de um intervalo
void relogio()
{
    time_t t;
    struct tm *infoTempo;
    char buffer[80];

    while (true)
    {
        system("cls");

        time(&t);
        infoTempo = localtime(&t);

        strftime(buffer, sizeof(buffer), "Horario atual: %H:%M", infoTempo);

        std::cout << buffer << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

//Função alarme armazena a hora que o usuario insere quando chega nessa hora determinada escreve na tela
void alarme()
{
    std::string alrname;
    int hours;
    int minutes;
    time_t t;
    struct tm *infoTime;
    char buffer[80];

    std::cout << "O alarme esta configurado em AM e PM coloque as horas nesse formato!\n";
    std::cout << "Digite o nome do alarme: ";
    std::cin >> alrname;
    std::cout << "\nDigite a hora: ";
    std::cin >> hours;
    std::cout << "\nDigite os minutos: ";
    std::cin >> minutes;

    while (true)
    {
        system("cls");
        time(&t);
        infoTime = localtime(&t);
        strftime(buffer, sizeof(buffer), "Hora atual: %H:%M", infoTime);
        std::cout << buffer << std::endl;
        std::cout << "O alarme com o nome "
                  << "\"" << alrname << "\""
                  << " vai disparar as " << hours << " horas e " << minutes << " Minutos!" << std::endl;
        if (hours == infoTime->tm_hour && minutes == infoTime->tm_min)
        {
            system("cls");
            std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
            std::cout << "O alarme com nome de "
                      << "\"" << alrname << "\""
                      << " Disparou" << std::endl;
            std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

//Função conometro vai começar 00:00:00 com horas, minutos e segundos iniciado em zero e vai conometrar o tempo
void cronometro()
{
    int hour;
    int min;
    int sec;
    for (hour = 0; hour < 24; hour++)
    {
        for (min = 0; min < 59; min++)
        {
            for (sec = 0; sec < 59; sec++)
            {
                system("cls");
                std::cout << "Conometro: " << hour << ":" << min << ":" << sec << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
        }
    }
}

//Função temporizador parecido com alarme so que mais pratico para uso mais rapido
void temporizador()
{
    system("cls");
    int hours;
    int min;
    int sec;
    std::cout << "Digite as horas: ";
    std::cin >> hours;
    std::cout << "Digite os minutos: ";
    std::cin >> min;
    std::cout << "Digite os segundos: ";
    std::cin >> sec;
    while (true)
    {
        if (sec <= 59 && sec > 0)
        {
            sec--;
        }
        if (sec == 0 && min <= 59 && min > 0)
        {
            min--;
            sec = 59;
            if (min == 0 && hours <= 24 && hours > 0)
            {
                hours--;
                min = 59;
            }
        }
        else if (sec == 0 && min == 0 && hours == 0)
        {
            std::cout << "Tempo Acabou!" << std::endl;
            break;
        }
        system("cls");
        std::cout << "Temporizador: " << hours << ":" << min << ":" << sec << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}