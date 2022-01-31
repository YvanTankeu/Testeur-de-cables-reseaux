/*
  Titre      : Testeur de clâbles reseaux
  Auteur     : Yvan Tankeu
  Date       : 28/01/2022
  Description: Ce projet consite à déterminer si un câble est croisé ou non
  vers, ion    : 0.0.1
*/

#include <Arduino.h>
#include "Cable.hpp"

// Implémentations des méthodes de la classe

/**
 * @brief construit un nouveau cable::cable object
 * Cette syntaxe d'implémentation de constructeur est éxpliqué sur openclassroom via ce lien "t.ly/U6fQ" que j'ai raccourci car trop long
 *
 * @param cableOrange  // Câble de couleur orange
 * @param cableOrangeI // Câble de couleur orange Interrompue
 * @param cableVert    // Câble de couleur verte
 * @param cableVertI   // Câble de couleur verte interompue
 * @param cableBleu    // Câble de couleur bleue
 * @param cableBleuI   // Câble de couleur bleue interrompue
 * @param cableBrun    // Câble de couleur brun
 * @param cableBrunI   // Câble de couleur brun interrompue
 */
Cable::Cable(   uint8_t cableOrange, uint8_t cableOrangeI, uint8_t cableVert, uint8_t cableVertI, uint8_t cableBleu,
                uint8_t cableBleuI, uint8_t cableBrun, uint8_t cableBrunI)
                :   cableOrange_(cableOrange), cableOrangeI_(cableOrangeI), cableVert_(cableVert),
                    cableVertI_(cableVertI), cableBleu_(cableBleu), cableBleuI_(cableBleuI), cableBrun_(cableBrun){

                }

// Implémentation de getters
uint8_t Cable::cableOrange() const{
    return cableOrange_;
}

uint8_t Cable::cableOrangeI() const{
    return cableOrangeI_;
}

uint8_t Cable::cableVert() const{
    return cableVert_;
}

uint8_t Cable::cableVertI() const{
 return cableVertI_;
}

uint8_t Cable::cableBleu() const{
    return cableBleu_;
}

uint8_t Cable::cableBleuI() const{
    return cableBleuI_;
}

uint8_t Cable::cableBrun() const{
    return cableBrun_;
}

uint8_t Cable::cableBrunI() const{
    return cableBrunI_;
}

// Implémentation de setters
void Cable::cableOrange(uint8_t cableOrange){
    cableOrange_ = cableOrange;
}

void Cable::cableOrangeI(uint8_t cableOrangeI){
    cableOrangeI_ = cableOrangeI;
}

void Cable::cableVert(uint8_t cableVert){
    cableVert_ = cableVert;
}

void Cable::cableVertI(uint8_t cableVertI){
    cableVertI_ = cableVertI;
}

void Cable::cableBleu(uint8_t cableBleu){
    cableBleu_ = cableBleu;
}
void Cable::cableBleuI(uint8_t cableBleuI){
    cableBleuI_ = cableBleuI;
}

void Cable::cableBrun(uint8_t cableBrun){
    cableBrun_ = cableBrun;
}

void Cable::cableBrunI(uint8_t cableBrunI){
    cableBrunI_ = cableBrunI;
}

/**
 * @brief Elle defini l'etat de la broche entre high et low
 *
 * @param etatSouhaite  prendra deux etat pour la mise sous tension ou non des broches
 */
void Cable::miseSousTension(bool etatSouhaite){
    digitalWrite(cableOrange_, etatSouhaite);
    digitalWrite(cableOrangeI_, etatSouhaite);
    digitalWrite(cableVert_, etatSouhaite);
    digitalWrite(cableVertI_, etatSouhaite);
    digitalWrite(cableBleu_, etatSouhaite);
    digitalWrite(cableBleuI_, etatSouhaite);
    digitalWrite(cableBrun_, etatSouhaite);
    digitalWrite(cableBrunI_, etatSouhaite);
}

/**
 * @brief Méthode qui devra mettre les broches en mode input pour certains et output pour les autres
 *
 * @param mode  chaine de caractère qui ne pourra être que INPUT ou OUTPOUT
 */
void Cable::modeBroche(uint8_t mode){
    if (mode == INPUT)
    {
        pinMode(cableOrange_, mode);
        pinMode(cableOrangeI_, mode);
        pinMode(cableVert_, mode);
        pinMode(cableVertI_, mode);
        pinMode(cableBleu_, mode);
        pinMode(cableBleuI_, mode);
        pinMode(cableBrun_, mode);
        pinMode(cableBrunI_, mode);
    }else
    if (mode == OUTPUT){
        pinMode(cableOrange_, mode);
        pinMode(cableOrangeI_, mode);
        pinMode(cableVert_, mode);
        pinMode(cableVertI_, mode);
        pinMode(cableBleu_, mode);
        pinMode(cableBleuI_, mode);
        pinMode(cableBrun_, mode);
        pinMode(cableBrunI_, mode);
    }else
    {
        Serial.println("INPUT ou OUTPUT ? :");
    }
}

/**
 * @brief Verifie si le signal a été recu dans les broches destinaires
 *
 * @return true , s'il y a le signale dans toutes les 08 broches destinataires
 * @return false s'il n'y a le signale dans toutes les 08 broches destinataires
 */
bool Cable::verifierSignale()
{
    bool bon = false;
    if ((digitalRead(cableOrange_) == 1)  && (digitalRead(cableOrangeI_) == 1)
        && (digitalRead(cableVert_) == 1) && (digitalRead(cableVertI_) == 1)
        && (digitalRead(cableBleu_) == 1) && (digitalRead(cableBleuI_) == 1)
        && (digitalRead(cableBrun_) == 1) && (digitalRead(cableBrunI_) == 1))
    {
            bon = true;
    }else{
        bon = false;
    }

    // Testeur qui ne fera pas partie du code final
    Serial.println(" ");
    Serial.print("cable Orange      : ");
    Serial.println((digitalRead(cableOrange_)));
    Serial.print("cable Orange blanc: ");
    Serial.println((digitalRead(cableOrangeI_)));

    Serial.print("cable Vert        : ");
    Serial.println((digitalRead(cableVert_)));
    Serial.print("cable Vert blanc  : ");
    Serial.println((digitalRead(cableVertI_)));

    Serial.print("cable bleu blanc  : ");
    Serial.println((digitalRead(cableBleu_)));
    Serial.print("cable bleu blanc  : ");
    Serial.println((digitalRead(cableBleuI_)));

    Serial.print("cable Brun        : ");
    Serial.println((digitalRead(cableBrun_)));

    Serial.print("cable Brun blanc  : ");
    Serial.println((digitalRead(cableBrunI_)));

    return bon;
}

/**
 * @brief Méthodes statique pour la detection de la nature du cable
 * 
 * @param obj1 est un objet qui est la 1ère extréminté du cable
 * @param obj2 est un objet qui est la 2ème extréminté du cable
 */
void Cable::natureDuCable(Cable obj1, Cable obj2){
   obj1.miseSousTension(LOW);
   obj2.miseSousTension(LOW);

   // Envoie du signal à la brôche Orange interrompue de E -> R
   digitalWrite(obj1.cableOrangeI_, HIGH);

   if (digitalRead(obj2.cableOrangeI_) == 1)
   {
       Serial.println(" ");
       Serial.println("Orange blanc 1, émet vers, Orange blanc 2");
       Serial.println(" ");

       // Envoie du signal à brôche Orange si l'interrompu a reçu
       digitalWrite(obj1.cableOrange_, HIGH);

       if (digitalRead(obj2.cableOrange_) == 1)
       {
           Serial.println(" ");
           Serial.println("Orange 1 émet vers, Orange 2");
           Serial.println(" ");

           // Envoie du signal à brôche Verte interrompue si l'orange a reçu
           digitalWrite(obj1.cableVertI_, HIGH);

           if (digitalRead(obj2.cableVertI_) == 1)
           {
               Serial.println(" ");
               Serial.println("Vert blanc 1, émet vers, vert blanc 2");


               // Envoie du signal à brôche Bleu  si la verte Interrompue a reçu
               digitalWrite(obj1.cableBleu_, HIGH);

               if (digitalRead(obj2.cableBleu_) == 1)
               {
                   Serial.println(" ");
                   Serial.println("Bleu 1 émet vers, Bleu  2");
                   Serial.println(" ");

                   // Envoie du signal à brôche Bleu Interrompue si la bleue a reçu
                   digitalWrite(obj1.cableBleuI_, HIGH);

                   if (digitalRead(obj2.cableBleuI_) == 1)
                   {
                       Serial.println(" ");
                       Serial.println("Bleu blanc 1, émet vers, Bleu Int  2");
                       Serial.println(" ");

                       // Envoie du signal à brôche Verte si la bleue Interrompue a reçu
                       digitalWrite(obj1.cableVert_, HIGH);

                       if (digitalRead(obj2.cableVert_) == 1)
                       {
                           Serial.println(" ");
                           Serial.println("Vert 1 émet vers, vert 2");
                           Serial.println(" ");

                           // Envoie du signal à brôche Brun interrompue si la verte  a reçu
                           digitalWrite(obj1.cableBrunI_, HIGH);

                           if (digitalRead(obj2.cableBrunI_) == 1)
                           {
                               Serial.println(" ");
                               Serial.println("Brun blanc 1, émet vers, Brun blanc 2");
                               Serial.println(" ");

                               // Envoie du signal à brôche Brun  si la Brun Interrompue  a reçu
                               digitalWrite(obj1.cableBrun_, HIGH);

                               if (digitalRead(obj2.cableBrun_) == 1)
                               {   Serial.println(" ");
                                   Serial.println("Brun 1 émet vers, Brun 2");
                                   Serial.println(" ");
                                   Serial.println("===== Câble droit =====");
                               }
                               else 
                                Serial.println("Le signal ne passe pas entre Brun");
                           }
                           else
                             Serial.println("Le signal ne passe pas entre Brun Int");          
                       }
                      else
                        Serial.println("Le signal ne passe pas entre  Verte");
                   }
                   else
                       Serial.println("Le signal ne passe pas entre  Bleue Int");
               }
               else{Serial.println("Le signal ne passe pas entre  Bleue");}
           }
           else
            Serial.println("Le signal ne passe pas entre vert Int");
       }
       else
         Serial.println("Le signal ne passe pas entre orange"); 
   }
   else if (digitalRead(obj2.cableVertI_) == 1)
   {
       Serial.println("Orange blanc 1, émet vers, orange blanc 2, broche differente actu (b19) ");

       // Envoie du signal de la brôche orange 1 si la orange Interrompue 2 a reçu
       digitalWrite(obj1.cableOrange_, HIGH);
       if (digitalRead(obj2.cableVertI_) == 1)
       {

           Serial.println(" ");
           Serial.println("Orange 1, émet vers, orange blanc 2, broche differente actu (b18) ");

           // Envoie du signal de la brôche Verte interrompue 1  si la orange  2 a reçu
           digitalWrite(obj1.cableVertI_, HIGH);
           if (digitalRead(obj2.cableOrangeI_) == 1)
           {
               Serial.println(" ");
               Serial.println("Vert blanc 1, émet vers, le Vert blanc 2, broche differente actu (b05) ");
                
               // Envoie du signal à brôche Bleu  si la verte interrompue a reçu
               digitalWrite(obj1.cableBleu_, HIGH);
               if (digitalRead(obj2.cableBleu_) == 1)
               {
                   Serial.println(" ");
                   Serial.println("Bleu 1 émet vers, Bleu 2");

                   // Envoie du signal à brôche Bleu Interrompue si la bleu a reçu
                   digitalWrite(obj1.cableBleuI_, HIGH);
                   if (digitalRead(obj2.cableBleuI_) == 1)
                   {
                       Serial.println(" ");
                        Serial.println("Bleu blanc 1 émet vers, Bleu blanc 2");
                        
                       // Envoie du signal à brôche Verte si la bleue Interrompue a reçu
                       digitalWrite(obj1.cableVert_, HIGH);
                       if (digitalRead(obj2.cableOrange_) == 1)
                       {
                           Serial.println(" ");
                           Serial.println("Vert 1, émet vers, le Vert 2, broche differente actu (b04) ");

                           // Envoie du signal à brôche Brun interrompue si la verte  a reçu
                           digitalWrite(obj1.cableBrunI_, HIGH);
                           if (digitalRead(obj2.cableBrunI_) == 1)
                           {
                               Serial.println(" ");
                               Serial.println("Brun blanc 1, émet vers, Brun blanc 2");

                               // Envoie du signal à brôche Brun  si la Brun Interrompue  a reçu
                               digitalWrite(obj1.cableBrun_, HIGH);
                               if (digitalRead(obj2.cableBrun_) == 1)
                               {
                                   Serial.println(" ");
                                   Serial.println("Brun 1 émet vers, Brun 2");
                                   Serial.println(" ");
                                   Serial.println("===== Câble croisé =====");
                               }
                           }
                           Serial.println(" ");
                            Serial.println("===== Câble croisé =====");
                       }
                   }
                   else
                   {
                       Serial.println("===== Câble croisé =====");
                       //Serial.println("Le signal ne passe pas entre vert blanc");
                   }
               }
               else
               {
                   Serial.println("Le signal ne passe pas entre orange");
               }
           }
           else
           {
               Serial.println("Impossible de déterminer la nature de ce câble");
           }
         
           delay(2000);
       }
   }
}
