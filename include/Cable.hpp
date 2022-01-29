/*
  Titre      : Testeur de clâbles reseaux
  Auteur     : Yvan Tankeu
  Date       : 28/01/2022
  Description: Ce projet consite à déterminer si un câble est croisé ou non
  Version    : 0.0.1
*/

#ifndef DEF_CABLE
#define DEF_CABLE

class Cable
{
private:
    // Attributs répresente les couleurs se trouvant dans la paire torsadée 
    uint8_t cableOrange_;
    uint8_t cableOrangeI_;
    uint8_t cableVert_;
    uint8_t cableVertI_;
    uint8_t cableBleu_;
    uint8_t cableBleuI_;
    uint8_t cableBrun_;
    uint8_t cableBrunI_;
    
public:
    // Déclatation de protoypes des méthodes
    //constructeurs
    Cable(uint8_t cableOrange, uint8_t cableOrangeI, uint8_t cableVert, 
         uint8_t cableVertI, uint8_t cableBleu, uint8_t cableBleuI, uint8_t cableBrun,  uint8_t cableBrunI);

    //Getters
    uint8_t cableOrange() const;
    uint8_t cableOrangeI() const;
    uint8_t cableVert() const;
    uint8_t cableVertI() const;
    uint8_t cableBleu() const;
    uint8_t cableBleuI() const;
    uint8_t cableBrun() const;
    uint8_t cableBrunI() const;


    //setters
    void cableOrange(uint8_t) ;
    void cableOrangeI(uint8_t) ;
    void cableVert(uint8_t) ;
    void cableVertI(uint8_t) ;
    void cableBleu(uint8_t) ;
    void cableBleuI(uint8_t) ;
    void cableBrun(uint8_t) ;
    void cableBrunI(uint8_t) ;

    // Prototype d'etat des broches, input ou ouput
    void modeBroche(uint8_t);

    // Prototype de mise sous tension des broches
    void miseSousTension(bool);

    // Prototype de verification du signal entre plusieurs bornes réliées entre elles
    bool verifierSignale();   
};

#endif
