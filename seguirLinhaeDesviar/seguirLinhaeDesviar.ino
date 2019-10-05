#include <Servo.h>
#include <NewPing.h>

#define motorEsquerdoPIN 8
#define motorDireitoPIN 9
#define echoPIN 10
#define triggerPIN 11
#define iRsensorEsqPIN 12
#define iRsensorDirPIN 13

Servo motorEsquerdo, motorDireito;
NewPing sonar(echoPIN, triggerPIN);

void setup()
{
    // configurando servo-motores
    motorEsquerdo.attach(motorEsquerdoPIN);
    motorDireito.attach(motorDireitoPIN);

    // configurando sensores infra-vermelhos
    pinMode(iRsensorDirPIN, INPUT);
    pinMode(iRsensorEsqPIN, INPUT);

    Serial.begin(9600); // para debugar
}

void loop()
{
    // lendo valor do sensor ultrassônico e convertendo para centímetros
    int valorSonar = sonar.ping_cm();

    // lendo valor dos sensores infravermelhos
    int valorSensorEsq = digitalRead(iRsensorEsqPIN);
    int valorSensorDir = digitalRead(iRsensorDirPIN);

    if (valorSonar > 2 && valorSonar < 10)
    { // se um objeto estiver entre 2 e 10 centímetros de distância
        desviarObstaculo();
    }

    if (!valorSensorDir && !valorSensorEsq)
    { // se ambos os sensores lerem 0 (ou falso)
        frente();
    }
    else if (valorSensorDir && !valorSensorEsq)
    { //se o direito vir preto e o esquerdo vir branco
        direita();
    }
    else if (!valorSensorDir && valorSensorEsq)
    { //se o esquerdo vir preto e direito vir branco
        esquerda();
    }
    else
    { // se ambos os sensores lerem 1
        tras();
    }
}

void desviarObstaculo()
{
    direita();
    delay(1200);
    frente();
    delay(2500);
    esquerda();
    delay(1200);
    frente();
    delay(2500);
    esquerda();
    delay(1200);
    frente();
    delay(2500);
    direita();
    delay(1200);
}

void frente()
{
    motorEsquerdo.write(180);
    motorDireito.write(0);
    //Serial.println("frente");
}
void esquerdo()
{
    motorEsquerdo.write(0);
    motorDireito.write(0);
    //Serial.println("esquerda");
}
void direita()
{
    motorEsquerdo.write(180);
    motorDireito.write(180);
    //Serial.println("direita");
}

void tras()
{
    motorEsquerdo.write(0);
    motorDireito.write(180);
    //Serial.println("trás");
}