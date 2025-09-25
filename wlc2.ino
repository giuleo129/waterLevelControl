#define BLYNK_TEMPLATE_ID "TMPL4Uq3hnltn"
#define BLYNK_TEMPLATE_NAME "Water Level Control" // Nome del template
#define BLYNK_AUTH_TOKEN "H_DKyxEzylM_lIEkPT_YAI679YjQKA94" // Auth Token del progetto

#define BLYNK_PRINT Serial // Per il debug via monitor seriale

#include <Bridge.h>
#include <BlynkSimpleYun.h>

// Pin del sensore ultrasonico
int TRIG_PIN = 3;   // Trigger pin
int ECHO_PIN = 2;   // Echo pin
int PIEZO_PIN = 5;  // Pin per il buzzer

int MAX_DISTANCE = 200; // Valore predefinito di MAX_DISTANCE

// Funzione per ricevere il valore dallo slider su Blynk
BLYNK_WRITE(V1) {
  MAX_DISTANCE = param.asInt(); // Aggiorna MAX_DISTANCE
  Serial.print("[Blynk] Nuovo valore di MAX_DISTANCE: ");
  Serial.println(MAX_DISTANCE);
}

void setup() {
  // serial printer per il debug e inizializzazione blynk
  Serial.begin(9600);
  Serial.println("Inizializzazione del sistema...");

  Blynk.begin(BLYNK_AUTH_TOKEN);

  // Configura i pin
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(PIEZO_PIN, OUTPUT);

  Serial.println("Sistema pronto! Connessione a Blynk avviata...");
}


void loop() {
  Blynk.run(); // Mantiene la connessione a Blynk

  // Emetti un impulso sul pin Trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  
  long duration = pulseIn(ECHO_PIN, HIGH); // durata eco
  long distance = (duration / 2) / 29.1; // conversione in cm

  // Debugging: durata segnale e distanza calcolata
  Serial.print("Durata del segnale: ");
  Serial.print(duration);
  Serial.print(" microsecondi, Distanza calcolata: ");
  Serial.print(distance);
  Serial.println(" cm");

  //percentuale del livello dell'acqua
  float percentage = ((float)(MAX_DISTANCE - distance) / MAX_DISTANCE) * 100;

  if (MAX_DISTANCE - distance <= 0.10 * MAX_DISTANCE) {
        // Scrive livello dell'acqua sul Virtual Pin V0
    Blynk.virtualWrite(V0, MAX_DISTANCE - distance);

    //la percentuale dell'acqua sul Virtual Pin V2
    Blynk.virtualWrite(V2, percentage);

    Serial.println("ATTENZIONE: Livello dell'acqua troppo basso!");
    tone(PIEZO_PIN, 1000, 1000); // Suona il buzzer (frequenza 1000 Hz, durata 1 secondo)

    // creazione di un evento per segnalare il livello basso
    Blynk.logEvent("low_water", "Attenzione! Livello dell'acqua troppo basso!");

  } else {
    noTone(PIEZO_PIN); //buzzer spento se il livello è normale
    Serial.print("Livello dell'acqua OK. Acqua rimanente: ");
    Serial.print(MAX_DISTANCE - distance);
    Serial.println(" cm");
  
    Blynk.virtualWrite(V0, MAX_DISTANCE - distance); 
    Blynk.virtualWrite(V2, percentage);
   
  }

  //valore attuale di MAX_DISTANCE
  Serial.print("Valore corrente di MAX_DISTANCE: ");
  Serial.println(MAX_DISTANCE);

  delay(500); // Aspetta mezzo secondo prima della prossima lettura
 }

