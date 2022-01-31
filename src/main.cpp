/*
  Titre      : Testeur de clâbles reseaux
  Auteur     : Yvan Tankeu
  Date       : 28/01/2022
  Description: Ce projet consite à déterminer si un câble est croié ou non
  Version    : 0.0.1
*/

#include <Arduino.h>
#include "Cable.hpp"

unsigned long delai;

// Déclaration des broches
// Broches 1er groupe
 const uint8_t cableOrange_1   = 14;
 const uint8_t cableOrangeI_1  = 25;
 const uint8_t cableVert_1     = 33;
 const uint8_t cableVertI_1    = 32;
 const uint8_t cableBleu_1     = 26;
 const uint8_t cableBleuI_1    = 27;
 const uint8_t cableBrun_1     = 13;
 const uint8_t cableBrunI_1    = 12;

// Broches 2eme groupe
 const uint8_t cableOrange_2   =  4;
 const uint8_t cableOrangeI_2  =  5;
 const uint8_t cableVert_2     = 18;
 const uint8_t cableVertI_2    = 19;
 const uint8_t cableBleu_2     = 17;
 const uint8_t cableBleuI_2    = 16;
 const uint8_t cableBrun_2     = 22;
 const uint8_t cableBrunI_2    = 23;

// Déclaration d'un cable
Cable emeteur(cableOrange_1, cableOrangeI_1, cableVert_1, cableVertI_1,cableBleu_1, cableBleuI_1, cableBrun_1, cableBrunI_1);
Cable destinataire(cableOrange_2, cableOrangeI_2, cableVert_2, cableVertI_2,cableBleu_2, cableBleuI_2, cableBrun_2, cableBrunI_2);

void setup() {

  delai = 5000;

  // on démarre la liaison
  // en la réglant à une vitesse de 9600 bits par seconde.
  Serial.begin(9600); // Debit de communication par seconde depuis le Moniteur serie

  emeteur.modeBroche(OUTPUT);
  destinataire.modeBroche(INPUT);
}

void loop() {
  
  Cable::natureDuCable(emeteur, destinataire);

  delay(delai); // delai de 5 secondes
}