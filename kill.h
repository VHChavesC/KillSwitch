#ifndef KILL_LIBRARY_H
#define KILL_LIBRARY_H
#define HIGH 1
#define LOW 0
#define LIMITE 1000
#endif

//Função responsável por encerrar totalmente a atividade do sistema.
int KillSystem() {
    return HIGH;
};

//Função responsável por desacoplar a sonda do balão.
int KillCoupler() {
    return HIGH;
};

//Função responsável por encerrar o log. de dados gerado pela missão, que é salvo no cartão SD.
int KillLog() {
    return HIGH;
};

//Função responsável por encerrar o atuador das válvulas que controlam o fluxo de gás do balão.
int KillValvula() {
    return HIGH;
};

//Função responável por encerrar tarefas computacionalmente custosas em funcionamento.
int KillTask() {
    return HIGH;
};

//Rotina respnosável por verificar os parâmetros vitais do sistema e encerrar o sistema em caso de pane.
int Watchdog(int Param1, int Param2, int Param3, int ParamN) {
    while (HIGH) {
        if (Param1 > LIMITE || Param2 > LIMITE || Param3 > LIMITE || ParamN > LIMITE) {
            KillSystem();
            return HIGH;
        }
    }
};

//Rotina Responsável por executar a ação enviada por telecomando.
int Telecomando(int TrechoDoPacoteReservadoAoKillSwitch){
    switch (TrechoDoPacoteReservadoAoKillSwitch){
        case 1:
            KillSystem();
            break;
        case 2:
            KillCoupler();
            break;
        case 3:
            KillLog();
            break;
        case 4:
            KillValvula();
            break;
        case 5:
            KillTask();
            break;
        default:
            return LOW;
    }
}