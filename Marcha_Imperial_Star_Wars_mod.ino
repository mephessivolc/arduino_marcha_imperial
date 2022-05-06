/* 
  Marcha Imperia- Star Wars
 Conecte uma saida de audio ao pino 11 ou selecione um novo pino.

Criado por Robson Couto, 2019. Disponivel em: https://github.com/robsoncouto/arduino-songs/blob/master/imperialmarch/imperialmarch.ino

Modificado por Thiago Vasconcelos. Dispopnivel em: 

*/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


// Mude isso se quiser deixar a música mais lenta ou mais rápida
int tempo = 120;

// Define o pino de saida do audio. Mude se achar necessario
int buzzer = 11;

// notas da função moledy seguidas da duração.
// um 4 significa uma semínima, 8 uma semicolcheia, 16 semicolcheia, assim por diante
// !!números negativos são usados ​​para representar notas pontilhadas,
// então -4 significa uma semínima pontilhada, ou seja, uma semínima mais uma colcheia!!
int melody[] = {
  
  // Aqui é escrita a partitura da musica tema 
  // Dart Vader theme (Imperial March) - Star wars 
  // Partitura disponivel em https://musescore.com/user/202909/scores/1141521
  // A parte do saxofone tenor foi usada
  
  NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
  NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
  NOTE_A4,4, NOTE_A4,4, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16,

  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,//4
  NOTE_E5,4, NOTE_E5,4, NOTE_E5,4, NOTE_F5,-8, NOTE_C5,16,
  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
  
  NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
  NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,

  NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
  NOTE_C5,4, NOTE_A4,-8, NOTE_C5,16, NOTE_E5,2,

  NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
  NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,

  NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
  
};

 // sizeof fornece o número de bytes, cada valor int é composto por dois bytes (16 bits)
// há dois valores por nota (altura e duração), então para cada nota há quatro bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// Aqui calcula a duração de uma nota inteira em ms(milissegundos)
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void setup() {
  // Iterar sobre as notas da melodia.
  // Lembre-se, o array é o dobro do número de notas (notas + durações)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calcula a duração de cada nota
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // nota normal, apenas prossiga
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // notas pontilhadas são representadas com durações negativas!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // aumenta a duração pela metade para notas pontilhadas
    }

    // tocamos a nota apenas por 90% da duração, deixando 10% como pausa
    tone(buzzer, melody[thisNote], noteDuration*0.9);

    // Aguarda a duração específica antes de tocar a próxima nota.
    delay(noteDuration);
    
    // interrompe a geração da forma de onda antes da próxima nota.
    noTone(buzzer);
  }
}

void loop() {
  // não há necessidade de repetir a melodia.
}
